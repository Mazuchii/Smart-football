#ifndef JOUEUR_H
#define JOUEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Joueur {
private:
    int id_joueur;
    QString nom;
    QString prenom;
    QString ddn;
    int num_joueur;
    QString nom_eq;

public:
    Joueur();
    Joueur(int id_joueur, QString nom, QString prenom, QString ddn, int num_joueur, QString nom_eq);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id_joueur);
    bool modifier(int id_joueur, int num_joueur, QString nom_eq);
    QSqlQuery rechercher(int id_joueur);
    QSqlQueryModel* rechercherParNom(QString nom);
    QSqlQueryModel* trierParID();
    QSqlQueryModel* trierParNom();
    QSqlQueryModel* trierParPrenom();
    QSqlQueryModel* trierParNumero();
    QSqlQueryModel* getEquipeStats();
    bool idExists(int id_joueur);
    bool nomEqExists(QString nom_eq);
    bool addPlayerMatch(int id_joueur, int id_match, int buts, int assists);
    QSqlQueryModel* getPlayerMatchPerformance(int id_joueur);
    QSqlQueryModel* getAggregatedPerformance();
    QSqlQueryModel* getPerformanceTrends(int id_joueur, int lastNMatches);
    QSqlQueryModel* getMatchImpactScores(int id_joueur);
};

#endif // JOUEUR_H
