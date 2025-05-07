#include "ball.h"
#include "qbrush.h"
#include <QRandomGenerator>

Ball::Ball() {
    setRect(0, 0, 10, 10);
    setBrush(QBrush(Qt::white));
    velocity *= 0.99;
}

void Ball::move() {
    // Limite la vitesse maximale
    qreal maxSpeed = 5.0;
    qreal speed = std::hypot(velocity.x(), velocity.y());
    if (speed > maxSpeed) {
        velocity *= maxSpeed / speed;
    }

    moveBy(velocity.x(), velocity.y());

    // Rebond sur les bords
    if (pos().x() <= 0 || pos().x() >= 700) velocity.rx() *= -1;
    if (pos().y() <= 0 || pos().y() >= 340) velocity.ry() *= -1;
}


void Ball::addImpulse(QPointF impulse) {
    velocity += impulse;
}

void Ball::reset() {
    setPos(300, 150);
    velocity = QPointF(QRandomGenerator::global()->bounded(-2, 3), QRandomGenerator::global()->bounded(-2, 3));
}
