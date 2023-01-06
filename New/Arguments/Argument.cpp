#include "Argument.h"

/// <summary>
/// Creates an argument for the video codec.
/// </summary>
/// <param name="codec">The video codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VideoCodec(QString codec) {
	return QString(" -c:v %1").arg(codec);
}

/// <summary>
/// Creates an argument for the audio codec.
/// </summary>
/// <param name="codec">The audio codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioCodec(QString codec) {
	return QString(" -c:a %1").arg(codec);
}

/// <summary>
/// The pixel format for the video to be processed in.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::PixelFormat(QString format) {
	return QString(" -pix_fmt %1").arg(format);
}

/// <summary>
/// Sets the path to ffmpeg.
/// </summary>
/// <param name="path">The file path to ffmpeg.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::FFMpeg(QString path) {
	return QString("\"%1\"").arg(path);
}

/// <summary>
/// Overrides the output file.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::Override() {
	return QString(" -y");
}

/// <summary>
/// Sets the source video to encode.
/// </summary>
/// <param name="path">The path to the input file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Input(QString path) {
	return QString(" -i \"%1\"").arg(path);
}

/// <summary>
/// Saves the output to a specified destination.
/// </summary>
/// <param name="path">The path to the output file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Output(QString path) {
	return QString(" \"%1\"").arg(path);
}

/// <summary>
/// Maps a stream to a media file.
/// </summary>
/// <param name="type">The stream type.</param>
/// <param name="s1">Stream 1 selection.</param>
/// <param name="s2">Stream 2 selection.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::MapVideo(QString type, QString s1, int s2) {
	return QString(" -map %1:%2:%3").arg(s1).arg(type).arg(s2);
}

/// <summary>
/// Maps all of a particular stream in a video container. 
/// </summary>
/// <param name="type">The stream type to target.</param>
/// <param name="s1">Stream one identifier.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::MapAll(QString type, QString s1) {
	return QString(" -map %1:%2").arg(s1).arg(type);
}

/// <summary>
/// Enables FFMpeg filters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::EnableFilters() {
	return QString(" -filter:v \"");
}

/// <summary>
/// Adds a comma to seperate video filters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::AddComma() {
	return QString(", ");
}

/// <summary>
/// Adds a colin to an argument.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::AddColin() {
	return QString(":");
}

/// <summary>
/// Concludes the filters list by adding a quotation mark.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::ConcludeFilters() {
	return QString("\"");
}

/// <summary>
/// Sets the constant rate factor value of the video.
/// </summary>
/// <param name="crf">The constant rate factor value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::ConstantRateFactor(int crf) {
	return QString(" -crf %1").arg(crf);
}

/// <summary>
/// Sets the video resolution to the specified value.
/// </summary>
/// <param name="width">The selected width of the video.</param>
/// <param name="height">The selected height of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VideoResolution(int width, int height) {
	return QString("scale=%1x%2").arg(width).arg(height);
}

/// <summary>
/// Disabled the auto rotate feature in FFMpeg.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::NoAutoRotate() {
	return QString(" -noautorotate");
}

/// <summary>
/// Configures the pipe for VSPipe.exe.
/// </summary>
/// <param name="vspipe">The path to VSPipe.exe.</param>
/// <param name="vsscript">The path to the VapourSynth script file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VSPipe(QString vspipe, QString vsscript) {
	return QString("\"%1\" -c y4m \"%2\" -").arg(vspipe).arg(vsscript);
}