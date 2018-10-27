#include "numberList.h"

#include <iostream>
using namespace std;

/******************************************************
 * Function: getNumber
 * Description: Returns the number at the given index.
 ******************************************************/
int NumberList::getNumber(int index) const
{
   int number = -1;

   if (index >= 0 && index < size)
   {
      number = array[index];
   }

   return number;
}

/******************************************************
 * Function: setNumber
 * Description: Sets the value to the array at the given index.
 ******************************************************/
void NumberList::setNumber(int index, int value)
{
   if (index >= 0 && index < size)
   {
      array[index] = value;
   }
}

/******************************************************
 * Function: displayList
 * Description: displays the list
 ******************************************************/
void NumberList::displayList() const
{
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << endl;
   }

   cout << endl;
}

NumberList::NumberList(const int size)
{
   array = new int[size];
   this->size = size;
   for (int i = 0; i < size; i++)
   {
      array[i] = 0;
   }
}

NumberList::~NumberList()
{
   array = NULL;
   cout << "Freeing memory" << endl;
}

