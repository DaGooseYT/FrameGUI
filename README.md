# FrameGUI
![alt text][fgui]

[fgui]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/frameGUI.PNG "FrameGUI"

FrameGUI combines simplicity with advanced encoding features to accomplish tasks such as frame interpolation using the SVPFlow AviSynth plugins. Advanced options and custom input parameters are availible for those who are skilled with SVPFlow. There is also a simple layout for defining SVPFlow parameters for those who do not have knowledge of the SVPFlow parameters syntax. On top of that, FrameGUI has very advanced error event handlers so that solving problems with FFLoader, AviSynth+, and FFMpeg will not be a hassle. While the encoding is in progress, advanced conversion progress info (such as a progress bar, bitrate, and fps) will be displayed in the UI.

### Requirements
- A minimum of 6GB **availible** RAM must be allocated for FrameGUI. Note, **availible** RAM to use; not total RAM. Crashes are possible if there is not enough availible RAM and no error will be shown.
- Windows OS (64-bit). FrameGUI was only tested on Windows 10; older versions of Windows have not been tested and may not work.
- AviSynth+. If you don't have it installed already, FrameGUI will detect that and will open the AviSynth+ setup wizard for you.

# Features
- FFMpeg v4.4 GPL with AviSynth+ support (included in release).
- SVPFlow AviSynth plugins for frame interpolation of videos (included in release).
- AviSynth+, FFMpeg, and FFLoader error reporting for a rich user interface.
- Options to save user settings.
- Can copy FFMpeg command to clipboard.
- Advanced conversion progress info; live progress bar, real-time fps, real-time bitrate, duration left to process, and percentage complete.
- Noob friendly layout for selecting SVPFlow parameters with the alternative option to input custom parameters for SVPFlow (for advanced users).
- Output video format selection consists of the most popular video formats: .mp4, .mkv, .avi, .mov, .flv.
- Output audio format selection consists of the most popular audio formats: .aac, .mp3.

### FFMpeg Specific Features
- Sharpen videos.
- Constant rate factor encoding mode (CRF).
- 1 Pass Average Bitrate encoding mode.
- Encoding/CPU preset selection.
- Options to change the video resolution and the resize algo.
- Change video frame rate (if SVPFlow isn't used).
- Set video encoding tune.
- Set audio bitrate.
- Set audio sample rate.

# Usage
If you do not like reading (like me), the official video tutorial for FrameGUI as an alternative can be found [here](). Otherwise, continue reading for documentation and usage regarding FrameGUI.

### Select Input File
Start by selecting an input file on the `Main` tab. The supported input formats are (case sensitive): .mp4, .mkv, .mov, .avi, .thp, .bik, .m2ts, .ts, .flv, .webm, .ogv

![alt text][input]

[input]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/input.PNG "Select Input File"

### Select Video Encoding Options
Head over to the `Encoder Settings` tab where you will first be presented with the FFMpeg encoding options, or the `Video (x264)` tab. Set the settings to your desire.


![alt text][x264]

[x264]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/x264.PNG "Select Video Encoding Options"


Options in red: Set these options to `0` to passthrough the value from the input video.

### Select Audio Encoding Options
Head over to the `Audio` tab where you will find the audio encoding options. As of now, these are the only options availible. More audio encoding options will come if there is a demand for them. 

![alt text][audio]

[audio]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/audio.PNG "Select Audio Encoding Options"

Note: the `aac` selection in `Audio Format` will use the FFMpeg native AAC encoder. Due to license resrictions, no other aac encoder was built with FFMpeg.

### Select SVPFlow Parameters (optional)
1. Head over to the `SVPFlow/AviSynth+/Other` tab to set the SVPFlow parameters. 
2. Select the `Use` checkbox (in the red box) to enable the options. FrameGUI will attempt to find the AviSynth+ files before enabling the options. If FrameGUI can't find the files, then a message box will show prompting you to install AviSynth+. Select yes (no internet is required for this procedure). 
3. The values in the green box can remain on their defaults, unless you need more memory or threads to AviSynth+. If you already know the syntax of the SVPFlow parameters, skip steps 4, 5, 6 and enter the parameters in the `Smooth`, `Super`, and `Analyse` text boxes

![alt text][svp]

[svp]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/svpflow.PNG "Select SVPFlow Parameters (optional)"

4. If you don't already know the syntax of the parameters and don't want to learn them, then you can have FrameGUI build the parameters for you. To do that, select the `Noob?` checkbox (in the blue box, above) to enable the simplified UI. You will need to specify the input fps as well as the output fps for the video. Enter the input fps of the video (in the red box, below) and then set the output fps (in the blue box, below). Due to safety measures of the encoder and AviSynth+, a minimum of 15 fps input video will be accepted and a maximum of 120 fps output will be accepted. 
5. Define if you want to use the GPU for frame interpolation (**_the video encoding will still use x264; CPU encoding_**). You can do this by selecting or deselecting the `Use GPU?` checkbox (in the green box, below). It is **NOT** recommended to use the GPU at all becuase it will create more artefacts in the output video. 
6. Finally, define the smoothness strength (in the orange checkbox).

![alt text][noob]

[noob]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/noob.PNG "Noob Parameters (optional)"

7. Now that all settings are set, if you would like to save them then select the `Save Current Settings` button. FrameGUI will start up with the saved settings next time you open it.

### Save Output Video & Start Encode
1. Now that all settings are set, go back to the `Main` tab and on the bottom, select the output video format (in the blue box). 
2. Click the `Save Output` button (in the red box) to select the destination for the output video file.

![alt text][saveout]

[saveout]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/save.PNG "Save Output Video"

3. Lastly, select the `Start Encode` button (in the green box) to start the encoding process.
4. Please wait up to 10 seconds for the process to start, then progress info will show (in the red box, below).
5. You can cancel the encoding process at any time while its running. Select the `Cancel` button (in the blue box) to do this.

![alt text][progress]

[progress]: https://github.com/DaGooseYT/FrameGUI/blob/main/photos/progress.PNG "Progress Info"

6. All done!

# Troubleshooting 
FrameGUI consists of multiple error event handlers which makes it easy to detect problems and report them the the user when necessary. A log file of the FFMpeg console output is also created for each encoding process; even if there is a problem/error. Required files and other info to properly report errors, problems, bugs, and issues are listed below. **_Issues and problem reports will not be accepted without these files and info!_**
1. `ffmpeglogs.txt`. This can be found in `C:\Users\~USER\AppData\Local\Temp\FrameGUI`. If no log file was generated or if it's blank, please state that when reporting the issue.
2. `aviscript.avs`. This can also be found in `C:\Users\~USER\AppData\Local\Temp\FrameGUI`. If no AviSynth+ script was generated (e.g. you didn't use AviSynth+) then please state that when reporting the issue.
3. The settings that you have set in FrameGUI (If `ffmpeglogs.txt` was not generated).
4. What version OS you are using (Windows 10, Windows 7, etc.)

All of this information will help me solve the problem quicker and hopefully in one response. Thank you.

# License & Dependencies

### License
FrameGUI and FFLoader as stand-alone software are licensed under the GPL v3.0. A copy of this license is in `main\LICENSE`. By using, modifying, and/or distributing FrameGUI and/or FFLoader, you agree to the terms and conditions presented in the license.

### Dependencies
FrameGUI depends on multiple other third party applications in order for it to function. A list of each application is below along with a copy of their license, the author, and the source code. By using FrameGUI, you also agree to the terms and conditions of the licenses of those applications.

- FFMpeg v4.4 GPL Build - "The FFMpeg Developers" - [GPL v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html) - [Source code](https://github.com/FFmpeg/FFmpeg)
- AviSynth+ v3.7.0 (including installer) - From Jeeb's "AviSynth" - [GPL v2.0](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html) - [Source code](https://github.com/AviSynth/AviSynthPlus)
- SVPFlow AviSynth Plugins - "The SVP Team" - SVPFlow2: Closed Cource. SVPFlow1: [GPL v2.0](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html) - [SVPFlow1 source code](http://www.svp-team.com/files/gpl/svpflow1-src.zip)
- FFms2 AviSynth Plugin - Thomas Goyne, Alex Smith, & Derek Buitenhuis - [MIT License](https://opensource.org/licenses/MIT) - [Source code](https://github.com/FFMS/ffms2)
