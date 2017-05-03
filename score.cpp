#include "score.h"
#include <QFont>
#include <QDebug>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the score to 0
    score = 0;

//Draw the score
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white); //score color
    setFont(QFont("Ariel",14));
}

void Score::increase(int amt)
{
    score += amt;
    qDebug() << "added to score";
    this->setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore()
{
    return score;
}


void Score::clear()
{
    score = 0;
    this->setPlainText(QString("Score: ") + QString::number(score));
    qDebug() << "score clear";
}
