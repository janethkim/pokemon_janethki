#include "mainwindow.h"
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include <time.h>


using namespace std;

MainWindow::MainWindow(QApplication* a_)
  : a(a_)
{
  paused = false;
  first = true;
//  vx = 3;
//  time = 15;
  vx = 7;
  time = 30;
  pokeball_start = false;
  obst = star = puff = generating = 0;
  dead = false;
  srand(clock());
  window = new QWidget;
  bgPic = new QPixmap("Images/game-background2.jpg");
  tabs = new QStackedLayout(window);
  start_screen = new StartScreen(window, bgPic, this);
  tabs->addWidget(start_screen);
  name_screen = new Username(window, bgPic, this);
  tabs->addWidget(name_screen);
  
  window->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );

  pause_c = new QPixmap("Images/Pause_clicked.png");
  pause_u = new QPixmap("Images/Pause_unclicked.png");
  restart = new QPixmap("Images/restart.png");
  quit = new QPixmap("Images/quit_scale.png");

  

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
  timers.push_back(timer);
  timers.push_back(timer_user);
  timers.push_back(timer_rise);
  timers.push_back(timer_fall);
  timers.push_back(timer_die);
  timers.push_back(timer_pokeball);
  timers.push_back(speedUp);
//  timer_enemy = new QTimer(this);
//  bgPic = new QPixmap("Images/game-background.jpg");
//  bg_1 = new Background(bgPic, 0, 0, vx);
//  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0, vx);
//  scene->addItem( bg_1 );
//  scene->addItem( bg_2 );
  setFocus();
  
  scoreWidget = new QWidget(view);
  score = new QLineEdit;
  score->setReadOnly(true);
  score->setFixedSize(70, 25);
  scoreLabel = new QLabel(tr("SCORE:"));
  scoreLabel->setBuddy(score);
  user_name = new QLabel;
  
  
  scorelayout = new QGridLayout;
  scorelayout->addWidget(scoreLabel, 0, 0);
  scorelayout->addWidget(score, 0, 1);
  scorelayout->addWidget(user_name, 0, 2);
  scoreWidget->setLayout(scorelayout);
  scoreWidget->setFixedSize(300, 50);
  
  
  grid = new QGraphicsRectItem(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y-2);
  scene->setSceneRect(grid->rect());
  
  view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  
  open = new QPixmap("Images/pidgey.png");
  closed = new QPixmap("Images/pidgey_close.png");
//  bird = new Pidgey(open, closed, 0, 0);
//  scene->addItem(bird);
//  bird->setVisible(false);
  
  stand = new QPixmap("Images/picturesforrunningplayer/standing.png");
  left = new QPixmap("Images/picturesforrunningplayer/runleft.png");
  right = new QPixmap("Images/picturesforrunningplayer/runright1.png");
//  user = new Player(stand, left, right, bird, 100, 340, vx);
  
  obstacle = new QPixmap("Images/boulder_scale.png");
  
  jigglypuff = new QPixmap("Images/remorepics/jigglypuff_scale.png");
  r1 = new QPixmap("Images/jigglypuff_45.png");
  r2 = new QPixmap("Images/jigglypuff_90.png");
  r3 = new QPixmap("Images/jigglypuff_135.png");
  r4 = new QPixmap("Images/jigglypuff_180.png");
  r5 = new QPixmap("Images/jigglypuff_225.png");
  r6 = new QPixmap("Images/jigglypuff_270.png");
  r7 = new QPixmap("Images/jigglypuff_315.png");
  
  icon = new QPixmap("Images/icon.png");
//  QGraphicsPixmapItem *temp;
//  for (int i = 0; i < 3; i++)
//  {
//    temp = new QGraphicsPixmapItem( *icon );
//    temp->setPos(750 - i*40, 5);
//    scene->addItem(temp);
//    temp->setZValue(2);
//  }
//  
//  temp = new Pause( pause_u, pause_c, 150, 0, this );
//  scene->addItem(temp);
//  temp->setZValue(2);
  
//  temp = new QGraphicsPixmapItem( *icon );
//  temp->setPos(600, 50);
//  scene->addItem(temp);
  
  pokeball = new QPixmap("Images/remorepics/Pokeball_scale.png");
//  Thing* temp = new Pokeball(pokeball, WINDOW_MAX_X, 150, true);
//  scene->addItem(temp);
//  goodThings.push_back(temp);
  
  starmie = new QPixmap("Images/remorepics/Starmie_scale.png");
  beam = new QPixmap("Images/hyper_beam.png");
  gameOver = new QPixmap("Images/gameOver_words.png");
  
//  Thing* temp = new Starmie(starmie, beam, user, 500, WINDOW_MAX_X, rand()%335, &badThings, scene, vx);
//  scene->addItem(temp);
//  badThings.push_back(temp);

//  scene->addItem(user);
  
  speedUp->setInterval(2500);
  connect(speedUp, SIGNAL(timeout()), this, SLOT(handle_speedUp()));
  
  timer_pokeball->setInterval(250);
  connect(timer_pokeball, SIGNAL(timeout()), this, SLOT(generatePokeballs()));
  
  timer_user->setInterval(time);
  connect(timer_user, SIGNAL(timeout()), this, SLOT(handleTimer_user()));
//  connect(timer_user, SIGNAL(timeout()), this, SLOT(debug()))
  
  timer->setInterval(time);
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
  delete speedUp;
//  delete timer_enemy;
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
  delete icon;
  delete gameOver;
  delete quit;
  delete restart;
  delete pause_c;
  delete pause_u;
  
//  delete badThings;
//  delete goodThings;
}

void MainWindow::setName(std::string name_)
{
  name = name_;
  
}


void MainWindow::goToUsername()
{
  tabs->setCurrentWidget(name_screen);
}

void MainWindow::show()
{
  setFocus();
  window->show();

}

void MainWindow::gameStart()
{
  

  if (!first)
  {
//    delete user;
//    delete bg_1;
//    delete bg_2;
//    delete bird;
    scene->clear();
    badThings.clear();
    goodThings.clear();
//    thingsToDelete.clear();
    for (int i = 0; i < timers.size(); i++)
    {
      timers[i]->stop();
    }
  }
  else
  {
    tabs->removeWidget(start_screen);
    tabs->removeWidget(name_screen);
    start_screen->setParent(NULL);
    name_screen->setParent(NULL);
    delete start_screen;
    delete name_screen;
    first = false;
  }
  paused = false;
  dead = false;

  bg_1 = new Background(bgPic, 0, 0, vx);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0, vx);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );
  bird = new Pidgey(open, closed, 0, 0);
  scene->addItem(bird);

  user = new Player(stand, left, right, bird, 100, 340, vx);
  user->setName(name);
  QString temp_name;
  temp_name = temp_name.fromStdString(name);
  temp_name.prepend("PLAYER: ");
  user_name->setText(temp_name);
  time = 30;
//  time = 15;

  bird->setVisible(false);
  scene->addItem( user );
  
  QGraphicsPixmapItem *temp;
  
  for (int i = 0; i < 3; i++)
  {
    temp = new QGraphicsPixmapItem( *icon );
    temp->setPos(750 - i*40, 5);
    scene->addItem(temp);
    temp->setZValue(2);
  }
  
  lastIcon = temp;
  
  temp = new Pause( pause_u, pause_c, 10, 450, this );
  scene->addItem(temp);
  temp->setZValue(2);
  
  temp = new Restart(restart, 710, 452, this);
  scene->addItem(temp);
  temp->setZValue(2);
  
  temp = new Quit(quit, 750, 451, this);
  scene->addItem(temp);
  temp->setZValue(2);
  
  tabs->setCurrentWidget(view);
  view->setFocus();
  
  score->setText("0");
  
  timer->setInterval(time);
  timer_user->setInterval(time);
  timer->start();
  timer_user->start();
  speedUp->start();

}

void MainWindow::continueGame()
{
  paused = false;
  for (int i = 0; i < timersToStart.size(); i++)
  {
    timers[timersToStart[i]]->start();
  }
  timersToStart.clear();
}

void MainWindow::pauseGame()
{
  paused = true;
  for(int i = 0; i < timers.size(); i++)
  {
    if (timers[i]->isActive())
    {
      timersToStart.push_back(i);
      timers[i]->stop();
    }  
  }
}

void MainWindow::handleTimer_user()
{
  user->move();
}

void MainWindow::handleTimer()
{
  
//  if (bg_1->getX() <= -WINDOW_MAX_X)
//  {
//    bg_2->setPos(-5, 0);
//    
//  }
//  else if (bg_2->getX() <= -WINDOW_MAX_X)
//    bg_1->setPos(-5,0);
  
  bg_1->move(WINDOW_MAX_X, WINDOW_MAX_Y); 
  bg_2->move(WINDOW_MAX_X, WINDOW_MAX_Y);
  
  int badThingsSize = badThings.size();
  MyList<Thing*> badDeleted;
  for (int i = 0; i < badThingsSize; i++)
  { 
    badThings[i]->move();
    if (badThings[i]->getX() < -50 || badThings[i]->getX() > WINDOW_MAX_X+20 )
    {
//      bool Present = false;
      scene->removeItem(badThings[i]);
      delete badThings[i];
      badDeleted.push_back(badThings[i]);
     
//      delete temp;
     
    
    }
    else if (user->collidesWithItem(badThings[i]))
    {
      dead = true;
//      std::cout << "Current Life count before decreasing: " << user->getLives() << std::endl;
//      user->decreaseLife();
//      std::cout << "Life after decreasing: " << user->getLives() << std::endl;
      
      timer->stop();
      timer_user->stop();
      //  timer_jump->stop();
      timer_fall->stop();
      timer_rise->stop();
      bird->setVisible(false);
      speedUp->stop();
      timer_die->start();
//      timer_die->start();
//      speedUp->stop();
      break;
    }
  }
  
  for (int i = 0; i < badDeleted.size(); i++)
  {
    badThings.remove(badDeleted[i]);
  }
  

  int goodThingsSize = goodThings.size();
  MyList<Thing*> goodDeleted;
  
  
  
  for (int i = 0; i < goodThingsSize; i++)
  {
    goodThings[i]->move();
    if (goodThings[i]->getX() < -50 || goodThings[i]->getX() > WINDOW_MAX_X+20 )
    {
      scene->removeItem(goodThings[i]);
      delete goodThings[i];
      goodDeleted.push_back(goodThings[i]);
//      goodThings.remove(goodThings[i]);
    }
    else if (user->collidesWithItem(goodThings[i]))
    {
      int val = goodThings[i]->collision();
      user->updateScore(val);
      QString s;
      score->setText(s.setNum(user->getScore()));
      scene->removeItem(goodThings[i]);
      delete goodThings[i];
      goodDeleted.push_back(goodThings[i]);
//      goodThings.remove(goodThings[i]);
      
     
    }
  }
  
  for (int i = 0; i < goodDeleted.size(); i++)
  {
    goodThings.remove(goodDeleted[i]);
  }
  
  

}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
//  cout << this->hasFocus() << endl;
//  cout << "What." << endl;
  if (!dead && !paused)
    {
    switch(event->key()) {
      case Qt::Key_Up:
        if (timer_user->isActive())
          timer_user->stop();
//        if (!timer_user->isActive())
//          timer_jump->start();
        if (timer_fall->isActive())
          timer_fall->stop();
//        bird->setVisible(true);
        timer_rise->start();
        
         
        break;
    }
  }
}
  
  
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
  if(!dead && !paused)
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
      temp = new Starmie(starmie, beam, user, 500/vx, WINDOW_MAX_X, rand()%335, &badThings, scene, vx);
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

  
  user->die();
//  std::cout << "Lives: " << user->getLives() << std::endl;
//  user->decreaseLife();
  //if(user->decreaseLife())
    //GAME OVER
//  bool over = user->gameOver();
  if (user->getY() > WINDOW_MAX_Y+100)
  { 
    timer_die->stop();
    
    restartGame();
    
  }
}



void MainWindow::restartGame()
{
  user->decreaseLife();
  if (user->getLives() == 0)
  {
    lastLife();
    return;
  }
  pauseGame();
  scene->removeItem( user );
  scene->removeItem( bird );
  scene->clear();
  badThings.clear();
  goodThings.clear();
//  thingsToDelete.clear();
  time = 30;
//  time = 15;
  bg_1 = new Background(bgPic, 0, 0, vx);
  bg_2 = new Background(bgPic, WINDOW_MAX_X, 0, vx);
  scene->addItem( bg_1 );
  scene->addItem( bg_2 );

  scene->addItem(bird);
  bird->setVisible(false);
  scene->addItem( user );
  user->restart(vx);
  user->setZValue(2);
  dead = false;
  
  QGraphicsPixmapItem *temp;
  for (int i = 0; i < user->getLives(); i++)
  {
    temp = new QGraphicsPixmapItem( *icon );
    temp->setPos(750 - i*40, 5);
    scene->addItem(temp);
    temp->setZValue(2);
    
    if (i == (user->getLives() - 1))
      lastIcon = temp;
  }
  
  temp = new Pause(pause_u, pause_c, 10, 450, this);
  scene->addItem(temp);
  temp->setZValue(2);
  
  temp = new Restart(restart, 710, 452, this);
  scene->addItem(temp);
  temp->setZValue(2);
  
  temp = new Quit(quit, 750, 451, this);
  scene->addItem(temp);
  temp->setZValue(2);
  
  tabs->setCurrentWidget(view);
  timer->setInterval(time);
  timer_user->setInterval(time);
  continueGame();
  timer->start();
  timer_user->start();
  speedUp->start();
  view->setFocus();
  
}

void MainWindow::lastLife()
{
  scene->removeItem( lastIcon );
  delete lastIcon;
  QGraphicsPixmapItem* temp = new QGraphicsPixmapItem( *gameOver );
  temp->setPos(250, 200);
  scene->addItem(temp);
}

void MainWindow::callQuit()
{
  a->quit();
}
//QPushButton* MainWindow::getQuit()
//{
//  return start_screen->getQuit();
//}

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
  time = time*0.9;
//////  
//  time -= 0.5;
  if (time <= 1)
    time = 1;
  //time -= time/20;
//  std::cout << time << std::endl;
  
  timer->setInterval(time); 
  timer_user->setInterval(time);
  
}


