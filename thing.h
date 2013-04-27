#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>


/** The abstract base Thing class from which all other Things within the 
 *  game will be derived from. It derives from QGraphicsPixmapitem.
 *  @author Janet Kim */
class Thing : public QGraphicsPixmapItem {
public:
  /** The constructor that initializes the picture, its x and y position.
   *  @param pixMap_ The picture that will represent the item.
   *  @param x_ The initial x position
   *  @param y_ The initial y position */
  Thing(QPixmap* pixMap_, double x_, double y_);
  
  /** The destructor of Thing */
  ~Thing();
  
  /** A pure virtual function that dictates how the Thing objects will move */
  virtual void move() = 0;
  
  /** A virtual function that returns the score upon collision
   *  @return An int that indicates how many points the collision is worth */
  virtual int collision() { return 0; }
  
  /** Returns the x position
   *  @return A double that represents the x position */
  double getX();
  
  /** Returns the y position
   *  @return A double that represents the y position */
  double getY();
  
protected:
  /** The x position */
  double x;
  
  /** The y position */
  double y;
  
  /** The velocity in the x direction */
  double vx;
  
  /** The velocity in the y direction */
  double vy;
  
  /** The picture that represents the item */
  QPixmap* pixMap;
  
};

//Thing::Thing(QPixMap *pixMap_, int x_, int y_) : pixMap(pixMap_)
//{
//  x = x_;
//  y = y_;
////  pixMap = pixMap_;
//  setPixmap( *pixMap );
//  setPos(x, y);
//}



#endif
