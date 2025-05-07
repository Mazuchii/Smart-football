#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connexion {

    QSqlDatabase db;

public:
    Connexion();   // Vérifie bien que le constructeur est déclaré ici
    bool createConnection();
    void closeConnection();
};

#endif // CONNECTION_H
