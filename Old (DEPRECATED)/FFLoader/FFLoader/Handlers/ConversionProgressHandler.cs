using System;
using System.Diagnostics;

namespace FFLoader
{
    public class ConversionProgress : EventArgs
    {
        /// <summary>
        /// The speed of the conversion progress in FPS.
        /// </summary>
        public float ConversionFPS { get; private set; }

        /// <summary>
        /// The speed of the conversion progress in bitrate.
        /// </summary>
        public float ConversionBitrate { get; private set; }

        /// <summary>
        /// The total processed duration of the video being encoded.
        /// </summary>
        public TimeSpan ProcessedDuration { get; private set; }

        /// <summary>
        /// The estimated time remaining of the process.
        /// </summary>
        public TimeSpan TimeRemaining { get; private set; }

        /// <summary>
        /// The elapsed time of the current running process.
        /// </summary>
        public TimeSpan TimeElapsed { get; private set; }

        /// <summary>
        /// The progress percentage of the operation in a integer format. 
        /// </summary>
        public int ProgressPercentInt { get; internal set; }

        /// <summary>
        /// The progress percentage of the operation in a string format.
        /// </summary>
        public string ProgressPercentStrng { get; internal set; }

        /// <summary>
        /// Lists all aspects of the conversion progress for use in a windows form label.
        /// </summary>
        public string ConversionProgressLabel { get; private set; }

        /// <summary>
        /// The encoding conversion progress arguments.  
        /// </summary>
        /// <param name="fps">The FPS at which the conversion is processing.</param>
        /// <param name="bitrate">The Bitrate at which the conversion is processing.</param>
        /// <param name="processedDuration">The Processed Duration at which the conversion is processing.</param>
        /// <param name="totalDuration">The Total Duration from VideoInfo. Used for the purposes of finding the progress percentage and time remaining.</param>
        public ConversionProgress(float fps, float bitrate, double frame, TimeSpan processedDuration, TimeSpan totalDuration, float VIfps, TimeSpan timer)
        {
            ConversionFPS = fps;
            ConversionBitrate = bitrate;
            ProcessedDuration = processedDuration;
            TimeElapsed = timer;

            double totalFrames = totalDuration.TotalSeconds * VIfps;
            double framesLeft = totalFrames - frame;
            double timeLeft = framesLeft * (timer.TotalSeconds / frame);

            TimeRemaining = TimeSpan.FromSeconds(Math.Floor(timeLeft));

            ProgressPercentInt = (int)Math.Round(processedDuration.TotalMilliseconds / totalDuration.TotalMilliseconds * 100, 2);
            ProgressPercentStrng = Math.Round(processedDuration.TotalMilliseconds / totalDuration.TotalMilliseconds * 100, 2).ToString();

            ConversionProgressLabel = $"FPS: {fps}, Bitrate: {bitrate}kb/s, Time left: {TimeRemaining}, Time elapsed: {timer} - " + string.Format("{0:000.00}%", ProgressPercentStrng);
        }

        /// <summary>
        /// Sets ConversionProgress to complete (fixes incomplete progress bug).
        /// </summary>
        /// <param name="percent">Percentage in a string format.</param>
        /// <param name="timer">Instance of the timer for the encoding.</param>
        public ConversionProgress(string percent, Stopwatch timer)
        {
            ProgressPercentInt = 100;

            double ts = timer.Elapsed.TotalSeconds;
            TimeSpan timeElapsed = TimeSpan.FromSeconds(Math.Round(ts));
            TimeElapsed = timeElapsed;

            ConversionProgressLabel = $"FPS: {ConversionFPS}, Bitrate: {ConversionBitrate}kb/s, Time left: {TimeRemaining}, Time elapsed: {TimeElapsed} - " + string.Format("{0:000.00}%", percent);
        }
    }
}

    
