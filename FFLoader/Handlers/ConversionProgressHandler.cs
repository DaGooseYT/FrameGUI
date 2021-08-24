using System;

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
        /// The progress percentage of the operation in a integer format. 
        /// </summary>
        public int ProgressPercentInt { get; private set; }

        /// <summary>
        /// The number of frames encoded.
        /// </summary>
        public double ProcessedFrames { get; private set; }

        /// <summary>
        /// The progress percentage of the operation in a string format.
        /// </summary>
        public string ProgressPercentStrng { get; private set; }

        /// <summary>
        /// Lists all aspects of the conversion progress for use in a windows form label.
        /// </summary>
        public string ConversionProgressLabel { get; private set; }

        /// <summary>
        /// The total amount of frames in the video stream.
        /// </summary>
        public double TotalFrames { get; private set; }

        /// <summary>
        /// The remaining number of frames to encode.
        /// </summary>
        public double RemainingFrames { get; private set; }

        /// <summary>
        /// The encoding conversion progress arguments.  
        /// </summary>
        /// <param name="fps">The FPS at which the conversion is processing.</param>
        /// <param name="bitrate">The Bitrate at which the conversion is processing.</param>
        /// <param name="processedDuration">The Processed Duration at which the conversion is processing.</param>
        /// <param name="totalDuration">The Total Duration from VideoInfo. Used for the purposes of finding the progress percentage and time remaining.</param>
        public ConversionProgress(float fps, float bitrate, TimeSpan processedDuration, TimeSpan totalDuration)
        {
            ConversionFPS = fps;
            ConversionBitrate = bitrate;
            ProcessedDuration = processedDuration;

            //Reports duration left instead (TODO: create a new and accurate implementation of TimeRemaining).
            TimeRemaining = totalDuration.Subtract(processedDuration);

            ProgressPercentInt = (int)(processedDuration.TotalSeconds / totalDuration.TotalSeconds * 100);
            ProgressPercentStrng = Math.Floor((decimal)ProgressPercentInt).ToString();
            ConversionProgressLabel = string.Format($"FPS: {fps} - Bitrate: {bitrate}kb/s - Duration left: {TimeRemaining} - {ProgressPercentStrng}%");
        }
    }
}

    
