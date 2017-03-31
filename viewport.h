#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include "gameobject.h"

class ViewPort : public QGraphicsScene
{

public:
    ViewPort();
    void startGame();
    void addItem(GameObject*);

private:
    QTimer* cycleTimer;
    QVector<GameObject*> itemList;

public slots:
    void doGameTick();
};

#endif // VIEWPORT_H
