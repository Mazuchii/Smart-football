/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QTextEdit *textEdit_9;
    QTextEdit *textEdit_10;
    QTextEdit *textEdit_11;
    QTextEdit *textEdit_12;
    QDateEdit *date_2;
    QTextEdit *textEdit_13;
    QTextEdit *textEdit_14;
    QTextEdit *textEdit_15;
    QTextEdit *textEdit_16;
    QTextBrowser *textBrowser_3;
    QRadioButton *homme_2;
    QRadioButton *femme_2;
    QComboBox *poste_2;
    QPushButton *addButton_2;
    QLineEdit *nom_2;
    QLineEdit *prenom_2;
    QLineEdit *salaire_2;
    QLineEdit *niveaux_dexp_2;
    QLineEdit *numTel_2;
    QWidget *tab_7;
    QTableWidget *tab1_2;
    QPushButton *PDF;
    QLineEdit *recherche;
    QPushButton *btrecherche;
    QWidget *tab_8;
    QPushButton *deleteButton_2;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_7;
    QLineEdit *idd_2;
    QWidget *tab_9;
    QTextEdit *textEdit_18;
    QTextEdit *textEdit_25;
    QTextEdit *textEdit_26;
    QDateEdit *date_3;
    QTextEdit *textEdit_27;
    QTextEdit *textEdit_28;
    QTextBrowser *textBrowser_8;
    QTextEdit *textEdit_29;
    QTextEdit *textEdit_30;
    QPushButton *editButton_2;
    QLineEdit *idd_3;
    QLineEdit *nom_3;
    QLineEdit *prenom_3;
    QLineEdit *salaire_3;
    QLineEdit *niv_3;
    QLineEdit *poste_3;
    QLineEdit *numTel_3;
    QTextEdit *textEdit_31;
    QWidget *tab_10;
    QWidget *statsChartContainerWidget;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1153, 710);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(430, 50, 101, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 207, 104);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 10, 1001, 121));
        label_5->setStyleSheet(QString::fromUtf8(" background-color :white;\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(560, 50, 101, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 207, 104);"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(100, 130, 941, 531));
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        textEdit_9 = new QTextEdit(tab_6);
        textEdit_9->setObjectName("textEdit_9");
        textEdit_9->setGeometry(QRect(160, 80, 201, 41));
        textEdit_10 = new QTextEdit(tab_6);
        textEdit_10->setObjectName("textEdit_10");
        textEdit_10->setGeometry(QRect(160, 230, 201, 41));
        textEdit_11 = new QTextEdit(tab_6);
        textEdit_11->setObjectName("textEdit_11");
        textEdit_11->setGeometry(QRect(160, 280, 201, 41));
        textEdit_12 = new QTextEdit(tab_6);
        textEdit_12->setObjectName("textEdit_12");
        textEdit_12->setGeometry(QRect(160, 30, 201, 41));
        date_2 = new QDateEdit(tab_6);
        date_2->setObjectName("date_2");
        date_2->setGeometry(QRect(440, 130, 201, 41));
        textEdit_13 = new QTextEdit(tab_6);
        textEdit_13->setObjectName("textEdit_13");
        textEdit_13->setGeometry(QRect(160, 330, 201, 41));
        textEdit_14 = new QTextEdit(tab_6);
        textEdit_14->setObjectName("textEdit_14");
        textEdit_14->setGeometry(QRect(160, 130, 201, 41));
        textEdit_15 = new QTextEdit(tab_6);
        textEdit_15->setObjectName("textEdit_15");
        textEdit_15->setGeometry(QRect(160, 180, 201, 41));
        textEdit_16 = new QTextEdit(tab_6);
        textEdit_16->setObjectName("textEdit_16");
        textEdit_16->setGeometry(QRect(160, 380, 201, 41));
        textBrowser_3 = new QTextBrowser(tab_6);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(40, 20, 691, 421));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"background-color: rgb(10, 48, 13);"));
        homme_2 = new QRadioButton(tab_6);
        homme_2->setObjectName("homme_2");
        homme_2->setGeometry(QRect(450, 240, 91, 22));
        femme_2 = new QRadioButton(tab_6);
        femme_2->setObjectName("femme_2");
        femme_2->setGeometry(QRect(550, 240, 91, 22));
        poste_2 = new QComboBox(tab_6);
        poste_2->addItem(QString());
        poste_2->addItem(QString());
        poste_2->addItem(QString());
        poste_2->addItem(QString());
        poste_2->setObjectName("poste_2");
        poste_2->setGeometry(QRect(440, 380, 201, 41));
        poste_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        addButton_2 = new QPushButton(tab_6);
        addButton_2->setObjectName("addButton_2");
        addButton_2->setGeometry(QRect(790, 210, 80, 24));
        nom_2 = new QLineEdit(tab_6);
        nom_2->setObjectName("nom_2");
        nom_2->setGeometry(QRect(440, 30, 221, 41));
        nom_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        prenom_2 = new QLineEdit(tab_6);
        prenom_2->setObjectName("prenom_2");
        prenom_2->setGeometry(QRect(440, 80, 221, 41));
        prenom_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        salaire_2 = new QLineEdit(tab_6);
        salaire_2->setObjectName("salaire_2");
        salaire_2->setGeometry(QRect(440, 180, 221, 41));
        salaire_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        niveaux_dexp_2 = new QLineEdit(tab_6);
        niveaux_dexp_2->setObjectName("niveaux_dexp_2");
        niveaux_dexp_2->setGeometry(QRect(440, 280, 221, 41));
        niveaux_dexp_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        numTel_2 = new QLineEdit(tab_6);
        numTel_2->setObjectName("numTel_2");
        numTel_2->setGeometry(QRect(440, 330, 221, 41));
        numTel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_6, QString());
        textBrowser_3->raise();
        textEdit_9->raise();
        textEdit_10->raise();
        textEdit_11->raise();
        textEdit_12->raise();
        date_2->raise();
        textEdit_13->raise();
        textEdit_14->raise();
        textEdit_15->raise();
        textEdit_16->raise();
        homme_2->raise();
        femme_2->raise();
        poste_2->raise();
        addButton_2->raise();
        nom_2->raise();
        prenom_2->raise();
        salaire_2->raise();
        niveaux_dexp_2->raise();
        numTel_2->raise();
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tab1_2 = new QTableWidget(tab_7);
        if (tab1_2->columnCount() < 7)
            tab1_2->setColumnCount(7);
        QFont font;
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tab1_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tab1_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tab1_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tab1_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tab1_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tab1_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tab1_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tab1_2->setObjectName("tab1_2");
        tab1_2->setGeometry(QRect(10, 10, 920, 441));
        tab1_2->setMinimumSize(QSize(0, 381));
        tab1_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        tab1_2->horizontalHeader()->setDefaultSectionSize(130);
        PDF = new QPushButton(tab_7);
        PDF->setObjectName("PDF");
        PDF->setGeometry(QRect(410, 460, 80, 24));
        recherche = new QLineEdit(tab_7);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(500, 450, 201, 31));
        recherche->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        btrecherche = new QPushButton(tab_7);
        btrecherche->setObjectName("btrecherche");
        btrecherche->setGeometry(QRect(730, 460, 80, 24));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        deleteButton_2 = new QPushButton(tab_8);
        deleteButton_2->setObjectName("deleteButton_2");
        deleteButton_2->setGeometry(QRect(350, 330, 241, 71));
        deleteButton_2->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe MDL2 Assets\";"));
        textBrowser_4 = new QTextBrowser(tab_8);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(290, 40, 391, 61));
        textBrowser_7 = new QTextBrowser(tab_8);
        textBrowser_7->setObjectName("textBrowser_7");
        textBrowser_7->setGeometry(QRect(60, 160, 231, 71));
        idd_2 = new QLineEdit(tab_8);
        idd_2->setObjectName("idd_2");
        idd_2->setGeometry(QRect(370, 170, 221, 41));
        idd_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        textEdit_18 = new QTextEdit(tab_9);
        textEdit_18->setObjectName("textEdit_18");
        textEdit_18->setGeometry(QRect(170, 140, 201, 41));
        textEdit_25 = new QTextEdit(tab_9);
        textEdit_25->setObjectName("textEdit_25");
        textEdit_25->setGeometry(QRect(170, 290, 201, 41));
        textEdit_26 = new QTextEdit(tab_9);
        textEdit_26->setObjectName("textEdit_26");
        textEdit_26->setGeometry(QRect(170, 90, 201, 41));
        date_3 = new QDateEdit(tab_9);
        date_3->setObjectName("date_3");
        date_3->setGeometry(QRect(440, 190, 201, 41));
        textEdit_27 = new QTextEdit(tab_9);
        textEdit_27->setObjectName("textEdit_27");
        textEdit_27->setGeometry(QRect(170, 390, 201, 41));
        textEdit_28 = new QTextEdit(tab_9);
        textEdit_28->setObjectName("textEdit_28");
        textEdit_28->setGeometry(QRect(170, 190, 201, 41));
        textBrowser_8 = new QTextBrowser(tab_9);
        textBrowser_8->setObjectName("textBrowser_8");
        textBrowser_8->setGeometry(QRect(50, 20, 831, 431));
        textBrowser_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"background-color: rgb(10, 48, 13);"));
        textEdit_29 = new QTextEdit(tab_9);
        textEdit_29->setObjectName("textEdit_29");
        textEdit_29->setGeometry(QRect(170, 240, 201, 41));
        textEdit_30 = new QTextEdit(tab_9);
        textEdit_30->setObjectName("textEdit_30");
        textEdit_30->setGeometry(QRect(170, 340, 201, 41));
        editButton_2 = new QPushButton(tab_9);
        editButton_2->setObjectName("editButton_2");
        editButton_2->setGeometry(QRect(710, 180, 141, 81));
        editButton_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";\n"
"color: rgb(255, 170, 0);"));
        idd_3 = new QLineEdit(tab_9);
        idd_3->setObjectName("idd_3");
        idd_3->setGeometry(QRect(430, 30, 221, 41));
        idd_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        nom_3 = new QLineEdit(tab_9);
        nom_3->setObjectName("nom_3");
        nom_3->setGeometry(QRect(430, 90, 221, 41));
        nom_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        prenom_3 = new QLineEdit(tab_9);
        prenom_3->setObjectName("prenom_3");
        prenom_3->setGeometry(QRect(430, 140, 221, 41));
        prenom_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        salaire_3 = new QLineEdit(tab_9);
        salaire_3->setObjectName("salaire_3");
        salaire_3->setGeometry(QRect(430, 240, 221, 41));
        salaire_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        niv_3 = new QLineEdit(tab_9);
        niv_3->setObjectName("niv_3");
        niv_3->setGeometry(QRect(430, 290, 221, 41));
        niv_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        poste_3 = new QLineEdit(tab_9);
        poste_3->setObjectName("poste_3");
        poste_3->setGeometry(QRect(430, 340, 221, 41));
        poste_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        numTel_3 = new QLineEdit(tab_9);
        numTel_3->setObjectName("numTel_3");
        numTel_3->setGeometry(QRect(430, 390, 221, 41));
        numTel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        textEdit_31 = new QTextEdit(tab_9);
        textEdit_31->setObjectName("textEdit_31");
        textEdit_31->setGeometry(QRect(170, 30, 201, 51));
        tabWidget->addTab(tab_9, QString());
        textBrowser_8->raise();
        textEdit_18->raise();
        textEdit_25->raise();
        textEdit_26->raise();
        date_3->raise();
        textEdit_27->raise();
        textEdit_28->raise();
        textEdit_29->raise();
        textEdit_30->raise();
        editButton_2->raise();
        idd_3->raise();
        nom_3->raise();
        prenom_3->raise();
        salaire_3->raise();
        niv_3->raise();
        poste_3->raise();
        numTel_3->raise();
        textEdit_31->raise();
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        statsChartContainerWidget = new QWidget(tab_10);
        statsChartContainerWidget->setObjectName("statsChartContainerWidget");
        statsChartContainerWidget->setGeometry(QRect(120, 50, 551, 331));
        tabWidget->addTab(tab_10, QString());
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(830, 50, 101, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 207, 104);"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(120, 30, 141, 81));
        label_9->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/logo_app.png);"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo_app.png")));
        label_9->setScaledContents(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 50, 111, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 207, 104);"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(690, 50, 111, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 207, 104);"));
        MainWindow->setCentralWidget(centralWidget);
        label_5->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        tabWidget->raise();
        pushButton_5->raise();
        label_9->raise();
        pushButton->raise();
        pushButton_4->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1153, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        pushButton_2->setText(QString());
        label_5->setText(QString());
        pushButton_3->setText(QString());
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        textEdit_9->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Prenom</span></p></body></html>", nullptr));
        textEdit_10->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Sexe</span></p></body></html>", nullptr));
        textEdit_11->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; font-style:italic; text-decoration: underline;\">Niveaux_d'experience</span></p></body></html>", nullptr));
        textEdit_12->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Nom</span></p></body></html>", nullptr));
        textEdit_13->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Num_telephone</span></p></body></html>", nullptr));
        textEdit_14->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Date_de_naissence</span></p></body></html>", nullptr));
        textEdit_15->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Salaire</span></p></body></html>", nullptr));
        textEdit_16->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">Poste</span></p></body></html>", nullptr));
        homme_2->setText(QCoreApplication::translate("MainWindow", "homme", nullptr));
        femme_2->setText(QCoreApplication::translate("MainWindow", "femme", nullptr));
        poste_2->setItemText(0, QCoreApplication::translate("MainWindow", "Direction g\303\251nerale", nullptr));
        poste_2->setItemText(1, QCoreApplication::translate("MainWindow", "Direction de l'arbitrage", nullptr));
        poste_2->setItemText(2, QCoreApplication::translate("MainWindow", "Direction technique nationale", nullptr));
        poste_2->setItemText(3, QCoreApplication::translate("MainWindow", "Direction communication", nullptr));

        addButton_2->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "ajouter employe", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date_de_naissence", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab1_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "num_telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab1_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Niveaux_d'experience", nullptr));
        PDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        btrecherche->setText(QCoreApplication::translate("MainWindow", "recherche", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "afficher employe", nullptr));
        deleteButton_2->setText(QCoreApplication::translate("MainWindow", "Delete ", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:700; font-style:italic; text-decoration: underline;\">Delete employee</span></p></body></html>", nullptr));
        textBrowser_7->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700; text-decoration: underline;\">Id_employe :</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("MainWindow", "delete employe", nullptr));
        textEdit_18->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">prenom</span></p></body></html>", nullptr));
        textEdit_25->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">niveaux_d'experience</span></p></body></html>", nullptr));
        textEdit_26->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">nom</span></p></body></html>", nullptr));
        textEdit_27->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">num_telephone</span></p></body></html>", nullptr));
        textEdit_28->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">date_de_naissence</span></p></body></html>", nullptr));
        textEdit_29->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">salaire</span></p></body></html>", nullptr));
        textEdit_30->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">poste</span></p></body></html>", nullptr));
        editButton_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        textEdit_31->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\">id</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; font-weight:700; font-style:italic; text-decoration: underline;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("MainWindow", "modifier employe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("MainWindow", "statistique", nullptr));
        pushButton_5->setText(QString());
        label_9->setText(QString());
        pushButton->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
