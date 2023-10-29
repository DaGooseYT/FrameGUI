/****************************************************************************
 * Copyright (C) 2023 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "framegui.hpp"

FrameGUI::FrameGUI(QWidget *parent) : QMainWindow(parent) {
    _ui = new Ui::FrameGUIClass();
    _ui->setupUi(this);
    setupQueue();

    connect(_ui->SelectInBttn, SIGNAL(clicked(bool)), this, SLOT(inputBttn()));
    connect(_ui->SaveOutBttn, SIGNAL(clicked(bool)), this, SLOT(outBttn()));
    connect(_ui->StartEncBttn, SIGNAL(clicked(bool)), this, SLOT(start()));
    connect(_ui->AddJobBttn, SIGNAL(clicked(bool)), this, SLOT(createJob()));
    connect(_ui->CancelQueueBttn, SIGNAL(clicked(bool)), this, SLOT(cancelAllClick()));
    connect(_ui->LicensesBttn, SIGNAL(clicked(bool)), this, SLOT(licenseBttn()));
    connect(_ui->PauseBttn, SIGNAL(clicked(bool)), this, SLOT(pauseClick()));
    connect(_ui->CancelBttn, SIGNAL(clicked(bool)), this, SLOT(cancelMain()));
    connect(_ui->ClearJobsBttn, SIGNAL(clicked(bool)), this, SLOT(clearFinished()));
    connect(_ui->DonateToDaGooseBttn, SIGNAL(clicked(bool)), this, SLOT(donateDaGoose()));
    connect(_ui->YoutubeBttn, SIGNAL(clicked(bool)), this, SLOT(youClick()));
    connect(_ui->DiscordBttn, SIGNAL(clicked(bool)), this, SLOT(disClick()));
    connect(_ui->InstaBttn, SIGNAL(clicked(bool)), this, SLOT(igClick()));
    connect(_ui->UpscaleSetGB, SIGNAL(toggled(bool)), this, SLOT(upscaleSet()));
    connect(_ui->InterpSetGB, SIGNAL(toggled(bool)), this, SLOT(convertSet()));
    connect(_ui->ClearBttn, SIGNAL(clicked(bool)), this, SLOT(clearBttn()));
    #ifdef VERIFY
    connect(_ui->RegistrationBttn, SIGNAL(clicked(bool)), this, SLOT(verifyClick()));
    #endif

    _ffloader = new FFLoader();
    _inputBttn = new QList<QPushButton*>();
    _outputBttn = new QList<QPushButton*>();
    _logsBttn = new QList<QPushButton*>();
    _job = new QStringList();
    _gpuNames = new QStringList();
    _inputList = new QStringList();
    _outputList = new QStringList();
    _tempList = new QStringList();
    _state = new QStringList();

    _fileStream = new QStringList();
    _logFile = new QFile();

    connect(_ffloader, SIGNAL(setVideoInfo()), this, SLOT(regexFinished()));
    connect(_ffloader, SIGNAL(setProgress()), this, SLOT(updateProgress()));
    connect(_ffloader, SIGNAL(completed()), this, SLOT(encodeFinished()));
    connect(_ffloader, SIGNAL(logs(QString)), this, SLOT(writeFile(QString)));

    connect(new QShortcut(QKeySequence(Qt::Key_F1), this), &QShortcut::activated, []() { QDesktopServices::openUrl(QUrl("https://encodegui.com/support")); });

    gpuFinished();
    updater();
    loadSysSetting();

    FOR_EACH(_arguments.count()) {
        _ui->JobQueue->insertRow(_ui->JobQueue->rowCount());

        #ifdef Q_OS_WINDOWS
        bool checkVsScript = Checks::checkVsScript(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1\\%1.vpy")).arg(_job->at(i))) && Checks::checkInput(_inputList->at(i));
        #endif
        #ifdef Q_OS_DARWIN
        bool checkVsScript = Checks::checkVsScript(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1/%1.vpy")).arg(_job->at(i))) && Checks::checkInput(_inputList->at(i));
        #endif

        if (checkVsScript) {
            _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 0, new QTableWidgetItem(_job->at(i)));
            _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 1, new QTableWidgetItem(_state->at(i)));

            if (_state->at(i).contains(QString("Finished")))
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 2, new QTableWidgetItem(QString("100%")));
            else
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 2, new QTableWidgetItem(QString("0%")));

            bttns();

            for (int i = 0; i < 3; i++)
                _ui->JobQueue->item(_ui->JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);
        }
        else {
            _ui->JobQueue->removeRow(i);

            _arguments.removeAt(i);

            #ifdef Q_OS_WINDOWS
            _vapourScript.removeAt(i);
            #endif

            _tempList->removeAt(i);
            _audioArgs.removeAt(i);
            _outputList->removeAt(i);
            _inputList->removeAt(i);
            _state->removeAt(i);

            #ifdef Q_OS_WINDOWS
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif
            #ifdef Q_OS_DARWIN
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif

            _job->removeAt(i);

            VideoInfoList::removeDuration(i);
            VideoInfoList::removeFrameRate(i);

            i--;
        }
    }

    saveSettings();
    setJobSetting();
}

void FrameGUI::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);

    #ifdef Q_OS_WINDOWS
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libssl-1_1-x64.dll"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Required dependency \"libssl-1_1-x64.dll\" is missing in the FrameGUI installation folder. A clean install (uninstall + reinstall) should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libcrypto-1_1-x64.dll"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Required dependency \"libcrypto-1_1-x64.dll\" is missing in the FrameGUI installation folder. A clean install (uninstall + reinstall) should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\tls\\qopensslbackend.dll"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Required dependency \"qopensslbackend.dll\" is missing in the FrameGUI installation folder. A clean install (uninstall + reinstall) should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    #endif
    #ifdef Q_OS_DARWIN
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/../PlugIns/tls/libqsecuretransportbackend.dylib"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Required dependency \"libqsecuretransportbackend.dylib\" is missing in the FrameGUI installation folder. A clean install (uninstall + reinstall) should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    #endif
}

void FrameGUI::jobBttn() {
    int row = sender()->property("row").toInt();
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Info, QString("Job %1 input").arg(_job->at(row)), QString("Path: \"%1\"").arg(_inputList->at(row)), QMessageBox::Open, QMessageBox::Ok, QMessageBox::NoButton));

    if (msg == QMessageBox::Open)
        QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(_inputList->at(row))));
}

void FrameGUI::jobBttn2() {
    int row = sender()->property("row").toInt();
    QMessageBox::StandardButton bttn;

    if (QFile(_outputList->at(row)).exists() && _state->at(row).contains(QString("Finished")))
        bttn = QMessageBox::Open;
    else
        bttn = QMessageBox::NoButton;
    
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Info, QString("Job %1 output").arg(_job->at(row)), QString("Path: \"%1\"").arg(_outputList->at(row)), QMessageBox::Ok, bttn, QMessageBox::NoButton));

    if (msg == QMessageBox::Open)
        QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(_outputList->at(row))));
}

void FrameGUI::updater() {
    QNetworkRequest req;
    req.setUrl(QUrl("http://encodegui.com/updatef.txt"));
    req.setHeader(QNetworkRequest::UserAgentHeader, QString("FrameGUI Updater"));

    QNetworkAccessManager *nam(new QNetworkAccessManager());
    QNetworkReply *reply(nam->get(req));

    connect(reply, SIGNAL(finished()), this, SLOT(updaterFinished()));
}

void FrameGUI::reIndexBttns() {
    _logsBttn->clear();
    _outputBttn->clear();
    _inputBttn->clear();

    FOR_EACH(_arguments.count()) {
        QPushButton *jobButtn(new QPushButton(QString("See path"), _ui->JobQueue));
        QPushButton *jobButtn2(new QPushButton(QString("See path"), _ui->JobQueue));
        QPushButton *logButtn(new QPushButton(QString("Open"), _ui->JobQueue));

        #ifdef Q_OS_DARWIN
        jobButtn->setGeometry(QRect(0, 0, 108, 30));
        jobButtn->setMinimumWidth(50);
        jobButtn->setMinimumHeight(32);
        jobButtn->setMaximumHeight(32);
        jobButtn->setFocusPolicy(Qt::NoFocus);
        jobButtn2->setGeometry(QRect(0, 0, 108, 30));
        jobButtn2->setMinimumWidth(50);
        jobButtn2->setMinimumHeight(32);
        jobButtn2->setMaximumHeight(32);
        jobButtn2->setFocusPolicy(Qt::NoFocus);
        logButtn->setGeometry(QRect(0, 0, 108, 30));
        logButtn->setMinimumWidth(50);
        logButtn->setMinimumHeight(32);
        logButtn->setMaximumHeight(32);
        logButtn->setFocusPolicy(Qt::NoFocus);
        #endif

        _ui->JobQueue->removeCellWidget(i, 3);
        jobButtn->setProperty("row", i);
        connect(jobButtn, SIGNAL(clicked(bool)), this, SLOT(jobBttn()));
        _ui->JobQueue->setCellWidget(i, 3, jobButtn);

        _ui->JobQueue->removeCellWidget(i, 4);
        jobButtn2->setProperty("row", i);
        connect(jobButtn2, SIGNAL(clicked(bool)), this, SLOT(jobBttn2()));
        _ui->JobQueue->setCellWidget(i, 4, jobButtn2);

        _ui->JobQueue->removeCellWidget(i, 5);
        logButtn->setProperty("row", i);
        connect(logButtn, SIGNAL(clicked(bool)), this, SLOT(openJobLogs()));
        _ui->JobQueue->setCellWidget(i, 5, logButtn);

        _inputBttn->append(jobButtn);
        _outputBttn->append(jobButtn2);
        _logsBttn->append(logButtn);
    }
}

void FrameGUI::updaterFinished() {
    if (qobject_cast<QNetworkReply*>(sender())->error() == QNetworkReply::NoError) {
        QString output;
        QStringList lst;
        QTextStream stream(qobject_cast<QNetworkReply*>(sender()));

        bool newUp = false;

        while (!stream.atEnd()) {
            output = stream.readLine();

            if (output.contains(QString("Version=")))
                if (!output.contains(VERSION) && !output.contains(QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).value(QString("update"), VERSION).toString()))
                    newUp = true;
                else {
                    _version = output.remove(QString("Version="));
                    break;
                }

            if (!output.contains(QString("Version=")))
                lst << output;
            else
                _version = output.remove(QString("Version="));
        }

        if (newUp) {
            _update = new Update(this);
            _update->setText(lst.join(QString("\n")));
            _update->show();
            _update->activateWindow();

            connect(_update->getSkip(), SIGNAL(clicked(bool)), this, SLOT(skip()));
            connect(_update->getNow(), SIGNAL(clicked(bool)), this, SLOT(goToUpdate()));
            connect(_update->getLater(), SIGNAL(clicked(bool)), this, SLOT(later()));
        }
    }
    else
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Unable to check for updates due to a network error:\n") + qobject_cast<QNetworkReply*>(sender())->errorString(), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

    delete(sender());
}

void FrameGUI::skip() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("update"), _version);
    _update->close();
    delete(_update->getUpdate());
    delete(_update);
}

void FrameGUI::goToUpdate() {
    QDesktopServices::openUrl(QUrl("https://encodegui.com/downloads"));
    _update->close();
    delete(_update->getUpdate());
    delete(_update);
}

void FrameGUI::later() {
    _update->close();
    delete(_update->getUpdate());
    delete(_update);
}

void FrameGUI::inputBttn() {
    VideoInfoRegex::_durationLine.clear();

    #ifdef Q_OS_WINDOWS
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\ffprobe.exe")));
    #endif
    #ifdef Q_OS_DARWIN
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe")));
    #endif

    QString input(QFileDialog::getOpenFileName(this, QString("Select Input"), _ui->SelectInTxtBox->text(), QString("All files (*.*)")));

    if (input.isEmpty() && !_ui->SelectInTxtBox->text().isEmpty())
        input = _ui->SelectInTxtBox->text();

    getVideoInfo(QDir::toNativeSeparators(input), ffprobe);
}

void FrameGUI::getVideoInfo(QString input, QString ffprobe) {
    _ui->SelectInTxtBox->setText(input);

    VideoInfo::clearAll();
    AudioInfo::clearAll();
    SubtitleInfo::clearAll();

    if (!_ui->SelectInTxtBox->text().isEmpty())
        _ffloader->videoInfo(QStringList() << QString("-i") << input, ffprobe);
}

void FrameGUI::regexFinished() {
    if (VideoInfo::getVideoCodec().contains(QString("?"))) {
        msgBoxHelper(MessageType::Error, QString("Import file error"), QString("The selected input file is not a video. Only select video files as the input.\n"), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _ui->SelectInTxtBox->setText(QString());
    }
    else if (VideoInfo::getDurationStrng().contains(QString("?")) && !VideoInfo::getVideoCodec().contains(QString("?")))
        msgBoxHelper(MessageType::Error, QString("Input Error"), QString("FrameGUI was unable to find the duration of the selected video file. As a result, encoding progress info for this source will be limited."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void FrameGUI::dragEnterEvent(QDragEnterEvent* d) {
    const QMimeData* md(d->mimeData());

    if (md->hasUrls())
        d->acceptProposedAction();
}

void FrameGUI::dropEvent(QDropEvent* d) {
    const QMimeData* md(d->mimeData());

    QList<QUrl> urlList(md->urls());
    
    #ifdef Q_OS_WINDOWS
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\ffprobe.exe")));
    #endif
    #ifdef Q_OS_DARWIN
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe")));
    #endif

    getVideoInfo(QDir::toNativeSeparators(urlList.at(0).toLocalFile()), ffprobe);
}

void FrameGUI::upscaleSet() {
    if (_ui->UpscaleSetGB->isChecked())
        SET_DISABLED(_ui->InterpSetGB);
    else
        SET_ENABLED(_ui->InterpSetGB);
}

void FrameGUI::convertSet() {
    if (_ui->InterpSetGB->isChecked())
        SET_DISABLED(_ui->UpscaleSetGB);
    else
        SET_ENABLED(_ui->UpscaleSetGB);
}

void FrameGUI::updateProgress() {
    _ui->EncodeProgress->setMaximum(100);

    if (!ProcessError::getVkMemoryError() && !ProcessError::getVkQueueError()) {
        QString progress;

        if (!_encodingAudio) {
            progress.append(QString("Job %1/%2").arg(_ffloader->_currentJob + 1).arg(_ui->JobQueue->rowCount()));
            progress.append(QString(" - "));
            progress.append(QString("FPS: %1").arg(ProgressInfo::getFps()));
            progress.append(QString(", "));

            if (ProgressInfo::getTimeElapsed().isValid())
                progress.append(QString("Time elapsed: %1").arg(ProgressInfo::getTimeElapsed().toString()));
            else
                progress.append(QString("Time elapsed: > day"));

            if (VideoInfoList::getDuration(_ffloader->_currentJob).isValid()) {
                progress.append(QString(", "));

                if (ProgressInfo::getTimeLeft().isValid())
                    progress.append(QString("Time left: %1").arg(ProgressInfo::getTimeLeft().toString()));
                else
                    progress.append(QString("Time left: > day"));

                progress.append(QString(" - "));
                progress.append(QString("%1%").arg(ProgressInfo::getPercentage()));
            }
        }
        else {
            progress.append(QString("Job %1/%2 - ").arg(_ffloader->_currentJob + 1).arg(_ui->JobQueue->rowCount()));
            progress.append(QString("Audio and/or Subtitle muxing"));
            progress.append(QString(" - %1%").arg(ProgressInfo::getPercentage()));
        }

        if (VideoInfoList::getDuration(_ffloader->_currentJob).isValid()) {
            _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("%1%").arg(ProgressInfo::getPercentage()));
            _ui->EncodeProgress->setValue((int)ProgressInfo::getPercentage());
            _ui->EncodeProgress->repaint();
        }

        _ui->ProgressBarLabel->setText(progress);
    }
    else {
        _ffloader->killProcess(_ffloader->_encode);
        _ffloader->killProcess(_ffloader->_vs);
    }
}

void FrameGUI::outBttn() {
    QString output(QDir::toNativeSeparators(QFileDialog::getSaveFileName(this, QString("Save Output File"), _ui->SelectInTxtBox->text().left(_ui->SelectInTxtBox->text().lastIndexOf(QString("."))), QString("Supported extensions"))));

    if (output.isEmpty() && !_ui->SaveOutTxtBox->text().isEmpty())
        output = _ui->SaveOutTxtBox->text();

    _ui->SaveOutTxtBox->setText(output);
}

void FrameGUI::cancelAllClick() {
    if (_ui->JobQueue->rowCount() == 0)
        return;

    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Cancel confirmation"), QString("Are you sure you want to cancel ALL jobs? All curent progress of the current job process will be lost."), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::Yes) {
        FOR_EACH(_ui->JobQueue->rowCount())
            if (!_ui->JobQueue->item(i, 1)->text().contains(QString("Paused")) && !_ui->JobQueue->item(i, 1)->text().contains(QString("Active"))) {
                _ui->JobQueue->item(i, 1)->setText(QString("Canceled"));
                _state->replace(i, QString("Canceled"));
            }
            else if (_ui->JobQueue->item(i, 1)->text().contains(QString("Paused")))
                msgBoxHelper(MessageType::Warning, QString("Warning"), QString("The currently paused process could not be canceled. Please resume it first then cancel it."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

        if (_ffloader->_encode && _ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Active")))
            if (_ffloader->_encode->state() == QProcess::Running) {
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Canceled"));
                _state->replace(_ffloader->_currentJob, QString("Canceled"));

                _ffloader->closeProcess(_ffloader->_encode);

                if (_ffloader->_vs)
                    _ffloader->closeProcess(_ffloader->_vs);
            }

        if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Paused"))) {
            _ui->ProgressBarLabel->setText(QString());
            _ui->EncodeProgress->setValue(0);
        }

        setState();
    }
}

void FrameGUI::resetJob() {
    _ui->JobQueue->item(_selectedJob, 1)->setText(QString("Waiting"));
    _state->replace(_selectedJob, QString("Waiting"));

    setState();

    delete(sender());
}

void FrameGUI::removeJob() {
    if (_selectedJob == _ffloader->_currentJob || _ui->JobQueue->item(_selectedJob, 1)->text().contains(QString("Paused"))) {
        if (_ffloader->_encode && _ffloader->_encode->state() == QProcess::Running) {
            msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Please cancel the current job before removing it from the queue."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            return;
        }
    }

    _arguments.removeAt(_selectedJob);

    #ifdef Q_OS_WINDOWS
    _vapourScript.removeAt(_selectedJob);
    #endif

    _tempList->removeAt(_selectedJob);
    _audioArgs.removeAt(_selectedJob);
    _outputList->removeAt(_selectedJob);
    _inputList->removeAt(_selectedJob);
    _state->removeAt(_selectedJob);

    delete(_inputBttn->at(_selectedJob));
    delete(_outputBttn->at(_selectedJob));
    delete(_logsBttn->at(_selectedJob));
    _inputBttn->removeAt(_selectedJob);
    _outputBttn->removeAt(_selectedJob);
    _logsBttn->removeAt(_selectedJob);

    VideoInfoList::removeDuration(_selectedJob);
    VideoInfoList::removeFrameRate(_selectedJob);

    _ui->JobQueue->removeRow(_selectedJob);

    if (_ffloader->_currentJob != 0)
        FOR_EACH(_ui->JobQueue->rowCount())
        if (_ui->JobQueue->item(i, 1)->text().contains(QString("Active")) || _ui->JobQueue->item(i, 1)->text().contains(QString("Paused")))
            _ffloader->_currentJob = i;

    #ifdef Q_OS_WINDOWS
    QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(_selectedJob))).removeRecursively();
    #endif
    #ifdef Q_OS_DARWIN
    QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(_selectedJob))).removeRecursively();
    #endif

    _job->removeAt(_selectedJob);

    reIndexBttns();
    saveSettings();
    setJobSetting();

    delete(sender());
}

void FrameGUI::clearFinished() {
    FOR_EACH(_arguments.count())
        if (_ui->JobQueue->item(i, 1)->text().contains(QString("Finished"))) {
            _ui->JobQueue->removeRow(i);

            _arguments.removeAt(i);

            #ifdef Q_OS_WINDOWS
            _vapourScript.removeAt(i);
            #endif

            _tempList->removeAt(i);
            _audioArgs.removeAt(i);
            _outputList->removeAt(i);
            _inputList->removeAt(i);
            _state->removeAt(i);

            delete(_inputBttn->at(i));
            delete(_outputBttn->at(i));
            delete(_logsBttn->at(i));
            _inputBttn->removeAt(i);
            _outputBttn->removeAt(i);
            _logsBttn->removeAt(i);

            #ifdef Q_OS_WINDOWS
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif
            #ifdef Q_OS_DARWIN
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif

            _job->removeAt(i);

            VideoInfoList::removeDuration(i);
            VideoInfoList::removeFrameRate(i);

            i--;
        }

    if (_ffloader->_currentJob != 0)
        FOR_EACH(_arguments.count())
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Active")) || _ui->JobQueue->item(i, 1)->text().contains(QString("Paused")))
                _ffloader->_currentJob = i;

    reIndexBttns();
    saveSettings();
    setJobSetting();
}

void FrameGUI::cancelMain() {
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Cancel confirmation"), QString("Are you sure you want to cancel the currently active job? All progress will be lost."), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::Yes) {
        if (_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Active"))) {
            _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Canceled"));
            _state->replace(_ffloader->_currentJob, QString("Canceled"));

            _ffloader->closeProcess(_ffloader->_encode);

            if (_ffloader->_vs)
                _ffloader->closeProcess(_ffloader->_vs);

            setState();
        }
        else
            msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("A job must be active to cancel it."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void FrameGUI::cancelClick() {
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Cancel confirmation"), QString("Are you sure you want to cancel the selected job? All progress will be lost."), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::Yes) {
        if (_ui->JobQueue->item(_selectedJob, 1)->text().contains(QString("Active"))) {
            _ui->JobQueue->item(_selectedJob, 1)->setText(QString("Canceled"));

            if (_selectedJob == _ffloader->_currentJob) {
                _ffloader->closeProcess(_ffloader->_encode);

                if (_ffloader->_vs)
                    _ffloader->closeProcess(_ffloader->_vs);
            }

            _state->replace(_selectedJob, QString("Canceled"));
            setState();
        }
        else
            msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("A job must be active to cancel it."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }

    delete(sender());
}

void FrameGUI::pauseClick() {
    if (_ui->PauseBttn->text().contains(QString("Pause"))) {
        _ui->PauseBttn->setText(QString("Resume"));
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Paused"));
        _ui->JobStatusValueLabel->setText(QString("Paused"));

        _ffloader->pauseProcess(_ffloader->_encode, true);
        *_ffloader->_pauseTime = ProgressInfo::getTimeElapsed();
    }
    else {
        _ui->PauseBttn->setText(QString("Pause"));
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Active"));
        _ui->JobStatusValueLabel->setText(QString("Active"));

        _ffloader->pauseProcess(_ffloader->_encode, false);
        _ffloader->_timer->restart();
    }
}

void FrameGUI::start() {
    int jobs = _ui->JobQueue->rowCount(), count = 0;

    _encodingAudio = false;

    if (jobs > 0) {
        FOR_EACH(jobs)
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting"))) {
                _ffloader->_currentJob = i;
                SET_ENABLED(_ui->PauseBttn);
                SET_ENABLED(_ui->CancelBttn);
                SET_DISABLED(_ui->StartEncBttn);

                _ui->JobQueue->item(i, 1)->setText(QString("Active"));

                newTask();

                paletter(_ui->JobStatusValueLabel);
                _ui->JobStatusValueLabel->setText(QString("Active"));

                paletter(_ui->JobIDValueLabel);
                _ui->JobIDValueLabel->setText(_ui->JobQueue->item(i, 0)->text());

                count++;
                break;
            }
    }

    if (jobs == 0 || count == 0)
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("There are no waiting jobs in the queue."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void FrameGUI::newTask() {
    #ifdef Q_OS_WINDOWS
    QString fileName(LOGPATH_WIN);
    #endif
    #ifdef Q_OS_DARWIN
    QString fileName(LOGPATH_DAR);
    #endif

    if (Checks::checkInputExists(_inputList->at(_ffloader->_currentJob))) {
        QString deps(checkEnviornment());

        if (deps != QString()) {
            QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Required dependency \"%1\" is missing in the FrameGUI installation folder. A clean install (uninstall + reinstall) of FrameGUI should fix this.").arg(deps), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));
            if (msg == QMessageBox::Help)
                QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

            QApplication::quit();
            return;
        }

        ProcessError::clearAll();
        ProcessErrorRegex::clearBools();

        if (QFile(_outputList->at(_ffloader->_currentJob)).exists())
            QFile(_outputList->at(_ffloader->_currentJob)).remove();
        
        if (!QDir(QDir::toNativeSeparators(fileName + QString("\\job-%1")).arg(_job->at(_ffloader->_currentJob))).exists())
            QDir().mkpath(QDir::toNativeSeparators(fileName + QString("\\job-%1")).arg(_job->at(_ffloader->_currentJob)));

        _logFile->close();
        _logFile->setFileName(QDir::toNativeSeparators(fileName + QString("\\job-%1\\ProcessLogs-%1.txt")).arg(_job->at(_ffloader->_currentJob)));

        _logFile->open(QIODevice::WriteOnly);
        _fileStream->clear();

        *_fileStream << QString("#================================================#");
        *_fileStream << QString("FrameGUI process logs for job %1").arg(_job->at(_ffloader->_currentJob));

        #ifdef Q_OS_WINDOWS
        *_fileStream << QString("Video encoding arguments: %1 %2 | %3 %4").arg(VSPIPEPATH).arg(_vapourScript.at(_ffloader->_currentJob).toStringList().join(QString(" "))).arg(FFMPEGPATH_WIN).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")));
        *_fileStream << QString("Audio encoding arguments: %1 %2").arg(FFMPEGPATH_WIN).arg(_audioArgs.at(_ffloader->_currentJob).toStringList().join(QString(" ")));
        #endif
        #ifdef Q_OS_DARWIN
        *_fileStream << QString("Video encoding arguments: %1 %2").arg(FFMPEGPATH_DAR).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")));
        *_fileStream << QString("Audio encoding arguments: %1 %2").arg(FFMPEGPATH_DAR).arg(_audioArgs.at(_ffloader->_currentJob).toStringList().join(QString(" ")));
        #endif

        *_fileStream << QString("#================================================#\n");

        #ifdef Q_OS_WINDOWS
        bool checkVS = Checks::checkVsScript(QDir::toNativeSeparators(fileName + QString("\\job-%1\\%1.vpy")).arg(_job->at(_ffloader->_currentJob)));
        #endif
        #ifdef Q_OS_DARWIN
        bool checkVS = Checks::checkVsScript(QDir::toNativeSeparators(fileName + QString("/job-%1/%1.vpy")).arg(_job->at(_ffloader->_currentJob)));
        #endif

        if (checkVS) {
            #ifdef Q_OS_WINDOWS
            _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), _vapourScript.at(_ffloader->_currentJob).toStringList(), FFMPEGPATH_WIN, VSPIPEPATH);
            #endif
            #ifdef Q_OS_DARWIN
            _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_DAR, QString());
            #endif
        }
        else {
            msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Could not find VapourSynth script for job id: %1\nExiting job.").arg(_job->at(_ffloader->_currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
            encodeFinished();
        }

        _ui->ProgressBarLabel->setText(QString("Initializing components... (this may take some time)"));
        _ui->EncodeProgress->setMaximum(0);
    }
    else {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("The source video file at \"%1\" is missing or does not exist.").arg(_inputList->at(_ffloader->_currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
        *_fileStream << QString("FrameGUI error: could not find source file for job %1.").arg(_job->at(_ffloader->_currentJob));
        encodeFinished();
    }
}

void FrameGUI::closeEvent(QCloseEvent* event) {
    if (_ffloader->_encode && _ffloader->_encode->state() == QProcess::Running) {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Please cancel the current active job before closing FrameGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        event->ignore();
    }
    else if (_ffloader->_encode)
        if (_ffloader->_encode->state() == QProcess::NotRunning)
            event->accept();
        else
            event->accept();
}

void FrameGUI::encodeFinished() {
    #ifdef Q_OS_WINDOWS
    QFile(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.lwi").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif
    #ifdef Q_OS_DARWIN
    QFile(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1.ffindex").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif

    _ui->EncodeProgress->setMaximum(100);
    _ui->ProgressBarLabel->setText(QString());
    _ui->EncodeProgress->setValue(0);

    QMessageBox::StandardButton msg;

    if (ProcessError::error()) {
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
        _state->replace(_ffloader->_currentJob, QString("Failed"));

        if (ProcessError::getVkMemoryError())
            msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Failed to allocate memory for the current process. Your GPU many not be supported. Click \"Open\" below to see the associated job logs."), QMessageBox::Open, QMessageBox::NoButton, QMessageBox::NoButton);
        if (ProcessError::getVkQueueError() && !ProcessError::getVkMemoryError())
            msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Failed to queue the current process. Add registry keys to delay the queue submit timeout (see https://encodegui.com/support for directions)."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        if (ProcessError::getNcnnError())
            msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Failed to start the current process.\nYour GPU may not be supported or your GPU drivers may be outdated."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

        if (msg == QMessageBox::Open)
            openLogs();

        setState();
    }
    else if (ProcessError::getPipeError()) {
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
        _state->replace(_ffloader->_currentJob, QString("Failed"));

        msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("An unknown error occured with the current process. Click \"Open\" below to see the associated process logs."), QMessageBox::Ok, QMessageBox::Open, QMessageBox::NoButton);

        if (msg == QMessageBox::Open)
            openLogs();

        setState();
    }
    else if (_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Failed"))) {
        msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("An unknown error occured with the current process. Click \"Open\" below to open the current job's logs."), QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

        if (msg == QMessageBox::Open)
            openLogs();
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

        _state->replace(_ffloader->_currentJob, QString("Failed"));
        setState();
    }
    else if (_audioArgs.at(_ffloader->_currentJob) != QString("noa") && (!QFile(_tempList->at(_ffloader->_currentJob)).exists() || QFile(_tempList->at(_ffloader->_currentJob)).size() < 100000) && !_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Canceled"))) {
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));

        msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("An unknown error occured with the current process. Click \"Open\" below to open the current job's logs."), QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

        if (msg == QMessageBox::Open)
            openLogs();
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

        _state->replace(_ffloader->_currentJob, QString("Failed"));
        setState();
    }
    else {
        if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Canceled"))) {
            if (!QFile(_outputList->at(_ffloader->_currentJob)).exists() && !_encodingAudio && _audioArgs.at(_ffloader->_currentJob) != QString("noa")) {
                *_fileStream << QString("\n#================================================#");
                *_fileStream << QString("Begin audio encoding");
                *_fileStream << QString("#================================================#\n");

                #ifdef Q_OS_WINDOWS
                _ffloader->encode(_audioArgs.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_WIN, QString());
                #endif
                #ifdef Q_OS_DARWIN
                _ffloader->encode(_audioArgs.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_DAR, QString());
                #endif

                _encodingAudio = true;

                return;
            }
            else if ((!QFile(_outputList->at(_ffloader->_currentJob)).exists() || QFile(_outputList->at(_ffloader->_currentJob)).size() < 10000) && _audioArgs.at(_ffloader->_currentJob) == QString("noa")) {
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));

                msg = msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("An unknown error occured with the current process. Click \"Open\" below to open the current job's logs."), QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

                if (msg == QMessageBox::Open)
                    openLogs();
                if (msg == QMessageBox::Help)
                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

                _state->replace(_ffloader->_currentJob, QString("Failed"));
                setState();
            }
            else if (_encodingAudio && (!QFile(_outputList->at(_ffloader->_currentJob)).exists() || QFile(_outputList->at(_ffloader->_currentJob)).size() < 10000)) {
                _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("0%"));
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));

                QMessageBox::StandardButton sb(msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Audio/subtitle muxing failed. Click \"Open\" below to see the associated process logs."),
                    QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help));

                if (sb == QMessageBox::Open)
                    openLogs();
                if (sb == QMessageBox::Help)
                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

                _state->replace(_ffloader->_currentJob, QString("Failed"));
                setState();
            }
            else {
                _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("100%"));
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Finished"));

                _state->replace(_ffloader->_currentJob, QString("Finished"));
                setState();
            }
        }
    }

    _encodingAudio = false;
    delete(_ffloader->_pauseTime);

    if (!_fileStream->isEmpty() && _logFile->exists()) {
        *_fileStream << QString("\n#================================================#");
        *_fileStream << QString("End of logs");
        *_fileStream << QString("#================================================#");

        QTextStream stream(_logFile);

        foreach(QString line, *_fileStream)
            stream << line + QString("\n");

        _logFile->close();
        _fileStream->clear();
    }

    newJob();
}

void FrameGUI::bttns() {
    QPushButton *jobButtn(new QPushButton(QString("See path"), _ui->JobQueue));
    QPushButton *jobButtn2(new QPushButton(QString("See path"), _ui->JobQueue));
    QPushButton *logButtn(new QPushButton(QString("Open"), _ui->JobQueue));

    #ifdef Q_OS_DARWIN
    jobButtn->setGeometry(QRect(0, 0, 108, 30));
    jobButtn->setMinimumWidth(50);
    jobButtn->setMinimumHeight(32);
    jobButtn->setMaximumHeight(32);
    jobButtn->setFocusPolicy(Qt::NoFocus);
    jobButtn2->setGeometry(QRect(0, 0, 108, 30));
    jobButtn2->setMinimumWidth(50);
    jobButtn2->setMinimumHeight(32);
    jobButtn2->setMaximumHeight(32);
    jobButtn2->setFocusPolicy(Qt::NoFocus);
    logButtn->setGeometry(QRect(0, 0, 108, 30));
    logButtn->setMinimumWidth(50);
    logButtn->setMinimumHeight(32);
    logButtn->setMaximumHeight(32);
    logButtn->setFocusPolicy(Qt::NoFocus);
    #endif

    jobButtn->setProperty("row", _ui->JobQueue->rowCount() - 1);
    connect(jobButtn, SIGNAL(clicked(bool)), this, SLOT(jobBttn()));
    _ui->JobQueue->setCellWidget(_ui->JobQueue->rowCount() - 1, 3, jobButtn);

    jobButtn2->setProperty("row", _ui->JobQueue->rowCount() - 1);
    connect(jobButtn2, SIGNAL(clicked(bool)), this, SLOT(jobBttn2()));
    _ui->JobQueue->setCellWidget(_ui->JobQueue->rowCount() - 1, 4, jobButtn2);

    logButtn->setProperty("row", _ui->JobQueue->rowCount() - 1);
    connect(logButtn, SIGNAL(clicked(bool)), this, SLOT(openJobLogs()));
    _ui->JobQueue->setCellWidget(_ui->JobQueue->rowCount() - 1, 5, logButtn);

    _inputBttn->append(jobButtn);
    _outputBttn->append(jobButtn2);
    _logsBttn->append(logButtn);
}

void FrameGUI::newJob() {
    paletter(_ui->JobStatusValueLabel);
    _ui->JobStatusValueLabel->setText(QString("?"));

    paletter(_ui->JobIDValueLabel);
    _ui->JobIDValueLabel->setText(QString("?"));

    #ifdef Q_OS_WINDOWS
    QFile(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif
    #ifdef Q_OS_DARWIN
    QFile(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1.mkv").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif

    int isDone = 0;

    FOR_EACH(_ui->JobQueue->rowCount())
        if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting")) && !_ui->JobQueue->item(i, 1)->text().contains(QString("Failed")))
            isDone++;

    if (isDone > 0) {
        FOR_EACH(_ui->JobQueue->rowCount())
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting"))) {
                _ffloader->_currentJob = i;
                SET_ENABLED(_ui->PauseBttn);
                SET_ENABLED(_ui->CancelBttn);
                SET_DISABLED(_ui->StartEncBttn);

                _ui->JobQueue->item(i, 1)->setText(QString("Active"));

                paletter(_ui->JobStatusValueLabel);
                _ui->JobStatusValueLabel->setText(QString("Active"));

                paletter(_ui->JobIDValueLabel);
                _ui->JobIDValueLabel->setText(_ui->JobQueue->item(i, 0)->text());

                newTask();

                break;
            }
    }
    else {
        SET_DISABLED(_ui->PauseBttn);
        SET_DISABLED(_ui->CancelBttn);
        SET_ENABLED(_ui->StartEncBttn);

        msgBoxHelper(MessageType::Info, QString("Done processing jobs"), QString("No more jobs to process."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void FrameGUI::gpuFinished() {
    #ifdef Q_OS_WINDOWS
    IDXGIAdapter *adapter;
    IDXGIFactory *factory = NULL;
    DXGI_ADAPTER_DESC desc;

    std::vector<IDXGIAdapter*> videoAdapters;
    CreateDXGIFactory1(__uuidof(IDXGIFactory), (void**)&factory);

    for (UINT i = 0; factory->EnumAdapters(i, &adapter) != DXGI_ERROR_NOT_FOUND; i++)
        videoAdapters.push_back(adapter);

    if (factory)
        factory->Release();

    FOR_EACH(videoAdapters.size()) {
        videoAdapters.at(i)->GetDesc(&desc);

        if (!QString::fromStdWString(desc.Description).toLower().contains(QString("microsoft")) && !QString::fromStdWString(desc.Description).toLower().contains(QString("parsec")))
            _gpuNames->append(QString::fromStdWString(desc.Description));
    }

    if (_gpuNames->size() == 0) {
        msgBoxHelper(MessageType::Error, QString("Critical"), QString("No GPU device detected."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }

    if (adapter)
        adapter->Release();

    this->setWindowTitle(QString("FrameGUI v%1 - [GPU 0: %2]").arg(VERSION).arg(_gpuNames->at(0)));
    #endif
    #ifdef Q_OS_DARWIN
    char buf[100];
    size_t buflen = 100;
    sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

    _gpuNames->append(QString(buf));
    this->setWindowTitle(QString("FrameGUI v%1 - [GPU: %2]").arg(VERSION).arg(_gpuNames->at(0)));
    #endif
}

void FrameGUI::setState() {
    _sState.clear();

    foreach(QString sta, *_state)
        _sState.append(sta);

    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("state"), _sState);
}

void FrameGUI::writeFile(QString output) {
    *_fileStream << output;
}

void FrameGUI::paletter(QLabel* label) {
    QPalette palette(label->palette());
    palette.setColor(label->foregroundRole(), Qt::darkGreen);
    label->setPalette(palette);
}

void FrameGUI::inputClick() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(_inputList->at(_selectedJob)).absolutePath())));
    delete(sender());
}

void FrameGUI::outputClick() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(_outputList->at(_selectedJob)).absolutePath())));
    delete(sender());
}

void FrameGUI::clearBttn() {
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Warning, QString("Warning"), QString("Clearing the saved data will remove ALL inactive jobs in the queue. Continue?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::No)
        return;
    else if (msg == QMessageBox::Yes) {
        FOR_EACH(_arguments.count())
            if (!_ui->JobQueue->item(i, 1)->text().contains(QString("Active")) && !_ui->JobQueue->item(i, 1)->text().contains(QString("Paused"))) {
                _ui->JobQueue->removeRow(i);
                _arguments.removeAt(i);

                #ifdef Q_OS_WINDOWS
                _vapourScript.removeAt(i);
                #endif

                _tempList->removeAt(i);
                _audioArgs.removeAt(i);
                _outputList->removeAt(i);
                _inputList->removeAt(i);
                _state->removeAt(i);

                delete(_inputBttn->at(i));
                delete(_outputBttn->at(i));
                delete(_logsBttn->at(i));
                _inputBttn->removeAt(i);
                _outputBttn->removeAt(i);
                _logsBttn->removeAt(i);

                #ifdef Q_OS_WINDOWS
                QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(i))).removeRecursively();
                #endif
                #ifdef Q_OS_DARWIN
                QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(i))).removeRecursively();
                #endif

                _job->removeAt(i);

                VideoInfoList::removeDuration(i);
                VideoInfoList::removeFrameRate(i);

                i--;
            }

        QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("FrameGUI")).setValue(QString("key"), QVariantList());

        reIndexBttns();
        saveSettings();
        setJobSetting();

        msgBoxHelper(MessageType::Info, QString("Saved data deleted"), QString("Save data was cleared successfully."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void FrameGUI::openLogs() {
    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString(QString("\\job-%1")).arg(_job->at(_ffloader->_currentJob)))));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file://") + QDir::toNativeSeparators(LOGPATH_DAR + QString(QString("/job-%1")).arg(_job->at(_ffloader->_currentJob)))));
    #endif
}

void FrameGUI::openJobLogs() {
    int row = sender()->property("row").toInt();

    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(row)))));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file://") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(row)))));
    #endif
}

void FrameGUI::openOutput() {
    int row = sender()->property("row").toInt();
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(_outputList->at(row)).absolutePath())));
}

void FrameGUI::licenseBttn() {
    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\licenses"))));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/licenses"))));
    #endif
}

void FrameGUI::donateDaGoose() {
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/donate/?hosted_button_id=CLBETTY9GBM28"));
}

void FrameGUI::youClick() {
    QDesktopServices::openUrl(QUrl("https://youtube.com/c/DaGoose"));
}

void FrameGUI::disClick() {
    QDesktopServices::openUrl(QUrl("https://discord.gg/PmcbXJVBNu"));
}

void FrameGUI::igClick() {
    QDesktopServices::openUrl(QUrl("https://www.instagram.com/dagooseyt/"));
}

FrameGUI::~FrameGUI() {
    delete(_job);
    delete(_gpuNames);
    delete(_inputList);
    delete(_outputList);
    delete(_tempList);
    delete(_state);
    delete(_fileStream);
    delete(_logFile);
    delete(_inputBttn);
    delete(_outputBttn);
    delete(_logsBttn);
    delete(_ffloader);
    delete(_ui);
}