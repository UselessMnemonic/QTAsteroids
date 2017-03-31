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
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void updatePosition();

protected:
    int rotation;
    QVector2D velocity;
};

#endif // GAMEOBJECT_H
