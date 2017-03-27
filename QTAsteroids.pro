#-------------------------------------------------
#
# Project created by QtCreator 2017-03-17T11:21:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTAsteroids
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewport.cpp \
    ship.cpp \
    gameobject.cpp

HEADERS  += mainwindow.h \
    viewport.h \
    ship.h \
    globals.h \
    gameobject.h
