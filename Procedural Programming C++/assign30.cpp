/***********************************************************************
* Program:
*    Assignment 30,    
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
 * The function takes in 10 values from the user for the numbers to be
 * placed in the array.
 ***********************************************************************/
void getGrades(int grades[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Grade " << i + 1 << ": ";
		cin >> grades[i];
	}
}

/*****************************************************************
* This function in my program determines the average of all the 
* grades entered in the above function.
*****************************************************************/
int averageGrades(int grades[], int SIZE)
{
	int sum;

	for (int x = 0; x < SIZE; x++)
	{
		sum += grades[x];
	}

	return sum / 10;
}

/**************************************************************
* The main function calls the other two functions and then
* displays the output and the average grade.
**************************************************************/
int main()
{
	const int SIZE = 10;

	int grades[SIZE];

	getGrades(grades, SIZE);

	int average = averageGrades(grades, SIZE);

	cout << "Average Grade: " << average << "%\n";
   return 0;
}
