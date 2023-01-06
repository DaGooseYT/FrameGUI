#include "MediaConfig.h"

QString MediaConfig::ArgumentList;

void MediaConfig::Append(QString string) {
	ArgumentList.append(string);
}

void MediaConfig::SetVideoCodec(QString codec) {
	ArgumentList.append(Argument::VideoCodec(codec));
}

void MediaConfig::SetAudioCodec(QString codec) {
	ArgumentList.append(Argument::AudioCodec(codec));
}

void MediaConfig::SetMap(QString type, QString s1, int s2) {
	ArgumentList.append(Argument::MapVideo(type, s1, s2));
}

void MediaConfig::SetMapAll(QString type, QString s1) {
	ArgumentList.append(Argument::MapAll(type, s1));
}

void MediaConfig::SetConstantRateFactor(int crf) {
	ArgumentList.append(Argument::ConstantRateFactor(crf));
}

void MediaConfig::SetVideoResolution(int width, int height) {
	ArgumentList.append(Argument::VideoResolution(width, height));
}

void MediaConfig::SetNoAutoRotate() {
	ArgumentList.append(Argument::NoAutoRotate());
}

void MediaConfig::SetVSPipe(QString vspipe, QString vsscript) {
	ArgumentList.append(Argument::VSPipe(vspipe, vsscript));
}

void MediaConfig::SetFFMpeg(QString path) {
	ArgumentList.append(Argument::FFMpeg(path));
}

void MediaConfig::SetInput(QString path) {
	ArgumentList.append(Argument::Input(path));
}

void MediaConfig::SetOverride() {
	ArgumentList.append(Argument::Override());
}

void MediaConfig::SetOutput(QString path) {
	ArgumentList.append(Argument::Output(path));
}

void MediaConfig::SetComma() {
	ArgumentList.append(Argument::AddComma());
}

void MediaConfig::SetColin() {
	ArgumentList.append(Argument::AddColin());
}

void MediaConfig::SetFilters() {
	ArgumentList.append(Argument::EnableFilters());
}

void MediaConfig::SetConcludeFilters() {
	ArgumentList.append(Argument::ConcludeFilters());
}

void MediaConfig::ResetArguments() {
	ArgumentList.clear();
}

QString MediaConfig::GetArguments() {
	return(ArgumentList);
}