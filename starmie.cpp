#include "starmie.h"
#include <iostream>
using namespace std;


Starmie::Starmie(QPixmap *pixMap_, QPixmap *beampic_, Player *user_, int focus_, double x_,
double y_, MyList<Thing*> *badThings_, QGraphicsScene *scene_)
  : Thing(pixMap_, x_, y_), user(user_), focus(focus_), badThings(badThings_), scene(scene_)
{

  beam = new HyperBeam(beampic_, x_-50, y_+25, badThings, scene);
  badThings->push_back(beam);
  scene->addItem(beam);
  count = 0;
  vx = 0.5;
  vy = 0.5;
//  beam->setVisible(false);
}

void Starmie::move()
{
  count++;
  if (x < 700 && x > 650)
  {
    vx = 0;
    beam->setPos(x-20,y+25);
//    beam->setVisible(true);
  }
  if (count < focus)
  {
    
    if (user->getY() >= y)
    {
      y += vy;
    }
    else if (user->getY() < y)
    {
      y -= vy;
    }
  }
  else if (count < 1000)
    beam->setMove(true);
  else
  {
    beam->setMove(false);
//    beam->remove();
    vx = -0.5;
//    beam->setVisible(false);
    beam->setPos(x-20,y+25);
  }
  
  x -= vx;
  setPos(x,y);
  beam->setPos(x-20,y+25);
}

bool Starmie::timeIsUp()
{
  if (count >= focus)
    return true;
  else
    return false;
}

Starmie::~Starmie()
{
  scene->removeItem(beam);
  badThings->remove(beam);
  delete beam;
}
