#include "mainwindow.h"
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include <time.h>
#include <fstream>


using namespace std;

MainWindow::MainWindow(QApplication* a_)
  : a(a_)
{
  curr_level = 1;
// highScore = new QGraphicsSimpleTextItem;
 scores = new MaxList;
//  temp_label.prepend( high_name );

//   QString temp_name;
//  temp_name = temp_name.fromStdString(name);
//  temp_name.prepend("PLAYER: ");
//  user_name->setText(temp_name);
  
  paused = false;
  first = true;
//  vx = 3;
//  time = 15;
  vx =10;
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
  level = new QLabel(tr("Level "));
//  high_score = new QLabel;
  
  toplayout = new QVBoxLayout;
  scorelayout = new QHBoxLayout;
  scorelayout->addWidget(scoreLabel);
  scorelayout->addWidget(score);
//  scorelayout->addWidget(user_name, 1, 0);
  scorelayout->addWidget(level);
  toplayout->addLayout(scorelayout);
  toplayout->addWidget(user_name);
//  toplayout->addWidget(high_score);
  scoreWidget->setLayout(toplayout);
//  scoreWidget->setFixedSize(400, 75);
  
  
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
  
  chansey_stand = new QPixmap("Images/remorepics/chansey_scale.png");
  chansey_left = new QPixmap("Images/remorepics/chansey_move.png");
  chansey_right = new QPixmap("Images/remorepics/chansey_move_right.png");
  
 
 
  
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
  
  speedUp->setInterval(10000);
  connect(speedUp, SIGNAL(timeout()), this, SLOT(levelUp()));
  
  timer_pokeball->setInterval(250);
  connect(timer_pokeball, SIGNAL(timeout()), this, SLOT(generatePokeballs()));
  
  timer_user->setInterval(time);
  connect(timer_user, SIGNAL(timeout()), this, SLOT(handleTimer_user()));
//  connect(timer_user, SIGNAL(timeout()), this, SLOT(debug()))
  
  timer->setInterval(time);
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer, SIGNAL(timeout()), this, SLOT(generateEnemy()));
  

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
  delete scores;
  
  
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
    writeScore();
    scene->clear();
    badThings.clear();
    goodThings.clear();
//    thingsToDelete.clear();
    for (int i = 0; i < timers.size(); i++)
    {
      timers[i]->stop();
    }
    scores->clear();
//    scores = new MaxList;
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
//  scores = new MaxList;
  ifstream myFile("high_scores.txt");

  int value;
  string name_what;
  
  if (myFile.good())
  {
    myFile >> value;
    myFile.ignore();
    getline(myFile, name_what);
  }
  while (myFile.good())
  {
//    myFile >> value;
//    getline(myFile, name_what);
    Score *tempscore = new Score;
    tempscore->num = value;
    tempscore->name = name_what;
    scores->push(tempscore);
//    cout << value << " ";
//    if (myFile.eof())
//      break;
    myFile >> value;
    myFile.ignore();
    getline(myFile, name_what);
  }
//  high = 0;
//  int value;
//  high_name = " ";
//  while (myFile.good())
//  {
//    myFile >> value;
//    if (value > high)
//    {
//      high = value;
//      getline(myFile, high_name) ;
//    }
//    else
//    {
//      myFile.ignore(100, '\n');
//    } 
//  }
  myFile.close();
//  if (scores->size() > 0)
//  {
//    int high = scores->top()->num;
//    QString temp_label;
//    temp_label.setNum(high);
//    temp_label.prepend("High Score: ");
//    high_score->setText(temp_label);
//  }

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
  
  /****TESTING******/
  /*****************/
  
  Thing *temp_what = new Chansey(chansey_stand, chansey_left, chansey_right, 0,
    340, &goodThings, scene, vx);
  scene->addItem(temp_what);
  goodThings.push_back(temp_what);
  temp_what->setZValue(3);
  
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
  scene->removeItem(highScore);
  delete highScore;
//  for (int i = 0; i < displayScores.size(); i++)
//  {
//    delete displayScores.at(i);
//  }
//  displayScores.clear();
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
  highScore = new QGraphicsSimpleTextItem;
  QString final = "HIGH SCORES:\n";
  
  for (int i = 0; i < scores->size(); i++)
  {
    
    QString t1, t2;
    t1 = t1.fromStdString(scores->at(i)->name);
    t2.setNum(scores->at(i)->num);
    t1.prepend(" ");
    t1.prepend(t2);
    t1.append("\n");
    final.append(t1);
//    temp->setText(t1);
//    displayScores.push_back(temp);
  }
  highScore->setText(final);
  
  highScore->setPos(330, 150);
  scene->addItem(highScore);
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
      if (val)
      {
        user->updateScore(val);
        QString s;
        score->setText(s.setNum(user->getScore()));
        scene->removeItem(goodThings[i]);
        delete goodThings[i];
        goodDeleted.push_back(goodThings[i]);
      }
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
      temp = new Jigglypuff(jigglypuff, r1, r2, r3, r4, r5, r6, r7, WINDOW_MAX_X, rand()%100+235, vx);
      scene->addItem(temp);
      badThings.push_back(temp);
      added = true;
    }
    break;
  case 3:
    if (curr_level == 2 || curr_level == 3)
    {
      star++;
      if (star%5 == 0)
      {
        temp = new Starmie(starmie, beam, user, 500/vx, WINDOW_MAX_X, rand()%335, &badThings, scene, vx);
        scene->addItem(temp);
        badThings.push_back(temp);
        added = true;
      }
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
//  pauseGame();

  timer->stop();
  timer_user->stop(); 
  
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
  int lives = user->getLives();
  for (int i = 0; i < lives; i++)
  {
//    cout << i << endl;
    temp = new QGraphicsPixmapItem( *icon );
    temp->setPos(750 - i*40, 5);
//    cout << scene << endl;
    scene->addItem(temp);
    temp->setZValue(3);
    
    if (i == (user->getLives() - 1))
      lastIcon = temp;
  }
  
//  lastIcon = temp;
  
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
//  continueGame();
  timer->start();
  timer_user->start();
//  speedUp->start();
  view->setFocus();
  
}

void MainWindow::lastLife()
{
  scene->removeItem( lastIcon );
  delete lastIcon;
  QGraphicsPixmapItem* temp = new QGraphicsPixmapItem( *gameOver );
  temp->setPos(250, 200);
  scene->addItem(temp);
  
  writeScore();
  
}

void MainWindow::callQuit()
{
  if (!first)
    writeScore();
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
  time = time*0.8;
//////  
//  time -= 0.5;
  if (time <= 1)
    time = 1;
  //time -= time/20;
//  std::cout << time << std::endl;
  
  timer->setInterval(time); 
  timer_user->setInterval(time);
  
}

void MainWindow::writeScore()
{
  if (scores != NULL)
  {
    ofstream myFile("high_scores.txt");
    Score *temp;
    if (user != NULL)
    {
      temp = new Score;
      temp->num = user->getScore();
      temp->name = user->getName();
      scores->push(temp);
      
      while (scores->size() > 10) //maximum number of items in the list is 10
        scores->pop_back();
    }
    
//    cout << scores->size() << endl;
    for (int i = 0; i < scores->size(); i++)
    {
      temp = scores->at(i);
      myFile << temp->num << " " << temp->name << "\n";
    }
      
      myFile.close();
  }
  //  myFile << high << " " << high_name << "\n";
//  myFile << user->getScore() << " " << user->getName() << "\n";
  
}


void MainWindow::levelUp()
{
  curr_level++;
  
  if (curr_level == 2)
  {
    bgPic->load("Images/game-background3.jpg");
    bg_1->setPixmap( *bgPic );
    bg_2->setPixmap( *bgPic );
  }
  else if (curr_level == 3)
  {
    bgPic->load("Images/game-background4.jpg");
    bg_1->setPixmap( *bgPic );
    bg_2->setPixmap( *bgPic ); 
    speedUp->stop();
  }
//  switch (curr_level)
//  {
//    case 2: bgPic->load("Images/game-backgroundi3.jpg");
//            bg_1->set
//            break;
//    case 3: bgPic->load("Images/game-background4.jpg"); break;
//  }
}

