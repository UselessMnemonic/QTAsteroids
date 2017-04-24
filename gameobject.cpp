#include "gameobject.h"
#include "globals.h"
#include "asteroid.h"
#include "bullet.h"
#include "ship.h"
#include "viewport.h"
#include <QPainter>
#include <typeinfo>
#include <QDebug>
using namespace std;

//constructor that takes x and y coordinates
GameObject::GameObject(qreal x, qreal y) : QGraphicsItem()
{
    setPos(x, y);
    rotation = 0;
    setRotation(rotation);
    velocity = QVector2D(0,0);
}

//default constructor for game object
GameObject::GameObject() : GameObject(0,0)
{
}

//constructor that takes a QPointF
GameObject::GameObject(QPointF loc) : GameObject(loc.x(), loc.y())
{
}

//default update function that sets the object's position

/********************** possible place to input collision detection **************/
//This works only on asteroids-asteroids or asteroids-bullets.
//The reason why is because both asteroid and bullets call the default
//update() function listed below in doGameTick();
//
void GameObject::update()
{
    setRotation(rotation);
    setPos(pos() + velocity.toPointF());

    //collidingItems() returns a list of QgraphicsItem pointers
    //which have collided. They are then put into a list.
    QList<QGraphicsItem * > collidedItems = collidingItems();

    //default collision algorithm
    if(!getHitState())
    for(int i = 0, n = collidedItems.size(); i<n; i++)
    {
        //checks if an item in the list at [i] is a bullet
        //if it is, then removes the bullet and the calling object
        // ******************* IMPORTANT **********************
        //This allows for bullet-asteroid relationship only
        // if you wish to have bullet-asteroid AND asteroid-asteroid
        // change the typeid from bullet to asteroid.
        //*****************************************************
        if( typeid(*(collidedItems[i])) == typeid(Bullet) )
        {
            static_cast<Bullet *>(collidedItems[i])->setHitState(true);
            this->setHitState(true);
        }
    }

}

void GameObject::setHitState(bool x){
    hitState = x;
}

bool GameObject::getHitState(){
    return hitState;
}

//default paint function that draws the bounding box and velocity vector of the object
void GameObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::blue));
    painter->rotate(-rotation);

    if(SHOW_BOUNDS)
    {
        painter->drawRect(this->boundingRect());
    }

    if(SHOW_TRAJECTORIES)
    {
        painter->drawLine(QPointF(0,0), (velocity*3).toPointF());
    }
}
