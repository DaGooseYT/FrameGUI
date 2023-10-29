#include "framegui.hpp"

void FrameGUI::setupQueue() {
    _ui->JobQueue->setColumnWidth(0, 80);
    _ui->JobQueue->setColumnWidth(1, 85);
    _ui->JobQueue->setColumnWidth(2, 85);

    #ifdef Q_OS_WINDOWS
    _ui->JobQueue->setColumnWidth(3, 108);
    _ui->JobQueue->setColumnWidth(4, 108);
    #endif
    #ifdef Q_OS_DARWIN
    _ui->JobQueue->setColumnWidth(3, 110);
    _ui->JobQueue->setColumnWidth(4, 110);
    #endif

    _ui->JobQueue->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    _ui->JobQueue->horizontalHeader()->setSectionsClickable(false);

    connect(_ui->JobQueue, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(jobContext(QPoint)));
}

void FrameGUI::jobContext(QPoint pos) {
    QTableWidgetItem* item(_ui->JobQueue->itemAt(pos));

    if (item) {
        _ui->JobQueue->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = item->row();
        _ui->JobQueue->selectRow(row);
        _selectedJob = row;

        QMenu *m(new QMenu(this));
        QAction *input(new QAction(QString("Open input directory"), this));
        QAction *output(new QAction(QString("Open output directory"), this));
        QAction *pause(new QAction(QString("Pause / Resume"), this));
        QAction *cancel(new QAction(QString("Cancel"), this));
        QAction *remove(new QAction(QString("Remove"), this));
        QAction *reset(new QAction(QString("Reset"), this));

        if (_ui->JobQueue->item(row, 1)->text().contains(QString("Paused")) || _ui->JobQueue->item(row, 1)->text().contains(QString("Active"))) {
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
        m->addAction(input);
        m->addAction(output);
        m->addAction(pause);
        m->addAction(cancel);
        m->addAction(remove);
        m->addAction(reset);
        m->popup(_ui->JobQueue->viewport()->mapToGlobal(pos));

        connect(pause, SIGNAL(triggered()), this, SLOT(pauseClick()));
        connect(input, SIGNAL(triggered()), this, SLOT(inputClick()));
        connect(output, SIGNAL(triggered()), this, SLOT(outputClick()));
        connect(cancel, SIGNAL(triggered()), this, SLOT(cancelClick()));
        connect(remove, SIGNAL(triggered()), this, SLOT(removeJob()));
        connect(reset, SIGNAL(triggered()), this, SLOT(resetJob()));
        connect(m, &QMenu::aboutToHide, [this]() {
            _ui->JobQueue->selectionModel()->clear();
            _ui->JobQueue->setSelectionMode(QAbstractItemView::NoSelection);

            delete(sender());
        });
    }
}

void FrameGUI::createJob() {
    if (Checks::checkInput(_ui->SelectInTxtBox->text())) {
        if (Checks::checkInputExists(_ui->SelectInTxtBox->text())) {
            if (Checks::checkOutput(_ui->SaveOutTxtBox->text())) {
                if (_ffloader->_video->state() == QProcess::Running) {
                    msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Please wait for FrameGUI to gather media info before adding a job."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                int index = 0;

                QString container(_ui->OutContainerDD->currentText());

                FOR_EACH(AudioInfo::totalStreams()) {
                    if (AudioInfo::getCodec(i).contains(QString("AAC")))
                        index = 0;
                    else if (AudioInfo::getCodec(i).contains(QString("MP3")))
                        index = 1;
                    else if (AudioInfo::getCodec(i).contains(QString("AC3")) && !AudioInfo::getCodec(i).contains(QString("EAC3")))
                        index = 2;
                    else if (AudioInfo::getCodec(i).contains(QString("FLAC")))
                        index = 3;
                    else if (AudioInfo::getCodec(i).contains(QString("Vorbis")))
                        index = 4;
                    else if (AudioInfo::getCodec(i).contains(QString("Opus")))
                        index = 5;
                    else if (AudioInfo::getCodec(i).contains(QString("EAC3")))
                        index = 6;
                    else if (AudioInfo::getCodec(i).contains(QString("ALAC")))
                        index = 7;
                    else if (AudioInfo::getCodec(i).contains(QString("WMA")))
                        index = 8;
                    else if (AudioInfo::getCodec(i).contains(QString("PCM")))
                        index = 9;
                    else if (AudioInfo::getCodec(i).contains(QString("MP2")))
                        index = 10;
                    else if (AudioInfo::getCodec(i).contains(QString("DTS")))
                        index = 11;
                    else if (AudioInfo::getCodec(i).contains(QString("TrueHD")))
                        index = 12;
                    else {
                        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("%1 audio codec isn't supported in FrameGUI. Please use a different video with a supported audio codec.")
                            .arg(AudioInfo::getCodec(i)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton));

                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

                        return;
                    }

                    if (!Checks::checkAudioCompatability(index, container)) {
                        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("%1 audio codec isn't supported with the %2 output container.")
                            .arg(AudioInfo::getCodec(i)).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));

                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl("https://encodegui.com/support"));

                        return;
                    }
                }

                if (QFile(_ui->SaveOutTxtBox->text() + container).exists()) {
                    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, "Confirm overwrite", "The output file already exists. Creating and starting this job will automatically overwrite that output file. Continue?", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));
                    
                    if (msg == QMessageBox::No)
                        return;
                }

                if (QString(_ui->SaveOutTxtBox->text() + container).contains(_ui->SelectInTxtBox->text()) && QString(_ui->SaveOutTxtBox->text() + container).length() == _ui->SelectInTxtBox->text().length() && !_ui->SaveOutTxtBox->text().isEmpty()) {
                    msgBoxHelper(MessageType::Error, "EncodeGUI error", "The output destination path cannot be equivalent to the source file path. Change the output file destination to fix this.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                if (_ui->OutContainerDD->currentIndex() == 3 && SubtitleInfo::totalStreams() > 0) {
                    msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString(".avi output container does not support subtitles. Please select a compatible container such as .mkv."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                if (CHECKED(_ui->UpscaleSetGB)) {
                    int outH = _ui->OutputResDD->currentText().remove(QString("(")).remove(QString(")")).remove(QString("p")).remove(QString("HD")).remove(QString("F")).remove(QString("Q")).remove(QString("U")).remove(QString("4K")).remove(QString(" ")).toInt();
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
                    
                    if (VideoInfo::getWidth() >= outW) {
                        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Output resolution (%1p) for Upscaling is too small. Please select an upscaling resolution that is higher than the source resolution (%2x%3).").arg(outH).arg(VideoInfo::getWidth()).arg(VideoInfo::getHeight()), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }

                if (CHECKED(_ui->InterpSetGB)) {
                    if (VideoInfo::getFrameRate().toDouble() == _ui->OutFPSDD->currentText().toDouble()) {
                        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("The selected output FPS (%1) for Convert FPS cannot be equal to the source video FPS (%2). Please select a different output FPS.").arg(_ui->OutFPSDD->currentText().toDouble()).arg(VideoInfo::getFrameRate()), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }

                QDate date(QDate::currentDate());
                QString id(QString(QTime::currentTime().toString().remove(QString(":"))) + QString("%1").arg(date.day())), subtitleArgs;
                QStringList audioArgs;

                _ui->JobQueue->insertRow(_ui->JobQueue->rowCount());
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 0, new QTableWidgetItem(id));
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 1, new QTableWidgetItem(QString("Waiting")));
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 2, new QTableWidgetItem(QString("0%")));

                bttns();

                _state->append(QString("Waiting"));
                _sState.append(QString("Waiting"));

                for (int i = 0; i < 3; i++)
                    _ui->JobQueue->item(_ui->JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);

                #ifdef Q_OS_WINDOWS
                QString jobDir(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(id)));
                #endif
                #ifdef Q_OS_DARWIN
                QString jobDir(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(id)));
                #endif

                QDir().mkpath(jobDir);

                #ifdef Q_OS_WINDOWS
                QString vsScript(QDir::toNativeSeparators(QString("%1\\%2.vpy").arg(jobDir).arg(id)));
                #endif
                #ifdef Q_OS_DARWIN
                QString vsScript(QDir::toNativeSeparators(QString("%1/%2.vpy").arg(jobDir).arg(id)));
                #endif

                QFile script(vsScript);
                script.open(QIODevice::WriteOnly);
                QTextStream stream(&script);
                stream << buildScript(VideoInfo::getWidth(), VideoInfo::getHeight(), id);
                script.close();

                #ifdef Q_OS_WINDOWS
                _vapourScript.append(configureVS(id));
                _sVapourScript.append(configureVS(id));
                #endif

                QString tempFile(QString("%1.mkv").arg(id));

                _job->append(id);
                _sJob.append(id);

                _inputList->append(_ui->SelectInTxtBox->text());
                _sInputList.append(_ui->SelectInTxtBox->text());

                #ifdef Q_OS_WINDOWS
                _tempList->append(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(tempFile))); 
                _sTempList.append(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(tempFile)));
                #endif
                #ifdef Q_OS_DARWIN
                _tempList->append(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1").arg(tempFile)));
                _sTempList.append(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1").arg(tempFile)));
                #endif

                _outputList->append(_ui->SaveOutTxtBox->text() + container);
                _sOutputList.append(_ui->SaveOutTxtBox->text() + container);

                if (AudioInfo::totalStreams() != 0) {
                    audioArgs.append(configureAudioPT(1, tempFile, container));
                    _audioArgs.append(audioArgs);
                    _sAudioArgs.append(audioArgs);
                }
                else {
                    _audioArgs.append(QString("noa"));
                    _sAudioArgs.append(QString("noa"));
                }

                VideoInfoList::setDuration(VideoInfo::getDuration());
                _sDuration.append(VideoInfo::getDuration());

                if (!CHECKED(_ui->InterpSetGB)) {
                    VideoInfoList::setFrameRate(VideoInfo::getFrameRate());
                    _sFrameRate.append(VideoInfo::getFrameRate());
                }
                else {
                    VideoInfoList::setFrameRate(_ui->OutFPSDD->currentText());
                    _sFrameRate.append(_ui->OutFPSDD->currentText());
                }

                _arguments.append(configureArgs(container, id, vsScript)); 
                _sArguments.append(configureArgs(container, id, vsScript));

                saveSettings();
                setJobSetting();

                msgBoxHelper(MessageType::Info, QString("Add job"), QString("Added job with ID: ") + id, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            }
            else
                msgBoxHelper(MessageType::Error, QString("FrameGUI Error"), QString("An output file must be specified."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        }
        else
            msgBoxHelper(MessageType::Error, QString("FrameGUI Error"), QString("The selected source file is missing or does not exist."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else
        msgBoxHelper(MessageType::Error, QString("FrameGUI Error"), QString("An source file must be specified."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}