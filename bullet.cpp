#include "bullet.h"
#include "globals.h"
#include <QPainter>

// Default constructor - every bullet should
// spawn with a fixed size
Bullet::Bullet(QPointF loc, int angle) : GameObject(loc)
{
    rotation = angle;
    setRotation(rotation);
    velocity = QVector2D(5*degCOS(rotation), 5*degSIN(rotation));
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setPen( QPen(Qt::yellow, 1));
    painter->drawRect(QRect(0,0,2,3));

    GameObject::paint(painter, options, widget);
}
