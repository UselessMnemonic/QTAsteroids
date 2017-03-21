#include "ship.h"
#include <QPainter>

Ship::Ship(qreal x, qreal y) : QGraphicsItem()
{
    setPos(x, y);
}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen( QPen(Qt::red, 2));

    for(int i = 1; i <= 3; i++)
        painter->drawLine(geometry[i-1],geometry[i]);
    painter->drawLine(geometry[3], geometry[0]);

    painter->setPen(QPen(Qt::green, 2));
    painter->drawPoint(0,0);
}
