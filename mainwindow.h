#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox> // Included for direct use
#include <QDebug>      // Included for direct use
#include <QDate>       // Included for direct use
#include <QString>     // Included for direct use

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Employe;
class QTableWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_2_clicked();
    void on_deleteButton_2_clicked();
    void on_editButton_2_clicked();
    void on_btrecherche_clicked();
    void on_PDF_clicked();
    void on_tabWidget_currentChanged(int index);
    void loadEmployeeDataForEdit(const QString& id);
    // void on_tab1_2_itemClicked(QTableWidgetItem *item); // Optional

private:
    Ui::MainWindow *ui;

    void refreshEmployeeTableView(QString filter = "");
    void generatePdf();
    void clearAddForm();
    // *** NO displayPosteStats() method here ***
};
#endif // MAINWINDOW_H
