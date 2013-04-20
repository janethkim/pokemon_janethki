# Game Design Document

## General Idea
My game will be something like Plants vs. Zombies. Think something like
a wave of monsters are coming, which you're going to have to prepare for.

## Things
  1. The [enemy] (Images/goomba.jpg): will come toward your main defense line at different paces and at
      different times; the way I'm imagining it is for them to move horizontally across the 
      screen in the same direction (unless perhaps I implemented some other thing that would
      turn them around).
  1. A [projectile shooter] (Images/fireflower.jpg) which will be placed where the user chooses. After that, it won't move.
      It will shoot bullets/fireballs at the enemy when it sees it in its line of sight.
  1. The bullets ([fireballs] (Images/fireball.jpg)) that are shot by the projectile shooter. Depending on the type of projectile shooter,
      these bullets may be able to travel vertically or diagonally. The simplest bullet will simply
      shoot in the direction dictated by the projectile shooter. If time allows, it will rotate 
      as it moves across the screen.
  1. A [bomb] (Images/bomb.png) which will be placed where dictated by the user, and after a short amount of time, it
      will explode and kill/damage those around it within a certain radius. Maybe after using the bomb,
      though, the user will no longer be able to place anything there (kind of like a dead zone?)
  1. Some form of [currency] (Images/coin.png) which the user will build up to buy more things to defend the main line.
      It will come out of the boxes that drop around the screen. When the user clicks the box,
      coins might come out, which will give them added currency.
  1. A [mystery box] (Images/mystery.gif) which will drop into the screen at random places. They might contain hearts or
      coins.
  1. Maybe if I have time, I will implement a [boulder] (Images/boulder.png) which the user can purchase; as a line
      of defense, it can be set as a trap, and when an enemy triggers it by stepping on it,
      it will run across the screen, killing everything in its way (moves horizontally across the
      screen, accelerating as it does so)
     
## User Interaction
The user will use the mouse, and not the keyboard, to play the game. The user clicks on the mystery
boxes to find out what's inside. They will also click on the resulting item to pick it up, like
coins or hearts. When they have enough money, they will click from a menu on the side where they
can choose which item to purchase. They will then click the location on the screen where they want
it to be placed. The shooters will automatically shoot when enemies appear in their line of vision.

## Score Tracker
There will be a set time that each round will go for, but if the player
successfully kills all the monsters before the round is completely over,
there will be a points given. With each monster destroyed, more points
will be awarded. Points will go down every time you lose a life.

## Lives
Each time a monster makes it to your line of defense, you lose a life. When this happens,
the level restarts and points are deducted. They will have a total of 3 lives; after
letting a monster get past your line of defense 3 times, you die and the game is over.
      
## Layout
When the game initially starts, there will be a [home screen]
(Images/StartScreen.png) that has three buttons: Start,
Directions, Quit. Obviously the start button starts the game,
the directions button will pop up a box that has all the directions,
and the quit button will quit from the game.

When they click the Start button, they will then be prompted to enter
a [name] (Images/Name.png) for themselves. After doing so, they'll enter
the [game screen] (Images/Gameplay.png).
It'll count down from 3 seconds and then the game will officially start.
In the right, top corner of the screen will be a running total of their score.
In left, top corner, there will be another box displaying their 
currency.

On a menu on the left that runs down the length of the screen will be 
the items which they can purchase to protect themselves from oncoming
monsters. They click on the item to select it and then click on
an area on the screen where they want it to be placed.

Also at the top right corner will be a pause button and a quit button.
When they click the [pause button] (Images/pause.png), a sort of
transparent screen will
appear that asks whether they want Directions, to Resume, or to Quit.








