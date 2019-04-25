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
#include <vector>
#include <cassert>
#include <string>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
void promptNumbers(vector<int> &array)
{
	int number;

	do
	{
		cout << "Enter an integer: ";
		cin >> number;
		if (number != 0)
		{
			array.push_back(number);
		}
	}
	while (number != 0);
}

void displayNumbers(vector<int> &array)
{

	for (vector<int> :: iterator iter = array.begin(); iter != array.end(); iter++)
	{
		cout << "Your values are: ";
		cout << *iter << endl;
	}
	cout << endl;
}

void removeOdds(vector<int> &array)
{
	vector<int> :: iterator iter = array.begin();

	while (iter != array.end())
	{
		if (*iter % 2 != 0)
		{
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
	vector<int> array;

	promptNumbers(array);

	displayNumbers(array);

	removeOdds(array);

	displayNumbers(array);
   return 0;
}
