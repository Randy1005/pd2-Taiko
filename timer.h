#ifndef TIMER_H
#define TIMER_H

#include <QTCore>
#include <QTimer>
#include <QLabel>

class Timer: public QObject
{
    Q_OBJECT
public:
   Timer();
   int sec;
   QLabel *cntSec;
};

#endif // TIMER_H

