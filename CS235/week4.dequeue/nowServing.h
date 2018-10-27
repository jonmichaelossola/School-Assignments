/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Jon Michael Ossola
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include "deque.h"     // for DEQUE
#include <string>	   // I feel the need, the need for strings.

// the interactive nowServing program
void nowServing();

class CSlab
{
public:
	string myClass;
	string name;
	int time;

	CSlab() : myClass("nope"), name("SwaggyG"), time(0) {}
	void display(Deque<CSlab> &x, Deque<CSlab> &y) const;
	void addStudent(Deque<CSlab> &x, const string &classStudent, 
	const string &studentName, const int &time, Deque<CSlab> &help);
	void addEmergency(Deque<CSlab> &x, const string &classStudent, 
	const string &studentName, const int &time, Deque<CSlab> &emergency);
};

#endif // NOW_SERVING_H

