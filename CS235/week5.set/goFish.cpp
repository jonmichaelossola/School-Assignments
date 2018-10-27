/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    <your names here>
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
	cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";
	Set <string> myHand;
	int i = 1;
	int numMatches = 0;
	string card;

	// Let's go and read the file.
	ifstream fin("/home/cs235e/week05/hand.txt");

	// Check for errors
	if (fin.fail()) {
		cout << "Error: Unable to read file\n";
		return;
	}

	// read the file into a string variable and save it into the set
	while (fin >> card)
		myHand.insert(card);

	fin.close();

	do 
	{
		cout << "round " << i << ": ";
		cin >> card;

		// check if the card is in the set; and, if so, erase it.
		if (myHand.find(card) != -1)
		{
			cout << "\tYou got a match!\n";
			myHand.erase(myHand.find(card));
			numMatches++;
		}
		else 
		{
			cout << "\tGo Fish!\n";
		}
		i++;
	} while (i != 6);

	cout << "You have " << numMatches << " matches!\n";
	cout << "The remaining cards: ";
	SetIterator <string> it;

	// iterate through the set to display the remaining cards.
	i = 0;
	for (it = myHand.begin(); it != myHand.end(); it++, i++) 
	{
		if (i == 3)
		{
			cout << *it << endl;
		}
		else
		{
			cout << *it << ", "; 
		}
	}
   return ;
}
