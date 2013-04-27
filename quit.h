#ifndef QUIT_H
#define QUIT_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;

/** This class is the quit button on the gameplay screen */
class Quit : public Thing {
public:
  /** The constructor for the quit button
   *  @param pixMap The picture of the quit button
   *  @param x_ The x position
   *  @param y_ The y position
   *  @param w_ The pointer to the MainWindow */
  Quit(QPixmap* pixMap, double x_, double y_, MainWindow* w_);
  
  /** The inherited move function does nothing. */
  void move() { }
  
  /** When the user clicks on the button, it calls the callQuit() slot
   *  function of the MainWindow. Quits the game.
   *  @param event A QGraphicsSceneMouseEvent that is passed in whenever
   *    the button is clicked */
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
//  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  /** A pointer to the MainWindow */
  MainWindow* w;
  
  
};



#endif
