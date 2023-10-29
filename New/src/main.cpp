#include "framegui.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FrameGUI *w = new FrameGUI();
    w->show();
    return(a.exec());
}
