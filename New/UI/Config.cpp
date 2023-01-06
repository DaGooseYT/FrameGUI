#include "FrameGUI.h"

QString FrameGUI::ConfigureVS(QString id) {
	MediaConfig::ResetArguments();

	MediaConfig::SetVSPipe(QDir::toNativeSeparators(QDir::currentPath()) + "\\vapoursynth\\vspipe.exe",
		QDir::toNativeSeparators(QDir::tempPath()).replace("Temp", QString("FrameGUI\\job-%1\\%1.vpy").arg(id)));

	return MediaConfig::GetArguments();
}

QString FrameGUI::ConfigureAudioP(int stream, QString id, QString container) {
	MediaConfig::ResetArguments();

	if (stream == 1) {
		MediaConfig::SetFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe");
		MediaConfig::SetOverride();
		MediaConfig::SetInput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(id)));
		MediaConfig::SetInput(ui.SelectInTxtBox->text());
		MediaConfig::SetMapAll("v", "0");
		MediaConfig::SetVideoCodec("copy");
	}

	if (stream == 1)
		MediaConfig::SetMapAll("a", QString("%1").arg(stream));

	MediaConfig::SetAudioCodec("copy");
	MediaConfig::SetMapAll("s?", QString("%1").arg(stream));

	if (container.contains(".mkv"))
		MediaConfig::Append(" -c:s srt");
	else if (container.contains(".mov") || container.contains(".mp4"))
		MediaConfig::Append(" -c:s mov_text");

	if (stream == 1) {
		MediaConfig::Append(QString(" -metadata:g encoding_tool=\"FrameGUI v%1\"").arg(VERSION));
		MediaConfig::SetOutput(ui.SaveOutTxtBox->text() + container);
	}

	return MediaConfig::GetArguments();
}

QString FrameGUI::ConfigureArgs(QString container, QString id) {
	MediaConfig::ResetArguments();

	MediaConfig::SetFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe");
	MediaConfig::SetOverride();
	MediaConfig::SetNoAutoRotate();
	MediaConfig::Append(" -i -");

	if (ui.IWantDD->currentIndex() == 0)
		MediaConfig::SetVideoCodec("libx264");
	else {
		MediaConfig::SetVideoCodec("libx265");
		MediaConfig::Append(" -tag:v hvc1"); //Apple compat
	}

	MediaConfig::SetConstantRateFactor(17);

	if (ui.UpscaleSetGB->isChecked()) {
		int resH = ui.OutputResDD->currentText().remove("(").remove(")").remove("p").remove("HD").remove("F").remove("Q").remove("U").remove("4K").remove(" ").toInt();
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

		factor = static_cast<double>(outW) / VideoInfo::GetWidth();
		outH = static_cast<double>(factor) * VideoInfo::GetHeight();

		if (outH % 2 != 0)
			outH++;

		MediaConfig::SetFilters();
		MediaConfig::SetVideoResolution(outW, outH);
		MediaConfig::SetConcludeFilters();
	}

	MediaConfig::Append(QString(" -metadata:g encoding_tool=\"FrameGUI v%1\"").arg(VERSION));

	if (AudioInfo::TotalStreams() == 0 && SubtitleInfo::TotalStreams() == 0)
		MediaConfig::SetOutput(ui.SaveOutTxtBox->text() + container);
	else
		MediaConfig::SetOutput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(id)));

	return MediaConfig::GetArguments();
}