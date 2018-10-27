/***********************************************************************
 * File: world.cpp
 ***********************************************************************/

#include "voxel.h"
#include "world.h"

#include <iostream>
using namespace std;

World::World()
{
   cout << "Initializing the world and connecting to server...\n";
   // we are not really connecting to a server, just pretending
}

World::~World()
{
   cout << "Disconnecting from the server and saving state...\n";
   // Shh... we're not actually doing anything :-)
}

/*****************************************************
 * getBox / setBox
 * Description: Get or set a specific voxel.
 *****************************************************/
Voxel World::getBox(int x, int y, int z) const
{
   return boxes[x][y][z];
}

void World::setBox(int x, int y, int z, const Voxel & box)
{
   boxes[x][y][z] = box;
}

/*****************************************************
 * Function: Display
 * Description: Puts a message on the screen
 *****************************************************/
void World::display()
{
   cout << "Hello from your world.\n";
}

/*****************************************************
 * Function: DisplayBox
 * Description: Outputs the value of the Voxel at the
 *  location specified.
 *****************************************************/
void World::displayBox(int x, int y, int z)
{
   cout << "The value at (" << x << ", " << y << ", " << z << ") is: ";
   boxes[x][y][z].display();
   cout << endl;
}

