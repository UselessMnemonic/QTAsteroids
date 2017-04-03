#ifndef ASTEROID_H
#define ASTEROID_H

#include "gameobject.h"

class Asteroid : public GameObject
{
public:
    Asteroid(qreal, qreal);
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
    QRectF boundingRect() const
    { return QRectF(-size/2, -size/2, size, size); }
private:
    int size;
};

#endif // ASTEROID_H
