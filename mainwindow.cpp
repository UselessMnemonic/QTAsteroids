#include "mainwindow.h"
#include "viewport.h"
#include "ship.h"
#include "globals.h"
#include <QGraphicsView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    //Add viewport
    mainViewport = new ViewPort();
    view = new QGraphicsView(mainViewport);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFrameStyle(0);
    view->setFixedSize(BASE_SIZE, BASE_SIZE);
    view->setSceneRect(0, 0, BASE_SIZE, BASE_SIZE);

    setCentralWidget(view);

    //make window fixed size
    setFixedSize(BASE_SIZE, BASE_SIZE);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt:: ScrollBarAlwaysOff);
    //create game menu
    QMenu* gameMenu = menuBar()->addMenu("&Game");

    //create open and new actions
    gameMenu->addAction("&Start", this, SLOT(startGame()));
    gameMenu->addAction("&Quit", this, SLOT(close()));

}

MainWindow::~MainWindow()
{
}


void MainWindow::startGame()
{
   mainViewport->startGame();
}
