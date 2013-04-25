#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "thing.h"

class Obstacle : public Thing {
public:
  Obstacle(QPixmap *pixMap_, double x_, double y_, double vx_);
  ~Obstacle()
  {}
  void move();
private:

};

#endif
