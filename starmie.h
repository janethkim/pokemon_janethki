#ifndef STARMIE_H
#define STARMIE_H

#include "thing.h"
#include "player.h"
#include "hyperbeam.h"

class Starmie : public Thing {
public:
  Starmie(QPixmap*, QPixmap*, Player*, int, double, double, MyList<Thing*>*, QGraphicsScene*, double);
  ~Starmie();
  HyperBeam* getBeam();
  void move();
  bool timeIsUp();
private:
  Player *user;
  double beamvx;
  int focus, count;
  HyperBeam *beam;
  MyList<Thing*> *badThings;
  QGraphicsScene *scene;
  QPixmap* beampic;

};

#endif
