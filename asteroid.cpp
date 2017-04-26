#include "asteroid.h"
#include "time.h"
#include "globals.h"
#include <qdebug.h>
#include <QPainter>

//randomizes the size and velocity of the asteroid
Asteroid::Asteroid(qreal x, qreal y) : GameObject(x, y)
{
    size = rand() % 3 + 1;
    size *= 12;
    srand(time(NULL));
    int angle = rand()%360;
    float speed = 10.0/size;
    velocity = QVector2D(degCOS(angle) * speed, degSIN(angle) * speed);
    setRotation(angle);
    hitState = false;
}

Asteroid::Asteroid(qreal x, qreal y, QVector2D vel, int size)
{
    srand(time(NULL));
    int angle = rand()%360;
    rotation = angle;
    setRotation(rotation);
    hitState = false;
    velocity = vel;
    this->size = size;
}

bool Asteroid::split(ViewPort* window)
{
    qDebug() << "Size: " << size;
    bool spl = (size / 12) > 1;
    if(spl)
    {
        float speed = 10.0/size;

        rotation += 90;

        if(rotation < 0)
            rotation = 360+rotation;
        else if (rotation > 360)
            rotation -= 360;

        velocity = QVector2D(degCOS(rotation) * speed, degSIN(rotation) * speed);

        Asteroid* A = new Asteroid(x()+2,  y()+2, -velocity/2, size-12);
        Asteroid* B = new Asteroid(x()-2, y()-2, velocity/2, size-12);

        window->addItem(A);
        window->addItem(B);

        qDebug() << "SPLIT!";
    }

    return spl;
}

//draws a red circle
void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setPen(QColor(Qt::red));
    painter->drawEllipse(-size/2, -size/2, size, size);
    GameObject::paint(painter, options, widget);
}

