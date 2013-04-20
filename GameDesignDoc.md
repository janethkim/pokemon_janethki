# Game Design Document

## General Overview
This will be a sidescroll game in which the player is a Pokemon trainer trying to survive
attacks from other Pokemon

## Things
  1. A Jigglypuff that rolls onto screen. A warning will appear on the
  edge of the screen to indicate that it's coming. It will roll over the player if he/she
  doesn't jump over it.
  1. A Starmie that can float in air that will whirl in for like 2 seconds, after which it
  will shoot a hyper beam for a certain amount of time. If the player is caught
  in it or jumps into it, he/she is annihilated.
  1. Pokeballs will be floating in the air, which the player wants to collect. Some will
  move in a general sinusoidal fashion through the screen which the player wants
  to aim for to get. Others will be lined up in rows on the ground or randomly in the air.
  By getting pokeballs, the player will earn points. Certain pokeballs
  are worth more than others.
  1. There will be general obstacles. For example, a boulder that blocks the way on the
  ground. Legendary Pokemon (Articuno, Moltres, Zapdos) that float in the air that will
  kill you if you run into them.
  1. At certain parts, a Chansey will come out and lay eggs, which you can run into
  to find out objects inside. If you get a special item, you'll get a floating Mew beside you
  that makes a forcefield or something around you that lets you run through anything.
  
## User Interaction
The user will use the mouse to start the game and pause the game, but most of the gameplay
will be done using the keyboard. The up and down arrows will let you jump or crouch down.
Holding the up arrow key will fly up to the top of the screen (I guess you have a 
Dragonite with you or something that flies you up). So the player can easily run on the ground
or be flying in the sky.

## Score
The score is determined by the Pokeballs the player collects. There is no way that the score
goes down. When the game ends, there will also be a time bonus depending on how long
the user successfully played the game for. 

## Lives
The user will lose a life whenever it basically runs into anything, like the Jigglypuff,
the Starmie's hyper beam, the general obstacles (boulder, legendary Pokemon). Normally, the player
only has one life. I may make it so that some of the eggs have a heart inside them, but that will
be rare. It will die when it loses all of its lives.

## User Layout
When the game starts, a [start screen] (Images/StartScreen.png) will pull up.
It will have 3 buttons with the labels
start, directions, and quit. The start button leads to [another screen] (Images/Name.png) which asks the user
to input a name. After that, the interface will display the main gamescreen.
After counting for 3 seconds, the game will start. In the top right corner of the game,
there will be buttons for pausing the game and for quitting the game.

When you click the [pause button] (Images/pause.png), it will lead you to another screen that has 3 buttons:
resume game, directions, and quit.

If you click the directions button, it will bring up a screen with the purpose of 
the game and what each thing does.

If you click the quit screen, it will display the score, which the user can click OK.
Then the window closes.



