#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

/*bool Dialog::validateLogin()
{

    QSqlQuery query;
query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMP = :username AND MDP = :password");
    // Bind parameters
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "SQL Error", query.lastError().text());
        return false;
    }

    if (query.next()) {
        return true; // Found a match
    } else {
        return false; // No match
    }
}*/

void Dialog::on_pushButton_login_clicked()
{
    QString username = ui->id->text();
    QString password = ui->mdp->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMP = :username AND MDP = :password");
    // Bind parameters
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    qDebug() << "ID" << username <<"pwd" << password;
    if (query.exec() && query.next())  {
        QMessageBox::critical(this, "login", "connection ok");


    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password.");
    }
}
