#include "FrameGUI.h"

QString FrameGUI::BuildScript(int width, int height, QString jobID) {
	ScriptBuilder::ClearScript();

	QString matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out, format;

	if (VideoInfo::GetMatrix().contains("bt709"))
		matrix_in = "709";
	else if (VideoInfo::GetMatrix().contains("fcc"))
		matrix_in = "fcc";
	else if (VideoInfo::GetMatrix().contains("bt470bg"))
		matrix_in = "470bg";
	else if (VideoInfo::GetMatrix().contains("smpte170m"))
		matrix_in = "170m";
	else if (VideoInfo::GetMatrix().contains("smpte240m"))
		matrix_in = "240m";
	else if (VideoInfo::GetMatrix().contains("ycgco"))
		matrix_in = "ycgco";
	else if (VideoInfo::GetMatrix().contains("bt2020nc"))
		matrix_in = "2020ncl";
	else if (VideoInfo::GetMatrix().contains("bt2020c"))
		matrix_in = "2020cl";
	else
		matrix_in = "709";

	if (VideoInfo::GetTransfer().contains("bt709"))
		transfer_in = "709";
	else if (VideoInfo::GetTransfer().contains("bt470m"))
		transfer_in = "470m";
	else if (VideoInfo::GetTransfer().contains("bt470bg"))
		transfer_in = "470bg";
	else if (VideoInfo::GetTransfer().contains("log100"))
		transfer_in = "log100";
	else if (VideoInfo::GetTransfer().contains("log316"))
		transfer_in = "log316";
	else if (VideoInfo::GetTransfer().contains("smpte170m"))
		transfer_in = "709"; //patch
	else if (VideoInfo::GetTransfer().contains("smpte240m"))
		transfer_in = "240m";
	else if (VideoInfo::GetTransfer().contains("smpte2084"))
		transfer_in = "st2084";
	else
		transfer_in = "709";

	if (VideoInfo::GetPrimaries().contains("bt709"))
		primaries_in = "709";
	else if (VideoInfo::GetPrimaries().contains("bt470m"))
		primaries_in = "470m";
	else if (VideoInfo::GetPrimaries().contains("bt470bg"))
		primaries_in = "470bg";
	else if (VideoInfo::GetPrimaries().contains("smpte170m"))
		primaries_in = "170m";
	else if (VideoInfo::GetPrimaries().contains("smpte240m"))
		primaries_in = "240m";
	else if (VideoInfo::GetPrimaries().contains("bt2020"))
		primaries_in = "2020";
	else
		primaries_in = "709";

	if (VideoInfo::GetColors().contains("8-bit"))
		format = "YUV420P8";
	else if (VideoInfo::GetColors().contains("10-bit"))
		format = "YUV420P10";
	else
		format = "YUV420P8";

	ScriptBuilder::SetInclude();
	ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\LSMASHSource.dll"));

	if (CHECKED(ui.UpscaleSetGB))
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\srmd.dll"));

	if (CHECKED(ui.InterpSetGB))
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\rife.dll"));

	ScriptBuilder::SetInput(ui.SelectInTxtBox->text(), jobID);

	if (CHECKED(ui.InterpSetGB)) {
		double inFPS = VideoInfo::GetFrameRate().toDouble();
		double outFPS = ui.OutFPSDD->currentText().toDouble();

		if (inFPS != outFPS) {
			ScriptBuilder::SetRGB(matrix_in, transfer_in, primaries_in);
			ScriptBuilder::SetSCDetect(QString("0.14"));
			ScriptBuilder::SetRIFE(ui.OutFPSDD->currentText().toInt(), 0, 1, "False", "False", "True");
			ScriptBuilder::SetColorsOut("YUV420P8", matrix_in, transfer_in, primaries_in);
		}
	}
	else if (CHECKED(ui.UpscaleSetGB)) {
		int scale = 2;
		int outH = ui.OutputResDD->currentText().remove("(").remove(")").remove("p").remove("HD").remove("F").remove("Q").remove("U").remove("4K").remove(" ").toInt();
		int outW = 0;

		switch (outH) {
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

		ScriptBuilder::SetRGB(matrix_in, transfer_in, primaries_in);

		if (VideoInfo::GetWidth() * 2 < outW && VideoInfo::GetWidth() * 3 >= outW)
			scale = 3;
		else if (VideoInfo::GetWidth() * 3 < outW && VideoInfo::GetWidth() * 4 >= outW)
			scale = 4;

		ScriptBuilder::SetSRMD(scale, 3, 0, 1, "False");
		ScriptBuilder::SetColorsOut(format, matrix_in, transfer_in, primaries_in);
	}

	ScriptBuilder::SetConcludeClip();

	return ScriptBuilder::GetScript();
}

int FrameGUI::DecimalCounter(QString value) {
	int index = value.indexOf(".");
	int count = value.remove(".").length();

	return count - index;
}