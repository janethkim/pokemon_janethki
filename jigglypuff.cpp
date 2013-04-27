#include "jigglypuff.h"
#include <cmath>

//#define PI 3.14159265

//Jigglypuff::Jigglypuff(QPixmap* pixMap_, double x_, double y_)
//  : Thing(pixMap_, x_, y_) 
//{
//  vx = 0.5;
//  vy = 0;
//  angle = 0;
////  count = 0;
////  setTransformOriginPoint(50, 50);
//}

Jigglypuff::Jigglypuff(QPixmap* pixMap_, QPixmap* r1_, QPixmap* r2_, QPixmap* r3_, 
QPixmap* r4_, QPixmap* r5_, QPixmap* r6_,QPixmap* r7_, double x_, double y_, double vx_)
  : Thing(pixMap_, x_, y_), r1(r1_), r2(r2_), r3(r3_), r4(r4_), r5(r5_), r6(r6_), r7(r7_)
{
  vx = vx_*2;
  vy = 0;
//  angle = 0;
  count = 0;
//  setTransformOriginPoint(50, 50);
}

void Jigglypuff::move()
{
  count ++; 
//  angle -= 5;
//  setTransformOriginPoint(boundingRect().center());
//  rotate(angle);
//  angle -= 5;
//  setPos(0, 0);
//  setRotation(angle);
//  setPos(x-40*cos(angle*PI/180), y - 25*sin(angle*PI/180));
//  setTransform(QTransform().translate(800, 335).rotate(angle).translate(-800,-335));
  x -= vx;
  setPos(x, y);
//  
//  setRotation(angle);
//  if (angle <= -360)
//    angle = 0;
//  setPos(x, y);
//  setPos(x - 30*cos(angle*PI/180),y - 51*sin(angle*PI/180));
  switch (count%64)
  {
  case 0: setPixmap( *pixMap ); break;
  case 8: setPixmap( *r7 ); break;
  case 16: setPixmap( *r6 ); break;
  case 24: setPixmap( *r5 ); break;
  case 32: setPixmap( *r4 ); break;
  case 40: setPixmap( *r3 ); break;
  case 48: setPixmap( *r2 ); break;
  case 56: setPixmap( *r1 ); break;
  }
//  angle += 5;
//  setRotation(angle);
  

//  setTransformOriginPoint(x, y);
 
}
