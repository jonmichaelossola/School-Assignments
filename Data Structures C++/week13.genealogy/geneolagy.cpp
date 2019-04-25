/***********************************************************************
 * Module:
 *    Week 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Jon Michael Ossola
 * Summary:
 *    This program will do the geneolagy tree project.
 ************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "list.h"
#include "bnode.h"
#include "vector.h"


/**********************************************************************
 * This is our person class. We initialize our variables and then
 * we will be using this all over the place.
 ***********************************************************************/
class person
{
public:
	person() : firstName(""), lastName(""), birthday(""), id(0), birthYear(0) {}

	std::string firstName;
	std::string lastName;
	std::string upperLast;
	std::string birthday;
	int id;
	int birthYear;
};

/**********************************************************************
 * This is going to just display the name of the person we are building
 * the pedigree for. We don't want to hardcode this for any one individual.
 ***********************************************************************/
void displayFirst(const person & myPerson)
{
	std::cout << myPerson.firstName << ' ' << myPerson.lastName << ":" << std::endl;
}

/**********************************************************************
 * Display function. Takes in a person class object, and then chooses
 * the appropriate display to display the object's parts to the console.
 ***********************************************************************/
void display(const person & myPerson)
{
	// in the case of a first name, with no birthday and no last
	if (myPerson.lastName == "" && myPerson.birthday == "" && myPerson.firstName != "")
		std::cout << myPerson.firstName << std::endl; 
	else if (myPerson.lastName == "" && myPerson.birthday != "" && myPerson.firstName != "")
		std::cout << myPerson.firstName << ", b. " << myPerson.birthday << std::endl;
	else if (myPerson.firstName == "" && myPerson.lastName != "" && myPerson.birthday == "")
		std::cout << myPerson.lastName << std::endl;
	else if (myPerson.lastName == "" && myPerson.birthday != "") 
		std::cout << myPerson.firstName << ", b. " << myPerson.birthday << std::endl;
	else if (myPerson.lastName != "" && myPerson.firstName != "" && myPerson.birthday == "")
		std::cout << myPerson.firstName << ' ' << myPerson.lastName << std::endl;
	else
		std::cout << myPerson.firstName << ' ' << myPerson.lastName << ", b. "
		          << myPerson.birthday << std::endl;
}

/**********************************************************************
 * This is our less than or equals operator. We take in two person
 * class objects and return which one is less than or equals to.
 ***********************************************************************/
bool operator <= (person lhs, person rhs)
{
	lhs.lastName[0] = toupper(lhs.lastName[0]);
	rhs.lastName[0] = toupper(rhs.lastName[0]);

	if (lhs.lastName != rhs.lastName)
	{
		// compare last names to start
		return lhs.lastName < rhs.lastName;
	}
	else if (lhs.firstName != rhs.firstName)
	{
		// if they have the same last names, compare first names
		return lhs.firstName <= rhs.firstName;
	}
	else
	{
		// if they have the same first and last name, compare birth years
		return lhs.birthYear <= rhs.birthYear;
	}
}

/**********************************************************************
 * This takes everything from our sorted list, and then inserts it
 * into our tree.
 ***********************************************************************/
void insertToTree(Vector <BinaryNode <person> > & myPedigree, List <person> myTree)
{
	for (ListIterator <person> it = myTree.begin(); it != myTree.end(); it++)
	{
		myPedigree.push_back(BinaryNode <person> (*it));
	}
}

/**********************************************************************
 * This is our sorted insert to List function. This does a sort of 
 * linear sort to sort all of the items.
 ***********************************************************************/
void insertToList(List <person> & myTree, person & myPerson)
{
	if (myTree.empty())
	{
		myTree.push_front(myPerson);
	}
	else
	{	
		for (ListIterator <person> it = myTree.begin(); it != myTree.end(); it++)
		{
			if (myPerson <= myTree.front())
			{
				// we now know we need to insert to the front.
				myTree.push_front(myPerson);
				break;
			}

			if (it.isNextNull() && myTree.back() <= myPerson)
			{
				// We now know that we need to insert to the back.
				myTree.push_back(myPerson);
				break;
			}

			if (myPerson <= *it)
			{
				// insert into tree, needing to push in.
				it = myTree.insert(it, myPerson);
				break;
			}
		}
	}
}

/**********************************************************************
 * This is a simple get ID function. We pass in a line of code, and 
 * we return what the number is in the ID.
 ***********************************************************************/
int getId(const std::string & line)
{
	int count = 1;

	for (int i = 9; line[i] != '@'; i++)
		count++;

	int ID = atoi(line.substr(9, count).c_str());

	return ID;
}

/**********************************************************************
 * This is our pedigree reader. We will read from the file and construct
 * a binary tree based off of who's pedigree chart it is, then display.
 ***********************************************************************/
bool readToPedigree(std::string fileName, List <person> & myTree, Vector <BinaryNode <person> > & myPedigree)
{
	std::ifstream fin(fileName.c_str());
	std::string wordz;

	if (fin.fail())
	{
		std::cout << "Error reading file: " << fileName << std::endl;
		// if file read doesn't work, exit the program completely
		return false;
	}

	while (!(wordz[0] == '0' && wordz[2] == '@' && wordz[3] == 'F'))
		getline(fin, wordz);

	if ((wordz[0] == '0' && wordz[2] == '@' && wordz[3] == 'F'))
	{
		// copy everything into the tree
		insertToTree(myPedigree, myTree);

		// We need to connect our binary tree.
		while (!fin.eof())
		{
			BinaryNode <person> * husbPtr = NULL;
			BinaryNode <person> * wifePtr = NULL;
			BinaryNode <person> * childPtr = NULL;

			getline(fin, wordz);

			// now we are going to loop through families. Loop until we find another
			// family tag.
			while (!(wordz[0] == '0' && wordz[2] == '@' && wordz[3] == 'F') && !fin.eof())
			{
				if (wordz.size() >= 7)
				{
					if (wordz.substr(2, 4) == "HUSB")
					{
						for (int i = 0; i < myPedigree.size(); i++)
						{
							if (myPedigree[i].data.id == getId(wordz))
							{
								husbPtr = &myPedigree[i];
							}
						}
					} 
				}

				if (wordz.size() >= 7)
				{
					if (wordz.substr(2, 4) == "WIFE")
					{
						for (int i = 0; i < myPedigree.size(); i++)
						{
							if (myPedigree[i].data.id == getId(wordz))
							{
								wifePtr = &myPedigree[i];						
							}
						}
					}
				}	

				if (wordz.size() >= 7)
				{
					if (wordz.substr(2, 4) == "CHIL")
					{
						for (int i = 0; i < myPedigree.size(); i++)
						{
							if (myPedigree[i].data.id == getId(wordz))
							{
								childPtr = &myPedigree[i];
							}
						}
					}
				}	

				getline(fin, wordz);
			}

			if ((husbPtr && childPtr) || (wifePtr && childPtr))
			{
				// assign the pointer variables.
				childPtr->pLeft = husbPtr;
				childPtr->pRight = wifePtr;
			}
		}
	}	

	fin.close();

	for (int i = 0; i < myPedigree.size(); i++)
	{
		if (myPedigree[i].data.id == 1)
			myPedigree[i].level();
	}

	return true;
}

/**********************************************************************
 * This is our read to tree function. We will read into our tree based
 * off of the individuals, and then sort the list as we go.
 ***********************************************************************/
bool readToTree(std::string fileName, List <person> & myTree)
{
	std::ifstream fin(fileName.c_str());
	std::string wordz;

	if (fin.fail())
	{
		std::cout << "Error reading file: " << fileName << std::endl;
		// Return false, telling main to exit program completely.
		return false;
	}
	int i = 0;

	// Read the file and parse it.
	while (!fin.eof())
	{
		// on the first time through the loop, we want to locate the first sublist.
		if (i == 0)
		{
			while (!(wordz[2] == '@' && wordz[0] == '0' && wordz[3] == 'I'))
			   getline(fin, wordz);
			// now we won't get into this if statement a second time.
			i++;
		}

		// the below means we have hit a record file
		if (wordz[0] == '0' && wordz[2] == '@' && wordz[3] == 'I')
		{
			person thisPerson;
			int count = 1;

			for (int i = 4; wordz[i] != '@'; i++)
				count++;

			thisPerson.id = atoi(wordz.substr(4, count).c_str());

			// go to the next line.
			getline(fin, wordz);

			// now we are going to loop through the record's subfile
			while (!(wordz[2] == '@' && wordz[0] == '0' && wordz[3] == 'I') && !fin.eof())
			{
				// find their given name and save it
				if (wordz.substr(2,4) == "GIVN")
					thisPerson.firstName = wordz.substr(7);

				// find their surname and save it
				if (wordz.substr(2, 4) == "SURN")
					thisPerson.lastName = wordz.substr(7);

				// now let's work on the birthday.
				if (wordz.substr(2, 4) == "BIRT" && !fin.eof())
				{
					getline(fin, wordz);

					if (wordz.substr(2, 4) == "DATE")
					{
						thisPerson.birthday = wordz.substr(7);

						// does this even work?
						thisPerson.birthYear = atoi(wordz.substr(wordz.size()-5).c_str());
					}
				}

				// now let's get a new line.
				getline(fin, wordz);
			}

			// now we are going to sortidly insert this into the list.
			insertToList(myTree, thisPerson);
		}
	}
	// close the file!
	fin.close();

	return true;
}

/**********************************************************************
 * Write to file function. We are going to write to the file for testBed
 * purposes.
 ***********************************************************************/
bool writeToFile(List <person> & myTree)
{
	std::ofstream fout("smyPerson.dat");

	// if we fail, terminate execution.
	if (fout.fail())
	{
		std::cout << "Couldn't open file: sorted.dat\n";
		return false;
	}

	// write the data to the file
	for (ListIterator <person> it = myTree.begin(); it != myTree.end(); it++)
	{
		if ((*it).lastName == "" && (*it).birthday == "" && (*it).firstName != "")
			fout << (*it).firstName << std::endl; 
		else if ((*it).lastName == "" && (*it).birthday != "" && (*it).firstName != "")
			fout << (*it).firstName << ", b. " << (*it).birthday << std::endl;
		else if ((*it).firstName == "" && (*it).lastName != "" && (*it).birthday == "")
			fout << (*it).lastName << std::endl;
		else if ((*it).lastName == "" && (*it).birthday != "") 
			fout << (*it).firstName << ", b. " << (*it).birthday << std::endl;
		else if ((*it).lastName != "" && (*it).firstName != "" && (*it).birthday == "")
			fout << (*it).firstName << ' ' << (*it).lastName << std::endl;
		else
			fout << (*it).firstName << ' ' << (*it).lastName << ", b. "
		    	 << (*it).birthday << std::endl;
	}

	// close file
	fout.close();
	// We're done! Let's just exit the function now.

	return true;
}

/**********************************************************************
 * Main function. We take in the file name, and then proceed to read
 * through the file twice and build a list and a vector of binary nodes.
 ***********************************************************************/
int main(int argc, char * argv[])
{
	std::string fileName;

	if (argc == 1)
	{
		std::cout << "What is the name of the file? ";
		std::cin >> fileName;
	}
	else
	{
		fileName = argv[1];
	}

	List <person> myTree;
	Vector <BinaryNode <person> > myPedigree;

	// read from the file given.
	if (!readToTree(fileName, myTree))
		return 0;

	// write the results into a new file.
	if (!writeToFile(myTree))
		return 0;

	// read the file into a pedigree tree, also display from there.
	 if (!readToPedigree(fileName, myTree, myPedigree))
	 	return 0;

	return 0;
}