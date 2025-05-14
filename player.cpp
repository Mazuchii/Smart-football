#include "player.h"
#include "ball.h"
#include <QRandomGenerator>
#include <QtMath>

Player::Player(bool isRed, bool isCaptain)
    : isCaptain(isCaptain), isRedTeam(isRed) {
    setRect(0, 0, 10, 10);
    setBrush(isRed ? Qt::red : Qt::blue);
}

void Player::updateAI(Ball* ball, const QList<Player*>& teammates,const QList<Player*>& opponents, bool activeChaser) {
    QPointF target;
    if (goalkeeper) return;

    if (activeChaser) {
        // Poursuit la balle
        target = ball->pos();
    } else {
        // Se rapproche légèrement
        QPointF toBall = ball->pos() - pos();
        target = pos() + toBall * 0.05;  // petit déplacement vers la balle
    }

    QPointF dir = target - pos();
    qreal length = std::hypot(dir.x(), dir.y());
    if (length > 1) {
        dir /= length;
    }

    // Répulsion
    QPointF repulsion(0, 0);
    for (const Player* mate : teammates) {
        if (mate == this) continue;
        QPointF diff = pos() - mate->pos();
        qreal dist = std::hypot(diff.x(), diff.y());
        if (dist < 25 && dist > 0.1) {
            repulsion += diff / dist;
        }
    }

    dir += repulsion * 0.4;


    if (QLineF(pos(), ball->pos()).length() < 12) {
        QPointF impulse = dir * 2;
        ball->addImpulse(impulse);
    }


    qreal maxSpeed = activeChaser ? 1.5 : 0.3;
    if (std::hypot(dir.x(), dir.y()) > maxSpeed) {
        dir *= maxSpeed / std::hypot(dir.x(), dir.y());
    }

    moveBy(dir.x(), dir.y());
}
