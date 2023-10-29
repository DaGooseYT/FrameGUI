#pragma once

#ifndef PROCESSERRORREGEX_H
#define PROCESSERRORREGEX_H

#include <QtCore/QRegularExpression>
#include <QtCore/QList>

#include "processerror.hpp"

class ProcessErrorRegex {
public:
	static void errorRegex(QString output);
	static void clearBools();

private:
	enum GetError {
		Pipe = 0,
		Memory = 1,
		Queue = 2,
		Ncnn = 3
	};

	static QList<bool> _indexerBool;
	static QList<QRegularExpression> _indexerRegex;

	static void setupPatterns();
};

#endif // !PROCESSERRORREGEX_H