using System.Globalization;

namespace FFLoader.Arguments
{
    internal class CodecArgs
    {
        /// <summary>
        /// The selected output video codec.
        /// </summary>
        /// <param name="vCodec">The output video codec represented in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoCodecs(string vCodec)
        {
            return string.Format($" -c:v {vCodec}", CultureInfo.InvariantCulture);
        }

        /// <summary>
        /// The selected output audio codec.
        /// </summary>
        /// <param name="aCodec">The output audio codec represented in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string AudioCodecs(string aCodec)
        {
            if (aCodec == "aac")
            {
                return string.Format($" -c:a {aCodec}", CultureInfo.InvariantCulture); //Native FFMpeg AAC encoder (it sucks; will find better alternative soon).
            }
            else
            {
                return string.Format($" -c:a lib{aCodec}lame", CultureInfo.InvariantCulture);
            }
        }
    }
}
