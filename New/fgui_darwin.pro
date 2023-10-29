QT += core widgets gui network
TEMPLATE = app
TARGET = FrameGUI
DESTDIR = ./x64/Release
CONFIG += ./x64/Release
LIBS += -L"."
DEPENDPATH += .
INCLUDEPATH += ./include
MOC_DIR += ./x64/Release
OBJECTS_DIR += ./x64/Release
RC_FILE = ./assets/FrameGUI.rc
ICON = ./assets/icon.icns
HEADERS += ./include/argument.hpp \
    ./include/checks.hpp \
    ./include/audioinfo.hpp \
    ./include/processerror.hpp \
    ./include/progressinfo.hpp \
    ./include/subtitleinfo.hpp \
    ./include/videoinfo.hpp \
    ./include/videoinfolist.hpp \
    ./include/mediaconfig.hpp \
    ./include/scriptbuilder.hpp \
    ./include/audiosubinforegex.hpp \
    ./include/processerrorregex.hpp \
    ./include/progressinforegex.hpp \
    ./include/videoinforegex.hpp \
    ./include/update.hpp \
    ./include/vapoursynth.hpp \
    ./include/framegui.hpp \
    ./include/ffloader.hpp \
    ./include/darwin/ui_framegui.hpp \
    ./include/darwin/ui_update.hpp
SOURCES += ./src/arguments/argument.cpp \
    ./src/checks/files.cpp \
    ./src/checks/process.cpp \
    ./src/io/audioinfo.cpp \
    ./src/io/processError.cpp \
    ./src/io/progressinfo.cpp \
    ./src/io/subtitleinfo.cpp \
    ./src/io/videoinfo.cpp \
    ./src/io/videoinfolist.cpp \
    ./src/process/ffloader.cpp \
    ./src/process/mediaconfig.cpp \
    ./src/process/processworker.cpp \
    ./src/process/scriptbuilder.cpp \
    ./src/regex/audiosubinforegex.cpp \
    ./src/regex/processerrorregex.cpp \
    ./src/regex/progressinforegex.cpp \
    ./src/regex/videoinforegex.cpp \
    ./src/ui/config.cpp \
    ./src/ui/enviornment.cpp \
    ./src/ui/framegui.cpp \
    ./src/ui/jobs.cpp \
    ./src/ui/msgbox.cpp \
    ./src/ui/script.cpp \
    ./src/ui/settings.cpp \
    ./src/ui/update.cpp \
    ./src/vs/colors.cpp \
    ./src/vs/rife.cpp \
    ./src/vs/srmd.cpp \
    ./src/vs/svpflow.cpp \
    ./src/vs/vapoursynth.cpp \
    ./src/main.cpp
RESOURCES += ./assets/FrameGUI.qrc
