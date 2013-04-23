#ifndef PIDGEY_H
#define PIDGEY_H

#include "thing.h"

class Pidgey : public Thing {
public:
  Pidgey(QPixmap* pixMap_, QPixmap* closed_, double x_, double y_);
  void move();
  void setY(double y_);
  void setOpen(bool value);
  bool isOpen();
  
private:
  QPixmap *closed;
  int count;
  bool open;
  
};

#endif
