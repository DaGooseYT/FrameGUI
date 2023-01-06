using System;

namespace FFLoader
{
    public class VideoInfoHandler : EventArgs
    {
        /// <summary>
        /// The framerate of the video.
        /// </summary>
        public float FrameRate { get; private set; }

        /// <summary>
        /// The total amount of frames in the video.
        /// </summary>
        public double TotalFrames { get; private set; }

        /// <summary>
        /// The bitrate of the video.
        /// </summary>
        public double VideoBitrate { get; private set; }

        /// <summary>
        /// The total duration of the video.
        /// </summary>
        public TimeSpan Duration { get; private set; }

        /// <summary>
        /// The video codec used to encode the video.
        /// </summary>
        public string VideoCodec { get; private set; }

        /// <summary>
        /// The scan type of the video.
        /// </summary>
        public string ScanType { get; internal set; }

        /// <summary>
        /// The video resolution.
        /// </summary>
        public string VideoResolution { get; internal set; }

        /// <summary>
        /// The aspect ratio of the video.
        /// </summary>
        public string VideoAspectRatio { get; internal set; }

        /// <summary>
        /// The luminance of the video
        /// </summary>
        public string Luminance { get; internal set; }

        /// <summary>
        /// The color profile of the video.
        /// </summary>
        public string PixelFormat { get; internal set; }

        /// <summary>
        /// The audio codec used while encoding the video.
        /// </summary>
        public string AudioCodec { get; internal set; }

        /// <summary>
        /// The audio sample rate in Hz.
        /// </summary>
        public double AudioSampleRate { get; internal set; }

        /// <summary>
        /// The channel count of the audio.
        /// </summary>
        public float AudioDownMix { get; internal set; }

        /// <summary>
        /// The audio bitrate.
        /// </summary>
        public double AudioBitrate { get; internal set; }

        /// <summary>
        /// The language that the audio file is in.
        /// </summary>
        public string AudioLanguage { get; internal set; }

        /// <summary>
        /// Language of the subtitle if exists.
        /// </summary>
        public string SubtitleLanguage { get; internal set; }

        /// <summary>
        /// Grabs all video info from the FFMpeg console and creates event arguments.
        /// </summary>
        /// <param name="fps">The frames per second.</param>
        /// <param name="vBitrate">The video bitrate.</param>
        /// <param name="duration">The total duration of the video.</param>
        /// <param name="vCodec">The video codec.</param>
        /// <param name="scanType">The scan type of the video.</param>
        /// <param name="videoResolution">The resolution of the video in pixels.</param>
        /// <param name="videoRatio">The aspect ratio of the video.</param>
        /// <param name="luminance">The luminance of the video.</param>
        /// <param name="pixelFormat">The pixel format of the video.</param>
        /// <param name="aCodec">The audio codec in the video.</param>
        /// <param name="audioSR">The audio sample rate in the video.</param>
        /// <param name="audioDM">The audio downmix (channels) in the video.</param>
        /// <param name="aBitrate">The audio bitrate in the video.</param>
        /// <param name="audioLang">The language of the audio in the video.</param>
        /// <param name="subLang">The language of the subtitles in the video.</param>
        public VideoInfoHandler(float fps, double vBitrate, TimeSpan duration, string vCodec, string scanType, string videoResolution, 
            string videoRatio, string luminance, string pixelFormat, string aCodec, double audioSR, float audioDM, 
            double aBitrate, string audioLang, string subLang)
        {
            FrameRate = fps;
            TotalFrames = (int)fps * duration.TotalSeconds;
            VideoBitrate = vBitrate;
            Duration = duration;
            VideoCodec = vCodec;
            ScanType = scanType;
            VideoResolution = videoResolution;
            VideoAspectRatio = videoRatio;
            Luminance = luminance;
            PixelFormat = pixelFormat.ToUpper();
            AudioCodec = aCodec;
            AudioSampleRate = audioSR;
            AudioDownMix = audioDM;
            AudioBitrate = aBitrate;
            AudioLanguage = audioLang;
            SubtitleLanguage = subLang;
        }
    }
}
