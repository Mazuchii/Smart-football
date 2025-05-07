#ifndef MATCH_H
#define MATCH_H

#include "gesmatch.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include "simulation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Match; }
QT_END_NAMESPACE

class Match : public QMainWindow
{
    Q_OBJECT

public:
    Match(QWidget *parent = nullptr);
    ~Match();

private slots:
    void on_bt_ajouter_clicked();

    void on_bt_supprimer_clicked();


    void on_tab_match_clicked();

    void on_bt_modifier_clicked();

    void on_recherch_textEdited(const QString &arg1);

    void on_bt_simulation_clicked();


    void on_bt_tri_clicked();

    void on_bt_tri_2_clicked();

    void on_bt_pdf_clicked();

    void on_bt_MOD_clicked();

    void on_bt_tri_date_dec_clicked();

    void on_bt_tri_type_dec_clicked();

private:
    Ui::Match*Ui;
    void remplirComboBox();
    int getIdEquipeParNom(const QString &nomEquipe);
    int getIdStadeParNom(const QString &nomStade);
    int selectedIdMatch;

    QWidget* widget_modif;
    Simulation *simulation;
    GesMatch Etmp;

};

#endif // MATCH_H
