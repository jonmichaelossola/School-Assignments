/***********************************************************************
* Program:
*    Assignment 21,           
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*         This program is just basically an outline to be filled in,
*         and is useful when making a program because it will already 
*         have the structure to it.
*  
*    
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      The most difficult part is to determine what to write here.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/

int promptDevalue()
{
   return 0;
}

int promptInsurance()
{
   return 0;
}

int promptParking()
{
   return 0;
}

int getPeriodicCost()
{
   promptDevalue();
   promptInsurance();
   promptParking();
   return 0;
}

int promptMileage()
{
   return 0;
}

int promptGas()
{
   return 0;
}

int promptRepairs()
{
   return 0;
}

int promptTires()
{
   return 0;
}

int getUsageCost()
{
   promptGas();
   promptRepairs();
   promptTires();
   promptMileage();
   return 0;
}

void display(int costUsage,
             int costPeriodic)
{
   cout << "Success\n";
}

int main()
{
   display(getPeriodicCost(), getUsageCost());
   return 0;
}
