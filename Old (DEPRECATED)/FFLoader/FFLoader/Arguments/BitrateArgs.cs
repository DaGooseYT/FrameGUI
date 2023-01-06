using System.Globalization;

namespace FFLoader.Arguments
{
    internal class BitrateArgs
    {
        /// <summary>
        /// The selected output video bitrate arguments.
        /// </summary>
        /// <param name="bitrate">The bitrate of the output video in a double format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoBitrate(double bitrate)
        {
            return string.Format($" -b:v {bitrate}k", CultureInfo.InvariantCulture);
        }

        /// <summary>
        /// Copies the output video bitrate from the input video bitrate if vBitrate == 0. 
        /// </summary>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoBitrateCopy()
        {
            return string.Format(" -b:v copy", CultureInfo.InvariantCulture);
        }

        /// <summary>
        /// The selected output audio bitrate arguments.
        /// </summary>
        /// <param name="bitrate">The bitrate of the output audio in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string AudioBitrate(string bitrate)
        {
            return string.Format($" -b:a {bitrate}k", CultureInfo.InvariantCulture);
        }

        /// <summary>
        /// The constant rate factor value of the output video.
        /// </summary>
        /// <param name="crf">The constant rate factor value.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string RateFactor(double crf)
        {
            return string.Format($" -crf {crf}", CultureInfo.InvariantCulture);
        }
    }
}
