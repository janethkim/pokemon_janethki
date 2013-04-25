#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "mainwindow.h"
#include <QPalette>
#include <QGraphicsView>
#include <QGraphicsScene>
//#include "startbutton.h"
//#include "start.h"
//#include "quit.h"

//class StartButton;
//class Start;
//class Quit;

class MainWindow;

class StartScreen : public QGraphicsView
{
  Q_OBJECT
public:
  StartScreen(QWidget *parent, QPixmap *bg_, MainWindow *m);
  QPushButton* getQuit();
//  void handleStart();
//  void handleQuit();
//  void paintEvent(QPaintEvent *);
  
private:
  QPushButton *start, *quit;
//  Start *start;
//  Quit *quit;
  MainWindow *main;
  QPixmap* newGame;
  QGraphicsScene* scene;
  QPixmap *bg;
  QGraphicsPixmapItem* background;
  QGraphicsRectItem* grid;
  QHBoxLayout *layout;
  QPaintEvent *p;
  QWidget *buttons;
//  QApplication *a;
  
  
public slots:
  void handleStart();
//  void handleQuit();
 
  
};

#endif
