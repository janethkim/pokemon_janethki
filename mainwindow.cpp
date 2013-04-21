#include "mainwindow.h"
#include <cstdlib>
#include <iostream>
using namespace std;

MainWindow::MainWindow()
{
  window = new QWidget;
//  layout = new QVBoxLayout;
  window->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
//  window->setLayout(layout);
  scene = new QGraphicsScene;
  view = new QGraphicsView(scene, window);
//  view->setFocusPolicy( Qt::NoFocus );
//  layout->addWidget(view);
  view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
  timer = new QTimer(this);
  timer_user = new QTimer(this);
  timer_jump = new QTimer(this);
  bgPic = new QPixmap("Images/game-background.jpg");
  bg_1 = new Background(bgPic, 0, 0);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );
  this->setFocus();
//  setFocus();
//  cout << hasFocus() << endl;
  
  grid = new QGraphicsRectItem(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y-2);
  scene->setSceneRect(grid->rect());
  
  view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  
  stand = new QPixmap("Images/picturesforrunningplayer/standing.png");
  left = new QPixmap("Images/picturesforrunningplayer/runleft.png");
  right = new QPixmap("Images/picturesforrunningplayer/runright.png");
  user = new Player(stand, left, right, 100, 340, this);
  
  scene->addItem(user);
  
  timer_user->setInterval(5);
  connect(timer_user, SIGNAL(timeout()), this, SLOT(handleTimer_user()));
  
  timer->setInterval(5);
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer())); 
  
  timer_jump->setInterval(5);
  connect(timer_jump, SIGNAL(timeout()), this, SLOT(handleTimer_jump()));
//  setFocus();
//  window->addWidget( view );
}

MainWindow::~MainWindow()
{
  timer->stop();
  timer_user->stop();
  delete window;
  delete timer;
  delete timer_user;
  delete timer_jump;
  
}

void MainWindow::show()
{
  timer->start();
  timer_user->start();
  window->show();
  this->activateWindow();
  setFocus();
  cout << hasFocus() << endl;
  cout << scene->hasFocus() << endl;
}

void MainWindow::handleTimer_user()
{
  user->move(WINDOW_MAX_X, WINDOW_MAX_Y);
}

void MainWindow::handleTimer()
{
  bg_1->move(WINDOW_MAX_X, WINDOW_MAX_Y); 
  bg_2->move(WINDOW_MAX_X, WINDOW_MAX_Y);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
  cout << this->hasFocus() << endl;
  cout << "What." << endl;
  switch(e->key()) {
    case Qt::Key_Up:
      timer_user->stop();
      timer_jump->start();
      break;
  }
}

void MainWindow::handleTimer_jump()
{
  if (user->getY() == 340 && user->jumped )
  {
    timer_jump->stop();
    timer_user->start();
    user->jumped = false;
    return;
  }
  
  else
  {
    user->jump();
  }
}

