#include "player.h"  


Player::Player(QPixmap* pixMap_, QPixmap* left_, QPixmap* right_, Pidgey* pidgey_, double x_, double y_)
  : Thing(pixMap_, x_, y_), jumped(false), pidgey(pidgey_)
{
  count = 0;
  position = 0;
  vx = 0.5;
  vy = 0;
  angle = 0;
  left = left_;
  right = right_;
  lives = 3;
  score = 0;
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

void Player::fall()
{

  vy = vy - 0.1;
  if (vy < -5)
    vy = -5;
  y = y -vy;
  if (y > 340)
  {  y = 340; vy = 0; }
  if ((y-65) < 0)
    y = 65;
  setPos(x,y);
  if (pidgey->isOpen())
  { pidgey->setPos(x-30, y-80); pidgey->setY(y-80); }
  else
  {  pidgey->setPos(x-30, y-65); pidgey->setY(y-65); }
  
  if (vy < 0)
    pidgey->setOpen(true);
//  else
//    pidgey->move();
    
  if(pidgey->getY() >= 260)
    pidgey->setVisible(false);
}

void Player::rise()
{
  if(!jumped)
  { vy = 3; jumped = false; pidgey->setVisible(true); }
  
  y = y - vy;
  if ((y-65) < 0)
  { y =65; vy = 0; }
  setPos(x,y);
  pidgey->setOpen(false);
  
  pidgey->setPos(x-30, y-65); pidgey->setY(y-65);
//  pidgey->move();
  vy += 0.5;
  
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

void Player::updateScore(int val)
{
  score += val;
}

int Player::getScore()
{
  return score;
}



