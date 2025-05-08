#ifndef EQUIPE_H
#define EQUIPE_H

#include <QString>
#include <QSqlQuery>

class Equipe
{
public:
    Equipe();
    Equipe(int nb_jr, QString nom_eq, QString paye_q, int rang_eq, QString entraineur);

    bool ajouter();

private:
    int nb_jr, rang_eq;
    QString nom_eq, paye_q, entraineur;
};

#endif // EQUIPE_H
