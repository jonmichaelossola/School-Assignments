/***********************************************************************
* Header:
*    Set
* Summary:
*    This class contains the notion of a set: a bucket to hold
*    data for the user. The order and 
*
*    This will contain the class definition of:
*        Set         : A class that holds stuff
*        SetIterator : An iterator through Container
************************************************************************/

#ifndef SET_H
#define SET_H
#include <cassert>

template <class T>
class SetIterator;

template <class T>
class Set
{
public:
	// default constructor
	Set() : numItems(0), cap(0), myArray(NULL) {}

	// non-default constructor
	Set(int capacity) throw (const char *);

	// copy constructor
	Set(const Set<T> &rhs) throw (const char *);

	// destructor
	~Set() { delete [] myArray;                       }

	// assignment operator overloader
	Set<T> & operator = (const Set<T> &rhs) throw (const char *);

	// return if function is empty
	bool empty() const { return (numItems == 0);    }

	// returns size of array
	int size() const { return numItems;             }

	// returns the capacity
	int capacity() const { return cap;              }

	// clear the array
	void clear();

	// insert an item into the array
	void insert(const T &item);

	// erase an item from the this.
	void erase(int index);

	// find an item in the array
	int find(const T &item);

	// the intersection operator
	Set<T> operator && (const Set<T> &rhs);

	// the union operator
	Set<T> operator || (const Set<T> &rhs);

	// return iterator pointing to first element in array
	SetIterator<T> begin() { return SetIterator<T>(myArray); }

	// return iterator pointing to last element in array
	SetIterator<T> end() { return SetIterator<T>(myArray +  numItems); }
private:

	int numItems;

	int cap;

	T * myArray;

	void realloc() throw (const char *);
};

/************************************************************************
* This is the Set Iterator class. It is the iterator for the Set class.
* It points to the array in the Set class when declared properly.
************************************************************************/
template <class T>
class SetIterator
{
public:
	// default constructor
	SetIterator() : p(NULL) {}

	// initialize to direct p to some item
	SetIterator(T * p) : p(p) {}

	// not equals operator
	bool operator != (const SetIterator<T> &rhs) const
	{
		return rhs.p != this->p;
	}

	bool operator == (const SetIterator<T> &rhs) const
	{
		return rhs.p == this->p;
	}

	// dereference operator
	T & operator * ()
	{
		return *p;
	}

	// postfix increment
	SetIterator <T> & operator ++ ()
	{
		p++;
		return *this;
	}

	// postfix increment
	SetIterator <T> operator ++ (int postfix)
	{
		SetIterator tmp(*this);
		p++;
		return tmp;
	}
private:
	T * p;
};

/************************************************************************
* The non-defualt constructor. It takes in an integer for the capacity,
* and then allocates a new array, sets the number of items to zero and
* sets the capacity to the new capacity.
************************************************************************/
template <class T>
Set <T> :: Set(int newCapacity) throw (const char *)
{
	assert(newCapacity >= 0);

	if (newCapacity == 0)
	{
		this->numItems = this->cap = 0;
		this->myArray = NULL;
		return;
	}

	this->numItems = 0;
	this->cap = newCapacity;

	try 
	{
		myArray = new T[newCapacity];
	}
	catch (std::bad_alloc) 
	{
		throw "ERROR: Unable to allocate a new buffer for Set";
	}

	// initialize the container by calling the default constructor
    for (int i = 0; i < newCapacity; i++)
      this->myArray[i] = T();
}

/************************************************************************
* The copy constructor. If the capacity of the right hand side is zero, 
* it's an empty array. set everything to zero and return. Else, set 
* everything the same as the right hand side in a different array.
************************************************************************/
template <class T>
Set <T> :: Set(const Set<T> &rhs) throw (const char *)
{
	assert(cap >= 0);

	if (rhs.cap == 0)
    {
       this->numItems = 0;
       this->cap = 0;
       this->myArray = NULL;
       return;
    }

    assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
	this->numItems = rhs.numItems;
	this->cap = rhs.cap;

	try 
	{
		this->myArray = new T[cap];
	}
	catch (std::bad_alloc) 
	{
		throw "ERROR: Unable to allocate a new buffer for Set";
	}

	try 
	{
	   for (int i = 0; i < numItems; i++)
		   this->myArray[i] = rhs.myArray[i];
	}
	catch (char * message) 
	{
		std::cout << message << std::endl;
	}

	// the rest needs to be filled with the default value for T
    for (int i = numItems; i < cap; i++)
       this->myArray[i] = T();
}

/************************************************************************
* Assignment operator overload. Make sure that the right hand side and
* the left hand side aren't the same array. Delete any former lhs data, 
* and match everything from the lhs to the rhs.
************************************************************************/
template <class T>
Set<T> & Set<T> :: operator = (const Set<T> &rhs) throw (const char *)
{
	// we don't want the same address for our lhs and rhs. That'd be bad.
	assert(this != &rhs);

	if (this->myArray != NULL)
	{
		delete [] this->myArray;
		this->myArray = NULL;
		this->numItems = 0;
		this->cap = 0;
	}

	this->numItems = rhs.numItems;	
	this->cap = rhs.cap;

	try 
	{
		this->myArray = new T[cap];
	}
	catch (std::bad_alloc) 
	{
		throw "ERROR: Unable to allocate a new buffer for Set";
	}

	for (int i = 0; i < numItems; i++) 
		this->myArray[i] = rhs.myArray[i];

	for (int i = numItems; i < cap; i++)
		this->myArray[i] = T();

	return *this;
}


/************************************************************************
* Clear function. To clear all of the items but keep the pointer, we 
* need to delete the array but not set the pointer to null, because we
* might want to add items again.
************************************************************************/
template <class T>
void Set <T> :: clear() 
{
	numItems = 0;
	delete [] myArray;
}

/************************************************************************
* This is the insert function. Check if numItems is equal to cap or greater,
* and reallocate, then check if item isn't in the array. Then add the item
* into the spot where it is needed, making sure we aren't making copies.
************************************************************************/
template <class T>
void Set <T> :: insert(const T &item)
{
	if (numItems >= cap)
		realloc();

	if (find(item) == -1) {

		int keepTrack;

		if ((cap == 1) || (item > myArray[numItems-1]))
			myArray[numItems] = item;
		else  
		{
			for (int i = numItems-1; ((i >= 0) && (myArray[i] > item)); i--) 
			{
			       keepTrack = i;
			       myArray[i+1] = myArray[i];
		    }

			myArray[keepTrack] = item;
		}

		numItems++;
	}
}

/************************************************************************
* Erase function. Simply put, if you want to erase an item, decrement
* number of items variable, and then push every other variable down one 
* spot that was previously ahead of the variable.
*************************************************************************/
template <class T>
void Set <T> :: erase(int index)
{
	if (index == numItems-1)
		myArray[index] = T();
	else 
	{
		for (int i = index; i < numItems-1; i++) 
		{
		    myArray[i] = myArray[i+1];
		}
	}

	numItems--;
}

/************************************************************************
* Find function. We are going to use a binary search algorithm to save time.
* We have a begin and end variable that keep track of the index, and we 
* half the index each time, until we find it. Else, return a negative one.
*************************************************************************/
template <class T>
int Set <T> :: find(const T &item)
{
	int iBegin = 0;
	int iEnd = numItems - 1;

	// this is our binary search algorithm, saves TONS of time.
	while (iBegin <= iEnd) {

		int iMiddle = (iBegin + iEnd) / 2;

		if (item == myArray[iMiddle])
			return iMiddle;
		else if (item < myArray[iMiddle])
			iEnd = iMiddle - 1;
		else
			iBegin = iMiddle + 1;
	}

	return -1;
}

/*************************************************************************
* Reallocation function. If the capacity of the array is zero, then make 
* it one. If the number of items has reached the capacity, save all of the
* items on a new array with double the size, and delete the former array.
*************************************************************************/
template <class T>
void Set<T> :: realloc() throw (const char *)
{
	if (cap == 0) {
		cap = 1;

		try {
			myArray = new T[cap];
		}
		catch (std::bad_alloc) {
			throw "ERROR: Unable to allocate a new buffer for Set";
		}
	}
	else if (numItems == cap) {
		T * tmpData;
		cap *= 2;

		try {
			tmpData = new T[cap];
		}
		catch (std::bad_alloc) {
			throw "ERROR: Unable to allocate a new buffer for Set";
		}

		for (int i = 0; i < numItems; i++) {
			tmpData[i] = myArray[i];
		}

		delete [] myArray;
		myArray = tmpData;
	}
}

/*************************************************************************
* The union operator. We are going to make a new set, that combines all of
* the numbers from the right hand side, as well as the data from the this.
* Return the new set with all of the combined data.
*************************************************************************/
template <class T>
Set<T> Set<T> :: operator || (const Set<T> &rhs)
{
	Set<T> newSet;
	int iSet1 = 0;
	int iSet2 = 0;

	while (iSet1 < this->numItems || iSet2 < rhs.numItems)
	{
		if (iSet1 == this->numItems)
			newSet.insert(rhs.myArray[iSet2++]);
		else if (iSet2 == rhs.numItems)
			newSet.insert(this->myArray[iSet1++]);
		else if (this->myArray[iSet1] == rhs.myArray[iSet2])
		{
			newSet.insert(this->myArray[iSet1]);
			iSet2++;
			iSet1++;
		}
		else if (this->myArray[iSet1] < rhs.myArray[iSet2])
			newSet.insert(this->myArray[iSet1++]);
		else 
			newSet.insert(rhs.myArray[iSet2++]);
	}


	return newSet;
}

/*************************************************************************
* Intersection operator. We only want the items that are both in this and
* on the right hand side. So loop through the arrays to find the matching
* pieces, match them together, and then return the new set.
*************************************************************************/
template <class T>
Set<T> Set<T> :: operator && (const Set<T> &rhs)
{
	Set<T> newSet;
	int iSet1 = 0;
	int iSet2 = 0;

	while ((iSet1 < this->numItems) || (iSet2 < rhs.numItems)) {

		if (iSet1 >= this->numItems)
			return newSet;
		else if (iSet2 >= rhs.numItems)
			return newSet;
		else if (this->myArray[iSet1] == rhs.myArray[iSet2]) {
			newSet.insert(rhs.myArray[iSet2]);
			iSet2++;
			iSet1++;
		}
		else if (this->myArray[iSet1] < rhs.myArray[iSet2]) 
			iSet1++;
		else
			iSet2++;
	}

	return newSet;
}

#endif // SET_h