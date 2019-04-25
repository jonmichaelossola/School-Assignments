/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/

#include "date.h"
#include <iostream>
using namespace std;

// Put your method bodies here...
void Date::set(int iDay, int iMonth, int iYear)
{
	day = iDay;
	month = iMonth;
	year = iYear;
}

void Date::displayAmerican() const
{
	cout << month << "/" << day << "/" << year;
	cout << endl;
}

void Date::displayEuropean() const
{
	cout << day << "/" << month << "/" << year;
	cout << endl;
}

void Date::displayISO() const
{
	cout << year << "-" << month << "-" << day;
	cout << endl;
}
