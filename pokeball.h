#ifndef POKEBALL_H
#define POKEBALL_H

#include "thing.h"

class Pokeball : public Thing {
public:
  Pokeball(QPixmap *pixmap_, double x_, double y_, bool move_);
  void move();
  int collision();
private:
  bool moving;
  double angle;
  double y0;
};

#endif
