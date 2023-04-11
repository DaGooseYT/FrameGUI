#include "audiosubinforegex.hpp"

QList<QRegularExpression> AudioSubInfoRegex::_indexer;

QString AudioSubInfoRegex::_audioCodec;
QString AudioSubInfoRegex::_audioStreams;

QString AudioSubInfoRegex::_subCodec;
QString AudioSubInfoRegex::_subStreams;

void AudioSubInfoRegex::setupPattern() {
	_indexer << QRegularExpression(QString("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Audio:\\s?(\\w*)[^,]*,?\\s?([^\\s]*)\\sHz,\\s?([^,]*),?"));
	_indexer << QRegularExpression(QString("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Subtitle:\\s?([^\\s]*)"));
}

void AudioSubInfoRegex::audioInfoRegex(QString output) {
	if (_indexer.isEmpty())
		setupPattern();

	QRegularExpressionMatch matchAudioInfo(_indexer.at(GetInfo::Audio).match(output));

	if (!matchAudioInfo.hasMatch())
		return;
	else {
		_audioCodec = matchAudioInfo.captured(3);
		_audioStreams = matchAudioInfo.captured(1);

		if (_audioCodec.contains(QString("vorbis")))
			_audioCodec = QString("Vorbis");
		else if (_audioCodec.contains(QString("pcm")))
			_audioCodec = QString("PCM");
		else if (_audioCodec.contains(QString("truehd")))
			_audioCodec = QString("TrueHD");
		else if (_audioCodec.contains(QString("opus")))
			_audioCodec = QString("Opus");
		else if (_audioCodec.isEmpty())
			_audioCodec = QString("?");
		else
			_audioCodec = _audioCodec.toUpper();

#ifdef AUDIOINFO_H
		AudioInfo::addStream();
		AudioInfo::setCodec(_audioCodec);
		AudioInfo::setStream(_audioStreams);
#endif // AUDIOINFO_H
	}
}

void AudioSubInfoRegex::subInfoRegex(QString output) {
	if (_indexer.isEmpty())
		setupPattern();

	QRegularExpressionMatch matchSubtitleInfo(_indexer.at(GetInfo::Subtitle).match(output));

	if (!matchSubtitleInfo.hasMatch())
		return;
	else {
		_subStreams = matchSubtitleInfo.captured(1);
		_subCodec = matchSubtitleInfo.captured(3);

#ifdef SUBTITLEINFO_H
		SubtitleInfo::addStreams();
		SubtitleInfo::setStream(_subStreams);
		SubtitleInfo::setCodec(_subCodec);
#endif // SUBTITLEINFO_H
	}
}