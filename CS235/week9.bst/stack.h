/***********************************************************************
 * Module:
 *    Lesson 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement a stack
 ************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <cassert>  // because I am paranoid

/**************************************************
 * STACK
 * First-in-Last-out data structure
 *************************************************/
template <class T>
class Stack
{
public:
   // constructors and destructors
   Stack() : data(NULL), capacity(0), num(0) {                               }
   Stack(int capacity)         throw(const char *);
   Stack(const Stack<T> & rhs) throw(const char *);;
   ~Stack()                                  { if (!empty()) delete [] data; }

   // assignment operator
   Stack <T> & operator = (const Stack <T> & rhs) throw (const char *);
   
   // standard container interfaces
   bool empty() const                        { return num == 0;              }
   int  size () const                        { return num;                   }

   // stack-specific interfaces
   void pop()                  throw(const char *);
   T &  top()                  throw(const char *);
   const T & const_top() const throw(const char *);
   void push(const T & t)      throw(const char *);
  
private:
   void grow(int capacity = 0) throw(const char *);
  
   T * data;             // dynamically allocated data for the stack
   int capacity;         // the size of the data array
   int num;              // the number of items currently used in the array
};

/**********************************************************
 * STACK :: copy constructor
 *********************************************************/
template <class T>
Stack <T> :: Stack (int newCapacity) throw (const char *)
{
   // initially empty
   data = NULL;
   capacity = 0;
   num = 0;

   // allocate the buffer
   assert(newCapacity >= 0);
   grow(newCapacity);     // this could throw
}

/**********************************************************
 * STACK :: copy constructor
 *********************************************************/
template <class T>
Stack <T> :: Stack (const Stack <T> & rhs) throw (const char *)
{
   data = NULL;
   capacity = 0;
   num = 0;
   *this = rhs;
}

/*********************************************************
 * STACK :: assign
 * Copy one stack onto another
 ********************************************************/
template <class T>
Stack<T> & Stack <T> :: operator = (const Stack <T> & rhs) throw (const char *)
{
   assert(rhs.capacity >= 0);
   assert(rhs.num      >= 0);
   assert(rhs.num <= rhs.capacity);

   // delete the old stack if one exists
   if (!empty())
      delete [] data; 
   data = NULL;
   capacity = 0;
   num = 0;

   // do nothing if there is nothing to do
   if (rhs.empty())
      return *this;

   // copy the contents of the right-hand-side
   grow(num = rhs.num);   // this could throw
   for (int i = 0; i < rhs.num; i++)
      data[i] = rhs.data[i];
   
   return *this;
}


/********************************************************
 * STACK :: TOP
 * Returns a reference to the top element in the stack. 
 *******************************************************/
template <class T>
T & Stack <T> :: top() throw(const char *)
{
   // if an element is not present in the stack, throw
   if (empty())
      throw "ERROR: Unable to reference the element from an empty Stack";
   return data[num - 1];
}

/********************************************************
 * STACK :: TOP
 * Returns a reference to the top element in the stack. 
 *******************************************************/
template <class T>
const T & Stack <T> :: const_top() const throw(const char *)
{
   // if an element is not present in the stack, throw
   if (empty())
      throw "ERROR: Unable to reference the element from an empty Stack";
   return data[num - 1];
}

/********************************************************
 * STACK :: POP
 * Removes the element on top of the stack, effectively reducing its size by
 * one.
 *******************************************************/
template <class T>
void Stack <T> :: pop() throw(const char *)
{
   // if an element is not present in the stack, throw
   if (empty())
      throw "ERROR: Unable to pop from an empty Stack";
   num--;
}


/********************************************************
 * STACK :: PUSH
 * Inserts a new element at the top of the stack, above its current
 * top element. The content of this new element is initialized to a
 * copy of t.
 *******************************************************/
template <class T>
void Stack <T> :: push(const T & t) throw(const char *)
{
   // make sure there is room in our stack
   if (num == capacity)
      grow();

   data[num++] = t;
}

/*********************************************************
 * STACK :: GROW
 * Grow the size of the stack to (at a minimum) of a given
 * size.  If the size is set to zero, then the capacity will
 * be doubled.  If the stack is currently not empty, the contents
 * will be copied over to the new buffer
 *********************************************************/
template <class T>
void Stack <T> :: grow(int capacity) throw(const char *)
{
   assert(capacity >= 0);
   assert(num      >= 0);
   
   // determine the new buffer size
   if (capacity == 0)
      capacity = (this->capacity ? this->capacity * 2 : 2);

   // allocate the new buffer
   T * dataNew = new(std::nothrow) T[capacity];
   if (NULL == dataNew)
      throw "ERROR: Unable to allocate a new buffer for Stack";
   this->capacity = capacity;

   // copy the contents of the old buffer over to the new buffer
   assert(num <= capacity);
   if (NULL != data)
      for (int i = 0; i < num; i++)
         dataNew[i] = data[i];

   // free the old
   if (NULL != data)
      delete [] data;
   data = dataNew;
}

#endif // STACK_H
