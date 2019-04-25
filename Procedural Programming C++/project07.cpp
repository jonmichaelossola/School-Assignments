/***********************************************************************
* Program:
*    Project 07, Calendar Project   
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    My program is the calendar program. It takes from the user the month
*    and year that the user would like displayed, and then uses these
*    to display the calendar. 
*    
*    
*
*    Estimated:  4.0 hrs   
*    Actual:     4.0 hrs
*      The most difficult part was making the offset and display table.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function allows the user to input what month it is they want
 * to look up.
 ***********************************************************************/
int getMonth()
{
   int monthNumber;
   
   cout << "Enter a month number: ";
   cin >> monthNumber;
   
   while (monthNumber < 1 || monthNumber > 12)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> monthNumber;
   }
   return monthNumber;
}

/******************************************************************
 * This function takes the year from the user and returns it to 
 * the function main.
 *******************************************************************/
int getYear()
{
   int inputYear;
   
   cout << "Enter year: ";
   cin >> inputYear;
   
   while (inputYear < 1752 || inputYear > 2018)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> inputYear;
   }
   return inputYear;
}

/***************************************************************
* This function determines whether the year placed in by the user
* is a leap year and returns whether or not it is a leap year.
****************************************************************/
bool isLeapYear(int year)
{
   bool leapYear = false;
   if ( year % 4 == 0)
   {
      if (year % 100 == 0)
      {
         if (year % 400 == 0)
         {
            leapYear = true;
         }
      }
      else leapYear = true;
   }
   return leapYear;
}

/***************************************************************
* This function determines how many days are in the month.
* It takes that information and sends it to other functions.
***************************************************************/
int numDaysMonth(int month, int year)
{
   int numDaysMonth;
   
   
   if (month == 1)
      numDaysMonth = 31;
   else if (month == 2)
   {
      if (isLeapYear(year) == true)
         numDaysMonth = 29;
      else 
         numDaysMonth = 28;
   }
   else if (month == 3)
      numDaysMonth = 31;
   else if (month == 4)
      numDaysMonth = 30;
   else if (month == 5)
      numDaysMonth = 31;
   else if (month == 6)
      numDaysMonth = 30;
   else if (month == 7)
      numDaysMonth = 31;
   else if (month == 8)
      numDaysMonth = 31;
   else if (month == 9)
      numDaysMonth = 30;
   else if (month == 10)
      numDaysMonth = 31;
   else if (month == 11)
      numDaysMonth = 30;
   else if (month == 12)
      numDaysMonth = 31;
   
   return numDaysMonth;
}

/***************************************************************************
* This function finds out the number of days in the year that the user  
* inputs.
****************************************************************************/
int numDaysYear(int year)
{
   int numDaysYear;
   
   
   if (isLeapYear(year) == true)
   {
      numDaysYear = 366;
   }
   else if (isLeapYear(year) == false)
   {
      numDaysYear = 365;
   }
   return numDaysYear;
}

/*************************************************************************
* This function determines the offset of the calendar.
* It sends this information to the main function and display.
**************************************************************************/
int computeOffset(int year, int month)
{
   int totalDays = 0;  //Keeps track of total number of days from 1 Jan 1753
   
   for (int iYear = 1753; iYear < year; iYear++)
   {
      totalDays += numDaysYear(iYear);
   }
   for (int iMonth = 1; iMonth < month; iMonth++)
   {
      totalDays += numDaysMonth(iMonth, year);
   }
   
   totalDays = totalDays % 7;
   return totalDays;
}

/*************************************************************************
* This function displays all of the input and the calendar.
* The input of the month, year, offset, and days in a month are sent  
* to the function.
*************************************************************************/
void display(int month, int year, int offset, int daysMonth)
{
   int dayOfWeek;
   int day = offset;
   
   if (month == 1)
      cout << "January";
   else if (month == 2)
      cout << "February";
   else if (month == 3)
      cout << "March";
   else if (month == 4)
      cout << "April";
   else if (month == 5)
      cout << "May";
   else if (month == 6)
      cout << "June";
   else if (month == 7)
      cout << "July";
   else if (month == 8)
      cout << "August";
   else if (month == 9)
      cout << "September";
   else if (month == 10)
      cout << "October";
   else if (month == 11)
      cout << "November";
   else if (month == 12)
      cout << "December";
   
   cout << ", " << year << endl;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   
   if (day == 6)
   {
      cout << setw(4);
   }
   else
   {
      cout << setw(8 + 4 * day);
   }
   
   
   for (int dayWeek = 1; dayWeek <= daysMonth; dayWeek++)
   {
      cout << dayWeek;
      if (day != 5)
      {
         cout << setw(4);
      }
      if (day == 5)
      {
         cout << "\n" << setw(4);
      }
      else if (day == 6)
      {
         day = -1;
      }
      if (dayWeek == daysMonth && day != 5)
      {
         cout << endl;
      }
      day++;
   }
   
}

/***********************************************************************
* The main function calls the other functions.
************************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(year,month);
   cout << "\n";
   
   int daysYear = numDaysYear(year);
   int daysMonth = numDaysMonth(month, year);
   
   display(month, year, offset, daysMonth);
   
   
   
   return 0;
}
