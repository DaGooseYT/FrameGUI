#pragma once

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QtCore/QString>

class Argument {
protected:
	static QString videoCodec(QString codec);
	static QString audioCodec(QString codec);
	static QString subtitleCodec(QString codec);
	static QString override();
	static QString input();
	static QString mapAll(QString type, QString s1);
	static QString metaData1();
	static QString metaData2(QString str);
	static QString constantRateFactor(int crf);
	static QString videoResolution(int width, int height);
	static QString noAutoRotate();
	static QString appleTag();
	static QString vs();

	#ifdef Q_OS_WINDOWS
	static QString vsPipe1();
	static QString vsPipe2();
	#endif
};

#endif // !ARGUMENT_H