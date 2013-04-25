#ifndef JIGGLYPUFF_H
#define JIFFLYPUFF_H
#include "thing.h"

class Jigglypuff: public Thing {
public:
//  Jigglypuff(QPixmap*, double, double);
  Jigglypuff(QPixmap*, QPixmap*, QPixmap*, QPixmap*, QPixmap*, QPixmap*, QPixmap*, QPixmap*, double, double, double);
  void move();
private:
  int angle;
//  QGraphicsItem* parent;
  int count;
  QPixmap *r1, *r2, *r3, *r4, *r5, *r6, *r7;
};

#endif
