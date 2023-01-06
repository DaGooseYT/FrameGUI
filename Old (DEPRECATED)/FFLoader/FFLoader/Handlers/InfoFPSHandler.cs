using System;

namespace FFLoader
{
    public class InfoFPSHandler : EventArgs
    {
        /// <summary>
        /// The input video fps from FFMpeg.
        /// </summary>
        public float InputFPS { get; private set; }

        /// <summary>
        /// Event handler for returning the input video fps from FFMpeg.
        /// </summary>
        /// <param name="fps">The input video fps from FFMpeg.</param>
        public InfoFPSHandler(float fps)
        {
            InputFPS = fps;
        }
    }
}
