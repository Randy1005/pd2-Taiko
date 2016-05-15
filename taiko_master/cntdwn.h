#ifndef CNTDWN_H
#define CNTDWN_H

#include <QGraphicsTextItem>
#include <QString>

class Cntdwn: public QGraphicsTextItem
{
    Q_OBJECT

public:
    Cntdwn();
    int sec;


};

#endif // CNTDWN_H
