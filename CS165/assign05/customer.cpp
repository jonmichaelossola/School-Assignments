// File: customer.cpp

#include "customer.h"

/*************************************************************
* The function below is the default constructor for the 
* customer class.
**************************************************************/
Customer :: Customer()
{
	Address address;
	setName("unspecified");
	setAddress(address);
}

/**************************************************************
* The following is a non default constructor for the customer
* class.
***************************************************************/
Customer :: Customer(const string name, const Address &address)
{
	setName(name);
	setAddress(address);
}

/*************************************************************
* The following is the display method for the customer class.
* It also calls on the address methods to get the address
* of the customer.
**************************************************************/
void Customer :: display() const
{
	cout << name << endl;
	cout << address.getStreet() << endl;
	cout << address.getCity() << ", ";
	cout << address.getState() << " " << address.getZip() << endl;
}