#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connexion::Connexion() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("123456");
}

bool Connexion::ouvrirConnexion() {
    if (db.open()) {
        qDebug() << "Connexion réussie à la base de données!";
        return true;
    } else {
        qDebug() << "Échec de la connexion :" << db.lastError().text();
        return false;
    }
}

void Connexion::fermerConnexion() {
    db.close();
}
