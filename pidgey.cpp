#include "pidgey.h"

Pidgey::Pidgey(QPixmap* pixMap_, QPixmap* closed_, double x_, double y_)
  : Thing(pixMap_, x_, y_), closed(closed_)
{
//  setPixmap( *closed);
  open = true;
//  open = false;
  count = 0;
  vx = 0;
  vy = 0;
}

void Pidgey::setOpen(bool value)
{
  if (value)
  {
    open = true;
    setPixmap( *pixMap );
  }
  else
  {
    open = false;
    setPixmap( *closed );
  }
}

void Pidgey::move()
{
  count++;
  switch(count%50)
  {
  case 0: setPixmap( *pixMap ); open = true; break;
  case 25: setPixmap( *closed ); open = false; break;
  }
}

bool Pidgey::isOpen()
{
  return open;
}

void Pidgey::setY(double y_)
{
  y = y_;
}
