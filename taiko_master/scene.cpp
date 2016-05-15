#include "scene.h"
#include <QTime>
#include <QGraphicsPixmapItem>
#include <QFont>
//#include <QTest>   /*if you want to use "qWait"*/

Scene::Scene()
{
    screenMode = 0;
}

void Scene::init()
{
    /*add sound*/
    gayee = new QSound(":sound/sound/hah_gayee.wav");
    gotcha = new QSound(":sound/sound/gotcha.wav");
    huwaa = new QSound(":sound/sound/huwaa.wav");
    wrong = new QSound(":sound/sound/wrong.wav");
    headshot = new QSound(":sound/sound/headshot.wav");

    /*add start button*/
    btn_start = new Button();
    QPixmap start;
    start.load(":/image/pics/start_btn");
    start = start.scaled(start.width()*1.2,start.height()*1.2,Qt::KeepAspectRatio);
    btn_w_start = start.width();
    btn_h_start = start.height();
    btn_start->setPixmap(start);
    btn_start->setPos(280,280);
    addItem(btn_start);

    /*add exit button*/
    btn_exit = new Button();
    QPixmap exit;
    exit.load(":/image/pics/exit_btn");
    exit = exit.scaled(exit.width()*0.25,exit.height()*0.25,Qt::KeepAspectRatio);
    btn_w_exit = exit.width();
    btn_h_exit = exit.height();
    btn_exit->setPixmap(exit);
    btn_exit->setPos(10,20);
    addItem(btn_exit);

    i = 28;
}


/******PROBLEM: game starts a bit slow, needs optimization******/
void Scene::bgChange()
{
    /*change the background picture first*/
    QImage bg;
    bg.load(":/image/pics/game_bg.jpg"); //load the in-game picture
    bg = bg.scaled(780,580);
    this->setBackgroundBrush(bg);

    /*then remove the start button*/
    this->removeItem(btn_start);
    this->removeItem(btn_exit);

    /*add the rail*/
    rail = new Rail();
    QPixmap rail_pic;
    rail_pic.load(":/image/pics/rail.png");
    rail_pic = rail_pic.scaled(800,400,Qt::KeepAspectRatio);
    rail->setPixmap(rail_pic);
    rail->setPos(0,200);
    this->addItem(rail);

    /*add the lol_face on right-side*/
    lol_face = new Lol_face();
    QPixmap lol_pic;
    lol_pic.load(":/image/pics/lol_face.png");
    lol_pic = lol_pic.scaled(400,400,Qt::KeepAspectRatio);
    lol_face->setPixmap(lol_pic);
    lol_face->setPos(620,20);
    this->addItem(lol_face);

    /*add the mash_pt image, or else we cannot judge when to hit keys*/
    mash = new Mash_pt();
    QPixmap mash_pic;
    mash_pic.load(":/image/pics/mash_pt.png");
    mash_pic = mash_pic.scaled(90,90,Qt::KeepAspectRatio);
    mash->mash_pt_w = mash_pic.width(); //store the width of mash_pt
    mash->setPixmap(mash_pic);
    mash->setPos(138,225);
    this->addItem(mash);

    /*add instructions, in case we don't know what key to press*/

    //mad face instruction
    madIn = new Bigi();
    QPixmap mad_pic;
    mad_pic.load(":/image/pics/bigiface.png");
    mad_pic = mad_pic.scaled(100,100,Qt::KeepAspectRatio);
    madIn->setPixmap(mad_pic);
    madIn->setPos(60,450);
    this->addItem(madIn);

    s = new Instr();
    QPixmap s_pic;
    s_pic.load(":/image/pics/s");
    s_pic = s_pic.scaled(60,60,Qt::KeepAspectRatio);
    s->setPixmap(s_pic);
    s->setPos(40,440);
    this->addItem(s);

    //horny face instruction
    hornyIn = new Bigi();
    QPixmap horny_pic;
    horny_pic.load(":/image/pics/hornyface.png");
    horny_pic = horny_pic.scaled(100,100,Qt::KeepAspectRatio);
    hornyIn->setPixmap(horny_pic);
    hornyIn->setPos(260,450);
    this->addItem(hornyIn);

    d = new Instr();
    QPixmap d_pic;
    d_pic.load(":/image/pics/D");
    d_pic = d_pic.scaled(55,55,Qt::KeepAspectRatio);
    d->setPixmap(d_pic);
    d->setPos(240,440);
    this->addItem(d);

    //laugh face instruction
    laughIn = new Bigi();
    QPixmap laugh_pic;
    laugh_pic.load(":/image/pics/laugh.png");
    laugh_pic = laugh_pic.scaled(100,100,Qt::KeepAspectRatio);
    laughIn->setPixmap(laugh_pic);
    laughIn->setPos(460,450);
    this->addItem(laughIn);

    k = new Instr();
    QPixmap k_pic;
    k_pic.load(":/image/pics/k");
    k_pic = k_pic.scaled(55,55,Qt::KeepAspectRatio);
    k->setPixmap(k_pic);
    k->setPos(430,440);
    this->addItem(k);

    //cry face instruction
    cryIn = new Bigi();
    QPixmap cry_pic;
    cry_pic.load(":/image/pics/cry.png");
    cry_pic = cry_pic.scaled(100,100,Qt::KeepAspectRatio);
    cryIn->setPixmap(cry_pic);
    cryIn->setPos(660,450);
    this->addItem(cryIn);

    l = new Instr();
    QPixmap l_pic;
    l_pic.load(":/image/pics/l");
    l_pic = l_pic.scaled(60,60,Qt::KeepAspectRatio);
    l->setPixmap(l_pic);
    l->setPos(640,440);
    this->addItem(l);

    /*add the countdown timer*/
    /*CAUTION: THIS METHOD SUCKS*/

    //first add the clock icon
    clock = new Clock();
    QPixmap clock_pic;
    clock_pic.load(":/image/pics/Clock.png");
    clock_pic = clock_pic.scaled(70,70,Qt::KeepAspectRatio);
    clock->setPixmap(clock_pic);
    clock->setPos(180,40);
    this->addItem(clock);

    /*store the text 1-30 in a QList*/
    for(int i=0;i<30;i++)
    {
        QString str;
        str = QString("%1").arg(i);
        cntdwn_num = new Cntdwn();
        cntdwn_num->setPlainText(str);
        cntdwn_num->setFont(QFont("Courier",QFont::Bold,26));
        cntdwn_num->setPos(250,30);
        cntdwn_num->setDefaultTextColor("yellow");
        cntdwn_list.push_back(cntdwn_num);
    }
    this->addItem(cntdwn_list.at(29)); //add a "30" text first then remove it after 1 second

    cntdwnTmr = new QTimer(this);
    connect(cntdwnTmr,SIGNAL(timeout()),this,SLOT(secDecrease()));
    cntdwnTmr->start(1000);


    /*add the score*/
    scoreboard = new Score();
    scoreboard->setPos(400,30);
    this->addItem(scoreboard);

    /*add the bigi faces(call geneBigi() then start taking stuff out of the bigi list)*/
    qsrand(1); //set the seed
    geneBigi(); //generate bigi faces
    for(int i=0;i<40;i++)
    {
        bigi_list[i]->setPos(820+450*i,230); //put them in line, distance = 450 each bigi face
        this->addItem(bigi_list[i]);
    }
    gameInit(); //run the timer, start animation

}

void Scene::resultToMenu()
{
    //disconnect(gametimer,SIGNAL(timeout()),this,SLOT(advance()));
    //disconnect(cntdwnTmr,SIGNAL(timeout()),this,SLOT(secDecrease()));
    /*remove all the items*/
    this->removeItem(btn_restart);
    this->removeItem(btn_exit_last);
    this->removeItem(score_logo);
    this->removeItem(finalScore);

    /*change the bg back to menu*/
    QImage bg;
    bg.load(":/image/pics/start_bg");
    bg = bg.scaled(780,580);
    this->setBackgroundBrush(bg);

    this->init();
}

void Scene::gameInit()
{
    //set up a timer to control items(here's where the animation is made)
    gametimer = new QTimer(this);
    connect(gametimer,SIGNAL(timeout()),this,SLOT(advance()));
    /*
     * first we jump to the nextline and see that the start function has the parameter "time interval", so it means it
     * emits the "timeout" signal per 10 milliseconds, and advance function catches the signal then executes what's
     * inside advance function
     */
    gametimer->start(10);
}

void Scene::bgResult()
{
    screenMode = 2;
    /*remove all the items*/
    this->removeItem(rail);
    this->removeItem(lol_face);
    this->removeItem(madIn);
    this->removeItem(hornyIn);
    this->removeItem(laughIn);
    this->removeItem(cryIn);
    this->removeItem(s);
    this->removeItem(d);
    this->removeItem(k);
    this->removeItem(l);
    this->removeItem(mash);
    this->removeItem(clock);
    this->removeItem(scoreboard);

    /*remove the countdown timer*/
    foreach (Cntdwn *i,cntdwn_list)
    {
        this->removeItem(i);
        cntdwn_list.removeOne(i);
    }

    /*remove the faces*/
    foreach (Bigi *i,bigi_list)
    {
        this->removeItem(i);
        bigi_list.removeOne(i);
    }

    /*add the restart button*/
    btn_restart = new Button();
    QPixmap restart;
    restart.load(":/image/pics/restart");
    restart = restart.scaled(restart.width()*0.5,restart.height()*0.5,Qt::KeepAspectRatio);
    btn_w_restart = restart.width();
    btn_h_restart = restart.height();
    btn_restart->setPixmap(restart);
    btn_restart->setPos(90,400);
    addItem(btn_restart);

    /*add the exit button*/
    btn_exit_last = new Button();
    QPixmap exitLast;
    exitLast.load(":/image/pics/exit_blue");
    exitLast = exitLast.scaled(exitLast.width()*0.25,exitLast.height()*0.25,Qt::KeepAspectRatio);
    btn_w_exitLast = exitLast.width();
    btn_h_exitLast = exitLast.height();
    btn_exit_last->setPixmap(exitLast);
    btn_exit_last->setPos(570,410);
    addItem(btn_exit_last);

    /*add the score*/
    finalScore = new Score();
    finalScore->setPos(350,470);
    finalScore->setPlainText(QString::number(scoreboard->score));
    finalScore->setFont(QFont("Courier",28));
    finalScore->setDefaultTextColor("blue");
    this->addItem(finalScore);

    /*add the score logo*/
    score_logo = new QGraphicsPixmapItem();
    QPixmap sc;
    sc.load(":/image/pics/finalScore.png");
    sc = sc.scaled(180,60,Qt::KeepAspectRatio);
    score_logo->setPixmap(sc);
    score_logo->setPos(330,400);
    this->addItem(score_logo);


    if(scoreboard->score <= 40)
    {
       /*change the bg to suck background*/
        QImage bg;
        bg.load(":/image/pics/suck.jpg");
        bg = bg.scaled(780,580);
        this->setBackgroundBrush(bg);      
    }
    else
    {  
        /*change the bg to goodjob background*/
        QImage bg;
        bg.load(":/image/pics/good_job.jpg");
        bg = bg.scaled(780,580);
        this->setBackgroundBrush(bg);
    }
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode==0)
    {
        //now we're in the beginning page, let's see if the cursor x-coordinate is inside button range
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_w_start)
        {
            //now the cursor x coordinate is in range, let's judge y coordinate
            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h_start)
            {
                //cursor x,y coordinate both in button area
                cout<<"start game"<<endl;
                //clear background,switch screenMode
                bgChange();
                screenMode = 1;
            }

        }

        //if we're using the exit button
        else if(event->scenePos().x() > btn_exit->pos().x() && event->scenePos().x() <= btn_exit->pos().x()+btn_w_exit)
        {
            //now the cursor x coordinate is in range, judge y coordinate
            if(event->scenePos().y() > btn_exit->pos().y() && event->scenePos().y() <= btn_exit->pos().y()+btn_h_exit)
            {
                //cursor x,y coordinate both in exit button area
                cout<<"exit game"<<endl;
                //exit application
                QApplication::exit();
            }
        }

    }

    //if now we're in the result background
    if(screenMode==2)
    {
        if(event->scenePos().x() > btn_restart->pos().x() && event->scenePos().x() <= btn_restart->pos().x()+btn_w_restart)
        {
            if(event->scenePos().y() > btn_restart->pos().y() && event->scenePos().y() <= btn_restart->pos().y()+btn_h_restart)
            {
                cout<<"restart"<<endl;
                resultToMenu();
                screenMode = 0;
            }
        }
        else if(event->scenePos().x() > btn_exit_last->pos().x() && event->scenePos().x() <= btn_exit_last->pos().x()+btn_w_exit)
        {
            if(event->scenePos().y() > btn_exit_last->pos().y() && event->scenePos().y() <= btn_exit_last->pos().y()+btn_h_exit)
            {
                cout<<"exit game"<<endl;
                QApplication::exit();
            }
        }
    }

}

void Scene::geneBigi()
{
    for(int i=0;i<40;i++)
    {
        rand_list.push_back(qrand()%4+1); //store these numbers
    }

    //generate random bigi faces and store in bigi list, based on the random numbers
    for(int i=0;i<40;i++)
    {
        if(rand_list[i]==1)
        {
            Bigi *mad = new Bigi();
            QPixmap mad_pic;
            mad_pic.load(":/image/pics/bigiface.png");
            mad_pic = mad_pic.scaled(80,80,Qt::KeepAspectRatio);
            mad->setPixmap(mad_pic);
            mad->setSpeed(1);
            bigi_list.push_back(mad);
        }
        else if(rand_list[i]==2)
        {
            Bigi *horny = new Bigi();
            QPixmap horny_pic;
            horny_pic.load(":/image/pics/hornyface.png");
            horny_pic = horny_pic.scaled(80,80,Qt::KeepAspectRatio);
            horny->setPixmap(horny_pic);
            horny->setSpeed(1);
            bigi_list.push_back(horny);
        }
        else if(rand_list[i]==3)
        {
            Bigi *laugh = new Bigi();
            QPixmap laugh_pic;
            laugh_pic.load(":/image/pics/laugh.png");
            laugh_pic = laugh_pic.scaled(80,80,Qt::KeepAspectRatio);
            laugh->setPixmap(laugh_pic);
            laugh->setSpeed(1);
            bigi_list.push_back(laugh);
        }
        else if(rand_list[i]==4)
        {
            Bigi *cry = new Bigi();
            QPixmap cry_pic;
            cry_pic.load(":/image/pics/cry.png");
            cry_pic = cry_pic.scaled(80,80,Qt::KeepAspectRatio);
            cry->setPixmap(cry_pic);
            cry->setSpeed(1);
            bigi_list.push_back(cry);
        }
    }

}

void Scene::keyPressEvent(QKeyEvent *event)
{
    for(int i=0;i<bigi_list.size();i++)
    {
        if(bigi_list.at(i)->pos().x() > mash->pos().x() && bigi_list.at(i)->pos().x() <= mash->pos().x() + mash->mash_pt_w)
        {
            if(rand_list[i]==1) //if encoounter "mad" face
            {
                if(event->key()==Qt::Key_S)
                {
                    this->removeItem(bigi_list.at(i));
                    bigi_list.removeAt(i);
                    rand_list.removeAt(i);
                    break;
                }
                else
                    wrong->play();

            }
            if(rand_list[i]==2) //if encoounter "horny" face
            {
                if(event->key()==Qt::Key_D)
                {
                    this->removeItem(bigi_list.at(i));
                    bigi_list.removeAt(i);
                    rand_list.removeAt(i);
                    break;
                }
                else
                    wrong->play();

            }
            if(rand_list[i]==3) //if encoounter "laugh" face
            {
                if(event->key()==Qt::Key_K)
                {
                    this->removeItem(bigi_list.at(i));
                    bigi_list.removeAt(i);
                    rand_list.removeAt(i);
                    break;
                }
                else
                    wrong->play();
            }
            if(rand_list[i]==4) //if encoounter "cry" face
            {
                if(event->key()==Qt::Key_L)
                {
                    this->removeItem(bigi_list.at(i));
                    bigi_list.removeAt(i);
                    rand_list.removeAt(i);
                    break;
                }
                else
                    wrong->play();
            }
        }
    }
}



void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_S) || (event->key() == Qt::Key_D) || (event->key() == Qt::Key_K) || (event->key() == Qt::Key_L))
    {
        if(scoreboard->relativeNum - bigi_list.size() == 1)
        {
            scoreboard->increase();
            scoreboard->relativeNum--;

            /*add sound*/
            if(event->key() == Qt::Key_S)
                huwaa->play();

            if(event->key() == Qt::Key_D)
                gotcha->play();

            if(event->key() == Qt::Key_K)
                huwaa->play();

            if(event->key() == Qt::Key_L)
                headshot->play();

        }
    }
}


void Scene::secDecrease()
{
    if(i>0)
    {
        this->addItem(cntdwn_list.at(i)); //remove previous text displaying seconds
        this->removeItem(cntdwn_list.at(i+1)); //add the next text displaying seconds
        i--;
    }
    else
    {
        /*if i(defined in scene.h) decreases to -1, then timer is stopped and we call bgResult*/
        gametimer->stop();
        cntdwnTmr->stop();
        cout<<"timer stopped"<<endl;
        bgResult();
    }
}

