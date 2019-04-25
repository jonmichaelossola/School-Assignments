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
void determineGrade(char grades[], int gradeNumber)
{
   if (gradeNumber > 89)
   {
      cout << "Your grade is an: " << grades[0] << endl;
   }
   else if (gradeNumber > 79 && gradeNumber < 90)
   {
      cout << "Your grade is a: " << grades[1] << endl;
   }
   else if (gradeNumber > 69 && gradeNumber < 80)
   {
      cout << "Your grade is a: " << grades[2] << endl;
   }
   else if (gradeNumber < 70)
   {
      cout << "I'm sorry, you have failed the class..\n";
   }
}

int main()
{
   int gradeNumber;
   cout << "What was your test score (out of 100)? ";
   cin >> gradeNumber;
   char grades[5] =
   {
      'A', 'B', 'C', 'D', 'F'
   };
   determineGrade(grades, gradeNumber);
   return 0;
}
