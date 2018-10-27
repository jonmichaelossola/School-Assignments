/***********************************************************************
* Program:
*    Assignment 26,    
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
void getFilename(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

float readFile(char fileName[])
{
   float sum;
   float grade;
   int count = 0;
   // declare output stream
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;
   }
   // read the data
   while (fin >> grade)
   {
      count++;
      sum += grade;
   }
   if (count != 10)
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;
   }
   fin.close();
   sum = (sum / count);
   return sum;   
}

void display(float average)
{
   cout << "Average Grade: " << average << "%" << endl;
   
}

int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);
   char fileName[250];
   getFilename(fileName);
   float average = readFile(fileName);
   if (average != -1)
   {
      display(average);
   }

   return 0;
}
