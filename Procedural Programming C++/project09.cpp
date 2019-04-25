/***********************************************************************
* Program:
*    Project 09, Jon Michael Ossola  
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

/**************************************************************************
* This function traverses the file and finds the questions it needs to 
* ask the user. Then the function prompts the user for the missing value.
**************************************************************************/
void askQuestion(char words[][32])
{
   for (int i = 0; i < 256; i++)
   {
      if (words[i][0] == '<' && isalpha(words[i][1]))
      {
         cout << "\t" << (char)toupper(words[i][1]);
         
         for (int nextCharacter = 2; words[i][nextCharacter] != '>';
              nextCharacter++)
         {
            if (words[i][nextCharacter] == '_')
            {
               cout << " ";
            }
            else 
               cout << words[i][nextCharacter];
         }
         
         cout << ": ";
         cin.getline(words[i], 32, '\n');
         cin.get(words[i], 32);
         
      }
   }
}

/*************************************************************************
* The function below opens the file, and reads it. Then the 
* function has a multidimensional array which stores those words
* and then sends that array to the function above.
**************************************************************************/
int main()
{
   char fileName[256];
   
   getFileName(fileName);
   
   char words[50][32];
   
   int i = 0;
   
   ifstream fin(fileName);
   
   if (fin.fail())
   {
      cout << "ERROR! :D\n";
   }
   
   while (fin >> words[i])
   {
      i++;
   }
   
   fin.close();
   askQuestion(words);
   cout << "Thank you for playing.\n";
   
   return 0;
}
