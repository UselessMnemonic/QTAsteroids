#include "mainwindow.h"
#include "globals.h"
#include <QApplication>
#include <QtMath>

/* Aryan Khachikian
 * Ulysses Villegas
 * Richard Mojarro
 * Arrissa Calvillo
 * Christopher Madrigal
 * Group 3
 */

int main(int argc, char *argv[])
{

    //calculate sines and cosines for integer degrees between 0 and 359
    for(int x = 0; x <= 359; x++)
    {
        SINES[x] = sin(M_PI/180 * x);
        COSINES[x] = cos(M_PI/180 * x);
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
