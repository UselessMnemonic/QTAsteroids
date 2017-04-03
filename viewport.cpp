#include "viewport.h"
#include "ship.h"
#include "globals.h"
#include "asteroid.h"
#include "time.h"
#include <QDebug>

ViewPort::ViewPort() : QGraphicsScene()
{
    addLine(0,0,0,1, QPen(Qt::transparent, 1));

    setBackgroundBrush(QBrush(Qt::black));

    //set up timer to control game stepping
    cycleTimer = new QTimer(this);
    connect(cycleTimer, SIGNAL(timeout()), this, SLOT(doGameTick()));
    spawnCooldown = 0;
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
    Ship* ship = new Ship(SIZE/2, SIZE/2, this);
    addItem(ship);
    QGraphicsScene::setFocusItem(ship);
    ship->grabKeyboard();
    cycleTimer->start(33);
}

void ViewPort::doGameTick()
{
    spawnAsteroid();

    GameObject* object;
    int currSize = itemList.size();

    for(int i = 0; i <= currSize-2; i++)
    {
        object = itemList.at(i);
        object->update();

        if(object->pos().x() > SIZE || object->pos().x() < 0 || object->pos().y() > SIZE || object->pos().y() < 0)
        {
            itemList.remove(i);
            delete object;
            currSize--;
            i--;
        }
    }

    wrapShip();
}

void ViewPort::wrapShip()
{
    GameObject* obj;
    obj = itemList.at(itemList.size()-1);
    obj->update();

    if(obj->x() > SIZE)
        obj->setX(0);
    else if(obj->x() < 0)
        obj->setX(SIZE);

    if(obj->y() > SIZE)
        obj->setY(0);
    else if(obj->y() < 0)
        obj->setY(SIZE);
}

void ViewPort::spawnAsteroid()
{
    if(spawnCooldown == 0)
    {
        if(rand()%50 == 1)
        {
            int tb, x, y;
            srand(time(NULL));
            tb = rand() % 2;

            srand(time(NULL));
            if(tb)
            {
              y = rand() % 2;
              y *= SIZE;
              srand(time(NULL));
              x = rand() % SIZE;
            }
            else
            {
              x = rand() % 2;
              x *= SIZE;
              srand(time(NULL));
              y = rand() % SIZE;
            }

            addItem(new Asteroid(x, y));

            qDebug() << "added asteroid";
            spawnCooldown = 5;
        }
    }
    else
        spawnCooldown--;
}
