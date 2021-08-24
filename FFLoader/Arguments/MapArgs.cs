using System.Globalization;

namespace FFLoader.Arguments
{
    internal class MapArgs
    {
        /// <summary>
        /// Maps the input video and input audio to make a single media file.
        /// </summary>
        /// <returns>String representation of the argument.</returns>
        internal static string MapVideo()
        {
            return string.Format(" -map 0:v -map 1:a", CultureInfo.InvariantCulture);
        }
    }
}
