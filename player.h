#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QList>
#include "ball.h"

class Player : public QGraphicsEllipseItem {
public:
    Player(bool isRed, bool isCaptain = false); // add isCaptain
    void updateAI(Ball* ball, const QList<Player*>& teammates, const QList<Player*>& opponents, bool activeChaser);
    bool isCaptain;
    void setAsGoalkeeper(bool value) { goalkeeper = value; }
private:
    bool isRedTeam;
    bool goalkeeper = false;

};

#endif // PLAYER_H
