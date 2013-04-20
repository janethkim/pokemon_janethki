#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
  Q_OBJECT
public:
  MainWindow();
  ~MainWindow();
  
private:
  QWidget *window;
  QTimer *timer;
  QGraphicScene *scene;
  QGraphicsView *view;
  
public slots:
  void handleTimer();

};

#endif
