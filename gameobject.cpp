#include "gameobject.h"
#include "globals.h"
#include <QPainter>

//constructor that takes x y coordinates
GameObject::GameObject(qreal x, qreal y) : QGraphicsItem()
{
    setPos(x, y);
    rotation = 0;
    setRotation(rotation);
    velocity = QVector2D(0,0);
}

//default constructor for game object
GameObject::GameObject() : GameObject(0,0)
{
}

//constructor that takes a QPointF
GameObject::GameObject(QPointF loc) : GameObject(loc.x(), loc.y())
{
}

//default update function that sets the object's position
void GameObject::update()
{
    setRotation(rotation);
    setPos(pos() + velocity.toPointF());
}

//default paint function that draws the bounding box and velocity vector of the object
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
