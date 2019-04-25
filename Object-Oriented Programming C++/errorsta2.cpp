/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
	int bookNumber;
    string book;
    int chapter;
    int verse;
    int endVerse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture)
{
    cout << scripture.bookNumber << " ";
    cout << scripture.book << " ";
    cout << scripture.chapter;
    if (scripture.verse == 0 && scripture.endVerse == 0)
    {
       cout << endl;
    }
    else if (scripture.endVerse > scripture.verse)
    {
      cout << scripture.endVerse;
      cout << "-";
      cout << scripture.verse;
      cout << endl;
    }
    else
    {
      cout << scripture.endVerse;
      cout << "-";
      cout << scripture.verse;
      cout << endl;
    }
}

/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   // Insert your code here to prompt for the name of a file
	string file;
	cout << "Enter the name of the file: ";
	cin >> file;
	stringstream ss;
	string line;
	Scripture scripture;

	ifstream fin(file.c_str());

	if (fin.fail())
	{
		cout << "Error in opening file:\n";
	}

	while (getline(fin, line))
	{
		ss.str(line);
		ss >> scripture.bookNumber;
		ss >> scripture.book;
		ss >> scripture.chapter;
		ss >> scripture.verse;
		ss >> scripture.endVerse;
		if (ss.fail())
		{
			scripture.endVerse = 0;
			scripture.verse = 0;
		}
	}

	fin.close();

	display(scripture);
   // and pass it to a readFile function


   return 0;
}
