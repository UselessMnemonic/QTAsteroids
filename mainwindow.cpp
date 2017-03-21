#include "mainwindow.h"
#include "viewport.h"
#include "ship.h"
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
    setFixedSize(QSize(WIDTH+1, HEIGHT+22));
    //create game menu
    QMenu* gameMenu = menuBar()->addMenu("&Game");

    //create open and new actions
    gameMenu->addAction("&Close", this, SLOT(close()));
    gameMenu->addAction("&Open", this, SLOT(startGame()));

}
//set up canvas here
MainWindow::~MainWindow()
{
}

void MainWindow::startGame()
{
    mainViewport->addItem(new Ship( WIDTH/2 - 1 , HEIGHT/2 - 1 ));
}
