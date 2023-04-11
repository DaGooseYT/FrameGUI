#pragma once

#ifndef MEDIACONFIG_H
#define MEDIACONFIG_H

#include "argument.hpp"
#include <QtCore/QStringList>

class MediaConfig : protected Argument {
public:
	static QString getArguments();
	static void append(QString string);
	static void setVideoCodec(QString codec);
	static void setAudioCodec(QString codec);
	static void setMap(QString type, QString s1, int s2);
	static void setMapAll(QString type, QString s1);
	static void setConstantRateFactor(int crf);
	static void setVideoResolution(int width, int height);
	static void setNoAutoRotate();
	static void setVSPipe(QString vspipe, QString vsscript);
	static void setFFMpeg(QString path);
	static void setOverride();
	static void setInput(QString path);
	static void setOutput(QString path);
	static void setComma();
	static void setColin();
	static void setFilters();
	static void setConcludeFilters();
	static void resetArguments();

private:
	static QString _argumentList;
};

#endif // !MEDIACONFIG_H