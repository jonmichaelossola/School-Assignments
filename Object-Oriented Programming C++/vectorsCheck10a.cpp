/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <vector>
#include <string>

#include <iostream>
using namespace std;


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	// declare a vector that will store an array of integers
	vector<int> array;

	int number;

	do
	{
		cout << "Enter int: ";
		cin >> number;
		if (number != 0){
			array.push_back(number);
		}
	}
	while (number != 0);

	// this is the iterator which is basically like a pointer
	// this points to the start of the list of integers
	vector<int> :: iterator iter = array.begin();

	cout << "Your list is:" << endl;

	while (iter != array.end())
	{
		cout << *iter << endl;
		iter++;
	}

	cout << endl;

	// declare vector of strings
	vector<string> words;
	string word;

	// store all words in the vector until the word quit is entered.
	do
	{
		cout << "Enter string: ";
		cin >> word;
		if (word != "quit")
		{
			words.push_back(word);
		}
	}
	while (word != "quit");

	// declare pointer to start of vector, start from beginning.
	vector<string> :: iterator go = words.begin();
	cout << "Your list is:" << endl;

	// iterate through all words until end
	while (go != words.end())
	{
		cout << *go << endl;
		go++;
	}

   return 0;
}


