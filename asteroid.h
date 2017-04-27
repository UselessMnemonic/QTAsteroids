#ifndef ASTEROID_H
#define ASTEROID_H

#include "gameobject.h"
#include "viewport.h"

class Asteroid : public GameObject
{
public:
    //constructors
    Asteroid(qreal, qreal, QVector2D, int);
    Asteroid(qreal, qreal);

    bool split(ViewPort*);

    //draws the asteroid
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );

    QRectF boundingRect() const
    { return QRectF(-size/2, -size/2, size, size); }

private:
    // size of the asteroid defined by values 1-3
    int size;
};

#endif // ASTEROID_H
