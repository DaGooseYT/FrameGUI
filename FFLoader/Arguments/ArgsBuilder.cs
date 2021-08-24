using System.Globalization;
using System.Text;

namespace FFLoader.Arguments
{
    internal class ArgsBuilder
    {
        internal static StringBuilder _args;
        
        /// <summary>
        /// Builds arguments that will be later passed to ffmpeg.
        /// </summary>
        /// <param name="vCodec">The selected output video codec.</param>
        /// <param name="tune">The selected output video tune.</param>
        /// <param name="mode">The selected output video encoding mode.</param>
        /// <param name="vBitrate">Video bitrate.</param>
        /// <param name="preset">CPU preset.</param>
        /// <param name="aCodec">Audio codec/format.</param>
        /// <param name="aBitrate">Audio bitrate</param>
        /// <param name="fps">The frames per second.</param>
        /// <param name="bFrame">The number of b frames.</param>
        /// <param name="vheight">The adjusted height of the video.</param>
        /// <param name="vWidth">The adjusted width of the video.</param>
        /// <param name="resizeAlgo">The resize algorithm to use if resizing.</param>
        /// <param name="sampleRate">The audio sample rate.</param>
        /// <returns>The arguments in one string.</returns>
        internal static string ArgumentBuilder(string inputVideo, string outputVideo, string avisynthScript, string vCodec, string tune, string mode, double vBitrate, double crf, string preset, string aCodec,
            string aBitrate, double fps, double bFrame, double vheight, double vWidth, string resizeAlgo, string sampleRate, float sharpen)
        {
            if (_args != null)
            {
                _args.Clear();
                _args = null;
            }

            _args = new StringBuilder();

            _args.Append(string.Format("-y", CultureInfo.InvariantCulture));

            if (!string.IsNullOrEmpty(avisynthScript))
            {
                _args.Append(string.Format($@" -i ""{avisynthScript}""", CultureInfo.InvariantCulture));
            }

            _args.Append(string.Format($@" -i ""{inputVideo}""", CultureInfo.InvariantCulture));
            
            if (!string.IsNullOrEmpty(avisynthScript))
            {
                _args.Append(MapArgs.MapVideo());
            }

            if (!string.IsNullOrEmpty(vCodec))
            {
                _args.Append(CodecArgs.VideoCodecs(vCodec));
            }

            if (string.IsNullOrEmpty(preset))
            {
                _args.Append(PresetArgs.VideoPreset(preset));
            }

            if (tune != "none")
            {
                _args.Append(TuneArgs.VideoTunes(tune));
            }

            if (vBitrate > 0 && mode.Contains("OnePass"))
            {
                _args.Append(BitrateArgs.VideoBitrate(vBitrate));
            }
            else if (vBitrate == 0 && mode.Contains("1 Pass"))
            {
                _args.Append(BitrateArgs.VideoBitrateCopy());
            }
            else if (vBitrate == 0 && mode.Contains("Factor"))
            {
                _args.Append(BitrateArgs.RateFactor(crf));
            }
            
            _args.Append(FrameArgs.BFrame(bFrame));
            
            if (fps != 0)
            {
                _args.Append(FrameArgs.Fps(fps));
            }

            bool resEnabeled;

            if (vheight != 0 && vWidth != 0)
            {
                _args.Append(ResolutionArgs.VideoResolution(vheight, vWidth));
                resEnabeled = true;
            }
            else
            {
                resEnabeled = false;
            }

            if (vheight != 0 && vWidth != 0 && resizeAlgo != "none")
            {
                _args.Append(ResolutionArgs.VideoResizeAlgo(resizeAlgo));
            }

            if (sharpen != 0.0)
            {
                _args.Append(SharpenArgs.SharpenResEnabled(sharpen, resEnabeled));
            }
            else
            {
                _args.Append(string.Format(@"""", CultureInfo.InvariantCulture));
            }
            
            _args.Append(CodecArgs.AudioCodecs(aCodec));

            if (aBitrate != "copy")
            {
                _args.Append(BitrateArgs.AudioBitrate(aBitrate));
            }
            else
            {
                _args.Append(BitrateArgs.AudioBitrateCopy());
            }

            _args.Append(SampleRateArgs.SampleRate(sampleRate));

            _args.Append(string.Format($@" ""{outputVideo}"""));

            return _args.ToString();
        }
    }
}
