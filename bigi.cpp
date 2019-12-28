#include "bigi.h"

Bigi::Bigi()
{
    //initialize
    setSpeed(0);
}

Bigi::~Bigi()
{
    setSpeed(0);
}

void Bigi::advance(int phase)
{
    //moves the ball, receives SIGNAL from timeout, see gameInit function
    this->setPos(this->pos().x()+x_speed,this->pos().y());
}

void Bigi::setSpeed(int speed)
{
    x_speed = -speed;
}






