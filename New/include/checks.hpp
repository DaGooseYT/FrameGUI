#pragma once

#ifndef CHECKS_H
#define CHECKS_H

#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDir>

// video
#define AVC 0
#define HEVC 1
#define PRORES 2
#define THEORA 3
#define VP9 4
#define VC1 5
#define MPEG2 6
#define MPEG4 7

// audio
#define AAC 0
#define MP3 1
#define AC3 2
#define FLAC 3
#define VORBIS 4
#define OPUS 5
#define DTS 6
#define TRUEHD 7
#define EAC3 8
#define ALAC 9
#define WMA 10
#define PCM 11
#define MP2 12

class Checks {
public:
	static bool checkVsScript(QString path);
	static bool checkInputExists(QString path);
	static bool checkInput(QString path);
	static bool checkOutput(QString path);
	static bool checkOutputOverwrite(QString path);
	static bool checkAudioCompatability(int format, QString container);
	static bool checkSubtitleCompatability(QString format, QString container);
	static bool fileCheck(QString path);
};

#endif // !CHECKS_H