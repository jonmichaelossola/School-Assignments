/**********************
 * File: check07a.cpp
 **********************/

#include <iostream>
#include <string>
using namespace std;

#include "icecream.h"

float IceCream :: salesTax = 0.06;

/*****************************************
 * Function: Main
 * Purpose: Tests the Ice Cream class
 *****************************************/

int main()
{
   IceCream iceCream1;
   iceCream1.prompt();

   IceCream iceCream2;
   iceCream2.prompt();

   cout << "\nMenu:\n";
   iceCream1.display();
   iceCream2.display();
   cout << endl;

   float tax;
   cout << "Enter alternate sales tax: ";
   cin >> tax;

   // TODO: Set the sales tax static member variable here
   iceCream1.salesTax = tax;


   cout << "\nMenu:\n";
   iceCream1.display();
   iceCream2.display();

   return 0;
}
