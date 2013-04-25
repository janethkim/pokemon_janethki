#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"
#include "pidgey.h"
#include <string>
//#include <QGraphicsSceneMouseEvent>
using namespace std;

class Player : public Thing {
public:
  Player(QPixmap* pixMap_, QPixmap* left, QPixmap* right, Pidgey* pidgey_, double x_, double y_, double vx_);
  void move();
  void jump();
  void fall();
  void rise();
  bool jumped;
  void die();
  void speedUp();
  bool decreaseLife();
  void updateScore(int val);
  int getScore();
  void setName(string name_);
  string getName();
  
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
  string name;


};


#endif
