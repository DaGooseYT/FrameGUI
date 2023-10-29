#include "framegui.hpp"

QString FrameGUI::checkEnviornment() {
	#ifdef Q_OS_WINDOWS
	// ssl
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libssl-1_1-x64.dll"))).exists()) return(QString("libssl-1_1-x64.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libcrypto-1_1-x64.dll"))).exists()) return(QString("libcrypto-1_1-x64.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\tls\\qopensslbackend.dll"))).exists()) return(QString("qopensslbackend.dll"));

	// ffmpeg
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\avcodec-59.dll"))).exists()) return(QString("avcodec-59.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\avdevice-59.dll"))).exists()) return(QString("avdevice-59.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\avfilter-8.dll"))).exists()) return(QString("avfilter-8.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\avformat-59.dll"))).exists()) return(QString("avformat-59.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\avutil-57.dll"))).exists()) return(QString("avutil-57.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\ffmpeg.exe"))).exists()) return(QString("ffmpeg.exe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\ffprobe.exe"))).exists()) return(QString("ffprobe.exe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\postproc-56.dll"))).exists()) return(QString("postproc-56.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\swresample-4.dll"))).exists()) return(QString("swresample-4.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\swscale-6.dll"))).exists()) return(QString("swscale-6.dll"));

	// vs
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\_ctypes.pyd"))).exists()) return(QString("_ctypes.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\libffi-7.dll"))).exists()) return(QString("libffi-7.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\portable.vs"))).exists()) return(QString("portable.vs"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\python39.dll"))).exists()) return(QString("python39.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\python39.zip"))).exists()) return(QString("python39.zip"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vapoursynth.cp39-win_amd64.pyd"))).exists()) return(QString("vapoursynth.cp39-win_amd64.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vapoursynth.dll"))).exists()) return(QString("vapoursynth.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vspipe.exe"))).exists()) return(QString("vspipe.exe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsscript.dll"))).exists()) return(QString("vsscript.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vapoursynth64\\coreplugins\\miscfilters.dll"))).exists()) return(QString("miscfilters.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\liblsmashsource.dll"))).exists()) return(QString("liblsmashsource.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\librife.dll"))).exists()) return(QString("librife.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libsrmdnv.dll"))).exists()) return(QString("libsrmdnv.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libsvpflow.1.dll"))).exists()) return(QString("libsvpflow.1.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libsvpflow.2.dll"))).exists()) return(QString("libsvpflow.2.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v4.6\\flownet.bin"))).exists()) return(QString("RIFE model v4.6"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v4.6\\flownet.param"))).exists()) return(QString("RIFE model v4.6"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmd_x2.bin"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmd_x2.param"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmd_x3.bin"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmd_x3.param"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmd_x4.bin"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmd_x4.param"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmdnf_x2.bin"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmdnf_x2.param"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmdnf_x3.bin"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmdnf_x3.param"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmdnf_x4.bin"))).exists()) return(QString("SRMD models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\models-srmd\\srmdnf_x4.param"))).exists()) return(QString("SRMD models"));

	return(QString());
	#endif
	#ifdef Q_OS_DARWIN
	// tls
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/../PlugIns/tls/libqsecuretransportbackend.dylib"))).exists()) return(QString("libqsecuretransportbackend.dylib"));

	// moltenvk
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/moltenvk/libMoltenVK.dylib"))).exists()) return(QString("libMoltenVK.dylib"));

	// lib
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffmpeg"))).exists()) return(QString("ffmpeg"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe"))).exists()) return(QString("ffprobe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavcodec.dylib"))).exists()) return(QString("libavcodec.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavdevice.dylib"))).exists()) return(QString("libavdevice.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavfilter.dylib"))).exists()) return(QString("libavfilter.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavformat.dylib"))).exists()) return(QString("libavformat.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavutil.dylib"))).exists()) return(QString("libavutil.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libpostproc.dylib"))).exists()) return(QString("libpostproc.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libswresample.dylib"))).exists()) return(QString("libswresample.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libswscale.dylib"))).exists()) return(QString("libswscale.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libvapoursynth.dylib"))).exists()) return(QString("libvapoursynth.dylib"));

	// py
	if (!QFile(QDir::toNativeSeparators(QString("/usr/local/lib/libmpdec.3.dylib"))).exists()) return(QString("libmpdec.3.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/Python"))).exists()) return(QString("Python"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/_CodeSignature/CodeResources"))).exists()) return(QString("CodeResources"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/_weakrefset.py"))).exists()) return(QString("_weakrefset.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/ast.py"))).exists()) return(QString("ast.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/contextlib.py"))).exists()) return(QString("contextlib.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/copyreg.py"))).exists()) return(QString("copyreg.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/decimal.py"))).exists()) return(QString("decimal.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/dis.py"))).exists()) return(QString("dis.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/enum.py"))).exists()) return(QString("enum.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/fractions.py"))).exists()) return(QString("fractions.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/functools.py"))).exists()) return(QString("functools.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/inspect.py"))).exists()) return(QString("inspect.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/keyword.py"))).exists()) return(QString("keyword.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/linecache.py"))).exists()) return(QString("linecache.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/numbers.py"))).exists()) return(QString("numbers.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/opcode.py"))).exists()) return(QString("opcode.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/operator.py"))).exists()) return(QString("operator.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/optparse.py"))).exists()) return(QString("optparse.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/os.py"))).exists()) return(QString("os.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/reprlib.py"))).exists()) return(QString("reprlib.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/string.py"))).exists()) return(QString("string.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/struct.py"))).exists()) return(QString("struct.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/textwrap.py"))).exists()) return(QString("textwrap.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/threading.py"))).exists()) return(QString("threading.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/token.py"))).exists()) return(QString("token.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/tokenize.py"))).exists()) return(QString("tokenize.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/traceback.py"))).exists()) return(QString("traceback.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/types.py"))).exists()) return(QString("types.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/warnings.py"))).exists()) return(QString("warnings.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/collections/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/collections/abc.py"))).exists()) return(QString("abc.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/ctypes/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/ctypes/_endian.py"))).exists()) return(QString("_endian.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/aliases.py"))).exists()) return(QString("aliases.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/ascii.py"))).exists()) return(QString("ascii.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/utf_8.py"))).exists()) return(QString("utf_8.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/importlib/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/_ctypes.cpython-311-darwin.so"))).exists()) return(QString("_ctypes.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/_decimal.cpython-311-darwin.so"))).exists()) return(QString("_decimal.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/_struct.cpython-311-darwin.so"))).exists()) return(QString("_struct.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/math.cpython-311-darwin.so"))).exists()) return(QString("math.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/logging/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/importlib/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_casefix.py"))).exists()) return(QString("_casefix.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_compiler.py"))).exists()) return(QString("_compiler.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_constants.py"))).exists()) return(QString("_constants.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_parser.py"))).exists()) return(QString("_parser.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/site-packages/vapoursynth.so"))).exists()) return(QString("vapoursynth.so"));

	return(QString());
	#endif
}