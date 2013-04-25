#include "mainwindow.h"
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include <time.h>

using namespace std;

MainWindow::MainWindow()
{
  vx = 2;
  time = 10;
  pokeball_start = false;
  obst = star = puff = generating = 0;
  dead = false;
  srand(clock());
  window = new QWidget;
  bgPic = new QPixmap("Images/game-background2.jpg");
  tabs = new QStackedLayout(window);
  start_screen = new StartScreen(window, bgPic, this);
  tabs->addWidget(start_screen);
  
  window->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );


  scene = new QGraphicsScene;

  view = new MainView(scene, this, window);
//  view = new MainView(scene, this, window);
  tabs->addWidget(view);
//  tabs->setCurrentWidget(view);

  view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
  timer = new QTimer(this);
  timer_user = new QTimer(this);
//  timer_jump = new QTimer(this);
  timer_rise = new QTimer(this);
  timer_fall = new QTimer(this);
  timer_die = new QTimer(this);
  timer_pokeball = new QTimer(this);
  speedUp = new QTimer(this);
//  timer_enemy = new QTimer(this);
//  bgPic = new QPixmap("Images/game-background.jpg");
  bg_1 = new Background(bgPic, 0, 0, vx);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0, vx);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );
  setFocus();
  
  scoreWidget = new QWidget(view);
  score = new QLineEdit;
  score->setReadOnly(true);
  score->setFixedSize(70, 25);
  scoreLabel = new QLabel(tr("SCORE:"));
  scoreLabel->setBuddy(score);
  score->setText("0");
  
  scorelayout = new QGridLayout;
  scorelayout->addWidget(scoreLabel, 0, 0);
  scorelayout->addWidget(score, 0, 1);
  scoreWidget->setLayout(scorelayout);
  
  
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
  user = new Player(stand, left, right, bird, 100, 340, vx);
  
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
//  Thing* temp = new Pokeball(pokeball, WINDOW_MAX_X, 150, true);
//  scene->addItem(temp);
//  goodThings.push_back(temp);
  
  starmie = new QPixmap("Images/remorepics/Starmie_scale.png");
  beam = new QPixmap("Images/hyper_beam.png");
  
//  Thing* temp = new Starmie(starmie, beam, user, 500, WINDOW_MAX_X, rand()%335, &badThings, scene, vx);
//  scene->addItem(temp);
//  badThings.push_back(temp);

  scene->addItem(user);
  
  speedUp->setInterval(10000);
  connect(speedUp, SIGNAL(timeout()), this, SLOT(handle_speedUp()));
  
  timer_pokeball->setInterval(250);
  connect(timer_pokeball, SIGNAL(timeout()), this, SLOT(generatePokeballs()));
  
  timer_user->setInterval(time);
  connect(timer_user, SIGNAL(timeout()), this, SLOT(handleTimer_user()));
//  connect(timer_user, SIGNAL(timeout()), this, SLOT(debug()))
  
  timer->setInterval(time);
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
  delete timer_pokeball;
//  delete timer_jump;
  delete timer_rise;
  delete timer_fall;
  delete timer_die;
  delete bgPic;
  delete stand;
  delete left;
  delete right;
  delete obstacle;
  delete jigglypuff;
  delete r1;
  delete r2;
  delete r3;
  delete r4;
  delete r5;
  delete r6;
  delete r7;
  delete starmie;
  delete pokeball;
  delete open;
  delete closed;
  delete beam;
//  delete badThings;
//  delete goodThings;
}


void MainWindow::show()
{
  setFocus();
  window->show();

}

void MainWindow::handleTimer_user()
{
  user->move();
}

void MainWindow::handleTimer()
{
  
  if (bg_1->getX() <= -WINDOW_MAX_X)
  {
    bg_2->setPos(-5, 0);
    
  }
  else if (bg_2->getX() <= -WINDOW_MAX_X)
    bg_1->setPos(-5,0);
  
  bg_1->move(WINDOW_MAX_X, WINDOW_MAX_Y); 
  bg_2->move(WINDOW_MAX_X, WINDOW_MAX_Y);
  
  for (int i = 0; i < badThings.size(); i++)
  { 
    badThings[i]->move();
    if (badThings[i]->getX() < -300 || badThings[i]->getX() > WINDOW_MAX_X+20 )
    {
      scene->removeItem(badThings[i]);
      Thing* temp = badThings.pop(i);
      delete temp;
     
    
    }
    else if (user->collidesWithItem(badThings[i]))
    {
      dead = true;
      bird->setVisible(false);
      timer->stop();
      timer_user->stop();
      //  timer_jump->stop();
      timer_fall->stop();
      timer_rise->stop();
      speedUp->stop();
      timer_die->start();
//      speedUp->stop();
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
      int val = goodThings[i]->collision();
      user->updateScore(val);
      QString s;
      score->setText(s.setNum(user->getScore()));
      scene->removeItem(goodThings[i]);
      delete goodThings[i];
      goodThings.pop(i);
      
     
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
//    user->jumped = false;
    
  }
  else
    user->fall();
}

void MainWindow::generateEnemy()
{
  int divide = 500/vx;
  int choice = rand()%divide;
  Thing* temp;
  bool added = false;
  switch(choice)
  {
  case 0:
  case 5:
//    timer_pokeball->start();
    obst++;
    if (obst%5 == 0)
    {
      temp = new Obstacle(obstacle, WINDOW_MAX_X, 335, vx);
      scene->addItem(temp);
      
      badThings.push_back(temp);
      added = true;
    }
    break;
  case 1:
//    temp = new Jigglypuff(jigglypuff, 500, 335);
    timer_pokeball->start();
    puff++;
    if (puff%5 == 0)
    {
      temp = new Jigglypuff(jigglypuff, r1, r2, r3, r4, r5, r6, r7, WINDOW_MAX_X, 335, vx);
      scene->addItem(temp);
      badThings.push_back(temp);
      added = true;
    }
    break;
  case 3:
    star++;
    if (star%5 == 0)
    {
      temp = new Starmie(starmie, beam, user, 750/vx, WINDOW_MAX_X, rand()%335, &badThings, scene, vx);
      scene->addItem(temp);
      badThings.push_back(temp);
      added = true;
    }
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
//        cout << "Probably Starmie removed." << endl;
        scene->removeItem(temp);
        badThings.remove(temp);
        break;
      }
    }
    
  }
}

void MainWindow::handleTimer_die()
{
//  dead = true;
//  bird->setVisible(false);
//  timer->stop();
//  timer_user->stop();
////  timer_jump->stop();
//  timer_fall->stop();
//  timer_rise->stop();
//  speedUp->stop();
  
  user->die();
  user->decreaseLife();
  //if(user->decreaseLife())
    //GAME OVER
  if (user->getY() > WINDOW_MAX_Y+100)
    timer_die->stop();
}

void MainWindow::gameStart()
{
  tabs->setCurrentWidget(view);
  timer->start();
  timer_user->start();
  speedUp->start();

}

QPushButton* MainWindow::getQuit()
{
  return start_screen->getQuit();
}

void MainWindow::generatePokeballs()
{
  
  if (!pokeball_start)
  { 
    what = rand() % 3;
    pokeball_start = true;
    initialy = rand()%50 + 150;
  }
  int x = WINDOW_MAX_X;
  Thing* temp;
  switch (what)
  {
  case 0: 
      if (generating >= 7)
      { generating = 0; pokeball_start = false; timer_pokeball->stop(); break; }
   
      temp = new Pokeball(pokeball, x, initialy, false, vx);
      scene->addItem(temp);
      temp->setZValue(0);
      goodThings.push_back(temp);
      generating++;
      break;
  case 1: 
      if (generating >= 7)
      {
        generating = 0;
        pokeball_start = false;
        timer_pokeball->stop();
        break;
      }
      if ((initialy+generating*20)> 320)
        temp = new Pokeball(pokeball, x, 320, false, vx);
      else
        temp = new Pokeball(pokeball, x, initialy+(generating*20), false, vx);
      scene->addItem(temp);
      temp->setZValue(0);
      goodThings.push_back(temp);
      generating++;
      break;
  case 2:
      if (generating >= 1)
      {
        generating = 0;
        pokeball_start = false;
        timer_pokeball->stop();
        break;
      }
      temp = new Pokeball(pokeball, x, 150, true, vx);
      temp->setZValue(0);
      scene->addItem(temp);
      goodThings.push_back(temp);
      generating++;
      break;
          
  }
  
}

void MainWindow::handle_speedUp()
{
//  timer->stop();
//  user->speedUp();
//  bg_1->speedUp();
//  bg_2->speedUp();

//  vx += 0.01;
//  
  time = time*0.99;
////  
  if (time <= 0.01)
    time = 0.01;
  //time -= time/20;

  
  timer->setInterval(time); 
  timer_user->setInterval(time);
//  
}


