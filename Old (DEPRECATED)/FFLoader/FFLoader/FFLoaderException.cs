using System;
namespace FFLoader
{
    [Serializable]
    public class FFLoaderException : Exception
    {
        public FFLoaderException() : base() { }

        /// <summary>
        /// FFLoaderException that inherits Exception.
        /// </summary>
        /// <param name="exMessage">The exception message.</param>
        public FFLoaderException(string exMessage) : base(exMessage) { }
    }
}
