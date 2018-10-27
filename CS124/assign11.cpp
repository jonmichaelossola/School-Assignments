/***********************************************************************
* Program:
*    Assignment 11,       
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
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "\tItem           Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome" << setw(10) << "$" << setw(10) << "1000.00\n";
   cout << "\tTaxes" << setw(11) << "$" << setw(10) << "100.00\n";
   cout << "\tTithing" << setw(9) << "$" << setw(10) << "100.00\n";
   cout << "\tLiving" << setw(10) << "$" << setw(10) << "650.00\n";
   cout << "\tOther" << setw(11) << "$" << setw(10) << "90.00\n";
   cout << "\t=============  ==========\n";
   cout << "\tDelta" << setw(11) << "$" <<setw(10) << "60.00\n";
   return 0;
}
