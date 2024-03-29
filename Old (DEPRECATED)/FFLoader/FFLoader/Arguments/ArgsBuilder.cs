﻿using System.Globalization;
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
        /// <param name="sharpen">The sharpening value.</param>
        /// <param name="version">The verison of FrameGUI.</param>
        /// <param name="mute">Mutes the video audio.</param>
        /// <returns>The arguments in one string.</returns>
        internal static string ArgumentBuilder(string inputVideo, string outputVideo, string avisynthScript, string vCodec, string tune, string mode, double vBitrate, double crf, string preset, string aCodec,
            string aBitrate, double fps, double bFrame, double vheight, double vWidth, string resizeAlgo, string sampleRate, float sharpen, string version, bool mute)
        {
            if (_args != null)
            {
                _args.Clear();
                _args = null;
            }

            _args = new StringBuilder();

            _args.Append(string.Format("-y -noautorotate", CultureInfo.InvariantCulture));

            if (!string.IsNullOrEmpty(avisynthScript))
            {
                _args.Append(string.Format($@" -i ""{avisynthScript}""", CultureInfo.InvariantCulture));
            }

            _args.Append(string.Format($@" -i ""{inputVideo}""", CultureInfo.InvariantCulture));
            
            if (!string.IsNullOrEmpty(avisynthScript))
            {
                _args.Append(MapArgs.MapVideo());
            }
           
            _args.Append(CodecArgs.VideoCodecs(vCodec));
            _args.Append(PresetArgs.VideoPreset(preset));

            if (tune != "none")
            {
                _args.Append(TuneArgs.VideoTunes(tune));
            }

            if (vBitrate > 0 && mode.Contains("1 Pass"))
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

            bool fpsEnabled, resEnabeled;
            
            if (fps != 0)
            {
                _args.Append(FrameArgs.Fps(fps));
                fpsEnabled = true;
            }
            else
            {
                fpsEnabled = false;
            }

            if (vheight != 0 && vWidth != 0)
            {
                _args.Append(ResolutionArgs.VideoResolution(vheight, vWidth, fpsEnabled));
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
                _args.Append(SharpenArgs.SharpenResEnabled(sharpen, resEnabeled, fpsEnabled));
            }
            else if (fpsEnabled || resEnabeled)
            {
                _args.Append(string.Format(@"""", CultureInfo.InvariantCulture));
            }

            if (mute)
            {
                _args.Append(string.Format(" -an", CultureInfo.InvariantCulture));
            }
            else
            {
                _args.Append(CodecArgs.AudioCodecs(aCodec));
                _args.Append(BitrateArgs.AudioBitrate(aBitrate));
                _args.Append(SampleRateArgs.SampleRate(sampleRate));
            }
            
            _args.Append(EncoderAppArgs.EncoderApp(version));

            _args.Append(string.Format($@" ""{outputVideo}""", CultureInfo.InvariantCulture));

            return _args.ToString();
        }

        /// <summary>
        /// Arguments to be passed to the FFMpeg process for the one-click method.
        /// </summary>
        /// <param name="input">The input file path for the about-to-be encoded video.</param>
        /// <param name="output">The output file path of the encoded video.</param>
        /// <param name="avsScript">The path to the AviSynth+ script.</param>
        /// <param name="vCodec">The video codec to use in a string format.</param>
        /// <param name="version">The version of FrameGUI in a string format.</param>
        /// <returns>The arguments in a string representation.</returns>
        internal static string OneCArguments(string input, string output, string avsScript, string vCodec, string version)
        {
            if (_args != null)
            {
                _args.Clear();
                _args = null;
            }

            _args = new StringBuilder();

            _args.Append(string.Format("-y -noautorotate", CultureInfo.InvariantCulture));
            _args.Append(string.Format($@" -i ""{avsScript}""", CultureInfo.InvariantCulture));
            _args.Append(string.Format($@" -i ""{input}""", CultureInfo.InvariantCulture));
            _args.Append(MapArgs.MapVideo());

            _args.Append(CodecArgs.VideoCodecs(vCodec));

            _args.Append(string.Format(" -preset slow -bf 8 -crf 17 -b:a 320k", CultureInfo.InvariantCulture));

            _args.Append(EncoderAppArgs.EncoderApp(version + " One-Click"));
            _args.Append(string.Format($@" ""{output}""", CultureInfo.InvariantCulture));

            return _args.ToString();
        }
    }
}
