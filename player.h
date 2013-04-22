#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"
#include <QGraphicsSceneMouseEvent>


class Player : public Thing {
public:
  Player(QPixmap* pixMap_, QPixmap* left, QPixmap* right, double x_, double y_);
  void move();
  void jump();
  bool jumped;
  void die();
  bool decreaseLife();
  
//protected:
//  void mousePressEvent(QGraphicsSceneMouseEvent *event);
 
private:
  int position;
  QPixmap *left, *right;
  int count;
  int angle;
  int lives;


};


#endif
