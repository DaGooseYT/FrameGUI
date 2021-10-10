/****************************************************************************
 * Copyright (C) 2021 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using FFLoader.Arguments;
using FFLoader.Helpers;

namespace FFLoader
{
    public partial class FFLoaderBase : ProcessWorker
    {
        internal StreamWriter _fflog;

        internal StringBuilder _sb;

        /// <summary>
        /// The path to FFMpeg.exe.
        /// </summary>
        public string FFMpegPath { get; set; }

        /// <summary>
        /// The input video file path.
        /// </summary>
        public string InputVideoPath { get; set; }

        /// <summary>
        /// Path to AviSynth script path.
        /// </summary>
        public string AvisynthScriptPath { get; set; }

        /// <summary>
        /// The path to AviSynth.dll
        /// </summary>
        public string AvisynthDllPath { get; internal set; } = @"C:\Windows\System32\AviSynth.dll";

        /// <summary>
        /// Path to AviSynth+ contents.
        /// </summary>
        public string AvisynthPlusPath { get; internal set; } = @"C:\Program Files (x86)\AviSynth+\";

        /// <summary>
        /// The output video file path.
        /// </summary>
        public string OutputVideoPath { get; set; }

        /// <summary>
        /// The full command for the FFMpeg process.
        /// </summary>
        public string FFMpegCommand { get; internal set; }

        /// <summary>
        /// Path to the FFMpeg console log file.
        /// </summary>
        public string FFMpegLogPath { get; private set; } = Path.GetTempPath() + @"FrameGUI\ffmpeglogs.txt";

        /// <summary>
        /// Supported file extensions by the encoder.
        /// </summary>
        private readonly string[] supportedExtensions =
            { ".mp4", ".mkv", ".avi", ".mov", ".thp", ".bik", 
            ".m2ts", ".ts", ".flv", ".webm", ".ogv" };

        /// <summary>
        /// Strings to find in the output FFMpeg console.
        /// </summary>
        private readonly string[] find = { "[avisynth", "Input #0" };

        /// <summary>
        /// Determines if the selected input video type is supported.
        /// </summary>
        /// <returns>True of False.</returns>
        private bool SupportedFiles()
        {
            return supportedExtensions.Contains(Path.GetExtension(InputVideoPath).ToLower());
        }

        /// <summary>
        /// Converts a video file with specified arguments. 
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
        /// <param name="vHeight">The adjusted height of the video.</param>
        /// <param name="vWidth">The adjusted width of the video.</param>
        /// <param name="algo">The resize algorithm to use if resizing.</param>
        /// <param name="sRate">The audio sample rate.</param>
        /// <param name="crf">The Constant Rate Factor value.</param>
        /// <param name="sharpen">The sharpening value to be applied to the video.</param>
        /// <param name="version">The version of FrameGUI being used.</param>
        /// <param name="mute">Mutes the audio from the video.</param>
        public void ConvertFFMpeg(string vCodec, string mode, string preset, string tune, string algo, string aCodec, 
            string aBitrate, string sRate, double vHeight, double vWidth, double vBitrate, double fps, double bFrame, 
            double crf, float sharpen, string version, bool mute)
        {
            Cancelled = false;

            if (SupportedFiles())
            {
                _process = null;
                AvsError = false;

                if (_sb != null)
                {
                    _sb.Clear();
                    _sb = null;
                }

                _fflog = File.CreateText(FFMpegLogPath);
                _sb = new StringBuilder();
                
                FFMpegCommand = ArgsBuilder.ArgumentBuilder(InputVideoPath, OutputVideoPath, AvisynthScriptPath, vCodec,
                tune, mode, vBitrate, crf, preset, aCodec, aBitrate, fps, bFrame, vHeight, vWidth, algo, sRate, sharpen,
                version, mute);
                

                NewProcess(ExeName.FFMpeg, FFMpegPath, FFMpegCommand);
                _process.ErrorDataReceived += OutputData;
                FFEncoder.TryStartProcess(_fflog, _process, _sb, this);
            }
            else
            {
                CatchException($"The selected input is not a video or is not a supported video format.", out FFExceptionHandler handler);
                UpdateException(handler);
            }
        }

        /// <summary>
        /// Method to convert a video using a one click method and settings automatically defined.
        /// </summary>
        /// <param name="vCodec">The video codec for FFMpeg to use.</param>
        /// <param name="version">The version of FrameGUI.</param>
        public void ConvertOneClick(string vCodec, string version)
        {
            Cancelled = false;

            if (SupportedFiles())
            {
                _process = null;
                AvsError = false;

                if (_sb != null)
                {
                    _sb.Clear();
                    _sb = null;
                }

                _fflog = File.CreateText(FFMpegLogPath);
                _sb = new StringBuilder();

                FFMpegCommand = ArgsBuilder.OneCArguments(InputVideoPath, OutputVideoPath, AvisynthScriptPath, vCodec, version);

                NewProcess(ExeName.FFMpeg, FFMpegPath, FFMpegCommand);
                _process.ErrorDataReceived += OutputData;
                FFEncoder.TryStartProcess(_fflog, _process, _sb, this);
            }
            else
            {
                CatchException($"The selected input is not a video or is not a supported video format.", out FFExceptionHandler handler);
                UpdateException(handler);
            }
        }

        /// <summary>
        /// Gets the input FPS of the selected input video for use of one-click encoding method.
        /// </summary>
        public void GetVideoFPS()
        {
            Cancelled = false;

            if (SupportedFiles())
            {
                _process = null;

                string command = $@"-i ""{InputVideoPath}""";
                NewProcess(ExeName.FFMpeg, FFMpegPath, command);
                _process.ErrorDataReceived += (sender, e) =>
                {
                    if (e.Data == null)
                    {
                        return;
                    }

                    if (RegexTool.CheckRegexFPSInfoMatch(e.Data, out InfoFPSHandler handler))
                    {
                        UpdateInputVideoFPS(handler);
                    }
                };

                FFHelper.FFMpegPathNullOrMissing(FFMpegPath);
                FFHelper.InputFileNullOrMissing(InputVideoPath);

                _process.Start();
                _process.BeginErrorReadLine();
                _process.WaitForExit();
            }
            else
            {
                CatchException($"The selected input is not a video or is not a supported video format.", out FFExceptionHandler handler);
                UpdateException(handler);
            }
        }

        /// <summary>
        /// NOT YET TESTED; WIP
        /// </summary>
        public void GetVideoInfo()
        {
            if (SupportedFiles())
            {
                _process = null;

                string command = $@"-i ""{InputVideoPath}""";
                NewProcess(ExeName.FFMpeg, FFMpegPath, command);
                _process.ErrorDataReceived += OutputData;
                FFEncoder.TryStartProcess(_fflog, _process, _sb, this);
            }
            else
            {
                CatchException($"The selected input is not a video or is not a supported video format.", out FFExceptionHandler handler);
                UpdateException(handler);
            }
        }

        /// <summary>
        /// Fixes the progress percentage if complete but if the conversion progress info doesn't indicate completed.
        /// </summary>
        public bool FixPercentage()
        {
            if (!Cancelled)
            {
                var progress = new ConversionProgress("100", FFEncoder.Timer);
                UpdateConversionProgress(progress);

                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// True or false if output data contains an AviSynth+ error.
        /// </summary>
        private bool AvsError { get; set; }

        /// <summary>
        /// FFMpeg output console data.
        /// </summary>
        /// <param name="sender">Process object.</param>
        /// <param name="e">Instance of DataReceivedEventArgs.</param>
        private void OutputData(object sender, DataReceivedEventArgs e)
        {
            if (e.Data == null)
            {
                return;
            }

            RegexTool.CheckRegexDurationMatch(e.Data);
            RegexTool.CheckRegexProgressFPSMatch(e.Data);

            if (RegexTool.CheckProgressRegexMatch(e.Data, out ConversionProgress progress))
            {
                UpdateConversionProgress(progress);
            }

            if (!e.Data.Contains("frame="))
            {
                _fflog.WriteLine(e.Data);
            }

            //Gets the second line of the AviSynth+ error if exists.
            if (AvsError)
            {
                if (!e.Data.Contains(find.Last()) && !e.Data.Contains(AvisynthScriptPath))
                {
                    _sb.Append(" - ");
                    _sb.Append(e.Data.TrimStart());
                }
                    
                AvsError = false;
            }

            if (e.Data.Contains(find.First()))
            {
                _sb.Append(RegexTool.CheckAviSynthErrorMatch(e.Data));
                AvsError = true;
            }

            if (e.Data.Contains(AvisynthScriptPath) && string.IsNullOrEmpty(_sb.ToString()) && !string.IsNullOrEmpty(AvisynthScriptPath))
            {
                _sb.Append(FFHelper.AviSynthNullOrMissing(AvisynthDllPath, AvisynthPlusPath));
            }
        }
    }
}
