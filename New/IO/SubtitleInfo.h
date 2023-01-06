#pragma once

#ifndef SUBTITLEINFO_H
#define SUBTITLEINFO_H

#include <QtCore/QStringList>
#include <QtCore/QString>

class SubtitleInfo {
public:
	static void SetStream(QString);
	static void SetCodec(QString);
	static void SetChapter(bool);

	static QString GetStream(int);
	static QString GetCodec(int);
	static bool GetChapter();

	static int TotalStreams();
	static void AddStreams();
	static void ClearAll();
	static bool IsEmpty();

private:
	static QStringList Stream;
	static QStringList Codec;
	static int Streams;
	static bool Chapter;
};

#endif // !SUBTITLEINFO_H