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

NumberList& NumberList::operator=(const NumberList &list)
{
   // check to see if there is already an array stored, if so, then delete it.
   if (this->array != NULL)
   {
      delete [] this->array;
   }

   // make size equal to the size passed in that we are copying
   this->size = list.size;

   // dynamically allocate a new array with the size variable
   this->array = new int[list.size];

   // populate the array of the object with the parameter's array
   for (int i = 0; i < list.size; i++)
   {
      this->array[i] = list.array[i];
   }

   // return the data of the class through the dereference *.
   return *this;
}

NumberList::NumberList(const NumberList &rhs)
{
   // set array to NULL just to be safe
   array = NULL;

   // whatever is in RHS becomes whatever is in the object
   *this = rhs;
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
   // delete the array
   delete [] array;

   // set array to NULL because it's the responsible thing to do :D
   array = NULL;

   cout << "Freeing memory" << endl;
}
