#pragma once

#ifndef SCRIPTBUILDER_H
#define SCRIPTBUILDER_H

#include "..\VS\VapourSynth.h"

#include <QtCore/QString>

class ScriptBuilder : protected VapourSynth {
public:
	static QString GetScript();
	static void SetRIFE(int, int, int, QString, QString, QString);
	static void SetSRMD(int, int, int, int, QString);
	static void SetRGB(QString, QString, QString);
	static void SetColorsInOut(QString, QString, QString, QString, QString, QString, QString);
	static void SetColorsOut(QString, QString, QString, QString);
	static void SetSCDetect(QString);
	static void SetPlugin(QString);
	static void SetInput(QString, QString);
	static void SetInclude();
	static void SetConcludeClip();
	static void SetNewLine();
	static void ClearScript();

private:
	static QString ScriptList;
};

#endif // !SCRIPTBUILDER_H