// DO NOT CHANGE THIS FILE

/**********************
 * File: check13a.cpp
 *********************/

#include <iostream>
using namespace std;

#include "numberList.h"

/****************************************************************
 * Function: main
 * Purpose: Test the NumberList class.
 ****************************************************************/
int main()
{
   // YOU SHOULD NOT CHANGE ANYTHING IN THIS FUNCTION

   cout << "Starting program.\n";

   NumberList list(5);

   cout << "Initial list:\n";
   list.displayList();

   cout << "After a change:\n";
   list.setNumber(2, 10);
   list.displayList();

   for (int i = 0; i < 10; i++)
   {
      cout << "Create a list with " << i << " items.\n";
      NumberList tempList(i);
      tempList.displayList();
   } 

   cout << "Finishing program.\n";
   return 0;
}

