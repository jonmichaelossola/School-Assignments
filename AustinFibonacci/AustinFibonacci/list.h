/***********************************************************************
 * Header:
 *    List
 * Summary:
 *    This class contains the notion of a list
 *
 *    This will contain the class definition of:
 *        List: A set of nodes
 * Author
 *    Austin Nelson
 ************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <string>      // for STRING
#include "node.h"      // for NODE

// forward declaration
template <class T>
class ListIterator;

template <class T>
class List;

/**************************************************
 * LIST
 * A collection of pointers to the list
 *************************************************/
template <class T>
class List
{
private:
    Node<T> * pHead;
    Node<T> * pLast;
    int numNodes;
public:
    // Default constructor: Empty all the things
    List() : numNodes(0), pHead(NULL), pLast(NULL) {}
    
    // Copy constructor: copy the stuff
    List(List<T> & rhs) throw (const char *);
    
    // Non default constructor: Put something on right away
    List(T t) throw (const char *);
    
    // Destructor: Deletes everything if it hasn't already been deleted
    ~List() { freeData(pHead); }
    
    // Overloaded operator: =
    List<T> & operator = (List<T> & rhs) throw (const char *);
    
    // empty: Sees if there is anything in the List
    bool empty() { return (numNodes == 0 || pHead == NULL); }
    
    // size: Gets the size of the List
    int size() { return numNodes; }
    
    // clear: Clears the contents
    void clear() { numNodes = 0; freeData(pHead); pHead = NULL; pLast = NULL; }
    
    // push_front: Adds an item to the front of the container
    void push_front(const T & t) throw (const char *);
    
    // push_back: Adds an item to the container
    void push_back(const T & t) throw (const char *);
    
    // front: Returns the thing currently at the front of the List
    T & front() throw (const char *);
    
    // back: Returns the thing currently at the bottom of the List
    T & back() throw (const char *);
    
    // insert: Adds a thing to the middle of the list
    ListIterator<T> insert(ListIterator<T> & it, T t) throw (const char *);
    
    // remove: Removes a thing from the middle of the list
    void remove(ListIterator<T> & it) throw (const char *);
    
    // begin: returns an iterater that points to the first element of the list
    ListIterator <T> begin() throw (const char *);
    
    // rbegin: returns an iterater that points to the last element of the list
    ListIterator <T> rbegin() throw (const char *);
    
    // end: returns an iterater that points one past the last element of the list
    ListIterator <T> end() throw (const char *);
    
    // end: returns an iterater that points one past the first element of the list
    ListIterator <T> rend() throw (const char *);
    
};

/**************************************************
 * LIST ITERATOR
 * An iterator through List
 *************************************************/
template <class T>
class ListIterator
{
public:
    // list friends!!
    // friend class List<T>;
    
    // default constructor
    ListIterator() : p(NULL) {}
    
    // initialize to direct p to some item
    ListIterator(Node<T> * p) : p(p) {}
    
    // copy constructor
    ListIterator(const ListIterator & rhs) { *this = rhs; }
    
    // assignment operator
    ListIterator & operator = (const ListIterator & rhs)
    {
        this->p = rhs.p;
        return *this;
    }
    
    // not equals operator
    bool operator != (const ListIterator & rhs) const { return rhs.p != this->p; }
    
    // equals operator (just for fun)
    bool operator == (const ListIterator & rhs) const { return rhs.p == this->p; }
    
    // dereference operator
    T & operator * ()
    {
        return p->data;
    }
    
    // prefix increment
    ListIterator <T> & operator ++ ()
    {
        p = p->pNext;
        return *this;
    }
    
    // postfix increment
    ListIterator <T> operator ++ (int postfix)
    {
        ListIterator tmp(*this);
        p = p->pNext;
        return tmp;
    }
    
    // prefix decrement
    ListIterator <T> & operator -- ()
    {
        p = p->pPrev;
        return *this;
    }
    
    // postfix decrement
    ListIterator <T> operator -- (int postfix)
    {
        ListIterator tmp(*this);
        p = p->pPrev;
        return tmp;
    }
    
    // make friends!
    friend ListIterator <T> List <T> :: insert(ListIterator<T> & it, T t) throw (const char *);
    friend void List <T> :: remove(ListIterator<T> & it) throw (const char *);
    
    
private:
    Node<T> * p;
};

/***********************************************************************
 * Name: List Copy Constructor
 * Data Type: List Template
 * Parameters: The rhs of an object
 * Return: Nothing
 * Purpose: To copy things
 ************************************************************************/
template <class T>
List <T> :: List(List<T> & rhs) throw (const char *)
{
    numNodes = rhs.numNodes;
    Node<T> * newNode;
    try
    {
        newNode = new Node<T>;
    }
    catch (std::bad_alloc)
    {
        throw "Not enough memory";
    }
    if (rhs.pHead == NULL)
    {
        pHead = rhs.pHead;
        pLast = rhs.pLast;
        return;
    }
    else
    {
        pHead = copy(rhs.pHead);
        // loop through to get the end to get the pLast
        newNode = pHead;
        while (newNode->pNext != NULL)
        {
            newNode = newNode->pNext;
        }
        pLast = newNode;
        pHead->pPrev = NULL;
    }
    return;
}
/***********************************************************************
 * Name: List Non Default Constructor
 * Data Type: List Template
 * Parameters: An object
 * Return: Nothing
 * Purpose: To put something on right away
 ************************************************************************/
template <class T>
List<T> :: List(T t) throw (const char *)
{
    Node<T> * newNode;
    try
    {
        newNode = new Node<T>(t);
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: unable to allocate a new buffer for a list";
    }
    pHead = newNode;
    pLast = newNode;
    numNodes++;
    
}

/***********************************************************************
 * Name: Overload operator: =
 * Data Type: List Template
 * Parameters: The rigth hand side of the object
 * Return: the left hand side
 * Purpose: To copy things
 ************************************************************************/
template <class T>
List<T> & List<T> :: operator = (List<T> & rhs) throw (const char *)
{
    
    freeData(this->pHead);
    this->numNodes = rhs.numNodes;
    Node<T> * newNode;
    
    if (rhs.pHead == NULL)
    {
        this->pHead = rhs.pHead;
        this->pLast = rhs.pLast;
    }
    else
    {
        this->pHead = copy(rhs.pHead);
        // loop through to get the end to get the pLast
        newNode = pHead;
        while (newNode->pNext != NULL)
        {
            newNode = newNode->pNext;
        }
        this->pLast = newNode;
        this->pHead->pPrev = NULL;
    }
    // for (ListIterator<T> it = rhs.begin(); it != rhs.end(); it++)
    // {
    //    this->push_back(*it);
    // }
    
    return *this;
}

/***********************************************************************
 * Name: push_front
 * Data Type: void
 * Parameters: A constant thing of List Template type
 * Return: Nothing
 * Purpose: Adds stuff to the front container
 ************************************************************************/
template <class T>
void List <T> :: push_front(const T & t) throw (const char *)
{
    // make the new List to be pushed on
    Node<T> * newNode;
    
    // try allocating
    try
    {
        newNode = new Node<T>(t);
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: unable to allocate a new buffer for a list";
    }
    
    // reasign pointers
    if (pHead == NULL)
    {
        pHead = newNode;
        pLast = newNode;
    }
    else
    {
        pHead->pPrev = newNode;
        newNode->pNext = pHead;
        pHead = newNode;
        newNode->pPrev = NULL;
    }
    
    // increment numbers
    numNodes++;
    return;
}

/***********************************************************************
 * Name: push
 * Data Type: void
 * Parameters: A constant thing of List Template type
 * Return: Nothing
 * Purpose: Adds stuff to the back container
 ************************************************************************/
template <class T>
void List <T> :: push_back(const T & t) throw (const char *)
{
    // make the new List to be pushed on
    Node<T> * newNode;
    
    // try allocating
    try
    {
        newNode = new Node<T>(t);
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: unable to allocate a new List for a list";
    }
    
    // reset the pointers
    if (pHead == NULL)
    {
        pLast = newNode;
        pHead = newNode;
    }
    else
    {
        newNode->pPrev = pLast;
        pLast->pNext = newNode;
        pLast = newNode;
    }
    // increment num lists
    numNodes++;
    return;
}

/***********************************************************************
 * Name: front
 * Data Type: List Template
 * Parameters: None
 * Return: The item at the back of the List
 * Purpose: To get items from the front of the List
 ************************************************************************/
template <class T>
T & List <T> :: front() throw (const char *)
{
    if (numNodes == 0 || pHead == NULL)
    {
        throw "ERROR: unable to access data from an empty list";
    }
    return pHead->data;
}

/***********************************************************************
 * Name: back
 * Data Type: Template
 * Parameters: None
 * Return: The item at the back of the List
 * Purpose: To get items from the back of the List
 ************************************************************************/
template <class T>
T & List <T> :: back() throw (const char *)
{
    if (numNodes == 0 || pHead == NULL)
    {
        throw "ERROR: unable to access data from an empty list";
    }
    return pLast->data;
}

/***********************************************************************
 * Name: insert
 * Data Type: List Iterator Template
 * Parameters: The item to be added and the index to it
 * Return: The list iterator
 * Purpose: to add items to the middle of the list
 ************************************************************************/
template <class T>
ListIterator <T> List <T> :: insert(ListIterator<T> & it, T t) throw (const char *)
{
    // make the new List to be pushed on
    Node<T> * newNode;
    
    // try allocating
    try
    {
        newNode = new Node<T>(t);
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: unable to allocate a new List for a list";
    }
    
    // newNode->pNext = it.p->pNext;
    // newNode->pPrev = it.p;
    // it.p->pNext = newNode;
    // newNode->pNext = newNode->pNext->pPrev;
    
    
    // if inserting in an empty list
    if (pHead == NULL)
    {
        pHead = newNode;
        pLast = newNode;
    }
    // if inserting at the end
    else if (it == end())
    {
        pLast->pNext = newNode;
        newNode->pPrev = pLast;
        pLast = newNode;
    }
    else
    {
        newNode->pNext = it.p;
        newNode->pPrev = it.p->pPrev;
        it.p->pPrev = newNode; // newNode->pPrev->pNext = newNode;
        
        // if inserting at the head
        if (it.p == pHead)
        {
            pHead = newNode;
        }
        // if inserting in the middle
        else
        {
            newNode->pPrev->pNext = newNode;
        }
    }
    
    numNodes++;
    return it;
}

/***********************************************************************
 * Name: remove
 * Data Type: List Iterator Template
 * Parameters: The index to the item to be removed
 * Return: The list iterater
 * Purpose: To remove things from anywhere in the list
 ************************************************************************/
template <class T>
void List <T> :: remove(ListIterator<T> & it) throw (const char *)
{
    numNodes--;
    // test for end
    if (it.p->pNext != NULL && it.p->pPrev != NULL)
    {
        it.p->pPrev->pNext = it.p->pNext;
    }
    else if (it.p->pNext == NULL)
    {
        it.p->pPrev->pNext = NULL;
        pLast = it.p->pPrev;
        delete it.p;
        it.p = NULL;
        return;
    }
    
    // test for head
    if (it.p->pPrev != NULL)
    {
        it.p->pNext->pPrev = it.p->pPrev;
    }
    else
    {
        it.p->pNext->pPrev = NULL;
        pHead = it.p->pNext;
        delete it.p;
        it.p = NULL;
        return;
    }
    
    
    delete it.p;
    it.p = NULL;
    
    return;
}


/***********************************************************************
 * Name: begin
 * Data Type: List Iterator Template
 * Parameters: None
 * Return: the new list iterater pointing to the head
 * Purpose: get the new list iterater pointing to the head
 ************************************************************************/
template <class T>
ListIterator <T> List <T> :: begin() throw (const char *)
{
    ListIterator<T> newListI(pHead);
    
    return newListI;
}

/***********************************************************************
 * Name:
 * Data Type: List Iterator Template
 * Parameters: None
 * Return: the new list iterater pointing to the last thinng in the list
 * Purpose: get the new list iterater pointing to the last thing in the list
 ************************************************************************/
template <class T>
ListIterator <T> List <T> :: rbegin() throw (const char *)
{
    ListIterator<T> newListI(pLast);
    
    return newListI;
}

/***********************************************************************
 * Name: back
 * Data Type: List Iterator Template
 * Parameters: None
 * Return: the new list iterater pointing to the past the end element in the list
 * Purpose: get the new list iterater pointing to the past the end element in the list
 ************************************************************************/
template <class T>
ListIterator <T> List <T> :: end() throw (const char *)
{
    return ListIterator<T>(NULL);
}

/***********************************************************************
 * Name: rend
 * Data Type: List Iterator Template
 * Parameters: None
 * Return: the new list iterater pointing to the past the front element in the list
 * Purpose: get the new list iterater pointing to the past the front element in the list
 ************************************************************************/
template <class T>
ListIterator <T> List <T> :: rend() throw (const char *)
{
    ListIterator<T> newList(NULL);
    
    return newList;
}

#endif // list.h
