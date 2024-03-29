#include "ffloader.hpp"

void ProcessWorker::newProcess(QProcess* process, QStringList arguments, QString program) {
	if (!arguments.isEmpty())
		process->start(program, arguments);
	else
		process->start(program);
}

void ProcessWorker::pauseProcess(QProcess* process, bool pause) {
	if (pause) {
	#ifdef Q_OS_WINDOWS
		DebugActiveProcess(process->processId());
	#endif
	#ifdef Q_OS_DARWIN
		kill(process->processId(), SIGSTOP);
	#endif
	}
	else {
	#ifdef Q_OS_WINDOWS
		DebugActiveProcessStop(process->processId());
	#endif
	#ifdef Q_OS_DARWIN
		kill(process->processId(), SIGCONT);
	#endif
	}
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