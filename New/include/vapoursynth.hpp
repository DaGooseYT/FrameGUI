#pragma once

#ifndef VAPOURSYNTH_H
#define VAPOURSYNTH_H

#include <QtCore/QString>

class VapourSynth {
protected:
	static QString rife(int multi, int id, int thread, QString tta, QString uhd, QString sc);
	static QString srmd(int scale, int noise, int id, int thread, QString tta);
	static QString svpflow(int num, int den, int mode);
	static QString rgb(QString matrix, QString transfer, QString primaries);
	static QString colorsInOut(QString format, QString matrix_in, QString transfer_in, QString primaries_in, QString matrix, QString transfer, QString primaries);
	static QString colorsOut(QString format, QString matrix, QString transfer, QString primaries);
	static QString scDetect(QString threshold);
	static QString plugin(QString path);
	static QString input(QString path, QString id);
	static QString include();
	static QString concludeClip();
	static QString newLine();
};

#endif // !VAPOURSYNTH_H