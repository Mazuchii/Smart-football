#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
// Forward declare if not fully needed, or include
class QSqlQuery; // If used only in .cpp, forward declaration is fine
class QMessageBox; // If used only in .cpp, forward declaration is fine

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
    void on_pushButton_login_clicked(); // Assumes button is named pushButton_login

private:
    Ui::Dialog *ui;
    // bool validateLogin(); // Keep if you plan to re-implement this helper
};

#endif // DIALOG_H
