/***********************************************************************
* Program:
*    Assignment 33,    
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
void date(float *pAccount, float costDinner,
	float costMovie, float costIceCream)
{
    *pAccount -= costDinner;
    *pAccount -= costMovie;
	*pAccount -= costIceCream;
}


int main()
{
	cout.setf(ios::fixed); // No scientific notation
	cout.setf(ios::showpoint); // Show the decimal point
	cout.precision(2); // Two decimals for cents.

	float accountSam;
	float accountSue;
	float costDinner;
	float costMovie;
	float costIceCream;

	float * pAccount;

	cout << "What is Sam's balance? ";
	cin >> accountSam;
	cout << "What is Sue's balance? ";
	cin >> accountSue;
	cout << "Cost of the date:" << endl;
	cout << "\tDinner:    ";
	cin >> costDinner;
	cout << "\tMovie:     ";
	cin >> costMovie;
	cout << "\tIce cream: ";
	cin >> costIceCream;

	if (accountSam > accountSue)
	{
		pAccount = &accountSam;
	}
	else 
	{
		pAccount = &accountSue;
	}

	date(pAccount, costDinner, costMovie, costIceCream);

	
	cout << "Sam's balance: $" << accountSam << endl;
	cout << "Sue's balance: $" << accountSue << endl;

   return 0;

}
