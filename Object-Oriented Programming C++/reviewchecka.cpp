/***********************************************************************
* Program:
*    Checkpoint 01a, C++ Basics         
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
int main()
{
	cout << "Hello CS 165 World!\n";

	cout << "Please enter your first name: ";
	string name;
	cin >> name;

	int age;
	cout << "Please enter your age: ";
	cin >> age;
	cout << endl;

	cout << "Hello " << name <<", you are " << age << " years old.\n";

   return 0;
}
