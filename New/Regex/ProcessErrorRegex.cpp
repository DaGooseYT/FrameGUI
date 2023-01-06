#include "ProcessErrorRegex.h"

QList<bool> ProcessErrorRegex::IndexerBool;
QList<QRegularExpression> ProcessErrorRegex::IndexerRegex;

void ProcessErrorRegex::SetupPatterns() {
	IndexerRegex << QRegularExpression("pipe::\\sInvalid\\sdata\\sfound\\swhen\\sprocessing\\sinput");
	IndexerRegex << QRegularExpression("vkAllocateMemory\\sfailed");
	IndexerRegex << QRegularExpression("vkQueueSubmit\\sfailed");
	IndexerRegex << QRegularExpression("The\\sfile\\syou\\stried\\sto\\sload\\sor\\sone\\sof\\sits\\sdependencies\\sis\\sprobably\\smissing\\.");
}

void ProcessErrorRegex::ClearBools() {
	IndexerBool.clear();
}

void ProcessErrorRegex::ErrorRegex(QString output) {
	if (IndexerRegex.isEmpty())
		SetupPatterns();

	if (IndexerBool.isEmpty())
		for (int i = 0; i < IndexerRegex.count(); i++)
			IndexerBool << false;

	QRegularExpressionMatch matchPipeError = IndexerRegex.at(GetError::Pipe).match(output);
	QRegularExpressionMatch matchVkMemoryError = IndexerRegex.at(GetError::Memory).match(output);
	QRegularExpressionMatch matchVkQueueError = IndexerRegex.at(GetError::Queue).match(output);
	QRegularExpressionMatch matchNcnnError = IndexerRegex.at(GetError::Ncnn).match(output);

	if (matchPipeError.hasMatch())
		IndexerBool.replace(GetError::Pipe, true);
	if (matchVkMemoryError.hasMatch())
		IndexerBool.replace(GetError::Memory, true);
	if (matchVkQueueError.hasMatch())
		IndexerBool.replace(GetError::Queue, true);
	if (matchNcnnError.hasMatch())
		IndexerBool.replace(GetError::Ncnn, true);

	if (matchVkMemoryError.hasMatch() || matchVkQueueError.hasMatch() || matchNcnnError.hasMatch()) {

#ifdef PROCESSERROR_H
		ProcessError::SetVkMemoryError(IndexerBool.at(GetError::Memory));
		ProcessError::SetVkQueueError(IndexerBool.at(GetError::Queue));
		ProcessError::SetNcnnError(IndexerBool.at(GetError::Ncnn));

		ProcessError::SetError(true);
#endif // PROCESSERROR_H
	}
	else if (matchPipeError.hasMatch()) {
#ifdef PROCESSERROR_H
		ProcessError::SetPipeError(IndexerBool.at(GetError::Pipe));
#endif // PROCESSERROR_H
	}
}