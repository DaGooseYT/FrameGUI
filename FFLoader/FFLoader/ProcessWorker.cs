using System;
using System.Diagnostics;
using FFLoader.Helpers;

namespace FFLoader
{
    public class ProcessWorker : IDisposable
    {
        internal Process _process;

        /// <summary>
        /// True if the user requested to cancel the encode, otherwise false.
        /// </summary>
        internal static bool Cancelled { get; set; }

        /// <summary>
        /// The process at which to execute.
        /// </summary>
        internal enum ExeName
        {
            FFMpeg
            //More to come? (TODO)
        }

        /// <summary>
        /// Determines if a process is currently running.
        /// </summary>
        /// <param name="process"></param>
        /// <returns></returns>
        internal static bool IsProcessRunning(Process process)
        {
            bool processClosed;

            try
            {
                processClosed = process.HasExited;
            }
            catch
            {
                processClosed = true;
            }

            return !processClosed;
        }

        /// <summary>
        /// Starts a new process and defines StartInfo.
        /// </summary>
        /// <param name="exeName">The name of exe to launch.</param>
        /// <param name="exePath">The path to the exe to launch</param>
        /// <param name="cmdArgs">The arguments to pass to the exe</param>
        internal IDisposable NewProcess(ExeName exeName, string exePath, string cmdArgs)
        {
            _process = new Process();

            if (IsProcessRunning(_process))
            {
                FFHelper.ProcessAlreadyRunning(exeName.ToString());
            }

            _process.StartInfo.FileName = exePath;
            _process.StartInfo.Arguments = cmdArgs;
            _process.StartInfo.UseShellExecute = false;
            _process.StartInfo.CreateNoWindow = true;
            _process.StartInfo.RedirectStandardInput = true;
            _process.StartInfo.RedirectStandardError = true;

            return _process;
        }

        /// <summary>
        /// Stops the running FFMpeg process using a soft kill.
        /// </summary>
        public void StopFFMpegProcess()
        {
            if (IsProcessRunning(_process))
            {
                Cancelled = true;
                _process.StandardInput.Write('q');
                CloseProcess();
            }
            else
            {
                FFHelper.NoProcessRunning();
                Cancelled = false;
            }
        }

        /// <summary>
        /// Closes the running process.
        /// </summary>
        internal void CloseProcess()
        {
            if (_process != null)
            {
                _process.Close();
                Dispose();
            }
        }

        /// <summary>
        /// WIP
        /// </summary>
        /// <param name="pause"></param>
        public void PauseProcess(bool pause)
        {
            if (pause)
            {
                _process.StandardInput.Write(ConsoleSpecialKey.ControlBreak);
            }
            else
            {
                _process.StandardInput.Write(ConsoleKey.Enter);
            }
        }

        /// <summary>
        /// Frees all resources used by the process.
        /// </summary>
        public void Dispose()
        {
            _process?.Dispose();
        }
    }
}
