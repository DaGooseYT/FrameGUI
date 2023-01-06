using System.ComponentModel;
using System.Windows.Forms;
using EncodeProg;

namespace FrameGUI
{
    public partial class FrameGUI : Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        public IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        public void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrameGUI));
            this.SaveOutTxtBox = new System.Windows.Forms.TextBox();
            this.SaveOutBttn = new System.Windows.Forms.Button();
            this.StartEncodeBttn = new System.Windows.Forms.Button();
            this.AboutTab = new System.Windows.Forms.TabPage();
            this.SupportGB = new System.Windows.Forms.GroupBox();
            this.SupportLabel = new System.Windows.Forms.Label();
            this.OffDocButton = new System.Windows.Forms.Button();
            this.HelpLabel = new System.Windows.Forms.Label();
            this.AboutAuthGB = new System.Windows.Forms.GroupBox();
            this.TwitterLogo = new System.Windows.Forms.PictureBox();
            this.InstagramLogo = new System.Windows.Forms.PictureBox();
            this.YoutubeLogo = new System.Windows.Forms.PictureBox();
            this.AboutAuthDesc = new System.Windows.Forms.Label();
            this.AbAuthorLabel = new System.Windows.Forms.Label();
            this.AboutAuthLabel = new System.Windows.Forms.Label();
            this.AboutGUIGB = new System.Windows.Forms.GroupBox();
            this.VideoLinkEN = new System.Windows.Forms.LinkLabel();
            this.AboutGUIDesc = new System.Windows.Forms.Label();
            this.AbGUILabel = new System.Windows.Forms.Label();
            this.AboutGUILabel = new System.Windows.Forms.Label();
            this.MainTab = new System.Windows.Forms.TabPage();
            this.FGUIGB = new System.Windows.Forms.GroupBox();
            this.FGUILabel = new System.Windows.Forms.Label();
            this.FGUIDD = new System.Windows.Forms.ComboBox();
            this.ModeLabel = new System.Windows.Forms.Label();
            this.CancelBttn = new System.Windows.Forms.Button();
            this.FrameGUILogo = new System.Windows.Forms.PictureBox();
            this.SetInputBttn = new System.Windows.Forms.Button();
            this.InTxtBox = new System.Windows.Forms.TextBox();
            this.Tabs = new System.Windows.Forms.TabControl();
            this.SettingsTab = new System.Windows.Forms.TabPage();
            this.SettingsTabs = new System.Windows.Forms.TabControl();
            this.VideoTab = new System.Windows.Forms.TabPage();
            this.SizeGB = new System.Windows.Forms.GroupBox();
            this.ResizeAlgoDD = new System.Windows.Forms.ComboBox();
            this.ResizeAlgoLabel = new System.Windows.Forms.Label();
            this.WidthResNUD = new System.Windows.Forms.NumericUpDown();
            this.WidthLabel = new System.Windows.Forms.Label();
            this.HeightResNUD = new System.Windows.Forms.NumericUpDown();
            this.VidHeightLebel = new System.Windows.Forms.Label();
            this.ChangeResCB = new System.Windows.Forms.CheckBox();
            this.SizeLabel = new System.Windows.Forms.Label();
            this.EncodeGB = new System.Windows.Forms.GroupBox();
            this.ColorsGB = new System.Windows.Forms.GroupBox();
            this.SharpenValNUD = new System.Windows.Forms.NumericUpDown();
            this.SharpenCB = new System.Windows.Forms.CheckBox();
            this.ColorsDD = new System.Windows.Forms.ComboBox();
            this.ColorsLabel = new System.Windows.Forms.Label();
            this.FrameGB = new System.Windows.Forms.GroupBox();
            this.FrameLabel = new System.Windows.Forms.Label();
            this.FRLabel = new System.Windows.Forms.Label();
            this.FrameRNUD = new System.Windows.Forms.NumericUpDown();
            this.bframeLabel = new System.Windows.Forms.Label();
            this.BframeValue = new System.Windows.Forms.NumericUpDown();
            this.ModeGB = new System.Windows.Forms.GroupBox();
            this.crfNUD = new System.Windows.Forms.NumericUpDown();
            this.crfValueLabel = new System.Windows.Forms.Label();
            this.EModeSettingLabel = new System.Windows.Forms.Label();
            this.BitrateValue = new System.Windows.Forms.NumericUpDown();
            this.BitrateLabel = new System.Windows.Forms.Label();
            this.UseCB2 = new System.Windows.Forms.CheckBox();
            this.TuneDD = new System.Windows.Forms.ComboBox();
            this.TuneLabel = new System.Windows.Forms.Label();
            this.EncodeModeDD = new System.Windows.Forms.ComboBox();
            this.EncodeModeLabel = new System.Windows.Forms.Label();
            this.CPUPDD = new System.Windows.Forms.ComboBox();
            this.CPUPreLabel = new System.Windows.Forms.Label();
            this.EncodeLabel = new System.Windows.Forms.Label();
            this.AudioTab = new System.Windows.Forms.TabPage();
            this.AudioSetGB = new System.Windows.Forms.GroupBox();
            this.MuteAudCB = new System.Windows.Forms.CheckBox();
            this.SRDD = new System.Windows.Forms.ComboBox();
            this.AudNote = new System.Windows.Forms.Label();
            this.AudioSRLabel = new System.Windows.Forms.Label();
            this.AudioBitLabel = new System.Windows.Forms.Label();
            this.AudBitrateDD = new System.Windows.Forms.ComboBox();
            this.AudioSetLabel = new System.Windows.Forms.Label();
            this.AudFormatLabel = new System.Windows.Forms.Label();
            this.AudFormatDD = new System.Windows.Forms.ComboBox();
            this.ScriptOtherTab = new System.Windows.Forms.TabPage();
            this.vsSettingLabel = new System.Windows.Forms.GroupBox();
            this.MaxMemLabel = new System.Windows.Forms.Label();
            this.MaxMemNUD = new System.Windows.Forms.NumericUpDown();
            this.ThreadsNUD = new System.Windows.Forms.NumericUpDown();
            this.ThreadsLabel = new System.Windows.Forms.Label();
            this.aviLabel = new System.Windows.Forms.Label();
            this.OtherSettingGB = new System.Windows.Forms.GroupBox();
            this.LogsBttn = new System.Windows.Forms.Button();
            this.NotificationCB = new System.Windows.Forms.CheckBox();
            this.CopyCommandBttn = new System.Windows.Forms.Button();
            this.SaveSettingBttn = new System.Windows.Forms.Button();
            this.OtherSettingLabel = new System.Windows.Forms.Label();
            this.SettingsGB = new System.Windows.Forms.GroupBox();
            this.FPSLabel = new System.Windows.Forms.Label();
            this.ArtefactLabel = new System.Windows.Forms.Label();
            this.UseGPUCB = new System.Windows.Forms.CheckBox();
            this.IwantDD = new System.Windows.Forms.ComboBox();
            this.IwantLabel = new System.Windows.Forms.Label();
            this.OutFPSNUD = new System.Windows.Forms.NumericUpDown();
            this.OutFPSLabel = new System.Windows.Forms.Label();
            this.InputFPSLabel = new System.Windows.Forms.Label();
            this.NoobCB = new System.Windows.Forms.CheckBox();
            this.UseCB = new System.Windows.Forms.CheckBox();
            this.StuckLink = new System.Windows.Forms.LinkLabel();
            this.StuckLabel = new System.Windows.Forms.Label();
            this.AnalyseTxtBox = new System.Windows.Forms.TextBox();
            this.AnalyseLabel = new System.Windows.Forms.Label();
            this.SuperTxtBox = new System.Windows.Forms.TextBox();
            this.SmoothTxtBox = new System.Windows.Forms.TextBox();
            this.SuperLabel = new System.Windows.Forms.Label();
            this.SmoothLabel = new System.Windows.Forms.Label();
            this.ScriptsLabel = new System.Windows.Forms.Label();
            this.FormatDD = new System.Windows.Forms.ComboBox();
            this.FFWorker = new System.ComponentModel.BackgroundWorker();
            this.FPSGrabber = new System.ComponentModel.BackgroundWorker();
            this.EncodePB = new EncodeProg.ProgressBarLabel();
            this.AboutTab.SuspendLayout();
            this.SupportGB.SuspendLayout();
            this.AboutAuthGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TwitterLogo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.InstagramLogo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.YoutubeLogo)).BeginInit();
            this.AboutGUIGB.SuspendLayout();
            this.MainTab.SuspendLayout();
            this.FGUIGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FrameGUILogo)).BeginInit();
            this.Tabs.SuspendLayout();
            this.SettingsTab.SuspendLayout();
            this.SettingsTabs.SuspendLayout();
            this.VideoTab.SuspendLayout();
            this.SizeGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.WidthResNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.HeightResNUD)).BeginInit();
            this.EncodeGB.SuspendLayout();
            this.ColorsGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SharpenValNUD)).BeginInit();
            this.FrameGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FrameRNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BframeValue)).BeginInit();
            this.ModeGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.crfNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.BitrateValue)).BeginInit();
            this.AudioTab.SuspendLayout();
            this.AudioSetGB.SuspendLayout();
            this.ScriptOtherTab.SuspendLayout();
            this.vsSettingLabel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.MaxMemNUD)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ThreadsNUD)).BeginInit();
            this.OtherSettingGB.SuspendLayout();
            this.SettingsGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.OutFPSNUD)).BeginInit();
            this.SuspendLayout();
            // 
            // SaveOutTxtBox
            // 
            this.SaveOutTxtBox.Enabled = false;
            this.SaveOutTxtBox.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SaveOutTxtBox.Location = new System.Drawing.Point(10, 332);
            this.SaveOutTxtBox.Name = "SaveOutTxtBox";
            this.SaveOutTxtBox.Size = new System.Drawing.Size(433, 22);
            this.SaveOutTxtBox.TabIndex = 1;
            this.SaveOutTxtBox.TabStop = false;
            // 
            // SaveOutBttn
            // 
            this.SaveOutBttn.BackColor = System.Drawing.SystemColors.ControlLight;
            this.SaveOutBttn.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.SaveOutBttn.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SaveOutBttn.Location = new System.Drawing.Point(514, 330);
            this.SaveOutBttn.Name = "SaveOutBttn";
            this.SaveOutBttn.Size = new System.Drawing.Size(107, 26);
            this.SaveOutBttn.TabIndex = 41;
            this.SaveOutBttn.Text = "Save Output";
            this.SaveOutBttn.UseVisualStyleBackColor = false;
            this.SaveOutBttn.Click += new System.EventHandler(this.SaveOutBttn_Click);
            // 
            // StartEncodeBttn
            // 
            this.StartEncodeBttn.Font = new System.Drawing.Font("Arial", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.StartEncodeBttn.ForeColor = System.Drawing.Color.Green;
            this.StartEncodeBttn.Location = new System.Drawing.Point(324, 140);
            this.StartEncodeBttn.Name = "StartEncodeBttn";
            this.StartEncodeBttn.Size = new System.Drawing.Size(231, 69);
            this.StartEncodeBttn.TabIndex = 2;
            this.StartEncodeBttn.Text = "Start Encode";
            this.StartEncodeBttn.UseVisualStyleBackColor = true;
            this.StartEncodeBttn.Click += new System.EventHandler(this.StartEncodeBttn_Click);
            // 
            // AboutTab
            // 
            this.AboutTab.Controls.Add(this.SupportGB);
            this.AboutTab.Controls.Add(this.AboutAuthGB);
            this.AboutTab.Controls.Add(this.AboutGUIGB);
            this.AboutTab.Location = new System.Drawing.Point(4, 25);
            this.AboutTab.Name = "AboutTab";
            this.AboutTab.Padding = new System.Windows.Forms.Padding(3);
            this.AboutTab.Size = new System.Drawing.Size(604, 293);
            this.AboutTab.TabIndex = 3;
            this.AboutTab.Text = " About / Support ";
            this.AboutTab.UseVisualStyleBackColor = true;
            // 
            // SupportGB
            // 
            this.SupportGB.Controls.Add(this.SupportLabel);
            this.SupportGB.Controls.Add(this.OffDocButton);
            this.SupportGB.Controls.Add(this.HelpLabel);
            this.SupportGB.Location = new System.Drawing.Point(290, 219);
            this.SupportGB.Name = "SupportGB";
            this.SupportGB.Size = new System.Drawing.Size(308, 71);
            this.SupportGB.TabIndex = 4;
            this.SupportGB.TabStop = false;
            // 
            // SupportLabel
            // 
            this.SupportLabel.AutoSize = true;
            this.SupportLabel.BackColor = System.Drawing.Color.White;
            this.SupportLabel.Location = new System.Drawing.Point(124, 0);
            this.SupportLabel.Name = "SupportLabel";
            this.SupportLabel.Size = new System.Drawing.Size(58, 16);
            this.SupportLabel.TabIndex = 5;
            this.SupportLabel.Text = "Support";
            // 
            // OffDocButton
            // 
            this.OffDocButton.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.OffDocButton.Location = new System.Drawing.Point(66, 31);
            this.OffDocButton.Name = "OffDocButton";
            this.OffDocButton.Size = new System.Drawing.Size(219, 25);
            this.OffDocButton.TabIndex = 3;
            this.OffDocButton.Text = "Official documentation";
            this.OffDocButton.UseVisualStyleBackColor = true;
            this.OffDocButton.Click += new System.EventHandler(this.OffDoc_Click);
            // 
            // HelpLabel
            // 
            this.HelpLabel.AutoSize = true;
            this.HelpLabel.Location = new System.Drawing.Point(20, 34);
            this.HelpLabel.Name = "HelpLabel";
            this.HelpLabel.Size = new System.Drawing.Size(40, 16);
            this.HelpLabel.TabIndex = 2;
            this.HelpLabel.Text = "Help:";
            // 
            // AboutAuthGB
            // 
            this.AboutAuthGB.Controls.Add(this.TwitterLogo);
            this.AboutAuthGB.Controls.Add(this.InstagramLogo);
            this.AboutAuthGB.Controls.Add(this.YoutubeLogo);
            this.AboutAuthGB.Controls.Add(this.AboutAuthDesc);
            this.AboutAuthGB.Controls.Add(this.AbAuthorLabel);
            this.AboutAuthGB.Controls.Add(this.AboutAuthLabel);
            this.AboutAuthGB.Location = new System.Drawing.Point(290, 7);
            this.AboutAuthGB.Name = "AboutAuthGB";
            this.AboutAuthGB.Size = new System.Drawing.Size(308, 213);
            this.AboutAuthGB.TabIndex = 1;
            this.AboutAuthGB.TabStop = false;
            // 
            // TwitterLogo
            // 
            this.TwitterLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.TwitterLogo.Image = ((System.Drawing.Image)(resources.GetObject("TwitterLogo.Image")));
            this.TwitterLogo.Location = new System.Drawing.Point(210, 150);
            this.TwitterLogo.Margin = new System.Windows.Forms.Padding(4);
            this.TwitterLogo.Name = "TwitterLogo";
            this.TwitterLogo.Size = new System.Drawing.Size(68, 53);
            this.TwitterLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.TwitterLogo.TabIndex = 8;
            this.TwitterLogo.TabStop = false;
            this.TwitterLogo.Click += new System.EventHandler(this.TwitterLogo_Click);
            // 
            // InstagramLogo
            // 
            this.InstagramLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.InstagramLogo.Image = ((System.Drawing.Image)(resources.GetObject("InstagramLogo.Image")));
            this.InstagramLogo.Location = new System.Drawing.Point(35, 150);
            this.InstagramLogo.Margin = new System.Windows.Forms.Padding(4);
            this.InstagramLogo.Name = "InstagramLogo";
            this.InstagramLogo.Size = new System.Drawing.Size(60, 53);
            this.InstagramLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.InstagramLogo.TabIndex = 7;
            this.InstagramLogo.TabStop = false;
            this.InstagramLogo.Click += new System.EventHandler(this.InstagramLogo_Click);
            // 
            // YoutubeLogo
            // 
            this.YoutubeLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.YoutubeLogo.Image = ((System.Drawing.Image)(resources.GetObject("YoutubeLogo.Image")));
            this.YoutubeLogo.Location = new System.Drawing.Point(117, 154);
            this.YoutubeLogo.Margin = new System.Windows.Forms.Padding(4);
            this.YoutubeLogo.Name = "YoutubeLogo";
            this.YoutubeLogo.Size = new System.Drawing.Size(72, 43);
            this.YoutubeLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.YoutubeLogo.TabIndex = 6;
            this.YoutubeLogo.TabStop = false;
            this.YoutubeLogo.Click += new System.EventHandler(this.YoutubeLogo_Click);
            // 
            // AboutAuthDesc
            // 
            this.AboutAuthDesc.AutoSize = true;
            this.AboutAuthDesc.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AboutAuthDesc.Location = new System.Drawing.Point(46, 31);
            this.AboutAuthDesc.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AboutAuthDesc.Name = "AboutAuthDesc";
            this.AboutAuthDesc.Size = new System.Drawing.Size(246, 96);
            this.AboutAuthDesc.TabIndex = 5;
            this.AboutAuthDesc.Text = "The creator behind FrameGUI is \r\nDaGoose. Help support DaGoose\r\nto encourage futu" +
    "re development\r\nof FrameGUI and other tools by \r\nfollowing his social media page" +
    "s \r\nbelow (click one):";
            this.AboutAuthDesc.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // AbAuthorLabel
            // 
            this.AbAuthorLabel.AutoSize = true;
            this.AbAuthorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AbAuthorLabel.Location = new System.Drawing.Point(16, 29);
            this.AbAuthorLabel.Name = "AbAuthorLabel";
            this.AbAuthorLabel.Size = new System.Drawing.Size(0, 18);
            this.AbAuthorLabel.TabIndex = 1;
            this.AbAuthorLabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // AboutAuthLabel
            // 
            this.AboutAuthLabel.AutoSize = true;
            this.AboutAuthLabel.BackColor = System.Drawing.Color.White;
            this.AboutAuthLabel.Location = new System.Drawing.Point(133, 0);
            this.AboutAuthLabel.Name = "AboutAuthLabel";
            this.AboutAuthLabel.Size = new System.Drawing.Size(50, 16);
            this.AboutAuthLabel.TabIndex = 0;
            this.AboutAuthLabel.Text = "Author";
            // 
            // AboutGUIGB
            // 
            this.AboutGUIGB.Controls.Add(this.VideoLinkEN);
            this.AboutGUIGB.Controls.Add(this.AboutGUIDesc);
            this.AboutGUIGB.Controls.Add(this.AbGUILabel);
            this.AboutGUIGB.Controls.Add(this.AboutGUILabel);
            this.AboutGUIGB.Location = new System.Drawing.Point(3, 7);
            this.AboutGUIGB.Name = "AboutGUIGB";
            this.AboutGUIGB.Size = new System.Drawing.Size(281, 283);
            this.AboutGUIGB.TabIndex = 0;
            this.AboutGUIGB.TabStop = false;
            // 
            // VideoLinkEN
            // 
            this.VideoLinkEN.AutoSize = true;
            this.VideoLinkEN.Location = new System.Drawing.Point(47, 243);
            this.VideoLinkEN.Name = "VideoLinkEN";
            this.VideoLinkEN.Size = new System.Drawing.Size(174, 16);
            this.VideoLinkEN.TabIndex = 39;
            this.VideoLinkEN.TabStop = true;
            this.VideoLinkEN.Text = "Official Tutorial Video (EN)";
            this.VideoLinkEN.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.VideoLinkEN_LinkClicked);
            // 
            // AboutGUIDesc
            // 
            this.AboutGUIDesc.AutoSize = true;
            this.AboutGUIDesc.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AboutGUIDesc.Location = new System.Drawing.Point(24, 43);
            this.AboutGUIDesc.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AboutGUIDesc.Name = "AboutGUIDesc";
            this.AboutGUIDesc.Size = new System.Drawing.Size(253, 160);
            this.AboutGUIDesc.TabIndex = 3;
            this.AboutGUIDesc.Text = resources.GetString("AboutGUIDesc.Text");
            this.AboutGUIDesc.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // AbGUILabel
            // 
            this.AbGUILabel.AutoSize = true;
            this.AbGUILabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AbGUILabel.Location = new System.Drawing.Point(6, 29);
            this.AbGUILabel.Name = "AbGUILabel";
            this.AbGUILabel.Size = new System.Drawing.Size(0, 18);
            this.AbGUILabel.TabIndex = 2;
            this.AbGUILabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // AboutGUILabel
            // 
            this.AboutGUILabel.AutoSize = true;
            this.AboutGUILabel.BackColor = System.Drawing.Color.White;
            this.AboutGUILabel.Location = new System.Drawing.Point(84, 0);
            this.AboutGUILabel.Name = "AboutGUILabel";
            this.AboutGUILabel.Size = new System.Drawing.Size(113, 16);
            this.AboutGUILabel.TabIndex = 0;
            this.AboutGUILabel.Text = "About FrameGUI";
            // 
            // MainTab
            // 
            this.MainTab.Controls.Add(this.FGUIGB);
            this.MainTab.Controls.Add(this.CancelBttn);
            this.MainTab.Controls.Add(this.FrameGUILogo);
            this.MainTab.Controls.Add(this.StartEncodeBttn);
            this.MainTab.Controls.Add(this.SetInputBttn);
            this.MainTab.Controls.Add(this.InTxtBox);
            this.MainTab.Location = new System.Drawing.Point(4, 25);
            this.MainTab.Name = "MainTab";
            this.MainTab.Padding = new System.Windows.Forms.Padding(3);
            this.MainTab.Size = new System.Drawing.Size(604, 293);
            this.MainTab.TabIndex = 0;
            this.MainTab.Text = " Main ";
            this.MainTab.UseVisualStyleBackColor = true;
            // 
            // FGUIGB
            // 
            this.FGUIGB.Controls.Add(this.FGUILabel);
            this.FGUIGB.Controls.Add(this.FGUIDD);
            this.FGUIGB.Controls.Add(this.ModeLabel);
            this.FGUIGB.Location = new System.Drawing.Point(324, 66);
            this.FGUIGB.Name = "FGUIGB";
            this.FGUIGB.Size = new System.Drawing.Size(231, 68);
            this.FGUIGB.TabIndex = 8;
            this.FGUIGB.TabStop = false;
            // 
            // FGUILabel
            // 
            this.FGUILabel.AutoSize = true;
            this.FGUILabel.BackColor = System.Drawing.Color.White;
            this.FGUILabel.Location = new System.Drawing.Point(79, 0);
            this.FGUILabel.Name = "FGUILabel";
            this.FGUILabel.Size = new System.Drawing.Size(72, 16);
            this.FGUILabel.TabIndex = 9;
            this.FGUILabel.Text = "FrameGUI";
            // 
            // FGUIDD
            // 
            this.FGUIDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.FGUIDD.FormattingEnabled = true;
            this.FGUIDD.Items.AddRange(new object[] {
            "Normal",
            "One-click"});
            this.FGUIDD.Location = new System.Drawing.Point(90, 27);
            this.FGUIDD.Name = "FGUIDD";
            this.FGUIDD.Size = new System.Drawing.Size(106, 24);
            this.FGUIDD.TabIndex = 7;
            this.FGUIDD.SelectedIndexChanged += new System.EventHandler(this.FGUIDD_SelectedIndexChanged);
            // 
            // ModeLabel
            // 
            this.ModeLabel.AutoSize = true;
            this.ModeLabel.Location = new System.Drawing.Point(38, 30);
            this.ModeLabel.Name = "ModeLabel";
            this.ModeLabel.Size = new System.Drawing.Size(47, 16);
            this.ModeLabel.TabIndex = 6;
            this.ModeLabel.Text = "Mode:";
            // 
            // CancelBttn
            // 
            this.CancelBttn.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CancelBttn.ForeColor = System.Drawing.Color.Red;
            this.CancelBttn.Location = new System.Drawing.Point(324, 215);
            this.CancelBttn.Name = "CancelBttn";
            this.CancelBttn.Size = new System.Drawing.Size(231, 28);
            this.CancelBttn.TabIndex = 3;
            this.CancelBttn.Text = "Cancel";
            this.CancelBttn.UseVisualStyleBackColor = true;
            this.CancelBttn.Visible = false;
            this.CancelBttn.Click += new System.EventHandler(this.CancelClick);
            // 
            // FrameGUILogo
            // 
            this.FrameGUILogo.ErrorImage = null;
            this.FrameGUILogo.Image = ((System.Drawing.Image)(resources.GetObject("FrameGUILogo.Image")));
            this.FrameGUILogo.Location = new System.Drawing.Point(26, 54);
            this.FrameGUILogo.Name = "FrameGUILogo";
            this.FrameGUILogo.Size = new System.Drawing.Size(271, 204);
            this.FrameGUILogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.FrameGUILogo.TabIndex = 5;
            this.FrameGUILogo.TabStop = false;
            // 
            // SetInputBttn
            // 
            this.SetInputBttn.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.SetInputBttn.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SetInputBttn.Location = new System.Drawing.Point(487, 7);
            this.SetInputBttn.Name = "SetInputBttn";
            this.SetInputBttn.Size = new System.Drawing.Size(111, 24);
            this.SetInputBttn.TabIndex = 0;
            this.SetInputBttn.Text = "Select Input";
            this.SetInputBttn.UseVisualStyleBackColor = true;
            this.SetInputBttn.Click += new System.EventHandler(this.SetInputBttn_Click);
            // 
            // InTxtBox
            // 
            this.InTxtBox.Enabled = false;
            this.InTxtBox.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.InTxtBox.Location = new System.Drawing.Point(7, 8);
            this.InTxtBox.Name = "InTxtBox";
            this.InTxtBox.Size = new System.Drawing.Size(474, 22);
            this.InTxtBox.TabIndex = 0;
            this.InTxtBox.TabStop = false;
            // 
            // Tabs
            // 
            this.Tabs.Controls.Add(this.MainTab);
            this.Tabs.Controls.Add(this.SettingsTab);
            this.Tabs.Controls.Add(this.AboutTab);
            this.Tabs.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Tabs.Location = new System.Drawing.Point(10, 3);
            this.Tabs.Name = "Tabs";
            this.Tabs.SelectedIndex = 0;
            this.Tabs.Size = new System.Drawing.Size(612, 322);
            this.Tabs.TabIndex = 38;
            this.Tabs.TabStop = false;
            // 
            // SettingsTab
            // 
            this.SettingsTab.Controls.Add(this.SettingsTabs);
            this.SettingsTab.Location = new System.Drawing.Point(4, 25);
            this.SettingsTab.Name = "SettingsTab";
            this.SettingsTab.Padding = new System.Windows.Forms.Padding(3);
            this.SettingsTab.Size = new System.Drawing.Size(604, 293);
            this.SettingsTab.TabIndex = 4;
            this.SettingsTab.Text = " Encoder Settings ";
            this.SettingsTab.UseVisualStyleBackColor = true;
            // 
            // SettingsTabs
            // 
            this.SettingsTabs.Controls.Add(this.VideoTab);
            this.SettingsTabs.Controls.Add(this.AudioTab);
            this.SettingsTabs.Controls.Add(this.ScriptOtherTab);
            this.SettingsTabs.Location = new System.Drawing.Point(3, 3);
            this.SettingsTabs.Name = "SettingsTabs";
            this.SettingsTabs.SelectedIndex = 0;
            this.SettingsTabs.Size = new System.Drawing.Size(597, 286);
            this.SettingsTabs.TabIndex = 20;
            this.SettingsTabs.TabStop = false;
            // 
            // VideoTab
            // 
            this.VideoTab.Controls.Add(this.SizeGB);
            this.VideoTab.Controls.Add(this.EncodeGB);
            this.VideoTab.Location = new System.Drawing.Point(4, 25);
            this.VideoTab.Name = "VideoTab";
            this.VideoTab.Padding = new System.Windows.Forms.Padding(3);
            this.VideoTab.Size = new System.Drawing.Size(589, 257);
            this.VideoTab.TabIndex = 0;
            this.VideoTab.Text = " Video (x264) ";
            this.VideoTab.UseVisualStyleBackColor = true;
            // 
            // SizeGB
            // 
            this.SizeGB.Controls.Add(this.ResizeAlgoDD);
            this.SizeGB.Controls.Add(this.ResizeAlgoLabel);
            this.SizeGB.Controls.Add(this.WidthResNUD);
            this.SizeGB.Controls.Add(this.WidthLabel);
            this.SizeGB.Controls.Add(this.HeightResNUD);
            this.SizeGB.Controls.Add(this.VidHeightLebel);
            this.SizeGB.Controls.Add(this.ChangeResCB);
            this.SizeGB.Controls.Add(this.SizeLabel);
            this.SizeGB.Location = new System.Drawing.Point(412, 3);
            this.SizeGB.Name = "SizeGB";
            this.SizeGB.Size = new System.Drawing.Size(171, 250);
            this.SizeGB.TabIndex = 5;
            this.SizeGB.TabStop = false;
            // 
            // ResizeAlgoDD
            // 
            this.ResizeAlgoDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ResizeAlgoDD.Enabled = false;
            this.ResizeAlgoDD.FormattingEnabled = true;
            this.ResizeAlgoDD.Items.AddRange(new object[] {
            "None",
            "Bilinear",
            "Bicubic",
            "Experimental",
            "Neighbor",
            "Area",
            "Bicublin",
            "Gauss",
            "Sinc",
            "Lanczos",
            "Spline"});
            this.ResizeAlgoDD.Location = new System.Drawing.Point(24, 198);
            this.ResizeAlgoDD.Name = "ResizeAlgoDD";
            this.ResizeAlgoDD.Size = new System.Drawing.Size(123, 24);
            this.ResizeAlgoDD.TabIndex = 13;
            // 
            // ResizeAlgoLabel
            // 
            this.ResizeAlgoLabel.AutoSize = true;
            this.ResizeAlgoLabel.Location = new System.Drawing.Point(44, 168);
            this.ResizeAlgoLabel.Name = "ResizeAlgoLabel";
            this.ResizeAlgoLabel.Size = new System.Drawing.Size(85, 16);
            this.ResizeAlgoLabel.TabIndex = 6;
            this.ResizeAlgoLabel.Text = "Resize algo:";
            // 
            // WidthResNUD
            // 
            this.WidthResNUD.Enabled = false;
            this.WidthResNUD.Location = new System.Drawing.Point(79, 124);
            this.WidthResNUD.Maximum = new decimal(new int[] {
            3840,
            0,
            0,
            0});
            this.WidthResNUD.Name = "WidthResNUD";
            this.WidthResNUD.Size = new System.Drawing.Size(68, 22);
            this.WidthResNUD.TabIndex = 12;
            // 
            // WidthLabel
            // 
            this.WidthLabel.AutoSize = true;
            this.WidthLabel.Location = new System.Drawing.Point(21, 127);
            this.WidthLabel.Name = "WidthLabel";
            this.WidthLabel.Size = new System.Drawing.Size(48, 16);
            this.WidthLabel.TabIndex = 4;
            this.WidthLabel.Text = "Width:";
            // 
            // HeightResNUD
            // 
            this.HeightResNUD.Enabled = false;
            this.HeightResNUD.Location = new System.Drawing.Point(79, 79);
            this.HeightResNUD.Maximum = new decimal(new int[] {
            2160,
            0,
            0,
            0});
            this.HeightResNUD.Name = "HeightResNUD";
            this.HeightResNUD.Size = new System.Drawing.Size(68, 22);
            this.HeightResNUD.TabIndex = 11;
            // 
            // VidHeightLebel
            // 
            this.VidHeightLebel.AutoSize = true;
            this.VidHeightLebel.Location = new System.Drawing.Point(21, 81);
            this.VidHeightLebel.Name = "VidHeightLebel";
            this.VidHeightLebel.Size = new System.Drawing.Size(52, 16);
            this.VidHeightLebel.TabIndex = 2;
            this.VidHeightLebel.Text = "Height:";
            // 
            // ChangeResCB
            // 
            this.ChangeResCB.AutoSize = true;
            this.ChangeResCB.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ChangeResCB.Location = new System.Drawing.Point(47, 39);
            this.ChangeResCB.Name = "ChangeResCB";
            this.ChangeResCB.Size = new System.Drawing.Size(80, 20);
            this.ChangeResCB.TabIndex = 10;
            this.ChangeResCB.Text = "Change";
            this.ChangeResCB.UseVisualStyleBackColor = true;
            this.ChangeResCB.CheckedChanged += new System.EventHandler(this.ChangeResCB_CheckedChanged);
            // 
            // SizeLabel
            // 
            this.SizeLabel.AutoSize = true;
            this.SizeLabel.BackColor = System.Drawing.Color.White;
            this.SizeLabel.Location = new System.Drawing.Point(68, 0);
            this.SizeLabel.Name = "SizeLabel";
            this.SizeLabel.Size = new System.Drawing.Size(34, 16);
            this.SizeLabel.TabIndex = 0;
            this.SizeLabel.Text = "Size";
            // 
            // EncodeGB
            // 
            this.EncodeGB.Controls.Add(this.ColorsGB);
            this.EncodeGB.Controls.Add(this.FrameGB);
            this.EncodeGB.Controls.Add(this.ModeGB);
            this.EncodeGB.Controls.Add(this.UseCB2);
            this.EncodeGB.Controls.Add(this.TuneDD);
            this.EncodeGB.Controls.Add(this.TuneLabel);
            this.EncodeGB.Controls.Add(this.EncodeModeDD);
            this.EncodeGB.Controls.Add(this.EncodeModeLabel);
            this.EncodeGB.Controls.Add(this.CPUPDD);
            this.EncodeGB.Controls.Add(this.CPUPreLabel);
            this.EncodeGB.Controls.Add(this.EncodeLabel);
            this.EncodeGB.Location = new System.Drawing.Point(3, 3);
            this.EncodeGB.Name = "EncodeGB";
            this.EncodeGB.Size = new System.Drawing.Size(403, 250);
            this.EncodeGB.TabIndex = 3;
            this.EncodeGB.TabStop = false;
            // 
            // ColorsGB
            // 
            this.ColorsGB.Controls.Add(this.SharpenValNUD);
            this.ColorsGB.Controls.Add(this.SharpenCB);
            this.ColorsGB.Controls.Add(this.ColorsDD);
            this.ColorsGB.Controls.Add(this.ColorsLabel);
            this.ColorsGB.Location = new System.Drawing.Point(7, 127);
            this.ColorsGB.Name = "ColorsGB";
            this.ColorsGB.Size = new System.Drawing.Size(163, 116);
            this.ColorsGB.TabIndex = 2;
            this.ColorsGB.TabStop = false;
            // 
            // SharpenValNUD
            // 
            this.SharpenValNUD.DecimalPlaces = 1;
            this.SharpenValNUD.Location = new System.Drawing.Point(101, 73);
            this.SharpenValNUD.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.SharpenValNUD.Name = "SharpenValNUD";
            this.SharpenValNUD.Size = new System.Drawing.Size(49, 22);
            this.SharpenValNUD.TabIndex = 4;
            // 
            // SharpenCB
            // 
            this.SharpenCB.AutoSize = true;
            this.SharpenCB.Location = new System.Drawing.Point(10, 74);
            this.SharpenCB.Name = "SharpenCB";
            this.SharpenCB.Size = new System.Drawing.Size(88, 20);
            this.SharpenCB.TabIndex = 3;
            this.SharpenCB.Text = "Sharpen:";
            this.SharpenCB.UseVisualStyleBackColor = true;
            this.SharpenCB.CheckedChanged += new System.EventHandler(this.SharpenCB_CheckedChanged);
            // 
            // ColorsDD
            // 
            this.ColorsDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ColorsDD.FormattingEnabled = true;
            this.ColorsDD.Items.AddRange(new object[] {
            "4:2:0 8-bit"});
            this.ColorsDD.Location = new System.Drawing.Point(26, 33);
            this.ColorsDD.Name = "ColorsDD";
            this.ColorsDD.Size = new System.Drawing.Size(112, 24);
            this.ColorsDD.TabIndex = 5;
            this.ColorsDD.TabStop = false;
            // 
            // ColorsLabel
            // 
            this.ColorsLabel.AutoSize = true;
            this.ColorsLabel.BackColor = System.Drawing.Color.White;
            this.ColorsLabel.Location = new System.Drawing.Point(58, 2);
            this.ColorsLabel.Name = "ColorsLabel";
            this.ColorsLabel.Size = new System.Drawing.Size(49, 16);
            this.ColorsLabel.TabIndex = 0;
            this.ColorsLabel.Text = "Colors";
            // 
            // FrameGB
            // 
            this.FrameGB.Controls.Add(this.FrameLabel);
            this.FrameGB.Controls.Add(this.FRLabel);
            this.FrameGB.Controls.Add(this.FrameRNUD);
            this.FrameGB.Controls.Add(this.bframeLabel);
            this.FrameGB.Controls.Add(this.BframeValue);
            this.FrameGB.Location = new System.Drawing.Point(7, 10);
            this.FrameGB.Name = "FrameGB";
            this.FrameGB.Size = new System.Drawing.Size(146, 116);
            this.FrameGB.TabIndex = 1;
            this.FrameGB.TabStop = false;
            // 
            // FrameLabel
            // 
            this.FrameLabel.AutoSize = true;
            this.FrameLabel.BackColor = System.Drawing.Color.White;
            this.FrameLabel.Location = new System.Drawing.Point(53, 0);
            this.FrameLabel.Name = "FrameLabel";
            this.FrameLabel.Size = new System.Drawing.Size(49, 16);
            this.FrameLabel.TabIndex = 18;
            this.FrameLabel.Text = "Frame";
            // 
            // FRLabel
            // 
            this.FRLabel.AutoSize = true;
            this.FRLabel.Location = new System.Drawing.Point(7, 31);
            this.FRLabel.Name = "FRLabel";
            this.FRLabel.Size = new System.Drawing.Size(78, 16);
            this.FRLabel.TabIndex = 16;
            this.FRLabel.Text = "Framerate:";
            // 
            // FrameRNUD
            // 
            this.FrameRNUD.Location = new System.Drawing.Point(88, 29);
            this.FrameRNUD.Maximum = new decimal(new int[] {
            240,
            0,
            0,
            0});
            this.FrameRNUD.Name = "FrameRNUD";
            this.FrameRNUD.Size = new System.Drawing.Size(50, 22);
            this.FrameRNUD.TabIndex = 1;
            // 
            // bframeLabel
            // 
            this.bframeLabel.AutoSize = true;
            this.bframeLabel.Location = new System.Drawing.Point(11, 75);
            this.bframeLabel.Name = "bframeLabel";
            this.bframeLabel.Size = new System.Drawing.Size(69, 16);
            this.bframeLabel.TabIndex = 7;
            this.bframeLabel.Text = "B-frames:";
            // 
            // BframeValue
            // 
            this.BframeValue.Location = new System.Drawing.Point(84, 73);
            this.BframeValue.Maximum = new decimal(new int[] {
            14,
            0,
            0,
            0});
            this.BframeValue.Name = "BframeValue";
            this.BframeValue.Size = new System.Drawing.Size(50, 22);
            this.BframeValue.TabIndex = 2;
            this.BframeValue.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // ModeGB
            // 
            this.ModeGB.Controls.Add(this.crfNUD);
            this.ModeGB.Controls.Add(this.crfValueLabel);
            this.ModeGB.Controls.Add(this.EModeSettingLabel);
            this.ModeGB.Controls.Add(this.BitrateValue);
            this.ModeGB.Controls.Add(this.BitrateLabel);
            this.ModeGB.Location = new System.Drawing.Point(159, 67);
            this.ModeGB.Name = "ModeGB";
            this.ModeGB.Size = new System.Drawing.Size(238, 59);
            this.ModeGB.TabIndex = 4;
            this.ModeGB.TabStop = false;
            // 
            // crfNUD
            // 
            this.crfNUD.Location = new System.Drawing.Point(128, 24);
            this.crfNUD.Maximum = new decimal(new int[] {
            51,
            0,
            0,
            0});
            this.crfNUD.Name = "crfNUD";
            this.crfNUD.Size = new System.Drawing.Size(46, 22);
            this.crfNUD.TabIndex = 9;
            this.crfNUD.Value = new decimal(new int[] {
            9,
            0,
            0,
            0});
            // 
            // crfValueLabel
            // 
            this.crfValueLabel.AutoSize = true;
            this.crfValueLabel.Location = new System.Drawing.Point(46, 25);
            this.crfValueLabel.Name = "crfValueLabel";
            this.crfValueLabel.Size = new System.Drawing.Size(79, 16);
            this.crfValueLabel.TabIndex = 9;
            this.crfValueLabel.Text = "CRF value:";
            // 
            // EModeSettingLabel
            // 
            this.EModeSettingLabel.AutoSize = true;
            this.EModeSettingLabel.BackColor = System.Drawing.Color.White;
            this.EModeSettingLabel.Location = new System.Drawing.Point(39, 0);
            this.EModeSettingLabel.Name = "EModeSettingLabel";
            this.EModeSettingLabel.Size = new System.Drawing.Size(161, 16);
            this.EModeSettingLabel.TabIndex = 9;
            this.EModeSettingLabel.Text = "Encoding Mode Settings";
            // 
            // BitrateValue
            // 
            this.BitrateValue.Location = new System.Drawing.Point(134, 24);
            this.BitrateValue.Maximum = new decimal(new int[] {
            80000,
            0,
            0,
            0});
            this.BitrateValue.Name = "BitrateValue";
            this.BitrateValue.Size = new System.Drawing.Size(61, 22);
            this.BitrateValue.TabIndex = 9;
            this.BitrateValue.Value = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.BitrateValue.Visible = false;
            // 
            // BitrateLabel
            // 
            this.BitrateLabel.AutoSize = true;
            this.BitrateLabel.Location = new System.Drawing.Point(38, 25);
            this.BitrateLabel.Name = "BitrateLabel";
            this.BitrateLabel.Size = new System.Drawing.Size(93, 16);
            this.BitrateLabel.TabIndex = 9;
            this.BitrateLabel.Text = "Bitrate (kb/s):";
            this.BitrateLabel.Visible = false;
            // 
            // UseCB2
            // 
            this.UseCB2.AutoSize = true;
            this.UseCB2.Location = new System.Drawing.Point(339, 152);
            this.UseCB2.Name = "UseCB2";
            this.UseCB2.Size = new System.Drawing.Size(54, 20);
            this.UseCB2.TabIndex = 6;
            this.UseCB2.Text = "Use";
            this.UseCB2.UseVisualStyleBackColor = true;
            this.UseCB2.CheckedChanged += new System.EventHandler(this.UseCB2_CheckedChanged);
            // 
            // TuneDD
            // 
            this.TuneDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.TuneDD.Enabled = false;
            this.TuneDD.FormattingEnabled = true;
            this.TuneDD.Items.AddRange(new object[] {
            "none",
            "film",
            "animation",
            "grain",
            "stillimage",
            "fastdecode",
            "zerolatency",
            "psnr",
            "ssim"});
            this.TuneDD.Location = new System.Drawing.Point(227, 149);
            this.TuneDD.Name = "TuneDD";
            this.TuneDD.Size = new System.Drawing.Size(106, 24);
            this.TuneDD.TabIndex = 7;
            // 
            // TuneLabel
            // 
            this.TuneLabel.AutoSize = true;
            this.TuneLabel.Location = new System.Drawing.Point(179, 152);
            this.TuneLabel.Name = "TuneLabel";
            this.TuneLabel.Size = new System.Drawing.Size(44, 16);
            this.TuneLabel.TabIndex = 12;
            this.TuneLabel.Text = "Tune:";
            // 
            // EncodeModeDD
            // 
            this.EncodeModeDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.EncodeModeDD.FormattingEnabled = true;
            this.EncodeModeDD.ItemHeight = 16;
            this.EncodeModeDD.Items.AddRange(new object[] {
            "Constant Rate Factor (CRF)",
            "1 Pass Average Bit Rate"});
            this.EncodeModeDD.Location = new System.Drawing.Point(213, 30);
            this.EncodeModeDD.Name = "EncodeModeDD";
            this.EncodeModeDD.Size = new System.Drawing.Size(178, 24);
            this.EncodeModeDD.TabIndex = 3;
            this.EncodeModeDD.SelectedIndexChanged += new System.EventHandler(this.EncodeModeDD_SelectedIndexChanged);
            // 
            // EncodeModeLabel
            // 
            this.EncodeModeLabel.AutoSize = true;
            this.EncodeModeLabel.Location = new System.Drawing.Point(164, 32);
            this.EncodeModeLabel.Name = "EncodeModeLabel";
            this.EncodeModeLabel.Size = new System.Drawing.Size(47, 16);
            this.EncodeModeLabel.TabIndex = 5;
            this.EncodeModeLabel.Text = "Mode:";
            // 
            // CPUPDD
            // 
            this.CPUPDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.CPUPDD.FormattingEnabled = true;
            this.CPUPDD.Items.AddRange(new object[] {
            "ultrafast",
            "superfast",
            "veryfast",
            "faster",
            "fast",
            "medium",
            "slow",
            "slower",
            "veryslow",
            "placebo"});
            this.CPUPDD.Location = new System.Drawing.Point(268, 201);
            this.CPUPDD.Name = "CPUPDD";
            this.CPUPDD.Size = new System.Drawing.Size(117, 24);
            this.CPUPDD.TabIndex = 8;
            // 
            // CPUPreLabel
            // 
            this.CPUPreLabel.AutoSize = true;
            this.CPUPreLabel.Location = new System.Drawing.Point(180, 204);
            this.CPUPreLabel.Name = "CPUPreLabel";
            this.CPUPreLabel.Size = new System.Drawing.Size(85, 16);
            this.CPUPreLabel.TabIndex = 3;
            this.CPUPreLabel.Text = "CPU Preset:";
            // 
            // EncodeLabel
            // 
            this.EncodeLabel.AutoSize = true;
            this.EncodeLabel.BackColor = System.Drawing.Color.White;
            this.EncodeLabel.Location = new System.Drawing.Point(161, 0);
            this.EncodeLabel.Name = "EncodeLabel";
            this.EncodeLabel.Size = new System.Drawing.Size(67, 16);
            this.EncodeLabel.TabIndex = 0;
            this.EncodeLabel.Text = "Encoding";
            // 
            // AudioTab
            // 
            this.AudioTab.Controls.Add(this.AudioSetGB);
            this.AudioTab.Location = new System.Drawing.Point(4, 25);
            this.AudioTab.Name = "AudioTab";
            this.AudioTab.Padding = new System.Windows.Forms.Padding(3);
            this.AudioTab.Size = new System.Drawing.Size(589, 257);
            this.AudioTab.TabIndex = 1;
            this.AudioTab.Text = " Audio ";
            this.AudioTab.UseVisualStyleBackColor = true;
            // 
            // AudioSetGB
            // 
            this.AudioSetGB.Controls.Add(this.MuteAudCB);
            this.AudioSetGB.Controls.Add(this.SRDD);
            this.AudioSetGB.Controls.Add(this.AudNote);
            this.AudioSetGB.Controls.Add(this.AudioSRLabel);
            this.AudioSetGB.Controls.Add(this.AudioBitLabel);
            this.AudioSetGB.Controls.Add(this.AudBitrateDD);
            this.AudioSetGB.Controls.Add(this.AudioSetLabel);
            this.AudioSetGB.Controls.Add(this.AudFormatLabel);
            this.AudioSetGB.Controls.Add(this.AudFormatDD);
            this.AudioSetGB.Location = new System.Drawing.Point(3, 3);
            this.AudioSetGB.Name = "AudioSetGB";
            this.AudioSetGB.Size = new System.Drawing.Size(580, 250);
            this.AudioSetGB.TabIndex = 0;
            this.AudioSetGB.TabStop = false;
            // 
            // MuteAudCB
            // 
            this.MuteAudCB.AutoSize = true;
            this.MuteAudCB.Location = new System.Drawing.Point(350, 156);
            this.MuteAudCB.Name = "MuteAudCB";
            this.MuteAudCB.Size = new System.Drawing.Size(100, 20);
            this.MuteAudCB.TabIndex = 7;
            this.MuteAudCB.Text = "Mute audio";
            this.MuteAudCB.UseVisualStyleBackColor = true;
            this.MuteAudCB.CheckedChanged += new System.EventHandler(this.MuteAudCB_CheckedChanged);
            // 
            // SRDD
            // 
            this.SRDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.SRDD.FormattingEnabled = true;
            this.SRDD.Items.AddRange(new object[] {
            "48000"});
            this.SRDD.Location = new System.Drawing.Point(260, 153);
            this.SRDD.Name = "SRDD";
            this.SRDD.Size = new System.Drawing.Size(74, 24);
            this.SRDD.TabIndex = 3;
            // 
            // AudNote
            // 
            this.AudNote.AutoSize = true;
            this.AudNote.Location = new System.Drawing.Point(35, 216);
            this.AudNote.Name = "AudNote";
            this.AudNote.Size = new System.Drawing.Size(506, 16);
            this.AudNote.TabIndex = 3;
            this.AudNote.Text = "Note: Any settings set here will only apply to the FIRST audio track in the video" +
    ".";
            // 
            // AudioSRLabel
            // 
            this.AudioSRLabel.AutoSize = true;
            this.AudioSRLabel.Location = new System.Drawing.Point(133, 156);
            this.AudioSRLabel.Name = "AudioSRLabel";
            this.AudioSRLabel.Size = new System.Drawing.Size(122, 16);
            this.AudioSRLabel.TabIndex = 6;
            this.AudioSRLabel.Text = "Sample Rate (Hz):";
            // 
            // AudioBitLabel
            // 
            this.AudioBitLabel.AutoSize = true;
            this.AudioBitLabel.Location = new System.Drawing.Point(182, 101);
            this.AudioBitLabel.Name = "AudioBitLabel";
            this.AudioBitLabel.Size = new System.Drawing.Size(133, 16);
            this.AudioBitLabel.TabIndex = 4;
            this.AudioBitLabel.Text = "Audio Bitrate (kb/s):";
            // 
            // AudBitrateDD
            // 
            this.AudBitrateDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.AudBitrateDD.FormattingEnabled = true;
            this.AudBitrateDD.Items.AddRange(new object[] {
            "96",
            "112",
            "128",
            "160",
            "192",
            "224",
            "256",
            "320",
            "576"});
            this.AudBitrateDD.Location = new System.Drawing.Point(319, 98);
            this.AudBitrateDD.Name = "AudBitrateDD";
            this.AudBitrateDD.Size = new System.Drawing.Size(74, 24);
            this.AudBitrateDD.TabIndex = 2;
            // 
            // AudioSetLabel
            // 
            this.AudioSetLabel.AutoSize = true;
            this.AudioSetLabel.BackColor = System.Drawing.Color.White;
            this.AudioSetLabel.Location = new System.Drawing.Point(268, 0);
            this.AudioSetLabel.Name = "AudioSetLabel";
            this.AudioSetLabel.Size = new System.Drawing.Size(44, 16);
            this.AudioSetLabel.TabIndex = 0;
            this.AudioSetLabel.Text = "Audio";
            // 
            // AudFormatLabel
            // 
            this.AudFormatLabel.AutoSize = true;
            this.AudFormatLabel.Location = new System.Drawing.Point(195, 44);
            this.AudFormatLabel.Name = "AudFormatLabel";
            this.AudFormatLabel.Size = new System.Drawing.Size(97, 16);
            this.AudFormatLabel.TabIndex = 2;
            this.AudFormatLabel.Text = "Audio Format:";
            // 
            // AudFormatDD
            // 
            this.AudFormatDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.AudFormatDD.FormattingEnabled = true;
            this.AudFormatDD.Items.AddRange(new object[] {
            "aac",
            "mp3"});
            this.AudFormatDD.Location = new System.Drawing.Point(298, 41);
            this.AudFormatDD.Name = "AudFormatDD";
            this.AudFormatDD.Size = new System.Drawing.Size(74, 24);
            this.AudFormatDD.TabIndex = 1;
            // 
            // ScriptOtherTab
            // 
            this.ScriptOtherTab.Controls.Add(this.vsSettingLabel);
            this.ScriptOtherTab.Controls.Add(this.OtherSettingGB);
            this.ScriptOtherTab.Controls.Add(this.SettingsGB);
            this.ScriptOtherTab.Location = new System.Drawing.Point(4, 25);
            this.ScriptOtherTab.Name = "ScriptOtherTab";
            this.ScriptOtherTab.Size = new System.Drawing.Size(589, 257);
            this.ScriptOtherTab.TabIndex = 2;
            this.ScriptOtherTab.Text = " SVPFlow / AviSynth+ / Other ";
            this.ScriptOtherTab.UseVisualStyleBackColor = true;
            // 
            // vsSettingLabel
            // 
            this.vsSettingLabel.Controls.Add(this.MaxMemLabel);
            this.vsSettingLabel.Controls.Add(this.MaxMemNUD);
            this.vsSettingLabel.Controls.Add(this.ThreadsNUD);
            this.vsSettingLabel.Controls.Add(this.ThreadsLabel);
            this.vsSettingLabel.Controls.Add(this.aviLabel);
            this.vsSettingLabel.Location = new System.Drawing.Point(4, 145);
            this.vsSettingLabel.Name = "vsSettingLabel";
            this.vsSettingLabel.Size = new System.Drawing.Size(227, 107);
            this.vsSettingLabel.TabIndex = 2;
            this.vsSettingLabel.TabStop = false;
            // 
            // MaxMemLabel
            // 
            this.MaxMemLabel.AutoSize = true;
            this.MaxMemLabel.Location = new System.Drawing.Point(10, 68);
            this.MaxMemLabel.Name = "MaxMemLabel";
            this.MaxMemLabel.Size = new System.Drawing.Size(129, 16);
            this.MaxMemLabel.TabIndex = 4;
            this.MaxMemLabel.Text = "Max. memory (MB):";
            // 
            // MaxMemNUD
            // 
            this.MaxMemNUD.Enabled = false;
            this.MaxMemNUD.Location = new System.Drawing.Point(146, 66);
            this.MaxMemNUD.Maximum = new decimal(new int[] {
            4096,
            0,
            0,
            0});
            this.MaxMemNUD.Name = "MaxMemNUD";
            this.MaxMemNUD.Size = new System.Drawing.Size(66, 22);
            this.MaxMemNUD.TabIndex = 2;
            // 
            // ThreadsNUD
            // 
            this.ThreadsNUD.Enabled = false;
            this.ThreadsNUD.Location = new System.Drawing.Point(153, 34);
            this.ThreadsNUD.Maximum = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.ThreadsNUD.Name = "ThreadsNUD";
            this.ThreadsNUD.Size = new System.Drawing.Size(50, 22);
            this.ThreadsNUD.TabIndex = 1;
            // 
            // ThreadsLabel
            // 
            this.ThreadsLabel.AutoSize = true;
            this.ThreadsLabel.Location = new System.Drawing.Point(16, 36);
            this.ThreadsLabel.Name = "ThreadsLabel";
            this.ThreadsLabel.Size = new System.Drawing.Size(134, 16);
            this.ThreadsLabel.TabIndex = 1;
            this.ThreadsLabel.Text = "Processing threads:";
            // 
            // aviLabel
            // 
            this.aviLabel.AutoSize = true;
            this.aviLabel.BackColor = System.Drawing.Color.White;
            this.aviLabel.Location = new System.Drawing.Point(79, 0);
            this.aviLabel.Name = "aviLabel";
            this.aviLabel.Size = new System.Drawing.Size(71, 16);
            this.aviLabel.TabIndex = 0;
            this.aviLabel.Text = "AviSynth+";
            // 
            // OtherSettingGB
            // 
            this.OtherSettingGB.Controls.Add(this.LogsBttn);
            this.OtherSettingGB.Controls.Add(this.NotificationCB);
            this.OtherSettingGB.Controls.Add(this.CopyCommandBttn);
            this.OtherSettingGB.Controls.Add(this.SaveSettingBttn);
            this.OtherSettingGB.Controls.Add(this.OtherSettingLabel);
            this.OtherSettingGB.Location = new System.Drawing.Point(237, 145);
            this.OtherSettingGB.Name = "OtherSettingGB";
            this.OtherSettingGB.Size = new System.Drawing.Size(345, 107);
            this.OtherSettingGB.TabIndex = 3;
            this.OtherSettingGB.TabStop = false;
            // 
            // LogsBttn
            // 
            this.LogsBttn.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.LogsBttn.Location = new System.Drawing.Point(18, 52);
            this.LogsBttn.Name = "LogsBttn";
            this.LogsBttn.Size = new System.Drawing.Size(129, 26);
            this.LogsBttn.TabIndex = 4;
            this.LogsBttn.Text = "Open Logs Path";
            this.LogsBttn.UseVisualStyleBackColor = true;
            this.LogsBttn.Click += new System.EventHandler(this.LogsBttn_Click);
            // 
            // NotificationCB
            // 
            this.NotificationCB.AutoSize = true;
            this.NotificationCB.Checked = true;
            this.NotificationCB.CheckState = System.Windows.Forms.CheckState.Checked;
            this.NotificationCB.Location = new System.Drawing.Point(19, 82);
            this.NotificationCB.Name = "NotificationCB";
            this.NotificationCB.Size = new System.Drawing.Size(310, 20);
            this.NotificationCB.TabIndex = 3;
            this.NotificationCB.Text = "Show message box upon encoding complete";
            this.NotificationCB.UseVisualStyleBackColor = true;
            // 
            // CopyCommandBttn
            // 
            this.CopyCommandBttn.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.CopyCommandBttn.Location = new System.Drawing.Point(18, 20);
            this.CopyCommandBttn.Name = "CopyCommandBttn";
            this.CopyCommandBttn.Size = new System.Drawing.Size(311, 26);
            this.CopyCommandBttn.TabIndex = 1;
            this.CopyCommandBttn.Text = "Copy FFMpeg Command to Clipboard";
            this.CopyCommandBttn.UseVisualStyleBackColor = true;
            this.CopyCommandBttn.Click += new System.EventHandler(this.CopyCommandBttn_Click);
            // 
            // SaveSettingBttn
            // 
            this.SaveSettingBttn.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.SaveSettingBttn.Location = new System.Drawing.Point(153, 52);
            this.SaveSettingBttn.Name = "SaveSettingBttn";
            this.SaveSettingBttn.Size = new System.Drawing.Size(176, 26);
            this.SaveSettingBttn.TabIndex = 2;
            this.SaveSettingBttn.Text = "Save Current Settings";
            this.SaveSettingBttn.UseVisualStyleBackColor = true;
            this.SaveSettingBttn.Click += new System.EventHandler(this.SaveSettingBttn_Click);
            // 
            // OtherSettingLabel
            // 
            this.OtherSettingLabel.AutoSize = true;
            this.OtherSettingLabel.BackColor = System.Drawing.Color.White;
            this.OtherSettingLabel.Location = new System.Drawing.Point(123, 0);
            this.OtherSettingLabel.Name = "OtherSettingLabel";
            this.OtherSettingLabel.Size = new System.Drawing.Size(99, 16);
            this.OtherSettingLabel.TabIndex = 0;
            this.OtherSettingLabel.Text = "Other Settings";
            // 
            // SettingsGB
            // 
            this.SettingsGB.Controls.Add(this.FPSLabel);
            this.SettingsGB.Controls.Add(this.ArtefactLabel);
            this.SettingsGB.Controls.Add(this.UseGPUCB);
            this.SettingsGB.Controls.Add(this.IwantDD);
            this.SettingsGB.Controls.Add(this.IwantLabel);
            this.SettingsGB.Controls.Add(this.OutFPSNUD);
            this.SettingsGB.Controls.Add(this.OutFPSLabel);
            this.SettingsGB.Controls.Add(this.InputFPSLabel);
            this.SettingsGB.Controls.Add(this.NoobCB);
            this.SettingsGB.Controls.Add(this.UseCB);
            this.SettingsGB.Controls.Add(this.StuckLink);
            this.SettingsGB.Controls.Add(this.StuckLabel);
            this.SettingsGB.Controls.Add(this.AnalyseTxtBox);
            this.SettingsGB.Controls.Add(this.AnalyseLabel);
            this.SettingsGB.Controls.Add(this.SuperTxtBox);
            this.SettingsGB.Controls.Add(this.SmoothTxtBox);
            this.SettingsGB.Controls.Add(this.SuperLabel);
            this.SettingsGB.Controls.Add(this.SmoothLabel);
            this.SettingsGB.Controls.Add(this.ScriptsLabel);
            this.SettingsGB.Location = new System.Drawing.Point(4, 3);
            this.SettingsGB.Name = "SettingsGB";
            this.SettingsGB.Size = new System.Drawing.Size(578, 139);
            this.SettingsGB.TabIndex = 1;
            this.SettingsGB.TabStop = false;
            // 
            // FPSLabel
            // 
            this.FPSLabel.AutoSize = true;
            this.FPSLabel.ForeColor = System.Drawing.Color.ForestGreen;
            this.FPSLabel.Location = new System.Drawing.Point(148, 38);
            this.FPSLabel.Name = "FPSLabel";
            this.FPSLabel.Size = new System.Drawing.Size(16, 16);
            this.FPSLabel.TabIndex = 20;
            this.FPSLabel.Text = "0";
            this.FPSLabel.Visible = false;
            // 
            // ArtefactLabel
            // 
            this.ArtefactLabel.AutoSize = true;
            this.ArtefactLabel.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ArtefactLabel.ForeColor = System.Drawing.Color.Red;
            this.ArtefactLabel.Location = new System.Drawing.Point(64, 116);
            this.ArtefactLabel.Name = "ArtefactLabel";
            this.ArtefactLabel.Size = new System.Drawing.Size(429, 16);
            this.ArtefactLabel.TabIndex = 18;
            this.ArtefactLabel.Text = "Note: artefacts (glitches) can\'t be fully removed in the output video.";
            this.ArtefactLabel.Visible = false;
            // 
            // UseGPUCB
            // 
            this.UseGPUCB.AutoSize = true;
            this.UseGPUCB.Enabled = false;
            this.UseGPUCB.Location = new System.Drawing.Point(413, 38);
            this.UseGPUCB.Name = "UseGPUCB";
            this.UseGPUCB.Size = new System.Drawing.Size(95, 20);
            this.UseGPUCB.TabIndex = 8;
            this.UseGPUCB.Text = "Use GPU?";
            this.UseGPUCB.UseVisualStyleBackColor = true;
            this.UseGPUCB.Visible = false;
            // 
            // IwantDD
            // 
            this.IwantDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.IwantDD.Enabled = false;
            this.IwantDD.FormattingEnabled = true;
            this.IwantDD.Items.AddRange(new object[] {
            "Maximum smoothness at the cost of more artefacts (glitches)",
            "Balanced smoothness with less but some artefacts (glitches)",
            "Low smoothness with very little to no artefacts (glitches)"});
            this.IwantDD.Location = new System.Drawing.Point(101, 75);
            this.IwantDD.Name = "IwantDD";
            this.IwantDD.Size = new System.Drawing.Size(424, 24);
            this.IwantDD.TabIndex = 9;
            this.IwantDD.Visible = false;
            // 
            // IwantLabel
            // 
            this.IwantLabel.AutoSize = true;
            this.IwantLabel.Location = new System.Drawing.Point(45, 78);
            this.IwantLabel.Name = "IwantLabel";
            this.IwantLabel.Size = new System.Drawing.Size(48, 16);
            this.IwantLabel.TabIndex = 15;
            this.IwantLabel.Text = "I want:";
            this.IwantLabel.Visible = false;
            // 
            // OutFPSNUD
            // 
            this.OutFPSNUD.Enabled = false;
            this.OutFPSNUD.Location = new System.Drawing.Point(317, 36);
            this.OutFPSNUD.Maximum = new decimal(new int[] {
            140,
            0,
            0,
            0});
            this.OutFPSNUD.Name = "OutFPSNUD";
            this.OutFPSNUD.Size = new System.Drawing.Size(58, 22);
            this.OutFPSNUD.TabIndex = 7;
            this.OutFPSNUD.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
            this.OutFPSNUD.Visible = false;
            // 
            // OutFPSLabel
            // 
            this.OutFPSLabel.AutoSize = true;
            this.OutFPSLabel.Location = new System.Drawing.Point(230, 38);
            this.OutFPSLabel.Name = "OutFPSLabel";
            this.OutFPSLabel.Size = new System.Drawing.Size(86, 16);
            this.OutFPSLabel.TabIndex = 13;
            this.OutFPSLabel.Text = "Output FPS:";
            this.OutFPSLabel.Visible = false;
            // 
            // InputFPSLabel
            // 
            this.InputFPSLabel.AutoSize = true;
            this.InputFPSLabel.Location = new System.Drawing.Point(73, 38);
            this.InputFPSLabel.Name = "InputFPSLabel";
            this.InputFPSLabel.Size = new System.Drawing.Size(74, 16);
            this.InputFPSLabel.TabIndex = 11;
            this.InputFPSLabel.Text = "Input FPS:";
            this.InputFPSLabel.Visible = false;
            // 
            // NoobCB
            // 
            this.NoobCB.AutoSize = true;
            this.NoobCB.Location = new System.Drawing.Point(507, 115);
            this.NoobCB.Name = "NoobCB";
            this.NoobCB.Size = new System.Drawing.Size(71, 20);
            this.NoobCB.TabIndex = 2;
            this.NoobCB.Text = "Noob?";
            this.NoobCB.UseVisualStyleBackColor = true;
            this.NoobCB.CheckedChanged += new System.EventHandler(this.NoobCB_CheckedChanged);
            // 
            // UseCB
            // 
            this.UseCB.AutoSize = true;
            this.UseCB.Location = new System.Drawing.Point(6, 115);
            this.UseCB.Name = "UseCB";
            this.UseCB.Size = new System.Drawing.Size(54, 20);
            this.UseCB.TabIndex = 1;
            this.UseCB.Text = "Use";
            this.UseCB.UseVisualStyleBackColor = true;
            this.UseCB.CheckedChanged += new System.EventHandler(this.UseCB_CheckedChanged);
            // 
            // StuckLink
            // 
            this.StuckLink.AutoSize = true;
            this.StuckLink.Location = new System.Drawing.Point(142, 116);
            this.StuckLink.Name = "StuckLink";
            this.StuckLink.Size = new System.Drawing.Size(37, 16);
            this.StuckLink.TabIndex = 10;
            this.StuckLink.TabStop = true;
            this.StuckLink.Text = "here";
            this.StuckLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.StuckLink_LinkClicked);
            // 
            // StuckLabel
            // 
            this.StuckLabel.AutoSize = true;
            this.StuckLabel.Location = new System.Drawing.Point(72, 116);
            this.StuckLabel.Name = "StuckLabel";
            this.StuckLabel.Size = new System.Drawing.Size(412, 16);
            this.StuckLabel.TabIndex = 7;
            this.StuckLabel.Text = "Stuck? Go          to see the syntax and information of the scripts.";
            // 
            // AnalyseTxtBox
            // 
            this.AnalyseTxtBox.Enabled = false;
            this.AnalyseTxtBox.Location = new System.Drawing.Point(74, 83);
            this.AnalyseTxtBox.Name = "AnalyseTxtBox";
            this.AnalyseTxtBox.Size = new System.Drawing.Size(498, 22);
            this.AnalyseTxtBox.TabIndex = 5;
            // 
            // AnalyseLabel
            // 
            this.AnalyseLabel.AutoSize = true;
            this.AnalyseLabel.Location = new System.Drawing.Point(7, 85);
            this.AnalyseLabel.Name = "AnalyseLabel";
            this.AnalyseLabel.Size = new System.Drawing.Size(62, 16);
            this.AnalyseLabel.TabIndex = 5;
            this.AnalyseLabel.Text = "Analyse:";
            // 
            // SuperTxtBox
            // 
            this.SuperTxtBox.Enabled = false;
            this.SuperTxtBox.Location = new System.Drawing.Point(74, 53);
            this.SuperTxtBox.Name = "SuperTxtBox";
            this.SuperTxtBox.Size = new System.Drawing.Size(498, 22);
            this.SuperTxtBox.TabIndex = 4;
            // 
            // SmoothTxtBox
            // 
            this.SmoothTxtBox.Enabled = false;
            this.SmoothTxtBox.Location = new System.Drawing.Point(74, 23);
            this.SmoothTxtBox.Name = "SmoothTxtBox";
            this.SmoothTxtBox.Size = new System.Drawing.Size(498, 22);
            this.SmoothTxtBox.TabIndex = 3;
            // 
            // SuperLabel
            // 
            this.SuperLabel.AutoSize = true;
            this.SuperLabel.Location = new System.Drawing.Point(7, 55);
            this.SuperLabel.Name = "SuperLabel";
            this.SuperLabel.Size = new System.Drawing.Size(50, 16);
            this.SuperLabel.TabIndex = 2;
            this.SuperLabel.Text = "Super:";
            // 
            // SmoothLabel
            // 
            this.SmoothLabel.AutoSize = true;
            this.SmoothLabel.Location = new System.Drawing.Point(7, 25);
            this.SmoothLabel.Name = "SmoothLabel";
            this.SmoothLabel.Size = new System.Drawing.Size(60, 16);
            this.SmoothLabel.TabIndex = 1;
            this.SmoothLabel.Text = "Smooth:";
            // 
            // ScriptsLabel
            // 
            this.ScriptsLabel.AutoSize = true;
            this.ScriptsLabel.BackColor = System.Drawing.Color.White;
            this.ScriptsLabel.Location = new System.Drawing.Point(255, -1);
            this.ScriptsLabel.Name = "ScriptsLabel";
            this.ScriptsLabel.Size = new System.Drawing.Size(64, 16);
            this.ScriptsLabel.TabIndex = 0;
            this.ScriptsLabel.Text = "SVPFlow";
            // 
            // FormatDD
            // 
            this.FormatDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.FormatDD.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormatDD.FormattingEnabled = true;
            this.FormatDD.ItemHeight = 16;
            this.FormatDD.Items.AddRange(new object[] {
            ".mp4",
            ".mkv",
            ".avi",
            ".mov",
            ".flv"});
            this.FormatDD.Location = new System.Drawing.Point(449, 331);
            this.FormatDD.Name = "FormatDD";
            this.FormatDD.Size = new System.Drawing.Size(59, 24);
            this.FormatDD.TabIndex = 40;
            // 
            // FFWorker
            // 
            this.FFWorker.WorkerSupportsCancellation = true;
            // 
            // EncodePB
            // 
            this.EncodePB.Location = new System.Drawing.Point(10, 362);
            this.EncodePB.Name = "EncodePB";
            this.EncodePB.ProgressText = null;
            this.EncodePB.Size = new System.Drawing.Size(610, 25);
            this.EncodePB.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.EncodePB.TabIndex = 42;
            this.EncodePB.TextColor = System.Drawing.Color.Empty;
            // 
            // FrameGUI
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.AutoSize = true;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(632, 398);
            this.Controls.Add(this.EncodePB);
            this.Controls.Add(this.FormatDD);
            this.Controls.Add(this.Tabs);
            this.Controls.Add(this.SaveOutBttn);
            this.Controls.Add(this.SaveOutTxtBox);
            this.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.Color.Black;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.HelpButton = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "FrameGUI";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FrameGUI v1.2.3";
            this.AboutTab.ResumeLayout(false);
            this.SupportGB.ResumeLayout(false);
            this.SupportGB.PerformLayout();
            this.AboutAuthGB.ResumeLayout(false);
            this.AboutAuthGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TwitterLogo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.InstagramLogo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.YoutubeLogo)).EndInit();
            this.AboutGUIGB.ResumeLayout(false);
            this.AboutGUIGB.PerformLayout();
            this.MainTab.ResumeLayout(false);
            this.MainTab.PerformLayout();
            this.FGUIGB.ResumeLayout(false);
            this.FGUIGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FrameGUILogo)).EndInit();
            this.Tabs.ResumeLayout(false);
            this.SettingsTab.ResumeLayout(false);
            this.SettingsTabs.ResumeLayout(false);
            this.VideoTab.ResumeLayout(false);
            this.SizeGB.ResumeLayout(false);
            this.SizeGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.WidthResNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.HeightResNUD)).EndInit();
            this.EncodeGB.ResumeLayout(false);
            this.EncodeGB.PerformLayout();
            this.ColorsGB.ResumeLayout(false);
            this.ColorsGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SharpenValNUD)).EndInit();
            this.FrameGB.ResumeLayout(false);
            this.FrameGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.FrameRNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BframeValue)).EndInit();
            this.ModeGB.ResumeLayout(false);
            this.ModeGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.crfNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.BitrateValue)).EndInit();
            this.AudioTab.ResumeLayout(false);
            this.AudioSetGB.ResumeLayout(false);
            this.AudioSetGB.PerformLayout();
            this.ScriptOtherTab.ResumeLayout(false);
            this.vsSettingLabel.ResumeLayout(false);
            this.vsSettingLabel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.MaxMemNUD)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ThreadsNUD)).EndInit();
            this.OtherSettingGB.ResumeLayout(false);
            this.OtherSettingGB.PerformLayout();
            this.SettingsGB.ResumeLayout(false);
            this.SettingsGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.OutFPSNUD)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        internal TextBox SaveOutTxtBox;
        internal Button SaveOutBttn;
        internal Button StartEncodeBttn;
        internal TabPage AboutTab;
        internal GroupBox AboutAuthGB;
        internal Label AboutAuthLabel;
        internal GroupBox AboutGUIGB;
        internal Label AboutGUILabel;
        internal TabPage MainTab;
        internal PictureBox FrameGUILogo;
        internal Button SetInputBttn;
        internal TextBox InTxtBox;
        internal TabControl Tabs;
        internal Button CancelBttn;
        internal TabPage SettingsTab;
        internal Label AbGUILabel;
        internal Label AbAuthorLabel;
        internal ComboBox FormatDD;
        internal TabControl SettingsTabs;
        internal TabPage VideoTab;
        internal TabPage AudioTab;
        internal GroupBox EncodeGB;
        internal NumericUpDown BframeValue;
        internal Label bframeLabel;
        internal ComboBox CPUPDD;
        internal Label CPUPreLabel;
        internal NumericUpDown BitrateValue;
        internal Label BitrateLabel;
        internal Label EncodeLabel;
        internal TabPage ScriptOtherTab;
        internal GroupBox SettingsGB;
        internal LinkLabel StuckLink;
        internal Label StuckLabel;
        internal TextBox AnalyseTxtBox;
        internal Label AnalyseLabel;
        internal TextBox SuperTxtBox;
        internal TextBox SmoothTxtBox;
        internal Label SuperLabel;
        internal Label SmoothLabel;
        internal Label ScriptsLabel;
        internal GroupBox SizeGB;
        internal GroupBox OtherSettingGB;
        internal Label AboutAuthDesc;
        internal Label AboutGUIDesc;
        internal PictureBox TwitterLogo;
        internal PictureBox InstagramLogo;
        internal PictureBox YoutubeLogo;
        internal CheckBox UseCB;
        internal Label EncodeModeLabel;
        internal ComboBox EncodeModeDD;
        internal CheckBox ChangeResCB;
        internal Label SizeLabel;
        internal NumericUpDown HeightResNUD;
        internal Label VidHeightLebel;
        internal ComboBox TuneDD;
        internal Label TuneLabel;
        internal Label WidthLabel;
        internal NumericUpDown WidthResNUD;
        internal GroupBox vsSettingLabel;
        internal Label aviLabel;
        internal Label OtherSettingLabel;
        internal NumericUpDown ThreadsNUD;
        internal Label ThreadsLabel;
        internal Label FRLabel;
        internal NumericUpDown FrameRNUD;
        internal Button SaveSettingBttn;
        internal Button CopyCommandBttn;
        internal CheckBox UseCB2;
        internal GroupBox ModeGB;
        internal Label EModeSettingLabel;
        internal GroupBox FrameGB;
        internal Label FrameLabel;
        internal BackgroundWorker FFWorker;
        internal Label ResizeAlgoLabel;
        internal ComboBox ResizeAlgoDD;
        internal GroupBox ColorsGB;
        internal Label ColorsLabel;
        internal CheckBox NotificationCB;
        internal GroupBox AudioSetGB;
        internal Label AudioSetLabel;
        internal ComboBox ColorsDD;
        internal ComboBox AudFormatDD;
        internal Label AudFormatLabel;
        internal Label AudNote;
        internal ComboBox AudBitrateDD;
        internal Label AudioBitLabel;
        internal ComboBox SRDD;
        internal Label AudioSRLabel;
        internal Label MaxMemLabel;
        internal NumericUpDown MaxMemNUD;
        internal CheckBox NoobCB;
        internal NumericUpDown crfNUD;
        internal Label crfValueLabel;
        internal NumericUpDown SharpenValNUD;
        internal CheckBox SharpenCB;
        internal NumericUpDown OutFPSNUD;
        internal Label OutFPSLabel;
        internal Label InputFPSLabel;
        internal ComboBox IwantDD;
        internal Label IwantLabel;
        internal CheckBox UseGPUCB;
        internal Label ArtefactLabel;
        internal LinkLabel VideoLinkEN;
        internal Button OffDocButton;
        internal Label HelpLabel;
        internal Button LogsBttn;
        internal CheckBox MuteAudCB;
        internal GroupBox SupportGB;
        internal Label SupportLabel;
        internal ComboBox FGUIDD;
        internal Label ModeLabel;
        internal GroupBox FGUIGB;
        internal Label FGUILabel;
        internal BackgroundWorker FPSGrabber;
        internal Label FPSLabel;
        internal ProgressBarLabel EncodePB;
    }
}