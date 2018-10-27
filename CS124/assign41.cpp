 /***********************************************************************
* Program:
*    Assignment 41,    
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
#include <cassert>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int numCharactersString()
{
	int numCharacters;
	
	cout << "Number of characters: ";
	cin >> numCharacters;

	return numCharacters;
}

void promptString(char text[])
{
	cout << "Enter Text: ";

	cin.ignore();
	cin.getline(text, 256);
}

void displayList(char text[], int numCharacters)
{
	cout << "Text: ";
	for (int i = 0; i < numCharacters; i++)
	{
		cout << text[i];
	}
	cout << endl;
}

int main()
{
	int numCharacters = numCharactersString();

	char * text;

	if (numCharacters > 0)
	{
		text = new(nothrow) char[numCharacters + 1];

		promptString(text);

		displayList(text, numCharacters);
	}
	else 
		cout << "Allocation failure!\n";

	delete text;

   return 0;
}
