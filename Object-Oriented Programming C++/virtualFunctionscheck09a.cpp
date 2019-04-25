/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your classes here
class Car
{
protected:
	string name;
public:
	Car()
	{
		setName("Unknown model");
	}
	string getName() const { return name; }
	void setName(string name) { this->name = name; }
	virtual string getDoorSpecs() { return "Unknown Doors"; }
};

class Civic : public Car
{
public:
	Civic()
	{
		setName("Civic");
	}
	virtual string getDoorSpecs() { return "4 doors"; }
};

class Odyssey : public Car
{
public:
	Odyssey()
	{
		setName("Odyssey");
	}
	virtual string getDoorSpecs() { return "2 front doors, 2 sliding doors, 1 tail gate"; }
};

class Ferrari : public Car
{
public:
	Ferrari()
	{
		setName("Ferrari");
	}
	virtual string getDoorSpecs() { return "2 butterfly doors"; }
};

/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

// TODO: Include your attachDoors function here
void attachDoors(Car &car)
{
	cout << "Attaching doors to " << car.getName() << " - " << car.getDoorSpecs() << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}


