#include "CCValGui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCValGui w;
    w.show();
    return a.exec();
}
