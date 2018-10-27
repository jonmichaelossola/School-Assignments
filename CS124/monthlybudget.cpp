/***********************************************************************
* Program:
*    Project 02, Monthly Budget  
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*   This project takes in the monthly budget of a person and
*   displays it for them.
*    
*   
*    
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      The most difficult part is to determine what to write here.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main, calculates all the finances and takes the input given from the 
 * user to calculate and place the values in a table.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   // Here are all the different variables used in the table
   
   float income;
   float budgete;
   float actualexpenses;
   float taxes;
   float tithe;
   float otherexpenses;
   
   // Here is the code for the user to input his/her budget
   
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgete;
   cout << "\tYour actual living expenses: ";
   cin >> actualexpenses;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithe;
   cout << "\tYour actual other expenses: ";
   cin >> otherexpenses;

   // Here, the variables inputed are placed in a table
   
   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5); 
   cout << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << 0.00 << setw(5);
   cout << "$" << setw(11) << taxes << endl; 
   cout << "\tTithing" << setw(10) << "$" << setw(11) << 0.00 << setw(5);
   cout << "$" << setw(11) << tithe << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgete << setw(5);
   cout << "$" << setw(11) << actualexpenses << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << 0.00 << setw(5);
   cout << "$" << setw(11) << otherexpenses << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference" << setw (7) << "$" << setw(11) << 0.00 << setw(5);
   cout << "$" << setw(11) << 0.00 << endl;
   
      
   
   return 0;
}
