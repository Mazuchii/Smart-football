#ifndef MATCH_H
#define MATCH_H

#include "gesmatch.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>


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

private:
    Ui::Match*Ui;
    void remplirComboBox();
    int getIdEquipeParNom(const QString &nomEquipe);
    int getIdStadeParNom(const QString &nomStade);
    GesMatch Etmp;
};

#endif // MATCH_H
