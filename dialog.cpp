#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    if (ui->id) {
        ui->id->setFocus();
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_login_clicked()
{
    bool ok;
    int id = ui->id->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Login Failed", "Please enter a valid numeric ID.");
        if (ui->id) ui->id->selectAll();
        if (ui->id) ui->id->setFocus();
        return;
    }
    QString password = ui->mdp->text();

    if (password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter a password.");
        if (ui->id) ui->id->selectAll();
        if (ui->id) ui->id->setFocus();
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open.\nPlease contact support or restart the application.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID_EMP, NOM, PRENOM FROM SYSTEM.EMPLOYE WHERE ID_EMP = :id AND UPPER(TRIM(MDP)) = UPPER(TRIM(:mdp))");
    query.bindValue(":id", id);
    query.bindValue(":mdp", password);

    qDebug() << "Attempting login for ID:" << id << "with MDP:" << password;
    qDebug() << "Bound query:" << query.lastQuery();

    if (query.exec()) {
        if (query.next()) {
            QString foundId = query.value("ID_EMP").toString();
            QString foundNom = query.value("NOM").toString();
            QString foundPrenom = query.value("PRENOM").toString();
            qDebug() << "Login successful for:" << foundId << "-" << foundNom << foundPrenom;

            QMessageBox::information(this, "Login Successful", "Welcome, " + foundNom + " " + foundPrenom + "!");
            accept();
        } else {
            qDebug() << "Login failed: Invalid ID or password.";
            QMessageBox::warning(this, "Login Failed", "Invalid ID or password.");
            if (ui->mdp) ui->mdp->clear();
            if (ui->id) ui->id->selectAll();
            if (ui->id) ui->id->setFocus();
        }
    } else {
        qDebug() << "Login query execution error:" << query.lastError().text();
        QMessageBox::critical(this, "Database Query Error",
                              "An error occurred while trying to log in:\n" + query.lastError().text());
    }
}
