#ifndef JIGGLYPUFF_H
#define JIFFLYPUFF_H
#include "thing.h"

/** This class represents the rolling Jigglypuff enemy. Inherits
 *  from the Thing class.
 *  @author Janet Kim */
class Jigglypuff: public Thing {
public:
//  Jigglypuff(QPixmap*, double, double);

  /** Constructor
   *  @param pixMap_ 0 degrees rotated picture
   *  @param r1_ 45 degrees rotated picture
   *  @param r2_ 90 degrees rotated picture
   *  @param r3_ 135 degrees rotated picture
   *  @param r4_ 180 degrees rotated picture
   *  @param r5_ 225 degrees rotated picture
   *  @param r6_ 270 degrees rotated picture
   *  @param r7_ 315 degrees rotated picture
   *  @param x_ initial x position
   *  @param y_ initial y position
   *  @param vx_ x velocity */
  Jigglypuff(QPixmap* pixMap_, QPixmap* r1_, QPixmap* r2_, QPixmap* r3_, 
      QPixmap* r4_, QPixmap* r5_, QPixmap* r6_,QPixmap* r7_, double x_, double y_, double vx_);
   
  /** Switches in between the 8 images to make it seem like it's rolling while also moving horizontally
   *  across the screen. */
  void move();
private:
//  int angle;
//  QGraphicsItem* parent;
  /** Counter for determining which rotation picture the item should be set to */
  int count;
  
  /** 45 degrees rotated picture*/
  QPixmap *r1;
  
  /** 90 degrees rotated picture */
  QPixmap *r2;
  
  /** 135 degrees rotated picture */
  QPixmap *r3;
  
  /** 180 degrees rotated picture */
  QPixmap *r4;
  
  /** 225 degrees rotated picture */
  QPixmap *r5;
  
  /** 270 degrees rotated picture */
  QPixmap *r6;
  
  /** 315 degrees rotated picture */
  QPixmap *r7;
};

#endif
