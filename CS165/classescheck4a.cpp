/***********************************************************************
* Program:
*    Checkpoint 04a, Classes         
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

class Book
{
	// has scope within the class
	private:
		string title;
		string author;

	// constant function does not modify member data
	public: 
		void prompt();
		void display()const;
};

void Book :: prompt()
{
	cout << "Title: ";
	getline(cin, title);

	cout << "Author: ";
	getline(cin, author);
}

void Book :: display()const
{
	cout << "\"";
	cout << title; 
	cout << "\"";
	cout << " by ";
	cout << author;
	cout << endl;
}

int main()
{
	Book book;

	book.prompt();
	book.display();
   return 0;
}
