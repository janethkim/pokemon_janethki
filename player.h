#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"

class Player : public Thing {
public:
  Player(QPixmap* pixMap_, QPixmap* left, QPixmap* right, double x_, double y_);
  void move( int xmax, int ymax );

private:
  int position;
  QPixmap *left, *right;
  int count;
};


#endif
