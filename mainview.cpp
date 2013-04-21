#include "mainview.h"

MainView::MainView(QGraphicsScene* scene, MainWindow* w_, QWidget* parent)
  : QGraphicsView(scene, parent), w(w_)
{
  
}

void MainView::keyPressEvent(QKeyEvent* keyEvent)
{
  
    w->keyPressEvent(keyEvent);
}
