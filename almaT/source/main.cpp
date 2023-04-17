#include "almat.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    almat w;
    w.show();
    return a.exec();
}
