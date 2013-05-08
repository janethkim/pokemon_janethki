#ifndef CHANSEY_H
#define CHANSEY_H

#include "thing.h"
#include "mylist.h"

/** This class is a Chansey that will run in and drop some eggs
 *  and then run out. 
 *  @author Janet Kim */
class Chansey : public Thing {
public:
  /** The constructor for the Chansey class
   *  @param  stand The standing picture of Chansey
   *  @param move_left Chansey moving left 
   *  @param move_right Chansey moving right
   *  @param x_ The x position
   *  @param y_ The y position
   *  @param goodThings_ The pointer to the list of good Things
   *  @param scene_ A pointer to the main gameplay scene
   *  @param vx_ The velocity with which the Chansey should come in */
  Chansey(QPixmap *stand_, QPixmap *move_left_, QPixmap *move_right_, double x_,
    double y_, MyList<Thing*> *goodThings_, QGraphicsScene *scene_, double vx_);
  
  /** Moves the Chansey onto the screen. Stands for a moment to throw some eggs.
   *  Then continues to run off screen. */
  void move();
  
private:
  /** Picture of Chansey moving left */
  QPixmap *move_left;
  
  /** Picture of Chansey moving right */
  QPixmap *move_right;
  
  /** The pointer to the list of goood Things so that Chansey can add eggs to
   *  the list of goodThings */
  MyList<Thing*> *goodThings;
  
  /** A pointer to the main gameplay scene so that I can add the eggs to the scene */
  QGraphicsScene *scene;
  
  /** Time to throw eggs */
  int count;
  
  /** 2nd iterator to set the picture */
  int position;
  
  /** True if Chansey is standing; false if Chansey is running */
  bool standing;
  
  /** The speed at which the background moves */
  double originalvx;
};


#endif
