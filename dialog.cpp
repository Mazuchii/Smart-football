#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>       // For debugging
#include <QSqlDatabase> // For checking connection

    Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // Optional: Set focus to the ID field
    if (ui->id) { // Assuming your ID input field is named 'id'
        ui->id->setFocus();
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_login_clicked()
{
    // Ensure your UI elements are named 'id' and 'mdp' in dialog.ui
    QString username = ui->id->text(); // Or ui->lineEdit_id->text() if that's the name
    QString password = ui->mdp->text(); // Or ui->lineEdit_mdp->text()

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter both ID and password.");
        return;
    }

    // Check if the default database connection is open
    QSqlDatabase db = QSqlDatabase::database(); // Gets the default connection
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open.\nPlease contact support or restart the application.");
        // Optionally, you could try to open it here if Connexion object isn't managed by main
        // but it's better if main.cpp handles the primary connection setup.
        return;
    }

    QSqlQuery query; // Will use the default connection
    query.prepare("SELECT ID_EMP, NOM, PRENOM FROM EMPLOYE WHERE ID_EMP = :username AND MDP = :password");
    query.bindValue(":username", username); // ID_EMP is likely a NUMBER, username might need to be toInt()
    query.bindValue(":password", password);

    qDebug() << "Attempting login for ID:" << username;

    if (query.exec()) {
        if (query.next()) {
            // Login successful
            QString foundId = query.value("ID_EMP").toString();
            QString foundNom = query.value("NOM").toString();
            QString foundPrenom = query.value("PRENOM").toString();
            qDebug() << "Login successful for:" << foundId << "-" << foundNom << foundPrenom;

            QMessageBox::information(this, "Login Successful", "Welcome, " + foundNom + " " + foundPrenom + "!");
            accept(); // This closes the dialog and returns QDialog::Accepted to exec()
        } else {
            // Login failed - no matching record
            qDebug() << "Login failed: Invalid ID or password.";
            QMessageBox::warning(this, "Login Failed", "Invalid ID or password.");
            if (ui->mdp) ui->mdp->clear(); // Clear password field on failure
            if (ui->id) ui->id->selectAll();
            if (ui->id) ui->id->setFocus();
        }
    } else {
        // Query execution failed
        qDebug() << "Login query execution error:" << query.lastError().text();
        QMessageBox::critical(this, "Database Query Error",
                              "An error occurred while trying to log in:\n" + query.lastError().text());
    }
}
