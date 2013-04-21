#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Thing : public QGraphicsPixmapItem {
public:
  Thing(QPixmap* pixMap_, double x_, double y_);
  ~Thing();
  virtual void move(int xmax, int ymax) = 0;
  
protected:
  double x;
  double y;
  double vx;
  double vy;
  QPixmap* pixMap;
  
};

//Thing::Thing(QPixMap *pixMap_, int x_, int y_) : pixMap(pixMap_)
//{
//  x = x_;
//  y = y_;
////  pixMap = pixMap_;
//  setPixmap( *pixMap );
//  setPos(x, y);
//}



#endif
