/********************************************************************************
** Form generated from reading UI file 'framegui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMEGUI_H
#define UI_FRAMEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrameGUIClass
{
public:
    QWidget *centralWidget;
    QTabWidget *Tabs;
    QWidget *MainTab;
    QLabel *LogoLabel;
    QGroupBox *CurrentProcessGB;
    QPushButton *PauseBttn;
    QPushButton *CancelBttn;
    QLabel *JobIDLabel;
    QLabel *StatusLabel;
    QLabel *JobStatusValueLabel;
    QLabel *JobIDValueLabel;
    QLineEdit *SelectInTxtBox;
    QPushButton *SelectInBttn;
    QWidget *SettingsTab;
    QGroupBox *EncodeSetGB;
    QComboBox *IWantDD;
    QLabel *IWantLabel;
    QGroupBox *InterpSetGB;
    QLabel *OutFPSLabel;
    QComboBox *OutFPSDD;
    QLabel *UseAILabel;
    QCheckBox *USeAICB;
    QGroupBox *UpscaleSetGB;
    QLabel *OutputResLabel;
    QComboBox *OutputResDD;
    QWidget *QueueTab;
    QTableWidget *JobQueue;
    QLabel *JobQueueLabel;
    QPushButton *ClearJobsBttn;
    QPushButton *CancelQueueBttn;
    QWidget *AboutTab;
    QGroupBox *DonateGB;
    QLabel *DonateToDaGooseLabel;
    QPushButton *DonateToDaGooseBttn;
    QGroupBox *AboutGUIGB;
    QLabel *AboutGuiLabel;
    QGroupBox *LinksGB;
    QPushButton *YoutubeBttn;
    QPushButton *DiscordBttn;
    QPushButton *InstaBttn;
    QPushButton *ClearBttn;
    QPushButton *LicensesBttn;
    QLineEdit *SaveOutTxtBox;
    QPushButton *AddJobBttn;
    QProgressBar *EncodeProgress;
    QComboBox *OutContainerDD;
    QPushButton *SaveOutBttn;
    QPushButton *StartEncBttn;
    QLabel *ProgressBarLabel;

    void setupUi(QMainWindow *FrameGUIClass)
    {
        if (FrameGUIClass->objectName().isEmpty())
            FrameGUIClass->setObjectName(QString::fromUtf8("FrameGUIClass"));
        FrameGUIClass->resize(600, 400);
        FrameGUIClass->setMinimumSize(QSize(600, 400));
        FrameGUIClass->setMaximumSize(QSize(600, 400));
        FrameGUIClass->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/FrameGUI/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FrameGUIClass->setWindowIcon(icon);
        centralWidget = new QWidget(FrameGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Tabs->setGeometry(QRect(5, 5, 592, 333));
        MainTab = new QWidget();
        MainTab->setObjectName(QString::fromUtf8("MainTab"));
        LogoLabel = new QLabel(MainTab);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(64, 167, 454, 119));
        LogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/FrameGUI/FrameGUI.png")));
        LogoLabel->setScaledContents(true);
        CurrentProcessGB = new QGroupBox(MainTab);
        CurrentProcessGB->setObjectName(QString::fromUtf8("CurrentProcessGB"));
        CurrentProcessGB->setGeometry(QRect(151, 46, 289, 116));
        CurrentProcessGB->setAlignment(Qt::AlignCenter);
        PauseBttn = new QPushButton(CurrentProcessGB);
        PauseBttn->setObjectName(QString::fromUtf8("PauseBttn"));
        PauseBttn->setEnabled(false);
        PauseBttn->setGeometry(QRect(19, 80, 120, 24));
        QFont font;
        font.setBold(true);
        PauseBttn->setFont(font);
        CancelBttn = new QPushButton(CurrentProcessGB);
        CancelBttn->setObjectName(QString::fromUtf8("CancelBttn"));
        CancelBttn->setEnabled(false);
        CancelBttn->setGeometry(QRect(151, 80, 118, 24));
        CancelBttn->setFont(font);
        JobIDLabel = new QLabel(CurrentProcessGB);
        JobIDLabel->setObjectName(QString::fromUtf8("JobIDLabel"));
        JobIDLabel->setGeometry(QRect(21, 27, 41, 16));
        StatusLabel = new QLabel(CurrentProcessGB);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
        StatusLabel->setGeometry(QRect(21, 53, 49, 16));
        JobStatusValueLabel = new QLabel(CurrentProcessGB);
        JobStatusValueLabel->setObjectName(QString::fromUtf8("JobStatusValueLabel"));
        JobStatusValueLabel->setGeometry(QRect(167, 51, 101, 20));
        JobStatusValueLabel->setFont(font);
        JobStatusValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        JobIDValueLabel = new QLabel(CurrentProcessGB);
        JobIDValueLabel->setObjectName(QString::fromUtf8("JobIDValueLabel"));
        JobIDValueLabel->setGeometry(QRect(187, 25, 81, 20));
        JobIDValueLabel->setFont(font);
        JobIDValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SelectInTxtBox = new QLineEdit(MainTab);
        SelectInTxtBox->setObjectName(QString::fromUtf8("SelectInTxtBox"));
        SelectInTxtBox->setGeometry(QRect(12, 10, 457, 22));
        SelectInTxtBox->setReadOnly(true);
        SelectInBttn = new QPushButton(MainTab);
        SelectInBttn->setObjectName(QString::fromUtf8("SelectInBttn"));
        SelectInBttn->setGeometry(QRect(475, 9, 101, 24));
        Tabs->addTab(MainTab, QString());
        SettingsTab = new QWidget();
        SettingsTab->setObjectName(QString::fromUtf8("SettingsTab"));
        EncodeSetGB = new QGroupBox(SettingsTab);
        EncodeSetGB->setObjectName(QString::fromUtf8("EncodeSetGB"));
        EncodeSetGB->setGeometry(QRect(14, 6, 559, 70));
        EncodeSetGB->setAlignment(Qt::AlignCenter);
        IWantDD = new QComboBox(EncodeSetGB);
        IWantDD->addItem(QString());
        IWantDD->addItem(QString());
        IWantDD->setObjectName(QString::fromUtf8("IWantDD"));
        IWantDD->setGeometry(QRect(180, 28, 364, 22));
        IWantLabel = new QLabel(EncodeSetGB);
        IWantLabel->setObjectName(QString::fromUtf8("IWantLabel"));
        IWantLabel->setGeometry(QRect(18, 30, 49, 16));
        InterpSetGB = new QGroupBox(SettingsTab);
        InterpSetGB->setObjectName(QString::fromUtf8("InterpSetGB"));
        InterpSetGB->setGeometry(QRect(14, 85, 559, 90));
        InterpSetGB->setAlignment(Qt::AlignCenter);
        InterpSetGB->setCheckable(true);
        InterpSetGB->setChecked(false);
        OutFPSLabel = new QLabel(InterpSetGB);
        OutFPSLabel->setObjectName(QString::fromUtf8("OutFPSLabel"));
        OutFPSLabel->setGeometry(QRect(18, 55, 101, 16));
        OutFPSDD = new QComboBox(InterpSetGB);
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->addItem(QString());
        OutFPSDD->setObjectName(QString::fromUtf8("OutFPSDD"));
        OutFPSDD->setGeometry(QRect(487, 53, 57, 22));
        UseAILabel = new QLabel(InterpSetGB);
        UseAILabel->setObjectName(QString::fromUtf8("UseAILabel"));
        UseAILabel->setGeometry(QRect(18, 24, 404, 16));
        USeAICB = new QCheckBox(InterpSetGB);
        USeAICB->setObjectName(QString::fromUtf8("USeAICB"));
        USeAICB->setGeometry(QRect(531, 24, 22, 20));
        USeAICB->setChecked(true);
        UpscaleSetGB = new QGroupBox(SettingsTab);
        UpscaleSetGB->setObjectName(QString::fromUtf8("UpscaleSetGB"));
        UpscaleSetGB->setGeometry(QRect(14, 185, 559, 64));
        UpscaleSetGB->setAlignment(Qt::AlignCenter);
        UpscaleSetGB->setCheckable(true);
        UpscaleSetGB->setChecked(false);
        OutputResLabel = new QLabel(UpscaleSetGB);
        OutputResLabel->setObjectName(QString::fromUtf8("OutputResLabel"));
        OutputResLabel->setGeometry(QRect(18, 27, 137, 16));
        OutputResDD = new QComboBox(UpscaleSetGB);
        OutputResDD->addItem(QString());
        OutputResDD->addItem(QString());
        OutputResDD->addItem(QString());
        OutputResDD->addItem(QString());
        OutputResDD->setObjectName(QString::fromUtf8("OutputResDD"));
        OutputResDD->setGeometry(QRect(425, 25, 119, 22));
        Tabs->addTab(SettingsTab, QString());
        QueueTab = new QWidget();
        QueueTab->setObjectName(QString::fromUtf8("QueueTab"));
        JobQueue = new QTableWidget(QueueTab);
        if (JobQueue->columnCount() < 6)
            JobQueue->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        JobQueue->setObjectName(QString::fromUtf8("JobQueue"));
        JobQueue->setGeometry(QRect(6, 36, 574, 262));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JobQueue->sizePolicy().hasHeightForWidth());
        JobQueue->setSizePolicy(sizePolicy);
        JobQueue->setFocusPolicy(Qt::NoFocus);
        JobQueue->setContextMenuPolicy(Qt::CustomContextMenu);
        JobQueue->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        JobQueue->setEditTriggers(QAbstractItemView::NoEditTriggers);
        JobQueue->setSelectionMode(QAbstractItemView::NoSelection);
        JobQueue->setSelectionBehavior(QAbstractItemView::SelectRows);
        JobQueue->setRowCount(0);
        JobQueue->setColumnCount(6);
        JobQueue->horizontalHeader()->setVisible(true);
        JobQueue->horizontalHeader()->setCascadingSectionResizes(false);
        JobQueue->horizontalHeader()->setMinimumSectionSize(50);
        JobQueue->horizontalHeader()->setDefaultSectionSize(100);
        JobQueue->horizontalHeader()->setHighlightSections(false);
        JobQueue->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        JobQueue->horizontalHeader()->setStretchLastSection(true);
        JobQueue->verticalHeader()->setVisible(false);
        JobQueue->verticalHeader()->setCascadingSectionResizes(false);
        JobQueue->verticalHeader()->setMinimumSectionSize(25);
        JobQueue->verticalHeader()->setDefaultSectionSize(25);
        JobQueue->verticalHeader()->setHighlightSections(true);
        JobQueue->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        JobQueue->verticalHeader()->setStretchLastSection(false);
        JobQueueLabel = new QLabel(QueueTab);
        JobQueueLabel->setObjectName(QString::fromUtf8("JobQueueLabel"));
        JobQueueLabel->setGeometry(QRect(7, 5, 83, 23));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        JobQueueLabel->setFont(font1);
        ClearJobsBttn = new QPushButton(QueueTab);
        ClearJobsBttn->setObjectName(QString::fromUtf8("ClearJobsBttn"));
        ClearJobsBttn->setGeometry(QRect(421, 6, 159, 24));
        CancelQueueBttn = new QPushButton(QueueTab);
        CancelQueueBttn->setObjectName(QString::fromUtf8("CancelQueueBttn"));
        CancelQueueBttn->setGeometry(QRect(300, 6, 116, 24));
        Tabs->addTab(QueueTab, QString());
        AboutTab = new QWidget();
        AboutTab->setObjectName(QString::fromUtf8("AboutTab"));
        DonateGB = new QGroupBox(AboutTab);
        DonateGB->setObjectName(QString::fromUtf8("DonateGB"));
        DonateGB->setGeometry(QRect(15, 121, 403, 75));
        DonateGB->setAlignment(Qt::AlignCenter);
        DonateToDaGooseLabel = new QLabel(DonateGB);
        DonateToDaGooseLabel->setObjectName(QString::fromUtf8("DonateToDaGooseLabel"));
        DonateToDaGooseLabel->setGeometry(QRect(24, 32, 172, 16));
        DonateToDaGooseBttn = new QPushButton(DonateGB);
        DonateToDaGooseBttn->setObjectName(QString::fromUtf8("DonateToDaGooseBttn"));
        DonateToDaGooseBttn->setGeometry(QRect(283, 22, 103, 38));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/FrameGUI/pp_donate.png"), QSize(), QIcon::Normal, QIcon::Off);
        DonateToDaGooseBttn->setIcon(icon1);
        DonateToDaGooseBttn->setIconSize(QSize(90, 35));
        AboutGUIGB = new QGroupBox(AboutTab);
        AboutGUIGB->setObjectName(QString::fromUtf8("AboutGUIGB"));
        AboutGUIGB->setGeometry(QRect(14, 13, 555, 101));
        AboutGUIGB->setAlignment(Qt::AlignCenter);
        AboutGuiLabel = new QLabel(AboutGUIGB);
        AboutGuiLabel->setObjectName(QString::fromUtf8("AboutGuiLabel"));
        AboutGuiLabel->setGeometry(QRect(15, 29, 526, 54));
        AboutGuiLabel->setTextFormat(Qt::RichText);
        AboutGuiLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        AboutGuiLabel->setWordWrap(true);
        AboutGuiLabel->setOpenExternalLinks(true);
        LinksGB = new QGroupBox(AboutTab);
        LinksGB->setObjectName(QString::fromUtf8("LinksGB"));
        LinksGB->setGeometry(QRect(435, 121, 134, 162));
        LinksGB->setAlignment(Qt::AlignCenter);
        YoutubeBttn = new QPushButton(LinksGB);
        YoutubeBttn->setObjectName(QString::fromUtf8("YoutubeBttn"));
        YoutubeBttn->setGeometry(QRect(15, 24, 105, 35));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/FrameGUI/yt_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        YoutubeBttn->setIcon(icon2);
        YoutubeBttn->setIconSize(QSize(90, 35));
        DiscordBttn = new QPushButton(LinksGB);
        DiscordBttn->setObjectName(QString::fromUtf8("DiscordBttn"));
        DiscordBttn->setGeometry(QRect(15, 70, 105, 35));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/FrameGUI/discord_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DiscordBttn->setIcon(icon3);
        DiscordBttn->setIconSize(QSize(90, 35));
        InstaBttn = new QPushButton(LinksGB);
        InstaBttn->setObjectName(QString::fromUtf8("InstaBttn"));
        InstaBttn->setGeometry(QRect(15, 116, 105, 35));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/FrameGUI/ig_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        InstaBttn->setIcon(icon4);
        InstaBttn->setIconSize(QSize(90, 35));
        ClearBttn = new QPushButton(AboutTab);
        ClearBttn->setObjectName(QString::fromUtf8("ClearBttn"));
        ClearBttn->setGeometry(QRect(15, 258, 284, 24));
        LicensesBttn = new QPushButton(AboutTab);
        LicensesBttn->setObjectName(QString::fromUtf8("LicensesBttn"));
        LicensesBttn->setGeometry(QRect(305, 258, 114, 24));
        Tabs->addTab(AboutTab, QString());
        SaveOutTxtBox = new QLineEdit(centralWidget);
        SaveOutTxtBox->setObjectName(QString::fromUtf8("SaveOutTxtBox"));
        SaveOutTxtBox->setGeometry(QRect(5, 343, 305, 22));
        SaveOutTxtBox->setReadOnly(true);
        AddJobBttn = new QPushButton(centralWidget);
        AddJobBttn->setObjectName(QString::fromUtf8("AddJobBttn"));
        AddJobBttn->setGeometry(QRect(470, 342, 64, 24));
        EncodeProgress = new QProgressBar(centralWidget);
        EncodeProgress->setObjectName(QString::fromUtf8("EncodeProgress"));
        EncodeProgress->setGeometry(QRect(5, 371, 590, 23));
        EncodeProgress->setValue(0);
        EncodeProgress->setTextVisible(false);
        OutContainerDD = new QComboBox(centralWidget);
        OutContainerDD->addItem(QString());
        OutContainerDD->addItem(QString());
        OutContainerDD->addItem(QString());
        OutContainerDD->addItem(QString());
        OutContainerDD->setObjectName(QString::fromUtf8("OutContainerDD"));
        OutContainerDD->setGeometry(QRect(317, 343, 54, 22));
        SaveOutBttn = new QPushButton(centralWidget);
        SaveOutBttn->setObjectName(QString::fromUtf8("SaveOutBttn"));
        SaveOutBttn->setGeometry(QRect(378, 342, 86, 24));
        StartEncBttn = new QPushButton(centralWidget);
        StartEncBttn->setObjectName(QString::fromUtf8("StartEncBttn"));
        StartEncBttn->setGeometry(QRect(540, 342, 56, 24));
        StartEncBttn->setFont(font);
        ProgressBarLabel = new QLabel(centralWidget);
        ProgressBarLabel->setObjectName(QString::fromUtf8("ProgressBarLabel"));
        ProgressBarLabel->setGeometry(QRect(6, 371, 588, 22));
        ProgressBarLabel->setFont(font);
        ProgressBarLabel->setAlignment(Qt::AlignCenter);
        FrameGUIClass->setCentralWidget(centralWidget);

        retranslateUi(FrameGUIClass);

        Tabs->setCurrentIndex(0);
        OutFPSDD->setCurrentIndex(4);
        OutputResDD->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(FrameGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *FrameGUIClass)
    {
        FrameGUIClass->setWindowTitle(QCoreApplication::translate("FrameGUIClass", "FrameGUI v2.2.0", nullptr));
#if QT_CONFIG(tooltip)
        LogoLabel->setToolTip(QCoreApplication::translate("FrameGUIClass", "FrameGUI :)", nullptr));
#endif // QT_CONFIG(tooltip)
        LogoLabel->setText(QString());
        CurrentProcessGB->setTitle(QCoreApplication::translate("FrameGUIClass", "Current Process", nullptr));
#if QT_CONFIG(tooltip)
        PauseBttn->setToolTip(QCoreApplication::translate("FrameGUIClass", "Pauses the current running process.", nullptr));
#endif // QT_CONFIG(tooltip)
        PauseBttn->setText(QCoreApplication::translate("FrameGUIClass", "Pause", nullptr));
#if QT_CONFIG(tooltip)
        CancelBttn->setToolTip(QCoreApplication::translate("FrameGUIClass", "Cancels the current running process.", nullptr));
#endif // QT_CONFIG(tooltip)
        CancelBttn->setText(QCoreApplication::translate("FrameGUIClass", "Cancel", nullptr));
        JobIDLabel->setText(QCoreApplication::translate("FrameGUIClass", "ID:", nullptr));
        StatusLabel->setText(QCoreApplication::translate("FrameGUIClass", "Status:", nullptr));
        JobStatusValueLabel->setText(QCoreApplication::translate("FrameGUIClass", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">?</span></p></body></html>", nullptr));
        JobIDValueLabel->setText(QCoreApplication::translate("FrameGUIClass", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">?</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        SelectInTxtBox->setToolTip(QCoreApplication::translate("FrameGUIClass", "The source video file path.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SelectInBttn->setToolTip(QCoreApplication::translate("FrameGUIClass", "Opens a dialog to select the source video.", nullptr));
#endif // QT_CONFIG(tooltip)
        SelectInBttn->setText(QCoreApplication::translate("FrameGUIClass", "Select Input", nullptr));
        Tabs->setTabText(Tabs->indexOf(MainTab), QCoreApplication::translate("FrameGUIClass", "Main", nullptr));
        EncodeSetGB->setTitle(QCoreApplication::translate("FrameGUIClass", "Encoding", nullptr));
        IWantDD->setItemText(0, QCoreApplication::translate("FrameGUIClass", "High quality video with an AVERAGE file size (fast render - x264)", nullptr));
        IWantDD->setItemText(1, QCoreApplication::translate("FrameGUIClass", "High quality video with a SMALL file size (slow render - x265)", nullptr));

        IWantLabel->setText(QCoreApplication::translate("FrameGUIClass", "I want a:", nullptr));
#if QT_CONFIG(tooltip)
        InterpSetGB->setToolTip(QCoreApplication::translate("FrameGUIClass", "Enables frame interpolation or reduction.", nullptr));
#endif // QT_CONFIG(tooltip)
        InterpSetGB->setTitle(QCoreApplication::translate("FrameGUIClass", "Convert FPS (RIFE / SVPFlow)", nullptr));
        OutFPSLabel->setText(QCoreApplication::translate("FrameGUIClass", "Select output FPS:", nullptr));
        OutFPSDD->setItemText(0, QCoreApplication::translate("FrameGUIClass", "240", nullptr));
        OutFPSDD->setItemText(1, QCoreApplication::translate("FrameGUIClass", "144", nullptr));
        OutFPSDD->setItemText(2, QCoreApplication::translate("FrameGUIClass", "120", nullptr));
        OutFPSDD->setItemText(3, QCoreApplication::translate("FrameGUIClass", "90", nullptr));
        OutFPSDD->setItemText(4, QCoreApplication::translate("FrameGUIClass", "60", nullptr));
        OutFPSDD->setItemText(5, QCoreApplication::translate("FrameGUIClass", "50", nullptr));
        OutFPSDD->setItemText(6, QCoreApplication::translate("FrameGUIClass", "48", nullptr));
        OutFPSDD->setItemText(7, QCoreApplication::translate("FrameGUIClass", "30", nullptr));
        OutFPSDD->setItemText(8, QCoreApplication::translate("FrameGUIClass", "25", nullptr));
        OutFPSDD->setItemText(9, QCoreApplication::translate("FrameGUIClass", "24", nullptr));
        OutFPSDD->setItemText(10, QCoreApplication::translate("FrameGUIClass", "15", nullptr));

#if QT_CONFIG(tooltip)
        OutFPSDD->setToolTip(QCoreApplication::translate("FrameGUIClass", "The output video frame rate.", nullptr));
#endif // QT_CONFIG(tooltip)
        UseAILabel->setText(QCoreApplication::translate("FrameGUIClass", "Use AI for better quality conversion (slower and may not work on all PCs)?:", nullptr));
        USeAICB->setText(QString());
#if QT_CONFIG(tooltip)
        UpscaleSetGB->setToolTip(QCoreApplication::translate("FrameGUIClass", "Enables video resolution upscaling.", nullptr));
#endif // QT_CONFIG(tooltip)
        UpscaleSetGB->setTitle(QCoreApplication::translate("FrameGUIClass", "Upscale (SRMD)", nullptr));
        OutputResLabel->setText(QCoreApplication::translate("FrameGUIClass", "Select output resolution:", nullptr));
        OutputResDD->setItemText(0, QCoreApplication::translate("FrameGUIClass", "4K UHD (2160p)", nullptr));
        OutputResDD->setItemText(1, QCoreApplication::translate("FrameGUIClass", "QHD (1440p)", nullptr));
        OutputResDD->setItemText(2, QCoreApplication::translate("FrameGUIClass", "FHD (1080p)", nullptr));
        OutputResDD->setItemText(3, QCoreApplication::translate("FrameGUIClass", "HD (720p)", nullptr));

#if QT_CONFIG(tooltip)
        OutputResDD->setToolTip(QCoreApplication::translate("FrameGUIClass", "The output video resolution/quality.", nullptr));
#endif // QT_CONFIG(tooltip)
        Tabs->setTabText(Tabs->indexOf(SettingsTab), QCoreApplication::translate("FrameGUIClass", "Settings", nullptr));
        QTableWidgetItem *___qtablewidgetitem = JobQueue->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FrameGUIClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = JobQueue->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FrameGUIClass", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = JobQueue->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FrameGUIClass", "Progress", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = JobQueue->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("FrameGUIClass", "Input", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = JobQueue->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("FrameGUIClass", "Output", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = JobQueue->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("FrameGUIClass", "Logs", nullptr));
        JobQueueLabel->setText(QCoreApplication::translate("FrameGUIClass", "Job Queue", nullptr));
        ClearJobsBttn->setText(QCoreApplication::translate("FrameGUIClass", "Clear All Finished Jobs", nullptr));
        CancelQueueBttn->setText(QCoreApplication::translate("FrameGUIClass", "Cancel All Jobs", nullptr));
        Tabs->setTabText(Tabs->indexOf(QueueTab), QCoreApplication::translate("FrameGUIClass", "Queue", nullptr));
        DonateGB->setTitle(QCoreApplication::translate("FrameGUIClass", "Donate", nullptr));
        DonateToDaGooseLabel->setText(QCoreApplication::translate("FrameGUIClass", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">Goose</span><span style=\" font-weight:700;\"> (developer &amp; owner):</span></p></body></html>", nullptr));
        DonateToDaGooseBttn->setText(QString());
        AboutGUIGB->setTitle(QCoreApplication::translate("FrameGUIClass", "About FrameGUI", nullptr));
        AboutGuiLabel->setText(QCoreApplication::translate("FrameGUIClass", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">FrameGUI (frame-gooey) is the newest and most convenient encoding application ever made. Since v2.0.0, FrameGUI now features powerful AI tools to upscale and convert video FPS. It's so easy to use, ANYONE regardless of video encoding knowledge can use it!</span></p></body></html>", nullptr));
        LinksGB->setTitle(QCoreApplication::translate("FrameGUIClass", "DaGoose's Links", nullptr));
        YoutubeBttn->setText(QString());
        DiscordBttn->setText(QString());
        InstaBttn->setText(QString());
        ClearBttn->setText(QCoreApplication::translate("FrameGUIClass", "Clear saved data", nullptr));
        LicensesBttn->setText(QCoreApplication::translate("FrameGUIClass", "Licenses", nullptr));
        Tabs->setTabText(Tabs->indexOf(AboutTab), QCoreApplication::translate("FrameGUIClass", "About / Donate", nullptr));
#if QT_CONFIG(tooltip)
        SaveOutTxtBox->setToolTip(QCoreApplication::translate("FrameGUIClass", "The output destination path.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        AddJobBttn->setToolTip(QCoreApplication::translate("FrameGUIClass", "Creates a job for the work queue using the current user defined settings.", nullptr));
#endif // QT_CONFIG(tooltip)
        AddJobBttn->setText(QCoreApplication::translate("FrameGUIClass", "Add Job", nullptr));
        OutContainerDD->setItemText(0, QCoreApplication::translate("FrameGUIClass", ".mp4", nullptr));
        OutContainerDD->setItemText(1, QCoreApplication::translate("FrameGUIClass", ".mkv", nullptr));
        OutContainerDD->setItemText(2, QCoreApplication::translate("FrameGUIClass", ".mov", nullptr));
        OutContainerDD->setItemText(3, QCoreApplication::translate("FrameGUIClass", ".avi", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerDD->setToolTip(QCoreApplication::translate("FrameGUIClass", "The output video container", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SaveOutBttn->setToolTip(QCoreApplication::translate("FrameGUIClass", "Opens a dialog to save the output video to a filename.", nullptr));
#endif // QT_CONFIG(tooltip)
        SaveOutBttn->setText(QCoreApplication::translate("FrameGUIClass", "Save Output", nullptr));
#if QT_CONFIG(tooltip)
        StartEncBttn->setToolTip(QCoreApplication::translate("FrameGUIClass", "Starts the job queue.", nullptr));
#endif // QT_CONFIG(tooltip)
        StartEncBttn->setText(QCoreApplication::translate("FrameGUIClass", "Start", nullptr));
        ProgressBarLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrameGUIClass: public Ui_FrameGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMEGUI_H
