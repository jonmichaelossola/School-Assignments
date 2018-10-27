#ifndef POINT_H
#define POINT_H

#include <iostream>

/***********************************************************
 * Class: Point
 * Description: Holds a simply integer pair (xCoord, yCoord)
 ***********************************************************/
class Point
{
   private:
      float x;
      float y;

   public:
      Point() : x(0), y(0) { }
      
      // Getters
      float getX() const { return x; }
      float getY() const { return y; }

      // Setters
      void setX(float x) { this->x = x; }
      void setY(float y) { this->y = y; }

      void display() const;
      void promptForPoint();
};

#endif

