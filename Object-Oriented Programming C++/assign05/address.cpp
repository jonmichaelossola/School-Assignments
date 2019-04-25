// File: address.cpp

#include "address.h"
#include <iostream>
using namespace std;
#include <string>

/**********************************************************
* Below is the display method for the address class. It is
* very simple and displays the address of the customer.
***********************************************************/
void Address :: display()
{
	cout << street << endl;
	cout << city << ", " << state << " " << zip << endl;
}

/**********************************************************
* The function below is a default constructor for the 
* address class.
***********************************************************/
Address :: Address()
{
	setStreet("unknown");
	setCity("");
	setState("");
	setZip("00000");
}

/*********************************************************
* The function below is a non default constructor for the 
* address class.
**********************************************************/
Address :: Address(const string street, const string city, 
				const string state, const string zip)
{
	setStreet(street);
	setCity(city);
	setState(state);
	setZip(zip);
}	