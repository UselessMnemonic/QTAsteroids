#include "mainwindow.h"
#include <QApplication>

/* Aryan Khachikian
 * Ulysses Villegas
 * Richard Mojarro
 * Arrissa Calvillo
 * Christopher Madrigal
 * Group 3
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
