#include "viewport.h"
#include "ship.h"
#include "globals.h"
#include "asteroid.h"
#include "time.h"
#include <typeinfo>
#include <QList>
#include <QGraphicsItem>
#include <QDebug>

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
    for(int i = 0; i <= itemList.size()-1; i++)
        removeItem(itemList[i]);

    itemList.clear();

    Ship* ship = new Ship(BASE_SIZE/2, BASE_SIZE/2, this);
    addItem(ship);
    QGraphicsScene::setFocusItem(ship);
    ship->grabKeyboard();
    cycleTimer->start(33);
}

//timer event; calls update() on all game objects and (will check) collision

//checks if the object in the list is NULL already and deletes it from list if it is.
//if not then follows regular procedure. If the Object becomes NULL after update()
//then delete
/************ Possible place to put collision detection **************/
void ViewPort::doGameTick()
{
    spawnAsteroid();

    GameObject* object;

    //destroys game objects when they have flown off screen
    //The ship is at the end of the itemList, so to avoid deleting the ship
    //we only traverse the vector up until the element before the ship.
    for(int i = 0; i <= itemList.size()-2; i++)
    {
        //retrieve the object
        object = itemList.at(i);

        //will do what is relevant for the object at the moment
        object->update();
    }

    for(int i = 0; i <= itemList.size()-2; i++)
    {
        object = itemList.at(i);

        if(object->getHitState())
        {

            itemList.remove(i);
            removeItem(object);

            if(typeid(*object) == typeid(Asteroid))
            {
                if ((static_cast<Asteroid *>(object))->split(this))
                {
                    i+=2;
                }
            }
            delete object;
            i--;
            qDebug()<<"Object was deleted from memory!";
        }
        else if(object->pos().x() > BASE_SIZE || object->pos().x() < 0 || object->pos().y() > BASE_SIZE || object->pos().y() < 0)
        {
            itemList.remove(i);
            removeItem(object);
            delete object;
            i--;
         }
    }

    //special wraping case for ship- if it has not been destroyed.
    //ship should be deleted from memory in wrapship()
    wrapShip();
}

void ViewPort::wrapShip()
{
    GameObject* ship;
    ship = itemList.at(itemList.size()-1);
    ship->update();

    if(ship->getHitState())
    {
        itemList.remove(itemList.size()-1);
        removeItem(ship);
        endGame();
    }

    if(ship->x() > BASE_SIZE)
        ship->setX(0);
    else if(ship->x() < 0)
        ship->setX(BASE_SIZE);

    if(ship->y() > BASE_SIZE)
        ship->setY(0);
    else if(ship->y() < 0)
        ship->setY(BASE_SIZE);
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

void ViewPort::endGame()
{
    cycleTimer->stop();
}
