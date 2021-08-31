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

using System;
using System.IO;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.ComponentModel;
using System.Runtime.InteropServices;
using FrameGUI.Properties;
using FFLoader;

namespace FrameGUI
{
    public partial class FrameGUI : Form
    {
        internal FFLoaderBase _ffloader = new FFLoaderBase();

        /// <summary>
        /// Toggles what output file types are allowed based on the output container selection.
        /// </summary>
        private string Filter1 { get; set; }

        /// <summary>
        /// The input video FPS.
        /// </summary>
        internal string InputVideoFPS { get; private set; }

        /// <summary>
        /// Link to SVPFlow plugin parameters if the user needs assistance building the SVPFLow parameters.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of LinkLabelClickedEventArgs.</param>
        private void StuckLink_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Process.Start("https://www.svp-team.com/wiki/Manual:SVPflow");
        }

        /// <summary>
        /// The link to DaGoose's Instagram page.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of LinkLabelClickedEventArgs.</param>
        private void InstagramLogo_Click(object sender, EventArgs e)
        {
            Process.Start("https://www.instagram.com/dagooseyt/");
        }

        /// <summary>
        /// The link to DaGoose's YouTube channel.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of LinkLabelClickedEventArgs.</param>
        private void YoutubeLogo_Click(object sender, EventArgs e)
        {
            Process.Start("https://www.youtube.com/c/DaGoose");
        }

        /// <summary>
        /// The link to DaGoose's Twitter page.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of LinkLabelClickedEventArgs.</param>
        private void TwitterLogo_Click(object sender, EventArgs e)
        {
            Process.Start("https://twitter.com/dagooseyt");
        }

        /// <summary>
        /// The link to the official tutorial video of FrameGUI.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of LinkLabelClickedEventArgs.</param>
        private void VideoLinkEN_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Process.Start("https://youtu.be/Fs38PwpMdo4");
        }

        /// <summary>
        /// Sets the path for the input video.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        public void SetInputBttn_Click(object sender, EventArgs e)
        {
            OpenFileDialog InputFileWindow = new OpenFileDialog
            {

                Filter = "All files (*.*)|*.*",
                Title = "Select Input File",

            };

            if (InputFileWindow.ShowDialog() == DialogResult.OK)
            {
                InTxtBox.Text = InputFileWindow.FileName;
            }
        }

        /// <summary>
        /// Sets the output video path.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void SaveOutBttn_Click(object sender, EventArgs e)
        {
            if (FormatDD.SelectedIndex == 0)
            {
                Filter1 = "MP4 files(*.mp4)| *.mp4";
            }
            else if (FormatDD.SelectedIndex == 1)
            {
                Filter1 = "MKV Files (*.mkv)|*.mkv";
            }
            else if (FormatDD.SelectedIndex == 2)
            {
                Filter1 = "AVI Files (*.avi)|*.avi";
            }
            else if (FormatDD.SelectedIndex == 3)
            {
                Filter1 = "MOV Files (*.mov)|*.mov";
            }
            else if (FormatDD.SelectedIndex == 4)
            {
                Filter1 = "FLV Files (*.flv)|*.flv";
            }

            SaveFileDialog OutputFileWindow = new SaveFileDialog
            {
                Filter = Filter1,
                Title = "Save Output File",
            };

            if (OutputFileWindow.ShowDialog() == DialogResult.OK)
            {
                SaveOutTxtBox.Text = OutputFileWindow.FileName;
            }
        }

        /// <summary>
        /// Cancels the running encoding process.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        public void CancelClick(object sender, EventArgs e)
        {
            if (FFWorker.IsBusy)
            {
                if (ProgressLabel.Text != "The process will begin momentarily...")
                {
                    if (MessageBox.Show("Are you sure you want to cancel the encoding process? All encoded data associated with the process will be lost.", "Cancel encode confirmation",
                MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation) == DialogResult.Yes)
                    {
                        FFWorker.CancelAsync();
                        _ffloader.StopFFMpegProcess();
                        ProgressLabel.ForeColor = Color.Red;
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    MessageBox.Show("Please wait for the process to initialize before canceling it.", "FrameGUI error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                CancelBttn.Visible = false;
                return;
            }
        }

        /// <summary>
        /// The execution status' of kernel.
        /// </summary>
        internal enum EXECUTION_STATE : uint
        {
            ES_DISPLAY_REQUIRED = 0x00000002,
            ES_SYSTEM_REQUIRED = 0x00000001,
            ES_CONTINUOUS = 0x80000000,
            ES_AWAYMODE_REQUIRED = 0x00000040
        }

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        static extern EXECUTION_STATE SetThreadExecutionState(EXECUTION_STATE status);

        /// <summary>
        /// Initializes the encoding process.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void StartEncodeBttn_Click(object sender, EventArgs e)
        {
            //Deselect button.
            StartEncodeBttn.Enabled = false;
            StartEncodeBttn.Enabled = true;

            if (!FFWorker.IsBusy)
            {
                if (!string.IsNullOrEmpty(InTxtBox.Text))
                {
                    if (!string.IsNullOrEmpty(SaveOutTxtBox.Text))
                    {
                        if (File.Exists(SaveOutTxtBox.Text))
                        {
                            var message = MessageBox.Show("The selected output file already exists. Would you like to overwrite it?", "Confirm overwrite", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);

                            if (message == DialogResult.Yes)
                            {
                                File.Delete(SaveOutTxtBox.Text);
                            }
                            else 
                            {
                                return; 
                            }
                        }

                        ProgressLabel.Text = "The process will begin momentarily...";

                        CancelBttn.Visible = true;
                        EncodePB.Value = 0;

                        if (NoobCB.Checked)
                        {
                            ScriptGenerator.NoobHelper(FFWorker, _ffloader, UseCB.Checked, CancelBttn, (int)MaxMemNUD.Value, (int)ThreadsNUD.Value, InTxtBox.Text, SaveOutTxtBox.Text, 
                                (int)OutFPSNUD.Value, (int)InputFPSNUD.Value, IwantDD.SelectedIndex, UseGPUCB.Checked);
                        }
                        else
                        {
                            try
                            {
                                ScriptGenerator.AvsGenerate(FFWorker, _ffloader, UseCB.Checked, CancelBttn, (int)MaxMemNUD.Value, (int)ThreadsNUD.Value, InTxtBox.Text,
                            SuperTxtBox.Text, AnalyseTxtBox.Text, SmoothTxtBox.Text, SaveOutTxtBox.Text);
                            }
                            catch (IOException)
                            {
                                MessageBox.Show("FrameGUI is already open and working on a process. Please close any other running tasks of FrameGUI before starting a new process.", "FrameGUI error", MessageBoxButtons.OK, MessageBoxIcon.Error);

                                ProgressLabel.Invoke(new Action(() =>
                                {
                                    ProgressLabel.Text = "Process exited because FrameGUI is already open.";
                                }));

                                ProgressLabel.ForeColor = Color.Red;
                            }
                        }
                    }
                    else
                    {
                        MessageBox.Show("An output video file must be specified.", "FrameGUI exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
                else
                {
                    MessageBox.Show("An input video file must be specified.", "FrameGUI exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("FrameGUI is currently busy with another process. Please wait until that process is finished or cancelled before starting a new one.", 
                    "FrameGUI exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        /// <summary>
        /// Instance of DoWork event from FFWorker. 
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of DoWorkEventArgs.</param>
        internal void DoWork(object sender, DoWorkEventArgs e)
        {
            SetThreadExecutionState(EXECUTION_STATE.ES_SYSTEM_REQUIRED);

            Encoder.WhileWorking(_ffloader, CPUPDD, TuneDD, ResizeAlgoDD, AudFormatDD, SRDD, EncodeModeDD, AudBitrateDD, ProgressLabel, EncodePB, (double)FrameRNUD.Value, 
                (double)BframeValue.Value, (double)BitrateValue.Value, (double)crfNUD.Value, (double)HeightResNUD.Value, (double)WidthResNUD.Value, (float)SharpenValNUD.Value, Text);
        }

        /// <summary>
        /// Instance of WorkCompleted event from FFWorker.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of RunWorkerCompletedEventArgs.</param>
        internal void WorkCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            SetThreadExecutionState(EXECUTION_STATE.ES_CONTINUOUS);

            Encoder.WhileComplete(_ffloader, EncodePB, NotificationCB, CancelBttn);

            if (File.Exists(InTxtBox.Text + ".ffindex"))
            {
                File.Delete(InTxtBox.Text + ".ffindex");
            }
        }

        /// <summary>
        /// Definition for when tuning use checkbox check changes.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void UseCB2_CheckedChanged(object sender, EventArgs e)
        {
            if (UseCB2.Checked)
            {
                TuneDD.Enabled = true;
                TuneDD.SelectedIndex = Settings.Default.Tune;
            }
            else { TuneDD.Enabled = false; TuneDD.SelectedIndex = 0; }
        }

        /// <summary>
        /// If key F1 is clicked or help is requested through the help button, the documentation of FrameGUI will open.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="hlpevent">Instance of HelpEventArgs.</param>
        private void FrameGUI_HelpRequested(object sender, HelpEventArgs hlpevent)
        {
            Process.Start("https://github.com/DaGooseYT/FrameGUI/blob/main/README.md");
        }

        /// <summary>
        /// Opens the offical documentation for FrameGUI.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void OffDoc_Click(object sender, EventArgs e)
        {
            Process.Start("https://github.com/DaGooseYT/FrameGUI/blob/main/README.md");
        }

        /// <summary>
        /// Changes the output video file to string.empty if format changed to prevent exception
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void FormatDD_TabIndexChanged(object sender, EventArgs e)
        {
            SaveOutTxtBox.Text = string.Empty;
        }

        /// <summary>
        /// Determines if a process is running and if so will show a message box to cancel the process first before closing the form.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of FormClosingEventArgs.</param>
        public void FrameGUIClosing(object sender, FormClosingEventArgs e)
        {
            if (FFWorker.IsBusy)
            {
                var gui = MessageBox.Show("Please cancel the current running process before closing FrameGUI", "Cancel encode error",
                MessageBoxButtons.OK, MessageBoxIcon.Error);
                e.Cancel = (gui == DialogResult.OK);
            }
        }

        /// <summary>
        /// Checks to make sure AviSynth.dll and AviSynth+ directory exists.
        /// </summary>
        /// <returns>True or False.</returns>
        internal bool CheckAviSynthExists()
        {
            if (!File.Exists(_ffloader.AvisynthDllPath) || !Directory.Exists(_ffloader.AvisynthPlusPath))
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// <summary>
        /// Copies the FFMpeg command of the current running process.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void CopyCommandBttn_Click(object sender, EventArgs e)
        {
            if (!FFWorker.IsBusy)
            {
                MessageBox.Show("A process must be running before the FFMpeg command can be copied.", "Parse command error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Clipboard.SetText("ffmpeg " + _ffloader.FFMpegCommand);
                MessageBox.Show("FFMpeg command copied to clipboard!", "Command copy successful", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        /// <summary>
        /// Sets the output FPS in noob configuration based on the input FPS.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void InputFPSNUD_ValueChanged(object sender, EventArgs e)
        {
            OutFPSNUD.Minimum = InputFPSNUD.Value;
        }

        /// <summary>
        /// Opens the path to the logs and avs script file on the user's temp folder.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void LogsBttn_Click(object sender, EventArgs e)
        {
            if (Directory.Exists(SetUserTempPath()))
            {
                Process.Start("explorer.exe", SetUserTempPath());
            }
        }

        /// <summary>
        /// Creates the Temp path for FrameGUI.
        /// </summary>
        private string SetUserTempPath()
        {
            string tempPath = Path.GetTempPath() + "FrameGUI";

            if (!Directory.Exists(tempPath))
            {
                Directory.CreateDirectory(tempPath);
            }

            return tempPath;
        }

        /// <summary>
        /// Enables the sharpen numeric up-down if sharpen checkbox is checked.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void SharpenCB_CheckedChanged(object sender, EventArgs e)
        {
            if (SharpenCB.Checked)
            {
                SharpenValNUD.Value = Settings.Default.SharpenVal;
                SharpenValNUD.Enabled = true;
            }
            else
            {
                SharpenValNUD.Value = 0;
                SharpenValNUD.Enabled = false;
            }
        }

        /// <summary>
        /// Enables all functions of AviSynth+ in FrameGUI if use checkbox is checked.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void UseCB_CheckedChanged(object sender, EventArgs e)
        {
            if (UseCB.Checked)
            {
                if (CheckAviSynthExists())
                {
                    SuperTxtBox.Enabled = true;
                    AnalyseTxtBox.Enabled = true;
                    SmoothTxtBox.Enabled = true;
                    ThreadsNUD.Enabled = true;
                    ThreadsNUD.Value = Settings.Default.Threads;
                    FrameRNUD.Enabled = false;
                    FrameRNUD.Value = 0;
                    MaxMemNUD.Enabled = true;
                    MaxMemNUD.Value = Settings.Default.MaxMem;
                    InputFPSNUD.Enabled = true;
                    OutFPSNUD.Enabled = true;
                    IwantDD.Enabled = true;
                    UseGPUCB.Enabled = true;
                }
                else
                {
                    UseCB.Checked = false;

                    var action = MessageBox.Show($@"AviSynth+ is not installed and is required for FrameGUI to use this function. Would you like to install AviSynth+ now?", 
                        "Action needed", MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation);

                    if (action == DialogResult.Yes)
                    {
                        try
                        {
                            Process.Start(Directory.GetCurrentDirectory() + @"\AviSynth+\AviSynthPlus_3.7.0_vcredist.exe");
                        }
                        catch (Win32Exception)
                        {
                            MessageBox.Show(@"FrameGUI failed to load the installer for AviSynth+ in ""\FrameGUI\AviSynth+\AviSynthPlus_3.7.0_vcredist.exe"" 
                                Please ensure that no antivirus software or other program deleted the installer.", "AviSynth+ install error", MessageBoxButtons.OK, 
                                MessageBoxIcon.Error);
                        }
                    }
                }
            }
            else
            {
                SuperTxtBox.Enabled = false;
                AnalyseTxtBox.Enabled = false;
                SmoothTxtBox.Enabled = false;
                ThreadsNUD.Enabled = false;
                ThreadsNUD.Value = 0;
                FrameRNUD.Enabled = true;
                FrameRNUD.Value = Settings.Default.FrameRate;
                MaxMemNUD.Enabled = false;
                MaxMemNUD.Value = 0;
                InputFPSNUD.Enabled = false;
                OutFPSNUD.Enabled = false;
                IwantDD.Enabled = false;
                UseGPUCB.Enabled = false;
            }
        }

        /// <summary>
        /// Changes the encode mode settings based on the selected index if encoding mode drop-down.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void EncodeModeDD_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (EncodeModeDD.SelectedIndex == 1)
            {
                BitrateLabel.Visible = true;
                BitrateValue.Visible = true;
                BitrateValue.Value = (decimal)Settings.Default.vBitrate;
                crfValueLabel.Visible = false;
                crfNUD.Visible = false;
            }
            else
            {
                BitrateLabel.Visible = false;
                BitrateValue.Visible = false;
                BitrateValue.Value = 0;
                crfValueLabel.Visible = true;
                crfNUD.Visible = true;
            }
        }

        /// <summary>
        /// Enables all functions for resize if change resolution checkbox is checked.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void ChangeResCB_CheckedChanged(object sender, EventArgs e)
        {
            if (ChangeResCB.Checked)
            {
                HeightResNUD.Value = Settings.Default.Height;
                WidthResNUD.Value = Settings.Default.Width;
                HeightResNUD.Enabled = true;
                WidthResNUD.Enabled = true;
                ResizeAlgoDD.Enabled = true;
                ResizeAlgoDD.SelectedIndex = Settings.Default.Algo;
            }
            else
            {
                HeightResNUD.Value = 0;
                WidthResNUD.Value = 0;
                HeightResNUD.Enabled = false;
                WidthResNUD.Enabled = false;
                ResizeAlgoDD.Enabled = false;
                ResizeAlgoDD.SelectedIndex = 0;
            }
        }

        /// <summary>
        /// Provides an easy user interface for those who don't know or don't want to learn the SVPFlow parameters syntax.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void NoobCB_CheckedChanged(object sender, EventArgs e)
        {
            if (NoobCB.Checked)
            {
                SmoothLabel.Visible = false;
                SmoothTxtBox.Visible = false;
                AnalyseLabel.Visible = false;
                AnalyseTxtBox.Visible = false;
                SuperLabel.Visible = false;
                SuperTxtBox.Visible = false;
                StuckLink.Visible = false;
                StuckLabel.Visible = false;

                IwantDD.Visible = true;
                IwantLabel.Visible = true;
                InputFPSNUD.Visible = true;
                InputFPSLabel.Visible = true;
                OutFPSLabel.Visible = true;
                OutFPSNUD.Visible = true;
                UseGPUCB.Visible = true;
                ArtefactLabel.Visible = true;
            }
            else
            {
                SmoothLabel.Visible = true;
                SmoothTxtBox.Visible = true;
                AnalyseLabel.Visible = true;
                AnalyseTxtBox.Visible = true;
                SuperLabel.Visible = true;
                SuperTxtBox.Visible = true;
                StuckLink.Visible = true;
                StuckLabel.Visible = true;

                IwantDD.Visible = false;
                IwantLabel.Visible = false;
                InputFPSNUD.Visible = false;
                InputFPSLabel.Visible = false;
                OutFPSLabel.Visible = false;
                OutFPSNUD.Visible = false;
                UseGPUCB.Visible = false;
                ArtefactLabel.Visible = false;
            }
        }

        /// <summary>
        /// Saves user settings on button click.
        /// </summary>
        /// <param name="sender">FrameGUI object.</param>
        /// <param name="e">Instance of EventArgs.</param>
        private void SaveSettingBttn_Click(object sender, EventArgs e)
        {
            Settings.Default.SmoothScript = SmoothTxtBox.Text;
            Settings.Default.SuperScript = SuperTxtBox.Text;
            Settings.Default.AnalyseScript = AnalyseTxtBox.Text;
            Settings.Default.AudioBitrate = AudBitrateDD.SelectedIndex;
            Settings.Default.AudioFormat = AudFormatDD.SelectedIndex;
            Settings.Default.AudioSampleRate = SRDD.SelectedIndex;
            Settings.Default.EncodeMode = EncodeModeDD.SelectedIndex;
            Settings.Default.Preset = CPUPDD.SelectedIndex;
            Settings.Default.Use2CB = UseCB2.Checked;
            Settings.Default.Not = NotificationCB.Checked;
            Settings.Default.iWant = IwantDD.SelectedIndex;

            if (UseCB.Checked)
            {
                Settings.Default.Threads = (int)ThreadsNUD.Value;
                Settings.Default.MaxMem = (int)MaxMemNUD.Value;
            }
            else
            {
                Settings.Default.FrameRate = FrameRNUD.Value;
            }

            Settings.Default.Colors = ColorsDD.SelectedIndex;

            if (UseCB2.Checked)
            {
                Settings.Default.Tune = TuneDD.SelectedIndex;
            }

            if (EncodeModeDD.SelectedIndex == 1)
            {
                Settings.Default.vBitrate = (int)BitrateValue.Value;
            }
            
            if (ChangeResCB.Checked)
            {
                Settings.Default.Height = (int)HeightResNUD.Value;
                Settings.Default.Width = (int)WidthResNUD.Value;
                Settings.Default.Algo = ResizeAlgoDD.SelectedIndex;
            }

            Settings.Default.SharpenCB = SharpenCB.Checked;
            Settings.Default.NoobCB = NoobCB.Checked;
            Settings.Default.Format = FormatDD.SelectedIndex;
            Settings.Default.GPUCB = UseGPUCB.Checked;
            Settings.Default.InFPS = (int)InputFPSNUD.Value;
            Settings.Default.OutFPS = (int)OutFPSNUD.Value;
            Settings.Default.CRF = (int)crfNUD.Value;
            Settings.Default.ChangeRes = ChangeResCB.Checked;
            Settings.Default.BFrames = (int)BframeValue.Value;

            if (SharpenCB.Checked)
            {
                Settings.Default.SharpenVal = SharpenValNUD.Value;
            }

            Settings.Default.Save();
            MessageBox.Show("Current settings saved!", "Save complete", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        /// <summary>
        /// Loads the settings saved by the user.
        /// </summary>
        private void InitializeSavedSettings()
        {
            SmoothTxtBox.Text = Settings.Default.SmoothScript;
            AnalyseTxtBox.Text = Settings.Default.AnalyseScript;
            SuperTxtBox.Text = Settings.Default.SuperScript;
            CPUPDD.SelectedIndex = Settings.Default.Preset;
            FormatDD.SelectedIndex = Settings.Default.Format;
            EncodeModeDD.SelectedIndex = Settings.Default.EncodeMode;
            ColorsDD.SelectedIndex = Settings.Default.Colors;
            AudFormatDD.SelectedIndex = Settings.Default.AudioFormat;
            SRDD.SelectedIndex = Settings.Default.AudioSampleRate;
            ChangeResCB.Checked = Settings.Default.ChangeRes;
            BframeValue.Value = Settings.Default.BFrames;
            NotificationCB.Checked = Settings.Default.Not;
            IwantDD.SelectedIndex = Settings.Default.iWant;
            FrameRNUD.Value = Settings.Default.FrameRate;

            if (Settings.Default.ChangeRes)
            {
                HeightResNUD.Value = Settings.Default.Height;
                WidthResNUD.Value = Settings.Default.Width;
                ResizeAlgoDD.SelectedIndex = Settings.Default.Algo;
            }
            else
            {
                HeightResNUD.Value = 0;
                WidthResNUD.Value = 0;
                ResizeAlgoDD.SelectedIndex = 0;
            }

            UseCB2.Checked = Settings.Default.Use2CB;

            if (Settings.Default.Use2CB)
            {
                TuneDD.SelectedIndex = Settings.Default.Tune;
            }
            else
            {
                TuneDD.SelectedIndex = 0;
            }

            AudBitrateDD.SelectedIndex = Settings.Default.AudioBitrate;
            IwantDD.SelectedIndex = Settings.Default.iWant;
            NoobCB.Checked = Settings.Default.NoobCB;
            UseGPUCB.Checked = Settings.Default.GPUCB;
            InputFPSNUD.Value = Settings.Default.InFPS;
            OutFPSNUD.Value = Settings.Default.OutFPS;
            crfNUD.Value = Settings.Default.CRF;
            SharpenCB.Checked = Settings.Default.SharpenCB;

            if (Settings.Default.SharpenCB)
            {
                SharpenValNUD.Value = Settings.Default.SharpenVal;
            }
            else
            {
                SharpenValNUD.Value = 0;
                SharpenValNUD.Enabled = false;
            }
            
            OutFPSNUD.Minimum = InputFPSNUD.Value;
        }

        /// <summary>
        /// Intialize FrameGUI and load it's configuration.
        /// </summary>
        public FrameGUI()
        {
            InitializeComponent();
            InitializeSavedSettings();
            SetUserTempPath();

            FFWorker.DoWork += new DoWorkEventHandler(DoWork);
            FFWorker.RunWorkerCompleted += new RunWorkerCompletedEventHandler(WorkCompleted);
            FormClosing += new FormClosingEventHandler(FrameGUIClosing);
            HelpRequested += FrameGUI_HelpRequested;
            FormatDD.TextChanged += new EventHandler(FormatDD_TabIndexChanged);
        }
    }
}