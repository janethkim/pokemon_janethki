#include "background.h"
#include <cstdlib>

Background::Background(QPixmap* pixMap_, double x_, double y_)
  : Thing(pixMap_, x_, y_)
{
  vx = 0.5;
  vy = 0;
}

void Background::move(int xmax, int ymax)
{
  x -= vx;
  if ( x <= -xmax )
    x = xmax;
  y -= vy;
  if ( abs(y) > ymax )
    y = ymax;
    
  setPos(x, y);

  
}
