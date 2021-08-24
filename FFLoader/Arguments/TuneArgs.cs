using System.Globalization;

namespace FFLoader.Arguments
{
    internal class TuneArgs
    {
        /// <summary>
        /// The selected output video tune.
        /// </summary>
        /// <param name="tune">The tune in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoTunes(string tune)
        {
            return string.Format($" -tune {tune}", CultureInfo.InvariantCulture);
        }
    }
}
