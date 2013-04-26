#include "pause.h"

Pause::Pause(QPixmap* pixMap, QPixmap* clicked_, double x_, double y_, MainWindow* w_)
  : Thing(pixMap, x_, y_), w(w_), clicked(clicked_)
{ paused = false; }

void Pause::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) //if it's the left button
   {
      if (paused)
      {
        w->continueGame();
        setPixmap( *pixMap );
        paused = false;
      }
      else
      {
        setPixmap( *clicked );
        w->pauseGame();
        paused = true;
      }
   }
}

//void Pause::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//  if (event->button() == Qt::LeftButton) //if it's the left button
//   {
//      setPixmap( *pixMap );
//   
//   }
//}

