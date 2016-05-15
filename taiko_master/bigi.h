#ifndef BIGI_H
#define BIGI_H

#include <QGraphicsPixmapItem>
#include <iostream>
using namespace std;

class Bigi: public QGraphicsPixmapItem
{
public:
    Bigi();
    ~Bigi();
    //For Bigiface
    int x_speed;
    //For animation
    void advance(int phase);
    void setSpeed(int speed);
};

#endif // BIGI_H
