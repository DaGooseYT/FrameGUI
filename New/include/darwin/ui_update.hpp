#ifndef UPDATETIKRXK_H
#define UPDATETIKRXK_H

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
        Update->resize(550, 294);
        Update->setMinimumSize(QSize(550, 294));
        Update->setMaximumSize(QSize(550, 294));
        TitleLabel = new QLabel(Update);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(200, 7, 150, 32));
        TitleLabel->setAlignment(Qt::AlignCenter);
        ToDoLabel = new QLabel(Update);
        ToDoLabel->setObjectName(QString::fromUtf8("ToDoLabel"));
        ToDoLabel->setGeometry(QRect(7, 264, 111, 16));
        UpdateBttn = new QPushButton(Update);
        UpdateBttn->setObjectName(QString::fromUtf8("UpdateBttn"));
        UpdateBttn->setGeometry(QRect(200, 259, 95, 32));
        UpdateBttn->setMinimumSize(QSize(0, 32));
        UpdateBttn->setSizeIncrement(QSize(0, 32));
        QFont font;
        font.setBold(true);
        UpdateBttn->setFont(font);
        UpdateBttn->setFocusPolicy(Qt::NoFocus);
        RemindBttn = new QPushButton(Update);
        RemindBttn->setObjectName(QString::fromUtf8("RemindBttn"));
        RemindBttn->setGeometry(QRect(300, 259, 120, 32));
        RemindBttn->setMinimumSize(QSize(0, 32));
        RemindBttn->setSizeIncrement(QSize(0, 32));
        RemindBttn->setFocusPolicy(Qt::NoFocus);
        SkipBttn = new QPushButton(Update);
        SkipBttn->setObjectName(QString::fromUtf8("SkipBttn"));
        SkipBttn->setGeometry(QRect(425, 259, 118, 32));
        SkipBttn->setMinimumSize(QSize(0, 32));
        SkipBttn->setSizeIncrement(QSize(0, 32));
        SkipBttn->setFocusPolicy(Qt::NoFocus);
        textBrowser = new QTextBrowser(Update);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(7, 63, 536, 192));
        DetailsLabel = new QLabel(Update);
        DetailsLabel->setObjectName(QString::fromUtf8("DetailsLabel"));
        DetailsLabel->setGeometry(QRect(95, 38, 360, 20));
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

#endif // UPDATETIKRXK_H
