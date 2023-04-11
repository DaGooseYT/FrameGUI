#include "processerror.hpp"

bool ProcessError::_pipeError;
bool ProcessError::_vkMemoryError;
bool ProcessError::_vkQueueError;
bool ProcessError::_ncnnError;
bool ProcessError::_hasError;

/// <summary>
/// Raises the FFMpeg pipe error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::setPipeError(bool pipeError) {
	_pipeError = pipeError;
}

/// <summary>
/// Raises the VkAllocateMemory error.
/// </summary>
/// <param name="vkMemoryError">True or false.</param>
void ProcessError::setVkMemoryError(bool vkMemoryError) {
	_vkMemoryError = vkMemoryError;
}

/// <summary>
/// Raises the VkQueueSubmit error.
/// </summary>
/// <param name="vkQueueError">True or false.</param>
void ProcessError::setVkQueueError(bool vkQueueError) {
	_vkQueueError = vkQueueError;
}

/// <summary>
/// Raises the NCNN error.
/// </summary>
/// <param name="ncnnError">True or false.</param>
void ProcessError::setNcnnError(bool ncnnError) {
	_ncnnError = ncnnError;
}

/// <summary>
/// Receives the error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::setError(bool error) {
	_hasError = error;
}

/// <summary>
/// Receives the FFMpeg pipe error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getPipeError() {
	return(_pipeError);
}

/// <summary>
/// Receives the VkAllocateMemory error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getVkMemoryError() {
	return(_vkMemoryError);
}

/// <summary>
/// Receives the VkQueueSubmit error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getVkQueueError() {
	return(_vkQueueError);
}

/// <summary>
/// Receives the NCNN error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getNcnnError() {
	return(_ncnnError);
}

/// <summary>
/// Raises the error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::error() {
	return(_hasError);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void ProcessError::clearAll() {
	_pipeError = false;
	_vkMemoryError = false;
	_vkQueueError = false;
	_ncnnError = false;
	_hasError = false;
}