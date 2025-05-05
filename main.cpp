#include "connection.h"
#include <QApplication>
#include "mainwindow.h"


// main.cpp
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Add this line once at startup:
    QSqlDatabase::addDatabase("QSQLITE", "employe_connection");  // Unique connection name

    // Rest of your code...
    MainWindow w;
    w.show();
    return a.exec();
}
