#include "velocity.h"

#include <iostream>
using namespace std;

// TODO: Put your method bodies here



void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}

Velocity& Velocity::operator ++()
{
	setDx(dx + 1);
	setDy(dy + 1);

	// this returns the new values of Velocity
	return *this;
}

Velocity Velocity::operator ++(int x)
{
	// set the velocity object to the old value of velocity
	Velocity old = *this;

	// increment the velocity class here.
	setDx(dx + 1);
	setDy(dy + 1);

	// return the old velocity object
	return old;
}
