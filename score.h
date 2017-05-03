#ifndef SCORE_H
#define SCORE_H

#endif // SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{

public:
    Score(QGraphicsItem * parent = 0);
    void increase(int);
    int getScore();
    void clear();

private:
    int score;

};
