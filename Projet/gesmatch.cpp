#include "gesmatch.h"
#include <QString>
#include "qsqlerror.h"

GesMatch::GesMatch()
{
    id_match = 0;
    date = QDate::currentDate();
    type = "";
    id_equipe1 = 0;
    id_equipe2 = 0;
    id_stade = 0;
    score1 = 0;
    score2 = 0;
}

GesMatch::GesMatch(int id_match,QDate date,QString type,int id_equipe1,int id_equipe2,int id_stade,int score1,int score2)
{
    this->id_match=id_match;
    this->date=date;
    this->type=type;
    this->id_equipe1=id_equipe1;
    this->id_equipe2=id_equipe2;
    this->id_stade=id_stade;
    this->score1=score1;
    this->score2=score2;

}

bool GesMatch::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MATCH (DATE_M, TYPE_M, SCORE_EQ1, SCORE_EQ2, ID_STADE, ID_EQ1, ID_EQ2) "
                  "VALUES (:date_m, :type_m, :score_eq1, :score_eq2, :id_stade, :id_eq1, :id_eq2)");

    query.bindValue(":id_match", id_match);
    query.bindValue(":date_m", date.toString("dd-MM-yyyy"));
    query.bindValue(":type_m", type);
    query.bindValue(":score_eq1", score1);
    query.bindValue(":score_eq2", score2);
    query.bindValue(":id_stade", id_stade);
    query.bindValue(":id_eq1", id_equipe1);
    query.bindValue(":id_eq2", id_equipe2);

    if(!query.exec()) {
        qDebug() << "Error adding match:" << query.lastError().text();
        return false;
    }
    return true;
}

bool GesMatch::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE MATCH SET DATE_M = :date_m, TYPE_M = :type_m, "
                  "SCORE_EQ1 = :score_eq1, SCORE_EQ2 = :score_eq2, "
                  "ID_STADE = :id_stade, ID_EQ1 = :id_eq1, ID_EQ2 = :id_eq2 "
                  "WHERE ID_MATCH = :id_match");

    query.bindValue(":id_match", id_match);
    query.bindValue(":date_m", date.toString("dd-MM-yyyy"));
    query.bindValue(":type_m", type);
    query.bindValue(":score_eq1", score1);
    query.bindValue(":score_eq2", score2);
    query.bindValue(":id_stade", id_stade);
    query.bindValue(":id_eq1", id_equipe1);
    query.bindValue(":id_eq2", id_equipe2);

    if(!query.exec()) {
        qDebug() << "Error updating match:" << query.lastError().text();
        return false;
    }
    return true;
}

bool GesMatch::supprimer(int id_match)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MATCH WHERE ID_MATCH = :id_match");
    query.bindValue(":id_match", id_match);

    if(!query.exec()) {
        qDebug() << "Error deleting match:" << query.lastError().text();
        return false;
    }
    return true;
}
QSqlQueryModel* GesMatch::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(R"(
        SELECT
            M.ID_MATCH,
            E1.NOM_EQ AS EQUIPE_1,
            E2.NOM_EQ AS EQUIPE_2,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
    )");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Équipe 1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Équipe 2"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));

    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans afficher() :" << model->lastError().text();
    }
    return model;
}
/*
QSqlQuery GesMatch::rechercher(int id_match)
{

}
*/
