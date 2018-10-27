#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
	int myFront;
	int myBack;
	int cap;
	int numItems;
	T * data;
public:
	// default constructor
	Queue() : myBack(0), cap(0), myFront(0), numItems(0), data(NULL) {}

	// non - default constructor passing with index
	Queue(int index) throw (const char *);

	// copy constructor 
	Queue(const Queue <T> & rhs) throw (const char *);

	// Destructor for the class
	~Queue() { delete [] data; }

	// assignment operator overload
	Queue <T> & operator = (const Queue <T> & rhs) throw (const char *);

	// size function
	int size() const { return numItems; }

	// capacity function -- return the capacity.
	int capacity() const { return cap; } 

	// pop function -- removes an item from head of queue.
	void pop() throw (const char *);

	// returns the item currently in the back of the queue.
	T &back() const throw (const char *);

	// returns the item currently at the front of the queue.
	T &front() const throw (const char *);

	// Adds an item to the queue.
	void push(const T &item) throw (const char *);

	// empty function
	bool empty() const { return numItems == 0; }

	// empties queue of all items.
	void clear();
};


/*****************************************************
* Non default constructor for the Queue class. Set the
* capacity to the passed in parameter, allocate space for 
* an array that size, set everything else to zero.
*******************************************************/
template <class T>
Queue <T> :: Queue(int capacity) throw (const char *)
{
	cap = capacity;
	myBack = 0;
	myFront = 0;
	numItems = 0;

	// allocate memory
	try
	{
		data = new T[cap];
	}
	catch (bad_alloc)
	{
		throw "ERROR: Unable to allocate a new buffer for queue";
	}
}


/******************************************************
* Copy constructor. Set everything the same to the 
* right hand side, and then allocate space for a new
* array. Copy over the items from the right hand side.
********************************************************/
template <class T>
Queue <T> :: Queue(const Queue <T> & rhs) throw (const char *)
{
	this->cap = rhs.cap;
	this->myFront = 0;
	this->myBack = rhs.numItems;
	this->numItems = rhs.numItems;

	try 
	{
		this->data = new T[cap];
	}
	catch (bad_alloc)
	{
		throw "ERROR: Unable to allocate a new buffer for Queue";
	}

	// put the rhs items into our object
    int f = rhs.myFront;
	for (int i = 0; i != rhs.numItems; i++)
	{
		this->data[i] = rhs.data[f];
		f = (f+1) % cap;
	}
}

/*****************************************************************
* Get the item at the back of the array. If the array is
* empty, throw an exception. if the bottom is zero, return 
* the cap minus one, and for everything else return array minus one.
*****************************************************************/
template <class T>
T &Queue <T> :: back() const throw (const char *)
{
	if (empty())
		throw "ERROR: attempting to access an item in an empty queue";
	else if (myBack > 0)
		return data[myBack-1];
	else if (myBack == 0)
		return data[cap-1];
}

/*********************************************************
* get the item in the front of the array. if the array is 
* empty, throw an error. Otherwise, return that item in the
* front.
*********************************************************/
template <class T>
T &Queue <T> :: front() const throw (const char *)
{
	if (empty())
		throw "ERROR: attempting to access an item in an empty queue";
	else 
		return data[myFront];
}

/********************************************************
* The assignment operator. if data already was something,
* delete it all. Next, set everything to the right
* hand side and copy over all the other items.
*********************************************************/
template <class T>
Queue <T> & Queue <T> :: operator = (const Queue <T> &rhs) throw (const char *)
{
	// we don't want this to be the same as rhs.
	assert(this != &rhs);

	// if data is something beforehand, delete it!
	if (this->data != NULL)
	{
		delete [] this->data;
		this->data = NULL;
		this->cap = 0;
		this->myFront = 0;
		this->myBack = 0;
		this->numItems = 0;
	}

	this->cap = rhs.cap;
	this->myFront = 0;
	this->numItems = rhs.numItems;
	this->myBack = rhs.numItems;

	// allocate new memory for the left hand side
	try
	{
		this->data = new T[cap];
	}
	catch (bad_alloc)
	{
		throw "ERROR: Unable to allocate a new buffer for Queue";
	}

	// copy over the items
    int f = rhs.myFront;
	for (int i = 0; i != rhs.numItems; i++)
	{
		this->data[i] = rhs.data[f];
		f = (f+1) % cap;
	}

	return *this;
}

/******************************************************
* If the array is not empty, we need to pop the item
* off of the top of the array, by incrementing the 
* array. Otherwise throw an exception.
******************************************************/
template <class T>
void Queue <T> :: pop() throw (const char *)
{
	if ( !empty() )
	{
		numItems--;
		myFront = (myFront + 1) % cap;
	}
	else
		throw "ERROR: attempting to pop from an empty queue";
}

/*****************************************************************
* We need to push an item onto the queue. if the capacity is zero,
* allocate a new array with one space. If the number of items is 
* equal to the capacity, allocate more space. Else just put the item on.
*****************************************************************/
template <class T>
void Queue <T> :: push(const T &item) throw (const char *)
{
	T * tempData;
	int oldCap = cap;

	if (cap == 0)
	{
		try
		{
			data = new T[cap = 1];
		}
		catch (bad_alloc)
		{
			throw "ERROR: Unable to allocate a new buffer for queue";
		}

		data[myBack] = item;

		// make a new back and store the data in that value
		myBack = (myBack + 1) % cap;

		// push the item to the new back
		numItems++;

		return;
	}
	else if (numItems == cap)
	{
		try
		{
			tempData = new T[cap * 2];
		}
		catch (bad_alloc)
		{
			throw "ERROR: Unable to allocate a new buffer for queue";
		}

		// copy over the items
        int f  = myFront;
		for (int i = 0; i != numItems; i++)
		{
			tempData[i] = data[f];
			f = (f+1) % cap;
		}

		// let's not have any leaking data.
		delete [] data;

		// set our data the new data we made.
		data = tempData;

		// set the top to the zero element in data.
		myFront = 0;

		// set the bottom to the number of items
		myBack = numItems;

		// double the size of cap.
		cap *= 2;
	}

	// set the item into the bottom spot
	data[myBack] = item;

	// set the bottom to the next item in the list.
	myBack = (myBack + 1) % cap;

	// add to the number of items we have.
	numItems++;
}

/******************************************************
* Clear function. This is pretty simple, we don't need
* to deallocate anything. Just set the top, bottom and 
* number of items to zero.
******************************************************/
template <class T>
void Queue <T> :: clear()
{
	myFront = 0;
	myBack = 0;
	numItems = 0;
}


#endif // queue.h