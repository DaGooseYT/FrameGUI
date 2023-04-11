#pragma once

#ifndef PROGRESSINFOREGEX_H
#define PROGRESSINFOREGEX_H

#include "progressinfo.hpp"

#include <QtCore/QRegularExpression>
#include <QtCore/QElapsedTimer>
#include <QtCore/QTime>
#include <QtCore/QList>

class ProgressInfoRegex {
public:
	static bool progressRegex(QString output, QTime totalDuration, int totalFrames, QElapsedTimer timer, QTime pause);

private:
	enum GetInfo {
		Frame = 0,
		Fps = 1,
		Bitrate = 2,
		Time = 3
	};

	static QList<QRegularExpression> _indexer;

	static void setupPatterns();
};

#endif // !PROGRESSINFOREGEX_H