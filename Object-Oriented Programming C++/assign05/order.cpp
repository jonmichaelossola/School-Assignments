// File: order.cpp

#include "order.h"
#include <string>
#include <iostream>
using namespace std;

/**********************************************************
* The function below is a default constructor for the 
* order class.
**********************************************************/
Order :: Order()
{
	setQuantity(0);
	Customer();
	Product();
}

/**********************************************************
* The method below is a non default constructor for the 
* order class.
**********************************************************/
Order :: Order(const Product &product, const int quantity, 
			const Customer &customer)
{
	setProduct(product);
	setQuantity(quantity);
	setCustomer(customer);
}

/*******************************************************
* The function below determines the total price from
* the product class and multiplies that by the quantity.
********************************************************/
float Order :: getTotalPrice() const
{
	float totalPrice;
	// uses the total price function from the product class
	totalPrice = product.getTotalPrice() * quantity;
	return totalPrice;
}

/*******************************************************
* This function is the display information method, it 
* displays all of the data.
********************************************************/
void Order :: displayInformation() const
{
	string customerName = customer.getName();
	string productName = product.getName();
	float totalPrice = getTotalPrice();

	cout << customerName << endl;
	cout << productName << endl;
	cout << "Total Price: " << '$' << totalPrice << endl;
}