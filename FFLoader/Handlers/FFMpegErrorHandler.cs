using System;

namespace FFLoader
{
    public class FFMpegErrorHandler : EventArgs
    {
        /// <summary>
        /// The error message from FFMpeg console, if exists.
        /// </summary>
        public string ErrorMessage { get; private set; }

        /// <summary>
        /// The FFMpeg error event arguments.
        /// </summary>
        /// <param name="message">The FFMpeg error.</param>
        public FFMpegErrorHandler(string message)
        {
            ErrorMessage = message;
        }
    }
}
