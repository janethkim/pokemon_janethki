#include "background.h"
#include <cstdlib>

Background::Background(QPixmap* pixMap_, double x_, double y_, double vx_)
  : Thing(pixMap_, x_, y_)
{
  vx = vx_;
  vy = 0;
}

int Background::getX()
{
  return x;
}

void Background::setNewPos(int x_, int y_)
{
  setPos(x_,y_);
  x = x_;
  y = y_;
}

void Background::move(int xmax, int ymax)
{
  x -= vx;
  if ( x < -xmax )
    x = xmax-1;
  y -= vy;
  if ( abs(y) > ymax )
    y = ymax;
    
  setPos(x, y);

  
}

void Background::speedUp()
{
  vx += 0.01;
}
