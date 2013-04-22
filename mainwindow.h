#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTimer>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include "background.h"
#include "player.h"
#include "mainview.h"
#include "obstacle.h"
#include "mylist.h"
#include "jigglypuff.h"

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 500


class MainView;

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow();
  ~MainWindow();
  void show();
  void keyPressEvent(QKeyEvent *event);
  
private:
  QWidget *window;
  QVBoxLayout *layout;
  QGraphicsRectItem *grid;
  QTimer *timer, *timer_user, *timer_jump, *timer_die;
  QGraphicsScene *scene;
//  QGraphicsView *view;
  MainView *view;
  Background *bg_1;
  Background *bg_2;
  QPixmap* bgPic;
  Player *user;
  QPixmap *stand, *left, *right;
//  QPixmap *jigglypuff;
  QPixmap *jigglypuff, *r1, *r2, *r3, *r4, *r5, *r6, *r7;
  MyList<Thing*> badThings;
  MyList<Thing*> goodThings;
  QPixmap *obstacle;
  bool dead;
//  QList<QGraphicsItem*> collisions;
  
//  QApplication *app;
  
public slots:
  void handleTimer();
  void handleTimer_user();
  void handleTimer_jump();
  void generateEnemy();
  void handleTimer_die();
//  void debug();

  
};

#endif
