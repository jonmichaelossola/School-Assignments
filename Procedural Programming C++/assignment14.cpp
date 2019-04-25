/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The most difficult part is just understanding the different funcitoning parts in each function.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me, and I forgive him?\n";
   cout << "Till seven times?\n";
   return;
}
int responseLord()
{
   return 490;
}
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
