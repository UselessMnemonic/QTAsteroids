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
  { return QRectF(-10, -10, 20, 20 ); }

  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void update();

  void shootBullet();

private:
  QPoint geometry[4] = {QPoint(10, 0),QPoint(-10, -10),QPoint(-6, 0) ,QPoint(-10, 10)};
  int accelDir;
  int rotDir;
  int bulletCooldown;
  ViewPort* parent;
};

#endif // SHIP_H
