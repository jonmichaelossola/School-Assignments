/*********************
 * File: check05b.cpp
 *********************/

// You should not change anything in this file 


#include <iostream>
using namespace std;

#include "money.h"

/****************************************************************
 * Function: main
 * Purpose: Test the money class
 ****************************************************************/
int main()
{
   int dollars;
   int cents;

   cout << "Dollar amount: ";
   cin >> dollars;

   cout << "Cents amount: ";
   cin >> cents;

   Money m1;
   Money m2(dollars);
   Money m3(dollars, cents);

   cout << "Default constructor: ";
   m1.display();
   cout << endl;

   cout << "Non-default constructor 1: ";
   m2.display();
   cout << endl;

   cout << "Non-default constructor 2: ";
   m3.display();
   cout << endl;

   return 0;
}

