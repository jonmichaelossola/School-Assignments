/***********************************************************************
* Program:
*    Project 04, Monthly Budget  
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    
*    In this program, it takes in several different variables that the user
*    inputs, and then places that in a table and computes the monthly budget
*    for that month.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part was just writing all the code and correcting it.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The function title here is the first output of the program, and it just
 * says what the program will do.
 ***********************************************************************/
void title()
{
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   return;
}

/********************************************************************
 * This function gathers information from the user on what their monthly
 * income is.
 *********************************************************************/
double getIncome()
{
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/**********************************************************************
 * The following function takes data from the user for budget expenses
 *********************************************************************/
double getBudget()
{
   double budgete;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgete;
   return budgete;
}

/**********************************************************************
 * This function takes information from the user about living expenses
 **********************************************************************/
double getActualLiving()
{ 
   double actualE;
   cout << "\tYour actual living expenses: ";
   cin >> actualE;
   return actualE;
}

/******************************************************************
 * This function takes in the actual tax of the user
 ******************************************************************/
double getActualTax()
{
   double taxes;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;
   return taxes;
}

/**********************************************************
 * this function finds the tax needed to input into the table
 * and returns it into the main function.
 *********************************************************/
double computeTax(double income)
{
   double yearlyIncome = (income * 12);
   double actualTaxes;
   double monthlyTax;
   
   if (yearlyIncome >= 0 && yearlyIncome < 15100)
      actualTaxes = (yearlyIncome * .10);

   else if (yearlyIncome >= 15100 && yearlyIncome < 61300)
      actualTaxes = (1510 + .15 * (yearlyIncome - 15100));
   
   else if (yearlyIncome >= 61300 && yearlyIncome < 123700)
      actualTaxes = (8440 + .25 * (yearlyIncome - 61300));
   
   else if (yearlyIncome >= 123700 && yearlyIncome < 188450)
      actualTaxes = (24040 + .28 * (yearlyIncome - 123700));
   
   else if (yearlyIncome >= 188450 && yearlyIncome < 336550)
      actualTaxes = (42170 + .33 * (yearlyIncome - 188450));
   
   else 
      actualTaxes = (91043 + .35 * (yearlyIncome - 336550));
  
   monthlyTax = (actualTaxes / 12);
   return monthlyTax;
}

/*************************************************************
 * This function takes in the actual tithing of the user
 ************************************************************/
double getActualTithing()
{
   double tithe;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithe;
   return tithe;
}

/***********************************************************
 * This function takes other expenses from the user
 ***********************************************************/
double getActualOther()
{
   double otherE;
   cout << "\tYour actual other expenses: ";
   cin >> otherE;
   return otherE;
}  

/***********************************************************
 * This calls all the other functions and displays them
 **********************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   title();
// This calls the function which places the header of the code here

   double income = getIncome();
   double budgete = getBudget();
   double actualE = getActualLiving();
   double taxes = getActualTax();
   double tithe = getActualTithing();
   double otherE = getActualOther();
   double titheB = (income * .10);
   double difference = (income - taxes - tithe - actualE - otherE);
   double monthlyTax = computeTax(income);
   double otherBudget = (income - titheB - budgete - monthlyTax);
      
   cout << "\nThe following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5); 
   cout << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << monthlyTax << setw(5);
   cout << "$" << setw(11) << taxes << endl; 
   cout << "\tTithing" << setw(10) << "$" << setw(11) << titheB << setw(5);
   cout << "$" << setw(11) << tithe << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgete << setw(5);
   cout << "$" << setw(11) << actualE << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << otherBudget << setw(5);
   cout << "$" << setw(11) << otherE << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference" << setw (7) << "$" << setw(11) << 0.00 << setw(5);
   cout << "$" << setw(11) << difference << endl;
   return 0;
}
