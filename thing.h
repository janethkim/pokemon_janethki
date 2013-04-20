#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Thing : public QGraphicsPixmapItem {
public:
  Thing();
  virtual void move() = 0;
private:
  int x;
  int y;
  int vx;
  int vy;
  QPixmap* pixMap;
  
}
