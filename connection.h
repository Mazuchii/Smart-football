#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connexion {
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

private:
    QSqlDatabase db;
};

#endif // CONNECTION_H