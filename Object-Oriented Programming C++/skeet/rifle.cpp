/*************************************************************
 * File: rifle.cpp
 * Author: Br. Burton
 *
 * Description: Contains the function bodies for the rifle class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "rifle.h"
#include "point.h"
#include "uiDraw.h"

#include <cassert>

void Rifle :: draw() const
{
   assert(angle >= ANGLE_MIN);
   assert(angle <= ANGLE_MAX);
   
   drawRect(point, RIFLE_WIDTH, RIFLE_HEIGHT, 90 - angle);
}

void Rifle :: moveLeft()
{
   angle -= RIFLE_MOVE_AMOUNT;

   if (angle < ANGLE_MIN)
   {
      angle = ANGLE_MIN;
   }
}


void Rifle :: moveRight()
{
   angle += RIFLE_MOVE_AMOUNT;
   
   if (angle > ANGLE_MAX)
   {
      angle = ANGLE_MAX;
   }
}
