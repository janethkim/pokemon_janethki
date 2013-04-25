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
#include <QStackedLayout>
#include "background.h"
#include "player.h"
#include "mainview.h"
#include "obstacle.h"
#include "mylist.h"
#include "jigglypuff.h"
#include "pokeball.h"
#include "starmie.h"
#include "startscreen.h"
#include <QLineEdit>
#include <QLabel>

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 500

class StartScreen;
class MainView;

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow();
  ~MainWindow();
  void show();
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void gameStart();
  QPushButton* getQuit();
  
private:
  QApplication *a;
  QWidget *window;
  QStackedLayout *tabs;
  StartScreen *start_screen;
  QVBoxLayout *layout;
  QGraphicsRectItem *grid;
  QTimer *timer, *timer_user, *timer_die, *timer_enemy;
//  QTimer *timer_jump;
  QTimer *timer_rise, *timer_fall, *timer_pokeball;
  QGraphicsScene *scene;
//  QGraphicsView *view;
  MainView *view;
  Background *bg_1;
  Background *bg_2;
  QPixmap* bgPic;
  Player *user;
  Pidgey *bird;
  QPixmap *stand, *left, *right;
  QPixmap *open, *closed;
  QPixmap *starmie;
//  QPixmap *jigglypuff;
  QPixmap *jigglypuff, *r1, *r2, *r3, *r4, *r5, *r6, *r7;
  QPixmap *pokeball;
  QPixmap *beam;
  MyList<Thing*> badThings;
  MyList<Thing*> goodThings;
  QPixmap *obstacle;
  QLineEdit *score;
  QLabel *scoreLabel;
  QGridLayout *scorelayout;
  QWidget *scoreWidget;
  bool dead, pokeball_start;
  int obst, star, puff, generating, what, initialy;
//  QList<QGraphicsItem*> collisions;
  
//  QApplication *app;
  
public slots:
  void handleTimer();
  void handleTimer_user();
//  void handleTimer_jump();
  void generateEnemy();
  void handleTimer_die();
  void handleTimer_rise();
  void handleTimer_fall();
  void generatePokeballs();
//  void debug();

  
};

#endif
