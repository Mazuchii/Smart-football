#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipe.h"
#include <QSqlQuery>
#include "arduino.h"

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
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_rechercher_clicked();  // Recherche
    void on_pushButton_trier_clicked();       // Tri
    void on_pushButton_export_pdf_clicked();  // Export PDF
    void on_boutonRechercherNom_clicked();   // Recherche par nom
    void afficherHistoriqueMatchs(int idEquipe); // Affichage de l'historique des matchs
    void afficherEtatEquipes(); // Affichage de l'état des équipes (pourcentage de victoires/défaites)

     void handleArduinoReadyRead(); // Slot to process data from Arduino

private:
    Ui::MainWindow *ui;
    void afficherEquipes();
    void afficherEquipeParId(int id);
    void mettreAJourStatistiques();  // ✅ Ajouté pour la mise à jour des statistiques
    //void afficherDerniersMatchs();
    //void afficherMatchs();
    Arduino *A;

};

#endif // MAINWINDOW_H
