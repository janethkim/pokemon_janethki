#include "mainwindow.h"
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include <time.h>

using namespace std;

MainWindow::MainWindow()
{
  dead = false;
  srand(clock());
  window = new QWidget;
  
  window->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );

  scene = new QGraphicsScene;

  view = new MainView(scene, this, window);

  view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
  timer = new QTimer(this);
  timer_user = new QTimer(this);
//  timer_jump = new QTimer(this);
  timer_rise = new QTimer(this);
  timer_fall = new QTimer(this);
  timer_die = new QTimer(this);
//  timer_enemy = new QTimer(this);
  bgPic = new QPixmap("Images/game-background.jpg");
  bg_1 = new Background(bgPic, 0, 0);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );
  setFocus();

  
  grid = new QGraphicsRectItem(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y-2);
  scene->setSceneRect(grid->rect());
  
  view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  
  open = new QPixmap("Images/pidgey.png");
  closed = new QPixmap("Images/pidgey_close.png");
  bird = new Pidgey(open, closed, 0, 0);
  scene->addItem(bird);
  bird->setVisible(false);
  
  stand = new QPixmap("Images/picturesforrunningplayer/standing.png");
  left = new QPixmap("Images/picturesforrunningplayer/runleft.png");
  right = new QPixmap("Images/picturesforrunningplayer/runright1.png");
  user = new Player(stand, left, right, bird, 100, 340);
  
  obstacle = new QPixmap("Images/boulder_scale.png");
  
  jigglypuff = new QPixmap("Images/remorepics/jigglypuff_scale.png");
  r1 = new QPixmap("Images/jigglypuff_45.png");
  r2 = new QPixmap("Images/jigglypuff_90.png");
  r3 = new QPixmap("Images/jigglypuff_135.png");
  r4 = new QPixmap("Images/jigglypuff_180.png");
  r5 = new QPixmap("Images/jigglypuff_225.png");
  r6 = new QPixmap("Images/jigglypuff_270.png");
  r7 = new QPixmap("Images/jigglypuff_315.png");
  
  pokeball = new QPixmap("Images/remorepics/Pokeball_scale.png");
  

  scene->addItem(user);
  
  timer_user->setInterval(5);
  connect(timer_user, SIGNAL(timeout()), this, SLOT(handleTimer_user()));
//  connect(timer_user, SIGNAL(timeout()), this, SLOT(debug()))
  
  timer->setInterval(5);
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer, SIGNAL(timeout()), this, SLOT(generateEnemy()));
  
//  timer_enemy->setInterval(100);
//  connect(timer_enemy, SIGNAL(timeout()), this, SLOT(generateEnemy()));
  
//  timer_jump->setInterval(5);
//  connect(timer_jump, SIGNAL(timeout()), this, SLOT(handleTimer_jump()));
  timer_rise->setInterval(5);
  connect(timer_rise, SIGNAL(timeout()), this, SLOT(handleTimer_rise()));
  
  timer_fall->setInterval(5);
  connect(timer_fall, SIGNAL(timeout()), this, SLOT(handleTimer_fall()));
  
  
  timer_die->setInterval(5);
  connect(timer_die, SIGNAL(timeout()), this, SLOT(handleTimer_die()));
//  
//  timer_enemies->setInterval(30);
//  connect(timer_enemies, SIGNAL(timeout()), this, SLOT(generateEnemy()));

}

MainWindow::~MainWindow()
{
  timer->stop();
  timer_user->stop();
  timer_die->stop();
  delete window;
  delete timer;
  delete timer_user;
//  delete timer_jump;
  delete timer_rise;
  delete timer_fall;
  delete timer_die;
  delete bgPic;
  delete stand;
  delete left;
  delete right;
  delete obstacle;
  
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
  user->move();
}

void MainWindow::handleTimer()
{
  bg_1->move(WINDOW_MAX_X, WINDOW_MAX_Y); 
  bg_2->move(WINDOW_MAX_X, WINDOW_MAX_Y);
  for (int i = 0; i < badThings.size(); i++)
  { 
    badThings[i]->move();
    if (badThings[i]->getX() < -300 || badThings[i]->getX() > WINDOW_MAX_X )
    {
      scene->removeItem(badThings[i]);
      delete badThings[i];
      badThings.pop(i);
    }
    else if (user->collidesWithItem(badThings[i]))
    {
      dead = true;
      bird->setVisible(false);
      timer->stop();
      timer_user->stop();
//      timer_jump->stop();
      timer_fall->stop();
      timer_rise->stop();
      timer_die->start();
      break;
    }
  }
  
  for (int i = 0; i < goodThings.size(); i++)
  {
    goodThings[i]->move();
    if (goodThings[i]->getX() < -300 || goodThings[i]->getX() > WINDOW_MAX_X+20 )
    {
      scene->removeItem(goodThings[i]);
      delete goodThings[i];
      goodThings.pop(i);
    }
    else if (user->collidesWithItem(goodThings[i]))
    {
      scene->removeItem(goodThings[i]);
      goodThings.pop(i);
      int val = goodThings[i]->collision();
      user->updateScore(val);
    }
  }
  
  
//  for (int j = 0; j < badThings.size(); j++)
//  {
//    QGraphicsItem *temp = badThings[j];
//    if (user->collidesWithItem(temp))
//    {
//      dead = true;
//      timer->stop();
//      timer_user->stop();
//      timer_jump->stop();
//      timer_die->start();
//      
//    }
//  }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//  cout << this->hasFocus() << endl;
//  cout << "What." << endl;
  if (!dead)
    {
    switch(event->key()) {
      case Qt::Key_Up:
        if (timer_user->isActive())
          timer_user->stop();
//        if (!timer_user->isActive())
//          timer_jump->start();
        if (timer_fall->isActive())
          timer_fall->stop();
        timer_rise->start();
         
        break;
    }
  }
}
  
  
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
  if(!dead)
  {
    switch(event->key())
    {
    case Qt::Key_Up:
      timer_rise->stop();
      timer_fall->start();
      break;
    }
  }
}
//  QWidget::keyPressEvent(event);


//void MainWindow::handleTimer_jump()
//{
//  if (user->getY() == 340 && user->jumped )
//  {
//    timer_jump->stop();
//    timer_user->start();
//    user->jumped = false;
//    return;
//  }
//  
//  else
//  {
//    user->jump();
//  }
//}

void MainWindow::handleTimer_rise()
{
    user->rise();
}

void MainWindow::handleTimer_fall()
{
  if (dead || user->getY() >= 340)
  {
    timer_fall->stop();
    timer_user->start();
    user->jumped = false;
    
  }
  else
    user->fall();
}

void MainWindow::generateEnemy()
{
  int choice = rand()%500;
  Thing* temp;
  bool added = true;
  switch(choice)
  {
  case 0:
    temp = new Obstacle(obstacle, WINDOW_MAX_X, 335);
    scene->addItem(temp);
    
    badThings.push_back(temp);
    break;
  case 1:
//    temp = new Jigglypuff(jigglypuff, 500, 335);
    temp = new Jigglypuff(jigglypuff, r1, r2, r3, r4, r5, r6, r7, WINDOW_MAX_X, 335);
    scene->addItem(temp);
    
    badThings.push_back(temp);
    break;
  default:
    added = false;
    break;
  }
  
  if (added)
  {
    for (int j = 0; j < badThings.size(); j++)
    {
      if (temp == badThings[j])
        continue;
      else if (temp->collidesWithItem(badThings[j]))
      {
        scene->removeItem(temp);
        badThings.remove(temp);
        break;
      }
    }
    
  }
}

void MainWindow::handleTimer_die()
{
  user->die();
  user->decreaseLife();
  if (user->getY() > WINDOW_MAX_Y+100)
    timer_die->stop();
}

