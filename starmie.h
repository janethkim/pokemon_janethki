#ifndef STARMIE_H
#define STARMIE_H

#include "thing.h"
#include "player.h"
#include "hyperbeam.h"


/** The Starmie class inherits from the Thing class and
 *  tracks the position of the player. After that it will shoot
 *  hyper beams at the player.
 *  @author Janet Kim */
class Starmie : public Thing {
public:
  /** The constructor for the Starmie class.
   *  @param pixMap_ The picture for the Starmie 
   *  @param beampic_ The picture for the hyper beam 
   *  @param user_ The pointer to the main player
   *  @param focus_ A number that determines how long it's tracking the user for
   *  @param x_ The initial x position
   *  @param y_ The initial y position
   *  @param badThings_ A pointer to the list of bad Things
   *  @param scene  A pointer to the main gameplay scene
   *  @param vx_ The initial x velocity */
  Starmie(QPixmap *pixMap_, QPixmap *beampic_, Player *user_, int focus_, double x_,
    double y_, MyList<Thing*> *badThings_, QGraphicsScene *scene_, double vx_);
    
  /** Destructor */
  ~Starmie();
  
//  /** */
//  HyperBeam* getBeam();
  
  /** Moves the Starmie a certain amount towards the user for a limited time.
   *  Then it shoots out new hyper beams. */
  void move();
  
//  bool timeIsUp();
private:
  /** A pointer to the player */
  Player *user;
  
  /** The velocity of the beams that are shot out */
  double beamvx;
  
  /** The number that indicates for how long the starmie should track the user */
  int focus;
  
  /** The count that indicates how many times the starmie's move function was called */
  int count;
  
  /** The starting beam that travels intiially with the Starmie */
  HyperBeam *beam;
  
  /** The pointer to the list of bad Things so that the Starmie can add hyper beams to
   *  the list of badThings */
  MyList<Thing*> *badThings;
  
  /** A pointer to the main gameplay scene so that I can add the hyper beams to the scene */
  QGraphicsScene *scene;
  
  /** The picture of the hyper beam */
  QPixmap* beampic;

};

#endif
