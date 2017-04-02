#include "ship.h"
#include "bullet.h"
#include "globals.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsItem>

Ship::Ship(qreal x, qreal y, ViewPort* context) : GameObject(x, y)
{
    accelDir = 0;
    rotDir = 0;
    parent = context;
    qDebug("Added ship!");
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
   int input = event->key();
   switch(input)
  {
  case Qt::Key_Space:
      shootBullet();
  case Qt::Key_A:
      rotDir++;
  case Qt::Key_D:
      rotDir--;
  case Qt::Key_W:
       accelDir++;
  case Qt::Key_S:
       accelDir--;
  }
}

void Ship::keyReleaseEvent(QKeyEvent *event)
{
  int input = event->key();
  switch(input)
  {
  case Qt::Key_A:
      rotDir--;
  case Qt::Key_D:
      rotDir++;
  case Qt::Key_W:
       accelDir--;
  case Qt::Key_S:
       accelDir++;
  }
}

void Ship::updatePosition()
{
    rotation += rotDir*30;
    setRotation(rotation);
    QVector2D acceleration(degCOS(rotation), degSIN(rotation));
    acceleration *= accelDir;

    velocity+=acceleration;

    GameObject::updatePosition();
}

void Ship::shootBullet()
{
    Bullet* nB = new Bullet(pos(), rotation);
    parent->addItem(nB);
    qDebug("Shot bullet!");
}
