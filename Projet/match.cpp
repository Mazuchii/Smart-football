#include "match.h"
#include "ui_match.h"

Match::Match(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Match)
{
    ui->setupUi(this);
}

Match::~Match()
{
    delete ui;
}
