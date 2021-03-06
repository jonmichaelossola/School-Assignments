#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <iostream>
using namespace std;

/**********************************************************
* This is our Deque class. Declare all of our private 
* variables and our functions that we will be using.
*********************************************************/
template <class T>
class Deque
{
private:
    int myFront;
    int myBack;
    int cap;
    int numItems;
    T * data;

    // don't want the user to call on this function. 
    // solution: let's make it a private function! :)
    void realloc() throw (const char *);

public:
    // default constructor
    Deque() : myBack(0), cap(0), myFront(0), numItems(0), data(NULL) {}

    // non - default constructor passing with index
    Deque(int capacity) throw (const char *);

    // copy constructor
    Deque(const Deque <T> & rhs) throw (const char *);

    // Destructor for the class
    ~Deque() { delete [] data; }

    // assignment operator overload
    Deque <T> & operator = (const Deque <T> & rhs) throw (const char *);

    // size function, return the number of Items.
    int size() const { return numItems; }

    // capacity function, return the capacity.
    int capacity() const { return cap; }

    // pop function, removes an item from head of queue.
    void pop_front() throw (const char *);

    // pop back function, removes item at the back of the queue.
    void pop_back() throw (const char *);

    // returns the item currently in the back of the queue.
    T &back() const throw (const char *);

    // returns the item currently at the front of the queue.
    T &front() const throw (const char *);

    // Adds an item to the queue.
    void push_front(const T &item);

    // adds item to the back of the deque
    void push_back(const T &item);

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
Deque <T> :: Deque(int capacity) throw (const char *)
{
    cap = capacity;
    myBack = 0;
    myFront = 0;
    numItems = 0;

    // allocate memory
    try {
        data = new T[cap];
    }
    catch (bad_alloc) {
        throw "ERROR: Unable to allocate a new buffer for queue";
    }
}


/******************************************************
* Copy constructor. Set everything the same to the
* right hand side, and then allocate space for a new
* array. Copy over the items from the right hand side.
********************************************************/
template <class T>
Deque <T> :: Deque(const Deque <T> & rhs) throw (const char *)
{
    this->cap = rhs.cap;
    this->myFront = 0;
    this->myBack = rhs.numItems;
    this->numItems = rhs.numItems;

    try {
        this->data = new T[cap];
    }
    catch (bad_alloc) {
        throw "ERROR: Unable to allocate a new buffer for Queue";
    }

    // put the rhs items into our object
    int f = rhs.myFront;
    for (int i = 0; i != rhs.numItems; i++) {
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
T &Deque <T> :: back() const throw (const char *)
{
    if (empty())
        throw "ERROR: unable to access data from an empty deque";
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
T &Deque <T> :: front() const throw (const char *)
{
    if (empty())
        throw "ERROR: unable to access data from an empty deque";
    else
        return data[myFront];
}

/********************************************************
* The assignment operator. if data already was something,
* delete it all. Next, set everything to the right
* hand side and copy over all the other items.
*********************************************************/
template <class T>
Deque <T> & Deque <T> :: operator = (const Deque <T> &rhs) throw (const char *)
{
    // we don't want this to be the same as rhs.
    assert(this != &rhs);

    // if data is something beforehand, delete it!
    if (this->data != NULL) {
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
    try {
        this->data = new T[cap];
    }
    catch (bad_alloc) {
        throw "ERROR: Unable to allocate a new buffer for Queue";
    }

    // copy over the items
    int f = rhs.myFront;
    for (int i = 0; i != rhs.numItems; i++) {
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
void Deque <T> :: pop_front() throw (const char *)
{
    if ( !empty() ) {
        numItems--;
        myFront = (myFront + 1) % cap;
    }
    else
        throw "ERROR: unable to pop from the front of empty deque";
}

/******************************************************
 * Pop back function. Instead of popping items off of 
 * the front, let's pop them off of the back! We do this
 * by decrementing back and wrapping it if it is zero.
 ******************************************************/
template <class T>
void Deque <T> :: pop_back() throw (const char *)
{
    if ( !empty() ) {
        numItems--;
        if (myBack == 0)
            myBack = cap - 1;
        else
            myBack--;
    } else
        throw "ERROR: unable to pop from the back of empty deque";
}

/*****************************************************************
* We need to push an item onto the queue. if the capacity is zero,
* allocate a new array with one space. If the number of items is
* equal to the capacity, allocate more space. Else just put the item on.
*****************************************************************/
template <class T>
void Deque <T> :: push_back(const T &item)
{
    if (numItems == cap) {
        realloc();
    }

    // set the item into the bottom spot
    data[myBack] = item;

    // set back to next item in array, increment numItems.
    myBack = (myBack + 1) % cap;
    numItems++;
}

/******************************************************
 * Push front function. Push the item onto the front
 * of the array, allocate space where needed. Copy the
 * items where needed.
 ******************************************************/
template <class T>
void Deque <T> ::push_front(const T &item)
{
    if (numItems == cap) {
        realloc();
    }

    // wrapping for days!
    if (myFront == 0)
        myFront = cap - 1;
    else
        --myFront;

    data[myFront] = item;
    numItems++;
}

/********************************************************
* This function will reallocate our data. If the capacity
* is zero, create an array one long, or if the number of
* items is equal to the capacity, double it and copy items.
*********************************************************/
template <class T>
void Deque <T> :: realloc() throw (const char *)
{
    if (cap == 0) {
        try {
            data = new T[cap = 1];
        }
        catch (bad_alloc) {
            throw "ERROR: Unable to allocate a new buffer for deque";
        }
    }
    if (numItems == cap) {
        T * tempData;
        try {
            tempData = new T[cap * 2];
        }
        catch (bad_alloc) {
            throw "ERROR: Unable to allocate a new buffer for deque";
        }

        // copy over the items
        int j = myFront;
        for (int i = 0; i < numItems; i++, j = (j+1) % cap) {
            tempData[i] = data[j];
        }

        // don't want any leaking data!
        delete [] data;
        data = tempData;

        // adjust the variables
        myFront = 0;
        myBack = numItems;
        cap *= 2;
    }

}

/******************************************************
* Clear function. This is pretty simple, we don't need
* to deallocate anything. Just set the top, bottom and
* number of items to zero.
******************************************************/
template <class T>
void Deque <T> :: clear()
{
    myFront = 0;
    myBack = 0;
    numItems = 0;
}


#endif // QUEUE_H