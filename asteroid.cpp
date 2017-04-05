#include "asteroid.h"
#include "time.h"
#include "globals.h"
#include <QPainter>

Asteroid::Asteroid(qreal x, qreal y) : GameObject(x, y)
{
    size = rand() % 3 + 1;
    size *= 12;
    srand(time(NULL));
    int angle = rand()%360;
    float speed = 10.0/size;
    velocity = QVector2D(degCOS(angle) * speed, degSIN(angle) * speed);
    setRotation(angle);
}

void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setPen(QColor(Qt::red));
    painter->drawEllipse(-size/2, -size/2, size, size);
    GameObject::paint(painter, options, widget);
}
