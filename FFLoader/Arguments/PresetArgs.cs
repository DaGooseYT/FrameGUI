using System.Globalization;

namespace FFLoader.Arguments
{
    internal class PresetArgs
    {
        /// <summary>
        /// The selected output video/cpu preset arguments.
        /// </summary>
        /// <param name="preset">The output video/cpu preset in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoPreset(string preset)
        {
            return string.Format($" -preset {preset}", CultureInfo.InvariantCulture);
        }
    }
}
