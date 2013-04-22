#include "player.h"  


Player::Player(QPixmap* pixMap_, QPixmap* left_, QPixmap* right_, double x_, double y_)
  : Thing(pixMap_, x_, y_), jumped(false)
{
  count = 0;
  position = 0;
  vx = 0.5;
  vy = 0;
  angle = 0;
  left = left_;
  right = right_;
  lives = 3;
}

//void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//  if (event->button() == Qt::LeftButton)
//  {
//    w->keyPressEvent();
//  }
//}

void Player::move()
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
  { vy = 5; jumped = true; }
  
  y = y - vy;
  setPos(x, y);
  vy = vy - 0.1;
  
  if (y > 340)
    y = 340;
  
  
}

void Player::die()
{
  //rotate the player
  angle += 1;
  setRotation(angle);
  y += 0.5;
  setPos(x, y);
}

bool Player::decreaseLife()
{
  lives--;
  if (lives <= 0)
    return true;
  else
    return false;
}



