#include "viewport.h"
#include "ship.h"
#include "globals.h"
#include <iostream>

ViewPort::ViewPort() : QGraphicsScene()
{
    addLine(0,0,0,1, QPen(Qt::transparent, 1));

    //draw background
    addRect(0,0,500,500, QPen(Qt::black), QBrush(1));

    //set up timer to control game stepping
    cycleTimer = new QTimer(this);
    connect(cycleTimer, SIGNAL(timeout()), SLOT(doGameTick()));

  /* for(int r = 0, s = 500; r < 10; r++, s-=2)
        addRect(r, r, s, s, QPen(QColor(10*(10-r), 0, 0)), QBrush(1));
        */
}

void ViewPort::addItem(GameObject* gameItem)
{
    itemList.insert(0, gameItem);
    QGraphicsScene::addItem(gameItem);
}

void ViewPort::startGame()
{
    addItem(new Ship(WIDTH/2, HEIGHT/2, this));
    cycleTimer->start(33);
}

void ViewPort::doGameTick()
{
    GameObject* object;
    int currSize = itemList.size();

    for(int i = 0; i <= currSize - 1; i++)
    {
        object = itemList.at(i);
        object->updatePosition();
        if(object->pos().x() > WIDTH || object->pos().x() < 0 || object->pos().y() > HEIGHT || object->pos().y() < 0)
        {
            currSize--;
            i--;
            itemList.remove(i);
            delete object;
        }
    }

    std::cout << "Did game cycle!";
}
