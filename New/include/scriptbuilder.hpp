#pragma once

#ifndef SCRIPTBUILDER_H
#define SCRIPTBUILDER_H

#include "vapoursynth.hpp"

#include <QtCore/QString>

class ScriptBuilder : protected VapourSynth {
public:
	static QString getScript();
	static void setRIFE(int multi, int id, int thread, QString tta, QString uhd, QString sc);
	static void setSRMD(int scale, int noise, int id, int thread, QString tta);
	static void setRGB(QString matrix, QString transfer, QString primaries);
	static void setSVPFlow(int num, int den, int mode);
	static void setColorsInOut(QString format, QString matrix_in, QString transfer_in, QString primaries_in, QString matrix, QString transfer, QString primaries);
	static void setColorsOut(QString format, QString matrix, QString transfer, QString primaries);
	static void setSCDetect(QString threshold);
	static void setPlugin(QString path);
	static void setInput(QString path, QString id);
	static void setInclude();
	static void setConcludeClip();
	static void setNewLine();
	static void clearScript();

private:
	static QString _scriptList;
};

#endif // !SCRIPTBUILDER_H