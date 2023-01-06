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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "FrameGUI.h"

FFLoader* ffloader;
Update* up;

QString vers;
QFile LogFile;

int selectedJob;
bool EncodingAudio;

FrameGUI::FrameGUI(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);
    setup_queue();

    connect(ui.SelectInBttn, SIGNAL(clicked(bool)), this, SLOT(input_bttn()));
    connect(ui.SaveOutBttn, SIGNAL(clicked(bool)), this, SLOT(OutBttn()));
    connect(ui.StartEncBttn, SIGNAL(clicked(bool)), this, SLOT(Start()));
    connect(ui.AddJobBttn, SIGNAL(clicked(bool)), this, SLOT(CreateJob()));
    connect(ui.CancelQueueBttn, SIGNAL(clicked(bool)), this, SLOT(CancelAllClick()));
    connect(ui.PauseBttn, SIGNAL(clicked(bool)), this, SLOT(PauseClick()));
    connect(ui.CancelBttn, SIGNAL(clicked(bool)), this, SLOT(CancelMain()));
    connect(ui.ClearJobsBttn, SIGNAL(clicked(bool)), this, SLOT(ClearFinished()));
    connect(ui.DonateToDaGooseBttn, SIGNAL(clicked(bool)), this, SLOT(DonateDaGoose()));
    connect(ui.PatreonBttn, SIGNAL(clicked(bool)), this, SLOT(PatreonClick()));
    connect(ui.YoutubeBttn, SIGNAL(clicked(bool)), this, SLOT(YouClick()));
    connect(ui.DiscordBttn, SIGNAL(clicked(bool)), this, SLOT(DisClick()));
    connect(ui.InstaBttn, SIGNAL(clicked(bool)), this, SLOT(IgClick()));
    connect(ui.UpscaleSetGB, SIGNAL(toggled(bool)), this, SLOT(UpscaleSet()));
    connect(ui.InterpSetGB, SIGNAL(toggled(bool)), this, SLOT(ConvertSet()));

    ffloader = new FFLoader();
                   
    connect(ffloader, SIGNAL(setVideoInfo()), this, SLOT(RegexFinished()));
    connect(ffloader, SIGNAL(setProgress()), this, SLOT(UpdateProgress()));
    connect(ffloader, SIGNAL(Completed()), this, SLOT(EncodeFinished()));
    connect(ffloader, SIGNAL(Logs(QString)), this, SLOT(WriteFile(QString)));

    LoadSysSetting();

    FOR_EACH(arguments.count()) {
        ui.JobQueue->insertRow(ui.JobQueue->rowCount());

        if (Checks::CheckVsScript(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1\\%1.vpy").arg(job.at(i)))) && Checks::CheckInput(inputList.at(i))) {
            ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 0, new QTableWidgetItem(job.at(i)));
            ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 1, new QTableWidgetItem(state.at(i)));

            if (state.at(i).contains("Finished"))
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 2, new QTableWidgetItem("100%"));
            else
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 2, new QTableWidgetItem("0%"));

            ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 3, new QTableWidgetItem(outputList.at(i)));

            for (int i = 0; i < 3; i++)
                ui.JobQueue->item(ui.JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);
        }
        else {
            ui.JobQueue->removeRow(i);

            arguments.removeAt(i);
            vapourScript.removeAt(i);
            tempList.removeAt(i);
            AudioArgs.removeAt(i);
            outputList.removeAt(i);
            inputList.removeAt(i);
            state.removeAt(i);

            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(QDir::homePath()) + QString("\\AppData\\Local\\FrameGUI\\job-%1")).arg(job.at(i))).removeRecursively();

            job.removeAt(i);

            VideoInfoList::RemoveDuration(i);
            VideoInfoList::RemoveFrameRate(i);

            i--;
        }
    }

    SaveSettings();
    SetJobSetting();
}

void FrameGUI::Updater() {
    QNetworkRequest req;
    req.setUrl(QUrl("http://encodegui.com/updatef.txt"));
    req.setHeader(QNetworkRequest::UserAgentHeader, "FrameGUI Updater");

    QNetworkAccessManager* nam = new QNetworkAccessManager();
    QNetworkReply* reply = nam->get(req);

    connect(reply, SIGNAL(finished()), this, SLOT(UpdaterFinished()));
}

void FrameGUI::UpdaterFinished() {
    QNetworkReply* rply = qobject_cast<QNetworkReply*>(sender());

    if (rply->error() == QNetworkReply::NoError) {
        QString output;

        QStringList lst;
        QTextStream stream(rply);

        bool newUp = false;

        while (!stream.atEnd()) {
            output = stream.readLine();

            if (output.contains("Version="))
                if (!output.contains(VERSION) && !output.contains(QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").value("update", VERSION).toString()))
                    newUp = true;
                else {
                    vers = output.remove("Version=");
                    break;
                }

            if (!output.contains("Version="))
                lst << output;
            else
                vers = output.remove("Version=");
        }

        if (newUp) {
            up = new Update(this);

            up->SetText(lst.join("\n"));

            up->show();
            up->activateWindow();

            connect(up->GetSkip(), SIGNAL(clicked(bool)), this, SLOT(Skip()));
            connect(up->GetNow(), SIGNAL(clicked(bool)), this, SLOT(GoToUpdate()));
            connect(up->GetLater(), SIGNAL(clicked(bool)), this, SLOT(Later()));
        }
    }
}

void FrameGUI::Skip() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("update", vers);
    up->close();
}

void FrameGUI::GoToUpdate() {
    QDesktopServices::openUrl(QUrl("https://encodegui.com/downloads.html"));
    up->close();
}

void FrameGUI::Later() {
    up->close();
}

void FrameGUI::input_bttn() {
    VideoInfoRegex::DurationLine.clear();

    QString input;
    QString ffprobe = QDir::toNativeSeparators(QDir::currentPath() + QString("\\ffmpeg\\ffprobe.exe"));

    input = QFileDialog::getOpenFileName(this, tr("Select Input"), ui.SelectInTxtBox->text(), tr("All files (*.*)"));

    if (input.isEmpty() && !ui.SelectInTxtBox->text().isEmpty())
        input = ui.SelectInTxtBox->text();

    GetVideoInfo(QDir::toNativeSeparators(input), ffprobe);
}

void FrameGUI::GetVideoInfo(QString input, QString ffprobe) {
    if (Checks::CheckFFProbe(ffprobe)) {
        ui.SelectInTxtBox->setText(input);

        VideoInfo::ClearAll();
        AudioInfo::ClearAll();
        SubtitleInfo::ClearAll();

        if (!ui.SelectInTxtBox->text().isEmpty())
            ffloader->VideoInfo(QString("\"%1\"").arg(ffprobe) + QString(" -hide_banner -i \"%1\"").arg(input));
    }
    else {
        MsgBoxHelper(MessageType::Error, "FrameGUI error", "Required dependency \"ffprobe.exe\" is missing in FrameGUI installation. A clean install (uninstall + reinstall) of FrameGUI should fix this.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void FrameGUI::RegexFinished() {
    if (VideoInfo::GetVideoCodec().contains("?")) {
        QMessageBox::critical(this, tr("Import file error"), tr("The selected input file is not a video. Only select video files as the input.\n"));
        ui.SelectInTxtBox->setText(QString());
    }
    else if (VideoInfo::GetDurationStrng().contains("?") && !VideoInfo::GetVideoCodec().contains("?"))
        QMessageBox::warning(this, tr("Input Error"), tr("FrameGUI was unable to find the duration of the selected video file. As a result, encoding progress info for this source will be limited."));
}

void FrameGUI::dragEnterEvent(QDragEnterEvent* d) {
    const QMimeData* md = d->mimeData();

    if (md->hasUrls())
        d->acceptProposedAction();
}

void FrameGUI::dropEvent(QDropEvent* d) {
    const QMimeData* md = d->mimeData();

    QList<QUrl> urlList = md->urls();

    QString ffprobe = QDir::toNativeSeparators(QDir::currentPath() + QString("\\ffmpeg\\ffprobe.exe"));
    QString input = QDir::toNativeSeparators(urlList.at(0).toLocalFile());

    GetVideoInfo(input, ffprobe);
}

void FrameGUI::UpscaleSet() {
    if (ui.UpscaleSetGB->isChecked())
        SET_DISABLED(ui.InterpSetGB);
    else
        SET_ENABLED(ui.InterpSetGB);
}

void FrameGUI::ConvertSet() {
    if (ui.InterpSetGB->isChecked())
        SET_DISABLED(ui.UpscaleSetGB);
    else
        SET_ENABLED(ui.UpscaleSetGB);
}

void FrameGUI::UpdateProgress() {
    ui.EncodeProgress->setMaximum(100);

    if (!ProcessError::GetVkMemoryError() && !ProcessError::GetVkQueueError()) {
        QString progress;


        if (!EncodingAudio) {
            progress.append(QString("Job %1/%2").arg(ffloader->currentJob + 1).arg(ui.JobQueue->rowCount()));
            progress.append(" - ");
            progress.append(QString("FPS: %1").arg(ProgressInfo::GetFps()));
            progress.append(", ");

            if (ProgressInfo::GetTimeElapsed().isValid())
                progress.append(QString("Time elapsed: %1").arg(ProgressInfo::GetTimeElapsed().toString()));
            else
                progress.append(QString("Time elapsed: > day"));

            progress.append(", ");

            if (ProgressInfo::GetTimeLeft().isValid())
                progress.append(QString("Time left: %1").arg(ProgressInfo::GetTimeLeft().toString()));
            else
                progress.append(QString("Time left: > day"));

            progress.append(" - ");
            progress.append(QString("%1%").arg(ProgressInfo::GetPercentage()));
        }
        else {
            progress.append(QString("Job %1/%2 - ").arg(ffloader->currentJob + 1).arg(ui.JobQueue->rowCount()));
            progress.append("Audio and/or Subtitle muxing");
            progress.append(QString(" - %1%").arg(ProgressInfo::GetPercentage()));
        }

        if (VideoInfoList::GetDuration(ffloader->currentJob).isValid()) {
            ui.JobQueue->item(ffloader->currentJob, 2)->setText(QString("%1%").arg(ProgressInfo::GetPercentage()));
            ui.EncodeProgress->setValue((int)ProgressInfo::GetPercentage());
        }

        ui.ProgressBarLabel->setText(progress);
        
    }
    else {
        ffloader->KillProcess(ffloader->encode);
        ffloader->KillProcess(ffloader->vs);
    }
}

void FrameGUI::OutBttn() {
    QString output = QFileDialog::getSaveFileName(this, tr("Save Output File"), ui.SelectInTxtBox->text().left(ui.SelectInTxtBox->text().lastIndexOf(".")), QString("Supported extensions"));
    output = QDir::toNativeSeparators(output);

    if (output.isEmpty() && !ui.SaveOutTxtBox->text().isEmpty())
        output = ui.SaveOutTxtBox->text();

    ui.SaveOutTxtBox->setText(output);
}

void FrameGUI::CancelAllClick() {
    if (ui.JobQueue->rowCount() == 0)
        return;

    QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Question, "Cancel confirmation", "Are you sure you want to cancel ALL jobs? All curent progress of the current job process will be lost.", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

    if (msg == QMessageBox::Yes) {
        FOR_EACH(ui.JobQueue->rowCount())
            if (!ui.JobQueue->item(i, 1)->text().contains("Paused") && !ui.JobQueue->item(i, 1)->text().contains("Active")) {
                ui.JobQueue->item(i, 1)->setText("Canceled");
                state.replace(i, "Canceled");
            }
            else if (ui.JobQueue->item(i, 1)->text().contains("Paused")) {
                MsgBoxHelper(MessageType::Warning, "FrameGUI warning", "The currently paused process could not be canceled. Please resume it first then cancel it.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            }

        if (ffloader->encode && ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Active"))
            if (ffloader->encode->state() == QProcess::Running) {
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Canceled");
                state.replace(ffloader->currentJob, "Canceled");

                ffloader->CloseProcess(ffloader->encode);

                if (ffloader->vs)
                    ffloader->CloseProcess(ffloader->vs);
            }

        if (!ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Paused")) {
            ui.ProgressBarLabel->setText(QString());
            ui.EncodeProgress->setValue(0);
        }

        SetState();
    }
}

void FrameGUI::ResetJob() {
    ui.JobQueue->item(selectedJob, 1)->setText("Waiting");
    state.replace(selectedJob, "Waiting");

    SetState();
}

void FrameGUI::RemoveJob() {
    if (selectedJob == ffloader->currentJob || ui.JobQueue->item(selectedJob, 1)->text().contains("Paused")) {
        if (ffloader->encode && ffloader->encode->state() == QProcess::Running) {
            MsgBoxHelper(MessageType::Error, "FrameGUI error", "Please cancel the current job before removing it from the queue.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            return;
        }
    }

    arguments.removeAt(selectedJob);
    vapourScript.removeAt(selectedJob);
    tempList.removeAt(selectedJob);
    AudioArgs.removeAt(selectedJob);
    outputList.removeAt(selectedJob);
    inputList.removeAt(selectedJob);
    state.removeAt(selectedJob);

    VideoInfoList::RemoveDuration(selectedJob);
    VideoInfoList::RemoveFrameRate(selectedJob);

    ui.JobQueue->removeRow(selectedJob);

    if (ffloader->currentJob != 0)
        FOR_EACH(ui.JobQueue->rowCount())
        if (ui.JobQueue->item(i, 1)->text().contains("Active") || ui.JobQueue->item(i, 1)->text().contains("Paused"))
            ffloader->currentJob = i;

    QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(selectedJob)))).removeRecursively();

    job.removeAt(selectedJob);

    SaveSettings();
    SetJobSetting();
}

void FrameGUI::ClearFinished() {
    FOR_EACH(arguments.count())
        if (ui.JobQueue->item(i, 1)->text().contains("Finished")) {
            ui.JobQueue->removeRow(i);

            arguments.removeAt(i);
            vapourScript.removeAt(i);
            tempList.removeAt(i);
            AudioArgs.removeAt(i);
            outputList.removeAt(i);
            inputList.removeAt(i);
            state.removeAt(i);

            QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1")).arg(job.at(i))).removeRecursively();

            job.removeAt(i);

            VideoInfoList::RemoveDuration(i);
            VideoInfoList::RemoveFrameRate(i);

            i--;
        }

    if (ffloader->currentJob != 0)
        FOR_EACH(arguments.count())
        if (ui.JobQueue->item(i, 1)->text().contains("Active") || ui.JobQueue->item(i, 1)->text().contains("Paused"))
            ffloader->currentJob = i;

    SaveSettings();
    SetJobSetting();
}

void FrameGUI::CancelMain() {
    QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Question, "Cancel confirmation", "Are you sure you want to cancel the currently active job? All progress will be lost.", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

    if (msg == QMessageBox::Yes) {
        if (ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Active")) {
            ui.JobQueue->item(ffloader->currentJob, 1)->setText("Canceled");
            state.replace(ffloader->currentJob, "Canceled");

            ffloader->CloseProcess(ffloader->encode);

            if (ffloader->vs)
                ffloader->CloseProcess(ffloader->vs);

            SetState();
        }
        else
            MsgBoxHelper(MessageType::Error, "FrameGUI error", "A job must be active to cancel it.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void FrameGUI::CancelClick() {
    QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Question, "Cancel confirmation", "Are you sure you want to cancel the selected job? All progress will be lost.", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

    if (msg == QMessageBox::Yes) {
        if (ui.JobQueue->item(selectedJob, 1)->text().contains("Active")) {
            ui.JobQueue->item(selectedJob, 1)->setText("Canceled");

            if (selectedJob == ffloader->currentJob) {
                ffloader->CloseProcess(ffloader->encode);

                if (ffloader->vs)
                    ffloader->CloseProcess(ffloader->vs);
            }

            state.replace(selectedJob, "Canceled");
            SetState();
        }
        else
            MsgBoxHelper(MessageType::Error, "FrameGUI error", "A job must be active to cancel it.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void FrameGUI::PauseClick() {
    if (ui.PauseBttn->text().contains("Pause")) {
        ui.PauseBttn->setText("Resume");
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Paused");
        ui.JobStatusValueLabel->setText("Paused");

        ffloader->PauseProcess(ffloader->encode, true);
        ffloader->PauseTime = ProgressInfo::GetTimeElapsed();
    }
    else {
        ui.PauseBttn->setText("Pause");
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Active");
        ui.JobStatusValueLabel->setText("Active");

        ffloader->PauseProcess(ffloader->encode, false);
        ffloader->Timer.restart();
    }
}

void FrameGUI::Start() {
    int jobs = ui.JobQueue->rowCount();
    int count = 0;

    EncodingAudio = false;

    if (jobs > 0) {
        FOR_EACH(jobs)
            if (ui.JobQueue->item(i, 1)->text().contains("Waiting")) {
                ffloader->currentJob = i;
                SET_ENABLED(ui.PauseBttn);
                SET_ENABLED(ui.CancelBttn);
                SET_DISABLED(ui.StartEncBttn);

                ui.JobQueue->item(i, 1)->setText("Active");

                NewTask();

                Paletter(ui.JobStatusValueLabel);
                ui.JobStatusValueLabel->setText("Active");

                Paletter(ui.JobIDValueLabel);
                ui.JobIDValueLabel->setText(ui.JobQueue->item(i, 0)->text());

                count++;
                break;
            }
    }

    if (jobs == 0 || count == 0)
        MsgBoxHelper(MessageType::Error, "FrameGUI error", "There are no waiting jobs in the queue.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void FrameGUI::NewTask() {
    if (Checks::CheckFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe")) {
        if (Checks::CheckInputExists(inputList.at(ffloader->currentJob))) {
            if (Checks::CheckVsPipe(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\vspipe.exe"))) {
                ProcessError::ClearAll();
                ProcessErrorRegex::ClearBools();

                if (QFile(outputList.at(ffloader->currentJob)).exists())
                    QFile(outputList.at(ffloader->currentJob)).remove();

                if (!QDir(QDir::toNativeSeparators(QDir::tempPath().replace("Temp", QString("FrameGUI\\job-%1").arg(job.at(ffloader->currentJob))))).exists())
                    QDir().mkpath(QDir::toNativeSeparators(QDir::tempPath().replace("Temp", QString("FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));

                LogFile.close();
                LogFile.setFileName(QDir::toNativeSeparators(QDir::tempPath().replace("Temp", QString("FrameGUI\\job-%1\\ProcessLogs-%1.txt").arg(job.at(ffloader->currentJob)))));
                LogFile.open(QIODevice::WriteOnly);
                FileStream.clear();

                FileStream << "#================================================#";
                FileStream << QString("FrameGUI process logs for job %1").arg(job.at(ffloader->currentJob));
                FileStream << QString("Video encoding arguments: %1 | %2").arg(vapourScript.at(ffloader->currentJob)).arg(arguments.at(ffloader->currentJob));
                FileStream << QString("Audio encoding arguments: %1").arg(AudioArgs.at(ffloader->currentJob));
                FileStream << "#================================================#\n";

                if (Checks::CheckVsScript(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1\\%1.vpy").arg(job.at(ffloader->currentJob)))))
                    ffloader->Encode(arguments.at(ffloader->currentJob), vapourScript.at(ffloader->currentJob));
                else {
                    MsgBoxHelper(MessageType::Error, "FrameGUI error", QString("Could not find VapourSynth script for job id: %1\nExiting job.").arg(job.at(ffloader->currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
                    EncodeFinished();
                }

                ui.ProgressBarLabel->setText("Creating index file...");
                ui.EncodeProgress->setMaximum(0);
            }
            else {
                MsgBoxHelper(MessageType::Error, "FrameGUI error", "Required dependency \"vspipe.exe\" is missing in FrameGUI installation. A clean install (uninstall + reinstall) of FrameGUI should fix this.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                QApplication::quit();
            }
        }
        else {
            MsgBoxHelper(MessageType::Error, "FrameGUI error", QString("The source video file at \"%1\" is missing or does not exist.").arg(inputList.at(ffloader->currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
            FileStream << QString("FrameGUI error: could not find source file for job %1.").arg(job.at(ffloader->currentJob));
            EncodeFinished();
        }
    }
    else {
        MsgBoxHelper(MessageType::Error, "FrameGUI error", "Required dependency \"ffmpeg.exe\" is missing in FrameGUI installation. A clean install (uninstall + reinstall) of FrameGUI should fix this.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void FrameGUI::closeEvent(QCloseEvent* evnt) {
    if (ffloader->encode && ffloader->encode->state() == QProcess::Running) {
        MsgBoxHelper(MessageType::Error, "FrameGUI error", "Please cancel the current active job before closing FrameGUI.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        evnt->ignore();
    }
    else if (ffloader->encode)
        if (ffloader->encode->state() == QProcess::NotRunning)
            evnt->accept();
        else
            evnt->accept();
}

void FrameGUI::EncodeFinished() {
    QFile(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.lwi").arg(job.at(ffloader->currentJob)))).remove();

    ui.EncodeProgress->setMaximum(100);
    ui.ProgressBarLabel->setText(QString());
    ui.EncodeProgress->setValue(0);

    QMessageBox::StandardButton msg;

    if (ProcessError::Error()) {
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
        state.replace(ffloader->currentJob, "Failed");

        if (ProcessError::GetVkMemoryError())
            msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "Failed to allocate memory for the current process. Your GPU many not be supported. Click \"Open\" below to see the associated job logs.", QMessageBox::Open, QMessageBox::NoButton, QMessageBox::NoButton);
        if (ProcessError::GetVkQueueError() && !ProcessError::GetVkMemoryError())
            msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "Failed to queue the current process. Add registry keys to delay the queue submit timeout (see https://encodegui.com/support.html for directions).", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        if (ProcessError::GetNcnnError())
            msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "Failed to start the current process.\nYour GPU may not be supported or your GPU drivers may be outdated.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));

        SetState();
    }
    else if (ProcessError::GetPipeError()) {
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
        state.replace(ffloader->currentJob, "Failed");

        msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "An unknown error occured with the current process. Click \"Open\" below to see the associated process logs.", QMessageBox::Ok, QMessageBox::Open, QMessageBox::NoButton);

        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));

        SetState();
    }
    else if (ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Failed")) {
        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "An unknown error occured with the current process. Click \"Open\" below to open the current job's logs.", QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

        state.replace(ffloader->currentJob, "Failed");
        SetState();
    }
    else if (AudioArgs.at(ffloader->currentJob) != QString("noa") && (!QFile(tempList.at(ffloader->currentJob)).exists() || QFile(tempList.at(ffloader->currentJob)).size() < 100000) && !ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Canceled")) {
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");

        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "An unknown error occured with the current process. Click \"Open\" below to open the current job's logs.", QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

        state.replace(ffloader->currentJob, "Failed");
        SetState();
    }
    else {
        if (!ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Canceled")) {
            if (!QFile(outputList.at(ffloader->currentJob)).exists() && !EncodingAudio && AudioArgs.at(ffloader->currentJob) != QString("noa")) {
                FileStream << "\n#================================================#";
                FileStream << "Begin audio encoding";
                FileStream << "#================================================#\n";

                ffloader->Encode(AudioArgs.at(ffloader->currentJob), QString());
                EncodingAudio = true;

                return;
            }
            else if ((!QFile(outputList.at(ffloader->currentJob)).exists() || QFile(outputList.at(ffloader->currentJob)).size() < 10000) && AudioArgs.at(ffloader->currentJob) == QString("noa")) {
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");

                QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", "An unknown error occured with the current process. Click \"Open\" below to open the current job's logs.", QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

                if (msg == QMessageBox::Open)
                    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
                if (msg == QMessageBox::Help)
                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                state.replace(ffloader->currentJob, "Failed");
                SetState();
            }
            else if (EncodingAudio && (!QFile(outputList.at(ffloader->currentJob)).exists() || QFile(outputList.at(ffloader->currentJob)).size() < 10000)) {
                ui.JobQueue->item(ffloader->currentJob, 2)->setText("0%");
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");

                QMessageBox::StandardButton sb = MsgBoxHelper(MessageType::Error, "FrameGUI error", "Audio/subtitle muxing failed. Click \"Open\" below to see the associated process logs.",
                    QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

                if (sb == QMessageBox::Open)
                    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
                if (sb == QMessageBox::Help)
                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                state.replace(ffloader->currentJob, "Failed");
                SetState();
            }
            else {
                ui.JobQueue->item(ffloader->currentJob, 2)->setText("100%");
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Finished");

                state.replace(ffloader->currentJob, "Finished");
                SetState();
            }
        }
    }

    EncodingAudio = false;
    ffloader->PauseTime = QTime(0, 0, 0);

    if (!FileStream.isEmpty() && LogFile.exists()) {
        FileStream << "\n#================================================#";
        FileStream << "End of logs";
        FileStream << "#================================================#";

        QTextStream stream(&LogFile);

        foreach(QString line, FileStream)
            stream << line + "\n";

        LogFile.close();
        FileStream.clear();
    }

    NewJob();
}

void FrameGUI::NewJob() {
    Paletter(ui.JobStatusValueLabel);
    ui.JobStatusValueLabel->setText("?");

    Paletter(ui.JobIDValueLabel);
    ui.JobIDValueLabel->setText("?");

    QFile(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(job.at(ffloader->currentJob)))).remove();

    int isDone = 0;

    FOR_EACH(ui.JobQueue->rowCount())
        if (ui.JobQueue->item(i, 1)->text().contains("Waiting") && !ui.JobQueue->item(i, 1)->text().contains("Failed"))
            isDone++;

    if (isDone > 0) {
        FOR_EACH(ui.JobQueue->rowCount())
            if (ui.JobQueue->item(i, 1)->text().contains("Waiting")) {
                ffloader->currentJob = i;
                SET_ENABLED(ui.PauseBttn);
                SET_ENABLED(ui.CancelBttn);
                SET_DISABLED(ui.StartEncBttn);

                ui.JobQueue->item(i, 1)->setText("Active");

                Paletter(ui.JobStatusValueLabel);
                ui.JobStatusValueLabel->setText("Active");

                Paletter(ui.JobIDValueLabel);
                ui.JobIDValueLabel->setText(ui.JobQueue->item(i, 0)->text());

                NewTask();

                break;
            }
    }
    else {
        SET_DISABLED(ui.PauseBttn);
        SET_DISABLED(ui.CancelBttn);
        SET_ENABLED(ui.StartEncBttn);

        MsgBoxHelper(MessageType::Info, "Done processing jobs", "No more jobs to process.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void FrameGUI::SetState() {
    Vstate.clear();

    foreach(QString sta, state)
        Vstate << sta;

    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "FrameGUI").setValue("state", Vstate);
}

void FrameGUI::WriteFile(QString output) {
    FileStream << output;
}

void FrameGUI::Paletter(QLabel* label) {
    QPalette palette = label->palette();
    palette.setColor(label->foregroundRole(), Qt::darkGreen);
    label->setPalette(palette);
}

void FrameGUI::InputClick() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(inputList.at(selectedJob)).absolutePath())));
}

void FrameGUI::OpenJobLogs() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(job.at(selectedJob)))));
}

void FrameGUI::OpenOutput() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(outputList.at(selectedJob)).absolutePath())));
}

void FrameGUI::DonateDaGoose() {
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/donate/?hosted_button_id=CLBETTY9GBM28"));
}

void FrameGUI::PatreonClick() {
    QDesktopServices::openUrl(QUrl("https://www.patreon.com/dagoose"));
}

void FrameGUI::YouClick() {
    QDesktopServices::openUrl(QUrl("https://youtube.com/c/DaGoose"));
}

void FrameGUI::DisClick() {
    QDesktopServices::openUrl(QUrl("https://discord.gg/PmcbXJVBNu"));
}

void FrameGUI::IgClick() {
    QDesktopServices::openUrl(QUrl("https://www.instagram.com/dagooseyt/"));
}

FrameGUI::~FrameGUI() {
    delete ffloader;
}