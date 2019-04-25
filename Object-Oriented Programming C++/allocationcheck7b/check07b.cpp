/***********************************************************************
* File: check07b.cpp
************************************************************************/

#include <iostream>
using namespace std;

#include "voxel.h"
#include "world.h"

/**************************************************************
 * Function: main
 * Purpose: The driver for the program. Creates a world, sets
 *  some Voxels and displays them.
 **************************************************************/
int main()
{
   cout << "Starting Program.\n";

   // 1. Add code here to declare a World
   World *pWorld = new World;

   // 2. Add code here to call the world's display function
   pWorld->display();

   /* You CANNOT just do this:
   World w;
   w.display();
   */

   // First, we create a voxel for air
   Voxel air(180, 200, 255, 'A');

   // 3. Call setBox on your world to put the air at spot (50, 60, 70)
   pWorld->setBox(50, 60, 70, air);

   // Next, we create a voxel for grass
   Voxel grass(25, 255, 50, 'G');

   // 4. Call setBox on your world to put the grass at spot (45, 20, 10)
   pWorld->setBox(45, 20, 10, grass);

   // 5. Call world's displayBox twice, once for each of these spots
   pWorld->displayBox(50, 60, 70);
   pWorld->displayBox(45, 20, 10);

   // 6. Finally, make sure to free up your memory by deleting the world
   delete pWorld;

   cout << "Ending Program.\n";
   return 0;
}

