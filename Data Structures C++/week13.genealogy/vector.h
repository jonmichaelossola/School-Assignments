/***********************************************************************
* Header:
*    Container
* Summary:
*    This class contains the notion of a container: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Container         : A class that holds stuff
*        ContainerIterator : An iterator through Container
* Author
*    Br. Helfrich
************************************************************************/

#ifndef CONTAINER_H
#define CONTAINER_H

#include <cassert>

#include <iostream>
using namespace std;

// forward declaration for ContainerIterator
template <class T>
class VectorIterator;

/************************************************
 * CONTAINER
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (cap) delete [] data; }
    
    // Assignment operator overload
    Vector <T> & operator = (const Vector <T> &rhs) throw (const char *);
    
    // Square Bracket operator overload
    T & operator [] (const int index) throw (const char *);

    T & operator [] (const int index) const throw (const char *);
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }
    
    // returns the capacity of the current object
    int capacity() const { return cap; }
    
    // adds an element to the end of the vector and returns nothing
    void push_back(const T & t);
    
   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   // how many items are currently in the container?
   int size() const    { return numItems;              }

   // add an item to the container
   void insert(const T & t) throw (const char *);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int cap;           // how many items can I put on the Container before full?
};

/**************************************************
 * CONTAINER ITERATOR
 * An iterator through Container
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * CONTAINER :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
{
   assert(rhs.cap >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
      cap = numItems = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.cap];
   }
   catch (bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
   this->cap = rhs.cap;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
    try
    {
       for (int i = 0; i < numItems; i++)
         this->data[i] = rhs.data[i];
    }
    catch (char * message)
    {
        cout << message;
    }
        
   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < cap; i++)
      this->data[i] = T();
}

/***************************************************************
 * This is the overloaded brackets operator so that a user can
 * access the data and overwrite it.
 ***************************************************************/
template <class T>
T & Vector <T> :: operator [] (const int index) throw (const char *)
{
    if (index < 0 || index > this->cap)
        throw "Invalid index";
    
    return data[index];
}

/******************************************************************
* Make this the same function, but constant, so that we can use
* different functions to display the data, instead of editing it.
*****************************************************************/
template <class T>
T & Vector <T> :: operator [] (const int index) const throw (const char *)
{
    if (index < 0 || index > this->cap)
        throw "Invalid index";
    
    return data[index];
}

/*********************************************************************
* Assignment operator. Check if the data is already something, in which
* case set it to NULL first, and the rest of the data to zero.
* then copy over everything from the right hand side that is also a vector.
*********************************************************************/
template <class T>
Vector <T> & Vector <T> :: operator =(const Vector <T> &rhs) throw (const char *)
{
  if (this->data != NULL)
  {
    this->numItems = 0;
    this->cap = 0;
    this->data = NULL;
  }

  this->cap = rhs.cap;
  this->numItems = rhs.numItems;

  try
  {
    this->data = new T[rhs.cap];
  }
  catch (bad_alloc)
  {
    throw "ERROR: Unable to allocate buffer";
  }

  for (int i = 0; i < rhs.numItems; i++)
    this->data[i] = rhs.data[i];

  for (int i = numItems; i < cap; i++)
    this->data[i] = T();

  return *this;
}

/*****************************************************************
 * Push back function. Allocate space for the items depending on 
 * what is the current cap and if the number of items equals the cap.
 *****************************************************************/
template <class T>
void Vector <T> :: push_back(const T & t)
{
    T * newData;

    int oldCap = cap;

    if (cap < 1)
    {
        newData = new T[cap = 1];
        data = newData;

        data[numItems++] = t;
        // don't want to add another item in the array if need be.
        // let's go ahead and return from here.
        return;
    }
    else if (numItems == cap)
    {
        newData = new T[cap *= 2];

        for (int i = 0; i < numItems; i++)
        {
            newData[i] = data[i];
        }

        for (int i = numItems; i < cap; i++)
        {
          newData[i] = T();
        }

        data = newData;
    }
    
    data[numItems++] = t;
}

/**********************************************
 * CONTAINER : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->cap = this->numItems = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[capacity];
   }
   catch (bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->cap = capacity;
   this->numItems = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * CONTAINER :: INSERT
 * Insert an item on the end of the container
 **************************************************/
template <class T>
void Vector <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (cap == 0 || cap == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}


#endif // CONTAINER_H

