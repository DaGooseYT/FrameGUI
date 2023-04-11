#include "vapoursynth.hpp"

/// <summary>
/// Configures SVPFlow for if you don't know how to write the parameters.
/// </summary>
/// <param name="num">The frame rate numerator.</param>
/// <param name="den">The frame rate denominator.</param>
/// /// <param name="mode">The frame interpolation mode to use.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::svpflow(int num, int den, int mode) {
	QString super = QString("{scale:{up:2},gpu:0}");
	QString analyse = QString("{gpu:0,main:{search:{coarse:{distance:0},type:4}},refine:[{thsad:250}]}");
	QString smooth = QString("{rate:{num:%1,den:%2,abs:true},algo:13,mask:{area:0},scene:{mode:%3,blend:false}}").arg(num).arg(den).arg(mode);

	QString complete = QString("super_params=\"%1\"\n").arg(super) +
		QString("analyse_params=\"%1\"\n").arg(analyse) +
		QString("smoothfps_params=\"%1\"\n\n").arg(smooth) +
		QString("super = core.svp1.Super(clip, super_params)\n") +
		QString("vectors = core.svp1.Analyse(super[\"clip\"], super[\"data\"], clip, analyse_params)\n") +
		QString("clip = core.svp2.SmoothFps(clip, super[\"clip\"], super[\"data\"], vectors[\"clip\"], vectors[\"data\"], smoothfps_params)\n") +
		QString("clip = core.std.AssumeFPS(clip, fpsnum=%1, fpsden=%2)\n\n").arg(num).arg(den);

	return(complete);
}