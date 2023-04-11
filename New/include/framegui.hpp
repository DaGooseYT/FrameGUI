#pragma once

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtGui/QDesktopServices>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtGui/QCloseEvent>
#include <QtCore/QSettings>
#include <QtCore/QMimeData>
#include <QtWidgets/QMenu>
#include <QtCore/QProcess>
#include <QtGui/QAction>

#include "scriptbuilder.hpp"
#include "mediaconfig.hpp"
#include "ffloader.hpp"
#include "checks.hpp"
#include "audioinfo.hpp"
#include "subtitleinfo.hpp"
#include "../x64/Release/uic/ui_framegui.h"
#include "update.hpp"

#define FOR_EACH(total) for (int i = 0; i < total; i++)
#define SET_ENABLED(control) (control->setEnabled(true))
#define SET_DISABLED(control) (control->setEnabled(false))
#define SET_VISIBLE(control) (control->setVisible(true))
#define SET_INVISIBLE(control) (control->setVisible(false))
#define CHECKED(control) (control->isChecked())

// msgbox
#define ERROR 0
#define WARNING 1
#define INFO 2
#define QUESTION 3

#define VERSION (QString("2.1.0"))

class FrameGUI : public QMainWindow
{
    Q_OBJECT

public:
    FrameGUI(QWidget* parent = Q_NULLPTR);
    ~FrameGUI();

    enum MessageType {
        Error = 0,
        Warning = 1,
        Info = 2,
        Question = 3
    };

    QStringList _arguments;
    QStringList _job;
    QStringList _vapourScript;
    QStringList _inputList;
    QStringList _outputList;
    QStringList _tempList;
    QStringList _state;

    QVariantList _sArguments;
    QVariantList _sJob;
    QVariantList _sVapourScript;
    QVariantList _sInputList;
    QVariantList _sOutputList;
    QVariantList _sTempList;
    QVariantList _sState;
    QVariantList _sDuration;
    QVariantList _sAudioArgs;
    QVariantList _sFrameRate;

    QMessageBox::StandardButton msgBoxHelper(MessageType type, QString title, QString message, QMessageBox::StandardButton button1, QMessageBox::StandardButton button2, QMessageBox::StandardButton button3);

private:
    Ui::FrameGUIClass _ui;

    int _selectedJob;

    QStringList _fileStream;
    QStringList _audioArgs;
    QString _version;
    QFile _logFile; 
    
    FFLoader* _ffloader;
    Update* _update;
    
    void dragEnterEvent(QDragEnterEvent* d);
    void paletter(QLabel* label);
    void dropEvent(QDropEvent* d);
    void getVideoInfo(QString input, QString ffprobe);
    void loadSysSetting();
    void saveSettings();
    void setJobSetting();
    void setupQueue();
    void newJob();
    void newTask();
    void setState();
    void updater();

    QString configureVS(QString id);
    QString buildScript(int width, int height, QString jobID);
    QString configureAudioPT(int stream, QString id, QString container);
    QString configureArgs(QString container, QString id);

    int decimalCounter(QString value);

private slots:
    void updaterFinished();
    void inputBttn();
    void donateDaGoose();
    void patreonClick();
    void cancelClick();
    void pauseClick();
    void createJob();
    void cancelMain();
    void clearFinished();
    void openOutput();
    void upscaleSet();
    void convertSet();
    void outBttn();
    void openJobLogs();
    void youClick();
    void disClick();
    void igClick();
    void removeJob();
    void inputClick();
    void start();
    void skip();
    void goToUpdate();
    void later();
    void resetJob();
    void regexFinished();
    void cancelAllClick();
    void updateProgress();
    void encodeFinished();
    void writeFile(QString);
    void jobContext(QPoint);

protected:
    void closeEvent(QCloseEvent* event);
};