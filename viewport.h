#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include <QImage>
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
    void spawnAsteroid();
    int spawnCooldown;

public slots:
    void doGameTick();
};

#endif // VIEWPORT_H
