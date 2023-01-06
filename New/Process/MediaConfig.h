#pragma once

#ifndef MEDIACONFIG_H
#define MEDIACONFIG_H

#include "../Arguments/Argument.h"
#include <QStringList>

class MediaConfig : protected Argument {
public:
	static QString GetArguments();
	static void Append(QString);
	static void SetVideoCodec(QString);
	static void SetAudioCodec(QString);
	static void SetMap(QString, QString, int);
	static void SetMapAll(QString, QString);
	static void SetConstantRateFactor(int);
	static void SetVideoResolution(int, int);
	static void SetNoAutoRotate();
	static void SetVSPipe(QString, QString);
	static void SetFFMpeg(QString);
	static void SetOverride();
	static void SetInput(QString);
	static void SetOutput(QString);
	static void SetComma();
	static void SetColin();
	static void SetFilters();
	static void SetConcludeFilters();
	static void ResetArguments();

private:
	static QString ArgumentList;
};

#endif // !MEDIACONFIG_H