#include "gameobject.h"
#include "globals.h"
#include <QPainter>

GameObject::GameObject(qreal x, qreal y) : QGraphicsItem()
{
    setPos(x, y);
    theta = 0.0;
    velocity = QVector2D(0,0);
    rot = 0;
}

GameObject::GameObject() : GameObject(0,0)
{
}

void GameObject::doGameTick()
{
    qreal nextX = x() + velocity.x();
    qreal nextY = y() + velocity.y();
    setPos(nextX, nextY);
}

void GameObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(SHOW_BOUNDS)
    {
        painter->setPen( QPen(Qt::green, 1));
        painter->drawRect(this->boundingRect());
    }

    if(SHOW_TRAJECTORIES)
    {
        painter->setPen( QPen(Qt::red, 1));
        painter->drawLine(QPointF(0,0), velocity.toPointF());
    }
}
