/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"
#include <iostream>
using namespace std;

int main()
{
	int iDay;
	int iMonth;
	int iYear;
   // prompt for month, day, year
   cout << "Month: ";
	 cin >> iMonth;
	 cout << "Day: ";
	 cin >> iDay;
	 cout << "Year: ";
	 cin >> iYear;
   cout << endl;
   // create a Date object
    Date date;
   // set its values
    date.set(iDay, iMonth, iYear);
   // call each display function
    date.displayAmerican();
    date.displayEuropean();
    date.displayISO();

   return 0;
}
