#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "thing.h"

/** This class represents the sliding background that makes it seem like
 *  the user is moving forwards. Inherits from the Thing class. */
class Background : public Thing {
public:
  /** Constructor 
   *  @param pixMap_ The backgrond image
   *  @param x_ The initial x position
   *  @param y_ The initial y position
   *  @param vx_ The x velocity */
  Background(QPixmap *pixMap_, double x_, double y_, double vx_);
  
  /** Destructor */
  ~Background() {}
  
  /** The Background image slides to the left and then after leaving the scene
   *  it moves to the right side of the scene.
   *  @param xmax The width of the screen
   *  @param ymax The height of the screen */
  void move(int xmax, int ymax);
  
  /** The move function inherited from Thing and it does nothing */
  void move() {};
  

//  void die();
//  void speedUp();

  /** Returns the x position of the Background
   *  @return The x position of the Background */
  int getX();
  
  /** Sets the new position of the Background
   *  @param x_ The new x position
   *  @param y_ The new y position */
  void setNewPos(int x_, int y_);

};

#endif
