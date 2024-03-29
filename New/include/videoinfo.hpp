#pragma once

#ifndef VIDEOINFO_H
#define VIDEOINFO_H

#include <QtCore/QTime>
#include <QtCore/QString>

class VideoInfo {
public:
	static void setVideoCodec(QString videoCodec);
	static void setDuration(QTime duration);
	static void setDurationStrng(QString duration);
	static void setWidth(int width);
	static void setHeight(int height);
	static void setColors(QString colors);
	static void setMatrix(QString matrix);
	static void setTransfer(QString transfer);
	static void setPrimaries(QString primaries);
	static void setFrameRate(QString frameRate);
	static QString getVideoCodec();
	static QTime getDuration();
	static QString getDurationStrng();
	static int getWidth();
	static int getHeight();
	static QString getColors();
	static QString getMatrix();
	static QString getTransfer();
	static QString getPrimaries();
	static QString getFrameRate();

	static void clearAll();

private:
	static int _width;
	static int _height;
	static QTime _duration;
	static QString _videoCodec;
	static QString _durationStrng;
	static QString _colors;
	static QString _matrix;
	static QString _transfer;
	static QString _primaries;
	static QString _frameRate;
};

#endif // !VIDEOINFO_H