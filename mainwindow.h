#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "background.h"

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y 500

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow();
  ~MainWindow();
  void show();
  
private:
  QWidget *window;
  QTimer *timer;
  QGraphicsScene *scene;
  QGraphicsView *view;
  Background *bg_1;
  Background *bg_2;
  QPixmap* bgPic;
  
public slots:
  void handleTimer();

};

#endif
