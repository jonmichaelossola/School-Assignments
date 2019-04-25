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
		Product();
		Product(const string name, const string description,
			const float price, const int weight);
		void setName(const string name) {this->name = name;}
		string getName() const {return name;}
		void setDescription(const string description) {this->description = description;}
		string getDescription() const {return description;}
		void setBasePrice(const float price) {this->price = price;}
		float getBasePrice() const {return price;}
		void setWeight(const float weight) {this->weight = weight;}
		float getWeight() const {return weight;}
		void prompt();
		void displayAdvertising() const;
		void displayInventory() const;
		void displayReceipt() const;
		float getSalesTax() const;
		float getShippingCost() const;
		float getTotalPrice() const;
};
#endif
