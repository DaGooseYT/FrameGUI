#pragma once

#ifndef FFLOADER_H
#define FFLOADER_H

#include <QtCore/QProcess>
#include <QtCore/QtGlobal>
#include <QtCore/QTime>
#include <QtCore/QDir>

#include "audiosubinforegex.hpp"
#include "processerrorregex.hpp"
#include "progressinforegex.hpp"
#include "videoinforegex.hpp"
#include "videoinfolist.hpp"

#ifdef Q_OS_WINDOWS
#include "windows.h"
#endif

#ifdef Q_OS_DARWIN
#include "signal.h"
#endif

enum class ProcessType {
	Encode,
	VideoInfo,
	VideoFinish,
	EncodeFinish,
	VS
};

class ProcessWorker : public QObject {
public:
	void newProcess(QProcess *process, QStringList arguments, QString program);
	void pauseProcess(QProcess *process, bool pause);
	void closeProcess(QProcess *process);
	void killProcess(QProcess *process);
	void deconstruct(QProcess *process);

	QProcess *_video, *_encode, *_vs, *_vk;
	int _currentJob;
};

class FFLoader : public ProcessWorker {
	Q_OBJECT;

public:
	void encode(QStringList args, QStringList vsArgs, QString ffmpeg, QString vsPipe);
	void videoInfo(QStringList args, QString ffprobe);
	void connector(QProcess *process, ProcessType type);
	void disconnecter(QProcess *process, ProcessType type);
	void finisher(QProcess *process, ProcessType type);
	void outputData(QProcess *process, ProcessType type);
	void outputDataVideo();
	void outputDataInfo();
	void outputDataVS();
	void videoFinished();
	void encodeFinished();

	QElapsedTimer *_timer;
	QTime *_pauseTime;

signals:
	void setVideoInfo();
	void setProgress();
	void completed();
	void logs(QString);
};

#endif // !FFLOADER_H