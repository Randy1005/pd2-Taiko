#include "horny.h"

Horny::Horny()
{
    //initialize
    x_speed = 0;
}

Horny::~Horny()
{

}

void Horny::advance(int phase)
{
    //moves the ball, receives SIGNAL from timeout, see gameInit function
    this->setPos(this->pos().x()+x_speed,this->pos().y());
}

void Horny::setSpeed(int speed)
{
    x_speed = -speed;
}

