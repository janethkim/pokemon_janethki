#include "startscreen.h"
#include <QPainter>

StartScreen::StartScreen(QWidget *parent, QPixmap *bg_, MainWindow *m)
  : QGraphicsView(parent), main(m), bg(bg_)
{
//  QPalette p = this->palette();
//  p.setBrush(QPalette::Base, *bg);
//  this->setPalette(p);
//  parent->setStyleSheet("background-image: url(./Images/game-background.jpg)");
//  setPaletteBackgroundPixmap(*bg);
  scene = new QGraphicsScene;
  setScene(scene);
  background = new QGraphicsPixmapItem( *bg );
  scene->addItem(background);
//  QPixmap* newGame = new QPixmap("./Images/start_scale.png");
  start = new QPushButton( "START");
  
//  start = new Start( newGame, 200, 150, this );
//  quit = new Quit( newGame, 300, 150, this );
//  
//  scene->addItem(start);
//  scene->addItem(quit);
 
 

  
  buttons = new QWidget(this);
  start->setFixedSize(70, 30);
  quit = new QPushButton("QUIT");

  quit->setFixedSize(70,30);

  layout = new QHBoxLayout;
  layout->addWidget(start);
  layout->addWidget(quit);
 
  buttons->setLayout(layout);
  buttons->setGeometry(QRect(250,150, 300, 200));
  grid = new QGraphicsRectItem(0, 0, 800, 500);
  scene->setSceneRect(grid->rect());
  
  setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  
  connect(start, SIGNAL(clicked()), this, SLOT(handleStart()));
  connect(quit, SIGNAL(clicked()), m, SLOT(callQuit()));

    
}

void StartScreen::handleStart()
{
  main->gameStart();
}

//QPushButton* StartScreen::getQuit()
//{
//  return quit;
//}

//void StartScreen::handleQuit()
//{
//  a->quit();
//}

//void StartScreen::paintEvent(QPaintEvent *paint)
//{
//  QPainter paint(this);
//  paint.drawPixmap(0,0,*bg);
//  QWidget::paintEvent(*paint);
//}
