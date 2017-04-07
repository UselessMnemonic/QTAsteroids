#include "gameobject.h"
#include "globals.h"
#include <QPainter>

GameObject::GameObject(qreal x, qreal y) : QGraphicsItem()
{
    setPos(x, y);
    rotation = 0;
    setRotation(rotation);
    velocity = QVector2D(0,0);
}

GameObject::GameObject() : GameObject(0,0)
{
}

GameObject::GameObject(QPointF loc) : GameObject(loc.x(), loc.y())
{
}

void GameObject::update()
{
    setRotation(rotation);
    setPos(pos() + velocity.toPointF());
}

void GameObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::blue));
    painter->rotate(-rotation);

    if(SHOW_BOUNDS)
    {
        painter->drawRect(this->boundingRect());
    }

    if(SHOW_TRAJECTORIES)
    {
        painter->drawLine(QPointF(0,0), (velocity*3).toPointF());
    }
}
