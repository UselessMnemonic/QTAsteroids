#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>
#include <QVector2D>

class GameObject : public QGraphicsItem
{

public:
    GameObject();
    GameObject(qreal, qreal);
    GameObject(QPointF);
    virtual void update();

protected:
    int rotation;
    QVector2D velocity;
};

#endif // GAMEOBJECT_H
