#ifndef MATCH_H
#define MATCH_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "gesmatch.h"
#include "simulation.h"

// Forward declaration of Ui::MainWindow
namespace Ui {
class MainWindow;
}

class MainWindow; // Forward declaration of MainWindow

class Match : public QObject // Change to QObject since it's no longer a standalone window
{
    Q_OBJECT

public:
    explicit Match(Ui::MainWindow *ui, MainWindow *mainWindow, QObject *parent = nullptr);
    ~Match();

    int getIdEquipeParNom(const QString &nomEquipe);
    int getIdStadeParNom(const QString &nomStade);

private slots:
    void on_bt_ajouter_clicked();
    void on_bt_supprimer_clicked();
    void on_tab_match_clicked();
    void on_bt_modifier_clicked();
    void on_bt_MOD_clicked();
    void on_recherch_textEdited(const QString &arg1);
    void on_bt_simulation_clicked();
    void on_bt_tri_clicked();
    void on_bt_tri_2_clicked();
    void on_bt_pdf_clicked();
    void on_bt_tri_date_dec_clicked();
    void on_bt_tri_type_dec_clicked();

private:
    Ui::MainWindow *ui; // Pointer to MainWindow's UI
    MainWindow *mainWindow; // Pointer to MainWindow
    GesMatch Etmp;
    Simulation *simulation;
    QWidget *widget_modif;

    void remplirComboBox();
};

#endif // MATCH_H
