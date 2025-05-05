
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMapIterator>
#include <QSqlRecord>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout> // For placing chart in widget
#include <QMapIterator> // To iterate the stats map
#include "employe.h"    // Include your Employe class header
#include <QDebug>       // For debugging output

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentEmployee(nullptr)
    , m_model(nullptr)
{
    ui->setupUi(this);

    // Initialize database
    if (!Employee::initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to initialize database!");
    }

    // Setup UI
    setupTable();
    clearForm();
 afficherStatistiquesSexeChart();
    // Connect signals and slots
    connect(ui->addButton_2, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(ui->editButton_2, &QPushButton::clicked, this, &MainWindow::onEditButtonClicked);
    connect(ui->deleteButton_2, &QPushButton::clicked, this, &MainWindow::onDeleteButtonClicked);
    connect(ui->tab1_2, &QTableView::clicked, this, &MainWindow::onTableClicked);
}

MainWindow::~MainWindow()
{
    delete m_currentEmployee;
    delete m_model;
    delete ui;
}



void MainWindow::setupTable()
{
    // Clear existing content
    ui->tab1_2->setRowCount(0);

    // Get data
    QSqlQuery query("SELECT * FROM employees");
    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError();
        return;
    }

    // Set headers
    QStringList headers;
    headers << "ID" << "Nom" << "Prénom" << "Téléphone" << "Date Naissance"
            << "Poste" << "Salaire" << "Sexe" << "Niveau Expérience";
    ui->tab1_2->setColumnCount(headers.size());
    ui->tab1_2->setHorizontalHeaderLabels(headers);

    // Populate data
    int row = 0;
    while (query.next()) {
        ui->tab1_2->insertRow(row);
        for (int col = 0; col < headers.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(
                query.value(col).toString());
            ui->tab1_2->setItem(row, col, item);
        }
        row++;
    }

    // Adjust columns
    ui->tab1_2->resizeColumnsToContents();
}

void MainWindow::clearForm()
{
    ui->idd_2->clear();
    ui->nom_2->clear();
    ui->prenom_2->clear();
    ui->numTel_2->clear();
    ui->date_2->setDate(QDate::currentDate());
    ui->poste_2->setCurrentIndex(0);
    ui->salaire_2->clear();
    ui->niveaux_dexp_2->clear();
    ui->homme_2->setChecked(false);
    ui->femme_2->setChecked(false);

    delete m_currentEmployee;
    m_currentEmployee = nullptr;
}

void MainWindow::loadEmployeeData(int employeeId)
{
    // In a real application, you would fetch this from the database
    // For simplicity, we'll just create a temporary employee
    delete m_currentEmployee;
    m_currentEmployee = new Employee();
    m_currentEmployee->setId(employeeId);
}

void MainWindow::onAddButtonClicked()
{
    // Validate input
    if (ui->nom_2->text().isEmpty() || ui->prenom_2->text().isEmpty() ||
        ui->numTel_2->text().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Please fill in all required fields.");
        return;
    }

    if (!ui->homme_2->isChecked() && !ui->femme_2->isChecked()) {
        QMessageBox::warning(this, "Validation", "Please select a gender.");
        return;
    }

    // Create new employee
    Employee newEmployee;
    newEmployee.setNom(ui->nom_2->text());
    newEmployee.setPrenom(ui->prenom_2->text());
    newEmployee.setNumTel(ui->numTel_2->text());
    newEmployee.setDateNaissance(ui->date_2->date());
    newEmployee.setPoste(ui->poste_2->currentText());
    newEmployee.setSalaire(ui->salaire_2->text().toDouble());
    newEmployee.setSexe(ui->homme_2->isChecked() ? "homme" : "femme");
    newEmployee.setNiveauExp(ui->niveaux_dexp_2->text());

    if (newEmployee.create()) {
        QMessageBox::information(this, "Success", "Employee added successfully!");
        clearForm();
        refreshTable();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add employee: " + newEmployee.getLastError());
    }
}

void MainWindow::onEditButtonClicked()
{
    if (!m_currentEmployee) {
        QMessageBox::warning(this, "Warning", "No employee selected.");
        return;
    }

    // Update employee data
    m_currentEmployee->setNom(ui->nom_3->text());
    m_currentEmployee->setPrenom(ui->prenom_3->text());
    m_currentEmployee->setNumTel(ui->numTel_3->text());
    m_currentEmployee->setDateNaissance(ui->date_3->date());
    m_currentEmployee->setPoste(ui->poste_3->text());
    m_currentEmployee->setSalaire(ui->salaire_3->text().toDouble());
        m_currentEmployee->setNiveauExp(ui->niv_3->text());

    if (m_currentEmployee->update()) {
        QMessageBox::information(this, "Success", "Employee updated successfully!");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update employee: " + m_currentEmployee->getLastError());
    }
}

void MainWindow::onDeleteButtonClicked()
{

    int id = ui->idd_2->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }


    Employee emp;

    if (QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cet employé ?") == QMessageBox::Yes) {
        if (emp.remove(id)) {
            QMessageBox::information(this, "Succès", "Employé supprimé.");
            clearForm();
            setupTable();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
    }


void MainWindow::onTableClicked(const QModelIndex &index)
{
    int row = index.row();
    int employeeId = m_model->data(m_model->index(row, 0)).toInt();

    loadEmployeeData(employeeId);

    // Update form with selected employee's data
    ui->idd_2->setText(QString::number(employeeId));
    ui->nom_2->setText(m_model->data(m_model->index(row, 1)).toString());
    ui->prenom_2->setText(m_model->data(m_model->index(row, 2)).toString());
    ui->numTel_2->setText(m_model->data(m_model->index(row, 3)).toString());

    QDate birthDate = QDate::fromString(m_model->data(m_model->index(row, 4)).toString(), "yyyy-MM-dd");
    ui->date_2->setDate(birthDate);

    ui->poste_2->setCurrentText(m_model->data(m_model->index(row, 5)).toString());
    ui->salaire_2->setText(QString::number(m_model->data(m_model->index(row, 6)).toDouble()));

    QString gender = m_model->data(m_model->index(row, 7)).toString();
    ui->homme_2->setChecked(gender == "homme");
    ui->femme_2->setChecked(gender == "femme");

    ui->niveaux_dexp_2->setText(m_model->data(m_model->index(row, 8)).toString());
}

void MainWindow::refreshTable()
{
    setupTable();
}

void MainWindow::on_PDF_clicked()
{
    qDebug() << "PDF button clicked";

    // Ask user where to save the PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    QPrinter printer(QPrinter::PrinterMode::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html;

    html += "<table border='1' cellspacing='0' cellpadding='3'>";

    // Headers
    html += "<tr>";
    for (int col = 0; col < ui->tab1_2->columnCount(); ++col) {
        html += "<th>" + ui->tab1_2->horizontalHeaderItem(col)->text() + "</th>";
    }
    html += "</tr>";

    // Data
    for (int row = 0; row < ui->tab1_2->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < ui->tab1_2->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tab1_2->item(row, col);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

    qDebug() << "PDF saved to:" << fileName;
}

// In mainwindow.cpp - inside your statistics button slot

















// In mainwindow.cpp
void MainWindow::afficherStatistiquesSexeChart()
{
    qDebug() << "--- Generating Gender Statistics Chart ---";

    // --- 1. Get the Statistics Data ---
    // **** Make sure Employe::calculerStatistiquesSexe() is correctly implemented ****
    // **** and returns QMap<QString, double> where key=Gender, value=Percentage ****
    QMap<QString, double> genderStats = Employee::calculerStatistiquesSexe(); // Use correct class name 'Employe'

    // --- Check if container widget exists ---
    // *** VITAL: Replace 'statsChartContainerWidget' with the actual objectName ***
    // *** of the QWidget you added in Qt Designer to hold this chart! ***
    QWidget* chartContainer = ui->statsChartContainerWidget; // Use a pointer for easier access
    if (!chartContainer) {
        qDebug() << "FATAL ERROR: UI does not contain a widget named 'statsChartContainerWidget'. Cannot display chart.";
        QMessageBox::critical(this, "UI Error", "Chart container widget ('statsChartContainerWidget') not found in UI design. Please add a QWidget with this objectName.");
        return; // Exit the function if the container is missing
    }
    qDebug() << "Container widget 'statsChartContainerWidget' found.";


    // --- Clear previous content from the container widget's layout ---
    QLayout *oldLayout = chartContainer->layout();
    if (oldLayout != nullptr)
    {
        qDebug() << "Clearing previous layout from chart container.";
        QLayoutItem* item;
        // Safe way to delete all items and their widgets from a layout
        while ((item = oldLayout->takeAt(0)) != nullptr)
        {
            if (item->widget()) {
                item->widget()->setParent(nullptr); // Prevent potential double deletion issues
                delete item->widget(); // Delete the widget (e.g., previous QChartView or QLabel)
            }
            delete item; // Delete the layout item wrapper
        }
        delete oldLayout; // Delete the old layout itself
    } else {
        qDebug() << "No previous layout found in chart container.";
    }


    // --- Handle No Data ---
    if (genderStats.isEmpty()) {
        qDebug() << "WARNING: No gender statistics data returned to generate chart. Displaying 'No Data' message.";
        // Display a message IN the container widget
        QLabel *noDataLabel = new QLabel("Aucune donnée statistique disponible."); // Include QLabel header if needed
        noDataLabel->setAlignment(Qt::AlignCenter);
        noDataLabel->setStyleSheet("font-style: italic; color: gray;"); // Optional styling

        QVBoxLayout *layout = new QVBoxLayout(); // Create a new layout for the message
        layout->addWidget(noDataLabel);
        chartContainer->setLayout(layout); // Set the new layout containing the message
        chartContainer->setVisible(true); // Ensure container is visible
        return; // Exit after displaying the message
    }
    qDebug() << "Gender statistics data received. Size:" << genderStats.size();


    // --- 2. Prepare Data for the Chart ---
    QBarSet *set = new QBarSet("Pourcentage");
    QStringList categories;

    QMapIterator<QString, double> i(genderStats);
    while (i.hasNext()) {
        i.next();
        // Basic validation: Ensure value is reasonable for percentage
        double value = i.value();
        if (value < 0) value = 0; // Don't add negative percentages
        *set << value;
        categories << i.key(); // Use the gender name (e.g., "Homme", "Femme") as category
        qDebug() << "Adding to chart -> Category:" << i.key() << "| Value:" << value;
    }


    // --- 3. Create the Chart Components ---
    QBarSeries *series = new QBarSeries();
    series->append(set);
    // Optional: Add labels to bars
    series->setLabelsVisible(true);
    series->setLabelsFormat("@value{%.1f}%"); // Format label as "65.5%"

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Employés par Sexe (%)");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    // --- 4. Create and Configure Axes ---
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX); // Link series data to this axis

    QValueAxis *axisY = new QValueAxis();
        // Dynamically set range slightly above max value or use 100 if percentages are strict
    double maxValue = 0;
    // *** CORRECTED ITERATION to find max value ***
    for (int k = 0; k < set->count(); ++k) { // Loop using index
        double val = set->at(k); // Get value using at()
        if (val > maxValue) {
            maxValue = val;
        }
    }
    // *********************************************
    axisY->setRange(0, qMax(10.0, maxValue * 1.1)); // Set range 0 to 110% of max value (or at least 10)
    // axisY->setRange(0, 100); // Alternative: Use fixed 0-100 if values are strictly percentages
    axisY->setTitleText("Pourcentage (%)");
    axisY->setLabelFormat("%.1f"); // Format Y-axis labels (no % sign needed if title has it)
    axisY->setTickCount(qMin(6, qMax(3, (int)(maxValue / 20.0) + 2))); // Adjust tick count dynamically (e.g., 3 to 6 ticks)
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY); // Link series data to this axis


    // --- 5. Configure Legend ---
    chart->legend()->setVisible(true); // Show the legend (shows "Pourcentage")
    chart->legend()->setAlignment(Qt::AlignBottom);


    // --- 6. Create Chart View ---
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); // Makes the chart look smoother


    // --- 7. Integrate into the UI Container Widget ---
    QVBoxLayout *layout = new QVBoxLayout(); // Create a new layout
    layout->addWidget(chartView);            // Add the chart view
    layout->setContentsMargins(0, 0, 0, 0); // Remove margins around the chart if desired

    // *** VITAL: Uses the 'chartContainer' pointer defined earlier ***
    chartContainer->setLayout(layout);
    chartContainer->setVisible(true); // Ensure container is visible

    qDebug() << "Chart setup complete and added to UI.";
}







void MainWindow::on_btrecherche_clicked()
{
    QString nameSearch = ui->recherche->text();
    QSqlQuery query;

    // Exact match (case-sensitive)
    QString sql = QString("SELECT * FROM EMPLOYE WHERE NOM = '%1'").arg(nameSearch);
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "SQL Error", query.lastError().text());
        return;
    }

    // Clear previous content
    ui->tab1_2->setRowCount(0);
    ui->tab1_2->setColumnCount(query.record().count());

    // Set headers
    for (int i = 0; i < query.record().count(); ++i) {
        ui->tab1_2->setHorizontalHeaderItem(i, new QTableWidgetItem(query.record().fieldName(i)));
    }

    int row = 0;
    while (query.next()) {
        ui->tab1_2->insertRow(row);
        for (int col = 0; col < query.record().count(); ++col) {
            QString value = query.value(col).toString();
            ui->tab1_2->setItem(row, col, new QTableWidgetItem(value));
        }

        row++;
    }
}
