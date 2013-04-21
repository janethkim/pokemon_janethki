#include "mainwindow.h"
#include <cstdlib>
#include <QDebug>
#include <iostream>
using namespace std;

MainWindow::MainWindow()
{

  window = new QWidget;

  window->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );

  scene = new QGraphicsScene;

  view = new MainView(scene, this, window);

  view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
  timer = new QTimer(this);
  timer_user = new QTimer(this);
  timer_jump = new QTimer(this);
  bgPic = new QPixmap("Images/game-background.jpg");
  bg_1 = new Background(bgPic, 0, 0);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );

  
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
//  connect(timer_user, SIGNAL(timeout()), this, SLOT(debug()));
  
  timer->setInterval(5);
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer())); 
  
  timer_jump->setInterval(5);
  connect(timer_jump, SIGNAL(timeout()), this, SLOT(handleTimer_jump()));

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
  setFocus();
  timer->start();
  timer_user->start();
  window->show();

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//  cout << this->hasFocus() << endl;
//  cout << "What." << endl;
  switch(event->key()) {
    case Qt::Key_Up:
      if (timer_user->isActive())
        timer_user->stop();
      if (!timer_user->isActive())
        timer_jump->start();
      break;
  }
  
//  QWidget::keyPressEvent(event);
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

