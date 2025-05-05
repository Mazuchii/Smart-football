#include "employe.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include <QSqlError> // Include for error reporting
#include <QMap>      // Include QMap again for implementation
#include <QVariant>

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase> // Include for checking DB connection
#include <QMap>
#include <QVariant>
#include <QDebug>
Employee::Employee() :
    m_id(0), m_salaire(0.0) {}

Employee::Employee(int id, const QString& nom, const QString& prenom, const QString& numTel,
                   const QDate& dateNaiss, const QString& poste, double salaire,
                   const QString& sexe, const QString& niveauExp) :
    m_id(id), m_nom(nom), m_prenom(prenom), m_numTel(numTel),
    m_dateNaissance(dateNaiss), m_poste(poste), m_salaire(salaire),
    m_sexe(sexe), m_niveauExp(niveauExp) {}

bool Employee::initializeDatabase() {
    // Check driver
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qDebug() << "SQLite driver missing!";
        return false;
    }



    // Configure database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QDir().mkdir("database");  // Ensure directory exists
    db.setDatabaseName(QDir::currentPath() + "/database/employee_db.sqlite");

    // Open database
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError().text();
        return false;
    }

    // Create table
    QSqlQuery query;
    QString createTable =
        "CREATE TABLE IF NOT EXISTS employees ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nom TEXT NOT NULL, "
        "prenom TEXT NOT NULL, "
        "num_tel TEXT NOT NULL, "
        "date_naissance TEXT NOT NULL, "  // SQLite uses TEXT for dates
        "poste TEXT NOT NULL, "
        "salaire REAL NOT NULL, "
        "sexe TEXT NOT NULL, "
        "niveau_experience TEXT, "
        "created_at TEXT DEFAULT CURRENT_TIMESTAMP)";  // TEXT for timestamp

    if (!query.exec(createTable)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Employee::create()
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO employees (nom, prenom, num_tel, date_naissance, poste, salaire, sexe, niveau_experience) "
        "VALUES (:nom, :prenom, :num_tel, :date_naissance, :poste, :salaire, :sexe, :niveau_experience)");

    query.bindValue(":nom", m_nom);
    query.bindValue(":prenom", m_prenom);
    query.bindValue(":num_tel", m_numTel);
    query.bindValue(":date_naissance", m_dateNaissance.toString("yyyy-MM-dd"));
    query.bindValue(":poste", m_poste);
    query.bindValue(":salaire", m_salaire);
    query.bindValue(":sexe", m_sexe);
    query.bindValue(":niveau_experience", m_niveauExp);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }

    m_id = query.lastInsertId().toInt();
    return true;
}

bool Employee::update()
{
    QSqlQuery query;
    query.prepare(
        "UPDATE employe SET "
        "nom = :nom, prenom = :prenom, num_tel = :num_tel, "
        "date_naissance = :date_naissance, poste = :poste, "
        "salaire = :salaire, sexe = :sexe, niveau_experience = :niveau_experience "
        "WHERE ID_EMP = :id");

    query.bindValue(":id", m_id);
    query.bindValue(":nom", m_nom);
    query.bindValue(":prenom", m_prenom);
    query.bindValue(":num_tel", m_numTel);
    query.bindValue(":date_naissance", m_dateNaissance.toString("yyyy-MM-dd"));
    query.bindValue(":poste", m_poste);
    query.bindValue(":salaire", m_salaire);
    query.bindValue(":sexe", m_sexe);
    query.bindValue(":niveau_experience", m_niveauExp);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    return true;
}


QMap<QString, double> Employee::calculerStatistiquesSexe()
{
    qDebug() << "--- Entering calculerStatistiquesSexe (using 'employees' table, 'sexe' column) ---";
    QMap<QString, double> stats;
    QSqlQuery queryTotal;
    double totalEmployees = 0;

    // --- Check Database Connection ---
    QSqlDatabase db = QSqlDatabase::database(); // Get default connection
    if (!db.isOpen()) {
        qDebug() << "DATABASE ERROR: Default connection is not open in calculerStatistiquesSexe!";
        return stats;
    }
    qDebug() << "Database connection appears open.";

    // --- Step 1: Get the total number of employees ---
    QString totalSql = "SELECT COUNT(*) FROM employees"; // Use correct table name
    qDebug() << "Executing query for total employees:" << totalSql;
    queryTotal.prepare(totalSql);

    if (!queryTotal.exec()) {
        qDebug() << "QUERY FAILED (Total Count):" << queryTotal.lastError().text();
        qDebug() << "Executed SQL was:" << totalSql;
        // ***** CORRECTED *****
        qDebug() << "Native Error:" << queryTotal.lastError().nativeErrorCode(); // Call on lastError()
        return stats;
    }
    qDebug() << "Total count query executed successfully.";

    // Fetch the total count
    if (queryTotal.next()) {
        totalEmployees = queryTotal.value(0).toDouble();
        qDebug() << "Total employees fetched:" << totalEmployees;
    } else {
        qDebug() << "WARNING: Total count query returned no rows! Table 'employees' might be empty or missing.";
    }

    // Handle case where there are no employees
    if (totalEmployees < 1) {
        qDebug() << "No employees found (totalEmployees < 1). Returning empty stats.";
        return stats;
    }

    // --- Step 2: Get the count for each gender ---
    QSqlQuery queryGenderCounts;
    QString genderSql = "SELECT sexe, COUNT(*) FROM employees GROUP BY sexe"; // Use correct table/column names
    qDebug() << "Executing query for gender counts:" << genderSql;
    queryGenderCounts.prepare(genderSql);

    if (!queryGenderCounts.exec()) {
        qDebug() << "QUERY FAILED (Gender Counts):" << queryGenderCounts.lastError().text();
        qDebug() << "Executed SQL was:" << genderSql;
        // ***** CORRECTED *****
        qDebug() << "Native Error:" << queryGenderCounts.lastError().nativeErrorCode(); // Call on lastError()
        return stats;
    }
    qDebug() << "Gender count query executed successfully.";

    // --- Step 3: Calculate percentages and populate the map ---
    qDebug() << "Processing gender count results...";
    bool resultsFound = false;
    while (queryGenderCounts.next()) {
        resultsFound = true;
        QString gender = queryGenderCounts.value(0).toString();
        double count = queryGenderCounts.value(1).toDouble();
        qDebug() << "  Raw data fetched -> Gender:" << gender << "| Count:" << count;

        if (gender.isEmpty() || gender.isNull()) {
            qDebug() << "  -> Gender is empty/null, replacing with 'Non spécifié'";
            gender = "Non spécifié";
        }

        double percentage = (count / totalEmployees) * 100.0;
        stats.insert(gender, percentage);
        qDebug() << "  -> Calculated & Stored -> Gender:" << gender << "| Percentage:" << percentage;
    }

    if (!resultsFound && totalEmployees > 0) {
        qDebug() << "WARNING: Gender count query returned successfully, but found no non-NULL gender groups.";
        qDebug() << "         Please check if the 'sexe' column in the 'employees' table contains actual values or only NULLs.";
    }

    qDebug() << "--- Exiting calculerStatistiquesSexe. Final stats map size:" << stats.size() << "---";
    return stats;
}



bool Employee::remove(int id) {
        QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Failed to open DB:" << db.lastError().text();
            return false;
        }
    }

    QSqlQuery query(db);
    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to delete: " << query.lastError().text();
        return false;
    }

    return true;
}



QSqlQueryModel* Employee::getAll()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, prenom, num_tel, date_naissance, poste, salaire, sexe, niveau_experience FROM employees");

    if (model->lastError().isValid()) {
        qDebug() << "Query error:" << model->lastError();
    }

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, tr("Date Naissance"));
    model->setHeaderData(5, Qt::Horizontal, tr("Poste"));
    model->setHeaderData(6, Qt::Horizontal, tr("Salaire"));
    model->setHeaderData(7, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(8, Qt::Horizontal, tr("Niveau Expérience"));

    return model;
}

// Getters implementation
int Employee::getId() const { return m_id; }
QString Employee::getNom() const { return m_nom; }
QString Employee::getPrenom() const { return m_prenom; }
QString Employee::getNumTel() const { return m_numTel; }
QDate Employee::getDateNaissance() const { return m_dateNaissance; }
QString Employee::getPoste() const { return m_poste; }
double Employee::getSalaire() const { return m_salaire; }
QString Employee::getSexe() const { return m_sexe; }
QString Employee::getNiveauExp() const { return m_niveauExp; }
QString Employee::getLastError() const { return m_lastError; }

// Setters implementation
void Employee::setId(int id) { m_id = id; }
void Employee::setNom(const QString& nom) { m_nom = nom; }
void Employee::setPrenom(const QString& prenom) { m_prenom = prenom; }
void Employee::setNumTel(const QString& numTel) { m_numTel = numTel; }
void Employee::setDateNaissance(const QDate& date) { m_dateNaissance = date; }
void Employee::setPoste(const QString& poste) { m_poste = poste; }
void Employee::setSalaire(double salaire) { m_salaire = salaire; }
void Employee::setSexe(const QString& sexe) { m_sexe = sexe; }
void Employee::setNiveauExp(const QString& niveauExp) { m_niveauExp = niveauExp; }
