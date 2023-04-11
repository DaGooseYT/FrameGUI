#pragma once

#ifndef UPDATER
#define UPDATER

#include "../x64/Release/uic/ui_update.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QDialog>

class Update : public QDialog {
public:
	Update(QWidget* parent = Q_NULLPTR);
	void setText(QString text);

	QPushButton* getSkip();
	QPushButton* getNow();
	QPushButton* getLater();

private:
	Ui::Update _up;
};

#endif // !UPDATER