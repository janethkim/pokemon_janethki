#include "hyperbeam.h"

HyperBeam::HyperBeam(QPixmap *pixMap_, double x_, double y_, MyList<Thing*> *badThings_ , QGraphicsScene *scene_)
  : Thing(pixMap_, x_, y_), badThings(badThings_), scene(scene_), canMove(false)
{
  vx = 0.7;
  vy = 0;
  xlast = 0;
}



void HyperBeam::move()
{
  if(!canMove)
    return;
  if (xlast > x)
    xlast = x;
//  if (scene != NULL && badThings != NULL)
//  {
//    HyperBeam *temp = new HyperBeam(pixMap, xlast+4, y, NULL, NULL);
//    scene->addItem(temp);
//    badThings->push_back(temp);
//    moreBeams.push_back(temp);
//  }
}

void HyperBeam::remove()
{
  
//  for (int i = 0; i < moreBeams.size(); i++)
//  {
//    scene->removeItem(moreBeams[i]);
//    badThings->remove(moreBeams[i]);
//    delete moreBeams[i];
//  }
  moreBeams.clear();
}

void HyperBeam::setMove(bool value)
{ canMove = value; }


