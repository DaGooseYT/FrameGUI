using System.IO;

namespace FFLoader.Helpers
{
    internal partial class FFHelper
    {
        /// <summary>
        /// Checks to make sure the selected input video path is not null and exists in string "InputFile"
        /// </summary>
        internal static void InputFileNullOrMissing(string inputPath)
        {
            if (string.IsNullOrEmpty(inputPath))
            {
                throw new FFLoaderException("Video input path is not defined in configuration");
            }
            else if (!File.Exists(inputPath))
            {
                throw new FFLoaderException("The selected input video in path: " + inputPath + " is missing or does not exist.");
            }
        }

        /// <summary>
        /// Checks to make sure that the .avs AviSynth+ script file exists.
        /// </summary>
        /// <param name="scriptPath">The path to the .avs AviSynth+ script file.</param>
        internal static void AvsScriptFileNullOrMissing(string scriptPath)
        {
            if (!File.Exists(scriptPath))
            {
                throw new FFLoaderException("The selected input AviSynth script in path: " + scriptPath + " is missing or does not exist");
            }
        }

        /// <summary>
        /// Confirms that the file was created in the specified output path.
        /// </summary>
        internal static void OutputPathNullOrMissing(string outputPath)
        {
            if (string.IsNullOrEmpty(outputPath))
            {
                throw new FFLoaderException("Output video path is not defined in configuration");
            }
        }

        /// <summary>
        /// Determines if the output file has been made or not.
        /// </summary>
        /// <param name="outputPath">The output video path.</param>
        /// <returns>True or False.</returns>
        internal static bool OutputFileNotCreated(string outputPath)
        {
            if (!File.Exists(outputPath))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
