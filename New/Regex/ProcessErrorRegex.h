#pragma once

#ifndef PROCESSERRORREGEX_H
#define PROCESSERRORREGEX_H

#include "..\IO\ProcessError.h"

#include <QtCore/QRegularExpression>
#include <QtCore/QList>

class ProcessErrorRegex {
public:
	static void ErrorRegex(QString);
	static void ClearBools();

private:
	enum GetError {
		Pipe = 0,
		Memory = 1,
		Queue = 2,
		Ncnn = 3
	};

	static QList<bool> IndexerBool;
	static QList<QRegularExpression> IndexerRegex;

	static void SetupPatterns();
};

#endif // !PROCESSERRORREGEX_H