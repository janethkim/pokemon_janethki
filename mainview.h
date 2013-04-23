#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "mainwindow.h"

class MainWindow;

class MainView: public QGraphicsView {
public:
  MainView() {}
  MainView(QGraphicsScene *scene, MainWindow* w_, QWidget* parent);
protected:
  void keyPressEvent(QKeyEvent* keyEvent);
  void keyReleaseEvent(QKeyEvent* keyEvent);
private:
  MainWindow* w;
  
};

#endif
