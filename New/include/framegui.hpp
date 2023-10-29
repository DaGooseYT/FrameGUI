#pragma once

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QHttpMultiPart>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QtGui/QDesktopServices>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtGui/QCloseEvent>
#include <QtCore/QSettings>
#include <QtGui/QShortcut>
#include <QtCore/QMimeData>
#include <QtWidgets/QMenu>
#include <QtCore/QProcess>
#include <QtGui/QAction>
#include <QtCore/QPoint>

#include "scriptbuilder.hpp"
#include "mediaconfig.hpp"
#include "ffloader.hpp"
#include "checks.hpp"
#include "audioinfo.hpp"
#include "subtitleinfo.hpp"

#ifdef Q_OS_WINDOWS
#include "windows/ui_framegui.hpp"
#include "dxgi.h"
#pragma comment(lib, "dxgi.lib")
#endif
#ifdef Q_OS_DARWIN
#include "darwin/ui_framegui.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>
#endif
#include "update.hpp"

#define FOR_EACH(total) for (int i = 0; i < total; i++)
#define SET_ENABLED(control) (control->setEnabled(true))
#define SET_DISABLED(control) (control->setEnabled(false))
#define SET_VISIBLE(control) (control->setVisible(true))
#define SET_INVISIBLE(control) (control->setVisible(false))
#define CHECKED(control) (control->isChecked())

#define VERSION (QString("2.2.0"))
#define VSPIPEPATH (QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vspipe.exe")))
#define TEMPPATH_DAR (QDir::toNativeSeparators(QDir::homePath() + QString("/Library/Caches/TemporaryItems")))
#define FFMPEGPATH_WIN (QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\ffmpeg\\ffmpeg.exe")))
#define FFMPEGPATH_DAR (QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/lib/ffmpeg")))
#define LOGPATH_WIN (QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI")))
#define LOGPATH_DAR (QDir::toNativeSeparators(TEMPPATH_DAR + QString("/FrameGUI")))

class FrameGUI : public QMainWindow {
    Q_OBJECT

public:
    FrameGUI(QWidget *parent = Q_NULLPTR);
    ~FrameGUI();

private:
    Ui::FrameGUIClass *_ui;

    enum MessageType {
        Error = 0,
        Warning = 1,
        Info = 2,
        Question = 3
    };

    QMessageBox::StandardButton msgBoxHelper(MessageType type, QString title, QString message, QMessageBox::StandardButton button1, QMessageBox::StandardButton button2, QMessageBox::StandardButton button3);

    int _selectedJob;
    bool _encodingAudio;

    QVariantList _audioArgs;
    QVariantList _arguments;
    QStringList *_gpuNames;
    QStringList *_job;
    QStringList *_inputList;
    QStringList *_outputList;
    QStringList *_tempList;
    QStringList *_state;

    QVariantList _sAudioArgs;
    QVariantList _sArguments;
    QVariantList _sJob;
    QVariantList _sInputList;
    QVariantList _sOutputList;
    QVariantList _sTempList;
    QVariantList _sState;
    QVariantList _sDuration;
    QVariantList _sFrameRate;

    #ifdef Q_OS_WINDOWS
    QVariantList _vapourScript;
    QVariantList _sVapourScript;
    #endif

    QStringList *_fileStream;
    QFile *_logFile;
    QString _version;
    
    FFLoader *_ffloader;
    Update *_update;

    QList<QPushButton*> *_inputBttn;
    QList<QPushButton*> *_outputBttn;
    QList<QPushButton*> *_logsBttn;
    
    void dragEnterEvent(QDragEnterEvent *d);
    void paletter(QLabel *label);
    void dropEvent(QDropEvent *d);
    void getVideoInfo(QString input, QString ffprobe);
    void loadSysSetting();
    void saveSettings();
    void setJobSetting();
    void reIndexBttns();
    void openLogs();
    void setupQueue();
    void bttns();
    void newJob();
    void newTask();
    void gpuFinished();
    void setState();
    void updater();

    #ifdef Q_OS_WINDOWS
    QStringList configureVS(QString id);
    #endif

    QString buildScript(int width, int height, QString jobID);
    QStringList configureAudioPT(int stream, QString id, QString container);
    QStringList configureArgs(QString container, QString id, QString vsScript);
    QString checkEnviornment();

    int decimalCounter(QString value);

private slots:
    void updaterFinished();
    void inputBttn();
    void donateDaGoose();
    void cancelClick();
    void pauseClick();
    void createJob();
    void cancelMain();
    void clearFinished();
    void licenseBttn();
    void upscaleSet();
    void convertSet();
    void outBttn();
    void youClick();
    void disClick();
    void igClick();
    void removeJob();
    void inputClick();
    void outputClick();
    void openOutput();
    void openJobLogs();
    void start();
    void skip();
    void goToUpdate();
    void later();
    void resetJob();
    void jobBttn();
    void jobBttn2();
    void clearBttn();
    void regexFinished();
    void cancelAllClick();
    void updateProgress();
    void encodeFinished();
    void writeFile(QString);
    void jobContext(QPoint);

protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
};