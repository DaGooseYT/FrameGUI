#include "FrameGUI.h"

void FrameGUI::LoadSysSetting() {
	QSettings* sys = new QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI");

	foreach(QVariant arg, sys->value("arguments", QVariantList()).toList())
		arguments << arg.toString();

	foreach(QVariant id, sys->value("jobid", QVariantList()).toList())
		job << id.toString();

	foreach(QVariant vs, sys->value("vs", QVariantList()).toList())
		vapourScript << vs.toString();

	foreach(QVariant in, sys->value("input", QVariantList()).toList())
		inputList << in.toString();

	foreach(QVariant out, sys->value("output", QVariantList()).toList())
		outputList << out.toString();

	foreach(QVariant tmp, sys->value("temp", QVariantList()).toList())
		tempList << tmp.toString();

	foreach(QVariant aArgs, sys->value("audargs", QVariantList()).toList())
		AudioArgs << aArgs.toString();

	foreach(QVariant sta, sys->value("state", QVariantList()).toList())
		state << sta.toString();

	foreach(QVariant dur, sys->value("dur", QVariantList()).toList())
		VideoInfoList::SetDuration(dur.toTime());

	foreach(QVariant fr, sys->value("fr", QVariantList()).toList())
		VideoInfoList::SetFrameRate(fr.toString());

	sys->~QSettings();
}

void FrameGUI::SaveSettings() {
	Varguments.clear();
	Vjob.clear();
	Vstate.clear();
	VvapourScript.clear();
	VinputList.clear();
	VoutputList.clear();
	VtempList.clear();
	Vduration.clear();
	VaudioArgs.clear();
	VframeRate.clear();

	foreach(QString arg, arguments)
		Varguments << arg;

	foreach(QString id, job)
		Vjob << id;

	foreach(QString sta, state)
		Vstate << sta;

	foreach(QString vs, vapourScript)
		VvapourScript << vs;

	foreach(QString in, inputList)
		VinputList << in;

	foreach(QString out, outputList)
		VoutputList << out;

	foreach(QString temp, tempList)
		VtempList << temp;

	foreach(QString audarg, AudioArgs)
		VaudioArgs << audarg;

	FOR_EACH(arguments.count())
		Vduration << VideoInfoList::GetDuration(i);

	FOR_EACH(arguments.count())
		VframeRate << VideoInfoList::GetFrameRate(i);
}

void FrameGUI::SetJobSetting() {
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("arguments", Varguments);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("jobid", Vjob);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("vs", VvapourScript);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("input", VinputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("output", VoutputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("temp", VtempList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("audargs", VaudioArgs);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("state", Vstate);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("dur", Vduration);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("fr", VframeRate);
}