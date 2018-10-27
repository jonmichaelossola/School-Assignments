// DO NOT CHANGE THIS FILE

/**********************
 * File: check13b.cpp
 *********************/

#include <iostream>
using namespace std;

#include "numberList.h"

void changeList(NumberList list)
{
   // Passing the list by copy on purpose!
   
   cout << "In function.\n";
   list.displayList();

   cout << "Making a change.\n";
   list.setNumber(4, 25);

   list.displayList();

   cout << "Leaving function.\n";
}

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

   cout << "After changes:\n";
   list.setNumber(0, 1);
   list.setNumber(1, 10);
   list.setNumber(2, 7);
   list.setNumber(3, 15);
   list.displayList();

   cout << "Making copies, then some more changes.\n";
   NumberList list2(list);
   NumberList list3;
   NumberList list4;

   list4 = list3 = list;

   list.setNumber(0, 2);
   list2.setNumber(1, 2);
   list3.setNumber(2, 2);
   list4.setNumber(3, 2);

   cout << "List 1:\n";
   list.displayList();

   cout << "List 2:\n";
   list2.displayList();

   cout << "List 3:\n";
   list3.displayList();

   cout << "List 4:\n";
   list4.displayList();

   cout << "Calling a function.\n";
   changeList(list);

   cout << "Back in main.\n";
   list.displayList();

   cout << "Finishing program.\n";
   return 0;
}

