#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test = c.ouvrirConnexion();

    if (test) {
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Connexion échouée"),
                              QObject::tr("Échec de la connexion à la base de données.\nCliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
        return -1;
    }
}
