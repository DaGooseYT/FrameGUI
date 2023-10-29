#pragma once

#ifndef VIDEOINFOLIST_H
#define VIDEOINFOLIST_H

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QTime>

class VideoInfoList {
public:
	static void setDuration(QTime duration);
	static void setFrameRate(QString frameRate);
	static QTime getDuration(int index);
	static QString getFrameRate(int index);
	static void removeDuration(int index);
	static void removeFrameRate(int index);
	static void clearAll();

private:
	static QList<QTime> _duration;
	static QStringList _frameRate;
};

#endif // !VIDEOINFOLIST_H