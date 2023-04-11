#include "audioinfo.hpp"

QStringList AudioInfo::_codec;
QStringList AudioInfo::_stream;
int AudioInfo::_streams;

/// <summary>
/// Adds the audio codec to the audio info list.
/// </summary>
/// <param name="codec">The audio codec.</param>
void AudioInfo::setCodec(QString codec) {
	_codec << codec;
}

/// <summary>
/// Adds the audio strream number to the audio info list.
/// </summary>
/// <param name="stream">The audio stream number.</param>
void AudioInfo::setStream(QString stream) {
	_stream << stream;
}

/// <summary>
/// Gets the audio codec from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns>The audio codec.</returns>
QString AudioInfo::getCodec(int index) {
	return(_codec.at(index));
}

/// <summary>
/// Gets the audio stream identifier from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns></returns>
QString AudioInfo::getStream(int index) {
	return(_stream.at(index));
}

/// <summary>
/// Gets the total number of audio streams counted.
/// </summary>
/// <returns>The total number of streams.</returns>
int AudioInfo::totalStreams() {
	return(_streams);
}

/// <summary>
/// Adds an audio stream to info.
/// </summary>
void AudioInfo::addStream() {
	_streams++;
}

/// <summary>
/// Resets all private variables.
/// </summary>
void AudioInfo::clearAll() {
	_codec.clear();
	_stream.clear();
	_streams = 0;
}