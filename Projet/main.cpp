#include "match.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Match w;
    w.show();
    return a.exec();
}
