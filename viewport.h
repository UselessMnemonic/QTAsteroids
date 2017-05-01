#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include <QImage>
#include <QGraphicsItem>
#include "gameobject.h"
#include "viewport.h"

class ViewPort : public QGraphicsScene
{

    Q_OBJECT

public:
    ViewPort();
    void startGame();
    void addItem(GameObject*);
    void endGame();

    /*QRectF boundingRect() const
    {return QRectF(-4, -2, 4, 2);}
*/
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
