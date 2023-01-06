#pragma once

#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"
#include <QtWidgets/QMainWindow>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>
#include <QMimeData>
#include <QProcess>
#include <QAction>
#include <QMenu>

#include "../Process/ScriptBuilder.h"
#include "../Process/MediaConfig.h"
#include "../Process/FFLoader.h"
#include "../Checks/Checks.h"
#include "../IO/AudioInfo.h"
#include "../IO/SubtitleInfo.h"
#include "ui_FrameGUI.h"
#include "Update.h"

#define FOR_EACH(total) for (int i = 0; i < total; i++)
#define SET_ENABLED(control) (control->setEnabled(true))
#define SET_DISABLED(control) (control->setEnabled(false))
#define SET_VISIBLE(control) (control->setVisible(true))
#define SET_INVISIBLE(control) (control->setVisible(false))
#define CHECKED(control) (control->isChecked())

#define ERROR 0
#define WARNING 1
#define INFO 2
#define QUESTION 3

#define VERSION (QString("2.0.0"))

class FrameGUI : public QMainWindow
{
    Q_OBJECT

public:
    FrameGUI(QWidget *parent = Q_NULLPTR);
    ~FrameGUI();

    enum MessageType {
        Error = 0,
        Warning = 1,
        Info = 2,
        Question = 3
    };

    QStringList arguments;
    QStringList job;
    QStringList vapourScript;
    QStringList inputList;
    QStringList outputList;
    QStringList tempList;
    QStringList state;

    QVariantList Varguments;
    QVariantList Vjob;
    QVariantList VvapourScript;
    QVariantList VinputList;
    QVariantList VoutputList;
    QVariantList VtempList;
    QVariantList Vstate;
    QVariantList Vduration;
    QVariantList VaudioArgs;
    QVariantList VframeRate;

    QMessageBox::StandardButton MsgBoxHelper(MessageType, QString, QString, QMessageBox::StandardButton, QMessageBox::StandardButton, QMessageBox::StandardButton);

private:
    Ui::FrameGUIClass ui;

    int selectedJob;
    QStringList FileStream;
    QStringList AudioArgs;

    QFile LogFile;
    FFLoader* ffloader;
    
    void LoadSysSetting();
    void GetVideoInfo(QString, QString);
    void SaveSettings();
    void SetJobSetting();
    void setup_queue();
    void NewJob();
    void NewTask();
    void SetState();
    void Updater();
    void Paletter(QLabel*);
    void dragEnterEvent(QDragEnterEvent* d);
    void dropEvent(QDropEvent* d);

    QString ConfigureVS(QString);
    QString BuildScript(int, int, QString);
    QString ConfigureAudioP(int, QString, QString);
    QString ConfigureArgs(QString, QString);

    int DecimalCounter(QString);

private slots:
    void UpdaterFinished();
    void input_bttn();
    void DonateDaGoose();
    void PatreonClick();
    void CancelClick();
    void PauseClick();
    void CreateJob();
    void CancelMain();
    void ClearFinished();
    void OpenOutput();
    void UpscaleSet();
    void ConvertSet();
    void OutBttn();
    void OpenJobLogs();
    void YouClick();
    void DisClick();
    void IgClick();
    void RemoveJob();
    void InputClick();
    void Start();
    void Skip();
    void GoToUpdate();
    void Later();
    void ResetJob();
    void RegexFinished();
    void CancelAllClick();
    void UpdateProgress();
    void EncodeFinished();
    void WriteFile(QString);
    void JobContext(QPoint);

protected:
    void closeEvent(QCloseEvent*);
};
