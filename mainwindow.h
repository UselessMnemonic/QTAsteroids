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

protected:
     ViewPort* mainViewport;

private:
    QGraphicsView* view;

private slots:
    void startGame();
};

#endif // MAINWINDOW_H
