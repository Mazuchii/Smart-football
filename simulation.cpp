#include "simulation.h"
#include "qsqlquery.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QRandomGenerator>
#include <QSqlError>

Simulation::Simulation(QObject *parent) : QObject(parent), scene(nullptr), timer(new QTimer(this)), scoreRed(0), scoreBlue(0) {
    connect(timer, &QTimer::timeout, this, &Simulation::update);
}

void Simulation::start(QGraphicsScene *scene) {
    this->scene = scene;
    scene->clear();

    setupField();

    timer->start(30);
}

void Simulation::setupField() {
    QPixmap bg("simulation/field_background.png");
    QGraphicsPixmapItem *bgItem = scene->addPixmap(bg);
    bgItem->setZValue(-1);

    for (int i = 0; i < 5; ++i) {
        Player* red = new Player(true);
        Player* blue = new Player(false);

        if (i == 0) {
            red->isCaptain = true;
            red->setAsGoalkeeper(true);
            red->setPos(720, 165); // Rouge dans sa cage à droite

            blue->isCaptain = true;
            blue->setAsGoalkeeper(true);
            blue->setPos(10, 165); // Bleu dans sa cage à gauche
        } else {
            red->setPos(400 + QRandomGenerator::global()->bounded(180),
                        QRandomGenerator::global()->bounded(300));
            blue->setPos(QRandomGenerator::global()->bounded(180),
                         QRandomGenerator::global()->bounded(300));
        }

        scene->addItem(red);
        teamRed.append(red);

        scene->addItem(blue);
        teamBlue.append(blue);
    }

    ball = new Ball();
    ball->setPos(300, 150);
    scene->addItem(ball);
}


void Simulation::update() {
    // Combiner toutes les équipes
    QList<Player*> allPlayers = teamRed + teamBlue;

    // Trouver les 2 joueurs les plus proches de la balle
    std::sort(allPlayers.begin(), allPlayers.end(), [this](Player* a, Player* b) {
        return QLineF(a->pos(), ball->pos()).length() < QLineF(b->pos(), ball->pos()).length();
    });

    // Les 2 premiers vont poursuivre activement la balle
    QSet<Player*> activeChasers = { allPlayers.value(0), allPlayers.value(1) };

    // Mettre à jour tous les joueurs
    for (Player* p : allPlayers) {
        bool active = activeChasers.contains(p);
        p->updateAI(ball, teamRed, teamBlue, active);
    }

    ball->move();
    checkGoal();
}


void Simulation::checkGoal() {
    QPointF pos = ball->pos();
    QSqlQuery query;

    if (pos.x() < 10 && pos.y() > 110 && pos.y() < 190) {
        scoreRed++;
        qDebug() << "But pour l'équipe 2 ! Nouveau score : " << scoreRed;

        // Mettre à jour SCORE_EQ2 (équipe 2)
        query.prepare("UPDATE MATCH SET SCORE_EQ2 = :score2 WHERE ID_MATCH = :matchId");
        query.bindValue(":score2", scoreRed);
        query.bindValue(":matchId", matchId); // matchId doit être défini dans Simulation
        if (!query.exec()) {
            qDebug() << "Erreur lors de la mise à jour de SCORE_EQ2 :" << query.lastError().text();
        }

        emit scoreChanged(scoreBlue, scoreRed);
        ball->reset();

    } else if (pos.x() > 720 && pos.y() > 110 && pos.y() < 190) {
        scoreBlue++;
        qDebug() << "But pour l'équipe 1 ! Nouveau score : " << scoreBlue;

        // Mettre à jour SCORE_EQ1 (équipe 1)
        query.prepare("UPDATE MATCH SET SCORE_EQ1 = :score1 WHERE ID_MATCH = :matchId");
        query.bindValue(":score1", scoreBlue);
        query.bindValue(":matchId", matchId);
        if (!query.exec()) {
            qDebug() << "Erreur lors de la mise à jour de SCORE_EQ1 :" << query.lastError().text();
        }

        emit scoreChanged(scoreBlue, scoreRed);
        ball->reset();
    }
}


void Simulation::setMatchId(int id) {
    matchId = id;
}
