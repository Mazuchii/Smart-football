#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "employe.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onEditButtonClicked();
    void onDeleteButtonClicked();
    void onTableClicked(const QModelIndex &index);
    void refreshTable();


    void afficherStatistiquesSexeChart();
    void on_statistiquesButton_clicked(); // Keep or add this declaration
    void on_btrecherche_clicked();

    void on_PDF_clicked();

private:
    Ui::MainWindow *ui;
    Employee *m_currentEmployee;
    QSqlQueryModel *m_model;

    void clearForm();
    void loadEmployeeData(int employeeId);
    void setupTable();
};
#endif // MAINWINDOW_H
