#include "framegui.hpp"

void FrameGUI::loadSysSetting() {
	QSettings sys(QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")));

	_arguments = sys.value(QString("arguments"), QVariantList()).toList();
	_audioArgs = sys.value(QString("audargs"), QVariantList()).toList();

	#ifdef Q_OS_WINDOWS
	_vapourScript = sys.value(QString("vs"), QVariantList()).toList();
	#endif

	foreach(QVariant id, sys.value(QString("jobid"), QVariantList()).toList())
		*_job << id.toString();
	
	foreach(QVariant in, sys.value(QString("input"), QVariantList()).toList())
		*_inputList << in.toString();

	foreach(QVariant out, sys.value(QString("output"), QVariantList()).toList())
		*_outputList << out.toString();

	foreach(QVariant tmp, sys.value(QString("temp"), QVariantList()).toList())
		*_tempList << tmp.toString();

	foreach(QVariant sta, sys.value(QString("state"), QVariantList()).toList())
		*_state << sta.toString();

	foreach(QVariant dur, sys.value(QString("dur"), QVariantList()).toList())
		VideoInfoList::setDuration(dur.toTime());

	foreach(QVariant fr, sys.value(QString("fr"), QVariantList()).toList())
		VideoInfoList::setFrameRate(fr.toString());
}

void FrameGUI::saveSettings() {
	_sArguments.clear();
	_sJob.clear();
	_sState.clear();

	#ifdef Q_OS_WINDOWS
	_sVapourScript.clear();
	#endif

	_sInputList.clear();
	_sOutputList.clear();
	_sTempList.clear();
	_sDuration.clear();
	_sAudioArgs.clear();
	_sFrameRate.clear();

	_sArguments = _arguments;
	_sAudioArgs = _audioArgs;

	#ifdef Q_OS_WINDOWS
	_sVapourScript = _vapourScript;
	#endif

	foreach(QString id, *_job)
		_sJob.append(id);

	foreach(QString sta, *_state)
		_sState.append(sta);

	foreach(QString in, *_inputList)
		_sInputList.append(in);

	foreach(QString out, *_outputList)
		_sOutputList.append(out);

	foreach(QString temp, *_tempList)
		_sTempList.append(temp);

	FOR_EACH(_arguments.count())
		_sDuration.append(VideoInfoList::getDuration(i));

	FOR_EACH(_arguments.count())
		_sFrameRate.append(VideoInfoList::getFrameRate(i));
}

void FrameGUI::setJobSetting() {
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("arguments"), _sArguments);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("jobid"), _sJob);

	#ifdef Q_OS_WINDOWS
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("vs"), _sVapourScript);
	#endif

	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("input"), _sInputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("output"), _sOutputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("temp"), _sTempList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("audargs"), _sAudioArgs);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("state"), _sState);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("dur"), _sDuration);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("fr"), _sFrameRate);
}