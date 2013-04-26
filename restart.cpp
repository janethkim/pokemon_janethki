#include "restart.h"

Restart::Restart(QPixmap* pixMap, double x_, double y_, MainWindow* w_)
  : Thing(pixMap, x_, y_), w(w_)
{ }

void Restart::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) //if it's the left button
   {
      w->gameStart();
   }
}

