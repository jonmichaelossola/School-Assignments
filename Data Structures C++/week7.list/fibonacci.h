/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jon Michael Ossola
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "list.h"

class WholeNumber
{
public:
	List <int> number;
	WholeNumber(const WholeNumber & rhs) { this->number = rhs.number; }
	WholeNumber() {}
	~WholeNumber() { number.clear(); }
	WholeNumber & operator += ( WholeNumber & rhs) throw (const char *);
	void display(List <int> &myList, int carry);
};


// the interactive fibonacci program
void fibonacci();

#endif // FIBONACCI_H

