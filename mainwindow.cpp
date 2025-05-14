#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "joueur.h"
#include "employe.h"
#include "equipe.h"
#include "gesmatch.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QRegularExpression>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QDebug>
#include <QDate>
#include <QHeaderView>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMap>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QFile>
#include <QStandardPaths>
#include <QPixmap>
#include <QSqlRecord>

QT_USE_NAMESPACE

// MainWindow constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // Note: Corrected "setupuchy" to "setupUi"

    // Pass this (MainWindow) to Match
    match = new Match(ui, this, this);

    // Initialisation de la table
    updateTableView(joueur.afficher());

    // Connexions manuelles des boutons
    connect(ui->trierParIDButton, &QPushButton::clicked, this, &MainWindow::on_trierParIDButton_clicked);
    connect(ui->trierParNomButton, &QPushButton::clicked, this, &MainWindow::on_trierParNomButton_clicked);
    connect(ui->trierParPrenomButton, &QPushButton::clicked, this, &MainWindow::on_trierParPrenomButton_clicked);
    connect(ui->trierParNumeroButton, &QPushButton::clicked, this, &MainWindow::on_trierParNumeroButton_clicked);
    connect(ui->rechercherParNomButton, &QPushButton::clicked, this, &MainWindow::on_rechercherParNomButton_clicked);

    // Manual connection for analyzePerformanceButton
    connect(ui->analyzePerformanceButton, &QPushButton::clicked, this, &MainWindow::analyzePerformance);

    // Reset table when search field is cleared
    connect(ui->rechercherNomLineEdit, &QLineEdit::textChanged, this, [this](const QString& text) {
        if (text.isEmpty()) {
            updateTableView(joueur.afficher());
        }
    });

    ui->chatHistory->setReadOnly(true);
    ui->chatHistory->append("Chatbot: Bonjour! Je suis ici pour vous aider. Tapez une commande comme 'add player', 'delete player', ou 'show players'.");

    // Database connection is assumed to be established externally (e.g., in main.cpp)

    // --- Configure the main Employee display table (tab1_2) ---
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

    if (ui->statsDisplayWidget) {
        if (!ui->statsDisplayWidget->layout()) {
            QVBoxLayout *statsLayout = new QVBoxLayout(ui->statsDisplayWidget);
            ui->statsDisplayWidget->setLayout(statsLayout);
            qDebug() << "Dynamically added QVBoxLayout to statsDisplayWidget.";
        }
    } else {
        qWarning() << "WARNING: ui->statsDisplayWidget is NULL. Ensure it exists on the 'Statistique' tab and is named correctly.";
    }

    // --- Initial Data Load ---
    refreshEmployeeTableView();

    int statsTabIndex = -1;
    for(int i = 0; i < ui->tabWidget->count(); ++i) {
        if(ui->tabWidget->tabText(i).contains("Statistique", Qt::CaseInsensitive)) {
            statsTabIndex = i;
            break;
        }
    }
    if (statsTabIndex != -1 && ui->tabWidget->currentIndex() == statsTabIndex) {
        if (ui->statsDisplayWidget) displayPosteStats();
    }

    // --- Initial Data Load ---
    refreshEmployeeTableView();

    // --- Connect Signals (Example: Table Click -> Load Modify Form) ---
    connect(ui->tab1_2, &QTableWidget::itemClicked, this, [this](QTableWidgetItem *item) {
        this->on_tab1_2_itemClicked(item);
    });

    //----------------------------------------equipe-----------------------------------------------------------------------------------------------
    connect(ui->boutonRechercherNom_2, &QPushButton::clicked, this, &MainWindow::on_boutonRechercherNom_clicked);
    afficherEquipes();
    mettreAJourStatistiques();
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
    delete ui;
}

void MainWindow::updateTableView(QSqlQueryModel *model) {
    QStringList headers;
    headers << "ID du Joueur" << "Nom" << "Prénom" << "Date de naissance" << "Numéro du joueur" << "Nom d'équipe";

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < headers.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget->setItem(row, col, item);
        }
    }

    delete model;
}

void MainWindow::on_voirStatsButton_clicked() {
    QSqlQueryModel* model = joueur.getEquipeStats();
    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée disponible pour les statistiques.");
        delete model;
        return;
    }

    QPieSeries *series = new QPieSeries();
    for (int row = 0; row < model->rowCount(); ++row) {
        QString nomEq = model->data(model->index(row, 0)).toString();
        int nbJoueurs = model->data(model->index(row, 1)).toInt();
        series->append(nomEq, nbJoueurs);
    }

    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1 (%2 joueurs)").arg(slice->label()).arg(int(slice->value())));
    }

    if (!series->slices().isEmpty()) {
        series->slices().at(0)->setExploded(true);
        series->slices().at(0)->setLabelPosition(QPieSlice::LabelOutside);
    }

    QList<QColor> colors = {Qt::blue, Qt::green, Qt::red, Qt::yellow, Qt::cyan};
    for (int i = 0; i < series->slices().size() && i < colors.size(); ++i) {
        series->slices().at(i)->setColor(colors[i]);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des joueurs par équipe");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *chartWindow = new QMainWindow();
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(600, 400);
    chartWindow->setWindowTitle("Statistiques des équipes");
    chartWindow->show();

    delete model;
}

void MainWindow::analyzePerformance() {
    bool ok;
    int playerId = QInputDialog::getInt(this, "Analyser Performance", "Entrez l'ID du joueur pour une analyse détaillée:", 1, 1, 9999, 1, &ok);
    if (!ok) return;

    if (!joueur.idExists(playerId)) {
        QMessageBox::critical(this, "Erreur", "L'ID du joueur n'existe pas !");
        return;
    }

    QSqlQueryModel* trendModel = joueur.getPerformanceTrends(playerId, 5);
    if (trendModel->rowCount() == 0) {
        QMessageBox::information(this, "Performance", "Aucune donnée de match pour ce joueur.");
        delete trendModel;
        return;
    }

    QSqlQueryModel* impactModel = joueur.getMatchImpactScores(playerId);
    if (impactModel->rowCount() == 0) {
        QMessageBox::information(this, "Performance", "Aucune donnée d'impact pour ce joueur.");
        delete trendModel;
        delete impactModel;
        return;
    }

    QTableWidget *impactTable = new QTableWidget();
    QStringList impactHeaders;
    impactHeaders << "ID Match" << "Date" << "Équipe 1" << "Équipe 2" << "Buts" << "Assists" << "Résultat" << "Score d'Impact";
    impactTable->setRowCount(impactModel->rowCount());
    impactTable->setColumnCount(impactHeaders.size());
    impactTable->setHorizontalHeaderLabels(impactHeaders);

    for (int row = 0; row < impactModel->rowCount(); ++row) {
        QTableWidgetItem *idMatchItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 0)).toString());
        QTableWidgetItem *dateItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 1)).toString());
        QTableWidgetItem *equip1Item = new QTableWidgetItem(impactModel->data(impactModel->index(row, 2)).toString());
        QTableWidgetItem *equip2Item = new QTableWidgetItem(impactModel->data(impactModel->index(row, 3)).toString());
        QTableWidgetItem *butsItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 4)).toString());
        QTableWidgetItem *assistsItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 5)).toString());
        QTableWidgetItem *resultatItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 9)).toString());
        QTableWidgetItem *impactScoreItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 10)).toString());

        impactTable->setItem(row, 0, idMatchItem);
        impactTable->setItem(row, 1, dateItem);
        impactTable->setItem(row, 2, equip1Item);
        impactTable->setItem(row, 3, equip2Item);
        impactTable->setItem(row, 4, butsItem);
        impactTable->setItem(row, 5, assistsItem);
        impactTable->setItem(row, 6, resultatItem);
        impactTable->setItem(row, 7, impactScoreItem);
    }

    QBarSeries *series = new QBarSeries();
    QBarSet *goalsSet = new QBarSet("Buts");
    QBarSet *assistsSet = new QBarSet("Assists");
    QStringList categories;

    for (int row = 0; row < trendModel->rowCount(); ++row) {
        int goals = trendModel->data(trendModel->index(row, 2)).toInt();
        int assists = trendModel->data(trendModel->index(row, 3)).toInt();
        QString date = trendModel->data(trendModel->index(row, 1)).toString();

        *goalsSet << goals;
        *assistsSet << assists;
        categories << date;
    }

    series->append(goalsSet);
    series->append(assistsSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Tendances de performance du joueur %1 (derniers 5 matchs)").arg(playerId));
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Matchs (Date)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Valeur");
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *performanceWindow = new QMainWindow();
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    layout->addWidget(new QLabel(QString("Tendances de performance du joueur %1 :").arg(playerId)));
    layout->addWidget(chartView);
    layout->addWidget(new QLabel("Scores d'impact par match :"));
    layout->addWidget(impactTable);

    performanceWindow->setCentralWidget(centralWidget);
    performanceWindow->resize(800, 600);
    performanceWindow->setWindowTitle("Analyse de Performance des Joueurs");
    performanceWindow->show();

    delete trendModel;
    delete impactModel;
}

void MainWindow::on_trierParIDButton_clicked()
{
    updateTableView(joueur.trierParID());
}

void MainWindow::on_trierParNomButton_clicked()
{
    updateTableView(joueur.trierParNom());
}

void MainWindow::on_trierParPrenomButton_clicked()
{
    updateTableView(joueur.trierParPrenom());
}

void MainWindow::on_trierParNumeroButton_clicked()
{
    updateTableView(joueur.trierParNumero());
}

void MainWindow::on_ajouterButton_clicked() {
    qDebug() << "Bouton Ajouter cliqué !";

    QString idText = ui->id_joueur->text();
    QString nom = ui->nom_joueur->text();
    QString prenom = ui->prenom_joueur->text();
    QString ddn = ui->DDN->text();
    int num = ui->num_joueur->text().toInt();
    QString equipe = ui->nom_eq->text().trimmed();

    QRegularExpression idRegex("^\\d+$");
    if (!idRegex.match(idText).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "L'ID ne doit contenir que des chiffres !");
        return;
    }

    int id = idText.toInt();

    if (joueur.idExists(id)) {
        QMessageBox::critical(this, "Erreur", "Cet ID existe déjà ! Veuillez en choisir un autre.");
        return;
    }

    if (nom.isEmpty() || prenom.isEmpty() || ddn.isEmpty() || equipe.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Tous les champs obligatoires doivent être remplis !");
        return;
    }

    QRegularExpression nameRegex("^[A-Za-z]+$");
    if (!nameRegex.match(nom).hasMatch() || !nameRegex.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom et le prénom ne doivent contenir que des lettres !");
        return;
    }

    QDate date = QDate::fromString(ddn, "dd/MM/yyyy");
    if (!date.isValid()) {
        QMessageBox::critical(this, "Erreur", "Format de date invalide !");
        return;
    }
    QDate currentDate = QDate::currentDate();
    int age = currentDate.year() - date.year();
    if (age < 10 || age > 100) {
        QMessageBox::critical(this, "Erreur", "L'âge du joueur doit être entre 10 et 100 ans !");
        return;
    }
    QString oracleDate = date.toString("dd-MMM-yyyy");

    if (num <= 0) {
        QMessageBox::critical(this, "Erreur", "Le numéro de joueur doit être un nombre positif !");
        return;
    }

    if (!nameRegex.match(equipe).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom de l'équipe ne doit contenir que des lettres !");
        return;
    }

    if (!joueur.nomEqExists(equipe)) {
        QMessageBox::critical(this, "Erreur", "Cette equipe n'existe pas");
        return;
    }

    Joueur j(id, nom, prenom, oracleDate, num, equipe);
    if (j.ajouter()) {
        QMessageBox::information(this, "Succès", "Joueur ajouté avec succès !");
        updateTableView(joueur.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du joueur !");
    }
}

void MainWindow::on_supprimerButton_clicked() {
    qDebug() << "Bouton Supprimer cliqué !";
    int id = ui->supp_id_joueur->text().toInt();

    if (!joueur.idExists(id)) {
        QMessageBox::critical(this, "Erreur", "L'ID n'existe pas. Impossible de supprimer.");
        return;
    }

    if (joueur.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Joueur supprimé avec succès!");
        updateTableView(joueur.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du joueur!");
    }
}

void MainWindow::on_modifierButton_clicked() {
    qDebug() << "Bouton Modifier cliqué !";

    QString idText = ui->rech_id_joueur->text();
    int num = ui->mod_num_joueur->text().toInt();
    QString equipe = ui->mod_nom_eq->text().trimmed();

    QRegularExpression idRegex("^\\d+$");
    if (!idRegex.match(idText).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "L'ID ne doit contenir que des chiffres !");
        return;
    }

    int id = idText.toInt();

    if (!joueur.idExists(id)) {
        QMessageBox::critical(this, "Erreur", "L'ID n'existe pas. Impossible de modifier.");
        return;
    }

    if (num <= 0) {
        QMessageBox::critical(this, "Erreur", "Le numéro de joueur doit être un nombre positif !");
        return;
    }

    QRegularExpression nameRegex("^[A-Za-z]+$");
    if (!nameRegex.match(equipe).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom de l'équipe ne doit contenir que des lettres !");
        return;
    }

    if (!joueur.nomEqExists(equipe)) {
        QMessageBox::critical(this, "Erreur", "Cette equipe n'existe pas");
        return;
    }

    if (joueur.modifier(id, num, equipe)) {
        QMessageBox::information(this, "Succès", "Joueur modifié avec succès !");
        updateTableView(joueur.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du joueur !");
    }
}

void MainWindow::on_rechercherButton_clicked() {
    qDebug() << "Bouton Rechercher cliqué !";

    QString idText = ui->rech_id_joueur->text();

    QRegularExpression idRegex("^\\d+$");
    if (!idRegex.match(idText).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "L'ID ne doit contenir que des chiffres !");
        return;
    }

    int id = idText.toInt();

    QSqlQuery query = joueur.rechercher(id);

    if (query.isValid()) {
        QString nom = query.value("NOM").toString();
        QString prenom = query.value("PRENOM").toString();
        QString ddn = query.value("DDN").toString();
        int num = query.value("NUM_JOUEUR").toInt();
        QString equipe = query.value("NOM_EQ").toString();

        ui->mod_num_joueur->setText(QString::number(num));
        ui->mod_nom_eq->setText(equipe);

        ui->mod_num_joueur->setEnabled(true);
        ui->mod_nom_eq->setEnabled(true);
        ui->modifierButton->setEnabled(true);

        qDebug() << "Joueur trouvé :" << nom << prenom;
    } else {
        QMessageBox::critical(this, "Erreur", "Joueur non trouvé !");
        ui->mod_num_joueur->setEnabled(false);
        ui->mod_nom_eq->setEnabled(false);
        ui->modifierButton->setEnabled(false);
    }
}

void MainWindow::on_rechercherParNomButton_clicked() {
    QString nom = ui->rechercherNomLineEdit->text().trimmed().simplified();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un nom pour la recherche !");
        updateTableView(joueur.afficher());
        return;
    }

    qDebug() << "Lancement de la recherche pour le nom :" << nom;

    QSqlQueryModel* model = joueur.rechercherParNom(nom);

    qDebug() << "Nombre de joueurs trouvés :" << model->rowCount();

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Résultat", "Aucun joueur trouvé avec ce nom.");
    }

    updateTableView(model);
}

void MainWindow::on_sendButton_clicked()
{
    QString userInput = ui->chatInput->text().trimmed();
    if (userInput.isEmpty()) {
        return;
    }

    ui->chatHistory->append("Vous: " + userInput);
    processChatInput(userInput);
    ui->chatInput->clear();
}

void MainWindow::processChatInput(const QString& input)
{
    qDebug() << "Processing chat input:" << input;

    QStringList tokens = input.toLower().split(" ", Qt::SkipEmptyParts);
    if (tokens.isEmpty()) {
        ui->chatHistory->append("Chatbot: Commande vide. Essayez 'add player', 'delete player', etc.");
        return;
    }

    QString command = tokens[0];
    QString helpMessage = "Chatbot: Commandes disponibles:\n"
                          "- add player [id] [nom] [prenom] [ddn] [num] [equipe]\n"
                          "- delete player [id]\n"
                          "- modify player [id] [num] [equipe]\n"
                          "- show players\n"
                          "- sort by [nom/prenom/id/numero]\n"
                          "- analyze player [id]\n"
                          "- help";

    if (command == "help") {
        ui->chatHistory->append(helpMessage);
    }
    else if (command == "add" && tokens.size() > 1 && tokens[1] == "player") {
        if (tokens.size() != 8) {
            ui->chatHistory->append("Chatbot: Format incorrect. Utilisez: add player [id] [nom] [prenom] [ddn] [num] [equipe]");
            return;
        }

        QString idText = tokens[2];
        QString nom = tokens[3];
        QString prenom = tokens[4];
        QString ddn = tokens[5];
        QString numText = tokens[6];
        QString equipe = tokens[7];

        QRegularExpression idRegex("^\\d+$");
        if (!idRegex.match(idText).hasMatch()) {
            ui->chatHistory->append("Chatbot: L'ID ne doit contenir que des chiffres !");
            return;
        }
        int id = idText.toInt();

        if (joueur.idExists(id)) {
            ui->chatHistory->append("Chatbot: Cet ID existe déjà ! Veuillez en choisir un autre.");
            return;
        }

        if (nom.isEmpty() || prenom.isEmpty() || ddn.isEmpty() || equipe.isEmpty()) {
            ui->chatHistory->append("Chatbot: Tous les champs obligatoires doivent être remplis !");
            return;
        }

        QRegularExpression nameRegex("^[A-Za-z]+$");
        if (!nameRegex.match(nom).hasMatch() || !nameRegex.match(prenom).hasMatch()) {
            ui->chatHistory->append("Chatbot: Le nom et le prénom ne doivent contenir que des lettres !");
            return;
        }

        QDate date = QDate::fromString(ddn, "dd/MM/yyyy");
        if (!date.isValid()) {
            ui->chatHistory->append("Chatbot: Format de date invalide ! Utilisez dd/MM/yyyy.");
            return;
        }
        QDate currentDate = QDate::currentDate();
        int age = currentDate.year() - date.year();
        if (age < 10 || age > 100) {
            ui->chatHistory->append("Chatbot: L'âge du joueur doit être entre 10 et 100 ans !");
            return;
        }
        QString oracleDate = date.toString("dd-MMM-yyyy");

        bool ok;
        int num = numText.toInt(&ok);
        if (!ok || num <= 0) {
            ui->chatHistory->append("Chatbot: Le numéro de joueur doit être un nombre positif !");
            return;
        }

        if (!nameRegex.match(equipe).hasMatch()) {
            ui->chatHistory->append("Chatbot: Le nom de l'équipe ne doit contenir que des lettres !");
            return;
        }

        if (!joueur.nomEqExists(equipe)) {
            ui->chatHistory->append("Chatbot: Cette équipe n'existe pas !");
            return;
        }

        Joueur j(id, nom, prenom, oracleDate, num, equipe);
        if (j.ajouter()) {
            ui->chatHistory->append("Chatbot: Joueur ajouté avec succès !");
            updateTableView(joueur.afficher());
        } else {
            ui->chatHistory->append("Chatbot: Échec de l'ajout du joueur !");
        }
    }
    else if (command == "delete" && tokens.size() > 1 && tokens[1] == "player") {
        if (tokens.size() != 3) {
            ui->chatHistory->append("Chatbot: Format incorrect. Utilisez: delete player [id]");
            return;
        }

        QString idText = tokens[2];
        QRegularExpression idRegex("^\\d+$");
        if (!idRegex.match(idText).hasMatch()) {
            ui->chatHistory->append("Chatbot: L'ID ne doit contenir que des chiffres !");
            return;
        }
        int id = idText.toInt();

        if (!joueur.idExists(id)) {
            ui->chatHistory->append("Chatbot: L'ID n'existe pas. Impossible de supprimer.");
            return;
        }

        if (joueur.supprimer(id)) {
            ui->chatHistory->append("Chatbot: Joueur supprimé avec succès !");
            updateTableView(joueur.afficher());
        } else {
            ui->chatHistory->append("Chatbot: Échec de la suppression du joueur !");
        }
    }
    else if (command == "modify" && tokens.size() > 1 && tokens[1] == "player") {
        if (tokens.size() != 5) {
            ui->chatHistory->append("Chatbot: Format incorrect. Utilisez: modify player [id] [num] [equipe]");
            return;
        }

        QString idText = tokens[2];
        QString numText = tokens[3];
        QString equipe = tokens[4];

        QRegularExpression idRegex("^\\d+$");
        if (!idRegex.match(idText).hasMatch()) {
            ui->chatHistory->append("Chatbot: L'ID ne doit contenir que des chiffres !");
            return;
        }
        int id = idText.toInt();

        if (!joueur.idExists(id)) {
            ui->chatHistory->append("Chatbot: L'ID n'existe pas. Impossible de modifier.");
            return;
        }

        bool ok;
        int num = numText.toInt(&ok);
        if (!ok || num <= 0) {
            ui->chatHistory->append("Chatbot: Le numéro de joueur doit être un nombre positif !");
            return;
        }

        QRegularExpression nameRegex("^[A-Za-z]+$");
        if (!nameRegex.match(equipe).hasMatch()) {
            ui->chatHistory->append("Chatbot: Le nom de l'équipe ne doit contenir que des lettres !");
            return;
        }

        if (!joueur.nomEqExists(equipe)) {
            ui->chatHistory->append("Chatbot: Cette équipe n'existe pas !");
            return;
        }

        if (joueur.modifier(id, num, equipe)) {
            ui->chatHistory->append("Chatbot: Joueur modifié avec succès !");
            updateTableView(joueur.afficher());
        } else {
            ui->chatHistory->append("Chatbot: Échec de la modification du joueur !");
        }
    }
    else if (command == "show" && tokens.size() > 1 && tokens[1] == "players") {
        if (tokens.size() != 2) {
            ui->chatHistory->append("Chatbot: Format incorrect. Utilisez: show players");
            return;
        }

        QSqlQueryModel* model = joueur.afficher();
        if (model->rowCount() == 0) {
            ui->chatHistory->append("Chatbot: Aucun joueur à afficher.");
        } else {
            ui->chatHistory->append("Chatbot: Affichage des joueurs dans la table.");
            updateTableView(model);
        }
    }
    else if (command == "sort" && tokens.size() > 1 && tokens[1] == "by") {
        if (tokens.size() != 3) {
            ui->chatHistory->append("Chatbot: Format incorrect. Utilisez: sort by [nom/prenom/id/numero]");
            return;
        }

        QString criterion = tokens[2];
        QSqlQueryModel* model = nullptr;

        if (criterion == "nom") {
            model = joueur.trierParNom();
            ui->chatHistory->append("Chatbot: Joueurs triés par nom.");
        }
        else if (criterion == "prenom") {
            model = joueur.trierParPrenom();
            ui->chatHistory->append("Chatbot: Joueurs triés par prénom.");
        }
        else if (criterion == "id") {
            model = joueur.trierParID();
            ui->chatHistory->append("Chatbot: Joueurs triés par ID.");
        }
        else if (criterion == "numero") {
            model = joueur.trierParNumero();
            ui->chatHistory->append("Chatbot: Joueurs triés par numéro.");
        }
        else {
            ui->chatHistory->append("Chatbot: Critère de tri invalide. Utilisez nom, prenom, id ou numero.");
            return;
        }

        if (model->rowCount() == 0) {
            ui->chatHistory->append("Chatbot: Aucun joueur à afficher après le tri.");
        }
        updateTableView(model);
    }
    else if (command == "analyze" && tokens.size() > 1 && tokens[1] == "player") {
        if (tokens.size() != 3) {
            ui->chatHistory->append("Chatbot: Format incorrect. Utilisez: analyze player [id]");
            return;
        }

        QString idText = tokens[2];
        QRegularExpression idRegex("^\\d+$");
        if (!idRegex.match(idText).hasMatch()) {
            ui->chatHistory->append("Chatbot: L'ID ne doit contenir que des chiffres !");
            return;
        }
        int id = idText.toInt();

        if (!joueur.idExists(id)) {
            ui->chatHistory->append("Chatbot: L'ID n'existe pas.");
            return;
        }

        ui->chatHistory->append("Chatbot: Analyse de la performance du joueur en cours...");
        QSqlQueryModel* trendModel = joueur.getPerformanceTrends(id, 5);
        if (trendModel->rowCount() == 0) {
            ui->chatHistory->append("Chatbot: Aucune donnée de match pour ce joueur.");
            delete trendModel;
            return;
        }

        QSqlQueryModel* impactModel = joueur.getMatchImpactScores(id);
        if (impactModel->rowCount() == 0) {
            ui->chatHistory->append("Chatbot: Aucune donnée d'impact pour ce joueur.");
            delete trendModel;
            delete impactModel;
            return;
        }

        QTableWidget *impactTable = new QTableWidget();
        QStringList impactHeaders;
        impactHeaders << "ID Match" << "Date" << "Équipe 1" << "Équipe 2" << "Buts" << "Assists" << "Résultat" << "Score d'Impact";
        impactTable->setRowCount(impactModel->rowCount());
        impactTable->setColumnCount(impactHeaders.size());
        impactTable->setHorizontalHeaderLabels(impactHeaders);

        for (int row = 0; row < impactModel->rowCount(); ++row) {
            QTableWidgetItem *idMatchItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 0)).toString());
            QTableWidgetItem *dateItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 1)).toString());
            QTableWidgetItem *equip1Item = new QTableWidgetItem(impactModel->data(impactModel->index(row, 2)).toString());
            QTableWidgetItem *equip2Item = new QTableWidgetItem(impactModel->data(impactModel->index(row, 3)).toString());
            QTableWidgetItem *butsItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 4)).toString());
            QTableWidgetItem *assistsItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 5)).toString());
            QTableWidgetItem *resultatItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 9)).toString());
            QTableWidgetItem *impactScoreItem = new QTableWidgetItem(impactModel->data(impactModel->index(row, 10)).toString());

            impactTable->setItem(row, 0, idMatchItem);
            impactTable->setItem(row, 1, dateItem);
            impactTable->setItem(row, 2, equip1Item);
            impactTable->setItem(row, 3, equip2Item);
            impactTable->setItem(row, 4, butsItem);
            impactTable->setItem(row, 5, assistsItem);
            impactTable->setItem(row, 6, resultatItem);
            impactTable->setItem(row, 7, impactScoreItem);
        }

        QBarSeries *series = new QBarSeries();
        QBarSet *goalsSet = new QBarSet("Buts");
        QBarSet *assistsSet = new QBarSet("Assists");
        QStringList categories;

        for (int row = 0; row < trendModel->rowCount(); ++row) {
            int goals = trendModel->data(trendModel->index(row, 2)).toInt();
            int assists = trendModel->data(trendModel->index(row, 3)).toInt();
            QString date = trendModel->data(trendModel->index(row, 1)).toString();

            *goalsSet << goals;
            *assistsSet << assists;
            categories << date;
        }

        series->append(goalsSet);
        series->append(assistsSet);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(QString("Tendances de performance du joueur %1 (derniers 5 matchs)").arg(id));
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setTitleText("Matchs (Date)");
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Valeur");
        axisY->setLabelFormat("%i");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QMainWindow *performanceWindow = new QMainWindow();
        QWidget *centralWidget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        layout->addWidget(new QLabel(QString("Tendances de performance du joueur %1 :").arg(id)));
        layout->addWidget(chartView);
        layout->addWidget(new QLabel("Scores d'impact par match :"));
        layout->addWidget(impactTable);

        performanceWindow->setCentralWidget(centralWidget);
        performanceWindow->resize(800, 600);
        performanceWindow->setWindowTitle("Analyse de Performance des Joueurs");
        performanceWindow->show();

        delete trendModel;
        delete impactModel;
    }
    else {
        ui->chatHistory->append("Chatbot: Commande non reconnue. Voici les commandes disponibles:\n"
                                "- add player [id] [nom] [prenom] [ddn] [num] [equipe]\n"
                                "- delete player [id]\n"
                                "- modify player [id] [num] [equipe]\n"
                                "- show players\n"
                                "- sort by [nom/prenom/id/numero]\n"
                                "- analyze player [id]\n"
                                "- help");
    }
}

void MainWindow::on_joueursButton_clicked()
{
}

void MainWindow::on_equipeButton_clicked()
{
}

void MainWindow::on_addButton_2_clicked()
{
    QString nom = ui->nom_2->text().trimmed();
    QString prenom = ui->prenom_2->text().trimmed();
    QDate dateNaiss = ui->date_2->date();
    QString salaireStr = ui->salaire_2->text().trimmed();
    QString numTel = ui->numTel_2->text().trimmed();
    QString poste = ui->poste_2->currentText();
    QString sexe;
    if (ui->homme_2->isChecked()) sexe = "H";
    else if (ui->femme_2->isChecked()) sexe = "F";
    QString adresse = ui->adresse ? ui->adresse->text().trimmed() : QString();
    QString mdp = ui->mdp ? ui->mdp->text() : QString();

    if (nom.isEmpty() || prenom.isEmpty() || salaireStr.isEmpty() || numTel.isEmpty() || sexe.isEmpty() || (ui->adresse && adresse.isEmpty())) {
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
    emp.setStatut("Actif");

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

    if (emp.modifier(id_to_update)) {
        QMessageBox::information(this, "Succès", "Employé mis à jour avec succès!");
        refreshEmployeeTableView();
    } else {
        QMessageBox::critical(this, "Erreur Base de Données", "Échec de la mise à jour de l'employé.");
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    const int afficherEmployeTabIndex = 1;
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
        return;
    }

    Employe emp = Employe::chercher(id);
    if (emp.getIdEmp() != -1) {
        ui->idd_3->setText(QString::number(emp.getIdEmp()));
        ui->nom_3->setText(emp.getNom());
        ui->prenom_3->setText(emp.getPrenom());
        ui->date_3->setDate(emp.getDateNaissEmp());
        ui->salaire_3->setText(QString::number(emp.getSalaire(), 'f', 2));
        ui->niv_3->clear();
        ui->poste_3->setText(emp.getPoste());
        ui->numTel_3->setText(emp.getNumTelEmp());
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
    pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 20));

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

void MainWindow::on_tab1_2_itemClicked(QTableWidgetItem *item)
{
    if (!item) return;

    int row = item->row();
    QTableWidgetItem* idItem = ui->tab1_2->item(row, 0);  // Assuming ID is in first column

    if(idItem) {
        QString idStr = idItem->text();
        int modifyTabIndex = -1;
        for(int i=0; i < ui->tabWidget->count(); ++i) {
            if(ui->tabWidget->tabText(i).contains("modifier employe", Qt::CaseInsensitive)) {
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
        mettreAJourStatistiques();
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
        mettreAJourStatistiques();
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
        mettreAJourStatistiques();
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
    writer.setPageOrientation(QPageLayout::Landscape);
    writer.setResolution(300);

    QPainter painter(&writer);

    int margin = 100;
    int startX = margin;
    int startY = margin + 200;
    int rowHeight = 40 * 3.5;
    int colWidth = 150 * 3.5;

    QFont font("Times", 16);
    painter.setFont(font);

    QPixmap logo(":/logo.png");
    if (!logo.isNull()) {
        painter.drawPixmap(startX, margin, 200, 200, logo);
    }

    painter.drawText(startX + 220, margin + 100, "Liste des Équipes");

    int x = startX;
    int y = startY;

    QStringList headers = {"ID_EQ", "NB_JR", "NOM_EQ", "PAYE_Q", "RANG_EQ", "ENTRAINEUR"};
    painter.setBrush(QColor(200, 200, 255));
    painter.setPen(Qt::black);

    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
        painter.drawText(x + col * colWidth + 20, y + rowHeight / 2, headers[col]);
    }

    y += rowHeight;

    int rowCount = ui->tableWidget_equipe->rowCount();
    int colCount = ui->tableWidget_equipe->columnCount();
    int currentPage = 1;

    for (int row = 0; row < rowCount; ++row) {
        if (y + rowHeight > writer.height() - margin) {
            writer.newPage();
            y = startY;

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

            if (col == 0) {
                painter.setBrush(QColor(255, 255, 200));
            } else {
                painter.setBrush(Qt::NoBrush);
            }

            painter.setPen(Qt::black);
            painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
            painter.drawText(x + col * colWidth + 20, y + rowHeight / 2, text);
        }
        y += rowHeight;
    }

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

void MainWindow::afficherPourcentageToutesEquipes()
{
    QSqlQuery queryEquipes("SELECT ID_EQ, NOM_EQ FROM EQUIPE");

    ui->tableWidget_pourcentageTous->clearContents();
    ui->tableWidget_pourcentageTous->setRowCount(0);
    ui->tableWidget_pourcentageTous->setColumnCount(4);
    ui->tableWidget_pourcentageTous->setHorizontalHeaderLabels({"Équipe", "Victoire probable (%)", "Défaite probable (%)", "Nul probable (%)"});

    int row = 0;
    while (queryEquipes.next()) {
        int idEquipe = queryEquipes.value("ID_EQ").toInt();
        QString nomEquipe = queryEquipes.value("NOM_EQ").toString();

        QSqlQuery queryMatchs;
        queryMatchs.prepare(R"(
            SELECT *
            FROM (
                SELECT ID_EQ1, ID_EQ2, SCORE_EQ1, SCORE_EQ2
                FROM MATCH
                WHERE ID_EQ1 = :id OR ID_EQ2 = :id
                ORDER BY DATE_M DESC
            )
            WHERE ROWNUM <= 5
        )");
        queryMatchs.bindValue(":id", idEquipe);
        queryMatchs.exec();

        int victoires = 0, defaites = 0, nuls = 0, total = 0;

        while (queryMatchs.next()) {
            int id1 = queryMatchs.value("ID_EQ1").toInt();
            int id2 = queryMatchs.value("ID_EQ2").toInt();
            int s1 = queryMatchs.value("SCORE_EQ1").toInt();
            int s2 = queryMatchs.value("SCORE_EQ2").toInt();
            total++;

            if (id1 == idEquipe) {
                if (s1 > s2) victoires++;
                else if (s1 < s2) defaites++;
                else nuls++;
            } else {
                if (s2 > s1) victoires++;
                else if (s2 < s1) defaites++;
                else nuls++;
            }
        }

        double probaVictoire = (total > 0) ? (victoires * 100.0 / total) : 0.0;
        double probaDefaite  = (total > 0) ? (defaites * 100.0 / total) : 0.0;
        double probaNul      = (total > 0) ? (nuls * 100.0 / total) : 0.0;

        ui->tableWidget_pourcentageTous->insertRow(row);
        ui->tableWidget_pourcentageTous->setItem(row, 0, new QTableWidgetItem(nomEquipe));
        ui->tableWidget_pourcentageTous->setItem(row, 1, new QTableWidgetItem(QString::number(probaVictoire, 'f', 2) + " %"));
        ui->tableWidget_pourcentageTous->setItem(row, 2, new QTableWidgetItem(QString::number(probaDefaite, 'f', 2) + " %"));
        ui->tableWidget_pourcentageTous->setItem(row, 3, new QTableWidgetItem(QString::number(probaNul, 'f', 2) + " %"));
        row++;
    }

    ui->tableWidget_pourcentageTous->resizeColumnsToContents();
}
void MainWindow::displayPosteStats()
{
    qDebug() << "--- MainWindow::displayPosteStats (for QWidget) called ---";
    if (!ui->statsDisplayWidget) { // Make sure this is the objectName from your .ui file
        qWarning() << "statsDisplayWidget is not available in displayPosteStats!";
        return;
    }

    QLayout *layout = ui->statsDisplayWidget->layout();
    if (!layout) { // Ensure a layout exists
        qWarning() << "statsDisplayWidget has no layout! Cannot add statistics. Creating one.";
        // If no layout, create a default QVBoxLayout. Best to set it in Designer.
        layout = new QVBoxLayout(ui->statsDisplayWidget);
        ui->statsDisplayWidget->setLayout(layout);
    }

    // Clear previous content from the QWidget's layout
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    QMap<QString, QPair<int, double>> posteStats = Employe::calculerStatistiquesPoste();

    if (posteStats.isEmpty()) {
        qDebug() << "No poste statistics data returned to display.";
        QLabel *noDataLabel = new QLabel("Aucune donnée statistique disponible pour les postes.");
        noDataLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(noDataLabel);
        return;
    }

    qDebug() << "Populating statsDisplayWidget with" << posteStats.size() << "entries.";

    QLabel *titleLabel = new QLabel("<b>Statistiques par Poste:</b>");
    titleLabel->setAlignment(Qt::AlignHCenter);
    titleLabel->setStyleSheet("font-size: 12pt; margin-bottom: 10px;"); // Example styling
    layout->addWidget(titleLabel);

    QMapIterator<QString, QPair<int, double>> i(posteStats);
    while (i.hasNext()) {
        i.next();
        QString poste = i.key();
        int count = i.value().first;
        double percentage = i.value().second;

        QLabel *statLabel = new QLabel(
            QString("<b>%1:</b> %2 employé(s)  (<i>%3%</i>)")
                .arg(poste)
                .arg(count)
                .arg(QString::number(percentage, 'f', 1))
            );
        statLabel->setStyleSheet("font-size: 10pt; padding: 2px;");
        layout->addWidget(statLabel);
    }

    if (qobject_cast<QVBoxLayout*>(layout)) {
        layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    }
    qDebug() << "Finished populating statsDisplayWidget.";
}



void MainWindow::on_pushButton_pourcentageTous_clicked()
{
    afficherPourcentageToutesEquipes();
}
