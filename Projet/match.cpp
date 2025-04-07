#include "match.h"
#include "gesmatch.h"
#include "ui_match.h"
#include <qsqlerror.h>
#include <QTableWidgetItem>

Match::Match(QWidget *parent)
    : QMainWindow(parent)
    , Ui(new Ui::Match)
{
    Ui->setupUi(this);
    Ui->tab_match->setAlternatingRowColors(true);
    Ui->tab_match->setModel(GesMatch::afficher());
    remplirComboBox();  // 🔸 Fill combo boxes when window opens
}

Match::~Match()
{
    delete Ui;
}

void Match::remplirComboBox()
{
    QSqlQuery query;

    // Fill équipe1 & équipe2 combo boxes
    query.exec("SELECT NOM_EQ FROM EQUIPE");
    while (query.next()) {
        QString nomEquipe = query.value(0).toString();
        Ui->equip1_ajout->addItem(nomEquipe);
        Ui->equip2_ajout->addItem(nomEquipe);
    }

    // Fill stade combo box
    query.exec("SELECT NOM FROM STADE");
    while (query.next()) {
        QString nomStade = query.value(0).toString();
        Ui->stad_ajout->addItem(nomStade);
    }
}

int Match::getIdEquipeParNom(const QString &nomEquipe)
{
    QSqlQuery query;
    query.prepare("SELECT ID_EQ FROM EQUIPE WHERE NOM_EQ = :nom");
    query.bindValue(":nom", nomEquipe);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Erreur récupération ID_EQ :" << query.lastError().text();
        return -1; // Erreur
    }
}

int Match::getIdStadeParNom(const QString &nomStade)
{
    QSqlQuery query;
    query.prepare("SELECT ID_STADE FROM STADE WHERE NOM = :nom");
    query.bindValue(":nom", nomStade);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Erreur récupération ID_STADE :" << query.lastError().text();
        return -1; // Erreur
    }
}
void Match::on_bt_ajouter_clicked()
{
    QDate date = Ui->dateEdit->date();
    QString equipe1Nom = Ui->equip1_ajout->currentText();
    QString equipe2Nom = Ui->equip2_ajout->currentText();
    QString stadeNom = Ui->stad_ajout->currentText();
    QString typeMatch = Ui->type_ajout->currentText();

    // Check if input is valid
    if (equipe1Nom.isEmpty() || equipe2Nom.isEmpty() || stadeNom.isEmpty() || typeMatch.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
        return;
    }

    if (equipe1Nom == equipe2Nom) {
        QMessageBox::warning(this, "Erreur", "Les équipes doivent être différentes");
        return;
    }

    QSqlQuery query;
    int idEquipe1 = -1, idEquipe2 = -1, idStade = -1;

    // Get id_equipe1
    query.prepare("SELECT ID_EQ FROM EQUIPE WHERE NOM_EQ = :nom");
    query.bindValue(":nom", equipe1Nom);
    if (query.exec() && query.next()) {
        idEquipe1 = query.value(0).toInt();
    }

    // Get id_equipe2
    query.prepare("SELECT ID_EQ FROM EQUIPE WHERE NOM_EQ = :nom");
    query.bindValue(":nom", equipe2Nom);
    if (query.exec() && query.next()) {
        idEquipe2 = query.value(0).toInt();
    }

    // Get id_stade
    query.prepare("SELECT ID_STADE FROM STADE WHERE NOM = :nom");
    query.bindValue(":nom", stadeNom);
    if (query.exec() && query.next()) {
        idStade = query.value(0).toInt();
    }

     idEquipe1 = getIdEquipeParNom(equipe1Nom);
     idEquipe2 = getIdEquipeParNom(equipe2Nom);
     idStade = getIdStadeParNom(stadeNom);

    if (idEquipe1 == -1 || idEquipe2 == -1 || idStade == -1) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les identifiants des entités");
        return;
    }

    // Create match object (score initial = 0)
    GesMatch Match(-1, date, typeMatch, idEquipe1, idEquipe2, idStade, 0, 0);

    if (Match.ajouter()) {
        QMessageBox::information(this, "Succès", "Match ajouté avec succès");
        Ui->tab_match->setModel(GesMatch::afficher());
        // Reset form
        Ui->dateEdit->setDate(QDate::currentDate());
        Ui->equip1_ajout->setCurrentIndex(0);
        Ui->equip2_ajout->setCurrentIndex(0);
        Ui->stad_ajout->setCurrentIndex(0);
        Ui->type_ajout->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du match");
    }
}




void Match::on_bt_supprimer_clicked()
{
    // Get selected row
    QModelIndexList selectedIndexes = Ui->tab_match->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un match à supprimer.");
        return;
    }

    // Assume the ID is in column 0
    int selectedRow = selectedIndexes.first().row();
    QModelIndex index = Ui->tab_match->model()->index(selectedRow, 0); // 0 = column of ID_MATCH
    int id_match = Ui->tab_match->model()->data(index).toInt();

    // Call delete
    bool test = Etmp.supprimer(id_match);
    if (test) {
        QMessageBox::information(this, "OK", "Suppression effectuée.");
        Ui->tab_match->setModel(Etmp.afficher()); // refresh
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression non effectuée.");
    }
}




void Match::on_tab_match_clicked()
{
    Ui->tab_match->setModel(GesMatch::afficher());
}

