#include "asteroid.h"
#include "time.h"
#include "globals.h"
#include <qdebug.h>
#include <QtMath>
#include <QPainter>

//randomizes the size and velocity of the asteroid
Asteroid::Asteroid(qreal x, qreal y) : GameObject(x, y)
{
    size = rand() % 3 + 1;
    size *= 12;

    int m = rand()%3;
    m*= 15;

    if(x == 0)
    {
        if(y > BASE_SIZE/2)
            m = 330 - m;
        else
            m = 60 - m;
    }
    else if (x == BASE_SIZE)
    {
        if(y > BASE_SIZE/2)
            m = 240 - m;
        else
            m = 150 - m;
    }
    else if (y == 0)
    {
        if(x < BASE_SIZE/2)
            m = 330 - m;
        else
            m = 240 - m;
    }
    else
    {
        if (x < BASE_SIZE/2)
            m = 60 - m;
        else
            m = 150 -m;
    }

    rotation = (int)m;
    setRotation(rotation);

    float speed = 10.0/size;
    velocity = QVector2D(degCOS(rotation) * speed, degSIN(rotation) * speed);
    setRotation(rotation);
    hitState = false;
}

Asteroid::Asteroid(qreal x, qreal y, QVector2D vel, int rot, int newSize) : GameObject(x, y)
{
    rotation = rot;
    if(rot < 0)
        rot += 360;
    else if (rot >= 360)
        rot -= 360;
    setRotation(rotation);
    hitState = false;
    velocity = vel;
    size = newSize;
}

int Asteroid::getSize()
{
    return size;
}

bool Asteroid::split(ViewPort* window)
{
    qDebug() << "Size: " << this->size;
    int newSize = size/12 - 1;

    if(newSize >= 1)
    {
        newSize*=12;

        float newSpeed = 10.0/newSize;
        int newRotation = rotation += 90;

        if(newRotation < 0)
            newRotation += 360;
        else if (newRotation >= 360)
            newRotation -= 360;

        QVector2D newVelocity = QVector2D(degCOS(newRotation) * newSpeed, degSIN(newRotation) * newSpeed);

        Asteroid* A = new Asteroid(x()+(newSize/2),  y()+(newSize/2), -newVelocity, newRotation, newSize);
        Asteroid* B = new Asteroid(x()-(newSize/2), y()-(newSize/2), newVelocity, newRotation + 180, newSize);

        window->addItem(A);
        window->addItem(B);

        qDebug() << "SPLIT!";
    }

    return newSize >= 1;
}

//draws a red circle
void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setPen(QColor(Qt::red));
    painter->drawEllipse(-size/2, -size/2, size, size);
    GameObject::paint(painter, options, widget);
}

