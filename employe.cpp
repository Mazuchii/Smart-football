#include "employe.h"
#include <QtSql/QSqlError> // Include for error reporting
#include <QDebug>          // For printing debug messages

// --- Constructors ---

Employe::Employe()
{
    // Initialize with default/invalid values
    this->id_emp = -1; // Use -1 or 0 to indicate an invalid/new ID
    this->nom = "";
    this->prenom = "";
    this->adresse = "";
    this->num_tel_emp = "";
    this->date_naiss_emp = QDate(); // Invalid date
    this->poste = "";
    this->salaire = 0.0;
    this->statut = "";
    this->sexe = "";
    this->mdp = "";
}

Employe::Employe(int id, QString n, QString p, QString adr, QString tel, QDate dateN,
                 QString post, double sal, QString stat, QString sex, QString pass)
{
    this->id_emp = id;
    this->nom = n;
    this->prenom = p;
    this->adresse = adr;
    this->num_tel_emp = tel;
    this->date_naiss_emp = dateN;
    this->poste = post;
    this->salaire = sal;
    this->statut = stat;
    this->sexe = sex;
    this->mdp = pass;
}

// --- Getters ---

int Employe::getIdEmp() const { return id_emp; }
QString Employe::getNom() const { return nom; }
QString Employe::getPrenom() const { return prenom; }
QString Employe::getAdresse() const { return adresse; }
QString Employe::getNumTelEmp() const { return num_tel_emp; }
QDate Employe::getDateNaissEmp() const { return date_naiss_emp; }
QString Employe::getPoste() const { return poste; }
double Employe::getSalaire() const { return salaire; }
QString Employe::getStatut() const { return statut; }
QString Employe::getSexe() const { return sexe; }
QString Employe::getMdp() const { return mdp; } // Use with caution

// --- Setters ---

void Employe::setIdEmp(int id) { this->id_emp = id; }
void Employe::setNom(const QString &n) { this->nom = n; }
void Employe::setPrenom(const QString &p) { this->prenom = p; }
void Employe::setAdresse(const QString &adr) { this->adresse = adr; }
void Employe::setNumTelEmp(const QString &tel) { this->num_tel_emp = tel; }
void Employe::setDateNaissEmp(const QDate &dateN) { this->date_naiss_emp = dateN; }
void Employe::setPoste(const QString &post) { this->poste = post; }
void Employe::setSalaire(double sal) { this->salaire = sal; }
void Employe::setStatut(const QString &stat) { this->statut = stat; }
void Employe::setSexe(const QString &sex) { this->sexe = sex; }
void Employe::setMdp(const QString &pass) { this->mdp = pass; } // Use with caution

// --- Database Interaction Methods ---

bool Employe::ajouter()
{
    QSqlQuery query;

    // Prepare the INSERT statement - column names MUST match your DB table
    // Assuming ID_EMP is auto-generated (e.g., by a sequence/trigger in Oracle)
    // If you need to provide ID_EMP, add it to the query and bind it.
    query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, ADRESSE, NUM_TEL_EMP, DATE_NAISS_EMP, POSTE, SALAIRE, STATUT, SEXE, MDP) "
                  "VALUES (:nom, :prenom, :adresse, :num_tel, :date_n, :poste, :salaire, :statut, :sexe, :mdp)");

    // Bind values from the object's members
    query.bindValue(":nom", this->nom);
    query.bindValue(":prenom", this->prenom);
    query.bindValue(":adresse", this->adresse); // Bind even if not fully used in UI yet
    query.bindValue(":num_tel", this->num_tel_emp);
    query.bindValue(":date_n", this->date_naiss_emp);
    query.bindValue(":poste", this->poste);
    query.bindValue(":salaire", this->salaire);
    query.bindValue(":statut", this->statut); // Bind even if not fully used in UI yet
    query.bindValue(":sexe", this->sexe);     // Make sure this matches DB expectation (e.g., 'H', 'F')
    query.bindValue(":mdp", this->mdp);       // Bind password

    if (!query.exec()) { // <--- If this fails...
        qDebug() << "Error adding employee:" << query.lastError().text(); // This should print the DB error
        return false; // <--- ...it returns false here
    }
    return true;
}

// Static method - doesn't operate on a specific instance
QSqlQueryModel* Employe::afficher(QString filter, QString sortBy)
{
    QSqlQueryModel* model = new QSqlQueryModel(); // Caller must delete this later!
    QSqlQuery query; // Use temporary query object

    // Base query - Select columns you want to display
    QString sql = "SELECT ID_EMP, NOM, PRENOM, DATE_NAISS_EMP, POSTE, SEXE, NUM_TEL_EMP, SALAIRE, ADRESSE, STATUT FROM EMPLOYE"; // Adjust columns as needed

    // Add filtering if a filter string is provided
    if (!filter.isEmpty()) {
        // Case-insensitive search on common fields
        sql += " WHERE UPPER(NOM) LIKE UPPER(:filter) OR UPPER(PRENOM) LIKE UPPER(:filter) OR TO_CHAR(ID_EMP) LIKE :filter OR UPPER(POSTE) LIKE UPPER(:filter)";
        query.prepare(sql);
        query.bindValue(":filter", "%" + filter + "%"); // Add wildcards for LIKE search
    } else {
        query.prepare(sql);
    }

    // Add sorting
    if (!sortBy.isEmpty()) {
        // Basic safety check for common column names - avoid SQL injection risk if sortBy comes from user input directly
        if (sortBy == "ID_EMP" || sortBy == "NOM" || sortBy == "PRENOM" || sortBy == "POSTE" || sortBy == "SALAIRE") {
            sql += " ORDER BY " + sortBy;
            query.prepare(sql); // Re-prepare with ORDER BY
            // Re-bind if filter was present
            if (!filter.isEmpty()) {
                query.bindValue(":filter", "%" + filter + "%");
            }
        } else {
            qDebug() << "Warning: Invalid sort column provided:" << sortBy;
            // Proceed without sorting or default sort
            sql += " ORDER BY ID_EMP"; // Default sort
            query.prepare(sql);
            if (!filter.isEmpty()) {
                query.bindValue(":filter", "%" + filter + "%");
            }
        }
    }


    if (!query.exec()) {
        qDebug() << "Error executing query for afficher:" << query.lastError().text();
        delete model; // Clean up if query fails
        return nullptr;
    }

    model->setQuery(query); // Pass the executed query to the model

    // Set user-friendly header names for the table view
    // Index must match the order in the SELECT statement
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Statut"));
    // Add more headers if needed

    return model;
}


// Static method
Employe Employe::chercher(int id)
{
    QSqlQuery query;
    Employe emp; // Create a default/empty employee object

    query.prepare("SELECT ID_EMP, NOM, PRENOM, ADRESSE, NUM_TEL_EMP, DATE_NAISS_EMP, POSTE, SALAIRE, STATUT, SEXE, MDP "
                  "FROM EMPLOYE WHERE ID_EMP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error searching employee by ID:" << query.lastError().text();
        return emp; // Return the default object (ID = -1)
    }

    // If a record is found, populate the employee object
    if (query.next()) {
        emp.setIdEmp(query.value("ID_EMP").toInt());
        emp.setNom(query.value("NOM").toString());
        emp.setPrenom(query.value("PRENOM").toString());
        emp.setAdresse(query.value("ADRESSE").toString());
        emp.setNumTelEmp(query.value("NUM_TEL_EMP").toString());
        emp.setDateNaissEmp(query.value("DATE_NAISS_EMP").toDate());
        emp.setPoste(query.value("POSTE").toString());
        emp.setSalaire(query.value("SALAIRE").toDouble());
        emp.setStatut(query.value("STATUT").toString());
        emp.setSexe(query.value("SEXE").toString());
        emp.setMdp(query.value("MDP").toString()); // Retrieve password
    }
    // If query.next() is false, the default emp object (ID -1) is returned

    return emp;
}


bool Employe::modifier(int id_to_update)
{
    QSqlQuery query;

    // Prepare UPDATE statement
    query.prepare("UPDATE EMPLOYE SET "
                  "NOM = :nom, PRENOM = :prenom, ADRESSE = :adresse, NUM_TEL_EMP = :num_tel, "
                  "DATE_NAISS_EMP = :date_n, POSTE = :poste, SALAIRE = :salaire, STATUT = :statut, "
                  "SEXE = :sexe, MDP = :mdp "
                  "WHERE ID_EMP = :id_update"); // Condition to update specific row

    // Bind values from the *current object's* members
    query.bindValue(":nom", this->nom);
    query.bindValue(":prenom", this->prenom);
    query.bindValue(":adresse", this->adresse);
    query.bindValue(":num_tel", this->num_tel_emp);
    query.bindValue(":date_n", this->date_naiss_emp);
    query.bindValue(":poste", this->poste);
    query.bindValue(":salaire", this->salaire);
    query.bindValue(":statut", this->statut);
    query.bindValue(":sexe", this->sexe);
    query.bindValue(":mdp", this->mdp);
    query.bindValue(":id_update", id_to_update); // Bind the ID for the WHERE clause

    if (!query.exec()) {
        qDebug() << "Error updating employee:" << query.lastError().text();
        return false;
    }

    // Check if any row was actually affected (optional but good)
    // return query.numRowsAffected() > 0;
    return true; // Return true if execution succeeded
}

// Static method
bool Employe::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting employee:" << query.lastError().text();
        return false;
    }

    // Check if a row was actually deleted
    return query.numRowsAffected() > 0;
}
