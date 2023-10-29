#include "argument.hpp"

/// <summary>
/// Creates an argument for the video codec.
/// </summary>
/// <param name="codec">The video codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoCodec(QString codec) {
	return(QString("-c:v %1").arg(codec));
}

/// <summary>
/// Creates an argument for the audio codec.
/// </summary>
/// <param name="codec">The audio codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioCodec(QString codec) {
	return(QString("-c:a %1").arg(codec));
}

/// <summary>
/// Creates an argument for the subtitle codec.
/// </summary>
/// <param name="codec">The subtitle codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleCodec(QString codec) {
	return(QString("-c:s %1").arg(codec));
}

/// <summary>
/// Overrides the output file.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::override() {
	return(QString("-y"));
}

/// <summary>
/// Sets the source video to encode.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::input() {
	return(QString("-i"));
}

/// <summary>
/// Maps all of a particular stream in a video container. 
/// </summary>
/// <param name="type">The stream type to target.</param>
/// <param name="s1">Stream one identifier.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::mapAll(QString type, QString s1) {
	return(QString("-map %1:%2").arg(s1).arg(type));
}

/// <summary>
/// Sets the constant rate factor value of the video.
/// </summary>
/// <param name="crf">The constant rate factor value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantRateFactor(int crf) {
	return(QString("-crf %1").arg(crf));
}

/// <summary>
/// Sets the video resolution to the specified value.
/// </summary>
/// <param name="width">The selected width of the video.</param>
/// <param name="height">The selected height of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoResolution(int width, int height) {
	return(QString("-filter:v scale=%1x%2").arg(width).arg(height));
}

/// <summary>
/// Writes string metadata to the video file.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::metaData1() {
	return(QString("-metadata:g"));
}

/// <summary>
/// Writes string metadata to the video file.
/// </summary>
/// <param name="str">The string to write.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::metaData2(QString str) {
	return(QString("encoding_tool=%1").arg(str));
}

/// <summary>
/// Disables the auto rotate feature in FFMpeg.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::noAutoRotate() {
	return(QString("-noautorotate"));
}

/// <summary>
/// Adds tag for "Apple industry standard" HEVC videos.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::appleTag() {
	return(QString("-tag:v hvc1"));
}

/// <summary>
/// Enables vapoursynth script input.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::vs() {
	return(QString("-f vapoursynth"));
}

#ifdef Q_OS_WINDOWS
/// <summary>
/// Configures the pipe for vspipe.exe.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::vsPipe1() {
	return(QString("-c"));
}

/// <summary>
/// Configures the pipe for vspipe.exe.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::vsPipe2() {
	return(QString("y4m"));
}
#endif