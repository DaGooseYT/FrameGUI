#pragma once

#ifndef PROCESSERROR_H
#define PROCESSERROR_H

class ProcessError {
public:
	static void setPipeError(bool pipeError);
	static void setVkMemoryError(bool vkMemoryError);
	static void setVkQueueError(bool vkQueueError);
	static void setNcnnError(bool ncnnError);
	static bool getPipeError();
	static bool getVkMemoryError();
	static bool getVkQueueError();
	static bool getNcnnError();
	static void clearAll();
	static void setError(bool error);
	static bool error();

private:
	static bool _pipeError;
	static bool _vkMemoryError;
	static bool _vkQueueError;
	static bool _ncnnError;
	static bool _hasError;
};

#endif // !PROCESSERROR_H