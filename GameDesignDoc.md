# Game Design Document

## General Overview
This will be a sidescroll game in which the player is a Pokemon trainer trying to survive
attacks from other Pokemon

## Things
  1. A [Jigglypuff] (Images/jigglypuff.gif) that rolls onto screen. ~~A warning will appear on the
  edge of the screen to indicate that it's coming.~~ It will kill the player if he/she
  doesn't avoid it.
  1. A [Starmie] (Images/Starmie.gif) that can float in air that will whirl in for like 2 seconds and track
  after the player. It then stops moving and shoots small hyper beams. After shooting, it will leave the screen.
  If the player is caught in it or jumps into it, he/she is annihilated.
  1. A [hyper beam] (Images/hyper_beam.png) that is shot by the Starmie. Multiple beams will be shot by the Starmie
  and they will move horizontally across the screen.
  1. [Pokeballs] (Images/Pokeball.png) will be floating in the air, which the player wants to collect. 
  It cycles through 3 patterns. Some will move in a general sinusoidal fashion through the screen. Others
  will be lined in rows or in diagonal lines. The player wants to get these pokeballs.
  By getting pokeballs, the player will earn points. Moving pokeballs are worth 30 points and stationary pokeballs
  are worth 10 points.
  1. There will be a [boulder] (Images/boulder.png) that blocks the way on the ground. It is relatively stationary
  (meaning it looks like it's staying still on the ground).
  1. There is a [Pidgey] that appears by the Player's side when the player presses the up key. It moves vertically
  and also flaps its wings. It accelerates depending how long the player presses the key.
  1. ~~At certain parts, a [Chansey] (Images/chansey.png) will come out and lay eggs, which you can run into
  to find out objects inside~~
  1. ~~From the egg, you could get a floating [Mew] (Images/Mew.gif) that will accompany the user for
  a little while. It forms a forcefield that makes the user essentially invincible.~~
  
## User Interaction
The user will use the mouse to start the game and pause the game, but most of the gameplay
will be done using the keyboard. Holding the up arrow key will fly up to the top of the screen (because
your Pidgey is always with you). So the player can easily run on the ground
or be flying in the sky. When on the ground, the Pidgey disappears. There is also a restart button
on the right bottom corner of the screen and a quit button. These are represented by an arrow icon and an X icon.

## Score
The score is determined by the Pokeballs the player collects. There is no way that the score
goes down. Moving pokeballs are worth 30 points and stationary pokeballs are worth 10 points.

## Lives
The user will lose a life whenever it basically runs into anything, like the Jigglypuff,
the Starmie's hyper beam, the boulder. The player will have 3 lives. There will be icons on the 
right top corner of the screen that indicates how many lives you have left. The game is over when it loses
all 3 lives.

## User Layout
When the game starts, a [start screen] (Images/StartScreen.png) will pull up.
It will have 2 buttons with the labels start and quit.
The start button leads to [another screen] (Images/Name.png) which asks the user
to input a name. After that, the interface will display the main [gamescreen] (Images/Gameplay.png).
~~After counting for 3 seconds, the game will start.~~ In the bottom corners of the game,
there will be buttons for pausing the game and for quitting the game.

When you click the [pause button] (Images/pause.png), the game pauses.

~~If you click the [directions] (Images/Directions.png) button, it will bring up a screen with the purpose of 
the game and what each thing does.~~

If you clicke the quit button, then [GAME OVER] (Images/gameOver_word.png) will be displayed

~~If you click the [quit screen] (Images/quit.png), a GAME OVER screen will appear~~



