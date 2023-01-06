/********************************************************************************
** Form generated from reading UI file 'Update.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Update
{
public:
    QLabel *TitleLabel;
    QLabel *ToDoLabel;
    QPushButton *UpdateBttn;
    QPushButton *RemindBttn;
    QPushButton *SkipBttn;
    QTextBrowser *textBrowser;
    QLabel *DetailsLabel;

    void setupUi(QWidget *Update)
    {
        if (Update->objectName().isEmpty())
            Update->setObjectName(QString::fromUtf8("Update"));
        Update->resize(551, 294);
        Update->setMinimumSize(QSize(551, 294));
        Update->setMaximumSize(QSize(551, 294));
        TitleLabel = new QLabel(Update);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(175, 7, 200, 32));
        ToDoLabel = new QLabel(Update);
        ToDoLabel->setObjectName(QString::fromUtf8("ToDoLabel"));
        ToDoLabel->setGeometry(QRect(9, 266, 97, 16));
        UpdateBttn = new QPushButton(Update);
        UpdateBttn->setObjectName(QString::fromUtf8("UpdateBttn"));
        UpdateBttn->setGeometry(QRect(209, 263, 93, 24));
        QFont font;
        font.setBold(true);
        UpdateBttn->setFont(font);
        RemindBttn = new QPushButton(Update);
        RemindBttn->setObjectName(QString::fromUtf8("RemindBttn"));
        RemindBttn->setGeometry(QRect(309, 263, 116, 24));
        SkipBttn = new QPushButton(Update);
        SkipBttn->setObjectName(QString::fromUtf8("SkipBttn"));
        SkipBttn->setGeometry(QRect(432, 263, 112, 24));
        textBrowser = new QTextBrowser(Update);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(8, 63, 536, 192));
        DetailsLabel = new QLabel(Update);
        DetailsLabel->setObjectName(QString::fromUtf8("DetailsLabel"));
        DetailsLabel->setGeometry(QRect(106, 38, 341, 20));
        DetailsLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Update);

        QMetaObject::connectSlotsByName(Update);
    } // setupUi

    void retranslateUi(QWidget *Update)
    {
        Update->setWindowTitle(QCoreApplication::translate("Update", "FrameGUI - Updates", nullptr));
        TitleLabel->setText(QCoreApplication::translate("Update", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">It's Time to Update!</span></p></body></html>", nullptr));
        ToDoLabel->setText(QCoreApplication::translate("Update", "Choose an action:", nullptr));
        UpdateBttn->setText(QCoreApplication::translate("Update", "Update Now", nullptr));
        RemindBttn->setText(QCoreApplication::translate("Update", "Remind Me Later", nullptr));
        SkipBttn->setText(QCoreApplication::translate("Update", "Skip This Update", nullptr));
        DetailsLabel->setText(QCoreApplication::translate("Update", "Below are the details for the next new update for FrameGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Update: public Ui_Update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_H
