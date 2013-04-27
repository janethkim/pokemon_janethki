#ifndef PIDGEY_H
#define PIDGEY_H

#include "thing.h"

/** This class represents the Pidgey that flies with the user. */
class Pidgey : public Thing {
public:
  /** Constructor
   *  @param pixMap_ The picture of the Pidgey with wings open
   *  @param closed_ The picture of the Pidgey with wings closed
   *  @param x_ The initial x position
   *  @param y_ The initial y position */
  Pidgey(QPixmap* pixMap_, QPixmap* closed_, double x_, double y_);
  
  /** This move function is inherited from the Thing class. The 
   *  wings flap when moving. */
  void move();
  
  /** Set the y position of the Pidgey.
   *  @param y_ The y position */
  void setY(double y_);
  
  /** Sets the picture that represents the Pidgey.
   *  @param value A boolean that if it's true, the picture will be set
   *  to the one with the wings open */
  void setOpen(bool value);
  
  /** Returns true if the wings are open.
   *  @return True if wings are open; False if wings are closed */
  bool isOpen();
  
private:
  /** The picture of the Pidgey with wings closed */
  QPixmap *closed;
  
  /** The counter for determining the picture being used (whether open or closed wings) */
  int count;
  
  /** True if the wings are open; false if the wings are closed */
  bool open;
  
};

#endif
