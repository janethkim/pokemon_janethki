#include "starmie.h"
#include <iostream>



Starmie::Starmie(QPixmap *pixMap_, QPixmap *beampic_, Player *user_, int focus_, double x_,
double y_, MyList<Thing*> *badThings_, QGraphicsScene *scene_, double vx_)
  : Thing(pixMap_, x_, y_), user(user_), beamvx(vx_), focus(focus_), badThings(badThings_), scene(scene_),
  beampic(beampic_)
{
  receding = false;
  vx = vx_+1;
//  beam = new HyperBeam(beampic_, x_-50, y_+25, beamvx);
//  badThings->push_back(beam);
//  scene->addItem(beam);
  count = 0;
//  vx = vx_;
  vy = 3;
  vx_neg = -vx_/4;
//  beam->setVisible(false);
}

void Starmie::move()
{
  count++;
  if (!receding && x < 700 && x > 650)
  {
    vx = 0;
//    beam->setPos(x-20,y+25);
    receding = true;

//    beam->setVisible(true);
  }
  if (count < focus)
  {
    
    if (user->getY() >= y)
    {
      y += vy;
      if (y >= 330)
        y = 330;
    }
    else if (user->getY() < y)
    {
      y -= vy;
    }
//    beam->setPos(x-20,y+25);
  }
  else if (count > (focus*1.2) && count < (focus*2))
  {

    int mod = focus/10;
//    cout << "Gets here" << endl;
    if (count%mod == 0)
    {
//      cout << "Gets here." << endl;
   
      HyperBeam *temp = new HyperBeam(beampic, x-20, y+25, beamvx);
      badThings->push_back(temp);
      scene->addItem(temp);
      temp->setMove(true);
    }
    
  }
  else if (count > focus*2.5)
  {
//    beam->setMove(false);
//    beam->remove();
//   std::cout << "Gets to negative." << endl;
    vx = vx_neg;
//    beam->setVisible(false);
//    beam->setPos(x-20,y+25);
  }
  
  x -= vx;
  QGraphicsPixmapItem::setPos(x,y);
//  beam->setPos(x-20,y+25);
}

//bool Starmie::timeIsUp()
//{
//  if (count >= focus)
//    return true;
//  else
//    return false;
//}

Starmie::~Starmie()
{
//  scene->removeItem(beam);
//  badThings->remove(beam);
//  delete beam;
}
