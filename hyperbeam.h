#ifndef HYPERBEAM_H
#define HYPERBEAM_H

#include "thing.h"
#include "mylist.h"
#include <QGraphicsScene>

/** This class represents the hyper beams shot by the Starmie. Inherits from Thing class.
 *  @author Janet Kim */
class HyperBeam : public Thing {
public:
  /** Constructor
   *  @param pixMap_ The image for the hyper beam
   *  @param x_ initial x position
   *  @param y_ initial y position
   *  @param vx_ The x velocity */
  HyperBeam(QPixmap *pixMap_, double x_, double y_, double vx_);
  
  /** Moved horizontally across the screen. */
  void move();
  
  /** Set the position of the hyper beam.
   *  @param x_ The new x position
   *  @param y_ The new y position */
  void setPos(int x_, int y_);
//  void remove();

  /** Indicates whether the hyper beam was allowed to move
   *  @value If true, the hyper beam would move; if not,
   *  the hyper beam wouldn't move */
  void setMove(bool value);
private:
//  MyList<Thing*> *badThings;
//  QGraphicsScene *scene;
//  MyList<HyperBeam*> moreBeams;
  
//  int xlast;
  
//  int count;
  /** Indicates whether the hyper beam can move. If true, it can. If false, it can't. */
  bool canMove;
  
};

#endif
