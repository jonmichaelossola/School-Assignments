/***************************************************************
 * File: product.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

// put your class definition here
class Product
{
	private:
		string name;
		float price;
		float weight;
		string description;

	public:
		void prompt();
		void displayAdvertising() const;
		void displayInventory() const;
		void displayReceipt() const;
		float getSalesTax() const;
		float getShippingCost() const;
		float getTotalPrice() const;
};
#endif
