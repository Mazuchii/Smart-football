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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Match
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_9;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QDateEdit *dateEdit;
    QComboBox *equip1_ajout;
    QComboBox *equip2_ajout;
    QComboBox *type_ajout;
    QPushButton *bt_ajouter;
    QLabel *label_14;
    QComboBox *stad_ajout;
    QWidget *tab_2;
    QTableWidget *tab_match;
    QPushButton *bt_recherch;
    QLineEdit *recherch;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QLabel *lab_equip;
    QLabel *lab_score;
    QLabel *lab_stad;
    QLabel *lab_date;
    QLabel *lab_type;
    QLabel *lab_pre;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Match)
    {
        if (Match->objectName().isEmpty())
            Match->setObjectName("Match");
        Match->resize(1269, 580);
        Match->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 52, 15);"));
        centralwidget = new QWidget(Match);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(190, -10, 821, 81));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(160, 20, 121, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(320, 20, 121, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(490, 20, 121, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(660, 20, 121, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, -10, 141, 81));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/logo/assetes/logo/logo_app.png);\n"
"\n"
""));
        label_9->setPixmap(QPixmap(QString::fromUtf8("assetes/logo/logo_app.png")));
        label_9->setScaledContents(true);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 70, 1231, 461));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"	font: 600 10pt \"Segoe UI\";\n"
"    border: 2px solid  rgb(102, 218, 166); /* Green border */\n"
"    background: #F0F0F0;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: rgb(226, 191, 94);\n"
"    color: black;\n"
"    padding: 10px;\n"
"    border: 1px solid gray;\n"
" font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"background-color: rgb(102, 218, 166);\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #FF9800; /* Orange when hovered */\n"
"    color: white;\n"
"}\n"
""));
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 0, 1211, 421));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(130, 110, 191, 41));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(130, 160, 191, 41));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(130, 210, 191, 41));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(660, 170, 191, 41));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(380, 20, 461, 41));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        dateEdit = new QDateEdit(groupBox_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(360, 110, 191, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        equip1_ajout = new QComboBox(groupBox_2);
        equip1_ajout->setObjectName("equip1_ajout");
        equip1_ajout->setGeometry(QRect(360, 160, 191, 41));
        equip1_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
""));
        equip2_ajout = new QComboBox(groupBox_2);
        equip2_ajout->setObjectName("equip2_ajout");
        equip2_ajout->setGeometry(QRect(360, 210, 191, 41));
        equip2_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);"));
        type_ajout = new QComboBox(groupBox_2);
        type_ajout->setObjectName("type_ajout");
        type_ajout->setGeometry(QRect(870, 170, 191, 41));
        type_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);"));
        bt_ajouter = new QPushButton(groupBox_2);
        bt_ajouter->setObjectName("bt_ajouter");
        bt_ajouter->setGeometry(QRect(540, 320, 201, 51));
        bt_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(660, 110, 191, 41));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        stad_ajout = new QComboBox(groupBox_2);
        stad_ajout->setObjectName("stad_ajout");
        stad_ajout->setGeometry(QRect(870, 110, 191, 41));
        stad_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_match = new QTableWidget(tab_2);
        if (tab_match->columnCount() < 4)
            tab_match->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab_match->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab_match->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab_match->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab_match->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tab_match->setObjectName("tab_match");
        tab_match->setGeometry(QRect(-5, 0, 731, 431));
        tab_match->setStyleSheet(QString::fromUtf8("\n"
"QTableWidget {\n"
"    background-color: #f8f9fa;\n"
"    border: 2px solid #4CAF50;  /* Green Border */\n"
"    gridline-color: #ddd;\n"
"    selection-background-color: #2196F3;  /* Blue Selection */\n"
"    selection-color: white;\n"
"    alternate-background-color: #E3F2FD;  /* Light blue alternating rows */\n"
"}\n"
"\n"
"/* Header Style */\n"
"QHeaderView::section {\n"
"background-color: rgb(102, 218, 166);\n"
"    color: black;\n"
"    padding: 8px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #388E3C;\n"
"}\n"
"\n"
"/* Rows and Cells */\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #ddd;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Hover Effect */\n"
"QTableWidget::item:hover {\n"
"    background-color: #FFD700; /* Gold on Hover */\n"
"    color: black;\n"
"}\n"
"\n"
"/* Selected Row */\n"
"QTableWidget::item:selected {\n"
"    background-color: #2196F3;\n"
"    color: white;\n"
"}\n"
""));
        tab_match->setLineWidth(1);
        tab_match->horizontalHeader()->setMinimumSectionSize(100);
        tab_match->horizontalHeader()->setDefaultSectionSize(150);
        bt_recherch = new QPushButton(tab_2);
        bt_recherch->setObjectName("bt_recherch");
        bt_recherch->setGeometry(QRect(840, 250, 271, 51));
        bt_recherch->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        recherch = new QLineEdit(tab_2);
        recherch->setObjectName("recherch");
        recherch->setGeometry(QRect(790, 140, 391, 51));
        recherch->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 218, 166);\n"
"font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 0, 521, 421));
        lab_equip = new QLabel(groupBox_3);
        lab_equip->setObjectName("lab_equip");
        lab_equip->setGeometry(QRect(20, 20, 461, 51));
        lab_equip->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";"));
        lab_score = new QLabel(groupBox_3);
        lab_score->setObjectName("lab_score");
        lab_score->setGeometry(QRect(20, 80, 461, 51));
        lab_score->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";"));
        lab_stad = new QLabel(groupBox_3);
        lab_stad->setObjectName("lab_stad");
        lab_stad->setGeometry(QRect(20, 140, 461, 51));
        lab_stad->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";"));
        lab_date = new QLabel(groupBox_3);
        lab_date->setObjectName("lab_date");
        lab_date->setGeometry(QRect(20, 200, 461, 51));
        lab_date->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";"));
        lab_type = new QLabel(groupBox_3);
        lab_type->setObjectName("lab_type");
        lab_type->setGeometry(QRect(20, 260, 461, 51));
        lab_type->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";"));
        lab_pre = new QLabel(groupBox_3);
        lab_pre->setObjectName("lab_pre");
        lab_pre->setGeometry(QRect(20, 320, 461, 91));
        lab_pre->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";"));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(530, 10, 691, 421));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/img/assetes/img/terain.png")));
        label_10->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        Match->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Match);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1269, 26));
        Match->setMenuBar(menubar);
        statusbar = new QStatusBar(Match);
        statusbar->setObjectName("statusbar");
        Match->setStatusBar(statusbar);

        retranslateUi(Match);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Match);
    } // setupUi

    void retranslateUi(QMainWindow *Match)
    {
        Match->setWindowTitle(QCoreApplication::translate("Match", "Match", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Match", "menu", nullptr));
        pushButton->setText(QCoreApplication::translate("Match", "home", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Match", "match", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Match", "equipe", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Match", "stade", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Match", "employe", nullptr));
        label_9->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("Match", "ajout match", nullptr));
        label_7->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">date</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">equipe 1</p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">equipe 2</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">type du match</p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"> ajouter match</p></body></html>", nullptr));
        bt_ajouter->setText(QCoreApplication::translate("Match", "ajouter", nullptr));
        label_14->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">Stade</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Match", "ajouter match", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab_match->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Match", "Num\303\251ro", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab_match->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Match", "equpe1", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab_match->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Match", "equipe2", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab_match->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Match", "Date", nullptr));
#if QT_CONFIG(whatsthis)
        tab_match->setWhatsThis(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        bt_recherch->setText(QCoreApplication::translate("Match", "recherche", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Match", "afficher match", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Match", "contenue", nullptr));
#if QT_CONFIG(whatsthis)
        lab_equip->setWhatsThis(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lab_equip->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">psg-rmd</p></body></html>", nullptr));
        lab_score->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">2-1</p></body></html>", nullptr));
        lab_stad->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">Bernabiu</p></body></html>", nullptr));
        lab_date->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">12/3/2025</p></body></html>", nullptr));
        lab_type->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">CHAMPIONS LEAGUE</p></body></html>", nullptr));
        lab_pre->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">PREDICTION</p></body></html>", nullptr));
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Match", "details du match", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Match: public Ui_Match {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
