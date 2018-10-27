/***********************************************************************
 * File: voxel.cpp
 ***********************************************************************/

#include "voxel.h"

#include <iostream>
using namespace std;

/******************************************************
 * Function: Display
 * Description: Displays the value of a Voxel.
 ******************************************************/
void Voxel :: display() const
{
   cout << "(" << red << ", " << green << ", " << blue << ") - ";
   cout << typeCode;
}

