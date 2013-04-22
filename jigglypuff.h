#ifndef JIGGLYPUFF_H
#define JIFFLYPUFF_H
#include "thing.h"

class Jigglypuff: public Thing {
public:
  Jigglypuff(QPixmap* pixMap_, double x_, double y_);
  void move();
private:
  int angle;
};

#endif
