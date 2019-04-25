/***********************************************************************
* Program:
*    Checkpoint 11a, Function Templates
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/**********************************************************
 * Function: swapValues
 * Description: Swaps two values
 **********************************************************/
template <class T>
void swapValues(T &v1, T &v2)
{
   T temp;
   temp = v1;
   v1 = v2;
   v2 = temp;
}

/**********************************************************
 * Function: indexOfSmallest
 * Description: Finds the smallest value in the array
 *   and returns its index.
 **********************************************************/
template <class T>
int indexOfSmallest(const T array[], int startIndex, int size)
{
   T min = array[startIndex];
   int indexOfMin = startIndex;

   for (int index = startIndex + 1; index < size; index++)
   {
      if (array[index] < min)
      {
         min = array[index];
         indexOfMin = index;
      }
   }

   return indexOfMin;
}

/***********************************************************
 * Function: sort
 * Description: Uses a selection sort to sort the array.
 *
 * Source: Savitch, Absolute C++ 5th Edition, pp. 216-217
 ***********************************************************/
template <class T>
void sort(T array[], int size)
{
   int indexOfNextSmallest;

   for (int index = 0; index < size - 1; index++)
   {
      indexOfNextSmallest = indexOfSmallest(array, index, size);
      swapValues(array[index], array[indexOfNextSmallest]);
   }
}

const int SIZE = 5;

/********************************************************
 * Function: doIntList
 * Description: This function prompts the user for a list
 *   of integers and then passes it to the sort function
 *   above and finally displays it.
 *
 * You should not need to change this function.
 ********************************************************/
void doIntList()
{
   // You should not need to change this function
   
   int list[SIZE];

   cout << "Please enter " << SIZE << " ints.\n";

   // prompt for the values
   for (int i = 0; i < SIZE; i++)
   {
      cout << "Enter value " << i + 1 << ": ";
      cin >> list[i];
   }

   // now we call the sort function
   sort(list, SIZE);

   // finally we display it:
   for (int i = 0; i < SIZE; i++)
   {
      cout << list[i] << endl;
   }

   cout << endl;
}

/********************************************************
 * Function: doFloatList
 * Description: This function prompts the user for a list
 *   of floats and then passes it to the sort function
 *   above and finally displays it.
 *
 * You should not need to change this function.
 ********************************************************/
void doFloatList()
{
   // You should not need to change this function
   
   float list[SIZE];

   cout << "Please enter " << SIZE << " floats.\n";

   // prompt for the values
   for (int i = 0; i < SIZE; i++)
   {
      cout << "Enter value " << i + 1 << ": ";
      cin >> list[i];
   }

   // now we call the sort function
   sort(list, SIZE);

   // finally we display it:
   for (int i = 0; i < SIZE; i++)
   {
      cout << list[i] << endl;
   }

   cout << endl;
}

/********************************************************
 * Function: doStringList
 * Description: This function prompts the user for a list
 *   of strings and then passes it to the sort function
 *   above and finally displays it.
 *
 * You should not need to change this function.
 ********************************************************/
void doStringList()
{
   // You should not need to change this function
   
   string list[SIZE];

   cout << "Please enter " << SIZE << " strings.\n";

   // prompt for the values
   for (int i = 0; i < SIZE; i++)
   {
      cout << "Enter value " << i + 1 << ": ";
      cin >> list[i];
   }

   // now we call the sort function
   sort(list, SIZE);

   // finally we display it:
   for (int i = 0; i < SIZE; i++)
   {
      cout << list[i] << endl;
   }

   cout << endl;
}

/*******************************************************
 * Function: main
 * Description: This is the main driver for the program.
 *   It calls functions to build, sort, and display ints,
 *   floats, and strings.
 ********************************************************/
int main()
{
   doIntList();
   doFloatList();
   doStringList();

   return 0;
}
