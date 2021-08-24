using System;
using System.Globalization;
using System.Text.RegularExpressions;

namespace FFLoader
{
    internal class RegexTool
    {
        /// <summary>
        /// Total duration of the video file.
        /// </summary>
        private static TimeSpan TotalDuration { get; set; }

        //Conversion progress regex
        static readonly Regex _fps = new Regex(@"fps=\s?(?<FPS>\d*\.?\d?)");
        static readonly Regex _bitrate = new Regex(@"bitrate=\s?(?<Bitrate>\d*\.?\d?)kbits/s");
        static readonly Regex _processedDuration = new Regex(@"time=(?<ProcessedDuration>\d*:\d*:\d*)");

        //Video info regex
        static readonly Regex _VITotalDuration = new Regex(@"Duration:\s?(?<VITotalDuration>\d*:\d*:\d*)");
        static readonly Regex _VIBitrate = new Regex(@",\s?bitrate:\s?(?<VIBitrate>\d*)\s?kb/s");
        static readonly Regex _VI = new Regex(@"\s?Stream\s?#\d:\d:\s?Video:\s?(?<VideoCodec>\w*)\s?\(\w*\),\s?
            (?<PixelFormat>\w*)\((?<Luminance>\w*),\s?\w*,\s?(?<ScanType>\w*)\),\s?(?<Resolution>\w*)\s?
            \[SAR\s?\d?:\d?\s?DAR\s?(?<AspectRatio>\d*:\d*)\],\s?q=\d*-\d*,\s?\d*\s?kb/s,\s?(?<VFPS>\d*\.?\d?)\s?fps,");
        static readonly Regex _AI = new Regex(@"\s?Stream\s?#0:1\((?<AudioLang>\w*)\):\s?Audio:\s?(?<AudioCodec>\w*),\s?
                (?<AudioSR>\d*)\s?Hz,\s?(?<DownMix>\d*\.?\d?)\(\w*\),\s?\w*,\s?(?<AudioBitrate>\d*)\s?kb/s");

        //Subtitle info regex
        static readonly Regex _SI = new Regex(@"\s?Stream\s?#\d:\d\((?<SubLanguage>\w*)\):\s?Subtitle:");

        //Other regex
        static readonly Regex _avisynth = new Regex(@"(\[avisynth @ \w*\]\s)");

        /// <summary>
        /// Checks to make sure that there is a regex match for the conversion progress info.
        /// </summary>
        /// <param name="console">The output data from the process.</param>
        /// <param name="progress">Instance of ConversionProgress event handler.</param>
        /// <returns>If no match, False. If Match, True.</returns>
        internal static bool CheckProgressRegexMatch(string console, out ConversionProgress progress)
        {
            progress = null;

            var matchFPS = _fps.Match(console);
            var matchBitrate = _bitrate.Match(console);
            var matchProcessedDuration = _processedDuration.Match(console);

            if (!matchFPS.Success || !matchBitrate.Success || !matchProcessedDuration.Success)
            {
                return false;
            }
            else
            {
                float fps = ParseFloat(matchFPS, "FPS");
                float bitrate = ParseFloat(matchBitrate, "Bitrate");
                TimeSpan processedDuration = TimeSpan.Parse(matchProcessedDuration.Groups["ProcessedDuration"].Value, CultureInfo.InvariantCulture);

                progress = new ConversionProgress(fps, bitrate, processedDuration, TotalDuration);

                return true;
            }
        }

        /// <summary>
        /// Checks for matches for the video info of the input video file in the process console output data.
        /// </summary>
        /// <param name="console">The output data from the process.</param>
        /// <param name="info">Instance of VideoInfoHandler event handler.</param>
        internal static void CheckRegexVideoInfoMatch(string console, out VideoInfoHandler info)
        {
            info = null;

            var matchVIBitrate = _VIBitrate.Match(console);
            var matchVI = _VI.Match(console);
            var matchAI = _AI.Match(console);
            var matchSI = _SI.Match(console);

            if (!matchVIBitrate.Success || !matchVI.Success)
            {
                return;
            }
            else
            {
                //Video
                float fps = ParseFloat(matchVI, "VFPS");
                double vBitrate = ConvertDouble(matchVIBitrate, "VIBitrate");
                string vCodec = FormatString(matchVI, "VideoCodec");
                string scanType = FormatString(matchVI, "ScanType");
                string videoResolution = FormatString(matchVI, "Resolution");
                string videoRatio = FormatString(matchVI, "AspectRatio");
                string luminance = FormatString(matchVI, "Luminance");
                string pixelFormat = FormatString(matchVI, "PixelFormat");

                //Audio
                if (!matchAI.Success)
                {
                    return;
                }

                string aCodec = FormatString(matchAI, "AudioCodec");
                double audioSR = ConvertDouble(matchAI, "AudioSR");
                float audioDM = ParseFloat(matchAI, "DownMix");
                double aBitrate = ConvertDouble(matchAI, "AudioBitrate");
                string audioLang = FormatString(matchAI, "AudioLang");

                //Subtitles
                if (!matchSI.Success)
                {
                    return;
                }

                string subLang = FormatString(matchSI, "SubLanguage");

                info = new VideoInfoHandler(fps, vBitrate, TotalDuration, vCodec, scanType, videoResolution, videoRatio, luminance, pixelFormat,
                                aCodec, audioSR, audioDM, aBitrate, audioLang, subLang);
            }
        }

        /// <summary>
        /// Only attempts to match the Total Duration of the video for the purposes of finding TimeRemaining in progress info.
        /// </summary>
        /// <param name="console">The output data from the process.</param>
        internal static void CheckRegexDurationMatch(string console)
        {
            var matchTotalDuration = _VITotalDuration.Match(console);

            if (!matchTotalDuration.Success)
            {
                return;
            }
            else
            {
                TimeSpan.TryParse(matchTotalDuration.Groups["VITotalDuration"].Value, out TimeSpan totalVideoDuration);
                TotalDuration = totalVideoDuration;
            }
        }

        /// <summary>
        /// Checks for AviSynth error and matches it with the process console output.
        /// </summary>
        /// <param name="console">The output data from the process.</param>
        /// <returns>The AviSynth+ error message in a string format.</returns>
        internal static string CheckAviSynthErrorMatch(string console)
        {
            var match = _avisynth.Match(console);
            string lineToReplace = console.Replace(match.Groups[1].Value, string.Empty);

            return lineToReplace;
        }

        /// <summary>
        /// Parses a float from a regex match.
        /// </summary>
        /// <param name="matchType">The string to match with the FFMpeg console.</param>
        /// <param name="group">The group to match represented in a string.</param>
        /// <returns>The parsed float.</returns>
        private static float ParseFloat(Match matchType, string group)
        {
            float f = float.Parse(matchType.Groups[group].Value, CultureInfo.InvariantCulture);
            return f;
        }

        /// <summary>
        /// Parses a formatted string from a regex match. 
        /// </summary>
        /// <param name="matchType">The string to match with the FFMpeg console.</param>
        /// <param name="group">The group to match represented in a string.</param>
        /// <returns>The formatted string.</returns>
        private static string FormatString(Match matchType, string group)
        {
            string s = string.Format(matchType.Groups[group].Value, CultureInfo.InvariantCulture);
            return s;
        }

        /// <summary>
        /// Converts the string from the regex match into a double format.
        /// </summary>
        /// <param name="matchType">The string to match with the FFMpeg console.</param>
        /// <param name="group">The group to match represented in a string.</param>
        /// <returns></returns>
        private static double ConvertDouble(Match matchType, string group)
        {
            double d = Convert.ToDouble(matchType.Groups[group].Value, CultureInfo.InvariantCulture);
            return d;
        }
    }
}
