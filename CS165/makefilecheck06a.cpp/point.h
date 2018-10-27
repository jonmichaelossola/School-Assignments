/******************************************
 * File: point.h
 *
 * You should not need to change this file.
 ******************************************/

#ifndef POINT_H
#define POINT_H

class Point
{
private:
   int x;
   int y;

public:
   void display() const;

   Point()
   {
      x = 5;
      y = 5;
   }

   Point(int x, int y)
   {
      setX(x);
      setY(y);
   }


   int getX() const { return x; }
   int getY() const { return y; }

   void setX(int x);
   void setY(int y);

};

#endif
