/***********************************************************************
* Program:
*    Checkpoint 02a, Structs
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct User
{
	string firstName;
	string lastName;
	int id;
};

void displayStudent(const User & interface)
{
	cout << "Your information:\n";
	cout << interface.id;
	cout << " - ";
	cout << interface.firstName;
	cout << " ";
	cout << interface.lastName;
	cout << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	User interface;
	cout << "Please enter your first name: ";
	cin >> interface.firstName;
	cout << "Please enter your last name: ";
	cin >> interface.lastName;
	cout << "Please enter your id number: ";
	cin >> interface.id;
	cout << endl;

	displayStudent(interface);
   return 0;
}

