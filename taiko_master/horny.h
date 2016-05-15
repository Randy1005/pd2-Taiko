#ifndef HORNY_H
#define HORNY_H

#include <QGraphicsPixmapItem>
#include <iostream>
using namespace std;

class Horny: public QGraphicsPixmapItem
{
public:
    Horny();
    ~Horny();
    //For Hornyface
    int x_speed;
    //For animation
    void advance(int phase);
    void setSpeed(int speed);

};

#endif // HORNY_H
