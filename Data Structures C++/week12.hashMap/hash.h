/***********************************************************************
* Hash Class:
* Author: Jon Michael Ossola
* Implements a hash class.
*
************************************************************************/
#include <iostream>
#include <list>
#include <vector>

template <class T>
class Hash
{
public:
	// non default constructor
	Hash(const int & newCap) throw (const char *);

	// copy constructor
	Hash(const Hash & rhs) throw (const char *);

	// destructor
	~Hash();

	// assignment overloaded operator
	Hash & operator = (const Hash & rhs) throw (const char *);

	// empty function
	bool empty() const { return (numItems == 0); }

	// size function
	int size() const { return numItems; }

	// capacity function
	int capacity() const { return cap; }

	// clears all elements in the Hashmap
	void clear();

	// finds a certain value in the array
	bool find(const T & item);

	// insert function
	void insert(const T & item);

	// this is our Hash function. Pure virtual. Swag buckets
	virtual int hash(const T & item) const = 0;

	void debug();
protected:
	// a vector which will hold our linked lists and bucket of variables.
	std::vector < std::list<T> > data;

	// this will tell us the number of items in the array.
	int numItems;

	// This will track the number of variables we need in our hash table.
	int cap;
};

/************************************************************************
* Class destructor. Because the Vector and the List take care of  
* themselves when they fall out of scope, we really don't even need
* to do anything. They will delete themselves.
*************************************************************************/
template <class T>
Hash<T> :: ~Hash()
{
	// This is literally pointless. Vector and lists take care
	// of themselves. Thanks a lot, testBed.
}

/***********************************************************************
* Non default constructor. We are passed in the capacity, so we allocate
* a new array, set the number of items to zero, and the capacity to
* zero.
************************************************************************/
template <class T>
Hash<T> :: Hash(const int & newCap) throw (const char *)
{
	// allocate space for an array of lists! :D
	data.resize(newCap);

	// set everything else to zero or the passed in value.
	numItems = 0;
	this->cap = newCap;
}

/************************************************************************
* Copy constructor. Copy over all of the items from the right hand 
* side to the left hand side. Set the private data of each object
* to be the same.
************************************************************************/
template <class T>
Hash<T> :: Hash(const Hash & rhs) throw (const char *)
{
	// allocate the space necessary in our vector.
	data.resize(rhs.data.size());

	// make sure that the data members are the same.
	this->numItems = rhs.numItems;
	this->cap = rhs.cap;

	// if there's nothing in the array, then there's nothing else to be done.
	if (numItems == 0)
		return;

	// now, copy over the items.
	data = rhs.data;
}

/***********************************************************************
* Assignment operator. We need to keep in mind, that if there is data
* in the thing being assigned to, we need to clear it first. Next,
* set all the data equal to the right hand side.
************************************************************************/
template <class T>
Hash<T> & Hash<T> :: operator = (const Hash & rhs) throw (const char *)
{
	if (this->data.size() > 0)
	{
		this->clear();
	}

	// set the vector's capacity to rhs' capacity.
	data.resize(rhs.cap);

	// set the variables to be the same
	this->numItems = rhs.numItems;
	this->cap = rhs.cap;

	// call on vector's assignment operator, and in turn, call on 
	// list assignment operator.
	this->data = rhs.data;
}

/***********************************************************************
* We need to clear all of the items to their previous state. So we need
* to clear all the data from the linked lists.
************************************************************************/
template <class T>
void Hash<T> :: clear()
{
	// clear the items in the hash
	for (int i = 0; i < data.size(); i++)
	{
		data[i].clear();	
	}

	numItems = 0;
}

/***********************************************************************
* Find function. We are going to use our hash function to find the 
* approximate spot at where the item might be. Loop through the linked
* list, and if we still can't find it, it's not existant.
************************************************************************/
template <class T>
bool Hash<T> :: find(const T & t)
{
	// returns the index of our item
	int index = hash(t);
	bool found = false;

	// loop through the list and try and locate the item
	for (typename std::list<T>::iterator it = data[index].begin();
		it != data[index].end(); it++)
	{
		if (*it == t)
			found = true;
	}

	return found;
}

/************************************************************************
* Insert function. Get the index of where we are going to place the 
* item by using the pure virtual hash function. Then, push item onto
* list, and increment number of Items.
************************************************************************/
template <class T>
void Hash<T> :: insert(const T & t)
{
	// find approximate index of where we find the item.
	int index = hash(t);

	// now put it in the array
	data[index].push_back(t);
	numItems++;
}

/***********************************************************************
* Just a simple little debug function. It shows how many collisions
* are at each spot in our Hash Table.
************************************************************************/
template <class T>
void Hash<T> :: debug()
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i].size() << std::endl;
	}
}