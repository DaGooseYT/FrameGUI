#include "framegui.hpp"

QString FrameGUI::configureVS(QString id) {
	MediaConfig::resetArguments();

	MediaConfig::setVSPipe(QDir::toNativeSeparators(QDir::currentPath()) + QString("\\vs\\vspipe.exe"),
		QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1\\%1.vpy").arg(id)));

	return(MediaConfig::getArguments());
}

QString FrameGUI::configureAudioPT(int stream, QString id, QString container) {
	MediaConfig::resetArguments();

	if (stream == 1) {
		MediaConfig::setFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + QString("\\ffmpeg\\ffmpeg.exe"));
		MediaConfig::setOverride();
		MediaConfig::setInput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(id)));
		MediaConfig::setInput(_ui.SelectInTxtBox->text());
		MediaConfig::setMapAll(QString("v"), QString("0"));
		MediaConfig::setVideoCodec(QString("copy"));
	}

	if (stream == 1)
		MediaConfig::setMapAll(QString("a"), QString("%1").arg(stream));

	MediaConfig::setAudioCodec(QString("copy"));
	MediaConfig::setMapAll(QString("s?"), QString("%1").arg(stream));

	if (container.contains(QString(".mkv")))
		MediaConfig::append(QString(" -c:s srt"));
	else if (container.contains(QString(".mov")) || container.contains(QString(".mp4")))
		MediaConfig::append(QString(" -c:s mov_text"));

	if (stream == 1) {
		MediaConfig::append(QString(" -metadata:g encoding_tool=\"FrameGUI v%1\"").arg(VERSION));
		MediaConfig::setOutput(_ui.SaveOutTxtBox->text() + container);
	}

	return MediaConfig::getArguments();
}

QString FrameGUI::configureArgs(QString container, QString id) {
	MediaConfig::resetArguments();

	MediaConfig::setFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + QString("\\ffmpeg\\ffmpeg.exe"));
	MediaConfig::setOverride();
	MediaConfig::setNoAutoRotate();
	MediaConfig::append(QString(" -i -"));

	if (_ui.IWantDD->currentIndex() == 0)
		MediaConfig::setVideoCodec(QString("libx264"));
	else {
		MediaConfig::setVideoCodec(QString("libx265"));
		MediaConfig::append(QString(" -tag:v hvc1")); // apple compat
	}

	MediaConfig::setConstantRateFactor(17);

	if (_ui.UpscaleSetGB->isChecked()) {
		int resH = _ui.OutputResDD->currentText().remove(QString("(")).remove(QString(")")).remove(QString("p")).remove(QString("HD")).remove(QString("F")).remove(QString("Q")).remove(QString("U")).remove(QString("4K")).remove(QString(" ")).toInt();
		double factor = 0;
		int outH = 0;
		int outW = 0;

		switch (resH) {
		case 720:
			outW = 1280;
			break;
		case 1080:
			outW = 1920;
			break;
		case 1440:
			outW = 2560;
			break;
		case 2160:
			outW = 3840;
			break;
		}

		factor = static_cast<double>(outW) / VideoInfo::getWidth();
		outH = static_cast<double>(factor) * VideoInfo::getHeight();

		if (outH % 2 != 0)
			outH++;

		MediaConfig::setFilters();
		MediaConfig::setVideoResolution(outW, outH);
		MediaConfig::setConcludeFilters();
	}

	MediaConfig::append(QString(" -metadata:g encoding_tool=\"FrameGUI v%1\"").arg(VERSION));

	if (AudioInfo::totalStreams() == 0 && SubtitleInfo::totalStreams() == 0)
		MediaConfig::setOutput(_ui.SaveOutTxtBox->text() + container);
	else
		MediaConfig::setOutput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(id)));

	return(MediaConfig::getArguments());
}