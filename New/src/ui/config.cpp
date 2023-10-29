#include "framegui.hpp"

#ifdef Q_OS_WINDOWS
QStringList FrameGUI::configureVS(QString id) {
	MediaConfig::resetArguments();

	MediaConfig::setVsPipe1();
	MediaConfig::setVsPipe2();
	MediaConfig::append(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1\\%1.vpy").arg(id)));
	MediaConfig::append(QString("-"));

	return(MediaConfig::getArguments());
}
#endif

QStringList FrameGUI::configureAudioPT(int stream, QString id, QString container) {
	MediaConfig::resetArguments();

	if (stream == 1) {
		MediaConfig::setOverride();
		MediaConfig::setInput();

		#ifdef Q_OS_WINDOWS
		MediaConfig::append(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(id)));
		#endif
		#ifdef Q_OS_DARWIN
		MediaConfig::append(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1").arg(id)));
		#endif

		MediaConfig::setInput();
		MediaConfig::append(_ui->SelectInTxtBox->text());
		MediaConfig::setMapAll(QString("v"), QString("0"));
		MediaConfig::setVideoCodec(QString("copy"));
	}

	if (stream == 1)
		MediaConfig::setMapAll(QString("a"), QString("%1").arg(stream));

	MediaConfig::setAudioCodec(QString("copy"));
	MediaConfig::setMapAll(QString("s?"), QString("%1").arg(stream));

	if (container.contains(QString(".mkv")))
		MediaConfig::setSubtitleCodec("srt");
	else if (container.contains(QString(".mov")) || container.contains(QString(".mp4")))
		MediaConfig::setSubtitleCodec("mov_text");

	if (stream == 1) {
		MediaConfig::setMetaData1();
		MediaConfig::setMetaData2(QString("\"FrameGUI v%1\"").arg(VERSION));
		MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
	}

	return(MediaConfig::getArguments());
}

QStringList FrameGUI::configureArgs(QString container, QString id, QString vsScript) {
	MediaConfig::resetArguments();

	#ifdef Q_OS_DARWIN
	MediaConfig::setVs();
	#endif

	MediaConfig::setOverride();
	MediaConfig::setNoAutoRotate();
	MediaConfig::setInput();

	#ifdef Q_OS_WINDOWS
	MediaConfig::append(QString("-"));
	#endif
	#ifdef Q_OS_DARWIN
	MediaConfig::append(vsScript);
	#endif

	if (_ui->IWantDD->currentIndex() == 0)
		MediaConfig::setVideoCodec(QString("libx264"));
	else {
		MediaConfig::setVideoCodec(QString("libx265"));
		MediaConfig::setAppleTag();
	}

	MediaConfig::setConstantRateFactor(17);

	if (CHECKED(_ui->UpscaleSetGB)) {
		int resH = _ui->OutputResDD->currentText().remove(QString("(")).remove(QString(")")).remove(QString("p")).remove(QString("HD")).remove(QString("F")).remove(QString("Q")).remove(QString("U")).remove(QString("4K")).remove(QString(" ")).toInt();
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

		MediaConfig::setVideoResolution(outW, outH);
	}

	MediaConfig::setMetaData1();
	MediaConfig::setMetaData2(QString("\"FrameGUI v%1\"").arg(VERSION));

	if (AudioInfo::totalStreams() == 0 && SubtitleInfo::totalStreams() == 0)
		MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
	else {
		#ifdef Q_OS_WINDOWS
		MediaConfig::setOutput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(id)));
		#endif
		#ifdef Q_OS_DARWIN
		MediaConfig::setOutput(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1.mkv").arg(id)));
		#endif
	}

	return(MediaConfig::getArguments());
}