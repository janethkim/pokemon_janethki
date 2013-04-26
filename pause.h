#ifndef PAUSE_H
#define PAUSE_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;

class Pause : public Thing {
public:
  Pause(QPixmap* pixMap, QPixmap* clicked_, double x_, double y_, MainWindow* w_);
  void move() { }
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
//  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  MainWindow* w;
  QPixmap* clicked;
  bool paused;
  
};



#endif
