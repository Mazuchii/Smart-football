#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Dialog *ui;
    bool validateLogin();
};

#endif // DIALOG_H
