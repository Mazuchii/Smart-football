#ifndef GESMATCH_H
#define GESMATCH_H

#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

class GesMatch
{

    int id_match;
    QDate date;
    QString type;
    int id_equipe1;
    int id_equipe2;
    int id_stade;
    int score1;
    int score2;

public:
    // Constructors
    GesMatch();
    GesMatch(int, QDate, QString, int, int, int, int, int);

    // Getters
    int getId() const { return id_match; }
    QDate getDate() const { return date; }
    QString getType() const { return type; }
    int getEquipe1() const { return id_equipe1; }
    int getEquipe2() const { return id_equipe2; }
    int getStade() const { return id_stade; }
    int getScore1() const { return score1; }
    int getScore2() const { return score2; }

    // Setters
    void setId(int id) { id_match = id; }
    void setDate(QDate d) { date = d; }
    void setType(QString t) { type = t; }
    void setEquipe1(int e) { id_equipe1 = e; }
    void setEquipe2(int e) { id_equipe2 = e; }
    void setStade(int s) { id_stade = s; }
    void setScore1(int s) { score1 = s; }
    void setScore2(int s) { score2 = s; }

    // CRUD Operations
    bool ajouter();
    bool modifier();
    bool supprimer(int);
    static QSqlQueryModel* afficher();
    static QSqlQuery rechercher(int id);
};

#endif // GESMATCH_H
