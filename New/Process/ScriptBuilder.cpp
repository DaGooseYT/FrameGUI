#include "ScriptBuilder.h"

QString ScriptBuilder::ScriptList;

void ScriptBuilder::SetRIFE(int multi, int id, int thread, QString tta, QString uhd, QString sc) {
	ScriptList.append(VapourSynth::RIFE(multi, id, thread, tta, uhd, sc));
}

void ScriptBuilder::SetSRMD(int scale, int noise, int id, int thread, QString tta) {
	ScriptList.append(VapourSynth::SRMD(scale, noise, id, thread, tta));
}

void ScriptBuilder::SetRGB(QString matrix, QString transfer, QString primaries) {
	ScriptList.append(VapourSynth::RGB(matrix, transfer, primaries));
}

void ScriptBuilder::SetColorsInOut(QString format, QString matrix_in, QString transfer_in, QString primaries_in, QString matrix, QString transfer, QString primaries) {
	ScriptList.append(VapourSynth::ColorsInOut(format, matrix_in, transfer_in, primaries_in, matrix, transfer, primaries));
}

void ScriptBuilder::SetColorsOut(QString format, QString matrix, QString transfer, QString primaries) {
	ScriptList.append(VapourSynth::ColorsOut(format, matrix, transfer, primaries));
}

void ScriptBuilder::SetSCDetect(QString threshold) {
	ScriptList.append(VapourSynth::SCDetect(threshold));
}

void ScriptBuilder::SetPlugin(QString path) {
	ScriptList.append(VapourSynth::Plugin(path));
}

void ScriptBuilder::SetInput(QString path, QString id) {
	ScriptList.append(VapourSynth::Input(path, id));
}

void ScriptBuilder::SetInclude() {
	ScriptList.append(VapourSynth::Include());
}

void ScriptBuilder::SetConcludeClip() {
	ScriptList.append(VapourSynth::ConcludeClip());
}

void ScriptBuilder::SetNewLine() {
	ScriptList.append(VapourSynth::NewLine());
}

void ScriptBuilder::ClearScript() {
	ScriptList.clear();
}

QString ScriptBuilder::GetScript() {
	return(ScriptList);
}