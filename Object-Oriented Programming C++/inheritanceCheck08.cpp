/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
 class Book
 {
 private:
 	string title;
 	string author;
 	int publicationYear;
 public:
 	void promptBookInfo();
 	void displayBookInfo() const;
 };

// TODO: Define your TextBook class here
class TextBook : public Book
{
private:
	string subject;
public:
	void promptSubject();
	void displaySubject() const;
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
private:
	string illustrator;
public:
	void promptIllustrator();
	void displayIllustrator() const;
};

void Book :: promptBookInfo()
{
	cout << "Title: ";
	getline(cin, title);
	cout << "Author: ";
	getline(cin, author);
	cout << "Publication Year: ";
	cin >> publicationYear;
	cin.ignore();
}

void Book :: displayBookInfo() const
{
	cout << title << " (" << publicationYear << ") by " << author << endl;
}

void TextBook :: promptSubject()
{
	cout << "Subject: ";
	getline(cin, subject);
	cout << endl;
}

void TextBook :: displaySubject() const 
{
	cout << "Subject: " << subject << endl;
	cout << endl;
}

void PictureBook :: promptIllustrator()
{
	cout << "Illustrator: ";
	getline(cin, illustrator);
	cout << endl;
}

void PictureBook :: displayIllustrator() const
{
	cout << "Illustrated by " << illustrator << endl;
}
/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
	Book book;
	book.promptBookInfo();
	cout << endl;
	book.displayBookInfo();
	cout << endl;

   // Declare a TextBook object here and call its methods
	TextBook textBook;
	textBook.promptBookInfo();
	textBook.promptSubject();
	textBook.displayBookInfo();
	textBook.displaySubject();

   // Declare a PictureBook object here and call its methods
	PictureBook pictureBook;
	pictureBook.promptBookInfo();
	pictureBook.promptIllustrator();
	pictureBook.displayBookInfo();
	pictureBook.displayIllustrator();


   return 0;
}


