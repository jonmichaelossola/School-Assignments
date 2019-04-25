/*********************
 * File: check12b.cpp
 *********************/

#include <iostream>
using namespace std;

#include "money.h"

/****************************************************************
 * Function: main
 * Purpose: Test the money class and practice operators
 ****************************************************************/
int main()
{
   Money account1;
   Money account2;

   // Get the input from the user
   account1.prompt();
   account2.prompt();
   cout << endl;

   cout << "The original values are: ";
   account1.display();
   cout << " and ";
   account2.display();
   cout << endl;



   // use the operator overload for +=
   account1 += account2;

   // use the handle overflow function from the Money class
   if (account1.getCents() >= 100)
   {
      account1.handleOverflow();
   }


   cout << "After doing account1 += account2, the value of account1 is: ";
   account1.display();
   cout << endl;

   Money account3;

   // Use the operator overload for the + operation and store that into account3
   account3 = account1 + account2;
   if (account3.getCents() >= 100)
   {
      account3.handleOverflow();
   }


   cout << "From account1 + account2, the value of account3 is: ";
   account3.display();
   cout << endl;


   // Use the prefix increment operator overload
   ++account1;
   if (account1.getCents() >= 100)
   {
      account1.handleOverflow();
   }

   cout << "After ++account1, the value of account1 is: ";
   account1.display();
   cout << endl;


   return 0;
}

