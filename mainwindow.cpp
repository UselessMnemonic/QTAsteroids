#include "mainwindow.h"
#include "viewport.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainViewport = new ViewPort();
    QGraphicsView* view = new QGraphicsView(mainViewport);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFrameStyle(0);
    setCentralWidget(view);
}
//set up canvas here
MainWindow::~MainWindow()
{
}
