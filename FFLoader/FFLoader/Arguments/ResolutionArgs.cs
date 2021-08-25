using System.Globalization;

namespace FFLoader.Arguments
{
    internal class ResolutionArgs
    {
        /// <summary>
        /// The selected output video resolution. 
        /// </summary>
        /// <param name="height">The height of the video in pixels in double format.</param>
        /// <param name="width">The width of the video in pixels in double format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoResolution(double height, double width, bool fps)
        {
            if (fps)
            {
                return string.Format($@" , scale={width}:{height}", CultureInfo.InvariantCulture);
            }
            else
            {
                return string.Format($@" -vf ""scale={width}:{height}", CultureInfo.InvariantCulture);
            }
        }

        /// <summary>
        /// The selected output video scale resize algorithm.
        /// </summary>
        /// <param name="algo">The algorithm to use in a string format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string VideoResizeAlgo(string algo)
        {
            return string.Format($":flags={algo.ToLower()}", CultureInfo.InvariantCulture);
        }
    }
}
