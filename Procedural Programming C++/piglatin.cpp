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
#include <fstream>
#include <string> // for the string class variables
#include <iomanip> // for the setw() function
#include <cassert> // for debugging code
#include <cstdlib> // the library for changing command line parameters
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
	char phrase[256];
	char firstLetter;
	cout << "Enter in any word, make sure it's english: ";
	cin >> phrase;
	int counter = 0;

	string changePhrase;

	for (int i = 0; phrase[i]; i++)
	{
		phrase[i] = tolower(phrase[i]);
	}

	for (int i = 1; phrase[i]; i++)
	{
		changePhrase += phrase[i];
	}
	changePhrase = changePhrase + "ay";

	cout << "This is the pig latin translation of the word just entered: ";
	cout << changePhrase;
	cout << endl;


	
	// cout.setf(ios::fixed); no scientific notation
	// cout.setf(ios::showpoint); always show the decimal for real numbers
	// cout.precision(2); show two digits after the decimal
   return 0;
}
