#ifndef QUIT_H
#define QUIT_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;

class Quit : public Thing {
public:
  Quit(QPixmap* pixMap, double x_, double y_, MainWindow* w_);
  void move() { }
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
//  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  MainWindow* w;
  
  
};



#endif
