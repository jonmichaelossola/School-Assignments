// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"
#include <string>

// put your Customer class here
class Customer
{
	private:
		string name;
		Address address;

	public:
		Customer();
		Customer(const string name, const Address &address);
		void setName(const string name) {this->name = name;}
		string getName() const {return name;}
		void setAddress(const Address &address) {this->address = address;}
		Address getAddress() const {return address;}
		void display() const;
};
#endif
