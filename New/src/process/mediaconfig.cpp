#include "mediaconfig.hpp"

QString MediaConfig::_argumentList;

void MediaConfig::append(QString string) {
	_argumentList.append(string);
}

void MediaConfig::setVideoCodec(QString codec) {
	_argumentList.append(Argument::videoCodec(codec));
}

void MediaConfig::setAudioCodec(QString codec) {
	_argumentList.append(Argument::audioCodec(codec));
}

void MediaConfig::setMap(QString type, QString s1, int s2) {
	_argumentList.append(Argument::mapVideo(type, s1, s2));
}

void MediaConfig::setMapAll(QString type, QString s1) {
	_argumentList.append(Argument::mapAll(type, s1));
}

void MediaConfig::setConstantRateFactor(int crf) {
	_argumentList.append(Argument::constantRateFactor(crf));
}

void MediaConfig::setVideoResolution(int width, int height) {
	_argumentList.append(Argument::videoResolution(width, height));
}

void MediaConfig::setNoAutoRotate() {
	_argumentList.append(Argument::noAutoRotate());
}

void MediaConfig::setVSPipe(QString vspipe, QString vsscript) {
	_argumentList.append(Argument::vsPipe(vspipe, vsscript));
}

void MediaConfig::setFFMpeg(QString path) {
	_argumentList.append(Argument::ffmpeg(path));
}

void MediaConfig::setInput(QString path) {
	_argumentList.append(Argument::input(path));
}

void MediaConfig::setOverride() {
	_argumentList.append(Argument::override());
}

void MediaConfig::setOutput(QString path) {
	_argumentList.append(Argument::output(path));
}

void MediaConfig::setComma() {
	_argumentList.append(Argument::addComma());
}

void MediaConfig::setColin() {
	_argumentList.append(Argument::addColin());
}

void MediaConfig::setFilters() {
	_argumentList.append(Argument::enableFilters());
}

void MediaConfig::setConcludeFilters() {
	_argumentList.append(Argument::concludeFilters());
}

void MediaConfig::resetArguments() {
	_argumentList.clear();
}

QString MediaConfig::getArguments() {
	return(_argumentList);
}