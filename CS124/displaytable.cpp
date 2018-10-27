/***********************************************************************
* Program:
*    Assignment 25,    
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part is to determine what to write here.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function displays a table of a calendar when the user puts in
 * the offset and the number of days in a month.
 ***********************************************************************/
void displayTable()
{
   int numDays;
   int offset;
   
   
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   
   if (offset == 6)
   {
      cout << setw(4);
   }
   else 
   {
      cout << setw(8 + 4 * offset);
   }


   for (int dayWeek = 1; dayWeek <= numDays; dayWeek++)
   {
      cout << dayWeek;
      if (offset != 5)
      {
         cout << setw(4);
      }
      if (offset == 5)
      {
         cout << "\n" << setw(4);
      }
      else if (offset == 6)
      {
         offset = -1;
      }
      if (dayWeek == numDays && offset != 5)
      {
         cout << endl;
      }
      
      offset++;
   }
      
}
displayTable()
{
   int day = 1;
   int offset = 0;


   cout << "Number of days: ";
   cin >> day;
   cout << "Offset: ";
   cin >> offset;

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   

   while (day < 31)
   {
      cout << setw(4) << day;
      if (day % 7 == 0)
      {
         cout << endl;
      }
      day += 1;
   }
   return 0;
}

/**********************************************************
* Main calls the funciton to display the table and returns
* a value of zero.
*
***********************************************************/
int main()
{
   displayTable();   
   return 0;
}
