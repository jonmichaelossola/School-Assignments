/***********************************************************************
* Program:
*    Assignment 40,    
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part is to determine what to write here.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int readFile(char ticTacToe[][2], char fileName[])
{
   int i = 0;
   int counter = 0;

   cout << "Enter source filename: ";
   cin >> fileName;
   
   ifstream fin(fileName); // read file
   
   while (fin >> ticTacToe[i])
   {
      i++;
      counter++;
   }
   
   fin.close();
   
   return counter;
   
}

void writeFile(char ticTacToe[][2], int counter)
{
   int x = 0;
   char destinationFile[256];
   
   cout << "Enter destination filename: ";
   
   cin >> destinationFile;
   
   ofstream fout;

   for (int y = 0; y < 9; y++)
   {
      if (ticTacToe[y][0] == ' ')
      {
         ticTacToe[y][0] = '.';
      }
   }
   
   fout.open(destinationFile);
   
   for (int i = 0; i < 9; i++)
   {
      fout << ticTacToe[i] << " ";
   }
   
   fout.close();
   
   cout << "File written\n";
}

int main()
{
   char fileName[256];
   char ticTacToe[9][2];
   int i = 0;
   
   int counter = readFile(ticTacToe, fileName);

   for (int i = 0; i < counter; i++)
   {
      if (ticTacToe[i][0] == '.')
      {
         ticTacToe[i][0] = ' ';
      }
   }
   
   cout << " " << ticTacToe[0] << " |" << " " << ticTacToe[1] 
        << " |" << " " << ticTacToe[2] << " \n";
   
   cout << "---+---+---\n";
   
   cout << " " << ticTacToe[3] << " |" << " " << ticTacToe[4] 
        << " |" << " " << ticTacToe[5] << " \n";
   
   cout << "---+---+---\n";
   
   cout << " " << ticTacToe[6] << " |" << " " << ticTacToe[7] 
	<< " |" << " " << ticTacToe[8] << " \n";
   
   
   writeFile(ticTacToe, counter);
   
   
   
   return 0;
}
