/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>
#include <iomanip>
#include "fibonacci.h"   // for fibonacci() prototype
using namespace std;


/**********************************************************************
* the extraction operator. We need to do the following: output the
* giant number that fibonacci has. So we do this by iterating through
* our list backwards, outputing the numbers with commas as we go.
* Also, don't include this in the .h because you will get a multiple
* definition error.
***********************************************************************/
std::ostream & operator << (std::ostream & out, WholeNumber &pHead)
{
	out << "\t";

	for (ListIterator <int> it = pHead.number.rbegin(); it != pHead.number.rend(); --it)
	{
		if (it.isPreviousNull() == true)
		{
			out << *it << endl;
			break;
		}
		else
		{
			out << setfill('0') << setw(3) << *it << ',';
		}
	}

	return out;
}

/***********************************************************************
* Here's the operator that killed. The plus equals operator. We need
* to figure out a way to add on monstrous numbers onto monstrous numbers
* by putting each three integers into a block in a linked list. Next,
* iterate through two lists and add numbers, keeping track of carry overs.
***********************************************************************/
WholeNumber & WholeNumber :: operator += (WholeNumber & rhs) throw (const char *)
{
	int carry = 0;
	int newNumber = 0;
	List <int> newNum;

	if (rhs.number.empty())
	{
		// we need to throw this if this is out of wack.
		throw "Cannot add anything from an empty list bozo!!";
	}
	else
	{
		// we are going to iterate through both this and rhs at the same time.
		ListIterator <int> itRHS = rhs.number.begin(); 

		// this is where it gets REEALLL hairy.
	   for (ListIterator <int> it = this->number.begin(); 
	   	it != this->number.end() || itRHS != rhs.number.end(); it++, itRHS++)
	   {
	   	  if (it != this->number.end() && itRHS != rhs.number.end())
	   	  {
	   	    if (*it + *itRHS + carry >= 1000)
	   	    {
	   	    	// this deals with numbers greater than one thousand.
	   	    	newNumber = -1000 + *it + *itRHS + carry;
	   	 	    newNum.push_back(newNumber);
	   	 	    carry = 1;
	   	 	    // if both nodes are null and we still have carry over, push back a one.
	   	 	    // then set carry over to zero again.
	   	 	    if (carry == 1 && it.isNextNull() == true 
	   	 	    	&& itRHS.isNextNull() == true)
	   	 	    {
	   	 	    	newNum.push_back(1);
	   	 	   	    carry = 0;
	   	 	    }
	   	    }
	   	    else  
	   	    {
	   	    	newNumber = *it + *itRHS + carry;
	   	 	    newNum.push_back(newNumber);
	   	 	    carry = 0;
	   	    }
	      }
	   	  else if (it == this->number.end())
	   	  {
	   	  	// however much bigger rhs is, push those numbers onto new number.
	   	  	while (itRHS != rhs.number.end())
	   	  	{
	   	  		newNum.push_back(*itRHS + carry);
	   	  		++itRHS;
	   	  		carry = 0;
	   	  	}
	   	  }
	   }
	}

	this->number = newNum;
	return *this;
}

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   WholeNumber x;
   WholeNumber y;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers
   for (int i = 0; i < number; i++)
   {
   	if (i < 2) {
   		if (i == 0) {
   			y.number.push_back(1);
   			cout << y;
   		}
   		else {
   			x.number.push_back(1);
   			cout << x;
   		}
   	}
   	else 
   	{
   		if (i % 2 == 0) {
   			y += x;
   			cout << y;
   		}
   		else {
   			x += y;
   			cout << x;
   		}
   	}
   }

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   WholeNumber a;
   WholeNumber b;
   //your code to display the Fibonacci number
   for (int i = 0; i <= number; i++)
   {
   	if (i == number)
   	{
   		if (i % 2 == 0) {
   			// we need to add one more to get to the current fibonacci number.
   			a += b;
   			cout << b;
   		}
   		else {
   			// same deal as above.
   			b += a;
   			cout << b;
   		}
   	}
   	else
   	{
   		if (i < 2) {
   			if (i == 0) {
   				// to start off, let's push back a one on each list.
   				a.number.push_back(1);
   			}
   			else {
   				b.number.push_back(1);
   			}
   		}
   		else
   		{
   			if (i % 2 == 0) {
   				// use plus equals operator to do the dirty work.
   				a += b;
   			}
   			else {
   				b += a;
   			}
   		}
   	}
   }
}


