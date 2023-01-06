/****************************************************************************
 * Copyright (C) 2023 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "FFLoader.h"

QElapsedTimer Timer;
QTime PauseTime;

int currentJob;

void FFLoader::Encode(QString ffmpeg, QString vsArgs) {
	encode = new QProcess();

	Connector(encode, ProcessType::Encode);
	Connector(encode, ProcessType::EncodeFinish);
	Timer.restart();

	if (!vsArgs.isEmpty()) {
		vs = new QProcess();
		Connector(vs, ProcessType::Vs);

		vs->setStandardOutputProcess(encode);
		NewProcess(vs, QStringList(), vsArgs);
	}

	NewProcess(encode, QStringList(), ffmpeg);
}

void FFLoader::VideoInfo(QString arguments) {
	video = new QProcess();

	Connector(video, ProcessType::VideoInfo);
	Connector(video, ProcessType::VideoFinish);
	NewProcess(video, QStringList(), arguments);
}

void FFLoader::OutputDataVideo() {
	OutputData(video, ProcessType::VideoInfo);
}

void FFLoader::OutputDataInfo() {
	OutputData(encode, ProcessType::Encode);
}

void FFLoader::OutputDataVs() {
	OutputData(vs, ProcessType::Vs);
}

void FFLoader::VideoFinished() {
	Finisher(video, ProcessType::VideoFinish);
}

void FFLoader::EncodeFinished() {
	Finisher(encode, ProcessType::EncodeFinish);
}

void FFLoader::OutputData(QProcess* process, ProcessType type) {
	process->setReadChannel(QProcess::StandardError);

	QTextStream stream(process);
	QString output;

	while (!stream.atEnd()) {
		output = stream.readLine(0);

		if (type == ProcessType::Encode || type == ProcessType::Vs) {
			ProcessErrorRegex::ErrorRegex(output);

			if (type == ProcessType::Vs && !output.contains("Creating lwi index file"))
				emit Logs(output);
		}

		switch (type) {
		case ProcessType::Encode:
			if (ProgressInfoRegex::ProgressRegex(output, VideoInfoList::GetDuration(currentJob), VideoInfoList::GetFrameRate(currentJob).trimmed().toDouble()
				* QTime(0, 0, 0, 0).secsTo(VideoInfoList::GetDuration(currentJob)), Timer, PauseTime))
				emit setProgress();
			else
				emit Logs(output);

			break;
		case ProcessType::VideoInfo:
			VideoInfoRegex::DurationBitrateRegex(output);
			VideoInfoRegex::VideoInfoerRegex(output);
			AudioSubInfoRegex::AudioInfoRegex(output);
			AudioSubInfoRegex::SubInfoRegex(output);
			break;
		}
	}
}

void FFLoader::Finisher(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::EncodeFinish:
		Disconnecter(process, ProcessType::EncodeFinish);
		Disconnecter(process, ProcessType::Encode);

		if (vs)
			Disconnecter(vs, ProcessType::Vs);

		emit Completed();
		break;
	case ProcessType::VideoFinish:
		Disconnecter(process, ProcessType::VideoFinish);
		Disconnecter(process, ProcessType::VideoInfo);
		emit setVideoInfo();
		break;
	}

	Deconstruct(process);
}

void FFLoader::Connector(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVideo);
		break;
	case ProcessType::Vs:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVs);
		break;
	case ProcessType::VideoFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::VideoFinished);
		break;
	case ProcessType::EncodeFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::EncodeFinished);
		break;
	}
}

void FFLoader::Disconnecter(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVideo);
		break;
	case ProcessType::Vs:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVs);
		break;
	case ProcessType::VideoFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::VideoFinished);
		break;
	case ProcessType::EncodeFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::EncodeFinished);
		break;
	}

	process->closeReadChannel(QProcess::StandardError);
}