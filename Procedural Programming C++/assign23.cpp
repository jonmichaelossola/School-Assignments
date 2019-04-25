/***********************************************************************
* Program:
*    Assignment 23,    
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
int main()
{
   int number;
   int sum = 0;
   

   cout << "What multiples are we adding? ";
   cin >> number;

   int multiple = number;

   do
   {
      sum += multiple;
      multiple += number;
   }
   while (multiple < 100);

   cout << "The sum of multiples of " << number << " less than 100 are: "
        << sum << endl;
      
   return 0;
}
