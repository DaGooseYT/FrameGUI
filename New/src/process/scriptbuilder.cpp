#include "scriptbuilder.hpp"

QString ScriptBuilder::_scriptList;

void ScriptBuilder::setRIFE(int multi, int id, int thread, QString tta, QString uhd, QString sc) {
	_scriptList.append(VapourSynth::rife(multi, id, thread, tta, uhd, sc));
}

void ScriptBuilder::setSRMD(int scale, int noise, int id, int thread, QString tta) {
	_scriptList.append(VapourSynth::srmd(scale, noise, id, thread, tta));
}

void ScriptBuilder::setRGB(QString matrix, QString transfer, QString primaries) {
	_scriptList.append(VapourSynth::rgb(matrix, transfer, primaries));
}

#ifdef Q_OS_WINDOWS
void ScriptBuilder::setSVPFlow(int num, int den, int mode) {
	_scriptList.append(VapourSynth::svpflow(num, den, mode));
}
#endif

void ScriptBuilder::setColorsInOut(QString format, QString matrix_in, QString transfer_in, QString primaries_in, QString matrix, QString transfer, QString primaries) {
	_scriptList.append(VapourSynth::colorsInOut(format, matrix_in, transfer_in, primaries_in, matrix, transfer, primaries));
}

void ScriptBuilder::setColorsOut(QString format, QString matrix, QString transfer, QString primaries) {
	_scriptList.append(VapourSynth::colorsOut(format, matrix, transfer, primaries));
}

void ScriptBuilder::setSCDetect(QString threshold) {
	_scriptList.append(VapourSynth::scDetect(threshold));
}

void ScriptBuilder::setPlugin(QString path) {
	_scriptList.append(VapourSynth::plugin(path));
}

void ScriptBuilder::setInput(QString path, QString id) {
	_scriptList.append(VapourSynth::input(path, id));
}

void ScriptBuilder::setInclude() {
	_scriptList.append(VapourSynth::include());
}

void ScriptBuilder::setConcludeClip() {
	_scriptList.append(VapourSynth::concludeClip());
}

void ScriptBuilder::setNewLine() {
	_scriptList.append(VapourSynth::newLine());
}

void ScriptBuilder::clearScript() {
	_scriptList.clear();
}

QString ScriptBuilder::getScript() {
	return(_scriptList);
}