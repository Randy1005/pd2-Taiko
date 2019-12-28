#ifndef CNTDWNSCENE_H
#define CNTDWNSCENE_H

#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTGui>
#include "cntdwn.h"

class CntDwnScene: public QGraphicsScene
{
    Q_OBJECT

public:
    //For storing text 30,29,28,......,1
    QList<Cntdwn *> cntdwn_list;

    void showTimer();


public slots:

};

#endif // CNTDWNSCENE_H
