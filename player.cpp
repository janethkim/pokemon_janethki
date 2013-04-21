#include "player.h"  


Player::Player(QPixmap* pixMap_, QPixmap* left_, QPixmap* right_, double x_, double y_)
  : Thing(pixMap_, x_, y_)
{
  position = 0;
  vx = 0;
  vy = 0;
  left = left_;
  right = right_;
}


void Player::move( int xmax, int ymax )
{
  position = (position+1)%3;
  
  switch (position) {
  case 0: setPixmap( *pixMap ); break;
  case 1: setPixmap( *left ); break;
  case 2: setPixmap( *right ); break;
  }
}


