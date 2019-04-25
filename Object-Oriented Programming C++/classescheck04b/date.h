/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

// put your class definition here
// along with the data members, and method prototypes
class Date
{
	private:
		int month;
		int day;
		int year;

	public:
		void set(int iDay, int iMonth, int iYear);
		void displayAmerican() const;
		void displayEuropean() const;
		void displayISO() const;
};

#endif
