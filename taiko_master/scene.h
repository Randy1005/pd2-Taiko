#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTGui>
#include <QSound>
#include "button.h"
#include "rail.h"
#include "lol_face.h"
#include "bigi.h"
#include "mash_pt.h"
#include "instr.h"
#include "cntdwn.h"
#include "clock.h"
#include "score.h"



class Scene: public QGraphicsScene
{
    Q_OBJECT

public:
    /* member functions */
    Scene();
    void init(); //screen initialize
    void bgChange(); //For background changing from start menu to game
    void bgResult(); //At last we show the result
    void backToMenu(); //go to main menu
    void resultToMenu();
    void gameInit(); //start running these bigi faces
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //For clicking buttons
    void geneBigi(); //generates bigiface
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event); //For calculating scores. If I write the score-calculating function in keyPressEvent, then it fails because I have a for loop inside it.




    /* variables */
    // buttons
    Button *btn_start;
    int btn_w_start;
    int btn_h_start;
    Button *btn_exit;
    int btn_w_exit;
    int btn_h_exit;
    Button *btn_restart;
    int btn_w_restart;
    int btn_h_restart;
    Button *btn_exit_last;
    int btn_w_exitLast;
    int btn_h_exitLast;

    // game items
    Lol_face *lol_face;
    Rail *rail;
    Mash_pt *mash;
    Bigi *madIn;
    Bigi *hornyIn;
    Bigi *laughIn;
    Bigi *cryIn;
    Instr *s;
    Instr *d;
    Instr *k;
    Instr *l;
    Clock *clock;
    Score *scoreboard;
    QGraphicsPixmapItem *score_logo;
    Score *finalScore;


    //For storing the number of items before eliminating on screen
    int bigi_list_cnt;
    //For storing lots of bigi faces
    QList<Bigi *> bigi_list;
    QList<int> rand_list;

    //countdiwnTImer   For storing text 30,29,28,......,1
    QList<Cntdwn *> cntdwn_list;
    Cntdwn *cntdwn_num;
    int i = 28;

    //timer for animation
    QTimer *gametimer;
    QTimer *cntdwnTmr;

    //control scene page
    int screenMode;

    //sound
    QSound *wrong;
    QSound *gayee;
    QSound *gotcha;
    QSound *huwaa;
    QSound *headshot;
    QSound *bgm;


public slots:
    //for qtimer to connect and change the text per second for countdownTimer
   void secDecrease();

};

#endif // SCENE_H
