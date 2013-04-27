#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"
#include "pidgey.h"
#include <string>
//#include <QGraphicsSceneMouseEvent>
using namespace std;

/** This class represents the player, controlled by the one playing the game.
 *  Inherits from the Thing class.
 *  @author Janet Kim */
class Player : public Thing {
public:
  /** Constructor
   *  @param pixMap_ The picture of the standing position
   *  @param left The picture of the left running position
   *  @param right The picture of the right running position
   *  @param pidgey_ The pidgey that appears when the player presses the up key
   *  @param x_ The initial x position
   *  @param y_ The initial y position
   *  @param vx_ The initial velocity in the x direction */
  Player(QPixmap* pixMap_, QPixmap* left, QPixmap* right, Pidgey* pidgey_, double x_, double y_, double vx_);
  
  /** This move function switches between the three pictures of the user to
   *  make it seem like he/she is walking. */
  void move();
  
  /** This function makes it seem like the user is jumping. */
  void jump();
  
  /** This function is called when the player releases the up key.
   *  The player will start falling down. */
  void fall();
  
  /** This function is called when the player presses the up key.
   *  The player starts moving up and the Pidgey appears to
   *  help the player "fly". */
  void rise();
  
  /** This boolean value indicates whether or not the player has started
   *  flying. If so, then the y velocity doesn't have to be set.*/
  bool jumped;
  
  /** This function controls how the player moves when he/she dies. */
  void die();
  
  /** This function decreases the player's number of lives by 1. */
  void decreaseLife();
  
  /** Returns true if the player has no more lives left.
   *  @return A boolean that is true if the player is dead or false if they're not */
  bool gameOver();
  
  /** Resets the position and velocities of the player to initial values.
   *  @param vx_ The x velocity of the player */
  void restart(double vx_);
  
  /** Updates the score of the player by the given amount.
   *  @val The amount by which the score should increase */
  void updateScore(int val);
  
  /** Returns the player's score
   *  @return The player's score */
  int getScore();
  
  /** Sets the name of the player
   *  @param name_ The name of the player to change to */
  void setName(string name_);
  
  /** Returns the name of the player 
   *  @return The name of the player */
  string getName();
  
  /** Returns the number of lives left 
   *  @return The number of lives left */
  int getLives();
  
//protected:
//  void mousePressEvent(QGraphicsSceneMouseEvent *event);
 
private:
  /** An index that indicates whether the picture is in standing,
   *  left, or right position */
  int position;
  
  /** The picture of the left running position */
  QPixmap *left;
  
  /** The picture of the right running position */
  QPixmap *right;
  
  /** A counter that determines whether the user is in standing, left, or right position */
  int count;
  
  /** The angle by which the user is rotated */
  int angle;
  
  /** The number of lives that the player has left */
  int lives;
  
  /** The player's score in the game */
  int score;
  
  /** A pointer to the bird that accompanies the player when he flies */
  Pidgey *pidgey;
  
  /** The player's username */
  string name;


};


#endif
