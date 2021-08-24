using System;

namespace FFLoader
{
    public class FFExceptionHandler : EventArgs
    {
        /// <summary>
        /// Gets the exception in a string format (ideal for message boxes).
        /// </summary>
        public string Message { get; private set; }

        /// <summary>
        /// The stack trace of the exception.
        /// </summary>
        public string StackTrace { get; private set; }

        /// <summary>
        /// The FFLoader exception arguments.
        /// </summary>
        /// <param name="message">The message of the exception in a string format.</param>
        public FFExceptionHandler(string message)
        {
            Message = message;
        }
    }
}
