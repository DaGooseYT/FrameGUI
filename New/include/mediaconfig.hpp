#pragma once

#ifndef MEDIACONFIG_H
#define MEDIACONFIG_H

#include <QtCore/QStringList>
#include "argument.hpp"

class MediaConfig : protected Argument {
public:
	static QStringList getArguments();
	static void append(QString string);
	static void setVideoCodec(QString codec);
	static void setAudioCodec(QString codec);
	static void setSubtitleCodec(QString codec);
	static void setMapAll(QString type, QString s1);
	static void setConstantRateFactor(int crf);
	static void setVideoResolution(int width, int height);
	static void setMetaData1();
	static void setMetaData2(QString str);
	static void setNoAutoRotate();
	static void setOverride();
	static void setInput();
	static void setOutput(QString path);
	static void setAppleTag();
	static void setVs();
	static void resetArguments();

	#ifdef Q_OS_WINDOWS
	static void setVsPipe1();
	static void setVsPipe2();
	#endif

private:
	static QStringList _argumentList;

	static QStringList splitSpace(QString args);
};

#endif // !MEDIACONFIG_H