#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDate>
#include <QObject>

#include <QMap>

class Employee: public QObject
{
Q_OBJECT
public:

    Employee();
    Employee(int id, const QString& nom, const QString& prenom, const QString& numTel,
             const QDate& dateNaiss, const QString& poste, double salaire,
             const QString& sexe, const QString& niveauExp);

    // CRUD operations
    bool create();
    bool update();
    bool remove(int id);
    static QSqlQueryModel* getAll();
 static QMap<QString, double> calculerStatistiquesSexe();
    // Getters
    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getNumTel() const;
    QDate getDateNaissance() const;
    QString getPoste() const;
    double getSalaire() const;
    QString getSexe() const;
    QString getNiveauExp() const;
    QString getLastError() const;

    // Setters
    void setId(int id);
    void setNom(const QString& nom);
    void setPrenom(const QString& prenom);
    void setNumTel(const QString& numTel);
    void setDateNaissance(const QDate& date);
    void setPoste(const QString& poste);
    void setSalaire(double salaire);
    void setSexe(const QString& sexe);
    void setNiveauExp(const QString& niveauExp);

    // Database initialization
    static bool initializeDatabase();

private:
    int m_id;
    QString m_nom;
    QString m_prenom;
    QString m_numTel;
    QDate m_dateNaissance;
    QString m_poste;
    double m_salaire;
    QString m_sexe;
    QString m_niveauExp;
    QString m_lastError;

};

#endif // EMPLOYEE_H
