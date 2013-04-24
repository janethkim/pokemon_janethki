#include "pokeball.h"
#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265

Pokeball::Pokeball(QPixmap *pixmap_, double x_, double y_, bool move_)
  : Thing(pixmap_, x_, y_), moving(move_), y0(y_)
{
  vx = 0.5;
  if (moving)
  {
    vx = 0.5;
    if (y_ < 200)
      vy = -1;
    else
      vy = 1;
  }
  angle = 0;
}


void Pokeball::move()
{
  
  if (moving)
  {
    angle += PI/300;
    y = y0 + 100*sin(angle);
  }
  x -= vx;
  setPos(x, y);
}

int Pokeball::collision()
{
  if (moving)
    return 30;
  else
    return 10;
}

