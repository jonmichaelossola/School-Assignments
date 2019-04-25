/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions           
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int prompt() throw (const string)
{
	int number;
    cout << "Enter a number: ";
    cin >> number;
	
    if (number < 0)
	    throw string ("The number cannot be negative.");
    if (number > 100)
	    throw string("The number cannot be greater than 100.");
    if (number % 2 != 0)
	    throw string("The number cannot be odd.");
	
	return number;

}

int main() 
{
	try
	{
		int number = prompt();
		cout << "The number is ";
		cout << number << "." << endl;
	}
	catch (string message)
	{
		cout << "Error: " << message << endl;
	}
   return 0;
}
