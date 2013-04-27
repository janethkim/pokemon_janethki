#ifndef POKEBALL_H
#define POKEBALL_H

#include "thing.h"

/** This class represents the pokeballs that the user tries to get to
 *  gather points. Inherits from Thing class. */
class Pokeball : public Thing {
public:
  /** The constructor
   *  @param pixmap_ The picture of the pokeball
   *  @param x_ The initial x position of the pokeball
   *  @param y_ The initial y position of the pokeball
   *  @param move_ A boolean taht indicates whether the pokeball should move
   *  @param vx_ The initial x velocity of the pokeball */
  Pokeball(QPixmap *pixmap_, double x_, double y_, bool move_, double vx_);
  
  /** The inherited move function. If the pokeball is supposed to move,
   *  it will move in a sinusoidal fashion. Otherwise, it will just move
   *  across the screen with the background. In other words, it will look
   *  like it's remaining still relative to the background. */
  void move();
  
  /** This returns the number of points if/when the user hits the pokeball.
   *  If the pokeball is moving in a sinusoidal fashion, it's worth 30 points.
   *  Otherwise, it's worth 10 points.
   *  @return The points the collision with the pokeball is worth */
  int collision();
private:

  /** A boolean that is true if the Pokeball is moving sinusoidally */
  bool moving;
  
  /** The angle value that is necessary for the sinusoid function */
  double angle;
  
  /** The initial y position around which the moving pokeball will oscillate */
  double y0;
};

#endif
