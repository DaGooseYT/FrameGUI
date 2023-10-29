#include "vapoursynth.hpp"

/// <summary>
/// Sets the VapourSynth plugins to use.
/// </summary>
QString VapourSynth::plugin(QString path) {
	#ifdef Q_OS_WINDOWS
	return(QString("core.std.LoadPlugin(\"%1\")\n").arg(path.replace(QString("\\"), QString("\\\\"))));
	#endif
	#ifdef Q_OS_DARWIN
	return(QString("core.std.LoadPlugin(\"%1\")\n").arg(path));
	#endif
}

/// <summary>
/// Includes required python nodes.
/// </summary>
QString VapourSynth::include() {
	#ifdef Q_OS_WINDOWS
	return(QString("# This file was generated using FrameGUI\n\nimport tempfile\nimport vapoursynth as vs\nfrom vapoursynth import core\n\n"));
	#endif
	#ifdef Q_OS_DARWIN
	return(QString("# This file was generated using FrameGUI\n\nimport os\nimport vapoursynth as vs\nfrom vapoursynth import core\n\n"));
	#endif
}

/// <summary>
/// Configures the source video for vapoursynth.
/// </summary>
/// <param name="path">The source video file path.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::input(QString path, QString id) {
	#ifdef Q_OS_WINDOWS
	return(QString("\nclip = core.lsmas.LWLibavSource(source=\"%1\", cachefile=tempfile.gettempdir() + \"\\%2.lwi\")\n\n").arg(path).replace(QString("\\"), QString("\\\\")).arg(id));
	#endif
	#ifdef Q_OS_DARWIN

	return(QString("\nclip = core.ffms2.Source(source=\"%1\", cachefile=os.getenv(\"HOME\") + \"/Library/Caches/TemporaryItems/%2.ffindex\")\n\n").arg(path).arg(id));
	#endif
}

/// <summary>
/// Enabled scene change detection for frame interpolation.
/// </summary>
/// <param name="threshold">The sensitivity level for the scene change detection.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::scDetect(QString threshold) {
	return(QString("clip = core.misc.SCDetect(clip, threshold=%1)\n").arg(threshold));
}

/// <summary>
/// Concludes the clip for output pipe.
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::concludeClip() {
	return(QString("clip.set_output()"));
}

/// <summary>
/// Adds a new line to the script.
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::newLine() {
	return(QString("\n"));
}