using System.ComponentModel;
using System.Windows.Forms;

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
            this.EncodePB = new System.Windows.Forms.ProgressBar();
            this.SaveOutTxtBox = new System.Windows.Forms.TextBox();
            this.SaveOutBttn = new System.Windows.Forms.Button();
            this.StartEncodeBttn = new System.Windows.Forms.Button();
            this.AboutTab = new System.Windows.Forms.TabPage();
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
            this.CancelBttn = new System.Windows.Forms.Button();
            this.FrameGUILabel = new System.Windows.Forms.Label();
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
            this.ArtefactLabel = new System.Windows.Forms.Label();
            this.UseGPUCB = new System.Windows.Forms.CheckBox();
            this.IwantDD = new System.Windows.Forms.ComboBox();
            this.IwantLabel = new System.Windows.Forms.Label();
            this.OutFPSNUD = new System.Windows.Forms.NumericUpDown();
            this.OutFPSLabel = new System.Windows.Forms.Label();
            this.InputFPSNUD = new System.Windows.Forms.NumericUpDown();
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
            this.ProgressLabel = new System.Windows.Forms.Label();
            this.AboutTab.SuspendLayout();
            this.AboutAuthGB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TwitterLogo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.InstagramLogo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.YoutubeLogo)).BeginInit();
            this.AboutGUIGB.SuspendLayout();
            this.MainTab.SuspendLayout();
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
            ((System.ComponentModel.ISupportInitialize)(this.InputFPSNUD)).BeginInit();
            this.SuspendLayout();
            // 
            // EncodePB
            // 
            this.EncodePB.Cursor = System.Windows.Forms.Cursors.Default;
            this.EncodePB.Location = new System.Drawing.Point(10, 291);
            this.EncodePB.Name = "EncodePB";
            this.EncodePB.Size = new System.Drawing.Size(97, 20);
            this.EncodePB.TabIndex = 0;
            // 
            // SaveOutTxtBox
            // 
            this.SaveOutTxtBox.Enabled = false;
            this.SaveOutTxtBox.Location = new System.Drawing.Point(10, 262);
            this.SaveOutTxtBox.Name = "SaveOutTxtBox";
            this.SaveOutTxtBox.Size = new System.Drawing.Size(320, 20);
            this.SaveOutTxtBox.TabIndex = 1;
            this.SaveOutTxtBox.TabStop = false;
            // 
            // SaveOutBttn
            // 
            this.SaveOutBttn.BackColor = System.Drawing.SystemColors.ControlLight;
            this.SaveOutBttn.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SaveOutBttn.Location = new System.Drawing.Point(388, 260);
            this.SaveOutBttn.Name = "SaveOutBttn";
            this.SaveOutBttn.Size = new System.Drawing.Size(89, 24);
            this.SaveOutBttn.TabIndex = 41;
            this.SaveOutBttn.Text = "Save Output";
            this.SaveOutBttn.UseVisualStyleBackColor = false;
            this.SaveOutBttn.Click += new System.EventHandler(this.SaveOutBttn_Click);
            // 
            // StartEncodeBttn
            // 
            this.StartEncodeBttn.Font = new System.Drawing.Font("Arial", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.StartEncodeBttn.ForeColor = System.Drawing.Color.Green;
            this.StartEncodeBttn.Location = new System.Drawing.Point(245, 48);
            this.StartEncodeBttn.Name = "StartEncodeBttn";
            this.StartEncodeBttn.Size = new System.Drawing.Size(181, 56);
            this.StartEncodeBttn.TabIndex = 2;
            this.StartEncodeBttn.Text = "Start Encode";
            this.StartEncodeBttn.UseVisualStyleBackColor = true;
            this.StartEncodeBttn.Click += new System.EventHandler(this.StartEncodeBttn_Click);
            // 
            // AboutTab
            // 
            this.AboutTab.Controls.Add(this.OffDocButton);
            this.AboutTab.Controls.Add(this.HelpLabel);
            this.AboutTab.Controls.Add(this.AboutAuthGB);
            this.AboutTab.Controls.Add(this.AboutGUIGB);
            this.AboutTab.Location = new System.Drawing.Point(4, 23);
            this.AboutTab.Name = "AboutTab";
            this.AboutTab.Padding = new System.Windows.Forms.Padding(3);
            this.AboutTab.Size = new System.Drawing.Size(460, 224);
            this.AboutTab.TabIndex = 3;
            this.AboutTab.Text = "About";
            this.AboutTab.UseVisualStyleBackColor = true;
            // 
            // OffDocButton
            // 
            this.OffDocButton.Location = new System.Drawing.Point(271, 192);
            this.OffDocButton.Name = "OffDocButton";
            this.OffDocButton.Size = new System.Drawing.Size(183, 24);
            this.OffDocButton.TabIndex = 3;
            this.OffDocButton.Text = "Official documentation";
            this.OffDocButton.UseVisualStyleBackColor = true;
            this.OffDocButton.Click += new System.EventHandler(this.OffDoc_Click);
            // 
            // HelpLabel
            // 
            this.HelpLabel.AutoSize = true;
            this.HelpLabel.Location = new System.Drawing.Point(235, 196);
            this.HelpLabel.Name = "HelpLabel";
            this.HelpLabel.Size = new System.Drawing.Size(31, 14);
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
            this.AboutAuthGB.Location = new System.Drawing.Point(237, 7);
            this.AboutAuthGB.Name = "AboutAuthGB";
            this.AboutAuthGB.Size = new System.Drawing.Size(217, 179);
            this.AboutAuthGB.TabIndex = 1;
            this.AboutAuthGB.TabStop = false;
            // 
            // TwitterLogo
            // 
            this.TwitterLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.TwitterLogo.Image = ((System.Drawing.Image)(resources.GetObject("TwitterLogo.Image")));
            this.TwitterLogo.Location = new System.Drawing.Point(151, 126);
            this.TwitterLogo.Margin = new System.Windows.Forms.Padding(4);
            this.TwitterLogo.Name = "TwitterLogo";
            this.TwitterLogo.Size = new System.Drawing.Size(59, 43);
            this.TwitterLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.TwitterLogo.TabIndex = 8;
            this.TwitterLogo.TabStop = false;
            this.TwitterLogo.Click += new System.EventHandler(this.TwitterLogo_Click);
            // 
            // InstagramLogo
            // 
            this.InstagramLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.InstagramLogo.Image = ((System.Drawing.Image)(resources.GetObject("InstagramLogo.Image")));
            this.InstagramLogo.Location = new System.Drawing.Point(7, 126);
            this.InstagramLogo.Margin = new System.Windows.Forms.Padding(4);
            this.InstagramLogo.Name = "InstagramLogo";
            this.InstagramLogo.Size = new System.Drawing.Size(55, 43);
            this.InstagramLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.InstagramLogo.TabIndex = 7;
            this.InstagramLogo.TabStop = false;
            this.InstagramLogo.Click += new System.EventHandler(this.InstagramLogo_Click);
            // 
            // YoutubeLogo
            // 
            this.YoutubeLogo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.YoutubeLogo.Image = ((System.Drawing.Image)(resources.GetObject("YoutubeLogo.Image")));
            this.YoutubeLogo.Location = new System.Drawing.Point(78, 130);
            this.YoutubeLogo.Margin = new System.Windows.Forms.Padding(4);
            this.YoutubeLogo.Name = "YoutubeLogo";
            this.YoutubeLogo.Size = new System.Drawing.Size(58, 33);
            this.YoutubeLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.YoutubeLogo.TabIndex = 6;
            this.YoutubeLogo.TabStop = false;
            this.YoutubeLogo.Click += new System.EventHandler(this.YoutubeLogo_Click);
            // 
            // AboutAuthDesc
            // 
            this.AboutAuthDesc.AutoSize = true;
            this.AboutAuthDesc.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AboutAuthDesc.Location = new System.Drawing.Point(25, 29);
            this.AboutAuthDesc.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AboutAuthDesc.Name = "AboutAuthDesc";
            this.AboutAuthDesc.Size = new System.Drawing.Size(167, 84);
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
            this.AbAuthorLabel.Size = new System.Drawing.Size(0, 15);
            this.AbAuthorLabel.TabIndex = 1;
            this.AbAuthorLabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // AboutAuthLabel
            // 
            this.AboutAuthLabel.AutoSize = true;
            this.AboutAuthLabel.BackColor = System.Drawing.Color.White;
            this.AboutAuthLabel.Location = new System.Drawing.Point(88, 0);
            this.AboutAuthLabel.Name = "AboutAuthLabel";
            this.AboutAuthLabel.Size = new System.Drawing.Size(40, 14);
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
            this.AboutGUIGB.Size = new System.Drawing.Size(228, 213);
            this.AboutGUIGB.TabIndex = 0;
            this.AboutGUIGB.TabStop = false;
            // 
            // VideoLinkEN
            // 
            this.VideoLinkEN.AutoSize = true;
            this.VideoLinkEN.Location = new System.Drawing.Point(45, 187);
            this.VideoLinkEN.Name = "VideoLinkEN";
            this.VideoLinkEN.Size = new System.Drawing.Size(134, 14);
            this.VideoLinkEN.TabIndex = 39;
            this.VideoLinkEN.TabStop = true;
            this.VideoLinkEN.Text = "Official Tutorial Video (EN)";
            this.VideoLinkEN.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.VideoLinkEN_LinkClicked);
            // 
            // AboutGUIDesc
            // 
            this.AboutGUIDesc.AutoSize = true;
            this.AboutGUIDesc.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AboutGUIDesc.Location = new System.Drawing.Point(25, 29);
            this.AboutGUIDesc.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.AboutGUIDesc.Name = "AboutGUIDesc";
            this.AboutGUIDesc.Size = new System.Drawing.Size(176, 140);
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
            this.AbGUILabel.Size = new System.Drawing.Size(0, 15);
            this.AbGUILabel.TabIndex = 2;
            this.AbGUILabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // AboutGUILabel
            // 
            this.AboutGUILabel.AutoSize = true;
            this.AboutGUILabel.BackColor = System.Drawing.Color.White;
            this.AboutGUILabel.Location = new System.Drawing.Point(68, 0);
            this.AboutGUILabel.Name = "AboutGUILabel";
            this.AboutGUILabel.Size = new System.Drawing.Size(86, 14);
            this.AboutGUILabel.TabIndex = 0;
            this.AboutGUILabel.Text = "About FrameGUI";
            // 
            // MainTab
            // 
            this.MainTab.Controls.Add(this.CancelBttn);
            this.MainTab.Controls.Add(this.FrameGUILabel);
            this.MainTab.Controls.Add(this.FrameGUILogo);
            this.MainTab.Controls.Add(this.StartEncodeBttn);
            this.MainTab.Controls.Add(this.SetInputBttn);
            this.MainTab.Controls.Add(this.InTxtBox);
            this.MainTab.Location = new System.Drawing.Point(4, 23);
            this.MainTab.Name = "MainTab";
            this.MainTab.Padding = new System.Windows.Forms.Padding(3);
            this.MainTab.Size = new System.Drawing.Size(460, 224);
            this.MainTab.TabIndex = 0;
            this.MainTab.Text = "Main";
            this.MainTab.UseVisualStyleBackColor = true;
            // 
            // CancelBttn
            // 
            this.CancelBttn.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CancelBttn.ForeColor = System.Drawing.Color.Red;
            this.CancelBttn.Location = new System.Drawing.Point(245, 111);
            this.CancelBttn.Name = "CancelBttn";
            this.CancelBttn.Size = new System.Drawing.Size(181, 25);
            this.CancelBttn.TabIndex = 3;
            this.CancelBttn.Text = "Cancel";
            this.CancelBttn.UseVisualStyleBackColor = true;
            this.CancelBttn.Visible = false;
            this.CancelBttn.Click += new System.EventHandler(this.CancelClick);
            // 
            // FrameGUILabel
            // 
            this.FrameGUILabel.AutoSize = true;
            this.FrameGUILabel.Font = new System.Drawing.Font("Arial", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FrameGUILabel.Location = new System.Drawing.Point(207, 155);
            this.FrameGUILabel.Name = "FrameGUILabel";
            this.FrameGUILabel.Size = new System.Drawing.Size(247, 55);
            this.FrameGUILabel.TabIndex = 3;
            this.FrameGUILabel.Text = "FrameGUI";
            // 
            // FrameGUILogo
            // 
            this.FrameGUILogo.ErrorImage = null;
            this.FrameGUILogo.Image = ((System.Drawing.Image)(resources.GetObject("FrameGUILogo.Image")));
            this.FrameGUILogo.Location = new System.Drawing.Point(7, 36);
            this.FrameGUILogo.Name = "FrameGUILogo";
            this.FrameGUILogo.Size = new System.Drawing.Size(208, 176);
            this.FrameGUILogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.FrameGUILogo.TabIndex = 5;
            this.FrameGUILogo.TabStop = false;
            // 
            // SetInputBttn
            // 
            this.SetInputBttn.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SetInputBttn.Location = new System.Drawing.Point(359, 7);
            this.SetInputBttn.Name = "SetInputBttn";
            this.SetInputBttn.Size = new System.Drawing.Size(95, 22);
            this.SetInputBttn.TabIndex = 0;
            this.SetInputBttn.Text = "Select Input";
            this.SetInputBttn.UseVisualStyleBackColor = true;
            this.SetInputBttn.Click += new System.EventHandler(this.SetInputBttn_Click);
            // 
            // InTxtBox
            // 
            this.InTxtBox.Enabled = false;
            this.InTxtBox.Location = new System.Drawing.Point(7, 8);
            this.InTxtBox.Name = "InTxtBox";
            this.InTxtBox.Size = new System.Drawing.Size(346, 20);
            this.InTxtBox.TabIndex = 0;
            this.InTxtBox.TabStop = false;
            // 
            // Tabs
            // 
            this.Tabs.Controls.Add(this.MainTab);
            this.Tabs.Controls.Add(this.SettingsTab);
            this.Tabs.Controls.Add(this.AboutTab);
            this.Tabs.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Tabs.Location = new System.Drawing.Point(10, 3);
            this.Tabs.Name = "Tabs";
            this.Tabs.SelectedIndex = 0;
            this.Tabs.Size = new System.Drawing.Size(468, 251);
            this.Tabs.TabIndex = 38;
            this.Tabs.TabStop = false;
            // 
            // SettingsTab
            // 
            this.SettingsTab.Controls.Add(this.SettingsTabs);
            this.SettingsTab.Location = new System.Drawing.Point(4, 23);
            this.SettingsTab.Name = "SettingsTab";
            this.SettingsTab.Padding = new System.Windows.Forms.Padding(3);
            this.SettingsTab.Size = new System.Drawing.Size(460, 224);
            this.SettingsTab.TabIndex = 4;
            this.SettingsTab.Text = "Encoder Settings";
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
            this.SettingsTabs.Size = new System.Drawing.Size(454, 216);
            this.SettingsTabs.TabIndex = 20;
            this.SettingsTabs.TabStop = false;
            // 
            // VideoTab
            // 
            this.VideoTab.Controls.Add(this.SizeGB);
            this.VideoTab.Controls.Add(this.EncodeGB);
            this.VideoTab.Location = new System.Drawing.Point(4, 23);
            this.VideoTab.Name = "VideoTab";
            this.VideoTab.Padding = new System.Windows.Forms.Padding(3);
            this.VideoTab.Size = new System.Drawing.Size(446, 189);
            this.VideoTab.TabIndex = 0;
            this.VideoTab.Text = "Video (x264)";
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
            this.SizeGB.Location = new System.Drawing.Point(328, 6);
            this.SizeGB.Name = "SizeGB";
            this.SizeGB.Size = new System.Drawing.Size(112, 179);
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
            this.ResizeAlgoDD.Location = new System.Drawing.Point(6, 148);
            this.ResizeAlgoDD.Name = "ResizeAlgoDD";
            this.ResizeAlgoDD.Size = new System.Drawing.Size(100, 22);
            this.ResizeAlgoDD.TabIndex = 13;
            // 
            // ResizeAlgoLabel
            // 
            this.ResizeAlgoLabel.AutoSize = true;
            this.ResizeAlgoLabel.Location = new System.Drawing.Point(23, 124);
            this.ResizeAlgoLabel.Name = "ResizeAlgoLabel";
            this.ResizeAlgoLabel.Size = new System.Drawing.Size(66, 14);
            this.ResizeAlgoLabel.TabIndex = 6;
            this.ResizeAlgoLabel.Text = "Resize algo:";
            // 
            // WidthResNUD
            // 
            this.WidthResNUD.Enabled = false;
            this.WidthResNUD.Location = new System.Drawing.Point(53, 90);
            this.WidthResNUD.Maximum = new decimal(new int[] {
            3840,
            0,
            0,
            0});
            this.WidthResNUD.Name = "WidthResNUD";
            this.WidthResNUD.Size = new System.Drawing.Size(50, 20);
            this.WidthResNUD.TabIndex = 12;
            // 
            // WidthLabel
            // 
            this.WidthLabel.AutoSize = true;
            this.WidthLabel.Location = new System.Drawing.Point(6, 93);
            this.WidthLabel.Name = "WidthLabel";
            this.WidthLabel.Size = new System.Drawing.Size(37, 14);
            this.WidthLabel.TabIndex = 4;
            this.WidthLabel.Text = "Width:";
            // 
            // HeightResNUD
            // 
            this.HeightResNUD.Enabled = false;
            this.HeightResNUD.Location = new System.Drawing.Point(53, 57);
            this.HeightResNUD.Maximum = new decimal(new int[] {
            2160,
            0,
            0,
            0});
            this.HeightResNUD.Name = "HeightResNUD";
            this.HeightResNUD.Size = new System.Drawing.Size(50, 20);
            this.HeightResNUD.TabIndex = 11;
            // 
            // VidHeightLebel
            // 
            this.VidHeightLebel.AutoSize = true;
            this.VidHeightLebel.Location = new System.Drawing.Point(6, 59);
            this.VidHeightLebel.Name = "VidHeightLebel";
            this.VidHeightLebel.Size = new System.Drawing.Size(40, 14);
            this.VidHeightLebel.TabIndex = 2;
            this.VidHeightLebel.Text = "Height:";
            // 
            // ChangeResCB
            // 
            this.ChangeResCB.AutoSize = true;
            this.ChangeResCB.Location = new System.Drawing.Point(25, 27);
            this.ChangeResCB.Name = "ChangeResCB";
            this.ChangeResCB.Size = new System.Drawing.Size(63, 18);
            this.ChangeResCB.TabIndex = 10;
            this.ChangeResCB.Text = "Change";
            this.ChangeResCB.UseVisualStyleBackColor = true;
            this.ChangeResCB.CheckedChanged += new System.EventHandler(this.ChangeResCB_CheckedChanged);
            // 
            // SizeLabel
            // 
            this.SizeLabel.AutoSize = true;
            this.SizeLabel.BackColor = System.Drawing.Color.White;
            this.SizeLabel.Location = new System.Drawing.Point(41, 0);
            this.SizeLabel.Name = "SizeLabel";
            this.SizeLabel.Size = new System.Drawing.Size(28, 14);
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
            this.EncodeGB.Location = new System.Drawing.Point(3, 6);
            this.EncodeGB.Name = "EncodeGB";
            this.EncodeGB.Size = new System.Drawing.Size(319, 179);
            this.EncodeGB.TabIndex = 3;
            this.EncodeGB.TabStop = false;
            // 
            // ColorsGB
            // 
            this.ColorsGB.Controls.Add(this.SharpenValNUD);
            this.ColorsGB.Controls.Add(this.SharpenCB);
            this.ColorsGB.Controls.Add(this.ColorsDD);
            this.ColorsGB.Controls.Add(this.ColorsLabel);
            this.ColorsGB.Location = new System.Drawing.Point(6, 93);
            this.ColorsGB.Name = "ColorsGB";
            this.ColorsGB.Size = new System.Drawing.Size(122, 79);
            this.ColorsGB.TabIndex = 2;
            this.ColorsGB.TabStop = false;
            // 
            // SharpenValNUD
            // 
            this.SharpenValNUD.DecimalPlaces = 1;
            this.SharpenValNUD.Location = new System.Drawing.Point(76, 51);
            this.SharpenValNUD.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.SharpenValNUD.Name = "SharpenValNUD";
            this.SharpenValNUD.Size = new System.Drawing.Size(40, 20);
            this.SharpenValNUD.TabIndex = 4;
            // 
            // SharpenCB
            // 
            this.SharpenCB.AutoSize = true;
            this.SharpenCB.Location = new System.Drawing.Point(6, 52);
            this.SharpenCB.Name = "SharpenCB";
            this.SharpenCB.Size = new System.Drawing.Size(70, 18);
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
            this.ColorsDD.Location = new System.Drawing.Point(18, 20);
            this.ColorsDD.Name = "ColorsDD";
            this.ColorsDD.Size = new System.Drawing.Size(86, 22);
            this.ColorsDD.TabIndex = 5;
            this.ColorsDD.TabStop = false;
            // 
            // ColorsLabel
            // 
            this.ColorsLabel.AutoSize = true;
            this.ColorsLabel.BackColor = System.Drawing.Color.White;
            this.ColorsLabel.Location = new System.Drawing.Point(42, 0);
            this.ColorsLabel.Name = "ColorsLabel";
            this.ColorsLabel.Size = new System.Drawing.Size(38, 14);
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
            this.FrameGB.Location = new System.Drawing.Point(6, 10);
            this.FrameGB.Name = "FrameGB";
            this.FrameGB.Size = new System.Drawing.Size(122, 81);
            this.FrameGB.TabIndex = 1;
            this.FrameGB.TabStop = false;
            // 
            // FrameLabel
            // 
            this.FrameLabel.AutoSize = true;
            this.FrameLabel.BackColor = System.Drawing.Color.White;
            this.FrameLabel.Location = new System.Drawing.Point(43, 0);
            this.FrameLabel.Name = "FrameLabel";
            this.FrameLabel.Size = new System.Drawing.Size(37, 14);
            this.FrameLabel.TabIndex = 18;
            this.FrameLabel.Text = "Frame";
            // 
            // FRLabel
            // 
            this.FRLabel.AutoSize = true;
            this.FRLabel.Location = new System.Drawing.Point(6, 21);
            this.FRLabel.Name = "FRLabel";
            this.FRLabel.Size = new System.Drawing.Size(59, 14);
            this.FRLabel.TabIndex = 16;
            this.FRLabel.Text = "Framerate:";
            // 
            // FrameRNUD
            // 
            this.FrameRNUD.Location = new System.Drawing.Point(66, 19);
            this.FrameRNUD.Maximum = new decimal(new int[] {
            240,
            0,
            0,
            0});
            this.FrameRNUD.Name = "FrameRNUD";
            this.FrameRNUD.Size = new System.Drawing.Size(50, 20);
            this.FrameRNUD.TabIndex = 1;
            // 
            // bframeLabel
            // 
            this.bframeLabel.AutoSize = true;
            this.bframeLabel.Location = new System.Drawing.Point(6, 53);
            this.bframeLabel.Name = "bframeLabel";
            this.bframeLabel.Size = new System.Drawing.Size(55, 14);
            this.bframeLabel.TabIndex = 7;
            this.bframeLabel.Text = "B-frames:";
            // 
            // BframeValue
            // 
            this.BframeValue.Location = new System.Drawing.Point(66, 51);
            this.BframeValue.Maximum = new decimal(new int[] {
            14,
            0,
            0,
            0});
            this.BframeValue.Name = "BframeValue";
            this.BframeValue.Size = new System.Drawing.Size(50, 20);
            this.BframeValue.TabIndex = 2;
            // 
            // ModeGB
            // 
            this.ModeGB.Controls.Add(this.crfNUD);
            this.ModeGB.Controls.Add(this.crfValueLabel);
            this.ModeGB.Controls.Add(this.EModeSettingLabel);
            this.ModeGB.Controls.Add(this.BitrateValue);
            this.ModeGB.Controls.Add(this.BitrateLabel);
            this.ModeGB.Location = new System.Drawing.Point(134, 50);
            this.ModeGB.Name = "ModeGB";
            this.ModeGB.Size = new System.Drawing.Size(179, 60);
            this.ModeGB.TabIndex = 4;
            this.ModeGB.TabStop = false;
            // 
            // crfNUD
            // 
            this.crfNUD.Location = new System.Drawing.Point(102, 25);
            this.crfNUD.Maximum = new decimal(new int[] {
            51,
            0,
            0,
            0});
            this.crfNUD.Name = "crfNUD";
            this.crfNUD.Size = new System.Drawing.Size(38, 20);
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
            this.crfValueLabel.Location = new System.Drawing.Point(35, 27);
            this.crfValueLabel.Name = "crfValueLabel";
            this.crfValueLabel.Size = new System.Drawing.Size(59, 14);
            this.crfValueLabel.TabIndex = 9;
            this.crfValueLabel.Text = "CRF value:";
            // 
            // EModeSettingLabel
            // 
            this.EModeSettingLabel.AutoSize = true;
            this.EModeSettingLabel.BackColor = System.Drawing.Color.White;
            this.EModeSettingLabel.Location = new System.Drawing.Point(26, 0);
            this.EModeSettingLabel.Name = "EModeSettingLabel";
            this.EModeSettingLabel.Size = new System.Drawing.Size(122, 14);
            this.EModeSettingLabel.TabIndex = 9;
            this.EModeSettingLabel.Text = "Encoding Mode Settings";
            // 
            // BitrateValue
            // 
            this.BitrateValue.Location = new System.Drawing.Point(101, 25);
            this.BitrateValue.Maximum = new decimal(new int[] {
            80000,
            0,
            0,
            0});
            this.BitrateValue.Name = "BitrateValue";
            this.BitrateValue.Size = new System.Drawing.Size(61, 20);
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
            this.BitrateLabel.Location = new System.Drawing.Point(24, 27);
            this.BitrateLabel.Name = "BitrateLabel";
            this.BitrateLabel.Size = new System.Drawing.Size(72, 14);
            this.BitrateLabel.TabIndex = 9;
            this.BitrateLabel.Text = "Bitrate (kb/s):";
            this.BitrateLabel.Visible = false;
            // 
            // UseCB2
            // 
            this.UseCB2.AutoSize = true;
            this.UseCB2.Location = new System.Drawing.Point(274, 119);
            this.UseCB2.Name = "UseCB2";
            this.UseCB2.Size = new System.Drawing.Size(45, 18);
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
            this.TuneDD.Location = new System.Drawing.Point(172, 116);
            this.TuneDD.Name = "TuneDD";
            this.TuneDD.Size = new System.Drawing.Size(96, 22);
            this.TuneDD.TabIndex = 7;
            // 
            // TuneLabel
            // 
            this.TuneLabel.AutoSize = true;
            this.TuneLabel.Location = new System.Drawing.Point(131, 119);
            this.TuneLabel.Name = "TuneLabel";
            this.TuneLabel.Size = new System.Drawing.Size(34, 14);
            this.TuneLabel.TabIndex = 12;
            this.TuneLabel.Text = "Tune:";
            // 
            // EncodeModeDD
            // 
            this.EncodeModeDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.EncodeModeDD.FormattingEnabled = true;
            this.EncodeModeDD.ItemHeight = 14;
            this.EncodeModeDD.Items.AddRange(new object[] {
            "Constant Rate Factor (CRF)",
            "1 Pass Average Bit Rate"});
            this.EncodeModeDD.Location = new System.Drawing.Point(174, 20);
            this.EncodeModeDD.Name = "EncodeModeDD";
            this.EncodeModeDD.Size = new System.Drawing.Size(139, 22);
            this.EncodeModeDD.TabIndex = 3;
            this.EncodeModeDD.SelectedIndexChanged += new System.EventHandler(this.EncodeModeDD_SelectedIndexChanged);
            // 
            // EncodeModeLabel
            // 
            this.EncodeModeLabel.AutoSize = true;
            this.EncodeModeLabel.Location = new System.Drawing.Point(131, 24);
            this.EncodeModeLabel.Name = "EncodeModeLabel";
            this.EncodeModeLabel.Size = new System.Drawing.Size(36, 14);
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
            this.CPUPDD.Location = new System.Drawing.Point(202, 148);
            this.CPUPDD.Name = "CPUPDD";
            this.CPUPDD.Size = new System.Drawing.Size(111, 22);
            this.CPUPDD.TabIndex = 8;
            // 
            // CPUPreLabel
            // 
            this.CPUPreLabel.AutoSize = true;
            this.CPUPreLabel.Location = new System.Drawing.Point(131, 151);
            this.CPUPreLabel.Name = "CPUPreLabel";
            this.CPUPreLabel.Size = new System.Drawing.Size(64, 14);
            this.CPUPreLabel.TabIndex = 3;
            this.CPUPreLabel.Text = "CPU Preset:";
            // 
            // EncodeLabel
            // 
            this.EncodeLabel.AutoSize = true;
            this.EncodeLabel.BackColor = System.Drawing.Color.White;
            this.EncodeLabel.Location = new System.Drawing.Point(146, 0);
            this.EncodeLabel.Name = "EncodeLabel";
            this.EncodeLabel.Size = new System.Drawing.Size(51, 14);
            this.EncodeLabel.TabIndex = 0;
            this.EncodeLabel.Text = "Encoding";
            // 
            // AudioTab
            // 
            this.AudioTab.Controls.Add(this.AudioSetGB);
            this.AudioTab.Location = new System.Drawing.Point(4, 23);
            this.AudioTab.Name = "AudioTab";
            this.AudioTab.Padding = new System.Windows.Forms.Padding(3);
            this.AudioTab.Size = new System.Drawing.Size(446, 189);
            this.AudioTab.TabIndex = 1;
            this.AudioTab.Text = "Audio";
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
            this.AudioSetGB.Size = new System.Drawing.Size(438, 182);
            this.AudioSetGB.TabIndex = 0;
            this.AudioSetGB.TabStop = false;
            // 
            // MuteAudCB
            // 
            this.MuteAudCB.AutoSize = true;
            this.MuteAudCB.Location = new System.Drawing.Point(272, 118);
            this.MuteAudCB.Name = "MuteAudCB";
            this.MuteAudCB.Size = new System.Drawing.Size(78, 18);
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
            this.SRDD.Location = new System.Drawing.Point(178, 116);
            this.SRDD.Name = "SRDD";
            this.SRDD.Size = new System.Drawing.Size(74, 22);
            this.SRDD.TabIndex = 3;
            // 
            // AudNote
            // 
            this.AudNote.AutoSize = true;
            this.AudNote.Location = new System.Drawing.Point(26, 163);
            this.AudNote.Name = "AudNote";
            this.AudNote.Size = new System.Drawing.Size(387, 14);
            this.AudNote.TabIndex = 3;
            this.AudNote.Text = "Note: Any settings set here will only apply to the FIRST audio track in the video" +
    ".";
            // 
            // AudioSRLabel
            // 
            this.AudioSRLabel.AutoSize = true;
            this.AudioSRLabel.Location = new System.Drawing.Point(75, 119);
            this.AudioSRLabel.Name = "AudioSRLabel";
            this.AudioSRLabel.Size = new System.Drawing.Size(94, 14);
            this.AudioSRLabel.TabIndex = 6;
            this.AudioSRLabel.Text = "Sample Rate (Hz):";
            // 
            // AudioBitLabel
            // 
            this.AudioBitLabel.AutoSize = true;
            this.AudioBitLabel.Location = new System.Drawing.Point(124, 78);
            this.AudioBitLabel.Name = "AudioBitLabel";
            this.AudioBitLabel.Size = new System.Drawing.Size(103, 14);
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
            this.AudBitrateDD.Location = new System.Drawing.Point(233, 75);
            this.AudBitrateDD.Name = "AudBitrateDD";
            this.AudBitrateDD.Size = new System.Drawing.Size(74, 22);
            this.AudBitrateDD.TabIndex = 2;
            // 
            // AudioSetLabel
            // 
            this.AudioSetLabel.AutoSize = true;
            this.AudioSetLabel.BackColor = System.Drawing.Color.White;
            this.AudioSetLabel.Location = new System.Drawing.Point(201, 0);
            this.AudioSetLabel.Name = "AudioSetLabel";
            this.AudioSetLabel.Size = new System.Drawing.Size(35, 14);
            this.AudioSetLabel.TabIndex = 0;
            this.AudioSetLabel.Text = "Audio";
            // 
            // AudFormatLabel
            // 
            this.AudFormatLabel.AutoSize = true;
            this.AudFormatLabel.Location = new System.Drawing.Point(137, 37);
            this.AudFormatLabel.Name = "AudFormatLabel";
            this.AudFormatLabel.Size = new System.Drawing.Size(74, 14);
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
            this.AudFormatDD.Location = new System.Drawing.Point(217, 34);
            this.AudFormatDD.Name = "AudFormatDD";
            this.AudFormatDD.Size = new System.Drawing.Size(74, 22);
            this.AudFormatDD.TabIndex = 1;
            // 
            // ScriptOtherTab
            // 
            this.ScriptOtherTab.Controls.Add(this.vsSettingLabel);
            this.ScriptOtherTab.Controls.Add(this.OtherSettingGB);
            this.ScriptOtherTab.Controls.Add(this.SettingsGB);
            this.ScriptOtherTab.Location = new System.Drawing.Point(4, 23);
            this.ScriptOtherTab.Name = "ScriptOtherTab";
            this.ScriptOtherTab.Size = new System.Drawing.Size(446, 189);
            this.ScriptOtherTab.TabIndex = 2;
            this.ScriptOtherTab.Text = "SVPFlow/AviSynth+/Other";
            this.ScriptOtherTab.UseVisualStyleBackColor = true;
            // 
            // vsSettingLabel
            // 
            this.vsSettingLabel.Controls.Add(this.MaxMemLabel);
            this.vsSettingLabel.Controls.Add(this.MaxMemNUD);
            this.vsSettingLabel.Controls.Add(this.ThreadsNUD);
            this.vsSettingLabel.Controls.Add(this.ThreadsLabel);
            this.vsSettingLabel.Controls.Add(this.aviLabel);
            this.vsSettingLabel.Location = new System.Drawing.Point(3, 117);
            this.vsSettingLabel.Name = "vsSettingLabel";
            this.vsSettingLabel.Size = new System.Drawing.Size(134, 68);
            this.vsSettingLabel.TabIndex = 2;
            this.vsSettingLabel.TabStop = false;
            // 
            // MaxMemLabel
            // 
            this.MaxMemLabel.AutoSize = true;
            this.MaxMemLabel.Location = new System.Drawing.Point(3, 44);
            this.MaxMemLabel.Name = "MaxMemLabel";
            this.MaxMemLabel.Size = new System.Drawing.Size(64, 14);
            this.MaxMemLabel.TabIndex = 4;
            this.MaxMemLabel.Text = "Max. Mem. :";
            // 
            // MaxMemNUD
            // 
            this.MaxMemNUD.Enabled = false;
            this.MaxMemNUD.Location = new System.Drawing.Point(70, 42);
            this.MaxMemNUD.Maximum = new decimal(new int[] {
            4096,
            0,
            0,
            0});
            this.MaxMemNUD.Name = "MaxMemNUD";
            this.MaxMemNUD.Size = new System.Drawing.Size(56, 20);
            this.MaxMemNUD.TabIndex = 2;
            // 
            // ThreadsNUD
            // 
            this.ThreadsNUD.Enabled = false;
            this.ThreadsNUD.Location = new System.Drawing.Point(59, 17);
            this.ThreadsNUD.Maximum = new decimal(new int[] {
            25,
            0,
            0,
            0});
            this.ThreadsNUD.Name = "ThreadsNUD";
            this.ThreadsNUD.Size = new System.Drawing.Size(67, 20);
            this.ThreadsNUD.TabIndex = 1;
            // 
            // ThreadsLabel
            // 
            this.ThreadsLabel.AutoSize = true;
            this.ThreadsLabel.Location = new System.Drawing.Point(3, 19);
            this.ThreadsLabel.Name = "ThreadsLabel";
            this.ThreadsLabel.Size = new System.Drawing.Size(50, 14);
            this.ThreadsLabel.TabIndex = 1;
            this.ThreadsLabel.Text = "Threads:";
            // 
            // aviLabel
            // 
            this.aviLabel.AutoSize = true;
            this.aviLabel.BackColor = System.Drawing.Color.White;
            this.aviLabel.Location = new System.Drawing.Point(38, 0);
            this.aviLabel.Name = "aviLabel";
            this.aviLabel.Size = new System.Drawing.Size(57, 14);
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
            this.OtherSettingGB.Location = new System.Drawing.Point(143, 117);
            this.OtherSettingGB.Name = "OtherSettingGB";
            this.OtherSettingGB.Size = new System.Drawing.Size(298, 68);
            this.OtherSettingGB.TabIndex = 3;
            this.OtherSettingGB.TabStop = false;
            // 
            // LogsBttn
            // 
            this.LogsBttn.Location = new System.Drawing.Point(184, 41);
            this.LogsBttn.Name = "LogsBttn";
            this.LogsBttn.Size = new System.Drawing.Size(108, 22);
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
            this.NotificationCB.Location = new System.Drawing.Point(7, 44);
            this.NotificationCB.Name = "NotificationCB";
            this.NotificationCB.Size = new System.Drawing.Size(171, 18);
            this.NotificationCB.TabIndex = 3;
            this.NotificationCB.Text = "Show task complete message";
            this.NotificationCB.UseVisualStyleBackColor = true;
            // 
            // CopyCommandBttn
            // 
            this.CopyCommandBttn.Location = new System.Drawing.Point(6, 16);
            this.CopyCommandBttn.Name = "CopyCommandBttn";
            this.CopyCommandBttn.Size = new System.Drawing.Size(147, 22);
            this.CopyCommandBttn.TabIndex = 1;
            this.CopyCommandBttn.Text = "Copy FFMpeg Command";
            this.CopyCommandBttn.UseVisualStyleBackColor = true;
            this.CopyCommandBttn.Click += new System.EventHandler(this.CopyCommandBttn_Click);
            // 
            // SaveSettingBttn
            // 
            this.SaveSettingBttn.Location = new System.Drawing.Point(159, 16);
            this.SaveSettingBttn.Name = "SaveSettingBttn";
            this.SaveSettingBttn.Size = new System.Drawing.Size(133, 22);
            this.SaveSettingBttn.TabIndex = 2;
            this.SaveSettingBttn.Text = "Save Current Settings";
            this.SaveSettingBttn.UseVisualStyleBackColor = true;
            this.SaveSettingBttn.Click += new System.EventHandler(this.SaveSettingBttn_Click);
            // 
            // OtherSettingLabel
            // 
            this.OtherSettingLabel.AutoSize = true;
            this.OtherSettingLabel.BackColor = System.Drawing.Color.White;
            this.OtherSettingLabel.Location = new System.Drawing.Point(114, 0);
            this.OtherSettingLabel.Name = "OtherSettingLabel";
            this.OtherSettingLabel.Size = new System.Drawing.Size(76, 14);
            this.OtherSettingLabel.TabIndex = 0;
            this.OtherSettingLabel.Text = "Other Settings";
            // 
            // SettingsGB
            // 
            this.SettingsGB.Controls.Add(this.ArtefactLabel);
            this.SettingsGB.Controls.Add(this.UseGPUCB);
            this.SettingsGB.Controls.Add(this.IwantDD);
            this.SettingsGB.Controls.Add(this.IwantLabel);
            this.SettingsGB.Controls.Add(this.OutFPSNUD);
            this.SettingsGB.Controls.Add(this.OutFPSLabel);
            this.SettingsGB.Controls.Add(this.InputFPSNUD);
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
            this.SettingsGB.Location = new System.Drawing.Point(3, 3);
            this.SettingsGB.Name = "SettingsGB";
            this.SettingsGB.Size = new System.Drawing.Size(438, 112);
            this.SettingsGB.TabIndex = 1;
            this.SettingsGB.TabStop = false;
            // 
            // ArtefactLabel
            // 
            this.ArtefactLabel.AutoSize = true;
            this.ArtefactLabel.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ArtefactLabel.ForeColor = System.Drawing.Color.Red;
            this.ArtefactLabel.Location = new System.Drawing.Point(57, 91);
            this.ArtefactLabel.Name = "ArtefactLabel";
            this.ArtefactLabel.Size = new System.Drawing.Size(312, 14);
            this.ArtefactLabel.TabIndex = 18;
            this.ArtefactLabel.Text = "Note: artefacts (glitches) can\'t be fully removed in output video.";
            this.ArtefactLabel.Visible = false;
            // 
            // UseGPUCB
            // 
            this.UseGPUCB.AutoSize = true;
            this.UseGPUCB.Enabled = false;
            this.UseGPUCB.Location = new System.Drawing.Point(340, 23);
            this.UseGPUCB.Name = "UseGPUCB";
            this.UseGPUCB.Size = new System.Drawing.Size(75, 18);
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
            this.IwantDD.Location = new System.Drawing.Point(73, 56);
            this.IwantDD.Name = "IwantDD";
            this.IwantDD.Size = new System.Drawing.Size(335, 22);
            this.IwantDD.TabIndex = 9;
            this.IwantDD.Visible = false;
            // 
            // IwantLabel
            // 
            this.IwantLabel.AutoSize = true;
            this.IwantLabel.Location = new System.Drawing.Point(27, 59);
            this.IwantLabel.Name = "IwantLabel";
            this.IwantLabel.Size = new System.Drawing.Size(40, 14);
            this.IwantLabel.TabIndex = 15;
            this.IwantLabel.Text = "I want:";
            this.IwantLabel.Visible = false;
            // 
            // OutFPSNUD
            // 
            this.OutFPSNUD.Enabled = false;
            this.OutFPSNUD.Location = new System.Drawing.Point(247, 22);
            this.OutFPSNUD.Maximum = new decimal(new int[] {
            140,
            0,
            0,
            0});
            this.OutFPSNUD.Name = "OutFPSNUD";
            this.OutFPSNUD.Size = new System.Drawing.Size(58, 20);
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
            this.OutFPSLabel.Location = new System.Drawing.Point(177, 24);
            this.OutFPSLabel.Name = "OutFPSLabel";
            this.OutFPSLabel.Size = new System.Drawing.Size(64, 14);
            this.OutFPSLabel.TabIndex = 13;
            this.OutFPSLabel.Text = "Output FPS:";
            this.OutFPSLabel.Visible = false;
            // 
            // InputFPSNUD
            // 
            this.InputFPSNUD.Enabled = false;
            this.InputFPSNUD.Location = new System.Drawing.Point(88, 22);
            this.InputFPSNUD.Minimum = new decimal(new int[] {
            15,
            0,
            0,
            0});
            this.InputFPSNUD.Name = "InputFPSNUD";
            this.InputFPSNUD.Size = new System.Drawing.Size(57, 20);
            this.InputFPSNUD.TabIndex = 6;
            this.InputFPSNUD.Value = new decimal(new int[] {
            24,
            0,
            0,
            0});
            this.InputFPSNUD.Visible = false;
            this.InputFPSNUD.ValueChanged += new System.EventHandler(this.InputFPSNUD_ValueChanged);
            // 
            // InputFPSLabel
            // 
            this.InputFPSLabel.AutoSize = true;
            this.InputFPSLabel.Location = new System.Drawing.Point(27, 24);
            this.InputFPSLabel.Name = "InputFPSLabel";
            this.InputFPSLabel.Size = new System.Drawing.Size(55, 14);
            this.InputFPSLabel.TabIndex = 11;
            this.InputFPSLabel.Text = "Input FPS:";
            this.InputFPSLabel.Visible = false;
            // 
            // NoobCB
            // 
            this.NoobCB.AutoSize = true;
            this.NoobCB.Location = new System.Drawing.Point(381, 90);
            this.NoobCB.Name = "NoobCB";
            this.NoobCB.Size = new System.Drawing.Size(57, 18);
            this.NoobCB.TabIndex = 2;
            this.NoobCB.Text = "Noob?";
            this.NoobCB.UseVisualStyleBackColor = true;
            this.NoobCB.CheckedChanged += new System.EventHandler(this.NoobCB_CheckedChanged);
            // 
            // UseCB
            // 
            this.UseCB.AutoSize = true;
            this.UseCB.Location = new System.Drawing.Point(6, 90);
            this.UseCB.Name = "UseCB";
            this.UseCB.Size = new System.Drawing.Size(45, 18);
            this.UseCB.TabIndex = 1;
            this.UseCB.Text = "Use";
            this.UseCB.UseVisualStyleBackColor = true;
            this.UseCB.CheckedChanged += new System.EventHandler(this.UseCB_CheckedChanged);
            // 
            // StuckLink
            // 
            this.StuckLink.AutoSize = true;
            this.StuckLink.Location = new System.Drawing.Point(111, 91);
            this.StuckLink.Name = "StuckLink";
            this.StuckLink.Size = new System.Drawing.Size(29, 14);
            this.StuckLink.TabIndex = 10;
            this.StuckLink.TabStop = true;
            this.StuckLink.Text = "here";
            this.StuckLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.StuckLink_LinkClicked);
            // 
            // StuckLabel
            // 
            this.StuckLabel.AutoSize = true;
            this.StuckLabel.Location = new System.Drawing.Point(57, 91);
            this.StuckLabel.Name = "StuckLabel";
            this.StuckLabel.Size = new System.Drawing.Size(318, 14);
            this.StuckLabel.TabIndex = 7;
            this.StuckLabel.Text = "Stuck? Go          to see the syntax and information of the scripts.";
            // 
            // AnalyseTxtBox
            // 
            this.AnalyseTxtBox.Enabled = false;
            this.AnalyseTxtBox.Location = new System.Drawing.Point(59, 66);
            this.AnalyseTxtBox.Name = "AnalyseTxtBox";
            this.AnalyseTxtBox.Size = new System.Drawing.Size(373, 20);
            this.AnalyseTxtBox.TabIndex = 5;
            // 
            // AnalyseLabel
            // 
            this.AnalyseLabel.AutoSize = true;
            this.AnalyseLabel.Location = new System.Drawing.Point(7, 69);
            this.AnalyseLabel.Name = "AnalyseLabel";
            this.AnalyseLabel.Size = new System.Drawing.Size(50, 14);
            this.AnalyseLabel.TabIndex = 5;
            this.AnalyseLabel.Text = "Analyse:";
            // 
            // SuperTxtBox
            // 
            this.SuperTxtBox.Enabled = false;
            this.SuperTxtBox.Location = new System.Drawing.Point(59, 42);
            this.SuperTxtBox.Name = "SuperTxtBox";
            this.SuperTxtBox.Size = new System.Drawing.Size(373, 20);
            this.SuperTxtBox.TabIndex = 4;
            // 
            // SmoothTxtBox
            // 
            this.SmoothTxtBox.Enabled = false;
            this.SmoothTxtBox.Location = new System.Drawing.Point(59, 18);
            this.SmoothTxtBox.Name = "SmoothTxtBox";
            this.SmoothTxtBox.Size = new System.Drawing.Size(373, 20);
            this.SmoothTxtBox.TabIndex = 3;
            // 
            // SuperLabel
            // 
            this.SuperLabel.AutoSize = true;
            this.SuperLabel.Location = new System.Drawing.Point(7, 45);
            this.SuperLabel.Name = "SuperLabel";
            this.SuperLabel.Size = new System.Drawing.Size(39, 14);
            this.SuperLabel.TabIndex = 2;
            this.SuperLabel.Text = "Super:";
            // 
            // SmoothLabel
            // 
            this.SmoothLabel.AutoSize = true;
            this.SmoothLabel.Location = new System.Drawing.Point(7, 22);
            this.SmoothLabel.Name = "SmoothLabel";
            this.SmoothLabel.Size = new System.Drawing.Size(46, 14);
            this.SmoothLabel.TabIndex = 1;
            this.SmoothLabel.Text = "Smooth:";
            // 
            // ScriptsLabel
            // 
            this.ScriptsLabel.AutoSize = true;
            this.ScriptsLabel.BackColor = System.Drawing.Color.White;
            this.ScriptsLabel.Location = new System.Drawing.Point(194, 0);
            this.ScriptsLabel.Name = "ScriptsLabel";
            this.ScriptsLabel.Size = new System.Drawing.Size(52, 14);
            this.ScriptsLabel.TabIndex = 0;
            this.ScriptsLabel.Text = "SVPFlow";
            // 
            // FormatDD
            // 
            this.FormatDD.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.FormatDD.FormattingEnabled = true;
            this.FormatDD.ItemHeight = 14;
            this.FormatDD.Items.AddRange(new object[] {
            ".mp4",
            ".mkv",
            ".avi",
            ".mov",
            ".flv"});
            this.FormatDD.Location = new System.Drawing.Point(336, 261);
            this.FormatDD.Name = "FormatDD";
            this.FormatDD.Size = new System.Drawing.Size(46, 22);
            this.FormatDD.TabIndex = 40;
            // 
            // FFWorker
            // 
            this.FFWorker.WorkerSupportsCancellation = true;
            // 
            // ProgressLabel
            // 
            this.ProgressLabel.Cursor = System.Windows.Forms.Cursors.Default;
            this.ProgressLabel.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ProgressLabel.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ProgressLabel.Location = new System.Drawing.Point(113, 290);
            this.ProgressLabel.Name = "ProgressLabel";
            this.ProgressLabel.Size = new System.Drawing.Size(365, 20);
            this.ProgressLabel.TabIndex = 11;
            this.ProgressLabel.Text = "No process is currently running.";
            this.ProgressLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // FrameGUI
            // 
            this.AllowDrop = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(487, 320);
            this.Controls.Add(this.ProgressLabel);
            this.Controls.Add(this.FormatDD);
            this.Controls.Add(this.Tabs);
            this.Controls.Add(this.SaveOutBttn);
            this.Controls.Add(this.SaveOutTxtBox);
            this.Controls.Add(this.EncodePB);
            this.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.Color.Black;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.HelpButton = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "FrameGUI";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Text = "FrameGUI v1.0.5";
            this.AboutTab.ResumeLayout(false);
            this.AboutTab.PerformLayout();
            this.AboutAuthGB.ResumeLayout(false);
            this.AboutAuthGB.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.TwitterLogo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.InstagramLogo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.YoutubeLogo)).EndInit();
            this.AboutGUIGB.ResumeLayout(false);
            this.AboutGUIGB.PerformLayout();
            this.MainTab.ResumeLayout(false);
            this.MainTab.PerformLayout();
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
            ((System.ComponentModel.ISupportInitialize)(this.InputFPSNUD)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        internal ProgressBar EncodePB;
        internal TextBox SaveOutTxtBox;
        internal Button SaveOutBttn;
        internal Button StartEncodeBttn;
        internal TabPage AboutTab;
        internal GroupBox AboutAuthGB;
        internal Label AboutAuthLabel;
        internal GroupBox AboutGUIGB;
        internal Label AboutGUILabel;
        internal TabPage MainTab;
        internal Label FrameGUILabel;
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
        internal Label ProgressLabel;
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
        internal NumericUpDown InputFPSNUD;
        internal Label InputFPSLabel;
        internal ComboBox IwantDD;
        internal Label IwantLabel;
        internal CheckBox UseGPUCB;
        internal Label ArtefactLabel;
        internal LinkLabel VideoLinkEN;
        private Button OffDocButton;
        private Label HelpLabel;
        private Button LogsBttn;
        private CheckBox MuteAudCB;
    }
}