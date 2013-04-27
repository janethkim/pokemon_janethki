#include "hyperbeam.h"
#include <iostream>


HyperBeam::HyperBeam(QPixmap *pixMap_, double x_, double y_, double vx_)
  : Thing(pixMap_, x_, y_), canMove(false)
{
  vx = vx_*4;
  vy = 0;
//  xlast = 0;
//  count = 0;
}



void HyperBeam::move()
{
  if(!canMove)
    return;
//  if (xlast > x)
//      xlast = x;
//  count++;
  x -= vx;
  QGraphicsPixmapItem::setPos(x, y);
//  std::cout << "Beam being moved?" << endl;
//  if (scene != NULL && badThings != NULL && (count%25 == 0) && xlast > 200)
//  {
//    HyperBeam *temp = new HyperBeam(pixMap, xlast-25, y, NULL, NULL);
//    xlast -= 25;
//    scene->addItem(temp);
//    badThings->push_back(temp);
//    moreBeams.push_back(temp);
//  }
}

//void HyperBeam::remove()
//{
////  
////  for (int i = 0; i < moreBeams.size(); i++)
////  {
////    scene->removeItem(moreBeams[i]);
////    badThings->remove(moreBeams[i]);
////    delete moreBeams[i];
////  }
////  moreBeams.clear();
//}

void HyperBeam::setMove(bool value)
{ canMove = value; }


void HyperBeam::setPos(int x_, int y_)
{
  QGraphicsItem::setPos(x_, y_);
  x = x_;
  y = y_;
}

