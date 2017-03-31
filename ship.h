#ifndef SHIP_H
#define SHIP_H

#include "gameobject.h"
#include "viewport.h"
#include "bullet.h"

class Ship : public GameObject
{
public:
  Ship( qreal, qreal, ViewPort* );
  void paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* );
  QRectF boundingRect() const
  { return QRectF(-15, 0, 30, 30 ); }

  void keyPressEvent(QKeyEvent *event);
  void shootBullet();

private:
  QPoint geometry[4]; // = {QPoint(0, 0),QPoint(15, 30),QPoint(0, 24),QPoint(-15, 30)};
  int accelDir;
  ViewPort* parent;
};

#endif // SHIP_H
