#include "mainwindow.h"
#include "globals.h"
#include <QApplication>
#include <QtMath>
#include <QDebug>
#include <string>

/* Aryan Khachikian
 * Ulysses Villegas
 * Richard Mojarro
 * Arrissa Calvillo
 * Christopher Madrigal
 * Group 3
 */

float SINES[359];
float COSINES[359];
int SIZE = 500;
int PADDING = 5;

int main(int argc, char *argv[])
{

    //calculate sines and cosines for integer degrees between 0 and 359
    for(int x = 0; x <= 359; x++)
    {
        SINES[x] = (float)sin(M_PI/180 * x);
        COSINES[x] = (float)cos(M_PI/180 * x);
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
