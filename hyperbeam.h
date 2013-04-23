#ifndef HYPERBEAM_H
#define HYPERBEAM_H

#include "thing.h"
#include "mylist.h"
#include <QGraphicsScene>

class HyperBeam : public Thing {
public:
  HyperBeam(QPixmap *pixMap_, double x_, double y_, MyList<Thing*> *badThings_, QGraphicsScene *scene_);
  void move();
  void remove();
  void setMove(bool value);
private:
  MyList<Thing*> *badThings;
  QGraphicsScene *scene;
  MyList<HyperBeam*> moreBeams;
  int xlast;
  bool canMove;
  
};

#endif
