#ifndef RESTART_H
#define RESTART_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;


/** This class is the restart button. Inherits from Thing. */
class Restart : public Thing {
public:
  /** The constructor for the restart button
   *  @param pixMap The picture of the restart button
   *  @param x_ The x position
   *  @param y_ The y position
   *  @param w_ The pointer to the MainWindow */
  Restart(QPixmap* pixMap, double x_, double y_, MainWindow* w_);
  
  /** The inherited move function does nothing. */
  void move() { }
  
  /** When the user clicks on the button, it calls the restartGame()
   *  function of the MainWindow. Pretty much restarts the game.
   *  @param event A QGraphicsSceneMouseEvent that is passed in whenever
   *    the button is clicked */
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
//  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  /** A pointer to the MainWindow */
  MainWindow* w;
  
  
};



#endif
