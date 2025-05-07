#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

class Ball : public QGraphicsEllipseItem {
public:
    Ball();
    void move();
    void reset();
    void addImpulse(QPointF impulse);
private:
    QPointF velocity;
};

#endif // BALL_H
