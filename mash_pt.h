#ifndef MASH_PT_H
#define MASH_PT_H

#include <QGraphicsPixmapItem>

class Mash_pt: public QGraphicsPixmapItem
{
public:
    Mash_pt();
    int mash_pt_w; //for eliminating bigi faces (will need to judge x position)
};

#endif // MASH_PT_H
