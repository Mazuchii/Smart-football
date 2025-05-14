#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QMap>  // Added for QMap
#include <QPair> // Added for QPair

class Employe
{
private:
    int id_emp;
    QString nom;
    QString prenom;
    QString adresse;
    QString num_tel_emp;
    QDate date_naiss_emp;
    QString poste;
    double salaire;
    QString statut;
    QString sexe;
    QString mdp;

public:
    Employe();
    Employe(int id, QString n, QString p, QString adr, QString tel, QDate dateN,
            QString post, double sal, QString stat, QString sex, QString pass);

    // Getters
    int getIdEmp() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getAdresse() const;
    QString getNumTelEmp() const;
    QDate getDateNaissEmp() const;
    QString getPoste() const;
    double getSalaire() const;
    QString getStatut() const;
    QString getSexe() const;
    QString getMdp() const;

    // Setters
    void setIdEmp(int id);
    void setNom(const QString &n);
    void setPrenom(const QString &p);
    void setAdresse(const QString &adr);
    void setNumTelEmp(const QString &tel);
    void setDateNaissEmp(const QDate &dateN);
    void setPoste(const QString &post);
    void setSalaire(double sal);
    void setStatut(const QString &stat);
    void setSexe(const QString &sex);
    void setMdp(const QString &pass);

    // Database Methods
    bool ajouter();
    bool modifier(int id_to_update);
    static QSqlQueryModel* afficher(QString filter = "", QString sortBy = "ID_EMP");
    static Employe chercher(int id);
    static bool supprimer(int id);

    // Add the new static method for calculating post statistics
    static QMap<QString, QPair<int, double>> calculerStatistiquesPoste();
};

#endif // EMPLOYE_H
