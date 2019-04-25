#include <iostream>
#include "point.h"

using namespace std;

/***********************************************************
 * Function: Point :: display
 * Outputs a point to the screen.
 ***********************************************************/
void Point :: display() const
{
   cout << "(" << x << ", " << y << ")";
}

/***********************************************************
 * Function: Point :: promptForPoint
 * Prompts the user for the coordinates of the point.
 ***********************************************************/
void Point :: promptForPoint()
{
   cout << "Enter x: ";
   cin >> x;
      
   cout << "Enter y: ";
   cin >> y;
}

