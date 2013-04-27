#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "thing.h"

/** This class represents the rock that blocks the path. Inherits from Thing class. */
class Obstacle : public Thing {
public:
  /** Constructor
   *  @param pixMap_ The image of the boulder 
   *  @param x_ The initial x position
   *  @param y_ The initial y position
   *  @param vx_ The x velocity */
  Obstacle(QPixmap *pixMap_, double x_, double y_, double vx_);
  
  /** Destructor */
  ~Obstacle()
  {}
  
  /** Decrements the x position by the x velocity. Should remain still
   *  relative to the background (so player looks like he/she is moving
   *  past the boulder). */
  void move();
private:

};

#endif
