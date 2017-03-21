#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsItem>

class Ship : public QGraphicsItem
{
public:
  Ship( qreal, qreal );                          // constructor

  void     paint( QPainter*,
                  const QStyleOptionGraphicsItem*,
                  QWidget* );                       // implement virtual paint function
  QRectF   boundingRect() const
    { return QRectF(-15, 0, 30, 30 ); }           // implement virtual boundingRect

private:
  QPoint geometry[4] = {QPoint(0, 0), QPoint(15, 30), QPoint(0, 24), QPoint(-15, 30)};
};

#endif // SHIP_H
