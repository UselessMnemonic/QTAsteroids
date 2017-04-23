#ifndef ASTEROID_H
#define ASTEROID_H

#include "gameobject.h"

class Asteroid : public GameObject
{
public:
    //constructor
    Asteroid(qreal, qreal);

    //draws the asteroid
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
    QRectF boundingRect() const
    { return QRectF(-size/2, -size/2, size, size); }

private:
    // size of the asteroid defined by values 1-3
    int size;
};

#endif // ASTEROID_H
