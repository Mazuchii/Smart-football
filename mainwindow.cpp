#include "mainwindow.h"
#include "ui_mainwindow.h" // Generated UI header
#include "employe.h"       // Your Employee class header

// Standard Qt includes needed
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDate>
#include <QHeaderView>    // For table header customization
#include <QSqlQuery>      // Used by Employe class and here for total count
#include <QSqlError>      // For database error info
#include <QSqlQueryModel> // Potentially used by Employe::afficher
#include <QMap>           // For statistics data

// Includes for PDF Export
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>

    // --- Constructor ---
    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Database connection is assumed to be established externally (e.g., in main.cpp)

    // --- Configure the main Employee display table (tab1_2) ---
   // const int employeeTableColumnCount = 10; // ID, Nom, Prenom, DateN, Poste, Sexe, Tel, Salaire, Adresse, Statut
    //ui->tab1_2->setColumnCount(employeeTableColumnCount);
    QStringList employeeTableHeaders = {"ID", "Nom", "Prénom", "Date Naiss.", "Poste", "Sexe", "Téléphone", "Salaire", "Adresse", "Statut"};
    ui->tab1_2->setHorizontalHeaderLabels(employeeTableHeaders);
    ui->tab1_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab1_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tab1_2->verticalHeader()->setVisible(false);
    ui->tab1_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    // --- Populate ComboBoxes (Example: Add Tab Poste) ---
    ui->poste_2->clear();
    ui->poste_2->addItem("Direction génerale");
    ui->poste_2->addItem("Direction de l'arbitrage");
    ui->poste_2->addItem("Direction technique nationale");
    ui->poste_2->addItem("Direction communication");
    // Add more roles as needed

    // --- Setup for the statsPosteTableWidget (Statistics Tab) ---
    // Ensure 'statsPosteTableWidget' is the objectName in your .ui file
    /*if (ui->statsPosteTableWidget) { // Check if the widget exists in the UI
        ui->statsPosteTableWidget->setColumnCount(3); // Poste, Count, Percentage
        QStringList statsHeaders = {"Poste", "Nombre d'Employés", "Pourcentage (%)"};
        ui->statsPosteTableWidget->setHorizontalHeaderLabels(statsHeaders);
        ui->statsPosteTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->statsPosteTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    } else {
        qWarning() << "WARNING: ui->statsPosteTableWidget is NULL. Did you add it to the 'Statistique' tab in mainwindow.ui and give it the correct objectName?";
    }*/


    // --- Initial Data Load ---
    refreshEmployeeTableView(); // Load main employee table

    // Call displayPosteStats if the stats tab is initially active or exists
   /* int statsTabIndex = -1;
    for(int i = 0; i < ui->tabWidget->count(); ++i) {
        if(ui->tabWidget->tabText(i).contains("Statistique", Qt::CaseInsensitive)) { // Match tab title
            statsTabIndex = i;
            break;
        }
    }
    if (statsTabIndex != -1 && ui->tabWidget->currentIndex() == statsTabIndex) {
        if (ui->statsPosteTableWidget) displayPosteStats(); // Only call if widget exists
    }*/

    // --- Connect Signals (Example: Table Click -> Load Modify Form) ---
    // Uncomment if you want clicking a table row to load the modify form
    // connect(ui->tab1_2, &QTableWidget::itemClicked, this, &MainWindow::on_tab1_2_itemClicked);
}

// --- Destructor ---
MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------------------------------
// Slot Implementations
//---------------------------------------------------------------------

void MainWindow::on_addButton_2_clicked()
{
    // --- Get data from UI fields (Add Tab) ---
    QString nom = ui->nom_2->text().trimmed();
    QString prenom = ui->prenom_2->text().trimmed();
    QDate dateNaiss = ui->date_2->date();
    QString salaireStr = ui->salaire_2->text().trimmed();
    QString numTel = ui->numTel_2->text().trimmed();
    QString poste = ui->poste_2->currentText();
    QString sexe;
    if (ui->homme_2->isChecked()) sexe = "H";
    else if (ui->femme_2->isChecked()) sexe = "F";
    QString adresse = ui->adresse ? ui->adresse->text().trimmed() : QString(); // Check if adresse_2 exists
    QString mdp = ui->mdp ? ui->mdp->text() : QString();                       // Check if mdp_2 exists

    // --- Basic Validation ---
    if (nom.isEmpty() || prenom.isEmpty() || salaireStr.isEmpty() || numTel.isEmpty() || sexe.isEmpty() || (ui->adresse && adresse.isEmpty()) ) {
        QMessageBox::warning(this, "Input Error", "Veuillez remplir tous les champs obligatoires (Nom, Prénom, Salaire, Tel, Sexe, Adresse).");
        return;
    }
    bool ok;
    double salaire = salaireStr.toDouble(&ok);
    if (!ok || salaire < 0) {
        QMessageBox::warning(this, "Input Error", "Valeur de salaire invalide.");
        return;
    }

    Employe emp;
    emp.setNom(nom);
    emp.setPrenom(prenom);
    emp.setDateNaissEmp(dateNaiss);
    emp.setSalaire(salaire);
    emp.setNumTelEmp(numTel);
    emp.setPoste(poste);
    emp.setSexe(sexe);
    emp.setAdresse(adresse);
    emp.setMdp(mdp);
    emp.setStatut("Actif"); // Default value for STATUT

    qDebug() << "--- Values being sent to emp.ajouter() ---";
    qDebug() << "NOM:" << emp.getNom() << "| PRENOM:" << emp.getPrenom() << "| ADRESSE:" << emp.getAdresse()
             << "| NUM_TEL_EMP:" << emp.getNumTelEmp() << "| DATE_NAISS:" << emp.getDateNaissEmp().toString(Qt::ISODate)
             << "| POSTE:" << emp.getPoste() << "| SALAIRE:" << emp.getSalaire() << "| STATUT:" << emp.getStatut()
             << "| SEXE:" << emp.getSexe() << "| MDP:" << emp.getMdp();
    qDebug() << "--- End of values ---";

    if (emp.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès!");
        clearAddForm();
        refreshEmployeeTableView();
    } else {
        QMessageBox::critical(this, "Erreur Base de Données", "Échec de l'ajout de l'employé.\nVérifiez la console pour les détails de l'erreur Oracle.");
    }
}


void MainWindow::on_deleteButton_2_clicked()
{
    QString idStr = ui->idd_2->text().trimmed();
    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Veuillez entrer l'ID de l'employé à supprimer.");
        return;
    }
    bool ok;
    int id = idStr.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "Input Error", "ID d'employé invalide.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer Suppression", "Êtes-vous sûr de vouloir supprimer l'employé ID " + idStr + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Employe::supprimer(id)) {
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès!");
            ui->idd_2->clear();
            refreshEmployeeTableView();
        } else {
            QMessageBox::warning(this, "Erreur/Non Trouvé", "Impossible de supprimer l'employé.");
        }
    }
}

void MainWindow::on_editButton_2_clicked()
{
    QString idStr = ui->idd_3->text().trimmed();
    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Veuillez d'abord charger un employé à modifier.");
        return;
    }
    bool idOk;
    int id_to_update = idStr.toInt(&idOk);
    if (!idOk || id_to_update <= 0) {
        QMessageBox::warning(this, "Input Error", "ID chargé invalide.");
        return;
    }

    QString nom = ui->nom_3->text().trimmed();
    QString prenom = ui->prenom_3->text().trimmed();
    QDate dateNaiss = ui->date_3->date();
    QString salaireStr = ui->salaire_3->text().trimmed();
    QString poste = ui->poste_3->text().trimmed();
    QString numTel = ui->numTel_3->text().trimmed();
    // Assuming Adresse, MDP, Statut, Sexe are also editable on the modify tab via similar ui elements (e.g., ui->adresse_3, ui->mdp_3 etc.)
    // QString adresse_mod = ui->adresse_3 ? ui->adresse_3->text().trimmed() : QString();
    // QString mdp_mod = ui->mdp_3 ? ui->mdp_3->text() : QString();
    // QString statut_mod = ... ; // From UI or keep existing
    // QString sexe_mod = ... ; // From UI or keep existing


    if (nom.isEmpty() || prenom.isEmpty() || salaireStr.isEmpty() || numTel.isEmpty() || poste.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Veuillez remplir tous les champs obligatoires pour la modification.");
        return;
    }
    bool salaireOk;
    double salaire = salaireStr.toDouble(&salaireOk);
    if (!salaireOk || salaire < 0) {
        QMessageBox::warning(this, "Input Error", "Valeur de salaire invalide.");
        return;
    }

    Employe emp = Employe::chercher(id_to_update);
    if (emp.getIdEmp() == -1) {
        QMessageBox::critical(this, "Erreur", "Impossible de retrouver l'employé à modifier (ID: " + idStr + ").");
        return;
    }
    emp.setNom(nom);
    emp.setPrenom(prenom);
    emp.setDateNaissEmp(dateNaiss);
    emp.setSalaire(salaire);
    emp.setNumTelEmp(numTel);
    emp.setPoste(poste);
    // emp.setAdresse(adresse_mod); // If address is editable
    // emp.setMdp(mdp_mod);         // If mdp is editable
    // emp.setStatut(statut_mod);   // If statut is editable
    // emp.setSexe(sexe_mod);       // If sexe is editable

    if (emp.modifier(id_to_update)) {
        QMessageBox::information(this, "Succès", "Employé mis à jour avec succès!");
        refreshEmployeeTableView();
    } else {
        QMessageBox::critical(this, "Erreur Base de Données", "Échec de la mise à jour de l'employé.");
    }
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    const int afficherEmployeTabIndex = 1; // Assuming "afficher employe" is the 2nd tab (index 1)
    int statsTabIndex = -1;
    for(int i = 0; i < ui->tabWidget->count(); ++i) {
        if(ui->tabWidget->tabText(i).contains("Statistique", Qt::CaseInsensitive)) {
            statsTabIndex = i;
            break;
        }
    }

    if (index == afficherEmployeTabIndex) {
        refreshEmployeeTableView();
    }
    /*else if (statsTabIndex != -1 && index == statsTabIndex) {
        if (ui->statsPosteTableWidget) displayPosteStats(); // Display stats for Poste
    }*/
}


void MainWindow::on_btrecherche_clicked()
{
    QString searchTerm = ui->recherche->text().trimmed();
    refreshEmployeeTableView(searchTerm);
}


void MainWindow::on_PDF_clicked()
{
    generatePdf();
}


//---------------------------------------------------------------------
// Helper Functions
//---------------------------------------------------------------------

void MainWindow::refreshEmployeeTableView(QString filter)
{
    QSqlQueryModel *model = Employe::afficher(filter);
    ui->tab1_2->clearContents();
    ui->tab1_2->setRowCount(0);

    if (model) {
        ui->tab1_2->setRowCount(model->rowCount());
        if(ui->tab1_2->columnCount() != model->columnCount()){
            qWarning() << "Warning: Employee TableWidget column count mismatch. Adjusting table columns.";
            ui->tab1_2->setColumnCount(model->columnCount());
            // Re-set headers if column count changed and headers were based on old count
            QStringList employeeTableHeaders;
            for(int c=0; c < model->columnCount(); ++c) employeeTableHeaders << model->headerData(c, Qt::Horizontal).toString();
            ui->tab1_2->setHorizontalHeaderLabels(employeeTableHeaders);
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                QString data = model->data(index).toString();
                if (model->headerData(col, Qt::Horizontal).toString().contains("Date", Qt::CaseInsensitive)) {
                    data = model->data(index).toDate().toString("dd/MM/yyyy");
                } else if (model->headerData(col, Qt::Horizontal).toString().contains("Salaire", Qt::CaseInsensitive)) {
                    data = QString::number(model->data(index).toDouble(), 'f', 2);
                }
                QTableWidgetItem* newItem = new QTableWidgetItem(data);
                if (model->headerData(col, Qt::Horizontal).toString() == "ID" ||
                    model->headerData(col, Qt::Horizontal).toString().contains("Salaire", Qt::CaseInsensitive)) {
                    newItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
                }
                ui->tab1_2->setItem(row, col, newItem);
            }
        }
        delete model;
    } else {
        QMessageBox::critical(this, "Erreur Base de Données", "Impossible de récupérer les données des employés.");
    }
}


void MainWindow::loadEmployeeDataForEdit(const QString& idStr)
{
    bool ok;
    int id = idStr.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "ID Invalide", "ID numérique invalide.");
        ui->idd_3->clear(); ui->nom_3->clear(); ui->prenom_3->clear();
        ui->date_3->setDate(QDate::currentDate()); ui->salaire_3->clear();
        ui->niv_3->clear(); ui->poste_3->clear(); ui->numTel_3->clear();
        // Clear adresse_3, mdp_3 etc. if they exist in modify tab
        return;
    }

    Employe emp = Employe::chercher(id);
    if (emp.getIdEmp() != -1) {
        ui->idd_3->setText(QString::number(emp.getIdEmp()));
        ui->nom_3->setText(emp.getNom());
        ui->prenom_3->setText(emp.getPrenom());
        ui->date_3->setDate(emp.getDateNaissEmp());
        ui->salaire_3->setText(QString::number(emp.getSalaire(), 'f', 2));
        ui->niv_3->clear(); // Niveaux_d'experience field
        ui->poste_3->setText(emp.getPoste());
        ui->numTel_3->setText(emp.getNumTelEmp());
        // Set ui->adresse_3, ui->mdp_3 etc. if they exist for modification
        // ui->adresse_3->setText(emp.getAdresse());
        // ui->mdp_3->setText(emp.getMdp()); // Careful with displaying passwords
    } else {
        QMessageBox::warning(this, "Non Trouvé", "Employé ID non trouvé.");
        ui->idd_3->clear(); ui->nom_3->clear(); ui->prenom_3->clear();
        ui->date_3->setDate(QDate::currentDate()); ui->salaire_3->clear();
        ui->niv_3->clear(); ui->poste_3->clear(); ui->numTel_3->clear();
    }
}


void MainWindow::clearAddForm() {
    ui->nom_2->clear();
    ui->prenom_2->clear();
    ui->date_2->setDate(QDate::currentDate());
    ui->salaire_2->clear();
    ui->niveaux_dexp_2->clear();
    ui->numTel_2->clear();
    ui->poste_2->setCurrentIndex(0);
    if (ui->adresse) ui->adresse->clear();
    if (ui->mdp) ui->mdp->clear();
    ui->homme_2->setAutoExclusive(false); ui->femme_2->setAutoExclusive(false);
    ui->homme_2->setChecked(false); ui->femme_2->setChecked(false);
    ui->homme_2->setAutoExclusive(true); ui->femme_2->setAutoExclusive(true);
}


void MainWindow::generatePdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) fileName += ".pdf";

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 20)); // Margins in mm

    QTextDocument document;
    QString htmlContent = R"(
        <html><head><style>
            body { font-family: Arial, sans-serif; font-size: 9pt; }
            h1 { text-align: center; color: #333; margin-bottom: 15px; }
            table { width: 100%; border-collapse: collapse; }
            th, td { border: 1px solid #ccc; padding: 4px; text-align: left; word-wrap: break-word; }
            th { background-color: #f0f0f0; font-weight: bold; }
            tr:nth-child(even) { background-color: #f8f8f8; }
        </style></head><body>
        <h1>Liste des Employés</h1><table><thead><tr>
    )";
    for (int col = 0; col < ui->tab1_2->columnCount(); ++col) {
        QTableWidgetItem* headerItem = ui->tab1_2->horizontalHeaderItem(col);
        htmlContent += "<th>" + (headerItem ? headerItem->text() : QString("Col %1").arg(col+1)) + "</th>";
    }
    htmlContent += "</tr></thead><tbody>";
    for (int row = 0; row < ui->tab1_2->rowCount(); ++row) {
        htmlContent += "<tr>";
        for (int col = 0; col < ui->tab1_2->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tab1_2->item(row, col);
            QString cellText = item ? item->text() : "";
            cellText.replace('&', "&").replace('<', "<").replace('>', ">");
            htmlContent += "<td>" + cellText + "</td>";
        }
        htmlContent += "</tr>";
    }
    htmlContent += R"(</tbody></table></body></html>)";
    document.setHtml(htmlContent);
    document.print(&pdfWriter);
    QMessageBox::information(this, "Succès", "PDF exporté avec succès vers:\n" + fileName);
}

// --- Implementation for displaying Poste Statistics ---


// --- Optional Slot for Table Click ---
/*
void MainWindow::on_tab1_2_itemClicked(QTableWidgetItem *item)
{
    if (!item) return;
    int row = item->row();
    QTableWidgetItem* idItem = ui->tab1_2->item(row, 0); // Assuming ID is column 0

    if(idItem) {
        QString idStr = idItem->text();
        int modifyTabIndex = -1;
        for(int i=0; i < ui->tabWidget->count(); ++i) {
            if(ui->tabWidget->tabText(i).contains("modifier employe", Qt::CaseInsensitive)) { // Match tab title
                 modifyTabIndex = i;
                 break;
            }
        }
        if (modifyTabIndex != -1) {
             ui->tabWidget->setCurrentIndex(modifyTabIndex);
             loadEmployeeDataForEdit(idStr);
        } else {
             qWarning() << "Could not find 'modifier employe' tab!";
        }
    }
}
*/
