#include "joueur.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

Joueur::Joueur() {
    id_joueur = 0;
    nom = "";
    prenom = "";
    ddn = "";
    num_joueur = 0;
    nom_eq = "";
}

Joueur::Joueur(int id_joueur, QString nom, QString prenom, QString ddn, int num_joueur, QString nom_eq) {
    this->id_joueur = id_joueur;
    this->nom = nom;
    this->prenom = prenom;
    this->ddn = ddn;
    this->num_joueur = num_joueur;
    this->nom_eq = nom_eq;
}

bool Joueur::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO JOUEUR (ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ) "
                  "VALUES (:id_joueur, :nom, :prenom, TO_DATE(:ddn, 'DD-MON-YYYY'), :num_joueur, :nom_eq)");
    query.bindValue(":id_joueur", id_joueur);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":ddn", ddn);
    query.bindValue(":num_joueur", num_joueur);
    query.bindValue(":nom_eq", nom_eq);

    if (!query.exec()) {
        qDebug() << "Error adding joueur:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Joueur::supprimer(int id_joueur) {
    QSqlQuery query;
    query.prepare("DELETE FROM JOUEUR WHERE ID_JOUEUR = :id_joueur");
    query.bindValue(":id_joueur", id_joueur);

    if (!query.exec()) {
        qDebug() << "Error deleting joueur:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Joueur::modifier(int id_joueur, int num_joueur, QString nom_eq) {
    QSqlQuery query;
    query.prepare("UPDATE JOUEUR SET NUM_JOUEUR = :num_joueur, NOM_EQ = :nom_eq WHERE ID_JOUEUR = :id_joueur");
    query.bindValue(":id_joueur", id_joueur);
    query.bindValue(":num_joueur", num_joueur);
    query.bindValue(":nom_eq", nom_eq);

    if (!query.exec()) {
        qDebug() << "Error modifying joueur:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Joueur::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ FROM JOUEUR");
    if (!query.exec()) {
        qDebug() << "Error executing afficher query:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

QSqlQuery Joueur::rechercher(int id_joueur) {
    QSqlQuery query;
    query.prepare("SELECT * FROM JOUEUR WHERE ID_JOUEUR = :id_joueur");
    query.bindValue(":id_joueur", id_joueur);
    query.exec();
    return query;
}

QSqlQueryModel* Joueur::rechercherParNom(QString nom) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ "
                  "FROM JOUEUR WHERE UPPER(NOM) LIKE UPPER(:nom)");
    query.bindValue(":nom", "%" + nom + "%");
    if (!query.exec()) {
        qDebug() << "Error searching joueur by nom:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

bool Joueur::idExists(int id_joueur) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM JOUEUR WHERE ID_JOUEUR = :id_joueur");
    query.bindValue(":id_joueur", id_joueur);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

bool Joueur::nomEqExists(QString nom_eq) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EQUIPE WHERE NOM_EQ = :nom_eq");
    query.bindValue(":nom_eq", nom_eq);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

QSqlQueryModel* Joueur::trierParID() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ FROM JOUEUR ORDER BY ID_JOUEUR");
    if (!query.exec()) {
        qDebug() << "Error sorting by ID:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Joueur::trierParNom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ FROM JOUEUR ORDER BY NOM");
    if (!query.exec()) {
        qDebug() << "Error sorting by Nom:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Joueur::trierParPrenom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ FROM JOUEUR ORDER BY PRENOM");
    if (!query.exec()) {
        qDebug() << "Error sorting by Prenom:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Joueur::trierParNumero() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_JOUEUR, NOM, PRENOM, DDN, NUM_JOUEUR, NOM_EQ FROM JOUEUR ORDER BY NUM_JOUEUR");
    if (!query.exec()) {
        qDebug() << "Error sorting by Numero:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Joueur::getEquipeStats() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT NOM_EQ, COUNT(*) as NB_JOUEURS FROM JOUEUR GROUP BY NOM_EQ");
    if (!query.exec()) {
        qDebug() << "Error getting equipe stats:" << query.lastError().text();
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Joueur::getPerformanceTrends(int id_joueur, int lastNMatches) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    qDebug() << "Fetching performance trends for player ID:" << id_joueur << "(last" << lastNMatches << "matches)";

    query.prepare("SELECT * FROM ("
                  "SELECT JM.ID_MATCH, M.DATE_M, JM.BUTS, JM.ASSISTS "
                  "FROM JOUEUR_MATCH JM "
                  "JOIN MATCH M ON JM.ID_MATCH = M.ID_MATCH "
                  "JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ "
                  "JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ "
                  "JOIN JOUEUR J ON JM.ID_JOUEUR = J.ID_JOUEUR "
                  "WHERE JM.ID_JOUEUR = :id_joueur "
                  "AND (UPPER(TRIM(J.NOM_EQ)) = UPPER(TRIM(E1.NOM_EQ)) OR UPPER(TRIM(J.NOM_EQ)) = UPPER(TRIM(E2.NOM_EQ))) "
                  "ORDER BY M.DATE_M DESC"
                  ") WHERE ROWNUM <= :lastNMatches");
    query.bindValue(":id_joueur", id_joueur);
    query.bindValue(":lastNMatches", lastNMatches);

    qDebug() << "Executing query:" << query.lastQuery();
    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Error setting model query:" << model->lastError().text();
    }

    if (model->rowCount() == 0) {
        QSqlQuery debugQuery;
        debugQuery.prepare("SELECT JM.ID_MATCH, E1.NOM_EQ AS TEAM1, E2.NOM_EQ AS TEAM2, J.NOM_EQ "
                           "FROM JOUEUR_MATCH JM "
                           "JOIN MATCH M ON JM.ID_MATCH = M.ID_MATCH "
                           "JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ "
                           "JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ "
                           "JOIN JOUEUR J ON JM.ID_JOUEUR = J.ID_JOUEUR "
                           "WHERE JM.ID_JOUEUR = :id_joueur");
        debugQuery.bindValue(":id_joueur", id_joueur);
        if (debugQuery.exec() && debugQuery.next()) {
            qDebug() << "Records found in JOUEUR_MATCH for ID" << id_joueur << ":";
            do {
                qDebug() << "Match ID:" << debugQuery.value("ID_MATCH").toInt()
                << "Player Team:" << debugQuery.value("NOM_EQ").toString()
                << "Match Teams:" << debugQuery.value("TEAM1").toString()
                << "vs" << debugQuery.value("TEAM2").toString();
            } while (debugQuery.next());
            qDebug() << "No records satisfy the team condition (NOM_EQ must match TEAM1 or TEAM2).";
        } else {
            qDebug() << "No records found in JOUEUR_MATCH for ID" << id_joueur << "or data is inconsistent.";
        }
    } else {
        qDebug() << "Number of trends found for player ID" << id_joueur << ":" << model->rowCount();
    }

    return model;
}

QSqlQueryModel* Joueur::getMatchImpactScores(int id_joueur) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    qDebug() << "Fetching match impact scores for player ID:" << id_joueur;

    query.prepare("SELECT JM.ID_MATCH, M.DATE_M, E1.NOM_EQ AS TEAM1, E2.NOM_EQ AS TEAM2, JM.BUTS, JM.ASSISTS, M.SCORE_EQ1, M.SCORE_EQ2, J.NOM_EQ, "
                  "CASE "
                  "    WHEN (J.NOM_EQ = E1.NOM_EQ AND M.SCORE_EQ1 > M.SCORE_EQ2) OR (J.NOM_EQ = E2.NOM_EQ AND M.SCORE_EQ2 > M.SCORE_EQ1) THEN 'Victoire' "
                  "    WHEN M.SCORE_EQ1 = M.SCORE_EQ2 THEN 'Nul' "
                  "    ELSE 'Défaite' "
                  "END as RESULTAT, "
                  "((JM.BUTS * 100) + (JM.ASSISTS * 50)) as IMPACT_SCORE "
                  "FROM JOUEUR_MATCH JM "
                  "JOIN MATCH M ON JM.ID_MATCH = M.ID_MATCH "
                  "JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ "
                  "JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ "
                  "JOIN JOUEUR J ON JM.ID_JOUEUR = J.ID_JOUEUR "
                  "WHERE JM.ID_JOUEUR = :id_joueur "
                  "AND (UPPER(TRIM(J.NOM_EQ)) = UPPER(TRIM(E1.NOM_EQ)) OR UPPER(TRIM(J.NOM_EQ)) = UPPER(TRIM(E2.NOM_EQ))) "
                  "ORDER BY M.DATE_M");
    query.bindValue(":id_joueur", id_joueur);

    qDebug() << "Executing query:" << query.lastQuery();
    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Error setting model query:" << model->lastError().text();
    }

    if (model->rowCount() == 0) {
        QSqlQuery debugQuery;
        debugQuery.prepare("SELECT JM.ID_MATCH, E1.NOM_EQ AS TEAM1, E2.NOM_EQ AS TEAM2, J.NOM_EQ "
                           "FROM JOUEUR_MATCH JM "
                           "JOIN MATCH M ON JM.ID_MATCH = M.ID_MATCH "
                           "JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ "
                           "JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ "
                           "JOIN JOUEUR J ON JM.ID_JOUEUR = J.ID_JOUEUR "
                           "WHERE JM.ID_JOUEUR = :id_joueur");
        debugQuery.bindValue(":id_joueur", id_joueur);
        if (debugQuery.exec() && debugQuery.next()) {
            qDebug() << "Records found in JOUEUR_MATCH for ID" << id_joueur << ":";
            do {
                qDebug() << "Match ID:" << debugQuery.value("ID_MATCH").toInt()
                << "Player Team:" << debugQuery.value("NOM_EQ").toString()
                << "Match Teams:" << debugQuery.value("TEAM1").toString()
                << "vs" << debugQuery.value("TEAM2").toString();
            } while (debugQuery.next());
            qDebug() << "No records satisfy the team condition (NOM_EQ must match TEAM1 or TEAM2).";
        } else {
            qDebug() << "No records found in JOUEUR_MATCH for ID" << id_joueur << "or data is inconsistent.";
        }
    } else {
        qDebug() << "Number of match impacts found for player ID" << id_joueur << ":" << model->rowCount();
    }

    return model;
}
