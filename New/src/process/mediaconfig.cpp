#include "mediaconfig.hpp"

QStringList MediaConfig::_argumentList;

void MediaConfig::setVideoCodec(QString codec) {
	foreach(QString argument, splitSpace(Argument::videoCodec(codec)))
		_argumentList.append(argument);
}

void MediaConfig::setAudioCodec(QString codec) {
	foreach(QString argument, splitSpace(Argument::audioCodec(codec)))
		_argumentList.append(argument);
}

void MediaConfig::setSubtitleCodec(QString codec) {
	foreach(QString argument, splitSpace(Argument::subtitleCodec(codec)))
		_argumentList.append(argument);
}

void MediaConfig::setMapAll(QString type, QString s1) {
	foreach(QString argument, splitSpace(Argument::mapAll(type, s1)))
		_argumentList.append(argument);
}

void MediaConfig::setConstantRateFactor(int crf) {
	foreach(QString argument, splitSpace(Argument::constantRateFactor(crf)))
		_argumentList.append(argument);
}

void MediaConfig::setInput() {
	_argumentList.append(Argument::input());
}

void MediaConfig::setAppleTag() {
	foreach(QString argument, splitSpace(Argument::appleTag()))
		_argumentList.append(argument);
}

void MediaConfig::setVs() {
	foreach(QString argument, splitSpace(Argument::vs()))
		_argumentList.append(argument);
}

void MediaConfig::setVideoResolution(int width, int height) {
	foreach(QString argument, splitSpace(Argument::videoResolution(width, height)))
		_argumentList.append(argument);
}

void MediaConfig::append(QString string) {
	_argumentList.append(string);
}

void MediaConfig::setMetaData1() {
	_argumentList.append(Argument::metaData1());
}

void MediaConfig::setMetaData2(QString str) {
	_argumentList.append(Argument::metaData2(str));
}

void MediaConfig::setNoAutoRotate() {
	_argumentList.append(Argument::noAutoRotate());
}

#ifdef Q_OS_WINDOWS
void MediaConfig::setVsPipe1() {
	_argumentList.append(Argument::vsPipe1());
}

void MediaConfig::setVsPipe2() {
	_argumentList.append(Argument::vsPipe2());
}
#endif

void MediaConfig::setOverride() {
	_argumentList.append(Argument::override());
}

void MediaConfig::setOutput(QString path) {
	_argumentList.append(path);
}

void MediaConfig::resetArguments() {
	_argumentList.clear();
}

QStringList MediaConfig::splitSpace(QString args) {
	QStringList arg(args.split(QString(" ")));
	return(arg);
}

QStringList MediaConfig::getArguments() {
	return(_argumentList);
}