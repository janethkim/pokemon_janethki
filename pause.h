#ifndef PAUSE_H
#define PAUSE_H

#include "thing.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

class MainWindow;


/** This class represents the pause button on the main gameplay screen */
class Pause : public Thing {
public:
  /** Constructor
   *  @param pixMap The picture of the pause button
   *  @param clicked_ The picture of the pause button when clicked
   *  @param x_ The x position of the button
   *  @param y_ The y position of the button
   *  @param w_ Pointer to the MainWindow */
  Pause(QPixmap* pixMap, QPixmap* clicked_, double x_, double y_, MainWindow* w_);
  
  /** Inherited move function from Thing that does nothing because the button doesn't move */
  void move() { }
  
  /** Called when the user clicks on the button. Calls pauseGame() if the game isn't paused or
   *  continueGame() if the game is already paused from the MainWindow class
   *  @param event A pointer to the GraphicsSceneMouseEvent that
   *  can specify which button was clicked */
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
//  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  /** Pointer to the MainWindow */
  MainWindow* w;
  
  /** The picture of the button when it's clicked */
  QPixmap* clicked;
  
  /** True if the game is paused or false if the game isn't paused */
  bool paused;
  
};



#endif
