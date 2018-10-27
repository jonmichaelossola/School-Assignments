/***********************************************************************
 * Component:
 *    Week 10, Map
 *    Brother Ercanbrack, CS 235
 * Author:
 *    Jon Michael Ossola
 * Summary:
 *    Map out the entire book of mormon, among other things.
 ************************************************************************/


#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

/**********************************************************************
* Read file function. Take in a map, filename, and count variable, open 
* the file, read the file and change the words to cut out punctuation and
* capital letters. Put into map, close the file.
***********************************************************************/
void readFile(const std::string &fileName, std::map <std::string, int> &myMap, int &count)
{
	std::ifstream fin;
	std::string word;

	fin.open(fileName.c_str());

	if (fin.fail())
	{
		std::cout << "Couldn't open the file\n";
		return;
	}

	// count is going to track how many words there are in the entire file.
	count = 0;

	while (fin >> word)
	{
		std::string tmp;
		for (int i = 0; i < word.length(); i++)
		{
			if ( isupper(word[i]) )
				tmp += tolower(word[i]);
			else if ( ispunct(word[i]) && word[i] != '-');
			else
				tmp += word[i];
		}
		word = tmp;
		myMap[word]++;
		count++;
	}
	
	fin.close();
}	

/**********************************************************************
* Display function. We have a map of all of the things in the file,
* so we are going to put organize each item into a temporary multimap
* that we will then display to the screen.
**********************************************************************/
void display(std::map <std::string, int> &myMap, const int & count)
{
	std::cout << "Number of words processed: " << count << std::endl;
	std::cout << "100 most common words found and their frequencies:\n";

	std::multimap <int, std::string> sorter;

	// use the reverse iterator of the map to 
	for (std::map <std::string, int> :: reverse_iterator it = myMap.rbegin(); it != myMap.rend(); it++)
	{
		// we are going to store items into the multi map by integers. We use a multi map
		// because we want copies of the integers.
		sorter.insert(std::pair<int, std::string>((*it).second, (*it).first));
	}

	std::map <int, std::string> :: reverse_iterator it = sorter.rbegin();
	for (int i = 0; i < 100 && it != sorter.rend(); i++, it++)
	{
		std::cout << std::setw(23) << (*it).second << " - " << (*it).first << std::endl;
	}
}

/*********************************************************************
* Main function. Calls on the other functions of reading the file
* and display to do the real dirty work. Once all that jazz is done,
* return out of the function.
**********************************************************************/
int main()
{
	std::string fileName;
	std::map <std::string, int> myMap;
	int count;

	std::cout << "Enter filename: ";
	std::cin >> fileName;
	std::cout << std::endl;

	readFile(fileName, myMap, count);

	display(myMap, count);

	return 0;
}