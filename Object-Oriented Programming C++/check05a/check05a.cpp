/*********************
 * File: check05a.cpp
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
   Money money;

   money.prompt();
   money.display();

   cout << endl;

   cout << "That is " << money.getDollars() << " dollars and "
        << money.getCents() << " cents!\n";

   return 0;
}

