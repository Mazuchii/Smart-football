#include "match.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.createConnection();
    if (!test) {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to connect to database. Application will exit.");
        return -1; // Exit with error code
    }


    Match w;
    w.show();
    return a.exec();
}
