#include "checks.hpp"

/// <summary>
/// Checks to ensure that the audio codec is compatible with the selected output video container.
/// </summary>
/// <param name="format">The audio codec index.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::checkAudioCompatability(int format, QString container) {
	bool result = true;

	switch (format) {
	case AAC:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case MP3:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case AC3:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case FLAC:
		if (container.contains(QString(".mkv")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case VORBIS:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case OPUS:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")))
			result = true;
		else
			result = false;
		break;
	case DTS:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")))
			result = true;
		else
			result = false;
		break;
	case TRUEHD:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")))
			result = true;
		else
			result = false;
		break;
	case EAC3:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")))
			result = true;
		else
			result = false;
		break;
	case ALAC:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")))
			result = true;
		else
			result = false;
		break;
	case WMA:
		if (container.contains(QString(".mkv")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case PCM:
		if (container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	case MP2:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		else
			result = false;
		break;
	}

	return(result);
}

/// <summary>
/// Checks to ensure that the subtitle codec is compatible with the selected output container.
/// </summary>
/// <param name="format">The subtitle codec.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::checkSubtitleCompatability(QString format, QString container) {
	bool result = false;

	if ((format.contains(QString("subrip")) || format.contains(QString("srt"))) && container.contains(QString(".mkv"))) {
		result = true;
		return result;
	}
	else
		result = false;
	if (format.contains(QString("webvtt")) && container.contains(QString(".mkv"))) {
		result = true;
		return result;
	}
	else
		result = false;
	if ((format.contains(QString("ass")) || format.contains(QString("ssa"))) && container.contains(QString(".mkv"))) {
		result = true;
		return result;
	}
	else
		result = false;
	if (format.contains(QString("mov_text")) && (container.contains(QString(".mp4")) || container.contains(QString(".mov")))) {
		result = true;
		return result;
	}
	else
		result = false;

	return(result);
}