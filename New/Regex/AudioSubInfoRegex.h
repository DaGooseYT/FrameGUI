#pragma once

#ifndef AUDIOSUBINFOREGEX_H
#define AUDIOSUBINFOREGEX_H

#include "..\IO\AudioInfo.h"
#include "..\IO\SubtitleInfo.h"

#include <QtCore/QRegularExpression>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <QtCore/QList>

class AudioSubInfoRegex {
public:
	static void AudioInfoRegex(QString);
	static void SubInfoRegex(QString);

private:
	enum GetInfo {
		Audio = 0,
		Subtitle = 1
	};

	static QString AudioCodec;
	static QString AudioLanguage;
	static QString SampleRate;
	static QString Channels;
	static QString AudioStreams;

	static QString SubCodec;
	static QString SubLanguage;
	static QString SubStreams;

	static QList<QRegularExpression> Indexer;

	static void SetupPattern();
};

#endif // !AUDIOSUBINFOREGEX_H