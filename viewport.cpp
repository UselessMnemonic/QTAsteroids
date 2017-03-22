#include "viewport.h"
#include "globals.h"

ViewPort::ViewPort() : QGraphicsScene()
{
    addLine(0,0,0,1, QPen(Qt::transparent, 1));

    //draw background
    addRect(0,0,500,500, QPen(Qt::black), QBrush(1));

  /* for(int r = 0, s = 500; r < 10; r++, s-=2)
        addRect(r, r, s, s, QPen(QColor(10*(10-r), 0, 0)), QBrush(1));
        */
}
