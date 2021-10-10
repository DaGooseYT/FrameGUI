using System;
using System.IO;
using System.Drawing;
using System.Diagnostics;
using System.ComponentModel;
using System.Windows.Forms;
using FFLoader;
using EncodeProg;

namespace FrameGUI
{
    public class Encoder
    {
        /// <summary>
        /// The selected CPU preset.
        /// </summary>
        private static object Preset { get; set; }

        /// <summary>
        /// The selected video tuning.
        /// </summary>
        private static object Tune { get; set; }

        /// <summary>
        /// The selected rezise algorithm. 
        /// </summary>
        private static object ResizeAlgo { get; set; }

        /// <summary>
        /// The format/container of the audio of video.
        /// </summary>
        private static object AudioFormat { get; set; }

        /// <summary>
        /// The bitrate of the audio.
        /// </summary>
        private static object AudioBitrate { get; set; }

        /// <summary>
        /// The sample rate of the audio.
        /// </summary>
        private static object AudioSR { get; set; }

        /// <summary>
        /// The encoding mode for the video.
        /// </summary>
        private static object Mode { get; set; }

        /// <summary>
        /// The time elapsed since the start of the encoding process.
        /// </summary>
        internal static TimeSpan TimeElapsed { get; private set; }

        /// <summary>
        /// Instance of FFLoader.
        /// </summary>
        private static FFLoaderBase FFloader { get; set; }

        /// <summary>
        /// Instance of progress bar for conversion.
        /// </summary>
        private static ProgressBarLabel EncodePB { get; set; }

        /// <summary>
        /// 
        /// </summary>
        private static ComboBox FMode { get; set; }

        /// <summary>
        /// Configuration for FFLoader.
        /// </summary>
        /// <param name="worker">Instance of FFWorker.</param>
        /// <param name="ffLoader">Instance of FFLoader.</param>
        /// <param name="useCB">Bool of UseCB checked.</param>
        /// <param name="input">Input video file path.</param>
        /// <param name="output">Output video file path.</param>
        internal static void BeginEncode(BackgroundWorker worker, FFLoaderBase ffLoader, bool useCB, string input, string output, int oneClick)
        {
            ffLoader.FFMpegPath = Directory.GetCurrentDirectory() + @"\ffmpeg.exe";

            if (useCB || oneClick == 1)
            {
                ffLoader.AvisynthScriptPath = Path.GetTempPath() + @"FrameGUI\aviscript.avs";
            }
            else
            {
                ffLoader.AvisynthScriptPath = string.Empty;
            }

            ffLoader.InputVideoPath = input;
            ffLoader.OutputVideoPath = output;

            worker.RunWorkerAsync();
        }

        /// <summary>
        /// Tasks to do while encoding is in progress.
        /// </summary>
        /// <param name="ffLoader">Instance of FFLoader.</param>
        /// <param name="preset">Instance of the video/cpu preset drop-down.</param>
        /// <param name="tune">Instance of the video tuning drop-down.</param>
        /// <param name="algo">Instance of the resize algorithm drop-down.</param>
        /// <param name="format">Instance of the output video container drop-down.</param>
        /// <param name="sr">Instance of audio sample rate drop-down.</param>
        /// <param name="mode">Instance of encoding mode drop-down.</param>
        /// <param name="abitrate">Instance of audio bitrate drop-down.</param>
        /// <param name="pb">Instance of conversion progress bar.</param>
        /// <param name="frameRate">The output frame rate if SVPFlow isn't used.</param>
        /// <param name="bframe">The number of consecutive b-frames.</param>
        /// <param name="vbitrate">The output video bitrate.</param>
        /// <param name="crf">The value of constant rate factor.</param>
        /// <param name="height">The height of the video in pixels.</param>
        /// <param name="width">The width of the video in pixels.</param>
        internal static void WhileWorking(FFLoaderBase ffLoader, ComboBox preset, ComboBox tune, ComboBox algo, ComboBox format, ComboBox sr, 
            ComboBox mode, ComboBox abitrate, ProgressBarLabel pb, int fmode, double frameRate, double bframe, double vbitrate, double crf, 
            double height, double width, float sharpen, string version, bool mute)
        {
            EncodePB = pb;
            FFloader = ffLoader;

            //Prevents cross-threading errors.
            if (fmode == 0)
            {
                preset.Invoke(new Action(() => { Preset = preset.SelectedItem; }));
                tune.Invoke(new Action(() => { Tune = tune.SelectedItem; }));
                algo.Invoke(new Action(() => { ResizeAlgo = algo.SelectedItem; }));
                format.Invoke(new Action(() => { AudioFormat = format.SelectedItem; }));
                abitrate.Invoke(new Action(() => { AudioBitrate = abitrate.SelectedItem; }));
                sr.Invoke(new Action(() => { AudioSR = sr.SelectedItem; }));
                mode.Invoke(new Action(() => { Mode = mode.SelectedItem; }));
            }

            //Subcribe to events.
            ffLoader.FFConversionProgress += UpdateProgress;
            ffLoader.FFLoaderException += FFException;
            ffLoader.AviSynthError += AvsError;
            ffLoader.FFMpegError += FFError;

            try
            {
                if (fmode == 0)
                {
                    ffLoader.ConvertFFMpeg("libx264", Mode.ToString(), Preset.ToString(), Tune.ToString(), ResizeAlgo.ToString(), AudioFormat.ToString(),
                    AudioBitrate.ToString(), AudioSR.ToString(), height, width, vbitrate, frameRate, bframe, crf, sharpen, version, mute);
                }
                else
                {
                    ffLoader.ConvertOneClick("libx264", version);
                }
            }
            catch (IOException)
            {
                MessageBox.Show("FrameGUI is already open and working on a process. Please close any other running tasks of FrameGUI before starting a new process.", "FrameGUI error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                
                EncodePB.Invoke(new Action(() =>
                {
                    EncodePB.ProgressText = "Process exited because FrameGUI is already open.";
                }));
                
                EncodePB.TextColor = Color.Red;
            }
        }

        /// <summary>
        /// Tasks to do when the encoding process is complete.
        /// </summary>
        /// <param name="pb">Instance of conversion progress bar.</param>
        /// <param name="not">Instance of NotificationCB checkbox.</param>
        /// <param name="cancel">Instance of cancel button.</param>
        internal static void WhileComplete(FFLoaderBase ffLoader, ProgressBarLabel pb, CheckBox not, Button cancel)
        {
            cancel.Visible = false;

            if (ffLoader.FixPercentage() && pb.Value > 0)
            {
                if (not.Checked)
                {
                    MessageBox.Show($"Encoding process complete after (hh:mm:ss) {TimeElapsed}", "Encoding Complete", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }

            //Unsubscribe from events
            ffLoader.FFConversionProgress -= UpdateProgress;
            ffLoader.FFLoaderException -= FFException;
            ffLoader.FFMpegError -= FFError;
            ffLoader.AviSynthError -= AvsError;
        }

        /// <summary>
        /// Raises when there is an exception caught within FFLoader conversion.
        /// </summary>
        /// <param name="sender">FFLoader object.</param>
        /// <param name="e">Instance of FFExceptionHandler.</param>
        internal static void FFException(object sender, FFExceptionHandler e)
        {
            EncodePB.Invoke(new Action(() =>
            {
                EncodePB.ProgressText = "Process exited with FFLoader error.";
            }));

            EncodePB.TextColor = Color.Red;

            ProcessWorker.Cancelled = true;

            MessageBox.Show("FFLoader ran into a problem: " + Environment.NewLine + Environment.NewLine + 
                $@"""{e.Message}""", "FFLoader exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        /// <summary>
        /// Raises when there is a problem with the configuration or parameters of AviSynth+ from FFMpeg console.
        /// </summary>
        /// <param name="sender">FFLoader object.</param>
        /// <param name="e">Instance of AviSynthErrorHandler.</param>
        internal static void AvsError(object sender, AviSynthErrorHandler e)
        {
            EncodePB.Invoke(new Action(() =>
            {
                EncodePB.ProgressText = "Process exited with AviSynth+ error.";
            }));

            if (EncodePB.Value >= 1)
            {
                EncodePB.ProgressColor = Brushes.OrangeRed;
            }
            else
            {
                EncodePB.TextColor = Color.Red;
            }

            var error = MessageBox.Show("Process exited with AviSynth+ error: " + Environment.NewLine +
                Environment.NewLine + $@"""{e.AviSynthErrorMessage}""" + Environment.NewLine +
                Environment.NewLine + "Would you like to open the error logs?", "AviSynth+ error",
                MessageBoxButtons.YesNo, MessageBoxIcon.Error);

            if (error == DialogResult.Yes)
            {
                Process.Start(FFloader.FFMpegLogPath);
            }
        }

        /// <summary>
        /// Raises when there is a problem with FFMpeg (such as invalid arguments).
        /// </summary>
        /// <param name="sender">FFLoader object.</param>
        /// <param name="e">Instance of FFMpegErrorHandler.</param>
        internal static void FFError(object sender, FFMpegErrorHandler e)
        {
            EncodePB.Invoke(new Action(() =>
            {
                EncodePB.ProgressText = "Process exited with FFMpeg error.";
            }));

            EncodePB.TextColor = Color.Red;

            var error = MessageBox.Show("Process exited with FFMpeg error: " + Environment.NewLine +
                Environment.NewLine + $@"""{e.ErrorMessage}""" + Environment.NewLine +
                Environment.NewLine + "Would you like to open the error logs?", "FFMpeg error",
                MessageBoxButtons.YesNo, MessageBoxIcon.Error);

            if (error == DialogResult.Yes)
            {
                Process.Start(FFloader.FFMpegLogPath);
            }
        }

        /// <summary>
        /// Updates conversion progress info from the data received from FFMpeg console. 
        /// </summary>
        /// <param name="sender">FFLoader object.</param>
        /// <param name="e">Instance of ConversionProgress class.</param>
        internal static void UpdateProgress(object sender, ConversionProgress e)
        {
            EncodePB.Invoke(new Action(() =>
            {
                EncodePB.Value = e.ProgressPercentInt;
                EncodePB.ProgressText = e.ConversionProgressLabel;
                
                TimeElapsed = e.TimeElapsed;
            }));
        }
    }
}
