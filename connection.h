#ifndef CONNEXION_H
#define CONNEXION_H

#include <QString>
#include <QSqlDatabase>

class Connexion
{
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
