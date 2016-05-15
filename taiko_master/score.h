#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score: public QGraphicsTextItem
{
public:
    Score();
    void increase();
    int relativeNum;
    int score;

};


#endif // SCORE_H