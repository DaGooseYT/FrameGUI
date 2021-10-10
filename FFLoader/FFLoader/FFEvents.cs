using System;

namespace FFLoader
{
    public partial class FFLoaderBase
    {
        /// <summary>
        /// Raises when conversion progress info is availible.
        /// </summary>
        public event EventHandler<ConversionProgress> FFConversionProgress;

        /// <summary>
        /// Raises when video info is availible.
        /// </summary>
        public event EventHandler<VideoInfoHandler> FFVideoInfo;

        /// <summary>
        /// Raises when a problem occurs within FFLoader.
        /// </summary>
        public event EventHandler<FFExceptionHandler> FFLoaderException;

        /// <summary>
        /// Raises when a problem occurs within AviSynth+
        /// </summary>
        public event EventHandler<AviSynthErrorHandler> AviSynthError;

        /// <summary>
        /// Raises when a problem occures within FFMpeg.
        /// </summary>
        public event EventHandler<FFMpegErrorHandler> FFMpegError;

        /// <summary>
        /// Raises when Regex finds the FPS of the input video in FFMpeg.
        /// </summary>
        public event EventHandler<InfoFPSHandler> FPSHandler;

        /// <summary>
        /// Catches the FFLoader exception message and creates a new instance of FFExceptionHandler from it.
        /// </summary>
        /// <param name="message">The exception message.</param>
        /// <param name="handler">Instace of FFExceptionHandler.</param>
        internal void CatchException(string message, out FFExceptionHandler handler)
        {
            handler = new FFExceptionHandler(message);
        }

        /// <summary>
        /// Catches the AviSynth+ error message and creates a new instance of AviSynthErrorHandler from it.
        /// </summary>
        /// <param name="error">The AviSynth+ error message.</param>
        /// <param name="handler">Instance of AviSynthErrorHandler.</param>
        internal void CatchAvsError(string error, out AviSynthErrorHandler handler)
        {
            handler = new AviSynthErrorHandler(error);
        }

        /// <summary>
        /// Catches the FFMpeg error (if exists) and creates event arguments of it.
        /// </summary>
        /// <param name="error">The FFMpeg error message.</param>
        /// <param name="handler">Instance of FFMpegErrorHandler.</param>
        internal void CatchFFMpegError(string error, out FFMpegErrorHandler handler)
        {
            handler = new FFMpegErrorHandler(error);
        }

        /// <summary>
        /// Provides a method to update the AviSynthError event from the AviSynthErrorHandler event handler.
        /// </summary>
        /// <param name="handler">Instance of AviSynthErrorHandler.</param>
        internal virtual void UpdateAvsError(AviSynthErrorHandler handler)
        {
            AviSynthError?.Invoke(this, handler);
        }

        /// <summary>
        /// Provides a method to update the FFMpegError event from the FFMpegErrorHandler event handler.
        /// </summary>
        /// <param name="handler">Instance of FFMpegErrorHandler.</param>
        internal virtual void UpdateFFMpegError(FFMpegErrorHandler handler)
        {
            FFMpegError?.Invoke(this, handler);
        }

        /// <summary>
        /// Provides a method to update the FFConversionProgress event from the ConversionProgress event handler.
        /// </summary>
        /// <param name="progress">Instance of ConversionProgress.</param>
        internal virtual void UpdateConversionProgress(ConversionProgress progress)
        {
            FFConversionProgress?.Invoke(this, progress);
        }

        /// <summary>
        /// Provides a method to update the FPSHandler event from the InfoFPSHandler event handler.
        /// </summary>
        /// <param name="handler">Instance of InfoFPSHandler.</param>
        internal virtual void UpdateInputVideoFPS(InfoFPSHandler handler)
        {
            FPSHandler?.Invoke(this, handler);
        }

        /// <summary>
        /// Provides a method to update the FFVideoInfo event from the VideoInfoHandler event handler.
        /// </summary>
        /// <param name="info">Instace of VideoInfoHandler.</param>
        internal virtual void UpdateVideoInfo(VideoInfoHandler info)
        {
            FFVideoInfo?.Invoke(this, info);
        }

        /// <summary>
        /// Provides a method to update the FFLoaderException event from the FFExceptionHandler event handler.
        /// </summary>
        /// <param name="handler">Instance of FFExceptionHandler.</param>
        internal virtual void UpdateException(FFExceptionHandler handler)
        {
            FFLoaderException?.Invoke(this, handler);
        }
    }
}
