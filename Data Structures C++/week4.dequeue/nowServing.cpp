/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Jon Michael Ossola
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

/***********************************************************
* Display function. Determine which of the two deques to 
* output from, and then display the emergency students first,
* and then everyone else.
***********************************************************/
void CSlab :: display(Deque<CSlab> &help, Deque<CSlab> &emergency) const
{
	if (help.empty() == true)
	    return;

	if (help.empty() != true && help.front().time < 1 && emergency.empty() != true)
	{
		cout << "\tEmergency for " << emergency.front().name; 
		cout << " for class " << emergency.front().myClass << ". ";
		cout << "Time left: " << emergency.front().time--;
		cout << endl;
		if (emergency.front().time == 0)
			emergency.pop_front();
	}
	else if (help.empty() != true) {
	   while (help.front().time == 0) {
		   help.pop_front();
		   if (help.empty() == true)
		   	return;
	   }
	   if (help.front().time > 0) {
		   cout << "\tCurrently serving " << help.front().name; 
		   cout << " for class " << help.front().myClass << ". ";
		   cout << "Time left: " << help.front().time--;
		   cout << endl;
	   }
	}
}

/***********************************************************
* Uh oh! We've got an emergency. Let's add this person
* onto the deque, and set their variables to the things
* they entered, then let's push it to the back of the deque.
***********************************************************/
void CSlab :: addEmergency(Deque<CSlab> &emergency, const string &classStudent, 
	const string &studentName, const int &thisTime, Deque<CSlab> &help)
{
	CSlab newStudent;

	newStudent.myClass = classStudent;
	newStudent.name = studentName;
	newStudent.time = thisTime;

	emergency.push_back(newStudent);

	display(help, emergency);
}

/***********************************************************
* Let's add a regular student onto our deque by creating
* a temporary object of our class, set the variables to
* the values the user inputed, then push it onto the deque.
***********************************************************/
void CSlab :: addStudent(Deque<CSlab> &help, const string &option, 
	const string &studentName, const int &thisTime, Deque<CSlab> &emergency)
{
	CSlab newStudent;

	newStudent.myClass = option;
	newStudent.name = studentName;
	newStudent.time = thisTime;

	help.push_back(newStudent);

	display(help, emergency);
}

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   int i = 0;
   string option;
   string classStudent;
   string studentName;
   int time;
   CSlab empty;
   Deque<CSlab> help;
   Deque<CSlab> emergency;

   do
   {
   	cout << '<' << i << "> ";
   	i++;

   	cin >> option;

   	switch (option[0])
   	{
   		case '!':
   		cin >> classStudent >> studentName >> time;
   		empty.addEmergency(emergency, classStudent, studentName, time, help);
   		break;
   		case 'C': case 'c':
   		cin >> studentName >> time;
   		empty.addStudent(help, option, studentName, time, emergency);
   		break;
   		case 'n':
   		empty.display(help, emergency);
   		break;
   		case 'f':
   		break;
   	}
   } while (option[0] != 'f');

   // end
   cout << "End of simulation\n";
}


