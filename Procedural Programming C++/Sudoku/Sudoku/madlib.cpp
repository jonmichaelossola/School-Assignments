//
//  madlib.cpp
//  Sudoku
//
//  Created by Jon Michael Ossola on 10/13/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <stdio.h>

/***********************************************************************
 * Program:
 *    Project 10, Jon Michael Ossola
 *    Brother Cook, CS124
 * Author:
 *    Jon Michael Ossola
 * Summary:
 *    This is my project. It takes a file that
 *    the user inputs, and takes that file, and stores the whole thing
 *    in an array. Next, in one of the functions below,
 *    it takes that array, traverses it, and takes all of the questions
 *    from the array and prompts the user. Finally, the project prints
 *    out good game!
 *    Estimated:  1.0 hrs
 *    Actual:     2.0 hrs
 *      The most difficult piece was finding out how to prompt the user to
 *      ask a question for each of the parts of the file.
 ************************************************************************/

#include <iostream>
using namespace std;
#include <fstream>

/**********************************************************************
 * The function below finds the name of the file from the user and
 * that will be used in main.
 ***********************************************************************/
void getFileName(char fileName[])
{
    cout << "Please enter the filename of the Mad Lib: ";
    cin >> fileName;
}

/*******************************************************************
 * My Print Space Function. This handles all of the cases where
 * we either need to print a space or not print a space.
 ********************************************************************/
void printSpace(char words[][32], int i)
{
    // handle the new line character
    // no space before or after
    if ((words[i][0] == ':' && words[i][1] == '!')
        || (words[i+1][0] == ':' && words[i+1][1] == '!')) {
        return;
    }
    
    // handle double quotes
    // no space after open quotes no space before closing quotes
    if (words[i][1] == '<' || words[i+1][1] == '>')
        return;
    
    // handle periods and commas
    // no space before
    if (words[i+1][1] == '.' || words[i+1][1] == ',') {
        return;
    }
    
    cout << " ";
}

/*******************************************************************
 * This function edits all of the symbols and turns them into their
 * assigned values. It also inputs the proper grammar and text.
 ********************************************************************/
void display(char words[][32], int numWords)
{
    for (int i = 0; i < numWords; i++)
    {
//        if (words[i][0] == 'z')
//            cout << "BRUH";
        
        if (words[i][0] == ':' && words[i][1] == '!') {
            // situation of new line character
            cout << endl;
        }
        else if (words[i][0] == ':' && (words[i][1] == '<' ||
                                        words[i][1] == '>')) {
            // the case of parenthases
            cout << "\"";
        }
        else if (words[i][0] == ':') {
            cout << words[i][1];
        }
        else {
            // else, display the word
            cout << words[i];
        }
        
        // now call print space function.
        if (i == numWords-1)
            cout << endl;
        else
            printSpace(words, i);
    }
}

/*******************************************************************
 * This function below reads the data from the file, takes the
 * information, and stores it in the array declared in main.
 **********************************************************************/
int readFile(char fileName[], char words[][32])
{
    int i = 0;
    int count = 0;
    
    ifstream fin(fileName);
    
    if (fin.fail())
    {
        cout << "ERROR! :D\n";
    }
    
    while (fin >> words[i])
    {
        i++;
        count++;
    }
    
    fin.close();
    
    return count;
}

/**************************************************************************
 * This function traverses the file and finds the questions it needs to
 * ask the user. Then the function prompts the user for the missing value.
 **************************************************************************/
void askQuestion(char words[][32], int numWords)
{
    for (int i = 0; i < numWords; i++)
    {
        if (words[i][0] == ':' && isalpha(words[i][1]))
        {
            cout << "\t" << (char)toupper(words[i][1]);
            
            for (int nextChar = 2; words[i][nextChar] != '\0'; nextChar++)
            {
                if (words[i][nextChar] == '_')
                    cout << " ";
                else
                    cout << (char)tolower(words[i][nextChar]);
            }
            
            cout << ": ";
            cin.getline(words[i], 32, '\n');
            cin.get(words[i], 32);
            
        }
    }
    cout << endl;
}

/*************************************************************************
 * The function below opens the file, and reads it. Then the
 * function has a multidimensional array which stores those words
 * and then sends that array to the function above.
 **************************************************************************/
int main()
{
    char fileName[256];
    
    char words[100][32];
    
    char repeatEverything;
    
    do {
        getFileName(fileName);
        
        int numWords = readFile(fileName, words);
        
        askQuestion(words, numWords);
        
        display(words, numWords);
        
        cout << "Do you want to play again (y/n)? ";
        
        cin >> repeatEverything;
    }
    while (repeatEverything == 'y');
    
    if (repeatEverything == 'n')
    {
        cout << "Thank you for playing.\n";
    }
    
    return 0;
}
