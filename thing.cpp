#include "thing.h"

Thing::Thing(QPixMap *pixMap_, int x_, int y_)
{
  x = x_;
  y = y_;
  pixMap = pixMap_;
  setPixmap( *pixMap );
  setPos(x, y);
}

