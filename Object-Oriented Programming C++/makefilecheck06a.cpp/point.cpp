/******************************************
 * File: point.cpp
 *
 * You should not need to change this file.
 ******************************************/

#include "point.h"

#include <iostream>
using namespace std;


/******************************************
 * Setters
 ******************************************/
void Point :: setX(int x)
{
   if (x < 1)
   {
      x = 1;
   }
   else if (x > 10)
   {
      x = 10;
   }

   this->x = x;
}

void Point :: setY(int y)
{
   if (y < 1)
   {
      y = 1;
   }
   else if (y > 10)
   {
      y = 10;
   }

   this->y = y;
}




/******************************************
 * Function: display
 * Purpose: Displays the point
 ******************************************/
void Point :: display() const
{
   cout << "(" << getX() << ", " << getY() << ")";
}
