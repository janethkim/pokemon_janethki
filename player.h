#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"
#include "pidgey.h"
#include <QGraphicsSceneMouseEvent>


class Player : public Thing {
public:
  Player(QPixmap* pixMap_, QPixmap* left, QPixmap* right, Pidgey* pidgey_, double x_, double y_);
  void move();
  void jump();
  void fall();
  void rise();
  bool jumped;
  void die();
  bool decreaseLife();
  void updateScore(int val);
  int getScore();
  
//protected:
//  void mousePressEvent(QGraphicsSceneMouseEvent *event);
 
private:
  int position;
  QPixmap *left, *right;
  int count;
  int angle;
  int lives;
  int score;
  Pidgey *pidgey;


};


#endif
