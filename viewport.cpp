#include "viewport.h"
#include "ship.h"
#include "globals.h"
#include "asteroid.h"
#include "time.h"
#include <QDebug>

//draws bounding rectangle and creates frame timer
ViewPort::ViewPort() : QGraphicsScene()
{
   addLine(0,0,0,1, QPen(Qt::transparent, 1));

    if(SHOW_BOUNDS)
        addRect(0,0,BASE_SIZE,BASE_SIZE, QPen(Qt::blue));

    setBackgroundBrush(QBrush(Qt::black));

    //set up timer to control game stepping
    cycleTimer = new QTimer(this);
    connect(cycleTimer, SIGNAL(timeout()), this, SLOT(doGameTick()));
    spawnCooldown = 0;
  /* for(int r = 0, s = 500; r < 10; r++, s-=2)
        addRect(r, r, s, s, QPen(QColor(10*(10-r), 0, 0)), QBrush(1));
        */
}

//adds a GameObject into the scene and object list
void ViewPort::addItem(GameObject* gameItem)
{
    itemList.insert(0, gameItem);
    QGraphicsScene::addItem(gameItem);
}

//sets up ship and starts timer
void ViewPort::startGame()
{
    Ship* ship = new Ship(BASE_SIZE/2, BASE_SIZE/2, this);
    addItem(ship);
    QGraphicsScene::setFocusItem(ship);
    ship->grabKeyboard();
    cycleTimer->start(33);
}

//timer event; calls update() on all game objects and (will check) collision
void ViewPort::doGameTick()
{
    spawnAsteroid();

    GameObject* object;
    int currSize = itemList.size();

    //destroys game objects when they have flown off screen
    for(int i = 0; i <= currSize-2; i++)
    {
        object = itemList.at(i);
        object->update();

        if(object->pos().x() > BASE_SIZE || object->pos().x() < 0 || object->pos().y() > BASE_SIZE || object->pos().y() < 0)
        {
            itemList.remove(i);
            delete object;
            currSize--;
            i--;
        }
    }

    //special wraping case for ship
    wrapShip();
}

void ViewPort::wrapShip()
{
    GameObject* obj;
    obj = itemList.at(itemList.size()-1);
    obj->update();

    if(obj->x() > BASE_SIZE)
        obj->setX(0);
    else if(obj->x() < 0)
        obj->setX(BASE_SIZE);

    if(obj->y() > BASE_SIZE)
        obj->setY(0);
    else if(obj->y() < 0)
        obj->setY(BASE_SIZE);
}

//algorithm for spawning asteroids
//TODO find better algorithm
void ViewPort::spawnAsteroid()
{
    if(spawnCooldown == 0)
    {
        if(rand()%50 == 1)
        {
            int tb, x, y;
            tb = rand() % 2;

            if(tb)
            {
              y = rand() % 2;
              y *= BASE_SIZE;
              x = rand() % BASE_SIZE;
            }
            else
            {
              x = rand() % 2;
              x *= BASE_SIZE;
              y = rand() % BASE_SIZE;
            }

            addItem(new Asteroid(x, y));

            qDebug() << "added asteroid";
            spawnCooldown = 5;
        }
    }
    else
        spawnCooldown--;
}
