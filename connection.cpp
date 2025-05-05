#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connexion::Connexion() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_Source2A"); // Nom de la source de données ODBC
    db.setUserName("system"); // Nom d'utilisateur Oracle
    db.setPassword("123456"); // Mot de passe Oracle
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
