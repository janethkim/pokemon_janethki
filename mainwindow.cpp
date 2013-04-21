#include "mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow()
{
  window = new QWidget;
  window->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
  scene = new QGraphicsScene;
  view = new QGraphicsView(scene, window);
  view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
  timer = new QTimer(this);
  bgPic = new QPixmap("Images/game-background.jpg");
  bg_1 = new Background(bgPic, 0, 0);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );
  
  view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  
  stand = new QPixmap("Images/picturesforrunningplayer/standing.png");
  stand->scaled(50, 50);
  left = new QPixmap("Images/picturesforrunningplayer/runleft.png");
  right = new QPixmap("Images/picturesforrunningplayer/runright.png");
  left->scaled(50, 50);
  right->scaled(50, 50);
  user = new Player(stand, left, right, 100, 300);
  
  scene->addItem(user);
  
  timer->setInterval(5);
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer())); 
//  window->addWidget( view );
}

MainWindow::~MainWindow()
{
  timer->stop();
  delete window;
  delete timer;
}

void MainWindow::show()
{
  timer->start();
  window->show();
}

void MainWindow::handleTimer()
{
  bg_1->move(WINDOW_MAX_X, WINDOW_MAX_Y); 
  bg_2->move(WINDOW_MAX_X, WINDOW_MAX_Y);
  user->move(WINDOW_MAX_X, WINDOW_MAX_Y);
}
