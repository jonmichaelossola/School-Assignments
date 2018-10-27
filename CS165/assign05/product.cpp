/***************************************************************
 * File: product.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*************************************************************
* The function below is a default constructor for the product
* class.
**************************************************************/
Product :: Product()
{
	setName("none");
	setDescription("");
	setWeight(0);
	setBasePrice(0.0);
}

/**************************************************************
* The function below is the non default destructor for the product
* class.
**************************************************************/
Product :: Product(const string name, const string description,
				 const float price, const int weight)
{
	setName(name);
	setDescription(description);
	setWeight(weight);
	setBasePrice(price);
}

/**********************************************************
* This function accepts input from the user regarding the 
* declaration of the variables in private in the class
* declaration.
***********************************************************/
void Product::prompt()
{
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter description: ";
	getline(cin, description);

	cout << "Enter weight: ";
	cin >> weight;
	cout << "Enter price: ";
	cin >> price;

	// fail safe if the user enters in anything weird
	while (price < 0 || cin.fail())
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
		cout << "Enter price: ";
		cin >> price;
	}
}

/**********************************************************
* This function displays, on request, the advertising piece
* of the product.
***********************************************************/
void Product::displayAdvertising() const
{
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
	cout << name << " - " << '$' << price << endl;
	cout << '(' << description << ')' << endl;
}

/*********************************************************
* This function displays the inventory as requested by the
* user.
**********************************************************/
void Product::displayInventory() const 
{
	cout << '$' << price << " - " << name << " - ";

	cout.precision(1);
	cout << weight;
	cout.precision(2);
	cout << " lbs";
	cout << endl;
}

/********************************************************
* This function displays the receipt of the function.
* With all the proper spacing.
*********************************************************/
void Product::displayReceipt() const
{
	float salesTax = getSalesTax();
	float priceShipping = getShippingCost();
	float totalPrice = getTotalPrice();

	cout << name << endl;
	cout << "  " << "Price: " << setw(9);
	cout << '$' << setw(8) << price << endl;
	cout << "  " << "Sales tax: " << setw(5);
	cout << '$' << setw(8) << salesTax << endl;
	cout << "  " << "Shipping cost: ";
	cout << '$' << setw(8) << priceShipping << endl;
	cout << "  " << "Total: " << setw(9);
	cout << '$' << setw(8) << totalPrice << endl;
}


/***********************************************************
* This function simply determines how much the sales cost
* is of the product.
***********************************************************/
float Product::getSalesTax() const
{
	return price * .06;
}

/*************************************************************
* This function finds out the shipping cost by using the 
* weight to determine how much the user needs to input.
*************************************************************/
float Product::getShippingCost() const
{
	if (weight <= 5 && weight != 0)
	{
		return 2;
	}
	else if (weight > 5)
	{
		float priceShipping = 2;
		for (int x = 5; x < weight; x++)
		{
			priceShipping += .10;
		}
		return priceShipping;
	}
	return 0;
}

/**************************************************************
* This function determines the total price of everything, 
* adding in the shipping and the tax. It returns the total.
***************************************************************/
float Product::getTotalPrice() const
{
	float priceShipping = getShippingCost();
	float priceTax = getSalesTax();
	float totalPrice = price;
	totalPrice += priceShipping + priceTax;
	return totalPrice;
}

