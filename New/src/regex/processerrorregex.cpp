#include "processerrorregex.hpp"

QList<bool> ProcessErrorRegex::_indexerBool;
QList<QRegularExpression> ProcessErrorRegex::_indexerRegex;

void ProcessErrorRegex::setupPatterns() {
	_indexerRegex << QRegularExpression(QString("pipe::\\sInvalid\\sdata\\sfound\\swhen\\sprocessing\\sinput"));
	_indexerRegex << QRegularExpression(QString("vkAllocateMemory\\sfailed"));
	_indexerRegex << QRegularExpression(QString("vkQueueSubmit\\sfailed"));
	_indexerRegex << QRegularExpression(QString("The\\sfile\\syou\\stried\\sto\\sload\\sor\\sone\\sof\\sits\\sdependencies\\sis\\sprobably\\smissing\\."));
}

void ProcessErrorRegex::clearBools() {
	_indexerBool.clear();
}

void ProcessErrorRegex::errorRegex(QString output) {
	if (_indexerRegex.isEmpty())
		setupPatterns();

	if (_indexerBool.isEmpty())
		for (int i = 0; i < _indexerRegex.count(); i++)
			_indexerBool << false;

	QRegularExpressionMatch matchPipeError(_indexerRegex.at(GetError::Pipe).match(output));
	QRegularExpressionMatch matchVkMemoryError(_indexerRegex.at(GetError::Memory).match(output));
	QRegularExpressionMatch matchVkQueueError(_indexerRegex.at(GetError::Queue).match(output));
	QRegularExpressionMatch matchNcnnError(_indexerRegex.at(GetError::Ncnn).match(output));

	if (matchPipeError.hasMatch())
		_indexerBool.replace(GetError::Pipe, true);
	if (matchVkMemoryError.hasMatch())
		_indexerBool.replace(GetError::Memory, true);
	if (matchVkQueueError.hasMatch())
		_indexerBool.replace(GetError::Queue, true);
	if (matchNcnnError.hasMatch())
		_indexerBool.replace(GetError::Ncnn, true);

	if (matchVkMemoryError.hasMatch() || matchVkQueueError.hasMatch() || matchNcnnError.hasMatch()) {

#ifdef PROCESSERROR_H
		ProcessError::setVkMemoryError(_indexerBool.at(GetError::Memory));
		ProcessError::setVkQueueError(_indexerBool.at(GetError::Queue));
		ProcessError::setNcnnError(_indexerBool.at(GetError::Ncnn));

		ProcessError::setError(true);
#endif // PROCESSERROR_H
	}
	else if (matchPipeError.hasMatch()) {
#ifdef PROCESSERROR_H
		ProcessError::setPipeError(_indexerBool.at(GetError::Pipe));
#endif // PROCESSERROR_H
	}
}