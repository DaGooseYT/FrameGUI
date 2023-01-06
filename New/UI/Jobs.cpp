#include "FrameGUI.h"

QStringList AudioArgs;

QVariantList Varguments;
QVariantList Vjob;
QVariantList VvapourScript;
QVariantList VinputList;
QVariantList VoutputList;
QVariantList VtempList;
QVariantList Vstate;
QVariantList VaudioArgs;
QVariantList Vduration;
QVariantList VframeRate;

void FrameGUI::setup_queue() {
    ui.JobQueue->setColumnWidth(0, 100);
    ui.JobQueue->setColumnWidth(1, 80);
    ui.JobQueue->setColumnWidth(2, 70);
    ui.JobQueue->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui.JobQueue->horizontalHeader()->setSectionsClickable(false);

    connect(ui.JobQueue, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(JobContext(QPoint)));
}

void FrameGUI::JobContext(QPoint pos) {
    QTableWidgetItem* item = ui.JobQueue->itemAt(pos);

    if (item != nullptr) {
        ui.JobQueue->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = item->row();
        ui.JobQueue->selectRow(row);

        selectedJob = row;

        QMenu* m = new QMenu(this);

        QAction* logs = new QAction("Open logs path", this);
        QAction* input = new QAction("Open source path", this);
        QAction* output = new QAction("Open output path", this);
        QAction* pause = new QAction("Pause / Resume", this);
        QAction* cancel = new QAction("Cancel", this);
        QAction* remove = new QAction("Remove", this);
        QAction* reset = new QAction("Reset", this);

        if (ui.JobQueue->item(row, 1)->text().contains("Paused") || ui.JobQueue->item(row, 1)->text().contains("Active")) {
            SET_DISABLED(reset);
            SET_DISABLED(remove);
            SET_ENABLED(cancel);
            SET_ENABLED(pause);
        }
        else {
            SET_ENABLED(reset);
            SET_ENABLED(remove);
            SET_DISABLED(cancel);
            SET_DISABLED(pause);
        }

        m->setFont(this->font());
        m->addAction(logs);
        m->addAction(input);
        m->addAction(output);
        m->addAction(pause);
        m->addAction(cancel);
        m->addAction(remove);
        m->addAction(reset);
        m->popup(ui.JobQueue->viewport()->mapToGlobal(pos));

        connect(pause, SIGNAL(triggered()), this, SLOT(PauseClick()));
        connect(input, SIGNAL(triggered()), this, SLOT(InputClick()));
        connect(output, SIGNAL(triggered()), this, SLOT(OpenOutput()));
        connect(logs, SIGNAL(triggered()), this, SLOT(OpenJobLogs()));
        connect(cancel, SIGNAL(triggered()), this, SLOT(CancelClick()));
        connect(remove, SIGNAL(triggered()), this, SLOT(RemoveJob()));
        connect(reset, SIGNAL(triggered()), this, SLOT(ResetJob()));

        connect(m, &QMenu::aboutToHide, [this]() {
            ui.JobQueue->selectionModel()->clear();
            ui.JobQueue->setSelectionMode(QAbstractItemView::NoSelection);
        });
    }
}

void FrameGUI::CreateJob() {
    if (Checks::CheckInput(ui.SelectInTxtBox->text())) {
        if (Checks::CheckInputExists(ui.SelectInTxtBox->text())) {
            if (Checks::CheckOutput(ui.SaveOutTxtBox->text())) {
                if (ffloader->video->state() == QProcess::Running) {
                    MsgBoxHelper(MessageType::Error, "FrameGUI error", "Please wait for FrameGUI to gather media info before adding a job.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                int index = 0;

                QString container = ui.OutContainerDD->currentText();

                FOR_EACH(AudioInfo::TotalStreams()) {
                    if (AudioInfo::GetCodec(i).contains("AAC"))
                        index = 0;
                    else if (AudioInfo::GetCodec(i).contains("MP3"))
                        index = 1;
                    else if (AudioInfo::GetCodec(i).contains("AC3") && !AudioInfo::GetCodec(i).contains("EAC3"))
                        index = 2;
                    else if (AudioInfo::GetCodec(i).contains("FLAC"))
                        index = 3;
                    else if (AudioInfo::GetCodec(i).contains("Vorbis"))
                        index = 4;
                    else if (AudioInfo::GetCodec(i).contains("Opus"))
                        index = 5;
                    else if (AudioInfo::GetCodec(i).contains("EAC3"))
                        index = 6;
                    else if (AudioInfo::GetCodec(i).contains("ALAC"))
                        index = 7;
                    else if (AudioInfo::GetCodec(i).contains("WMA"))
                        index = 8;
                    else if (AudioInfo::GetCodec(i).contains("PCM"))
                        index = 9;
                    else if (AudioInfo::GetCodec(i).contains("MP2"))
                        index = 10;
                    else if (AudioInfo::GetCodec(i).contains("DTS"))
                        index = 11;
                    else if (AudioInfo::GetCodec(i).contains("TrueHD"))
                        index = 12;
                    else {
                        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", QString("%1 audio codec isn't supported in FrameGUI. Please use a different video with a supported audio codec.")
                            .arg(AudioInfo::GetCodec(i)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                        return;
                    }

                    if (!Checks::CheckAudioCompatability(index, container)) {
                        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "FrameGUI error", QString("%1 audio codec isn't supported with the %2 output container.")
                            .arg(AudioInfo::GetCodec(i)).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);

                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                        return;
                    }
                }

                if (ui.OutContainerDD->currentIndex() == 3 && SubtitleInfo::TotalStreams() > 0) {
                    MsgBoxHelper(MessageType::Error, "FrameGUI error", ".avi output container does not support subtitles. Please select a compatible container such as .mkv.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                if (CHECKED(ui.UpscaleSetGB)) {
                    int outH = ui.OutputResDD->currentText().remove("(").remove(")").remove("p").remove("HD").remove("F").remove("Q").remove("U").remove("4K").remove(" ").toInt();
                    int outW = 0;

                    switch (outH) {
                    case 720:
                        outW = 1280;
                        break;
                    case 1080:
                        outW = 1920;
                        break;
                    case 1440:
                        outW = 2560;
                        break;
                    case 2160:
                        outW = 3840;
                        break;
                    }
                    
                    if (VideoInfo::GetWidth() >= outW) {
                        MsgBoxHelper(MessageType::Error, "FrameGUI error", QString("Output resolution (%1p) for Upscaling is too small. Please select an upscaling resolution that is higher than the source resolution (%2x%3).").arg(outH).arg(VideoInfo::GetWidth()).arg(VideoInfo::GetHeight()), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }

                if (CHECKED(ui.InterpSetGB)) {
                    if (VideoInfo::GetFrameRate().toDouble() == ui.OutFPSDD->currentText().toDouble()) {
                        MsgBoxHelper(MessageType::Error, "FrameGUI error", QString("The selected output FPS (%1) for Convert FPS cannot be equal to the source video FPS (%2). Please select a different output FPS.").arg(ui.OutFPSDD->currentText().toDouble()).arg(VideoInfo::GetFrameRate()), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }

                QDate date(QDate::currentDate());
                QString audioArgs, subtitleArgs;
                QString id = QString(QTime::currentTime().toString().remove(":")) + QString("%1").arg(date.day());

                ui.JobQueue->insertRow(ui.JobQueue->rowCount());
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 0, new QTableWidgetItem(id));
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 1, new QTableWidgetItem("Waiting"));
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 2, new QTableWidgetItem("0%"));
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 3, new QTableWidgetItem(ui.SaveOutTxtBox->text() + container));

                state << "Waiting"; Vstate << "Waiting";

                for (int i = 0; i < 3; i++)
                    ui.JobQueue->item(ui.JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);

                QString jobDir = QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\FrameGUI\\job-%1").arg(id));
                QDir().mkpath(jobDir);

                QFile script = QString("%1\\%2.vpy").arg(jobDir).arg(id);;
                script.open(QIODevice::WriteOnly);

                QTextStream stream(&script);

                stream << BuildScript(VideoInfo::GetWidth(), VideoInfo::GetHeight(), id);

                script.close();
                vapourScript << ConfigureVS(id); VvapourScript << ConfigureVS(id);

                QString tempFile = QString("%1.mkv").arg(id);

                job << id; Vjob << id;

                inputList << ui.SelectInTxtBox->text(); VinputList << ui.SelectInTxtBox->text();
                tempList << QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(tempFile)); VtempList << QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(tempFile));
                outputList << ui.SaveOutTxtBox->text() + container; VoutputList << ui.SaveOutTxtBox->text() + container;

                if (AudioInfo::TotalStreams() != 0) {
                    audioArgs.append(ConfigureAudioP(1, tempFile, container));
                    AudioArgs << audioArgs; VaudioArgs << audioArgs;
                }
                else {
                    AudioArgs << QString("noa"); VaudioArgs << QString("noa");
                }

                VideoInfoList::SetDuration(VideoInfo::GetDuration());
                Vduration << VideoInfo::GetDuration();

                if (!CHECKED(ui.InterpSetGB)) {
                    VideoInfoList::SetFrameRate(VideoInfo::GetFrameRate());
                    VframeRate << VideoInfo::GetFrameRate();
                }
                else {
                    VideoInfoList::SetFrameRate(ui.OutFPSDD->currentText());
                    VframeRate << ui.OutFPSDD->currentText();
                }

                arguments << ConfigureArgs(container, id); Varguments << ConfigureArgs(container, id);

                SaveSettings();
                SetJobSetting();

                MsgBoxHelper(MessageType::Info, tr("Add job"), "Added job with ID: " + id, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            }
            else
                MsgBoxHelper(MessageType::Error, "FrameGUI Error", "An output file must be specified.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        }
        else
            MsgBoxHelper(MessageType::Error, "FrameGUI Error", "The selected source file is missing or does not exist.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else
        MsgBoxHelper(MessageType::Error, "FrameGUI Error", "An source file must be specified.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}