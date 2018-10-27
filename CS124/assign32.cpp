/***********************************************************************
* Program:
*    Assignment 32,    
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
int countLetters(char letter, char text[])
{
	int sum = 0;
	for (int i = 0; text[i] != 0; i++)
	{
		if (text[i] == letter)
		{
			sum += 1;					
		}
	}
	return sum;
}

int main()
{
	char letter;
	char text[256];
	cout << "Enter a letter: ";
	cin >> letter;
	while (sizeof(letter) > 1)
	{
		"Enter a letter: ";
		cin >> letter;
	}
	cout << "Enter text: ";
	cin.ignore();
	cin.getline(text, 256);
	cout << "Number of '" << letter << "'s: ";
	cout << countLetters(letter, text);
	cout << endl;

   return 0;
}
