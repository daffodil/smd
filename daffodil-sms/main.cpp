#include <QtGui/QApplication>
#include "mainobject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    MainObject m;

    return a.exec();
}
