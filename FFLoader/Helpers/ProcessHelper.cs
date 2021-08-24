using System.IO;

namespace FFLoader.Helpers
{
    internal partial class FFHelper
    {
        /// <summary>
        /// Checks to make sure FFMpeg's path is not null and exists in string "FFMpegPath"
        /// </summary>
        internal static void FFMpegPathNullOrMissing(string ffmpegPath)
        {
            if (string.IsNullOrEmpty(ffmpegPath))
            {
                throw new FFLoaderException("FFMpeg path is not defined in configuration");
            }

            else if (!File.Exists(ffmpegPath))
            {
                throw new FFLoaderException("ffmpeg.exe does not exist in the path: " + Path.GetDirectoryName(ffmpegPath) + ".");
            }
        }

        /// <summary>
        /// Checks to make sure AviSynth+ paths are not null or empty if used.
        /// </summary>
        /// <param name="avsdll">The path to AviSynth.dll.</param>
        /// <param name="avplusDirectory">The path to the AviSynth+ directory.</param>
        /// <returns></returns>
        internal static string AviSynthNullOrMissing(string avsdll, string avplusDirectory)
        {
            if (!File.Exists(avsdll) || !Directory.Exists(avplusDirectory))
            {
                return "AviSynth+ is missing or wasn't installed properly. Check to make sure an antivirus or other program didn't remove the AviSynth+ files.";
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// Checks to make sure that a process of the same type isn't already running.
        /// </summary>
        /// <param name="process">The name of the process.</param>
        internal static void ProcessAlreadyRunning(string process)
        {
            throw new FFLoaderException(process.ToString() + " is still running. Please wait until its process is complete before starting a new one.");
        }

        /// <summary>
        /// Throws exception if a process isn't running and the user is trying to do a function related to it.
        /// </summary>
        internal static void NoProcessRunning()
        {
            throw new FFLoaderException("No process is running that can be stopped.");
        }
    }
}
