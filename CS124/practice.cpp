/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate passing arrays of strings between functions
 ************************************************************************/

#include <iostream>
using namespace std;

/******************************************
 * GET NAMES
 * Prompt the user for NUM names
 ******************************************/
void getNames(char names[][32], int numNames)
{
   cout << "Who are your top " << numNames << " scripture heroes?\n";

   // standard FOR loop
   for (int iNames = 0; iNames < numNames; iNames++)
   {
      cout << "\t#" << iNames + 1 << ": ";
      cin  >> names[iNames];    // each element in the array is a string
   }
}

/*******************************************
 * DISPLAY
 * Display the list of names
 ******************************************/
void display(const char names[][32], int numNames)
{
   cout << "Your " << numNames << " heroes are: ";

   // display the first name.
   cout << names[0];

   // display the rest, putting a comma and a space before each
   // skip slot 0 because we did it already
   for (int iNames = 1; iNames < numNames; iNames++)   
      cout << ", "
           << names[iNames];

   cout << endl;
}

/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // declare the array of strings
   char names[5][32];

   // prompt the user for the data
   getNames(names, 5 /*numNames*/);
   
   // display the list of names
   display(names, 5 /*numNames*/);

   return 0;
}

