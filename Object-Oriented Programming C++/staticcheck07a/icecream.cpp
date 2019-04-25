/***********************************
 * File: icecream.cpp
 ***********************************/
#include "icecream.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/***********************************
 * Constructors
 ***********************************/
IceCream::IceCream()
{
   flavor = "unknown";
   price = 0;
}

IceCream::IceCream(string flavor, float price)
{
   this->flavor = flavor;
   this->price = price;
}

/**********************************************************************
 * Function: IceCream::getTotalPrice
 * Purpose: Gets the total price of the ice cream, including sales tax.
 **********************************************************************/
float IceCream::getTotalPrice() const
{
   // TODO: Change this to include sales tax
   IceCream i;
   float totalTax = price * i.salesTax;
   float totalPrice = price + totalTax;

   return totalPrice;
}

/**********************************************************************
 * Function: IceCream::getTotalPrice
 * Purpose: Prompts the user for the values of ice cream.
 **********************************************************************/
void IceCream::prompt()
{
   cout << "Flavor: ";
   getline(cin, flavor);

   // It would be better to check for bad values here...
   cout << "Price: ";
   cin >> price;
   cin.ignore();
}

/**********************************************************************
 * Function: IceCream::display
 * Purpose: Displays the current ice cream.
 **********************************************************************/
void IceCream::display() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   // we call the getTotalPrice() method here, so it will
   // automatically updated when sales tax is taken into accout.
   cout << "$" << getTotalPrice() << " - " << flavor << endl;
}

