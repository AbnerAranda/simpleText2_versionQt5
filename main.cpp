#include "ppppp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ppppp w;
    w.show();
    return a.exec();
}
