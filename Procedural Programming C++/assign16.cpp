/***********************************************************************
* Program:
*    Assignment 16,           
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    My program that I just created takes the income of a person and 
*   determines what their tax bracket is.
*    
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
 * The function below determines what someone's tax bracket is and then
 * sends that information back to the main function.
 ***********************************************************************/
int computeTax(int yearlyIncome)
{
   int taxBracket;
   
   if (yearlyIncome > 0 && yearlyIncome < 15100)
      taxBracket = 10;

   else if (yearlyIncome > 15100 && yearlyIncome < 61300)
      taxBracket = 15;

   else if (yearlyIncome > 61300 && yearlyIncome < 123700)
      taxBracket = 25;

   else if (yearlyIncome > 123700 && yearlyIncome < 188450)
      taxBracket = 28;

   else if (yearlyIncome > 188450 && yearlyIncome < 336550)
      taxBracket = 33;

   else if (yearlyIncome > 336550)
      taxBracket = 35;

   return taxBracket;
}
   
/***********************************************************************
 * The main function here takes from the user their yearly income and 
 * then uses the other function to find their tax bracket, and main
 * displays that information.
 **********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   int yearlyIncome;
   cout << "Income: ";
   cin >> yearlyIncome;
   cout << "Your tax bracket is " << computeTax(yearlyIncome) << "%\n";
   

   return 0;
}
