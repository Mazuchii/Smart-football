#include "connection.h"
#include <QSqlError>
#include <QDebug>

// Constructeur (doit exister)
Connexion::Connexion() {
    db = QSqlDatabase::addDatabase("QODBC");  // Assigner le type de base de données
    db.setDatabaseName("Source_Projet2A");   // Nom ODBC
    db.setUserName("system");                // Nom d'utilisateur Oracle
    db.setPassword("123456");                // Mot de passe Oracle
}

// Méthode pour ouvrir la connexion
bool Connexion::createConnection() {
    if (!db.open()) {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
        return false;
    }
    qDebug() << "Connexion réussie !";
    return true;
}

void Connexion::closeConnection(){db.close();}
