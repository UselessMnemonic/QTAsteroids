#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include "gameobject.h"

class ViewPort : public QGraphicsScene
{

    Q_OBJECT

public:
    ViewPort();
    void startGame();
    void addItem(GameObject*);

private:
    QTimer* cycleTimer;
    QVector<GameObject*> itemList;
    void wrapShip();

public slots:
    void doGameTick();
};

#endif // VIEWPORT_H
