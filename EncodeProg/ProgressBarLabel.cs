using System;
using System.Drawing;
using System.Windows.Forms;

namespace EncodeProg
{
    public partial class ProgressBarLabel : ProgressBar
    {
        /// <summary>
        /// The text to write to the ProgressBar.
        /// </summary>
        private string progressText;

        /// <summary>
        /// The color of the text in the ProgressBar.
        /// </summary>
        public Color TextColor { get; set; }

        /// <summary>
        /// The color of the ProgressBar chunks.
        /// </summary>
        public Brush ProgressColor { get; set; }

        /// <summary>
        /// The text to write to the ProgressBar.
        /// </summary>
        public string ProgressText
        {
            get
            {
                return progressText;
            }
            set
            {
                if (progressText != value)
                {
                    Invalidate();
                    progressText = value;
                }
            }
        }

        /// <summary>
        /// Overrides the message from the control.
        /// </summary>
        /// <param name="m">The message.</param>
        protected override void WndProc(ref Message m)
        {
            base.WndProc(ref m);

            switch (m.Msg)
            {
                case 15:
                    using (var graphics = Graphics.FromHwnd(Handle))
                    {
                        DrawText(graphics);
                    }

                    break;
            }
        }

        /// <summary>
        /// Draws the text to go on the progress bar.
        /// </summary>
        /// <param name="graphics"></param>
        private void DrawText(Graphics graphics)
        {
            if (!string.IsNullOrEmpty(ProgressText))
            {
                var font = new Font("Arial", 8.25F, FontStyle.Bold,
                            GraphicsUnit.Point, 0);

                var size = graphics.MeasureString(ProgressText, font);
                var point = new PointF(Width / 2 - size.Width / 2.0F, Height / 2 - size.Height / 2.0F + 2);

                graphics.DrawString(ProgressText, font, new SolidBrush(TextColor), point);
            }
        }

        /// <summary>
        /// Overrides the WS_EX_COMPOSITED parameters to prevent the control from blinking. 
        /// </summary>
        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams result = base.CreateParams;
                result.ExStyle |= 0x02000000;

                return result;
            }
        }

        /// <summary>
        /// Draws the progress bar and the chunks.
        /// </summary>
        /// <param name="pe">Instance of PaintEventArgs.</param>
        protected override void OnPaint(PaintEventArgs pe)
        {
            Rectangle rectangle = ClientRectangle;
            Graphics graphics = pe.Graphics;

            ProgressBarRenderer.DrawHorizontalBar(graphics, rectangle);
            rectangle.Inflate(-2, -2);

            if (Value > 0)
            {
                Rectangle progress = new Rectangle(rectangle.X, rectangle.Y, (int)Math.Floor((decimal)Value / Maximum * rectangle.Width), rectangle.Height);

                ProgressBarRenderer.DrawHorizontalChunks(graphics, progress);

                graphics.FillRectangle(ProgressColor, progress);
            }
        }

        /// <summary>
        /// Configuration.
        /// </summary>
        public ProgressBarLabel()
        {
            InitializeComponent();
            SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint, true);
            Style = ProgressBarStyle.Marquee;
        }
    }
}
