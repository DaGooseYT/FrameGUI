#pragma once

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QtCore/QString>

class Argument {
protected:
	static QString VideoCodec(QString);
	static QString AudioCodec(QString);
	static QString MapVideo(QString, QString, int);
	static QString MapAll(QString, QString);
	static QString PixelFormat(QString);
	static QString ConstantRateFactor(int);
	static QString VideoResolution(int, int);
	static QString NoAutoRotate();
	static QString VSPipe(QString, QString);
	static QString FFMpeg(QString);
	static QString Override();
	static QString Input(QString);
	static QString Output(QString);
	static QString AddComma();
	static QString AddColin();
	static QString EnableFilters();
	static QString ConcludeFilters();
};

#endif // !ARGUMENT_H