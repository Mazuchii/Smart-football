#include "joueur.h"
#include "ui_joueur.h"

Joueur::Joueur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Joueur)
{
    ui->setupUi(this);
}

Joueur::~Joueur()
{
    delete ui;
}

