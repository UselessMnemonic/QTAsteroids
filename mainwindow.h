#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewport.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    ViewPort* mainViewport;
    QGraphicsView* view;
    bool gameStarted;

private slots:
    void startGame();
};

#endif // MAINWINDOW_H
