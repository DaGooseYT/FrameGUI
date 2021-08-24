using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace FFLoader
{
    internal class FFLogBuilder
    {
        private StreamWriter _sw;

        internal void FFMpegLogBuilder(FFLoaderBase ff)
        {
            if (!ProcessWorker.IsProcessRunning(ff._process))
            {
                if (File.Exists(ff.FFMpegLogPath))
                {
                    File.Delete(ff.FFMpegLogPath);
                }

                _sw = File.CreateText(ff.FFMpegLogPath);

                foreach (string line in ff._output)
                {
                    _sw.WriteLine(line);
                }

                if (!string.IsNullOrEmpty(ff._output.Last()))
                {
                    if (!ff._output.Last().StartsWith(" ") && !ff._output.Last().StartsWith("[") && !ff._output.Last().Contains(ff.AvisynthScriptPath) && ff.IsRealProcess)
                    {
                        string lastLine = ff._output.Last();
                        ff.CatchFFMpegError(lastLine, out FFMpegErrorHandler handler);
                        ff.UpdateFFMpegError(handler);
                    }
                }

                
                _sw = null;
            }
        }
    }
}
