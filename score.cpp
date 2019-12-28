#include "score.h"

Score::Score()
{
    //initialize the score
    score = 0;
    relativeNum = 40; //relativeNum is for checking how many bigifaces I removed

    //draw the text
    setPlainText(QString("Score: ") + QString::number(score));//looks like "Score: 0"
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Courier",20));
}

void Score::increase()
{
    score+=5;
    setPlainText(QString("Score: ") + QString::number(score));//looks like "Score: 5"
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Courier",20));
}
