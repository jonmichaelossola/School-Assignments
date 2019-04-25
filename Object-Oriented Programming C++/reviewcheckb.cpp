/***********************************************************************
* Program:
*    Checkpoint 01b, Arrays            
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

int getSize()
{
	int sizeList;
	cout << "Enter the size of the list: ";
	cin >> sizeList;

	return sizeList;
}

void getList(int numbers[], int counter)
{
	int number; 

	for (int x = 0; x < counter; x++)
	{
		cout << "Enter number for index " << x << ": ";
		cin >> number;
		numbers[x] = number;
	}
	cout << endl;
} 

void displayMultiples(int numbers[], int sizeList)
{
	cout << "The following are divisible by 3:\n";

	for (int i = 0; i < sizeList; i++)
	{
		if (numbers[i] % 3 == 0)
		{
			cout << numbers[i] << endl;
		} 
	}
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	int sizeList = getSize();

	int numbers[sizeList];

	getList(numbers, sizeList);

	displayMultiples(numbers, sizeList);

   return 0;
}
