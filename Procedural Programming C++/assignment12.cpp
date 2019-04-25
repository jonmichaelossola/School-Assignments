/***********************************************************************
* Program:
*    Assignment 12,           
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    My program can intake an amount, or how much one's income is, and tell that to the person.
*    
*    
*
*    Estimated:  0.5 hrs   
*    Actual:     2.0 hrs
*      The most difficult part of making this program was just figuring out the right code and placing it in the right places.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * My program takes the income of a person and displays it to them.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float income;
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "Your income is: " << "$" << setw(9) << income << endl;
   return 0;
}
