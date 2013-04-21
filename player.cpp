#include "player.h"  


Player::Player(QPixmap* pixMap_, QPixmap* left_, QPixmap* right_, double x_, double y_)
  : Thing(pixMap_, x_, y_)
{
  count = 0;
  position = 0;
  vx = 0.5;
  vy = 0;
  left = left_;
  right = right_;
}


void Player::move( int xmax, int ymax )
{
  count = count+1;
  if (count > 10)
  {
    position = position+1;
    switch (position%3) {
    case 0: setPixmap( *pixMap ); break;
    case 1: setPixmap( *left ); break;
    case 2: setPixmap( *right ); break;
    }
    count = 0;
  }
  
}


