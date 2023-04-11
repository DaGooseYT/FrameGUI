# FrameGUI (NEW v2.0.0+)
<img class="image-align-left" src="https://github.com/DaGooseYT/FrameGUI/blob/main/New/fgui.png" width="450"/><img class="image-align-right" src="https://github.com/DaGooseYT/FrameGUI/blob/main/New/fgui_mos.png" width="450"/>

FrameGUI (frame-gooey) is a free cross-platform, very easy to use encoding utility featuring AI filters, based on the more comprehensive [EncodeGUI](https://github.com/DaGooseYT/EncodeGUI) encoding tool.<br />
FrameGUI is now the first RIFE GUI app to run 100% natively on Apple Silicon.

This repository only consists of the source code; no builds are hosted here. See https://encodegui.com/downloads for the latest builds.

# Features
Below is a list of key features in FrameGUI:
- 100% native Apple Scilicon support for the FrameGUI app itself and ALL its dependencies.
- Supports nearly any video as an input.
- Extreamly lightweight with a total installation size of around 150MB (MacOS).
- Advanced job queue with status indicators and an advanced control set.
- Decluttered encoding settings layout allows you to start processes in as little as a few clicks.
- Features RIFE v4.6 AI frame interpolation as the Convert FPS function.
- Features SRMD super resolution AI upscaling.
- AI filters can be used with ALL major GPU vendors: NVIDIA, AMD, INTEL (Intel iGPUs are not supported). 
- Features VapourSynth API for ALL included filters **which doesn't extract frames before rendering, allowing a faster render time than nearly all competing software.**

# Usage
Documentation including the basic usage guide can be found at https://encodegui.com/docs/documentation. The docs for FrameGUI are still being developed and will be released soon.

# Support
Support for issues and directions for how to submit a proper issue/bug report are available on https://encodegui.com/support.<br />
**No support is provided for legacy versions of FrameGUI (before v2.0.0).**

# Compilation
Requires `Qt 6.2.4 SDK` and MSVC. Install the Qt Visual Studio extension and compile using the built in Visual Studio tools.

Note: The Qt designer .ui file for FrameGUI is not included in this source code.

# License
FrameGUI's source code is licensed under the AGPL v3.0. See LICENSE for more details. Early released versions of FrameGUI are licensed under a custom license. Read it at https://encodegui.com/privacy-terms.

The setup file for FrameGUI is closed source and is NOT a part of this repository or the AGPL license. Read the privacy and terms at EncodeGUI.com linked above for more details.
