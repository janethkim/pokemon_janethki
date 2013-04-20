#include "mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow()
{
  window = new QWidget;
  scene = new QGraphicsScene;
  view = new QGraphicsView(scene);
  timer = new QTimer;
}

MainWindow::~MainWindow()
{
  delete window;
  delete timer;
}
