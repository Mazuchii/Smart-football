#include "equipe.h"

Equipe::Equipe() {}

Equipe::Equipe(int nb_jr, QString nom_eq, QString paye_q, int rang_eq, QString entraineur)
{
    this->nb_jr = nb_jr;
    this->nom_eq = nom_eq;
    this->paye_q = paye_q;
    this->rang_eq = rang_eq;
    this->entraineur = entraineur;
}

bool Equipe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPE (NB_JR, NOM_EQ, PAYE_Q, RANG_EQ, ENTRAINEUR) "
                  "VALUES (:nb_jr, :nom_eq, :paye_q, :rang_eq, :entraineur)");
    query.bindValue(":nb_jr", nb_jr);
    query.bindValue(":nom_eq", nom_eq);
    query.bindValue(":paye_q", paye_q);
    query.bindValue(":rang_eq", rang_eq);
    query.bindValue(":entraineur", entraineur);

    return query.exec();
}
