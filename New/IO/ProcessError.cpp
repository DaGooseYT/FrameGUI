#include "ProcessError.h"

bool ProcessError::PipeError;
bool ProcessError::VkMemoryError;
bool ProcessError::VkQueueError;
bool ProcessError::NcnnError;
bool ProcessError::HasError;

/// <summary>
/// Raises the FFMpeg pipe error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::SetPipeError(bool pipeError) {
	PipeError = pipeError;
}

/// <summary>
/// Raises the VkAllocateMemory error.
/// </summary>
/// <param name="vkMemoryError">True or false.</param>
void ProcessError::SetVkMemoryError(bool vkMemoryError) {
	VkMemoryError = vkMemoryError;
}

/// <summary>
/// Raises the VkQueueSubmit error.
/// </summary>
/// <param name="vkQueueError">True or false.</param>
void ProcessError::SetVkQueueError(bool vkQueueError) {
	VkQueueError = vkQueueError;
}

/// <summary>
/// Raises the NCNN error.
/// </summary>
/// <param name="ncnnError">True or false.</param>
void ProcessError::SetNcnnError(bool ncnnError) {
	NcnnError = ncnnError;
}

/// <summary>
/// Receives the FFMpeg pipe error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetPipeError() {
	return(PipeError);
}

/// <summary>
/// Receives the VkAllocateMemory error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetVkMemoryError() {
	return(VkMemoryError);
}

/// <summary>
/// Receives the VkQueueSubmit error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetVkQueueError() {
	return(VkQueueError);
}

/// <summary>
/// Receives the NCNN error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetNcnnError() {
	return(NcnnError);
}

/// <summary>
/// Receives the error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::SetError(bool error) {
	HasError = error;
}

/// <summary>
/// Raises the error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::Error() {
	return(HasError);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void ProcessError::ClearAll() {
	PipeError = false;
	VkMemoryError = false;
	VkQueueError = false;
	NcnnError = false;
	HasError = false;
}