#include "obstacle.h"

Obstacle::Obstacle(QPixmap* pixMap_, double x_, double y_, double vx_)
  : Thing(pixMap_, x_, y_)
{
  vx = vx_;
  vy = 0;
}

void Obstacle::move()
{
  x -= vx;
  setPos(x, y);
}


