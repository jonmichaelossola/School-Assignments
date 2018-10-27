/***********************************************************************
* Program:
*    Assignment 00,    
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
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
char computeLetterGrade(int numberGrade)
{
   char letterGrade;
   
   switch (numberGrade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
   
   return letterGrade;
}

void computeGradeSign(int numberGrade)
{
   if (numberGrade % 10 >= 7)
   {
      cout << (numberGrade % 10 >= 7 && numberGrade / 10 != 10 ? "+\n" : "\n");
   }
   else 
      cout << (numberGrade % 10 <= 3 ? "-\n" : "\n");
   
}

int main()
{
   int numberGrade;
   
   cout << "Enter number grade: ";
   cin >> numberGrade;
   
   char letterGrade = computeLetterGrade(numberGrade);
   
   cout << numberGrade << "%" << " is " << letterGrade;
   computeGradeSign(numberGrade);
   
   return 0;
}
