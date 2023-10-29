#include "vapoursynth.hpp"

/// <summary>
/// Enables SRMD super-resolution plugin.
/// </summary>
/// <param name="scale">The upscaling rate factor.</param>
/// <param name="noise">The amount of denoise to apply.</param>
/// <param name="id">The GPU id index to use.</param>
/// <param name="thread">The number of GPU threads to use.</param>
/// <param name="tta">Enables test time augmentation for better results.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::srmd(int scale, int noise, int id, int thread, QString tta) {
	#ifdef Q_OS_WINDOWS
	return(QString("clip = core.srmdnv.SRMD(clip, scale=%1, noise=%2, gpu_id=%3, gpu_thread=%4, tta=%5)\n\n").arg(scale).arg(noise).arg(id).arg(thread).arg(tta));
	#endif
	#ifdef Q_OS_DARWIN
	return(QString("clip = core.srmdnv.SRMD(clip, scale=%1, noise=%2, gpu_id=%3, gpu_thread=1, tta=%4)\n\n").arg(scale).arg(noise).arg(id).arg(tta));
	#endif
}