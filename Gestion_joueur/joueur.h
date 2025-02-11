#ifndef JOUEUR_H
#define JOUEUR_H

#include <QMainWindow>

namespace Ui {
class Joueur;  // Vérifie que c'est bien "Joueur" avec une majuscule si besoin
}

class Joueur : public QMainWindow
{
    Q_OBJECT

public:
    explicit Joueur(QWidget *parent = nullptr);
    ~Joueur();

private:
    Ui::Joueur *ui;  // Vérifie que ça correspond bien
};

#endif // JOUEUR_H
