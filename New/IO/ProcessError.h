#pragma once

#ifndef PROCESSERROR_H
#define PROCESSERROR_H

class ProcessError {
public:
	static void SetPipeError(bool);
	static void SetVkMemoryError(bool);
	static void SetVkQueueError(bool);
	static void SetNcnnError(bool);

	static bool GetPipeError();
	static bool GetVkMemoryError();
	static bool GetVkQueueError();
	static bool GetNcnnError();

	static void ClearAll();
	static void SetError(bool);
	static bool Error();

private:
	static bool PipeError;
	static bool VkMemoryError;
	static bool VkQueueError;
	static bool NcnnError;
	static bool HasError;
};

#endif // !PROCESSERROR_H