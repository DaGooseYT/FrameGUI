#include "framegui.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrameGUI w;
    w.show();
    return(a.exec());
}
