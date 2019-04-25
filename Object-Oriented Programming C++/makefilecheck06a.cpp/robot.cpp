/******************************************
 * File: robot.cpp
 *
 * You should not need to change this file.
 ******************************************/

#include "robot.h"
#include <iostream>
using namespace std;

/**************************************
 * Setters
 **************************************/
void Robot :: setPosition(Point position)
{
   this->position = position;
}

void Robot :: setEnergy(int energy)
{
   if (energy < 0)
   {
      this->energy = 0;
   }
   else
   {
      this->energy = energy;
   }
}

/************************************
 * Function: Display
 * Purpose: Displays the robot.
 ************************************/
void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

