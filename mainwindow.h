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
#include "mainscene.h"

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 500

class Player;
class MainScene;

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow();
  ~MainWindow();
  void show();
  void keyPressEvent(QKeyEvent *e);
  
private:
  QWidget *window;
//  QVBoxLayout *layout;
  QGraphicsRectItem *grid;
  QTimer *timer, *timer_user, *timer_jump;
  QGraphicsScene *scene;
  QGraphicsView *view;
  Background *bg_1;
  Background *bg_2;
  QPixmap* bgPic;
  Player *user;
  QPixmap *stand, *left, *right;
  
public slots:
  void handleTimer();
  void handleTimer_user();
  void handleTimer_jump();

};

#endif
