#include "AudioSubInfoRegex.h"

QList<QRegularExpression> AudioSubInfoRegex::Indexer;

QString AudioSubInfoRegex::AudioCodec;
QString AudioSubInfoRegex::AudioStreams;

QString AudioSubInfoRegex::SubCodec;
QString AudioSubInfoRegex::SubStreams;

void AudioSubInfoRegex::SetupPattern() {
	Indexer << QRegularExpression("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Audio:\\s?(\\w*)[^,]*,?\\s?([^\\s]*)\\sHz,\\s?([^,]*),?");
	Indexer << QRegularExpression("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Subtitle:\\s?([^\\s]*)");
}

void AudioSubInfoRegex::AudioInfoRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPattern();

	QRegularExpressionMatch matchAudioInfo = Indexer.at(GetInfo::Audio).match(output);

	if (!matchAudioInfo.hasMatch())
		return;
	else {
		AudioCodec = matchAudioInfo.captured(3);
		AudioStreams = matchAudioInfo.captured(1);

		if (AudioCodec.contains("vorbis"))
			AudioCodec = "Vorbis";
		else if (AudioCodec.contains("pcm"))
			AudioCodec = "PCM";
		else if (AudioCodec.contains("truehd"))
			AudioCodec = "TrueHD";
		else if (AudioCodec.contains("opus"))
			AudioCodec = "Opus";
		else if (AudioCodec.isEmpty())
			AudioCodec = "?";
		else
			AudioCodec = AudioCodec.toUpper();

#ifdef AUDIOINFO_H
		AudioInfo::AddStream();
		AudioInfo::SetCodec(AudioCodec);
		AudioInfo::SetStream(AudioStreams);
#endif // AUDIOINFO_H
	}
}

void AudioSubInfoRegex::SubInfoRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPattern();

	QRegularExpressionMatch matchSubtitleInfo = Indexer.at(GetInfo::Subtitle).match(output);

	if (!matchSubtitleInfo.hasMatch())
		return;
	else {
		SubStreams = matchSubtitleInfo.captured(1);
		SubCodec = matchSubtitleInfo.captured(3);

#ifdef SUBTITLEINFO_H
		SubtitleInfo::AddStreams();
		SubtitleInfo::SetStream(SubStreams);
		SubtitleInfo::SetCodec(SubCodec);
#endif // SUBTITLEINFO_H
	}
}