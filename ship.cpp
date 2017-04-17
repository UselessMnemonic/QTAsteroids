#include "ship.h"
#include "bullet.h"
#include "globals.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsItem>
#include <QVector2D>

//Constructor takes location, calls parent constructor, and sets ship defaults
Ship::Ship(qreal x, qreal y, ViewPort* context) : GameObject(x, y)
{
    accelDir = 0;
    rotDir = 0;
    parent = context;
    bulletCooldown = 0;
    rotation = 270;
    setRotation(rotation);
}

//draws a ship as defined by the verticies in geometry[]
void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen( QPen(Qt::white, 1));
    //draws the shape of the ship
    for(int i = 1; i <= 3; i++)
        painter->drawLine(geometry[i-1],geometry[i]);
    painter->drawLine(geometry[3], geometry[0]);

    GameObject::paint(painter, option, widget);
}

//takes key events
//TODO rework input interface
void Ship::keyPressEvent(QKeyEvent *event)
{
   int input = event->key();
   switch(input)
  {
  case Qt::Key_Space:
      shootBullet();
       break;
  case Qt::Key_A:
      rotDir--;
       break;
  case Qt::Key_D:
      rotDir++;
       break;
  case Qt::Key_W:
       accelDir++;
       break;
  case Qt::Key_S:
       accelDir--;
       break;
  }
}

//reacts to key releases
void Ship::keyReleaseEvent(QKeyEvent *event)
{
  int input = event->key();
  switch(input)
  {
  case Qt::Key_A:
      rotDir++;
      break;
  case Qt::Key_D:
      rotDir--;
      break;
  case Qt::Key_W:
       accelDir--;
      break;
  case Qt::Key_S:
       accelDir++;
      break;
  }
}

//update's ship's rotation, velocity, and position,
// and checks wether or not a bullet may be fired on this frame
void Ship::update()
{
    //cooldown before next bullet shot
    if(bulletCooldown > 0)
        bulletCooldown--;

    //set and adjust the rotation of the ship
    rotation += rotDir*5;
    if(rotation < 0)
        rotation = 355;
    else if (rotation > 360)
        rotation = 5;
    setRotation(rotation);

    //create acceleration and add to velocity
    QVector2D acceleration(degCOS(rotation) * 0.05 * accelDir, degSIN(rotation) * 0.05 * accelDir);
    velocity += acceleration;

    //finally, set position of ship
    setPos(pos() + velocity.toPointF());
}

//spawns bullet with ship's rotation and direction
void Ship::shootBullet()
{
    if(bulletCooldown == 0)
    {
        Bullet* nB = new Bullet(pos(), rotation);
        parent->addItem(nB);
        bulletCooldown = 8;
    }
}
