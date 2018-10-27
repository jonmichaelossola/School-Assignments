/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
* Author:
*    xxx
* Summary: 
*
************************************************************************/

#include <iostream>        // for CIN and COUT
#include <cstring>         // for strcmp
#include <iomanip>         // for SETW
#include <fstream>         // for Fin and Fout
#include "heap.h"
#include "merge.h"

using namespace std;

/**********************************************************************
 * MAIN
 * Gets the sort type and filename from the command line. If the sort type
 * or filename are not entered on the command line, the user will be
 * prompted for the sort type and/or filename.
 * Call the appropriate sort to sort the data contained in the vector or
 * linked list and display the sorted data to the console.
 ***********************************************************************/
int main(int argc, const char* argv[])
{
   char sortType[10];
   char fileName[50];
   if (argc == 1)
   {
      cout << "Which sort merge or heap? ";
      cin >> sortType;
      cout << "Enter name of file to sort: ";
      cin >> fileName;
   }
   else if (argc == 2)
   {
      strcpy(sortType,argv[1]);
      cout << "Enter name of file to sort: ";
      cin >> fileName;
   }
   else if (argc == 3)
   {
      strcpy(sortType,argv[1]);    
      strcpy(fileName,argv[2]);
   }
   
   if (strcmp(sortType, "heap") == 0)
   {
      //cout << "We got to the heap sort if statment! :)\n";
      ifstream fin(fileName);

      if (fin.fail())
      {
         cout << "Failed in opening the file: Try again next time?\n";
         return 0;
      }

      int i = 0;
      vector<int> sortThis;
      // we don't want to use the first item.
      sortThis.push_back(0);

      while (fin >> i)
      {
         sortThis.push_back(i);
      }     

      fin.close();

      heapSort(sortThis);
   }
   else if (strcmp(sortType, "merge") == 0)
   {
      list<int> sortThis;
      ifstream fin(fileName);

      if (fin.fail())
      {
         cout << "Couldn't open the file :(\n";
         return 0;
      }

      int i = 0;

      while (fin >> i)
      {
         sortThis.push_back(i);
      }

      mergeSort(sortThis);
   }
   else
   {
      cout << "\nInvalid sort name - must be 'heap' or 'merge'" << endl;
   }

      
   return 0;
}
