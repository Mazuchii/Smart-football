#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "ball.h"

class Simulation : public QObject {
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = nullptr);
    void start(QGraphicsScene *scene);
    void setMatchId(int id);

private slots:
    void update();

private:
    QGraphicsScene *scene;
    QList<Player*> teamRed;
    QList<Player*> teamBlue;
    Ball* ball;
    QTimer* timer;
    int scoreRed;
    int scoreBlue;
    void setupField();
    void checkGoal();
    int matchId;
signals:
    void scoreChanged(int scoreEquipe1, int scoreEquipe2);
};

#endif // SIMULATION_H
