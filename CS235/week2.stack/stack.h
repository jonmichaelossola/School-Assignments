#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
    int myCapacity;
    int myTop;
    T * myArray;
public:
    Stack();
    Stack(int capacity);
    Stack(const Stack <T> &rhs) throw (const char *);
    ~Stack() { delete [] myArray; }
    Stack <T> & operator = (const Stack <T> &rhs) throw (const char *);
    bool empty() { return  (myTop == 0); }
    int size()  { return myTop; }
    int capacity() { return myCapacity; }
    void clear() { myTop = 0; }
    void pop() throw (const char *);
    void push(const T &t) throw (const char *);
    T top() throw (const char *);
};

/************************************************************
 * Default constructor: We don't really know the size of the
 * capacity, so we will just take a guess and expand the array
 * if need be.
 **************************************************************/
template <class T>
Stack <T> :: Stack()
{
    // we aren't really sure how large they want the capacity. Let's say 100?
    myCapacity = 0;
    myTop = 0;

    myArray = new T[myCapacity];

    for (int i = myTop; i < myCapacity - 1; i++)
        myArray[i] = T();
}

/**********************************************************
 * Non default constructor: the user passes in the parameter
 * deciding how big the stack will be. Use that number to
 * declare a dynamically allocated array.
 **********************************************************/
template <class T>
Stack <T> :: Stack(int capacity)
{
    myCapacity = capacity;
    myTop = 0;

    // allocate space for a new array
    myArray = new T[myCapacity];

    // Let's fill up the rest of the values with the default C++ values.
    for (int i = myTop; i < myCapacity - 1; i++)
        myArray[i] = T();
}

/****************************************************************
 * Copy Constructor. Checks if the capacity of rhs is zero, and if
 * so, basically make everything 0 or NULL. Else, copy everything
 * from the right hand side into this.
 *****************************************************************/
template <class T>
Stack <T> :: Stack (const Stack <T> &rhs) throw (const char *)
{
    assert(rhs.myCapacity >= 0);

    // do nothing if there is nothing to do
    if (rhs.myCapacity == 0)
    {
        this->myCapacity = 0;
        this->myTop = 0;
        this->myArray = NULL;
        return;
    }

    // copy over the capacity and size
    this->myCapacity = rhs.myCapacity;
    this->myTop = rhs.myTop;

    // attempt to allocate
    try
    {
        this->myArray = new T[rhs.myCapacity];
    }
    catch (bad_alloc)
    {
        throw "ERROR: Unable to allocate buffer";
    }

    // copy the items over one at a time using the assignment operator
    try
    {
        for (int i = 0; i < myTop; i++)
            this->myArray[i] = rhs.myArray[i];
    }
    catch (const char * message)
    {
        cout << message << endl;
    }

    // the rest needs to be filled with the default value for T
    for (int i = myTop; i < myCapacity - 1; i++)
           this->myArray[i] = T();
}

/***************************************************************
 * Assignment operator overload. Set the variables of this to
 * everything on the right hand side and return *this. Also, make
 * sure that the parameters in the function are const.
 ***************************************************************/
template <class T>
Stack <T> & Stack <T> :: operator = (const Stack <T> & rhs) throw (const char *)
{
    assert(rhs.myTop >= -1 && rhs.myTop <= rhs.myCapacity);

    assert(rhs.myCapacity >= 0);

    // just a fail safe, if the data we are using in the current object
    // has data, delete it and make data into NULL so we aren't leaking memory.
    if (this->myArray != NULL)
    {
        delete [] this->myArray;
        this->myArray = NULL;
    }

    this->myCapacity = rhs.myCapacity;
    this->myTop = rhs.myTop;

    try
    {
        this->myArray = new T[rhs.myCapacity];
    }
    catch (bad_alloc)
    {
        throw "Error: Unable to allocate a new buffer for Vector";
    }

    // set the current objects data equal to the data in the rhs vector object
    if (this->myTop > -1)
    {
       for (int i = 0; i <= rhs.myTop; i++)
           this->myArray[i] = rhs.myArray[i];
    }
    // fill in the rest of the values for default T value.
    if (this->myTop > -1)
    {
       for (int i = rhs.myTop; i < rhs.myCapacity - 1; i++)
           this->myArray[i] = T();
    }

    return *this;
}

/**************************************************************
 * The push method. If the capacity is zero, allocate a dynamic
 * array for one item. If the top is equal to the capacity, 
 * allocate space for a dynamic array twice the size of the original.
 **************************************************************/
template <class T>
void Stack <T> :: push(const T &t) throw (const char *)
{
    int oldCapacity = myCapacity;

    T * newData;

    if (myCapacity == 0)
    {

        try
        {
            newData = new T[myCapacity = 1];
        }
        catch (bad_alloc)
        {
            throw "Error: unable to allocate a new buffer for Stack";
        }

        myArray = newData;

        myArray[myTop++] = t; 
        return;
    }

    if (myTop >= myCapacity - 1)
    {

        // If we go outside the bounds of our dynamically allocated
        // array, let's double the size of it
        try 
        {
            myCapacity *= 2;
            newData = new T[myCapacity];
        }
        catch (bad_alloc) 
        {
            throw "Error: unable to allocate a new buffer for Stack";
        }

        for (int i = 0; i < oldCapacity; i++)
        {
            newData[i] = myArray[i]; 
        }

        for (int i = myTop; i < myCapacity - 1; i++)
            newData[i] = T();

        myArray = newData;

        myArray[myTop++] = t;

        return;
    }
    // If we don't need to allocate new memory, add the item to the end
    myArray[myTop++] = t;
}

/*****************************************************************
 * This is the pop method. If the stack is not empty, it pops the
 * top, or moves the top member variable down, therefore making
 * the top variable the new top variable.
 ******************************************************************/
template <class T>
void Stack <T> :: pop() throw (const char *)
{
    if (!empty())
        myTop--;
    else
        throw "ERROR: Unable to pop from an empty Stack";
}

/*************************************************************
 * Return the top item of the array. Unless the array is empty,
 * in which case there is nothing really to return. In that
 * case, let's throw an error and go on with life.
 *************************************************************/
template <class T>
T Stack <T> :: top() throw (const char *)
{
    if (empty())
        throw "ERROR: Unable to reference the element from an empty Stack";
    else 
        return myArray[myTop - 1];
}

#endif // STACK_H