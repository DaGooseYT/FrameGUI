using System.Globalization;

namespace FFLoader.Arguments
{
    internal class FrameArgs
    {
        /// <summary>
        /// The selected output video FPS arguments.
        /// </summary>
        /// <param name="fps">The output video FPS in a double format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string Fps(double fps)
        {
            return string.Format($@" -vf ""fps={fps}", CultureInfo.InvariantCulture);
        }

        /// <summary>
        /// The selected output video consecutive b-frames arguments.
        /// </summary>
        /// <param name="bframe">The output video consecutive b-frames in a double format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string BFrame(double bframe)
        {
            return string.Format($" -bf {bframe}", CultureInfo.InvariantCulture);
        }
    }
}
