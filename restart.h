#ifndef RESTART_H
#define RESTART_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;

class Restart : public Thing {
public:
  Restart(QPixmap* pixMap, double x_, double y_, MainWindow* w_);
  void move() { }
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
//  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  MainWindow* w;
  
  
};



#endif
