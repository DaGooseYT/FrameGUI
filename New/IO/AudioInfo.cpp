#include "AudioInfo.h"

QStringList AudioInfo::Codec;
QStringList AudioInfo::Stream;
int AudioInfo::Streams;

/// <summary>
/// Adds the audio codec to the audio info list.
/// </summary>
/// <param name="codec">The audio codec.</param>
void AudioInfo::SetCodec(QString codec) {
	Codec << codec;
}

/// <summary>
/// Adds the audio strream number to the audio info list.
/// </summary>
/// <param name="stream">The audio stream number.</param>
void AudioInfo::SetStream(QString stream) {
	Stream << stream;
}

/// <summary>
/// Gets the audio codec from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns>The audio codec.</returns>
QString AudioInfo::GetCodec(int index) {
	return(Codec.at(index));
}

/// <summary>
/// Gets the audio stream identifier from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns></returns>
QString AudioInfo::GetStream(int index) {
	return(Stream.at(index));
}

/// <summary>
/// Gets the total number of audio streams counted.
/// </summary>
/// <returns>The total number of streams.</returns>
int AudioInfo::TotalStreams() {
	return(Streams);
}

/// <summary>
/// Adds an audio stream to info.
/// </summary>
void AudioInfo::AddStream() {
	Streams++;
}

/// <summary>
/// Resets all private variables.
/// </summary>
void AudioInfo::ClearAll() {
	Codec.clear();
	Stream.clear();
	Streams = 0;
}