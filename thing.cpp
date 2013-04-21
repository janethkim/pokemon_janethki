#include "thing.h"

Thing::Thing(QPixmap* pixMap_, double x_, double y_) : pixMap(pixMap_)
{
  x = x_;
  y = y_;
  //  pixMap = pixMap_;
  setPixmap( *pixMap );
  setPos(x, y);
}

Thing::~Thing()
{ }

double Thing::getX()
{ return x; }

double Thing::getY()
{ return y; }
