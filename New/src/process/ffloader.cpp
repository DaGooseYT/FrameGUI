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

#include "ffloader.hpp"

QElapsedTimer _timer;
QTime _pauseTime;

int _currentJob;

void FFLoader::encode(QString ffmpeg, QString vsArgs) {
	_encode = new QProcess();

	connector(_encode, ProcessType::Encode);
	connector(_encode, ProcessType::EncodeFinish);
	_timer.restart();

	if (!vsArgs.isEmpty()) {
		_vs = new QProcess();
		connector(_vs, ProcessType::VS);

		_vs->setStandardOutputProcess(_encode);
		newProcess(_vs, QStringList(), vsArgs);
	}

	newProcess(_encode, QStringList(), ffmpeg);
}

void FFLoader::videoInfo(QString arguments) {
	_video = new QProcess();

	connector(_video, ProcessType::VideoInfo);
	connector(_video, ProcessType::VideoFinish);
	newProcess(_video, QStringList(), arguments);
}

void FFLoader::outputDataVideo() {
	outputData(_video, ProcessType::VideoInfo);
}

void FFLoader::outputDataInfo() {
	outputData(_encode, ProcessType::Encode);
}

void FFLoader::outputDataVS() {
	outputData(_vs, ProcessType::VS);
}

void FFLoader::videoFinished() {
	finisher(_video, ProcessType::VideoFinish);
}

void FFLoader::encodeFinished() {
	finisher(_encode, ProcessType::EncodeFinish);
}

void FFLoader::outputData(QProcess* process, ProcessType type) {
	process->setReadChannel(QProcess::StandardError);

	QTextStream stream(process);
	QString output;

	while (!stream.atEnd()) {
		output = stream.readLine(0);

		if (type == ProcessType::Encode || type == ProcessType::VS) {
			ProcessErrorRegex::errorRegex(output);

			if (type == ProcessType::VS && !output.contains(QString("Creating lwi index file")))
				emit logs(output);
		}

		switch (type) {
		case ProcessType::Encode:
			if (ProgressInfoRegex::progressRegex(output, VideoInfoList::getDuration(_currentJob), VideoInfoList::getFrameRate(_currentJob).trimmed().toDouble()
				* QTime(0, 0, 0, 0).secsTo(VideoInfoList::getDuration(_currentJob)), _timer, _pauseTime))
				emit setProgress();
			else
				emit logs(output);

			break;
		case ProcessType::VideoInfo:
			VideoInfoRegex::durationBitrateRegex(output);
			VideoInfoRegex::videoInfoerRegex(output);
			AudioSubInfoRegex::audioInfoRegex(output);
			AudioSubInfoRegex::subInfoRegex(output);
			break;
		}
	}
}

void FFLoader::finisher(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::EncodeFinish:
		disconnecter(process, ProcessType::EncodeFinish);
		disconnecter(process, ProcessType::Encode);

		if (_vs)
			disconnecter(_vs, ProcessType::VS);

		emit completed();
		break;
	case ProcessType::VideoFinish:
		disconnecter(process, ProcessType::VideoFinish);
		disconnecter(process, ProcessType::VideoInfo);
		emit setVideoInfo();
		break;
	}

	deconstruct(process);
}

void FFLoader::connector(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVideo);
		break;
	case ProcessType::VS:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVS);
		break;
	case ProcessType::VideoFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::videoFinished);
		break;
	case ProcessType::EncodeFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::encodeFinished);
		break;
	}
}

void FFLoader::disconnecter(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVideo);
		break;
	case ProcessType::VS:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVS);
		break;
	case ProcessType::VideoFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::videoFinished);
		break;
	case ProcessType::EncodeFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::encodeFinished);
		break;
	}

	process->closeReadChannel(QProcess::StandardError);
}