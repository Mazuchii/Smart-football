/********************************************************************************
** Form generated from reading UI file 'match.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCH_H
#define UI_MATCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QTableView *tab_match;
    QPushButton *bt_simulation;
    QLineEdit *recherch;
    QPushButton *bt_modifier;
    QPushButton *bt_supprimer;
    QPushButton *bt_tri;
    QPushButton *bt_tri_2;
    QPushButton *bt_pdf;
    QPushButton *bt_tri_type_dec;
    QPushButton *bt_tri_date_dec;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QLabel *lab_equip;
    QLabel *lab_score;
    QLabel *lab_stad;
    QLabel *lab_date;
    QLabel *lab_type;
    QLabel *lab_pre;
    QGraphicsView *match_sim;
    QWidget *tab_4;
    QGroupBox *groupBox_4;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QDateEdit *date_MOD;
    QComboBox *equip1_MOD;
    QComboBox *equip2_MOD;
    QComboBox *type_MOD;
    QPushButton *bt_MOD;
    QLabel *label_25;
    QComboBox *stad_MOD;
    QLabel *match_id;
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
        tabWidget->setGeometry(QRect(20, 70, 1231, 481));
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
"font: 700 13pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';"));
        equip1_ajout = new QComboBox(groupBox_2);
        equip1_ajout->setObjectName("equip1_ajout");
        equip1_ajout->setGeometry(QRect(360, 160, 191, 41));
        equip1_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        equip2_ajout = new QComboBox(groupBox_2);
        equip2_ajout->setObjectName("equip2_ajout");
        equip2_ajout->setGeometry(QRect(360, 210, 191, 41));
        equip2_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        type_ajout = new QComboBox(groupBox_2);
        type_ajout->addItem(QString());
        type_ajout->addItem(QString());
        type_ajout->addItem(QString());
        type_ajout->setObjectName("type_ajout");
        type_ajout->setGeometry(QRect(870, 170, 191, 41));
        type_ajout->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
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
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_match = new QTableView(tab_2);
        tab_match->setObjectName("tab_match");
        tab_match->setGeometry(QRect(0, 0, 801, 431));
        tab_match->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #002b11;\n"
"    color: #ffffff;\n"
"    font-size: 16px;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    border: 2px solid #4CAF50;\n"
"    gridline-color: #4CAF50;\n"
"    selection-background-color: #28a745;\n"
"    selection-color: white;\n"
"    alternate-background-color: #144d29;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 8px;\n"
"    border-bottom: 1px solid #3e8e41;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #66ff99;\n"
"    color: #000;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #a3f7bf;\n"
"    color: #003300;\n"
"    padding: 7px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #388E3C;\n"
"    text-align: center;\n"
"}"));
        tab_match->setLineWidth(1);
        tab_match->horizontalHeader()->setMinimumSectionSize(150);
        tab_match->horizontalHeader()->setStretchLastSection(true);
        bt_simulation = new QPushButton(tab_2);
        bt_simulation->setObjectName("bt_simulation");
        bt_simulation->setGeometry(QRect(940, 90, 271, 51));
        bt_simulation->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        recherch = new QLineEdit(tab_2);
        recherch->setObjectName("recherch");
        recherch->setGeometry(QRect(850, 20, 321, 51));
        recherch->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 218, 166);\n"
"font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        bt_modifier = new QPushButton(tab_2);
        bt_modifier->setObjectName("bt_modifier");
        bt_modifier->setGeometry(QRect(940, 170, 271, 51));
        bt_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        bt_supprimer = new QPushButton(tab_2);
        bt_supprimer->setObjectName("bt_supprimer");
        bt_supprimer->setGeometry(QRect(940, 240, 271, 51));
        bt_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        bt_tri = new QPushButton(tab_2);
        bt_tri->setObjectName("bt_tri");
        bt_tri->setGeometry(QRect(810, 110, 71, 31));
        bt_tri->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        bt_tri->setIcon(icon);
        bt_tri_2 = new QPushButton(tab_2);
        bt_tri_2->setObjectName("bt_tri_2");
        bt_tri_2->setGeometry(QRect(810, 220, 71, 31));
        bt_tri_2->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        bt_tri_2->setIcon(icon);
        bt_pdf = new QPushButton(tab_2);
        bt_pdf->setObjectName("bt_pdf");
        bt_pdf->setGeometry(QRect(950, 340, 111, 51));
        bt_pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        bt_tri_type_dec = new QPushButton(tab_2);
        bt_tri_type_dec->setObjectName("bt_tri_type_dec");
        bt_tri_type_dec->setGeometry(QRect(810, 270, 71, 31));
        bt_tri_type_dec->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        bt_tri_type_dec->setIcon(icon1);
        bt_tri_date_dec = new QPushButton(tab_2);
        bt_tri_date_dec->setObjectName("bt_tri_date_dec");
        bt_tri_date_dec->setGeometry(QRect(810, 150, 71, 31));
        bt_tri_date_dec->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        bt_tri_date_dec->setIcon(icon1);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 0, 411, 421));
        lab_equip = new QLabel(groupBox_3);
        lab_equip->setObjectName("lab_equip");
        lab_equip->setGeometry(QRect(20, 20, 371, 51));
        lab_equip->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';\n"
""));
        lab_score = new QLabel(groupBox_3);
        lab_score->setObjectName("lab_score");
        lab_score->setGeometry(QRect(20, 80, 371, 51));
        lab_score->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';\n"
""));
        lab_stad = new QLabel(groupBox_3);
        lab_stad->setObjectName("lab_stad");
        lab_stad->setGeometry(QRect(20, 140, 371, 51));
        lab_stad->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';\n"
""));
        lab_date = new QLabel(groupBox_3);
        lab_date->setObjectName("lab_date");
        lab_date->setGeometry(QRect(20, 200, 371, 51));
        lab_date->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';\n"
""));
        lab_type = new QLabel(groupBox_3);
        lab_type->setObjectName("lab_type");
        lab_type->setGeometry(QRect(20, 260, 371, 51));
        lab_type->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 12pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';\n"
""));
        lab_pre = new QLabel(groupBox_3);
        lab_pre->setObjectName("lab_pre");
        lab_pre->setGeometry(QRect(20, 320, 371, 91));
        lab_pre->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 202, 101);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 10pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignTop | AlignHCenter';\n"
""));
        match_sim = new QGraphicsView(tab);
        match_sim->setObjectName("match_sim");
        match_sim->setGeometry(QRect(425, 11, 791, 401));
        match_sim->setStyleSheet(QString::fromUtf8("border-image:url(:/img/assetes/img/terain.png)"));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 0, 1211, 421));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(140, 90, 191, 41));
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(350, 90, 191, 41));
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(560, 90, 191, 41));
        label_22->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(1000, 90, 191, 41));
        label_23->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(380, 20, 461, 41));
        label_24->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        date_MOD = new QDateEdit(groupBox_4);
        date_MOD->setObjectName("date_MOD");
        date_MOD->setGeometry(QRect(140, 170, 191, 41));
        date_MOD->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
"qproperty-alignment: 'AlignCenter';"));
        equip1_MOD = new QComboBox(groupBox_4);
        equip1_MOD->setObjectName("equip1_MOD");
        equip1_MOD->setGeometry(QRect(350, 170, 191, 41));
        equip1_MOD->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        equip2_MOD = new QComboBox(groupBox_4);
        equip2_MOD->setObjectName("equip2_MOD");
        equip2_MOD->setGeometry(QRect(560, 170, 191, 41));
        equip2_MOD->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        type_MOD = new QComboBox(groupBox_4);
        type_MOD->addItem(QString());
        type_MOD->addItem(QString());
        type_MOD->addItem(QString());
        type_MOD->setObjectName("type_MOD");
        type_MOD->setGeometry(QRect(1000, 170, 191, 41));
        type_MOD->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        bt_MOD = new QPushButton(groupBox_4);
        bt_MOD->setObjectName("bt_MOD");
        bt_MOD->setGeometry(QRect(540, 320, 201, 51));
        bt_MOD->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 191, 94);\n"
"color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";\n"
"selection-background-color: rgb(227, 172, 7);"));
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(780, 90, 191, 41));
        label_25->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        stad_MOD = new QComboBox(groupBox_4);
        stad_MOD->setObjectName("stad_MOD");
        stad_MOD->setGeometry(QRect(780, 170, 191, 41));
        stad_MOD->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 168, 132);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 13pt \"Segoe UI\";\n"
""));
        match_id = new QLabel(groupBox_4);
        match_id->setObjectName("match_id");
        match_id->setGeometry(QRect(10, 170, 121, 41));
        match_id->setStyleSheet(QString::fromUtf8("background-color: rgb(99, 99, 99);\n"
"font: 14pt \"Trebuchet MS\";\n"
"color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_4, QString());
        Match->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Match);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1269, 26));
        Match->setMenuBar(menubar);
        statusbar = new QStatusBar(Match);
        statusbar->setObjectName("statusbar");
        Match->setStatusBar(statusbar);

        retranslateUi(Match);

        tabWidget->setCurrentIndex(1);


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
        type_ajout->setItemText(0, QCoreApplication::translate("Match", "Champions League", nullptr));
        type_ajout->setItemText(1, QCoreApplication::translate("Match", "Ligue", nullptr));
        type_ajout->setItemText(2, QCoreApplication::translate("Match", "Amical", nullptr));

        bt_ajouter->setText(QCoreApplication::translate("Match", "ajouter", nullptr));
        label_14->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">Stade</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Match", "ajouter match", nullptr));
#if QT_CONFIG(whatsthis)
        tab_match->setWhatsThis(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        bt_simulation->setText(QCoreApplication::translate("Match", "Simulation", nullptr));
        bt_modifier->setText(QCoreApplication::translate("Match", "Modifier", nullptr));
        bt_supprimer->setText(QCoreApplication::translate("Match", "Suprimer", nullptr));
        bt_tri->setText(QCoreApplication::translate("Match", "date", nullptr));
        bt_tri_2->setText(QCoreApplication::translate("Match", "type", nullptr));
        bt_pdf->setText(QCoreApplication::translate("Match", "pdf", nullptr));
        bt_tri_type_dec->setText(QCoreApplication::translate("Match", "type", nullptr));
        bt_tri_date_dec->setText(QCoreApplication::translate("Match", "date", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Match", "afficher match", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Match", "contenue", nullptr));
#if QT_CONFIG(whatsthis)
        lab_equip->setWhatsThis(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lab_equip->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        lab_score->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        lab_stad->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        lab_date->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        lab_type->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        lab_pre->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Match", "details du match", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Match", "ajout match", nullptr));
        label_20->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">date</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">equipe 1</p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">equipe 2</p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">type du match</p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">Modifier match</p></body></html>", nullptr));
        type_MOD->setItemText(0, QCoreApplication::translate("Match", "Champions League", nullptr));
        type_MOD->setItemText(1, QCoreApplication::translate("Match", "Ligue", nullptr));
        type_MOD->setItemText(2, QCoreApplication::translate("Match", "Amical", nullptr));

        bt_MOD->setText(QCoreApplication::translate("Match", "Modifier", nullptr));
        label_25->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\">Stade</p></body></html>", nullptr));
        match_id->setText(QCoreApplication::translate("Match", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Match", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Match: public Ui_Match {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCH_H
