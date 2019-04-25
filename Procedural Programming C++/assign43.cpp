/***********************************************************************
* Program:
*    Assignment 43,    
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
#include <cstdlib>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main(int countArgument, char ** listArguments)
{
	cout.precision(1); // show one digit after the decimal
	cout.setf(ios::showpoint); // show the decimal for real numbers
	cout.setf(ios::fixed); // no scientific notation

	float userInput[countArgument];
	float toMeters[countArgument];

	for (int i = 0; i < countArgument; i++)
	{
		userInput[i] = atof(listArguments[i]); // copy command line parameters to float
	}

	for (int x = 0; x < countArgument; x++)
	{
		toMeters[x] = userInput[x] * 0.3048; // convert command line parameters to meters
	}

	for (int a = 1; a < countArgument; a++)
	{
		cout << userInput[a] << " feet is " << toMeters[a] << " meters" << endl;
	} // display the feet to meters input and result

   return 0;
}
