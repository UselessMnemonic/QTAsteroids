#include "ship.h"
#include <QPainter>
#include <QKeyEvent>

Ship::Ship(qreal x, qreal y) : GameObject(x, y)
{
    accelDir = 0;
}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   
    painter->setPen( QPen(Qt::white, 1));
    //draws the shape of the ship
    for(int i = 1; i <= 3; i++)
        painter->drawLine(geometry[i-1],geometry[i]);
    painter->drawLine(geometry[3], geometry[0]);
    GameObject::paint(painter, option, widget);
}

void Ship::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key::Key_Space:
                accelDir += 1;

        case Qt::Key::Key_Shift:
                accelDir -= 1;

        case Qt::Key::Key_D:
                rot -= 1;

        case Qt::Key::Key_A:
                rot += 1;
    }
}

void Ship::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key::Key_Space:
                accelDir -= 1;

        case Qt::Key::Key_Shift:
                accelDir += 1;

        case Qt::Key::Key_D:
                rot += 1;

        case Qt::Key::Key_A:
                rot -= 1;
    }
}

void Ship::doGameTick()
{
    qreal nX = cos(theta);
    qreal nY = sin(theta);

    QVector2D acceleration = accelDir * QVector2D(nX, nY);
    velocity += acceleration;

    GameObject::doGameTick();
}
