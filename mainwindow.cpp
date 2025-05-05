#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipe.h"
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFile>
#include <QStandardPaths>
#include <QPixmap>
#include <QDate>
#include <QDebug>
#include <QSqlRecord>
#include "arduino.h"  // or the correct path to your Arduino class header


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //arduino
    A = new Arduino();
    QObject::connect(A->getserial(), &QSerialPort::readyRead, this, [this]() {
        A->readFromArduino();
    });


    int ret = A->connect_arduino();  // Lancer la connexion à Arduino

    // Traitement du résultat de la connexion
    switch (ret) {
    case 0:  // Connexion réussie
        qDebug() << "Arduino is available and connected to:" << A->getarduino_port_name();
        break;
    case 1:  // Arduino est disponible mais la connexion a échoué
        qDebug() << "Arduino is available but not connected to:" << A->getarduino_port_name();
        break;
    case -1: // Arduino n'est pas disponible
        qDebug() << "Arduino is not available";
        break;
    default:
        qDebug() << "Unknown error";
        break;
    }




    connect(ui->boutonRechercherNom_2, &QPushButton::clicked, this, &MainWindow::on_boutonRechercherNom_clicked);
    afficherEquipes();
    mettreAJourStatistiques(); // ✅ MAJ LCD dès le démarrage
    // Initialize the match table

    ui->tableWidget_equipe->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_equipe->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList paysList = {"Sélectionner un pays", "France", "Brésil", "Espagne", "Italie", "Argentine",
                            "Allemagne", "Portugal", "Maroc", "Sénégal", "Tunisie"};

    ui->comboBox_paye->addItems(paysList);
    ui->comboBox_paye_2->addItems(paysList);
}

MainWindow::~MainWindow()
{
    //arduino.close_arduino();
    delete ui;
}

void MainWindow::afficherEquipes()
{
    QSqlQuery query("SELECT * FROM EQUIPE");

    ui->tableWidget_equipe->setRowCount(0);
    ui->tableWidget_equipe->setColumnCount(6);
    QStringList headers = {"ID_EQ", "NOM_EQ", "PAYE_Q", "ENTRAINEUR" , "RANG_EQ","NB_JR"};
    ui->tableWidget_equipe->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->tableWidget_equipe->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_equipe->setItem(row, col, item);
        }
        row++;
    }
}




/*void MainWindow::handleArduinoReadyRead()
{
    qDebug() << "===== handleArduinoReadyRead() STARTED ====="; // <-- ADD 1

    QByteArray data = arduino.readFromArduino();
    QString receivedString = QString::fromLatin1(data).trimmed();

    if (receivedString.isEmpty()) {
        qDebug() << "Received empty data, ignoring."; // <-- ADD 2
        qDebug() << "===== handleArduinoReadyRead() FINISHED (empty read) =====";
        return;
    }

    qDebug() << "Received raw data:" << data; // <-- ADD 3
    qDebug() << "Received processed string (UID?):" << receivedString; // <-- ADD 4

    QString rfid_uid = receivedString;

    // Basic validation
    if (rfid_uid.length() < 4 || rfid_uid.length() > 20) {
        qDebug() << "Ignoring potentially invalid UID:" << rfid_uid;
        qDebug() << "===== handleArduinoReadyRead() FINISHED (invalid UID) =====";
        return;
    }

    // --- Query the EMPLOYE table ---
    qDebug() << "Preparing database query for RFID:" << rfid_uid; // <-- ADD 5
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM SYSTEM.EMPLOYE WHERE RFID = :rfid");
    checkQuery.bindValue(":rfid", rfid_uid);

    QString commandToSend;
    bool accessGranted = false;

    qDebug() << "Executing database query..."; // <-- ADD 6
    if (checkQuery.exec()) {
        qDebug() << "Database query executed successfully."; // <-- ADD 7
        if (checkQuery.next()) {
            int count = checkQuery.value(0).toInt();
            qDebug() << "Query result count:" << count; // <-- ADD 8
            if (count > 0) {
                qDebug() << "RFID FOUND. Setting command to OPEN."; // <-- ADD 9
                commandToSend = "OPEN\n";
                accessGranted = true;
            } else {
                qDebug() << "RFID NOT FOUND. Setting command to DENY."; // <-- ADD 10
                commandToSend = "DENY\n";
                accessGranted = false;
            }
        } else {
            qDebug() << "Query executed but .next() failed!"; // <-- ADD 11
            commandToSend = "DENY\n";
        }
    } else {
        qDebug() << "!!! Database query FAILED:" << checkQuery.lastError().text(); // <-- ADD 12
        QMessageBox::critical(this, "Database Error", "Failed to check RFID: " + checkQuery.lastError().text());
        commandToSend = "DENY\n";
    }

    // --- Send command back to Arduino ---
    if (!commandToSend.isEmpty()) {
        qDebug() << "Attempting to send command to Arduino:" << commandToSend.trimmed(); // <-- ADD 13
        arduino.write_to_arduino(commandToSend.toLatin1());
        qDebug() << "Command sent (or at least write function was called)."; // <-- ADD 14
    } else {
        qDebug() << "!!! No command determined to send back!"; // <-- ADD 15
    }
    qDebug() << "===== handleArduinoReadyRead() FINISHED ====="; // <-- ADD 16
}
*/



















void MainWindow::on_pushButton_ajouter_clicked()
{
    QString nb_jr_str = ui->lineEdit_nbjr->text();
    QString nom = ui->lineEdit_nom->text();
    QString pays = ui->comboBox_paye->currentText();
    int rang = ui->spinBox_rang->value();
    QString entraineur = ui->lineEdit_entraineur->text();

    QRegularExpression regexNom("^[^0-9]+$");
    if (!regexNom.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'équipe ne doit pas contenir de chiffres.");
        return;
    }
    if (!regexNom.match(entraineur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'entraîneur ne doit pas contenir de chiffres.");
        return;
    }

    QRegularExpression regexNum("^[0-9]+$");
    if (!regexNum.match(nb_jr_str).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nombre de joueurs doit être un nombre entier.");
        return;
    }
    int nb_jr = nb_jr_str.toInt();
    if (nb_jr <= 20) {
        QMessageBox::warning(this, "Erreur", "Le nombre de joueurs doit être supérieur à 20.");
        return;
    }
    if (rang == 0) {
        QMessageBox::warning(this, "Erreur", "Le rang ne peut pas être égal à 0.");
        return;
    }
    if (ui->comboBox_paye->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un pays valide.");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EQUIPE WHERE RANG_EQ = :rang");
    checkQuery.bindValue(":rang", rang);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Ce rang est déjà utilisé par une autre équipe.");
        return;
    }

    Equipe e(nb_jr, nom, pays, rang, entraineur);
    if (e.ajouter()) {
        afficherEquipes();
        mettreAJourStatistiques(); // ✅ MAJ LCD
        ui->lineEdit_nbjr->clear();
        ui->lineEdit_nom->clear();
        ui->comboBox_paye->setCurrentIndex(0);
        ui->spinBox_rang->setValue(0);
        ui->lineEdit_entraineur->clear();
        QMessageBox::information(this, "Succès", "Équipe ajoutée avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'équipe.");
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_eq = ui->lineEdit_id_delete->text().toInt();
    if (id_eq <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE WHERE ID_EQ = :id_eq");
    query.bindValue(":id_eq", id_eq);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "L'équipe a été supprimée avec succès.");
        afficherEquipes();
        mettreAJourStatistiques(); // ✅ MAJ LCD après suppression
        ui->lineEdit_id_delete->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id_eq = ui->lineEdit_id_modify->text().toInt();
    QString nom_eq = ui->lineEdit_nom_2->text();
    int nb_jr = ui->lineEdit_nbjr_2->text().toInt();
    QString paye_q = ui->comboBox_paye_2->currentText();
    int rang_eq = ui->spinBox_rang_2->value();
    QString entraineur = ui->lineEdit_entraineur_2->text();

    if (id_eq <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return;
    }

    if (nb_jr <= 20) {
        QMessageBox::warning(this, "Erreur", "Le nombre de joueurs doit être supérieur à 20.");
        return;
    }

    if (rang_eq == 0) {
        QMessageBox::warning(this, "Erreur", "Le rang ne peut pas être égal à 0.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE EQUIPE SET "
                  "NOM_EQ = :nom_eq, "
                  "NB_JR = :nb_jr, "
                  "PAYE_Q = :paye_q, "
                  "RANG_EQ = :rang_eq, "
                  "ENTRAINEUR = :entraineur "
                  "WHERE ID_EQ = :id_eq");

    query.bindValue(":nom_eq", nom_eq);
    query.bindValue(":nb_jr", nb_jr);
    query.bindValue(":paye_q", paye_q);
    query.bindValue(":rang_eq", rang_eq);
    query.bindValue(":entraineur", entraineur);
    query.bindValue(":id_eq", id_eq);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "L'équipe a été modifiée avec succès !");
        afficherEquipes();
        mettreAJourStatistiques(); // ✅ MAJ LCD
        ui->lineEdit_id_modify->clear();
        ui->lineEdit_nom_2->clear();
        ui->lineEdit_nbjr_2->clear();
        ui->comboBox_paye_2->setCurrentIndex(0);
        ui->spinBox_rang_2->setValue(0);
        ui->lineEdit_entraineur_2->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification : " + query.lastError().text());
    }
}

void MainWindow::mettreAJourStatistiques()
{
    QSqlQuery query("SELECT COUNT(*) FROM EQUIPE");
    if (query.next()) {
        int total = query.value(0).toInt();
        ui->lcdNumber_total->display(total);
    }
}






void MainWindow::on_pushButton_rechercher_clicked()
{
    int id = ui->lineEdit_recherche_id->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }
    afficherEquipeParId(id);
}

void MainWindow::afficherEquipeParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPE WHERE ID_EQ = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur dans la recherche.");
        return;
    }

    ui->tableWidget_equipe->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget_equipe->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_equipe->setItem(row, col, item);
        }
        row++;
    }
}

void MainWindow::on_pushButton_trier_clicked()
{
    QSqlQuery query("SELECT * FROM EQUIPE ORDER BY RANG_EQ ASC");

    ui->tableWidget_equipe->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget_equipe->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tableWidget_equipe->setItem(row, col, item);
        }
        row++;
    }
}

void MainWindow::on_pushButton_export_pdf_clicked()
{
    QPdfWriter writer("export_equipes.pdf");
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Landscape); // 🔁 Format paysage
    writer.setResolution(300); // Haute qualité

    QPainter painter(&writer);

    int margin = 100;
    int startX = margin;
    int startY = margin + 200;
    int rowHeight = 40 * 3.5;
    int colWidth = 150 * 3.5;

    QFont font("Times", 16);
    painter.setFont(font);

    // ✅ LOGO EN HAUT (si tu as un logo dans les ressources)
    QPixmap logo(":/logo.png");
    if (!logo.isNull()) {
        painter.drawPixmap(startX, margin, 200, 200, logo);
    }

    // ✅ TITRE
    painter.drawText(startX + 220, margin + 100, "Liste des Équipes");

    int x = startX;
    int y = startY;

    // ✅ En-têtes de colonnes avec fond coloré
    QStringList headers = {"ID_EQ", "NB_JR", "NOM_EQ", "PAYE_Q", "RANG_EQ", "ENTRAINEUR"};
    painter.setBrush(QColor(200, 200, 255)); // Bleu clair
    painter.setPen(Qt::black);

    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
        painter.drawText(x + col * colWidth + 20, y + rowHeight / 2, headers[col]);
    }

    y += rowHeight;

    // ✅ Données du tableau
    int rowCount = ui->tableWidget_equipe->rowCount();
    int colCount = ui->tableWidget_equipe->columnCount();
    int currentPage = 1;

    for (int row = 0; row < rowCount; ++row) {
        if (y + rowHeight > writer.height() - margin) {
            writer.newPage();
            y = startY;

            // Réaffichage des en-têtes
            painter.setBrush(QColor(200, 200, 255));
            for (int col = 0; col < headers.size(); ++col) {
                painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
                painter.drawText(x + col * colWidth + 20, y + rowHeight / 2, headers[col]);
            }
            y += rowHeight;
            currentPage++;
        }

        for (int col = 0; col < colCount; ++col) {
            QString text = ui->tableWidget_equipe->item(row, col)->text();

            // ✅ Première colonne avec fond différent
            if (col == 0) {
                painter.setBrush(QColor(255, 255, 200)); // Jaune clair
            } else {
                painter.setBrush(Qt::NoBrush);
            }

            painter.setPen(Qt::black);
            painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
            painter.drawText(x + col * colWidth + 20, y + rowHeight / 2, text);
        }
        y += rowHeight;
    }

    // ✅ Pagination en bas à droite
    painter.drawText(writer.width() - 300, writer.height() - 100, "Page " + QString::number(currentPage));

    painter.end();
    QMessageBox::information(this, "PDF", "Export PDF réussi avec succès !");
}









void MainWindow::on_boutonRechercherNom_clicked()
{
    QString nom = ui->champRechercheNom->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPE WHERE NOM_EQ LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche.");
        return;
    }

    ui->tableWidget_equipe->setRowCount(0);
    int row = 0;

    while (query.next()) {
        ui->tableWidget_equipe->insertRow(row);
        for (int col = 0; col < query.record().count(); ++col) {
            ui->tableWidget_equipe->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        // Afficher les matchs de la première équipe trouvée
        if (row == 0) {
            int idEquipe = query.value("ID_EQ").toInt();
            afficherHistoriqueMatchs(idEquipe);
        }

        row++;
    }
}








void MainWindow::afficherHistoriqueMatchs(int idEquipe)
{
    QSqlQuery query;
    query.prepare(R"(
    SELECT *
    FROM (
        SELECT
            M.DATE_M,
            E1.NOM_EQ AS EQUIPE1,
            E2.NOM_EQ AS EQUIPE2,
            M.SCORE_EQ1,
            M.SCORE_EQ2
        FROM MATCH M
        JOIN EQUIPE E1 ON M.ID_EQ1 = E1.ID_EQ
        JOIN EQUIPE E2 ON M.ID_EQ2 = E2.ID_EQ
        WHERE M.ID_EQ1 = :id OR M.ID_EQ2 = :id
        ORDER BY M.DATE_M DESC
    )
    WHERE ROWNUM <= 5
)");
    query.bindValue(":id", idEquipe);


    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l’affichage de l’historique.");
        return;
    }

    ui->tableMatchs->setRowCount(0);
    ui->tableMatchs->setColumnCount(5);
    ui->tableMatchs->setHorizontalHeaderLabels({"Date", "Équipe 1", "Score 1", "Score 2", "Équipe 2"});

    int row = 0;
    while (query.next()) {
        ui->tableMatchs->insertRow(row);

        ui->tableMatchs->setItem(row, 0, new QTableWidgetItem(query.value("DATE_M").toString()));
        ui->tableMatchs->setItem(row, 1, new QTableWidgetItem(query.value("EQUIPE1").toString()));
        ui->tableMatchs->setItem(row, 2, new QTableWidgetItem(query.value("SCORE_EQ1").toString()));
        ui->tableMatchs->setItem(row, 3, new QTableWidgetItem(query.value("SCORE_EQ2").toString()));
        ui->tableMatchs->setItem(row, 4, new QTableWidgetItem(query.value("EQUIPE2").toString()));

        row++;
    }
}







