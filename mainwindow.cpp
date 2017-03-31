#include "mainwindow.h"
#include "viewport.h"
#include "ship.h"
#include "globals.h"
#include <QGraphicsView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Add viewport
    mainViewport = new ViewPort();
    view = new QGraphicsView(mainViewport);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFrameStyle(0);
    setCentralWidget(view);

    //make window fixed size
    setFixedSize(WIDTH + 1, HEIGHT + 28);

    //create game menu
    QMenu* gameMenu = menuBar()->addMenu("&Game");

    //create open and new actions
    gameMenu->addAction("&Open", this, SLOT(startGame()));
    gameMenu->addAction("&Close", this, SLOT(close()));

    //init vars
    gameStarted = false;

}

MainWindow::~MainWindow()
{
}


void MainWindow::startGame()
{
    //avoid adding extra ships if the game has started
    if(!gameStarted)
        mainViewport->startGame();
}
