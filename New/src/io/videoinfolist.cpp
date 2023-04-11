#include "videoinfolist.hpp"

QList<QTime> VideoInfoList::_duration;
QStringList VideoInfoList::_frameRate;

/// <summary>
/// Sets the total duration.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfoList::setDuration(QTime duration) {
	_duration << duration;
}

/// <summary>
/// Sets the frame rate.
/// </summary>
/// <param name="frameRate">The frame rate.</param>
void VideoInfoList::setFrameRate(QString frameRate) {
	_frameRate << frameRate;
}

/// <summary>
/// Gets the duration from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The duration.</returns>
QTime VideoInfoList::getDuration(int index) {
	return(_duration.at(index));
}

/// <summary>
/// Gets the frame rate from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The frame rate.</returns>
QString VideoInfoList::getFrameRate(int index) {
	return(_frameRate.at(index));
}

/// <summary>
/// Removes a duration from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeDuration(int index) {
	_duration.removeAt(index);
}

/// <summary>
/// The frame rate to remove at an index in the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeFrameRate(int index) {
	_frameRate.removeAt(index);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void VideoInfoList::clearAll() {
	_duration.clear();
	_frameRate.clear();
}