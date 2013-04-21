#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;

class Player : public Thing {
public:
  Player(QPixmap* pixMap_, QPixmap* left, QPixmap* right, double x_, double y_, MainWindow* w_);
  void move( int xmax, int ymax );
  void jump();
  bool jumped;
  
//protected:
//  void mousePressEvent(QGraphicsSceneMouseEvent *event);
 
private:
  int position;
  QPixmap *left, *right;
  int count;
  MainWindow *w;


};


#endif
