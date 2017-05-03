#include "prize.h"
#include "globals.h"
#include "ship.h"
#include <QPainter>
#include <QtMath>
#include <typeinfo>

// Default constructor - every bullet should
// spawn with a fixed size, fixed velocity with direction of ship
Prize::Prize(QPointF loc) : GameObject(loc)
{
    rotation = 0;
    setRotation(rotation);
    velocity = QVector2D(0,0);
    hitState = false;
    t = 0;
}

//draws a prize
void Prize::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    float g = cos(t) + 1;
    float b = sin(t) + 1;
    g/=2;
    b/=2;
    g *= 255;
    b *= 255;

    painter->setPen( QPen(QColor(0, (int)g, (int)b), 1) );
    painter->drawRect(QRect(-4,-4,8,8));
    painter->drawLine(QLine(0, -4, 0, 4));
    painter->drawLine(QLine(-4, 0, 4, 0));
    GameObject::paint(painter, options, widget);
}

void Prize::update()
{

    t += 5;

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
        if( typeid(*(collidedItems[i])) == typeid(Ship) )
        {
            setHitState(true);
        }
    }

}
