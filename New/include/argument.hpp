#pragma once

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QtCore/QString>

class Argument {
protected:
	static QString videoCodec(QString codec);
	static QString audioCodec(QString codec);
	static QString pixelFormat(QString format);
	static QString ffmpeg(QString path);
	static QString override();
	static QString input(QString path);
	static QString output(QString path);
	static QString mapVideo(QString type, QString s1, int s2);
	static QString mapAll(QString type, QString s1);
	static QString enableFilters();
	static QString addComma();
	static QString addColin();
	static QString concludeFilters();
	static QString constantRateFactor(int crf);
	static QString videoResolution(int width, int height);
	static QString noAutoRotate();
	static QString vsPipe(QString vspipe, QString vsscript);
};

#endif // !ARGUMENT_H