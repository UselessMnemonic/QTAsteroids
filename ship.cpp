#include "ship.h"
#include <QPainter>

Ship::Ship(qreal x, qreal y) : QGraphicsItem()
{
    //only constructor

    //set position of ship
    setPos(x, y);
}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //set up brush before paint
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen( QPen(Qt::red, 2));

    //draws the shape of the ship
    for(int i = 1; i <= 3; i++)
        painter->drawLine(geometry[i-1],geometry[i]);
    painter->drawLine(geometry[3], geometry[0]);

}
