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
    query.bindValue(":date_m", date);
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
    query.prepare(R"(
        UPDATE MATCH
        SET DATE_M = :date,
            TYPE_M = :type,
            ID_EQ1 = :id_eq1,
            ID_EQ2 = :id_eq2,
            ID_STADE = :id_stade
        WHERE ID_MATCH = :id
    )");

    query.bindValue(":id", id_match);
    query.bindValue(":date", date);
    query.bindValue(":type", type);
    query.bindValue(":id_eq1", id_equipe1);
    query.bindValue(":id_eq2", id_equipe2);
    query.bindValue(":id_stade", id_stade);

    if (!query.exec()) {
        qDebug() << "Erreur update:" << query.lastError().text();
    }

    return query.isActive();
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
            M.TYPE_M AS TYPE_M,
            E3.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE E3 ON M.ID_STADE = E3.ID_STADE
    )");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Équipe 1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Équipe 2"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STADE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));

    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans afficher() :" << model->lastError().text();
    }
    return model;
}


QSqlQuery GesMatch::rechercher(int id_match)
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT
            ID_MATCH,
            ID_EQ1,
            ID_EQ2,
            TYPE_M,
            ID_STADE,
            DATE_M,
            SCORE1,
            SCORE2
        FROM MATCH
        WHERE ID_MATCH = :id_match
    )");

    query.bindValue(":id_match", id_match);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche du match:" << query.lastError().text();
    }

    return query;
}

bool GesMatch::modifierScore(int id_match, int score1, int score2)
{
    QSqlQuery query;
    query.prepare(R"(
        UPDATE MATCH
        SET SCORE_EQ1 = :score1,
            SCORE_EQ2 = :score2
        WHERE ID_MATCH = :id_match
    )");

    query.bindValue(":score1", score1);
    query.bindValue(":score2", score2);
    query.bindValue(":id_match", id_match);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour du score:" << query.lastError().text();
        return false;
    }

    return true;
}

QString GesMatch::statistics(const QString& team1, const QString& team2)
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT
            E1.NOM_EQ AS EQUIPE1,
            E2.NOM_EQ AS EQUIPE2,
            M.SCORE_EQ1,
            M.SCORE_EQ2
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        WHERE
            (E1.NOM_EQ = :team1 AND E2.NOM_EQ = :team2)
            OR
            (E1.NOM_EQ = :team2 AND E2.NOM_EQ = :team1)
    )");
    query.bindValue(":team1", team1);
    query.bindValue(":team2", team2);

    int winsTeam1 = 0;
    int winsTeam2 = 0;
    int goalsTeam1 = 0;
    int goalsTeam2 = 0;

    if (!query.exec()) {
        qDebug() << "Erreur lors de statistics:" << query.lastError().text();
        return "Erreur lors de la récupération des statistiques.";
    }

    while (query.next()) {
        QString eq1 = query.value(0).toString();
        QString eq2 = query.value(1).toString();
        int score1 = query.value(2).toInt();
        int score2 = query.value(3).toInt();

        if (eq1 == team1 && eq2 == team2) {
            goalsTeam1 += score1;
            goalsTeam2 += score2;

            if (score1 > score2) winsTeam1++;
            else if (score2 > score1) winsTeam2++;
        } else {
            goalsTeam1 += score2;
            goalsTeam2 += score1;

            if (score2 > score1) winsTeam1++;
            else if (score1 > score2) winsTeam2++;
        }
    }

    // Prédiction simple basée sur le nombre de victoires
    QString prediction;
    if (winsTeam1 > winsTeam2)
        prediction = QString("👉 *Prévision : avantage à* **%1**").arg(team1);
    else if (winsTeam2 > winsTeam1)
        prediction = QString("👉 *Prévision : avantage à* **%1**").arg(team2);
    else
        prediction = "👉 *Prévision : match équilibré (égalité de victoires)*";

    QString stats = QString(
                        "Historique des confrontations :\n"
                        "%1 : %2 victoires, %3 buts\n"
                        "%4 : %5 victoires, %6 buts\n"
                        "%7"
                        ).arg(team1).arg(winsTeam1).arg(goalsTeam1)
                        .arg(team2).arg(winsTeam2).arg(goalsTeam2)
                        .arg(prediction);

    return stats;
}
