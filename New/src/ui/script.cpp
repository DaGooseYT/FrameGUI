#include "framegui.hpp"

QString FrameGUI::buildScript(int width, int height, QString jobID) {
	ScriptBuilder::clearScript();

	QString matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out, format;

	if (VideoInfo::getMatrix().contains(QString("bt709")))
		matrix_in = QString("709");
	else if (VideoInfo::getMatrix().contains(QString("fcc")))
		matrix_in = QString("fcc");
	else if (VideoInfo::getMatrix().contains(QString("bt470bg")))
		matrix_in = QString("470bg");
	else if (VideoInfo::getMatrix().contains(QString("smpte170m")))
		matrix_in = QString("170m");
	else if (VideoInfo::getMatrix().contains(QString("smpte240m")))
		matrix_in = QString("240m");
	else if (VideoInfo::getMatrix().contains(QString("ycgco")))
		matrix_in = QString("ycgco");
	else if (VideoInfo::getMatrix().contains(QString("bt2020nc")))
		matrix_in = QString("2020ncl");
	else if (VideoInfo::getMatrix().contains(QString("bt2020c")))
		matrix_in = QString("2020cl");
	else
		matrix_in = QString("709");

	if (VideoInfo::getTransfer().contains(QString("bt709")))
		transfer_in = QString("709");
	else if (VideoInfo::getTransfer().contains(QString("bt470m")))
		transfer_in = QString("470m");
	else if (VideoInfo::getTransfer().contains(QString("bt470bg")))
		transfer_in = QString("470bg");
	else if (VideoInfo::getTransfer().contains(QString("log100")))
		transfer_in = QString("log100");
	else if (VideoInfo::getTransfer().contains(QString("log316")))
		transfer_in = QString("log316");
	else if (VideoInfo::getTransfer().contains(QString("smpte170m")))
		transfer_in = QString("709"); // patch
	else if (VideoInfo::getTransfer().contains(QString("smpte240m")))
		transfer_in = QString("240m");
	else if (VideoInfo::getTransfer().contains(QString("smpte2084")))
		transfer_in = QString("st2084");
	else
		transfer_in = QString("709");

	if (VideoInfo::getPrimaries().contains(QString("bt709")))
		primaries_in = QString("709");
	else if (VideoInfo::getPrimaries().contains(QString("bt470m")))
		primaries_in = QString("470m");
	else if (VideoInfo::getPrimaries().contains(QString("bt470bg")))
		primaries_in = QString("470bg");
	else if (VideoInfo::getPrimaries().contains(QString("smpte170m")))
		primaries_in = QString("170m");
	else if (VideoInfo::getPrimaries().contains(QString("smpte240m")))
		primaries_in = QString("240m");
	else if (VideoInfo::getPrimaries().contains(QString("bt2020")))
		primaries_in = QString("2020");
	else
		primaries_in = QString("709");

	if (VideoInfo::getColors().contains(QString("8-bit")))
		format = QString("YUV420P8");
	else if (VideoInfo::getColors().contains(QString("10-bit")))
		format = QString("YUV420P10");
	else
		format = QString("YUV420P8");

	ScriptBuilder::setInclude();
	ScriptBuilder::setPlugin(QDir::toNativeSeparators(QDir::currentPath() + QString("\\vs\\plugins\\liblsmashsource.dll")));

	if (CHECKED(_ui.UpscaleSetGB))
		ScriptBuilder::setPlugin(QDir::toNativeSeparators(QDir::currentPath() + QString("\\vs\\plugins\\libsrmdnv.dll")));

	if (CHECKED(_ui.InterpSetGB)) {
		if (CHECKED(_ui.USeAICB))
			ScriptBuilder::setPlugin(QDir::toNativeSeparators(QDir::currentPath() + QString("\\vs\\plugins\\librife.dll")));
		else {
			ScriptBuilder::setPlugin(QDir::toNativeSeparators(QDir::currentPath() + QString("\\vs\\plugins\\libsvpflow.1.dll")));
			ScriptBuilder::setPlugin(QDir::toNativeSeparators(QDir::currentPath() + QString("\\vs\\plugins\\libsvpflow.2.dll")));
		}
	}

	ScriptBuilder::setInput(_ui.SelectInTxtBox->text(), jobID);

	if (CHECKED(_ui.InterpSetGB)) {
		double inFPS = VideoInfo::getFrameRate().toDouble();
		double outFPS = _ui.OutFPSDD->currentText().toDouble();

		if (CHECKED(_ui.USeAICB)) {
			if (inFPS != outFPS) {
				ScriptBuilder::setRGB(matrix_in, transfer_in, primaries_in);
				ScriptBuilder::setSCDetect(QString("0.14"));
				ScriptBuilder::setRIFE(_ui.OutFPSDD->currentText().toInt(), 0, 2, QString("False"), QString("False"), QString("True"));
				ScriptBuilder::setColorsOut(format, matrix_in, transfer_in, primaries_in);
			}
		}
		else {
			if (inFPS != outFPS) {
				ScriptBuilder::setColorsInOut(QString("YUV420P8"), matrix_in, transfer_in, primaries_in, QString("709"), QString("709"), QString("709"));
				
				if ((int)outFPS % (int)inFPS != 0)
					ScriptBuilder::setSVPFlow(_ui.OutFPSDD->currentText().toInt(), 1, 0);
				else
					ScriptBuilder::setSVPFlow(_ui.OutFPSDD->currentText().toInt(), 1, 1);

				ScriptBuilder::setColorsOut(format, matrix_in, transfer_in, primaries_in);
			}
		}
	}
	else if (CHECKED(_ui.UpscaleSetGB)) {
		int scale = 2;
		int outH = _ui.OutputResDD->currentText().remove(QString("(")).remove(QString(")")).remove(QString("p")).remove(QString("HD")).remove(QString("F")).remove(QString("Q")).remove(QString("U")).remove(QString("4K")).remove(QString(" ")).toInt();
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

		ScriptBuilder::setRGB(matrix_in, transfer_in, primaries_in);

		if (VideoInfo::getWidth() * 2 < outW && VideoInfo::getWidth() * 3 >= outW)
			scale = 3;
		else if (VideoInfo::getWidth() * 3 < outW && VideoInfo::getWidth() * 4 >= outW)
			scale = 4;

		ScriptBuilder::setSRMD(scale, 3, 0, 2, QString("False"));
		ScriptBuilder::setColorsOut(format, matrix_in, transfer_in, primaries_in);
	}

	ScriptBuilder::setConcludeClip();

	return(ScriptBuilder::getScript());
}

int FrameGUI::decimalCounter(QString value) {
	int index = value.indexOf(QString("."));
	int count = value.remove(QString(".")).length();

	return(count - index);
}