#ifndef BULLET_H
#define BULLET_H

#include "gameobject.h"

class Bullet : public GameObject
{

public:
    // default constructor - sets size of bullet
    Bullet(QPointF, int);

    //draws the bullet
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
    QRectF boundingRect() const
    { return QRectF(-4,-2,4,2); }



};

#endif // BULLET_H
