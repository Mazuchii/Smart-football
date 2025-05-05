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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget_equipe;
    QLabel *label_3;
    QPushButton *pushButton_11;
    QLabel *label;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_8;
    QLineEdit *lineEdit_nbjr;
    QLineEdit *lineEdit_entraineur;
    QPushButton *pushButton_ajouter;
    QLabel *label_6;
    QLabel *label_9;
    QComboBox *comboBox_paye;
    QLineEdit *lineEdit_nom;
    QLabel *label_11;
    QSpinBox *spinBox_rang;
    QLabel *label_7;
    QLabel *label_17;
    QWidget *tab_2;
    QLabel *label_4;
    QLabel *label_18;
    QLineEdit *lineEdit_id_delete;
    QPushButton *pushButton_supprimer;
    QWidget *tab_5;
    QLineEdit *lineEdit_id_modify;
    QLabel *label_31;
    QLabel *label_30;
    QLineEdit *lineEdit_nom_2;
    QLabel *label_33;
    QSpinBox *spinBox_rang_2;
    QLineEdit *lineEdit_entraineur_2;
    QPushButton *pushButton_modifier;
    QLineEdit *lineEdit_nbjr_2;
    QComboBox *comboBox_paye_2;
    QLabel *label_29;
    QLabel *label_32;
    QLabel *label_28;
    QWidget *tab_3;
    QTableWidget *tableMatchs;
    QPushButton *boutonRechercherNom_2;
    QLineEdit *champRechercheNom;
    QWidget *tab_4;
    QTableWidget *tableWidgetEtatEquipes;
    QPushButton *boutonAfficherEtat;
    QLineEdit *rechercheetat;
    QPushButton *pushButton_export_pdf;
    QPushButton *pushButton_trier;
    QPushButton *pushButton_rechercher;
    QLineEdit *lineEdit_recherche_id;
    QLCDNumber *lcdNumber_total;
    QLabel *label_34;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1384, 717);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 48, 13);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget_equipe = new QTableWidget(centralwidget);
        if (tableWidget_equipe->columnCount() < 6)
            tableWidget_equipe->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_equipe->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_equipe->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_equipe->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_equipe->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_equipe->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_equipe->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_equipe->rowCount() < 2)
            tableWidget_equipe->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_equipe->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_equipe->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_equipe->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_equipe->setItem(0, 3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_equipe->setItem(0, 4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_equipe->setItem(0, 5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_equipe->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_equipe->setItem(1, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_equipe->setItem(1, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_equipe->setItem(1, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_equipe->setItem(1, 4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_equipe->setItem(1, 5, __qtablewidgetitem17);
        tableWidget_equipe->setObjectName("tableWidget_equipe");
        tableWidget_equipe->setGeometry(QRect(10, 210, 771, 381));
        tableWidget_equipe->setStyleSheet(QString::fromUtf8("font: 7pt \"Segoe UI\";\n"
"background-color: rgb(188, 188, 188);"));
        tableWidget_equipe->horizontalHeader()->setDefaultSectionSize(128);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 10, 1341, 111));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"background-color: rgb(10, 48, 13);"));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(400, 50, 101, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 241, 121));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/logo_app.png);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo_app.png")));
        label->setScaledContents(true);
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(580, 50, 101, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(750, 50, 101, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(920, 50, 101, 41));
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(1090, 50, 101, 41));
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(790, 110, 591, 541));
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 390, 201, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        lineEdit_nbjr = new QLineEdit(tab);
        lineEdit_nbjr->setObjectName("lineEdit_nbjr");
        lineEdit_nbjr->setGeometry(QRect(240, 320, 113, 28));
        lineEdit_nbjr->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_entraineur = new QLineEdit(tab);
        lineEdit_entraineur->setObjectName("lineEdit_entraineur");
        lineEdit_entraineur->setGeometry(QRect(240, 390, 113, 28));
        lineEdit_entraineur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_ajouter = new QPushButton(tab);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(200, 460, 101, 41));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 130, 181, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 260, 181, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        comboBox_paye = new QComboBox(tab);
        comboBox_paye->setObjectName("comboBox_paye");
        comboBox_paye->setGeometry(QRect(240, 260, 111, 28));
        lineEdit_nom = new QLineEdit(tab);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(240, 130, 113, 28));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(180, 10, 211, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 600 16pt \"Segoe UI\";"));
        spinBox_rang = new QSpinBox(tab);
        spinBox_rang->setObjectName("spinBox_rang");
        spinBox_rang->setGeometry(QRect(240, 190, 111, 29));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 320, 201, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        label_17 = new QLabel(tab);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 200, 141, 20));
        label_17->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, 10, 251, 51));
        label_4->setStyleSheet(QString::fromUtf8("font: 600 15pt \"Segoe UI\";"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 110, 301, 51));
        label_18->setStyleSheet(QString::fromUtf8("font: 600 15pt \"Segoe UI\";"));
        lineEdit_id_delete = new QLineEdit(tab_2);
        lineEdit_id_delete->setObjectName("lineEdit_id_delete");
        lineEdit_id_delete->setGeometry(QRect(320, 120, 113, 28));
        lineEdit_id_delete->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_supprimer = new QPushButton(tab_2);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(220, 290, 101, 41));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        lineEdit_id_modify = new QLineEdit(tab_5);
        lineEdit_id_modify->setObjectName("lineEdit_id_modify");
        lineEdit_id_modify->setGeometry(QRect(260, 70, 113, 28));
        lineEdit_id_modify->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_31 = new QLabel(tab_5);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 60, 251, 41));
        label_31->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 170, 0);"));
        label_30 = new QLabel(tab_5);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(40, 330, 201, 31));
        label_30->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        lineEdit_nom_2 = new QLineEdit(tab_5);
        lineEdit_nom_2->setObjectName("lineEdit_nom_2");
        lineEdit_nom_2->setGeometry(QRect(260, 140, 113, 28));
        lineEdit_nom_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_33 = new QLabel(tab_5);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(30, 210, 141, 20));
        label_33->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        spinBox_rang_2 = new QSpinBox(tab_5);
        spinBox_rang_2->setObjectName("spinBox_rang_2");
        spinBox_rang_2->setGeometry(QRect(260, 200, 111, 29));
        lineEdit_entraineur_2 = new QLineEdit(tab_5);
        lineEdit_entraineur_2->setObjectName("lineEdit_entraineur_2");
        lineEdit_entraineur_2->setGeometry(QRect(260, 400, 113, 28));
        lineEdit_entraineur_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_modifier = new QPushButton(tab_5);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(240, 470, 101, 41));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"background-color: rgb(10, 48, 13);\n"
"color: rgb(255, 255, 0);\n"
"color: rgb(255, 170, 0);"));
        lineEdit_nbjr_2 = new QLineEdit(tab_5);
        lineEdit_nbjr_2->setObjectName("lineEdit_nbjr_2");
        lineEdit_nbjr_2->setGeometry(QRect(260, 330, 113, 28));
        lineEdit_nbjr_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox_paye_2 = new QComboBox(tab_5);
        comboBox_paye_2->addItem(QString());
        comboBox_paye_2->addItem(QString());
        comboBox_paye_2->addItem(QString());
        comboBox_paye_2->setObjectName("comboBox_paye_2");
        comboBox_paye_2->setGeometry(QRect(260, 270, 111, 28));
        label_29 = new QLabel(tab_5);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 270, 181, 31));
        label_29->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        label_32 = new QLabel(tab_5);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(30, 140, 181, 31));
        label_32->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";color: rgb(255, 170, 0);"));
        label_28 = new QLabel(tab_5);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(40, 400, 201, 20));
        label_28->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";"));
        tabWidget->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableMatchs = new QTableWidget(tab_3);
        tableMatchs->setObjectName("tableMatchs");
        tableMatchs->setGeometry(QRect(10, 60, 571, 231));
        tableMatchs->setStyleSheet(QString::fromUtf8("background-color: rgb(168, 168, 168);\n"
"color: rgb(6, 6, 6);"));
        boutonRechercherNom_2 = new QPushButton(tab_3);
        boutonRechercherNom_2->setObjectName("boutonRechercherNom_2");
        boutonRechercherNom_2->setGeometry(QRect(270, 20, 80, 24));
        champRechercheNom = new QLineEdit(tab_3);
        champRechercheNom->setObjectName("champRechercheNom");
        champRechercheNom->setGeometry(QRect(110, 20, 113, 28));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tableWidgetEtatEquipes = new QTableWidget(tab_4);
        tableWidgetEtatEquipes->setObjectName("tableWidgetEtatEquipes");
        tableWidgetEtatEquipes->setGeometry(QRect(20, 60, 541, 291));
        tableWidgetEtatEquipes->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(117, 117, 117);"));
        boutonAfficherEtat = new QPushButton(tab_4);
        boutonAfficherEtat->setObjectName("boutonAfficherEtat");
        boutonAfficherEtat->setGeometry(QRect(270, 400, 83, 29));
        rechercheetat = new QLineEdit(tab_4);
        rechercheetat->setObjectName("rechercheetat");
        rechercheetat->setGeometry(QRect(120, 400, 113, 28));
        rechercheetat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_4, QString());
        pushButton_export_pdf = new QPushButton(centralwidget);
        pushButton_export_pdf->setObjectName("pushButton_export_pdf");
        pushButton_export_pdf->setGeometry(QRect(610, 620, 131, 51));
        pushButton_export_pdf->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        pushButton_trier = new QPushButton(centralwidget);
        pushButton_trier->setObjectName("pushButton_trier");
        pushButton_trier->setGeometry(QRect(90, 620, 131, 51));
        pushButton_trier->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        pushButton_rechercher = new QPushButton(centralwidget);
        pushButton_rechercher->setObjectName("pushButton_rechercher");
        pushButton_rechercher->setGeometry(QRect(210, 160, 101, 21));
        pushButton_rechercher->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        lineEdit_recherche_id = new QLineEdit(centralwidget);
        lineEdit_recherche_id->setObjectName("lineEdit_recherche_id");
        lineEdit_recherche_id->setGeometry(QRect(70, 160, 113, 28));
        lineEdit_recherche_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lcdNumber_total = new QLCDNumber(centralwidget);
        lcdNumber_total->setObjectName("lcdNumber_total");
        lcdNumber_total->setGeometry(QRect(590, 162, 71, 31));
        label_34 = new QLabel(centralwidget);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(460, 160, 121, 31));
        label_34->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 170, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1384, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_equipe->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID \303\250quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_equipe->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nome d'\303\250quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_equipe->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Classement", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_equipe->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Pays de l\303\250quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_equipe->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Nombre des joueurs", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_equipe->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Nom du entra\303\256neur", nullptr));

        const bool __sortingEnabled = tableWidget_equipe->isSortingEnabled();
        tableWidget_equipe->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_equipe->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "154", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_equipe->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "fc barcelone", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_equipe->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_equipe->item(0, 3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "espagne", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_equipe->item(0, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "40", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_equipe->item(0, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Hans-Dieter Flick", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_equipe->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "295", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_equipe->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "real madrid fc", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_equipe->item(1, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_equipe->item(1, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "espagne", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_equipe->item(1, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "42", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_equipe->item(1, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Carlo Ancelotti", nullptr));
        tableWidget_equipe->setSortingEnabled(__sortingEnabled);

        label_3->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        label->setText(QString());
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Match", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "\303\211quipe", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Stade", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Employer", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nom du entra\303\256neur:", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nom de l'\303\250quipe:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pays de l'\303\250quipe:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ajouter \303\250quipe", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nombre des joueurs:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Classement:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", " Ajouter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Suppression d'\303\250quipe", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "ID d'\303\250quipe a supprimer:", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "ID \303\250quipe pour modifier:", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Nombre des joueurs:", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Classement:", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        comboBox_paye_2->setItemText(0, QCoreApplication::translate("MainWindow", "Select", nullptr));
        comboBox_paye_2->setItemText(1, QCoreApplication::translate("MainWindow", "TUNISI", nullptr));
        comboBox_paye_2->setItemText(2, QCoreApplication::translate("MainWindow", "MAROC", nullptr));

        label_29->setText(QCoreApplication::translate("MainWindow", "Pays de l'\303\250quipe:", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Nom de l'\303\250quipe:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Nom du entra\303\256neur:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        boutonRechercherNom_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "HIST", nullptr));
        boutonAfficherEtat->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "etat", nullptr));
        pushButton_export_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_trier->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        pushButton_rechercher->setText(QCoreApplication::translate("MainWindow", "RECHERCHER", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Le Nombre Total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
