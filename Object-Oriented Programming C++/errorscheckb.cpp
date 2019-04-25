/***********************************************************************
* Program:
*    Checkpoint 03b, Errors            
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int prompt()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid input.\n";

		cout << "Enter a number: ";
		cin >> number;
	}

	return number;
}

int main()
{
	int number = prompt();
	cout << "The number is " << number << "." << endl;
   return 0;
}
