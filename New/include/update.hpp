#pragma once

#ifndef UPDATER
#define UPDATER

#include <QtWidgets/QPushButton>
#include <QtWidgets/QDialog>

#ifdef Q_OS_WINDOWS
#include "windows/ui_update.hpp"
#endif
#ifdef Q_OS_DARWIN
#include "darwin/ui_update.hpp"
#endif

class Update : public QDialog {
public:
	Update(QWidget *parent = Q_NULLPTR);
	void setText(QString text);

	Ui::Update *getUpdate();
	QPushButton *getSkip();
	QPushButton *getNow();
	QPushButton *getLater();

private:
	Ui::Update *_up;
};

#endif // !UPDATER