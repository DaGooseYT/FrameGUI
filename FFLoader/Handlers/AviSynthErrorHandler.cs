using System;

namespace FFLoader
{
    public class AviSynthErrorHandler : EventArgs
    {
        /// <summary>
        /// The message AviSynth+ throws if there is a problem.
        /// </summary>
        public string AviSynthErrorMessage { get; private set; }

        /// <summary>
        /// The AviSynth+ error arguments.
        /// </summary>
        /// <param name="message">The AviSynth+ error message in a string format.</param>
        public AviSynthErrorHandler(string message)
        {
            AviSynthErrorMessage = message;
        }
    }
}
