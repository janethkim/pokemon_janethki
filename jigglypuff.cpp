#include "jigglypuff.h"

Jigglypuff::Jigglypuff(QPixmap* pixMap_, double x_, double y_)
  : Thing(pixMap_, x_, y_)
{
  vx = 2;
  vy = 0;
  angle = 0;
}

void Jigglypuff::move()
{
  x -= vx;
}
