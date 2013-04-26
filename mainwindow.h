#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
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
#include "pause.h"
#include "restart.h"
#include "quit.h"

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 500

class Quit;
class Restart;
class Pause;
class StartScreen;
class MainView;

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow(QApplication *a_);
  ~MainWindow();
  void show();
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  void gameStart();
  void restartGame();
//  QPushButton* getQuit();
  void SpeedUp();
  void pauseGame();
  void continueGame();
  
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
  QTimer *speedUp;
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
  QPixmap *icon, *pause_c, *pause_u, *restart, *quit;
//  QPixmap *jigglypuff;
  QPixmap *jigglypuff, *r1, *r2, *r3, *r4, *r5, *r6, *r7;
  QPixmap *pokeball;
  QPixmap *beam;
  MyList<Thing*> badThings;
  MyList<Thing*> goodThings;
  MyList<QTimer*> timers;
  MyList<int> timersToStart;
  QPixmap *obstacle;
  QLineEdit *score;
  QLabel *scoreLabel;
  QGridLayout *scorelayout;
  QWidget *scoreWidget;
  bool dead, pokeball_start, first;
  int obst, star, puff, generating, what, initialy;
  double time;
  double vx;
//  QApplication *a;
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
  void handle_speedUp();
  void callQuit();
  
//  void debug();

  
};

#endif
