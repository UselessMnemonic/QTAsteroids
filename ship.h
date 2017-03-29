#ifndef SHIP_H
#define SHIP_H

#include "gameobject.h"

class Ship : public GameObject
{
public:
  Ship( qreal, qreal );
  void paint( QPainter*,
              const QStyleOptionGraphicsItem*,
              QWidget* );
  QRectF boundingRect() const
  { return QRectF(-15, 0, 30, 30 ); }

private:
  //defines the ship's verticies
  int accelDir;
  int rot;

  QPoint geometry[4] = {QPoint(0, 0), QPoint(15, 30), QPoint(0, 24), QPoint(-15, 30)};
};

#endif // SHIP_H
