#include <QtGui/QApplication>
#include "marcs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MARCS w;

    w.show();

    return a.exec();
}
