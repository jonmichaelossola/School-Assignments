/***********************************************************************
 * File: voxel.h
 ***********************************************************************/

#ifndef VOXEL_H
#define VOXEL_H

/*********************************************************
 * Class: Voxel
 * Description: Holds an RGB color value as well as a char
 *   for a type.
 *********************************************************/
class Voxel
{
private:
   // stores an integer for Red, Blue, and Green
   // The astute coder will observe the great ineffiency here
   int red;
   int green;
   int blue;

   // Stores a character code for a particular type
   char typeCode;

public:
   Voxel() : red(0), green(0), blue(0), typeCode('_') { }
   Voxel(int red, int green, int blue, char type)
      : red(red), green(green), blue(blue), typeCode(type) { }

   /******************************************************
    * Function: Display
    * Description: Displays the value of a Voxel.
    ******************************************************/
   void display() const;
};

#endif
