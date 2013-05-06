#include "quit.h"

Quit::Quit(QPixmap* pixMap, double x_, double y_, MainWindow* w_)
  : Thing(pixMap, x_, y_), w(w_)
{ }

void Quit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) //if it's the left button
   {
//      w->writeScore();
      w->callQuit();
   }
}

