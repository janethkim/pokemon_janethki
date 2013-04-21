#include "player.h"  


Player::Player(QPixmap* pixMap_, QPixmap* left_, QPixmap* right_, double x_, double y_, MainWindow* w_)
  : Thing(pixMap_, x_, y_), jumped(false), w(w_)
{
  count = 0;
  position = 0;
  vx = 0.5;
  vy = 0;
  left = left_;
  right = right_;
}

//void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//  if (event->button() == Qt::LeftButton)
//  {
//    w->keyPressEvent();
//  }
//}

void Player::move( int xmax, int ymax )
{
  count = count+(vx*2);
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

void Player::jump()
{
  if (!jumped)
  { vy = 10; jumped = true; }
  
  y = y - vy;
  setPos(x, y);
  vy = vy - 0.25;
  
  if (y > 340)
    y = 340;
  
  
}



