/******************************************
 * File: robot.h
 *
 * You should not need to change this file.
 ******************************************/

#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

class Robot
{
private:
   Point position;
   int energy;

public:
   void display() const;

   Robot()
   {
      energy = 100;
   }

   Robot(int energy)
   {
      setEnergy(energy);
   }

   Robot(Point p, int energy)
   {
      setPosition(p);
      setEnergy(energy);
   }

   Point getPosition() const { return position; }
   int getEnergy() const { return energy; }

   void setPosition(Point position);
   void setEnergy(int energy);

};

#endif
