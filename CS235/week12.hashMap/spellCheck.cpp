/***********************************************************************
 * Module:
 *    Week 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "spellCheck.h"
#include "hash.h"
using namespace std;

/***********************************************************************
* This is our new Hash class. It is of type string. We will compute the
* hash value by adding together all of the ascii values of the characters
* and then modding them by the capacity of the hash.
************************************************************************/
class newHash : public Hash <string>
{
public:
	newHash(int numBuckets) throw (const char *) :
        Hash <string> (numBuckets) {}
    newHash(const newHash & rhs) throw (const char *) :
        Hash <string> (rhs) {}

   // hash function for strings will add up all the ASCII values
   int hash(const string & word) const
   {
   	  int value = 0;

   	  for (int i = 0; i < word.size(); i++)
   	  {
   	  	value += (int)word[i];
   	  }

      return value % capacity();
   }
};

/***********************************************************************
* Display function. Display all of the missepelled words and then 
* if there are no misspelled words, we can display a message instead.
* then return nothing.
************************************************************************/
void display(vector <string> &v)
{
	if (!v.empty())
	{
		cout << "Misspelled: ";
		for (int i = 0; i < v.size(); i++)
		{
			if (i+1 == v.size())
			{
				cout << v[i] << endl;
				break;
			}
			else
				cout << v[i] << ", ";
		}
	}
	else
	{
		cout << "File contains no spelling errors\n";
	}
}

/***********************************************************************
* Read file function. Read the words from a given file into a file,
* and then check those words against the words in the dictionary.
* Then push the misspelled words onto our vector of misspelled stuff.
************************************************************************/
void readFile(string fileName, vector<string> &v, newHash &dictionary)
{
	string word;

	ifstream fin(fileName.c_str());

	if (fin.fail())
	{
		cout << "Error in reading file: " << fileName << endl;
		return;
	}

	while (fin >> word)
	{
		string tmp;
		for (int i = 0; i < word.size(); i++)
		{
			if (isupper(word[i]))
				tmp += tolower(word[i]);
			else
				tmp += word[i];
		}
		if (!dictionary.find(tmp))
		{
			v.push_back(word);
		}
	}

	fin.close();
}

/***********************************************************************
* Read Dictionary function. We are going to store all of the words inside
* of the dictionary file into the file, and then use the dictionary 
* later on to see how many things are misspelled.
************************************************************************/
void readDictionary(newHash &dictionary)
{
	string word;
	ifstream fin("/home/cs235e/week12/dictionary.txt");

	if (fin.fail())
	{
		cout << "Error in reading file: /home/cs235e/week12/dictionary.txt\n";
		return;
	}

	while (fin >> word)
		dictionary.insert(word);

	fin.close();
}

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
	string fileName;
	cout << "What file do you want to check? ";
	cin >> fileName;

	// our Hash object.
	newHash dictionary(2000);
	vector <string> misspelled;

	readDictionary(dictionary);
	readFile(fileName, misspelled, dictionary);

	display(misspelled);
}
