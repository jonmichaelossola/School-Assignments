/***********************************************************************
* Program:
*    Assignment 00,    
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
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int computeOffset()
{
   int totalDays = 0;
   int month;
   int year;
   int firstYear = 1753;

   cout << "Enter a month number: ";
   cin >> month;
   cout << "Enter year: ";
   cin >> year;
   year = (year * 365);

      while (firstYear < year)
      {
         totalDays += 365;
      }
   for (int firstMonth = 1; firstMonth < month; firstMonth++)
   {
      totalDays += 30;
   }
   return totalDays % 7;
}

int main()
{
   int offset = computeOffset();
   cout << offset;
   return 0;
}
