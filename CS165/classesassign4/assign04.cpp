/***************************************************************
 * File: assign04.cpp
 * Author: (your name here)
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "product.h"


/**************************************************************
* This is the main function. It declares a class variable and 
* calls functions that are within that class.
**************************************************************/
int main()
{
   // Declare your Product object here
   Product product;

   // Call your prompt function here
   product.prompt();


   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   if (choice == 1)
   {
      product.displayAdvertising();
   }
   else if (choice == 2)
   {
      product.displayInventory();
   }
   else if (choice == 3)
   {
      product.displayReceipt();
   }

   return 0;
}
