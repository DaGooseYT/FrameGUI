#include "framegui.hpp"

void FrameGUI::loadSysSetting() {
	QSettings* sys(new QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")));

	foreach(QVariant arg, sys->value(QString("arguments"), QVariantList()).toList())
		_arguments << arg.toString();

	foreach(QVariant id, sys->value(QString("jobid"), QVariantList()).toList())
		_job << id.toString();

	foreach(QVariant vs, sys->value(QString("vs"), QVariantList()).toList())
		_vapourScript << vs.toString();

	foreach(QVariant in, sys->value(QString("input"), QVariantList()).toList())
		_inputList << in.toString();

	foreach(QVariant out, sys->value(QString("output"), QVariantList()).toList())
		_outputList << out.toString();

	foreach(QVariant tmp, sys->value(QString("temp"), QVariantList()).toList())
		_tempList << tmp.toString();

	foreach(QVariant aArgs, sys->value(QString("audargs"), QVariantList()).toList())
		_audioArgs << aArgs.toString();

	foreach(QVariant sta, sys->value(QString("state"), QVariantList()).toList())
		_state << sta.toString();

	foreach(QVariant dur, sys->value(QString("dur"), QVariantList()).toList())
		VideoInfoList::setDuration(dur.toTime());

	foreach(QVariant fr, sys->value(QString("fr"), QVariantList()).toList())
		VideoInfoList::setFrameRate(fr.toString());

	sys->~QSettings();
}

void FrameGUI::saveSettings() {
	_sArguments.clear();
	_sJob.clear();
	_sState.clear();
	_sVapourScript.clear();
	_sInputList.clear();
	_sOutputList.clear();
	_sTempList.clear();
	_sDuration.clear();
	_sAudioArgs.clear();
	_sFrameRate.clear();

	foreach(QString arg, _arguments)
		_sArguments << arg;

	foreach(QString id, _job)
		_sJob << id;

	foreach(QString sta, _state)
		_sState << sta;

	foreach(QString vs, _vapourScript)
		_sVapourScript << vs;

	foreach(QString in, _inputList)
		_sInputList << in;

	foreach(QString out, _outputList)
		_sOutputList << out;

	foreach(QString temp, _tempList)
		_sTempList << temp;

	foreach(QString audarg, _audioArgs)
		_sAudioArgs << audarg;

	FOR_EACH(_arguments.count())
		_sDuration << VideoInfoList::getDuration(i);

	FOR_EACH(_arguments.count())
		_sFrameRate << VideoInfoList::getFrameRate(i);
}

void FrameGUI::setJobSetting() {
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("arguments"), _sArguments);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("jobid"), _sJob);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("vs"), _sVapourScript);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("input"), _sInputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("output"), _sOutputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("temp"), _sTempList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("audargs"), _sAudioArgs);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("state"), _sState);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("dur"), _sDuration);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("fr"), _sFrameRate);
}