#include "videoinforegex.hpp"

QList<QRegularExpression> VideoInfoRegex::_indexer;
QString VideoInfoRegex::_durationLine;

void VideoInfoRegex::setupPatterns() {
	_indexer << QRegularExpression(QString("(\\s*?Duration:\\s[0-9]*:[0-9]*:[^\\.]*\\.[^,]*,\\s?start:\\s?-?[0-9]*\\.[^,]*,\\s?bitrate:\\s?[0-9]*\\s?kb/s)")); // duration/bitrate
	_indexer << QRegularExpression(QString("Stream\\s#0:[0-9]*[^V]*Video:\\s*([^,]*)[^(]*\\(?([^)]*)\\)?,\\s?[^\\s]*[^,]*?,?\\s?[^\\s]*")); // video info line
	_indexer << QRegularExpression(QString("\\s?([0-9]*)\\s?kb/s")); // bitrate
	_indexer << QRegularExpression(QString("([0-9]*):([0-9]*):([0-9]*)\\.([^,]*)")); // duration
	_indexer << QRegularExpression(QString("([^,/]*),?([^,/]*),?/?([^/\\s]*)/?([^/\\s]*),?")); // colors
	_indexer << QRegularExpression(QString("(\\d*\\.?\\d*?)\\s?fps")); // fps
	_indexer << QRegularExpression(QString("(\\d*\\.?\\d*?)\\s?tbr")); // tbr
	_indexer << QRegularExpression(QString("\\s(\\d*[0-9]*)x(\\d*)\\s?,?")); // resolution
	_indexer << QRegularExpression(QString("\\)?,\\s([a-z]*)([0-9])([0-9])([0-9])p([0-9]*)\\w*,?\\(?")); // pixel format
	_indexer << QRegularExpression(QString("(Stream\\s#0:[0-9]*[^V]*Video:\\s*[^,]*)")); // video info (part)
	_indexer << QRegularExpression(QString("([^\\s]*)")); // codec 
	_indexer << QRegularExpression(QString("\\[[0-9]\\s([^\\]]*)\\]\\s*queueC=")); // gpu
}

void VideoInfoRegex::durationBitrateRegex(QString output) {
	if (_indexer.isEmpty())
		setupPatterns();

	QRegularExpressionMatch matchDuration(_indexer.at(GetInfo::DurationBitrate).match(output));

	if (!matchDuration.hasMatch())
		return;
	else
		_durationLine = matchDuration.captured(1);
}

void VideoInfoRegex::videoInfoerRegex(QString output) {
	if (output.contains(QString("attached pic")) || output.contains(QString("mjpeg")) || output.contains(QString("png")) || output.contains(QString("gif")) || output.contains(QString("tiff")) || output.contains(QString("bmp")) ||
		output.contains(QString("heic")) || output.contains(QString("tga")) || output.contains(QString("webp")) || output.contains(QString("avif")))
		return;

	QRegularExpressionMatch matchVideoInfo(_indexer.at(GetInfo::VideoInfo).match(output));

	QString durationStrng, colors, matrix, transfer, primaries, frameRate;
	QTime duration;
	int width, height;

	if (!matchVideoInfo.hasMatch())
		return;
	else {
		QString remove(_indexer.at(GetInfo::VideoInfoPart).match(output).captured(1));
		QString videoCodec(_indexer.at(GetInfo::Codec).match(matchVideoInfo.captured(1)).captured(1));

		if (!_durationLine.isEmpty()) {
			durationStrng = QString("%1:%2:%3.%4").arg(_indexer.at(GetInfo::Duration).match(_durationLine).captured(1)).arg(_indexer.at(GetInfo::Duration).match(_durationLine).captured(2)).
				arg(_indexer.at(GetInfo::Duration).match(_durationLine).captured(3)).arg(_indexer.at(GetInfo::Duration).match(_durationLine).captured(4));
			duration = QTime(_indexer.at(GetInfo::Duration).match(_durationLine).captured(1).toInt(), _indexer.at(GetInfo::Duration).match(_durationLine).captured(2).toInt(),
				_indexer.at(GetInfo::Duration).match(_durationLine).captured(3).toInt(), _indexer.at(GetInfo::Duration).match(_durationLine).captured(4).toInt());
		}

		if (!_indexer.at(GetInfo::PixFormat).match(output).captured(2).isEmpty()) {
			colors = _indexer.at(GetInfo::PixFormat).match(output).captured(2) + QString(':') + _indexer.at(GetInfo::PixFormat).match(output).captured(3) +
				QString(':') + _indexer.at(GetInfo::PixFormat).match(output).captured(4) + QString('/');

			if (_indexer.at(GetInfo::PixFormat).match(output).captured(5).isEmpty())
				colors += QString("8-bit");
			else
				colors += _indexer.at(GetInfo::PixFormat).match(output).captured(5) + QString("-bit");
		}
		else
			colors = QString("?");

		width = _indexer.at(GetInfo::Resolution).match(output.remove(remove)).captured(1).toInt();
		height = _indexer.at(GetInfo::Resolution).match(output.remove(remove)).captured(2).toInt();

		if (_indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(2).isEmpty())
			matrix = _indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(1);
		else
			matrix = _indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(2);

		transfer = _indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(4);
		primaries = _indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(3);

		if (!_indexer.at(GetInfo::Fps).match(output).hasMatch())
			frameRate = _indexer.at(GetInfo::Tbr).match(output).captured(1);
		else
			frameRate = _indexer.at(GetInfo::Fps).match(output).captured(1);

		if (matrix.contains(QString("progressive")) || matrix.contains(QString("interlaced")) || matrix.contains(QString("tv")) ||
			matrix.contains(QString("top first")) || matrix.contains(QString("full")) || matrix.isEmpty()) {

			matrix = QString("?");
		}
		if (transfer.isEmpty())
			transfer = QString("?");
		if (primaries.isEmpty())
			primaries = QString("?");
		if (videoCodec.isEmpty())
			videoCodec = QString("?");

		transfer.remove(QString(','));
		videoCodec.remove(QString(','));

		if (videoCodec.contains(QString("h264")))
			videoCodec = QString("AVC");
		if (videoCodec.contains(QString("theora")))
			videoCodec = QString("Theora");
		else if (videoCodec.contains(QString("prores")))
			videoCodec = QString("ProRes");
		else if (videoCodec.contains(QString("video")))
			videoCodec = videoCodec.remove(QString("video")).toUpper();
		else if (videoCodec.contains(QString("huffyuv")))
			videoCodec = QString("HuffYUV");
		else
			videoCodec = videoCodec.toUpper();

		if (frameRate.isEmpty())
			frameRate = QString("?");
		if (durationStrng.isEmpty())
			durationStrng = QString("?");

		if (frameRate.contains(QString("23.98")))
			frameRate = QString("23.976"); // assume
		if (frameRate.contains(QString("47.96")))
			frameRate = QString("47.952"); // assume
		if (frameRate.contains(QString("95.91")))
			frameRate = QString("95.904"); // assume

#ifdef VIDEOINFO_H
		VideoInfo::setVideoCodec(videoCodec);
		VideoInfo::setDuration(duration);
		VideoInfo::setDurationStrng(durationStrng);
		VideoInfo::setWidth(width);
		VideoInfo::setHeight(height);
		VideoInfo::setColors(colors);
		VideoInfo::setMatrix(matrix);
		VideoInfo::setTransfer(transfer);
		VideoInfo::setPrimaries(primaries);
		VideoInfo::setFrameRate(frameRate);
#endif // PROGRESSINFO_H
	}
}