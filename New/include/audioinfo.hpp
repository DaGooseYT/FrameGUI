#pragma once

#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <QtCore/QStringList>

class AudioInfo {
public:
	static void setCodec(QString codec);
	static void setStream(QString stream);

	static QString getCodec(int index);
	static QString getStream(int index);

	static int totalStreams();
	static void addStream();

	static void clearAll();

private:
	static QStringList _codec;
	static QStringList _stream;
	static int _streams;
};

#endif // !AUDIOINFO_H