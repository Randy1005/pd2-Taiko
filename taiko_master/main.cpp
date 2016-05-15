#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /***set window size***/
    QDesktopWidget window;
    int screenW = 800;
    int screenH = 600;
    w.setGeometry(window.screen()->width()/2 - (screenW/2),window.screen()->height()/2 - (screenH/2),screenW,screenH);

    /***set window title and icon***/
    w.setWindowTitle("Taiko Master");
    w.setWindowIcon(QIcon(":/image/pics/icon.png"));
    w.setFixedSize(screenW,screenH);
    w.show();

    return a.exec();
}
