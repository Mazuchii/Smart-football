#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "joueur.h"
#include "employe.h"
#include "equipe.h"
#include "match.h"
#include "qtablewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateTableView(QSqlQueryModel *model);

private slots:
    void on_voirStatsButton_clicked();
    void analyzePerformance();
    void on_trierParIDButton_clicked();
    void on_trierParNomButton_clicked();
    void on_trierParPrenomButton_clicked();
    void on_trierParNumeroButton_clicked();
    void on_ajouterButton_clicked();
    void on_supprimerButton_clicked();
    void on_modifierButton_clicked();
    void on_rechercherButton_clicked();
    void on_rechercherParNomButton_clicked();
    void on_sendButton_clicked();
    void processChatInput(const QString& input);
    void on_joueursButton_clicked();
    void on_equipeButton_clicked();
    void on_addButton_2_clicked();
    void on_deleteButton_2_clicked();
    void on_editButton_2_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_btrecherche_clicked();
    void on_PDF_clicked();
    void on_tab1_2_itemClicked(QTableWidgetItem *item);
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_rechercher_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButton_export_pdf_clicked();
    void on_boutonRechercherNom_clicked();
    void on_pushButton_pourcentageTous_clicked();

private:
    Ui::MainWindow *ui;
    Joueur joueur;
    Employe employe;
    Equipe equipe;
    Match *match;

    void refreshEmployeeTableView(QString filter = "");
    void loadEmployeeDataForEdit(const QString& idStr);
    void clearAddForm();
    void generatePdf();
    void afficherEquipes();
    void mettreAJourStatistiques();
    void afficherEquipeParId(int id);
    void afficherHistoriqueMatchs(int idEquipe);
    void afficherPourcentageToutesEquipes();
    void displayPosteStats();
};

#endif // MAINWINDOW_H
