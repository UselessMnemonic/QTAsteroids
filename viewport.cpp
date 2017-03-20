#include "viewport.h"
#include "ship.h"

ViewPort::ViewPort() : QGraphicsScene()
{
    addLine(0,0,0,1, QPen(Qt::transparent, 1));
    addItem(new Ship(40 , 40));
}
