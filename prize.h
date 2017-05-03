#ifndef PRIZE_H
#define PRIZE_H

#include "gameobject.h"

class Prize : public GameObject
{

public:
    // default constructor - sets position of prize
    Prize(QPointF);

    //draws the prize
    void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );

    QRectF boundingRect() const
    { return QRectF(-4,-4,8,8); }

    void update();

    //add logic to provide power ups
private:
    float t;

};

#endif // PRIZE_H
