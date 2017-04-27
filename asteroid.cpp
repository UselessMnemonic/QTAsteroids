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
    rotation = rand()%360;
    float speed = 10.0/size;
    velocity = QVector2D(degCOS(rotation) * speed, degSIN(rotation) * speed);
    setRotation(rotation);
    hitState = false;
}

Asteroid::Asteroid(qreal x, qreal y, QVector2D vel, int newSize) : GameObject(x, y)
{
    srand(time(NULL));
    int angle = rand()%360;
    rotation = angle;
    setRotation(rotation);
    hitState = false;
    velocity = vel;
    size = newSize;
}

bool Asteroid::split(ViewPort* window)
{
    qDebug() << "Size: " << this->size;
    int newSize = size/2;

    if(newSize >= 12)
    {
        float newSpeed = 10.0/newSize;
        int newRotation = rotation += 90;

        if(newRotation < 0)
            newRotation += 360;
        else if (newRotation >= 360)
            newRotation -= 360;

        QVector2D newVelocity = QVector2D(degCOS(newRotation) * newSpeed, degSIN(newRotation) * newSpeed);

        Asteroid* A = new Asteroid(x()+(newSize/2),  y()+(newSize/2), newVelocity/2, newSize);
        Asteroid* B = new Asteroid(x()-(newSize/2), y()-(newSize/2), -newVelocity/2, newSize);

        window->addItem(A);
        window->addItem(B);

        qDebug() << "SPLIT!";
    }

    return newSize >= 12;
}

//draws a red circle
void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setPen(QColor(Qt::red));
    painter->drawEllipse(-size/2, -size/2, size, size);
    GameObject::paint(painter, options, widget);
}

