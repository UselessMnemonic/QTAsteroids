#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>
#include <QList>
#include <QVector2D>

class GameObject : public QGraphicsItem
{

public:
    GameObject();
    GameObject(qreal, qreal);
    GameObject(QPointF);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void update();
    virtual void setHitState(bool);
    virtual bool getHitState();


protected:
    bool hitState;
    int rotation;
    QVector2D velocity;
};

#endif // GAMEOBJECT_H
