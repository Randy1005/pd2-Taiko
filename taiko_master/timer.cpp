#include "timer.h"

Timer::Timer()
{
    sec = 30;
    cntSec->setText(QString::number(sec));
}
