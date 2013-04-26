#ifndef HYPERBEAM_H
#define HYPERBEAM_H

#include "thing.h"
#include "mylist.h"
#include <QGraphicsScene>

class HyperBeam : public Thing {
public:
  HyperBeam(QPixmap *pixMap_, double x_, double y_, double vx_);
  void move();
  void setPos(int x_, int y_);
//  void remove();
  void setMove(bool value);
private:
//  MyList<Thing*> *badThings;
//  QGraphicsScene *scene;
//  MyList<HyperBeam*> moreBeams;
  int xlast, count;
  bool canMove;
  
};

#endif
