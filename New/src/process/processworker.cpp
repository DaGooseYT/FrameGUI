#include "ffloader.hpp"
#include "Windows.h"

QProcess* video, *encode, *vs, *vk;

void ProcessWorker::newProcess(QProcess* process, QStringList arguments, QString program) {
	if (!arguments.isEmpty())
		process->start(program, arguments);
	else
		process->start(program);
}

void ProcessWorker::pauseProcess(QProcess* process, bool pause) {
	if (pause)
		DebugActiveProcess(process->processId());
	else
		DebugActiveProcessStop(process->processId());
}

void ProcessWorker::closeProcess(QProcess* process) {
	process->close();
}

void ProcessWorker::killProcess(QProcess* process) {
	process->kill();
}

void ProcessWorker::deconstruct(QProcess* process) {
	process->~QProcess();
}