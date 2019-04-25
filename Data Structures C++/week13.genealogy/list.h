#ifndef List_H
#define List_H

#include "node.h"
#include <cassert>

template <class T>
class ListIterator;

/**********************************************************************
* List class definition. Includes many many different functions, from
* three different insert functions to constructors, to clear, and a 
* few more to help with our List Iterator.
***********************************************************************/
template <class T>
class List 
{
private:
	// does this need to be private/public? need class template?
	Node <T>* pHead; 
	Node <T>* pTail;
	int numNodes;
public:
	// default constructor
	List() : pHead(NULL), pTail(NULL), numNodes(0) {}

	// copy constructor
	List(const List<T> &rhs) throw (const char *);

	// destructor
	~List() { clear(); }

	// assignment operator overloader
	List & operator = (const List<T> &rhs) throw (const char *);

	// empty checker
	bool empty() const						{return (pHead == NULL);    }

	// size function, returns number of nodes in List
	int size()                          { return numNodes;               }

	// clear function
	void clear();

	// push back function, pushes data to back of linked List.
	void push_back(const T &item) throw (const char *);

	// push front function, pushes data to front of linked List.
	void push_front(const T &item) throw (const char *);

	// returns item at the front by reference.
	T & front() throw (const char *) { return pHead->data; }

	// returns item at the back of the List.
	T & back() throw (const char *) { return pTail->data;    }

	// insert function.
	ListIterator<T> insert(ListIterator<T> &afterMe, T item) throw (const char *);

	// find item in the List and remove it
	void remove(ListIterator<T> &it) throw (const char *);

	// returns ListIterator to first item in List
	ListIterator<T> begin();

	// returns ListIterator to last item in the List
	ListIterator<T> rbegin();

	// returns ListIterator referring to the past-the-end element in List.
	ListIterator<T> end();

	// returns iterator referring to the past-the-front element in List.
	ListIterator<T> rend();

	int getNumNodes() const { return numNodes; }
};

/**********************************************************************
* List Iterator class. This is very helpful when working with iterating
* through the array, whether that be frontwards or backwards. Let's also
* make our data public for later on use. So much easier that way.
***********************************************************************/
template <class T>
class ListIterator
{
public:
		// default constructor
	ListIterator() : myNodes(NULL) {}

	// initialize to direct p to some item
	ListIterator(Node<T> * p) : myNodes(p) {}

	// not equals operator
	bool operator != (const ListIterator<T> &rhs) const
	{
		return (rhs.myNodes != this->myNodes);
	}

	bool operator == (const ListIterator<T> &rhs) const
	{
		return (rhs.myNodes == this->myNodes);
	}

	// dereference operator
	T & operator * ()
	{
		if (myNodes != NULL)
		   return myNodes->data;
	}

	// postfix increment
	ListIterator <T> & operator ++ ()
	{
		if (myNodes == NULL);
		else
		   myNodes = myNodes->pNext;
		return *this;
	}

	// postfix increment
	ListIterator <T> operator ++ (int postfix)
	{
		ListIterator tmp(*this);
		if (myNodes == NULL);
		else 
		   myNodes = myNodes->pNext;
		return tmp;
	}

	// prefix decrement
	ListIterator<T> & operator -- ()
	{
		myNodes = myNodes->pPrevious;
		return *this;
	}

	// postfix decrement
	ListIterator<T> operator -- (int postfix)
	{
		ListIterator tmp(*this);
		if (myNodes == NULL);
		else 
		   myNodes = myNodes->pPrevious;
		return tmp;
	}

	friend ListIterator<T> List<T> :: insert(ListIterator<T> &afterMe, T item) throw (const char *);
	friend void List<T> :: remove(ListIterator<T> &it) throw (const char *);

	// We are going to need you for fibonacci and display functions.
	bool isNextNull()
	{
		if (myNodes->pNext == NULL)
			return true;
		else 
			return false;
	}

	// Same for this. We need this for fibonacci.
	bool isPreviousNull()
	{
		if (myNodes->pPrevious == NULL)
			return true;
		else
			return false;
	}

private:
	// has-a relationship. We now have access to Node functions.
	Node<T> * myNodes;
};

/**********************************************************************
* Copy constructor. Let's simply copy over all the items from one
* side to the other, also using our resources, like the node's copy
* function, and then making the previous pointers and end pointer.
***********************************************************************/
template <class T>
List<T> :: List(const List<T> &rhs) throw (const char *)
{
	if (rhs.pHead == NULL)
	{
		this->pHead = NULL;
		this->pTail = NULL;
		this->numNodes = 0;
		return;
	}

	this->numNodes = rhs.numNodes;
	this->pHead = copy(rhs.pHead);

	for (Node <T> * p = this->pHead; p; p = p->pNext)
	{
		if (p->pNext == NULL)
			pTail = p;
		else
			p->pNext->pPrevious = p;
	}
}

/**********************************************************************
* Assignment operator overload. We need to take all of the things from
* the right hand side, and copy them over into the left hand side. But 
* first, let's delete everything from the left hand side first. Because
* we don't really like leaking data.
***********************************************************************/
template <class T>
List<T> & List<T> :: operator = (const List<T> &rhs) throw (const char *)
{
	assert(this != &rhs);

	if (this->pHead != NULL)
	{
		// don't want any leaking data.
		clear();
	}

	this->numNodes = rhs.numNodes;
	this->pHead = copy(rhs.pHead);

	for (Node <T> * p = this->pHead; p; p = p->pNext)
	{
		if (p->pNext == NULL)
			pTail = p;
		else
			p->pNext->pPrevious = p;
	}

	return *this;
}

/**********************************************************************
* Push back function. We need to think of a few specifics with this one,
* including where are we pushing, into an empty list or no. Then adjust
* the pointers of our new node and change others so that this is new tail.
***********************************************************************/
template <class T>
void List<T> :: push_back(const T &item) throw (const char *)
{
	Node <T> * p = new Node<T>(item);

	if (empty())
	{
		p->pNext = NULL;
		p->pPrevious = NULL;
		pHead = p;
		pTail = p;
		numNodes++;
	}
	else
	{
		p->pPrevious = pTail;
		p->pNext = NULL;
		pTail->pNext = p;
		pTail = p;
		numNodes++;
	}
}

/***********************************************************************
* This is a simple push front function. We need to push an item onto
* the front of the array. We simply need to account for the case that
* if the list is empty.
***********************************************************************/
template <class T>
void List<T> :: push_front(const T &item) throw (const char *)
{
	Node<T> * p = new Node<T>(item);

	if (empty())
	{
		p->pNext = NULL;
		p->pPrevious = NULL;
		pHead = p;
		pTail = p;
		numNodes++;
	}
	else
	{
		p->pPrevious = NULL;
		p->pNext = pHead;
		pHead->pPrevious = p;
		pHead = p;
		numNodes++;
	}
}

/***********************************************************************
* Our insert function. This is where things can get a little hairy.
* We need to deal with a few seperate cases where we might be inserting, 
* but we need to adjust the pointers of our node and of the previous 
* and of the following nodes.
***********************************************************************/
template <class T>
ListIterator<T> List<T> :: insert(ListIterator<T> &afterMe, T item) throw (const char *)
{
	Node <T> * p = new Node<T>(item);

	if (numNodes == 0)
	{
		pTail = p;
		pHead = p;
		numNodes++;
	}
	else if (afterMe.myNodes == NULL && numNodes != 0)
	{
		p->pPrevious = pTail;
		pTail->pNext = p;
		pTail = p;
		numNodes++;
	}
	else if (afterMe.myNodes == pHead && numNodes > 0)
	{
		p->pNext = pHead;
		afterMe.myNodes->pPrevious = p;
		pHead = p;
		numNodes++;
	}
	else if (afterMe.myNodes != pHead && afterMe.myNodes != NULL) 
	{
		// insert into the middle of the list
		p->pNext = afterMe.myNodes;
		p->pPrevious = afterMe.myNodes->pPrevious;
		afterMe.myNodes->pPrevious->pNext = p;
		afterMe.myNodes->pPrevious = p;
		numNodes++;
	}

	ListIterator <T> myIter(p);
	return myIter;
}

/***********************************************************************
* This is our remove function. We need to think of a few cases, for
* example in case we are removing from the head, tail, or in between, 
* or in the case that this is the only remaining node.
***********************************************************************/
template <class T>
void List<T> :: remove(ListIterator<T> &it) throw (const char *)
{
	if (it.myNodes == NULL)
		throw "Unable to remove from an invalid location in a list";
	
	if (numNodes == 1)
	{
		pHead = NULL;
		pTail = NULL;
		delete it.myNodes;
		numNodes--;
	}
	else if (it.myNodes == pHead && numNodes > 1)
	{
		it.myNodes->pNext->pPrevious = NULL;
		pHead = it.myNodes->pNext;
		delete it.myNodes;
		numNodes--;
	}
	else if (it.myNodes == pTail && numNodes > 1)
	{
		it.myNodes->pPrevious->pNext = NULL;
		pTail = it.myNodes->pPrevious;
		delete it.myNodes;
		numNodes--;
	}
	else if (it.myNodes != pHead && it.myNodes != pTail)
	{
		it.myNodes->pPrevious->pNext = it.myNodes->pNext;
		it.myNodes->pNext->pPrevious = it.myNodes->pPrevious;
		delete it.myNodes;
		numNodes--;
	}
}

/***********************************************************************
* Our last List iterator. We need to set the data to the head of our class
* data. We do this via the non default constructor. We store that into 
* a temporary object, and return that list iterator object.
***********************************************************************/
template <class T>
ListIterator<T> List<T> :: begin()
{
	ListIterator<T> myIter(this->pHead);
	return myIter;
}

/**********************************************************************
* This is the reverse begin of the list iterator. We are going to assign
* the nodes of the iterator to the tail pointer we have, and then return
* an object with the data intialized to that tail.
***********************************************************************/
template <class T>
ListIterator<T> List<T> :: rbegin()
{
	ListIterator<T> myIter(this->pTail);
	return myIter;
}

/***********************************************************************
* This is the literal end of the list iterator class. We need to create
* a temporary list iterator, store NULL via its non default constructor,
* and then return that iterator.
***********************************************************************/
template <class T>
ListIterator<T> List<T> :: end()
{
	ListIterator<T> myIter(NULL);
	return myIter;
}

/***********************************************************************
* Reverse figurative end of the array. What we need to do is, create
* a temporary list iterator object, use the non default constructor
* to set nodes to NULL, and then return that object.
***********************************************************************/
template <class T>
ListIterator<T> List<T> :: rend()
{
	ListIterator<T> myIter(NULL);
	return myIter;
}

/***********************************************************************
* Clear function. We are going to use the leapfrog technique 
* to delete data and set all of the other data to NULL or to zero.
* This should all only be done, if the function is not empty.
***********************************************************************/
template <class T>
void List<T> :: clear()
{
	if (!empty())
	{
		Node<T> * p = pHead;
		Node<T> * next;

		while (p != NULL)
		{
			next = p->pNext;
			delete p;
			p = next;
		}
	}
	pHead = NULL;
	pTail = NULL;
	numNodes = 0;
}



#endif // List_H