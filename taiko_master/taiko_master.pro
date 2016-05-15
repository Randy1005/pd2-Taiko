#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T13:36:26
#
#-------------------------------------------------

QT       += core gui
QT       += testlib
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko_master
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    button.cpp \
    rail.cpp \
    lol_face.cpp \
    bigi.cpp \
    mash_pt.cpp \
    instr.cpp \
    cntdwn.cpp \
    clock.cpp \
    score.cpp

HEADERS  += mainwindow.h \
    scene.h \
    button.h \
    rail.h \
    lol_face.h \
    bigi.h \
    mash_pt.h \
    instr.h \
    cntdwn.h \
    clock.h \
    score.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
