#include "match.h"
#include "gesmatch.h"
#include "simulation.h"
#include "ui_match.h"
#include <qsqlerror.h>
#include <QTableWidgetItem>
#include <QGraphicsView>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>

Match::Match(QWidget *parent)
    : QMainWindow(parent)
    , Ui(new Ui::Match)
{
    Ui->setupUi(this);
    Ui->tab_match->setAlternatingRowColors(true);
    Ui->tab_match->setModel(GesMatch::afficher());
    Ui->tab_match->setColumnHidden(0, true);
    Ui->tab_match->setSortingEnabled(true);
    Ui->tab_match->sortByColumn(5, Qt::AscendingOrder);
    remplirComboBox();
    Ui->lab_pre->setWordWrap(true);


    widget_modif = Ui->tabWidget->widget(3);
    Ui->tabWidget->removeTab(3);

    Ui->dateEdit->setDate(QDate::currentDate());
    Ui->equip1_ajout->setCurrentIndex(-1);
    Ui->equip2_ajout->setCurrentIndex(-1);
    Ui->stad_ajout->setCurrentIndex(-1);
    Ui->type_ajout->setCurrentIndex(-1);
}

Match::~Match()
{
    delete Ui;
}

void Match::remplirComboBox()
{
    QSqlQuery query;


    query.exec("SELECT NOM_EQ FROM EQUIPE");
    while (query.next()) {
        QString nomEquipe = query.value(0).toString();
        Ui->equip1_ajout->addItem(nomEquipe);
        Ui->equip2_ajout->addItem(nomEquipe);
        Ui->equip1_MOD->addItem(nomEquipe);
        Ui->equip2_MOD->addItem(nomEquipe);
    }


    query.exec("SELECT NOM FROM STADE");
    while (query.next()) {
        QString nomStade = query.value(0).toString();
        Ui->stad_ajout->addItem(nomStade);
        Ui->stad_MOD->addItem(nomStade);
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
        return -1;
    }
}
void Match::on_bt_ajouter_clicked()
{
    QDate date = Ui->dateEdit->date();
    QString equipe1Nom = Ui->equip1_ajout->currentText();
    QString equipe2Nom = Ui->equip2_ajout->currentText();
    QString stadeNom = Ui->stad_ajout->currentText();
    QString typeMatch = Ui->type_ajout->currentText();


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


    query.prepare("SELECT ID_EQ FROM EQUIPE WHERE NOM_EQ = :nom");
    query.bindValue(":nom", equipe1Nom);



    query.prepare("SELECT ID_EQ FROM EQUIPE WHERE NOM_EQ = :nom");
    query.bindValue(":nom", equipe2Nom);



    query.prepare("SELECT ID_STADE FROM STADE WHERE NOM = :nom");
    query.bindValue(":nom", stadeNom);


     idEquipe1 = getIdEquipeParNom(equipe1Nom);
     idEquipe2 = getIdEquipeParNom(equipe2Nom);
     idStade = getIdStadeParNom(stadeNom);

    if (idEquipe1 == -1 || idEquipe2 == -1 || idStade == -1) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les identifiants des entités");
        return;
    }


    GesMatch Match(-1, date, typeMatch, idEquipe1, idEquipe2, idStade, 0, 0);

    if (Match.ajouter()) {
        QMessageBox::information(this, "Succès", "Match ajouté avec succès");
        Ui->tab_match->setModel(GesMatch::afficher());
        // Reset form
        Ui->dateEdit->setDate(QDate::currentDate());
        Ui->equip1_ajout->setCurrentIndex(-1);
        Ui->equip2_ajout->setCurrentIndex(-1);
        Ui->stad_ajout->setCurrentIndex(-1);
        Ui->type_ajout->setCurrentIndex(-1);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du match");
    }
}




void Match::on_bt_supprimer_clicked()
{

    QModelIndexList selectedIndexes = Ui->tab_match->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un match à supprimer.");
        return;
    }


    int selectedRow = selectedIndexes.first().row();
    QModelIndex index = Ui->tab_match->model()->index(selectedRow, 0); // 0 = column of ID_MATCH
    int id_match = Ui->tab_match->model()->data(index).toInt();


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



void Match::on_bt_modifier_clicked()
{
    QModelIndex index = Ui->tab_match->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un match.");
        return;
    }


    int row = index.row();
    QString match_id_str = Ui->tab_match->model()->index(row, 0).data().toString();

    QSqlQuery query;
    query.prepare(R"(
        SELECT
            E1.NOM_EQ AS EQUIPE1,
            E2.NOM_EQ AS EQUIPE2,
            M.TYPE_M,
            S.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY')
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE S ON M.ID_STADE = S.ID_STADE
        WHERE M.ID_MATCH = :id
    )");
    query.bindValue(":id", match_id_str);

    if (query.exec() && query.next()) {
        QString eq1 = query.value(0).toString();
        QString eq2 = query.value(1).toString();
        QString type = query.value(2).toString();
        QString stade = query.value(3).toString();
        QString date = query.value(4).toString();

        QDate date_m = QDate::fromString(date, "dd/MM/yyyy");

        Ui->match_id->setText(match_id_str);


        // Sélectionner les bons éléments dans les ComboBox par NOM
        int index1 = Ui->equip1_MOD->findText(eq1);
        if (index1 != -1)
            Ui->equip1_MOD->setCurrentIndex(index1);

        int index2 = Ui->equip2_MOD->findText(eq2);
        if (index2 != -1)
            Ui->equip2_MOD->setCurrentIndex(index2);

        int stadeIndex = Ui->stad_MOD->findText(stade);
        if (stadeIndex != -1)
            Ui->stad_MOD->setCurrentIndex(stadeIndex);

        int typeIndex = Ui->type_MOD->findText(type);
        if (typeIndex != -1)
            Ui->type_MOD->setCurrentIndex(typeIndex);

        Ui->date_MOD->setDate(date_m);

        Ui->tabWidget->addTab(widget_modif, "Modifier Match");
        Ui->tabWidget->setCurrentWidget(widget_modif);
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les détails du match.\n" + query.lastError().text());
    }
}

void Match::on_bt_MOD_clicked()
{
    QString id_match = Ui->match_id->text();
    QString equipe1Nom = Ui->equip1_MOD->currentText();
    QString equipe2Nom = Ui->equip2_MOD->currentText();
    QString stadeNom = Ui->stad_MOD->currentText();
    QString type = Ui->type_MOD->currentText();
    QDate date = Ui->date_MOD->date();

    // Convertir les noms en ID via les fonctions auxiliaires
    int id_eq1 = getIdEquipeParNom(equipe1Nom);
    int id_eq2 = getIdEquipeParNom(equipe2Nom);
    int id_stade = getIdStadeParNom(stadeNom);

    // Créer un objet GesMatch avec les nouvelles valeurs

    GesMatch m;
    int matchId = id_match.toInt();
    m.setId(matchId);
    m.setDate(date);
    m.setType(type);
    m.setEquipe1(id_eq1);
    m.setEquipe2(id_eq2);
    m.setStade(id_stade);

    // Appeler la méthode modifier
    if (m.modifier()) {
        QMessageBox::information(this, "Succès", "Match modifié avec succès.");
        Ui->tabWidget->removeTab(3);
        Ui->tab_match->setModel(GesMatch::afficher());
        Ui->tabWidget->setCurrentIndex(1); // retour à l'onglet principal si souhaité
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du match.");
    }
}




void Match::on_recherch_textEdited(const QString &arg1)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    QString search = "%" + arg1 + "%";

    query.prepare(R"(
        SELECT
            M.ID_MATCH,
            E1.NOM_EQ AS EQUIPE_1,
            E2.NOM_EQ AS EQUIPE_2,
            M.TYPE_M AS TYPE_M,
            E3.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE E3 ON M.ID_STADE = E3.ID_STADE
        WHERE
            LOWER(E1.NOM_EQ) LIKE LOWER(:search) OR
            LOWER(E2.NOM_EQ) LIKE LOWER(:search)

    )");

    query.bindValue(":search", search);

    if (!query.exec()) {
        qDebug() << "Search query error:" << query.lastError().text();
        delete model;
        return;
    }
    model->setQuery(std::move(query));
    Ui->tab_match->setModel(model);

}


void Match::on_bt_simulation_clicked()
{

    QModelIndex index = Ui->tab_match->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un match.");
        return;
    }

    int row = index.row();
    QString match_id_str = Ui->tab_match->model()->index(row, 0).data().toString();

    QSqlQuery query;
    query.prepare(R"(
        SELECT
            E1.NOM_EQ AS EQUIPE1,
            E2.NOM_EQ AS EQUIPE2,
            M.TYPE_M,
            M.SCORE_EQ1,
            M.SCORE_EQ2,
            S.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY')
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE S ON M.ID_STADE = S.ID_STADE
        WHERE M.ID_MATCH = :id
    )");
    GesMatch g;

    query.bindValue(":id", match_id_str);
    if (query.exec() && query.next()) {
        QString eq1 = query.value(0).toString();
        QString eq2 = query.value(1).toString();
        QString type = query.value(2).toString();
        int score1 = query.value(3).toInt();
        int score2 = query.value(4).toInt();
        QString stade = query.value(5).toString();
        QString date = query.value(6).toString();

        Ui->lab_equip->setText(eq1 + " - " + eq2);
        Ui->lab_score->setText(QString::number(score1) + " - " + QString::number(score2));
        Ui->lab_type->setText(type);
        Ui->lab_stad->setText(stade);
        Ui->lab_date->setText(date);
        Ui->lab_pre->setText(g.statistics(eq1, eq2));


        Ui->tabWidget->setCurrentIndex(2);


        QGraphicsScene *scene = new QGraphicsScene(this);
        Ui->match_sim->setScene(scene);


        simulation = new Simulation(this);
        simulation->setMatchId(match_id_str.toInt());
        simulation->start(scene);


    } else {
        qDebug() << "Erreur simulation:" << query.lastError().text();
    }
}





void Match::on_bt_tri_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare(R"(
        SELECT
            M.ID_MATCH,
            E1.NOM_EQ AS EQUIPE_1,
            E2.NOM_EQ AS EQUIPE_2,
            M.TYPE_M AS TYPE_M,
            E3.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE E3 ON M.ID_STADE = E3.ID_STADE
        ORDER BY M.DATE_M ASC
    )");

    if (!query.exec()) {
        qDebug() << "Tri par date échoué:" << query.lastError().text();
        delete model;
        return;
    }

    model->setQuery(std::move(query));
    Ui->tab_match->setModel(model);
}



void Match::on_bt_tri_2_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare(R"(
        SELECT
            M.ID_MATCH,
            E1.NOM_EQ AS EQUIPE_1,
            E2.NOM_EQ AS EQUIPE_2,
            M.TYPE_M AS TYPE_M,
            E3.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE E3 ON M.ID_STADE = E3.ID_STADE
        ORDER BY M.TYPE_M ASC
    )");

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri par type:" << query.lastError().text();
        delete model;
        return;
    }

    model->setQuery(std::move(query));
    Ui->tab_match->setModel(model);
}



void Match::on_bt_pdf_clicked() {
    QModelIndex index = Ui->tab_match->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "PDF", "Veuillez sélectionner un match.");
        return;
    }

    int row = index.row();
    int id_match = Ui->tab_match->model()->index(row, 0).data().toInt();

    QSqlQuery query;
    query.prepare(R"(
        SELECT
            E1.NOM_EQ AS EQUIPE1,
            E2.NOM_EQ AS EQUIPE2,
            M.TYPE_M,
            M.SCORE_EQ1,
            M.SCORE_EQ2,
            S.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE S ON M.ID_STADE = S.ID_STADE
        WHERE M.ID_MATCH = :id
    )");
    query.bindValue(":id", id_match);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les informations du match.");
        return;
    }

    QString eq1 = query.value(0).toString();
    QString eq2 = query.value(1).toString();
    QString type = query.value(2).toString();
    int score1 = query.value(3).toInt();
    int score2 = query.value(4).toInt();
    QString stade = query.value(5).toString();
    QString date = query.value(6).toString();

    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty())
        return;

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&writer);

    // Set fonts
    QFont titleFont("Helvetica", 18, QFont::Bold);
    QFont labelFont("Helvetica", 14);
    QFont boldFont("Helvetica", 14, QFont::Bold);

    int left = 500;
    int y = 500;
    int spacing = 500;

    // Title
    painter.setFont(titleFont);
    painter.drawText(QRect(0, y, writer.width(), 1000), Qt::AlignCenter, "📄 FICHE DU MATCH");
    y += spacing;

    painter.setFont(labelFont);
    painter.drawLine(left, y, writer.width() - left, y); // Horizontal line
    y += spacing;

    // Date and Type
    painter.setFont(boldFont);
    painter.drawText(left, y, "📅 Date:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, date);
    y += spacing;

    painter.setFont(boldFont);
    painter.drawText(left, y, "🏆 Type:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, type);
    y += spacing;

    painter.drawLine(left, y, writer.width() - left, y);
    y += spacing;

    // Teams and Scores
    painter.setFont(boldFont);
    painter.drawText(left, y, "🔵 Équipe 1:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, eq1);
    y += spacing;

    painter.setFont(boldFont);
    painter.drawText(left, y, "   🔢 Score:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, QString::number(score1));
    y += spacing;

    painter.setFont(boldFont);
    painter.drawText(left, y, "🔴 Équipe 2:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, eq2);
    y += spacing;

    painter.setFont(boldFont);
    painter.drawText(left, y, "   🔢 Score:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, QString::number(score2));
    y += spacing;

    painter.drawLine(left, y, writer.width() - left, y);
    y += spacing;

    // Stadium
    painter.setFont(boldFont);
    painter.drawText(left, y, "🏟️ Stade:");
    painter.setFont(labelFont);
    painter.drawText(left + 1500, y, stade);

    painter.end();

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}




void Match::on_bt_tri_date_dec_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare(R"(
        SELECT
            M.ID_MATCH,
            E1.NOM_EQ AS EQUIPE_1,
            E2.NOM_EQ AS EQUIPE_2,
            M.TYPE_M AS TYPE_M,
            E3.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE E3 ON M.ID_STADE = E3.ID_STADE
        ORDER BY M.DATE_M DESC
    )");

    if (!query.exec()) {
        qDebug() << "Erreur tri date décroissante :" << query.lastError().text();
        delete model;
        return;
    }

    model->setQuery(std::move(query));
    Ui->tab_match->setModel(model);
}


void Match::on_bt_tri_type_dec_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare(R"(
        SELECT
            M.ID_MATCH,
            E1.NOM_EQ AS EQUIPE_1,
            E2.NOM_EQ AS EQUIPE_2,
            M.TYPE_M AS TYPE_M,
            E3.NOM AS STADE,
            TO_CHAR(M.DATE_M, 'DD/MM/YYYY') AS DATE_M
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        JOIN STADE E3 ON M.ID_STADE = E3.ID_STADE
        ORDER BY M.TYPE_M DESC
    )");

    if (!query.exec()) {
        qDebug() << "Erreur tri type décroissant :" << query.lastError().text();
        delete model;
        return;
    }

    model->setQuery(std::move(query));
    Ui->tab_match->setModel(model);
}

