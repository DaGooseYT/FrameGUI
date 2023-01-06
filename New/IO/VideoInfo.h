#pragma once

#ifndef VIDEOINFO_H
#define VIDEOINFO_H

#include <QtCore/QTime>
#include <QtCore/QString>

class VideoInfo {
public:
	static void SetVideoCodec(QString);
	static void SetDuration(QTime);
	static void SetDurationStrng(QString);
	static void SetWidth(int);
	static void SetHeight(int);
	static void SetColors(QString);
	static void SetMatrix(QString);
	static void SetTransfer(QString);
	static void SetPrimaries(QString);
	static void SetFrameRate(QString);

	static QString GetVideoCodec();
	static QTime GetDuration();
	static QString GetDurationStrng();
	static int GetWidth();
	static int GetHeight();
	static QString GetColors();
	static QString GetMatrix();
	static QString GetTransfer();
	static QString GetPrimaries();
	static QString GetFrameRate();

	static void ClearAll();

private:
	static QString VideoCodec;
	static QTime Duration;
	static QString DurationStrng;
	static int Width;
	static int Height;
	static QString Colors;
	static QString Matrix;
	static QString Transfer;
	static QString Primaries;
	static QString FrameRate;
};

#endif // !VIDEOINFO_H