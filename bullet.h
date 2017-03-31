#ifndef BULLET_H
#define BULLET_H

#include "gameobject.h"

class Bullet : public GameObject
{

public:
    // default constructor - sets size of bullet
    Bullet(QPointF, int);
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
    QRectF boundingRect() const
    { return QRectF(0, 0, 2, 3 ); }
};

#endif // BULLET_H
