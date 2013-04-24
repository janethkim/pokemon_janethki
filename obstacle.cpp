#include "obstacle.h"

Obstacle::Obstacle(QPixmap* pixMap_, double x_, double y_)
  : Thing(pixMap_, x_, y_)
{
  vx = 0.5;
  vy = 0;
}

void Obstacle::move()
{
  x -= vx;
  setPos(x, y);
}


