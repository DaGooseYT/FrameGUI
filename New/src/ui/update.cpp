#include "update.hpp"

Update::Update(QWidget* parent) : QDialog(parent) {
	_up = new Ui::Update();
	_up->setupUi(this);
}

void Update::setText(QString text) {
	_up->textBrowser->insertPlainText(text + QString("\n"));
}

QPushButton *Update::getSkip() {
	return(_up->SkipBttn);
}

QPushButton *Update::getNow() {
	return(_up->UpdateBttn);
}

QPushButton *Update::getLater() {
	return(_up->RemindBttn);
}

Ui::Update *Update::getUpdate() {
	return(_up);
}