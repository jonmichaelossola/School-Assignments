/***********************************************************************
* Program:
*    Checkpoint ###, ????          (e.g. Checkpoint 01a, review)  
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cassert>
#include <string>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
void promptNumbers(list<int> &array)
{
	int number;

	// store integers in vector using the vector's push back method.
	do
	{
		cout << "Enter an integer: ";
		cin >> number;
		if (number != 0)
		{
			// stores number in vector in the back
			array.push_back(number);
		}
	}
	while (number != 0);
	cout << endl;
}

void displayNumbers(list<int> &array)
{
	/* use size to iterate through vector 
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}
	*/

	// iterate through array backwards using iterators
	for (list<int> :: reverse_iterator iter = array.rbegin(); iter != array.rend(); iter++)
	{
		cout << "Your values are: ";
		// use * to access data in iter. 
		cout << *iter << endl;
	}
	cout << endl;
}

void removeOdds(list<int> &array)
{
	list<int> :: iterator iter = array.begin();

	while (iter != array.end())
	{
		if (*iter % 2 != 0)
		{
			// use iter = array.erase(iter) b/c the list needs it.
			// otherwise iter doesn't know what it's pointing at. 
			iter = array.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	cout << "Odd numbers erased! :)" << endl;
}

int main()
{
	list<int> array;

	promptNumbers(array);

	displayNumbers(array);

	removeOdds(array);

	displayNumbers(array);
   return 0;
}
