#include "mainwindow.h"
#include "globals.h"
#include <QApplication>
#include <QtMath>
#include <QDebug>
#include <QScreen>
#include <string>

/* Aryan Khachikian
 * Ulysses Villegas
 * Richard Mojarro
 * Arrissa Calvillo
 * Christopher Madrigal
 * Group 3
 */

/*Entry point for QTAsteroids game
 * Simple but well paced game of asteroids soon to have neat graphics, sounds, and user prefernces
 */

//TODO Preferences


int main(int argc, char *argv[])
{

    //calculate sines and cosines for integer degrees between 0 and 359
    for(int x = 0; x <= 359; x++)
    {
        SINES[x] = (float)sin(M_PI/180 * x);
        COSINES[x] = (float)cos(M_PI/180 * x);
    }

    QApplication a(argc, argv);

    QSize size = qApp->screens()[0]->size();;
    int height = size.height();
    int width = size.width();

    if(height > width)
        BASE_SIZE = width-100;
    else
        BASE_SIZE = height-100;

    MainWindow w;
    w.show();
    return a.exec();
}
