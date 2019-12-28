#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(20,10,760,560);
    setBg();
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBg()
{
    QImage bg;
    bg.load(":/image/pics/start_bg");
    bg = bg.scaled(780,580);
    scene->setBackgroundBrush(bg);
    /* set the initial page */
    scene->init();
}


