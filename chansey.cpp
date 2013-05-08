#include "chansey.h"

Chansey::Chansey(QPixmap *stand_, QPixmap *move_left_, QPixmap *move_right_, double x_,
    double y_, MyList<Thing*> *goodThings_, QGraphicsScene *scene_, double vx_)
    : Thing(stand_, x_, y_), move_left(move_left_), move_right(move_right_),
    goodThings(goodThings_), scene(scene_)
{
  originalvx = vx_;
  vx = -vx_/2;
  vy = 0;
  count = 0;
  position = 0;
  standing = false;
}

void Chansey::move()
{
  x -= vx;
  setPos(x, y);
  
  if (!standing)
  {
    position++;
    switch(position%6) {
    case 0: setPixmap( *pixMap ); break;
    case 2: setPixmap( *move_left ); break;
    case 4: setPixmap( *move_right ); break;
    }
//    x -= vx;
//    setPos(x, y);
    
    if (x >= 600)
    {
      vx = originalvx;
      standing = true;
      setPixmap( *pixMap );
    }
  }
  else if (standing)
  {
    //throw egg
    
    
  }
  
  
  
}
