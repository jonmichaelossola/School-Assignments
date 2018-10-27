/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy 
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    The program below takes in the user's input of the DNA of him or 
*    her and his relatives, and uses that input to measure to what 
*    degree are the DNA of the user and the DNA of his or her relatives
*    are the same. The program then converts that to a percentage
*    and displays that as well.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was figuring out all of the for loops.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
* The function below retrieves input from the user pertaining to their
* DNA sequence as well as how many potential relatives they have.
***********************************************************************/
int userInfo(char yourDNA[])
{
   int numRelatives;
   cout << "Enter your DNA sequence: ";
   cin >> yourDNA;
   
   cout << "Enter the number of potential relatives: ";
   cin >> numRelatives;
   cout << endl;
   return numRelatives;
}

/**********************************************************************
* The function below retrieves the names of all of the relatives of
* the user.
***********************************************************************/
void relativeNames(char relatives[][256], const int numRelatives)
{
   for (int x = 0; x < numRelatives; x++)
   {
      cout << "Please enter the name of relative #" << x + 1 << ": ";
      cin >> relatives[x];
   }
   cout << endl;
}

/**********************************************************************
* This function below allows the user to input the DNA sequence for 
* all of his relatives.
***********************************************************************/
void dnaSequence(const char relatives[][256], char dnaSequenceRelatives[][11],
                 const int numRelatives)
{
   for (int x = 0; x < numRelatives; x++)
   {
      cout << "Please enter the DNA sequence for " << relatives[x] << ": ";
      cin >> dnaSequenceRelatives[x];
   }
   cout << endl;
}

/************************************************************************
* The function below determines to what percent the user's DNA matches
* with the DNA of his or her relatives.
*************************************************************************/
void percentMatch(const char yourDNA[], const char dnaSequenceRelatives[][11],
                  const int numRelatives, const char relatives[][256])
{
   int counter = 0;
   for (int x = 0; x < numRelatives; x++)
   {
      for (int i = 0; i < 10; i++)
      {
         if (yourDNA[i] == dnaSequenceRelatives[x][i])
         {
            counter++;
         }
      }
      cout << "Percent match for " << relatives[x] << ": ";
      switch (counter)
      {
         case 10:
            cout << "100%\n";
            break;
         case 9:
            cout << "90%\n";
            break;
         case 8:
            cout << "80%\n";
            break;
         case 7:
            cout << "70%\n";
            break;
         case 6:
            cout << "60%\n";
            break;
         case 5:
            cout << "50%\n";
            break;
         case 4:
            cout << "40%\n";
            break;
         case 3:
            cout << "30%\n";
            break;
         case 2:
            cout << "20%\n";
            break;
         case 1:
            cout << "10%\n";
            break;
         case 0:
            cout << "0%\n";
            break;
      }
      counter = 0;
   }	
}

/**********************************************************************
 * The function main calls all of the other functions and displays
 * them to the screen.
 ***********************************************************************/
int main()
{
   char yourDNA[11];
   
   int numRelatives = userInfo(yourDNA);
   
   char relatives[numRelatives][256];
   
   relativeNames(relatives, numRelatives);
   
   char dnaSequenceRelatives[numRelatives][11];
   
   dnaSequence(relatives, dnaSequenceRelatives, numRelatives);
   
   percentMatch(yourDNA, dnaSequenceRelatives, numRelatives, relatives);
   
   return 0;
}
