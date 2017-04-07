#include "bullet.h"
#include "globals.h"
#include <QPainter>

// Default constructor - every bullet should
// spawn with a fixed size
Bullet::Bullet(QPointF loc, int angle) : GameObject(loc)
{
    rotation = angle;
    setRotation(rotation);
    velocity = QVector2D(degCOS(rotation) * 8, degSIN(rotation) * 8);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setPen( QPen(Qt::yellow, 1));
    painter->setBackground(QBrush(Qt::yellow));
    painter->drawRect(QRect(-4,-2,4,2));
}
