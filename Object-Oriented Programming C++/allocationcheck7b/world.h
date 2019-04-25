/***********************************************************************
 * File: world.h
 ***********************************************************************/

#ifndef WORLD_H
#define WORLD_H

#include "voxel.h"

/***********************************************************
 * Class: World
 * Description: Holds a 3D array of Voxels for the world.
 ***********************************************************/
class World
{
private:
   Voxel boxes[100][100][100];

public:
   World();
   ~World();

   Voxel getBox(int x, int y, int z) const;
   void setBox(int x, int y, int z, const Voxel & box);
   void display();
   void displayBox(int x, int y, int z);
};

#endif
