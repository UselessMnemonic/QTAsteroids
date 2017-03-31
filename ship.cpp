#include "ship.h"
#include "bullet.h"
#include <QPainter>
#include <QKeyEvent>

Ship::Ship(qreal x, qreal y, ViewPort* context) : GameObject(x, y)
{
    accelDir = 0;
    parent = context;
}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   
    painter->setPen( QPen(Qt::white, 1));
    //draws the shape of the ship
    for(int i = 1; i <= 3; i++)
        painter->drawLine(geometry[i-1],geometry[i]);
    painter->drawLine(geometry[3], geometry[0]);

    GameObject::paint(painter, option, widget);
}

void Ship::keyPressEvent(QKeyEvent *event)
{
  if(event->key() == Qt::Key_Space)
  {

  }
}

void Ship::shootBullet()
{
    Bullet* nB = new Bullet(pos(), rotation);
    parent->addItem(nB);
}
