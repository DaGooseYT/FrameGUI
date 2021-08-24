using System.Globalization;

namespace FFLoader.Arguments
{
    internal class SampleRateArgs
    {
        /// <summary>
        /// The selected output audio sample rate.
        /// </summary>
        /// <param name="rate">The sample rate in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string SampleRate(string rate)
        {
            return string.Format($" -ar {rate}", CultureInfo.InvariantCulture);
        }
    }
}
