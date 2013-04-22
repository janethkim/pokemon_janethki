#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "thing.h"

class Background : public Thing {
public:
  Background(QPixmap *pixMap_, double x_, double y_);
  ~Background() {}
  void move(int xmax, int ymax);
  void move() {};
  void die();

};

#endif
