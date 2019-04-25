// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
using namespace std;
#include <string>

// Put your Address class here
class Address
{
	private:
		string street;
		string city;
		string state;
		string zip;

	public:
		Address();
		Address(const string street, const string city, 
				const string state, const string zip);
		void setStreet(const string street) { this->street = street; }
		string getStreet() const { return street; }
		void setCity(const string city) { this->city = city; }
		string getCity() const { return city; }
		void setZip(const string zip) { this->zip = zip; }
		string getZip() const { return zip; } 
		void setState(const string state) { this->state = state; }
		string getState() const { return state; }
		void display();
};
#endif
