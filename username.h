#ifndef USERNAME_H
#define USERNAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>

class MainWindow;

class Username : public QGraphicsView
{
  Q_OBJECT
public:
  Username(QWidget *parent, QPixmap *bg_, MainWindow *m);
private:
  QPushButton* enter;
  QLineEdit* name;
  MainWindow *main;
  QGraphicsScene* scene;
  QPixmap *bg;
  QGraphicsPixmapItem* background;
  QGraphicsRectItem* grid;
  QVBoxLayout *layout;
//  QPaintEvent *p;
  QWidget *overall;
  
public slots:
  void handleEnter();

};

#endif
