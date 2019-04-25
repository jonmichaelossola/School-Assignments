/***********************************************************************
* Program:
*    Week 01, Vector
*    Brother XXX, CS 235
* Author:
*    Br. Helfrich
*    Modified by Br. Ercanbrack - Removed extra credit test.
* Summary: 
*    This is a driver program to exercise the Vector class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>       // for CIN and COUT
#include <string>         // because testIterate() uses a Vector of string
#include "vector.h"       // your Vector class needs to be in vector.h
using namespace std;

// prototypes for our four test functions
void testSimple();
void testFill();
void testIterate();
void testCopy();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testFill()
#define TEST3   // for testIterate()
#define TEST4   // for testCopy()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a Vector.\n";
   cout << "\t2. The above plus fill the Vector.\n";
   cout << "\t3. The above plus iterate through the Vector.\n";
   cout << "\t4. The above plus copy the Vector.\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testFill();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testIterate();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testCopy();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }
   
   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a vector: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   try
   {
      // Test 1.a: bool Vector with default constructor
      cout << "Create a bool Vector using default constructor\n";
      Vector <bool> v1;
      cout << "\tSize:     " << v1.size()                   << endl;
      cout << "\tCapacity: " << v1.capacity()               << endl;
      cout << "\tEmpty?    " << (v1.empty() ? "Yes" : "No") << endl;

      // Test 1.b: double Vector with non-default constructor
      cout << "Create a double Vector using the non-default constructor\n";
      Vector <double> v2(10 /*capacity*/);
      cout << "\tSize:     " << v2.size()                   << endl;
      cout << "\tCapacity: " << v2.capacity()               << endl;
      cout << "\tEmpty?    " << (v2.empty() ? "Yes" : "No") << endl;

      // Test 1.c: copy the Vector using the copy constructor
      {
         cout << "Create a double Vector using the copy constructor\n";
         Vector <double> v3(v2);
         cout << "\tSize:     " << v3.size()                   << endl;
         cout << "\tCapacity: " << v3.capacity()               << endl;
         cout << "\tEmpty?    " << (v3.empty() ? "Yes" : "No") << endl;
      }

      // Test 1.d: copy the Vector using the assignment operator
      cout << "Copy a double Vector using the assignment operator\n";
      Vector <double> v4(2);
      v4 = v2;
      cout << "\tSize:     " << v4.size()                   << endl;
      cout << "\tCapacity: " << v4.capacity()               << endl;
      cout << "\tEmpty?    " << (v4.empty() ? "Yes" : "No") << endl;      
   }
   catch (const char * sError)
   {
      cout << sError << endl;
   }   
#endif // TEST1
}

#ifdef TEST2

/*****************************************
 * DISPLAY
 * Display the contents of a vector
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const Vector <T> & rhs)
{
   // If the body of this FOR loop fails to compile due to the [] operator,
   // then you got to make sure that operator[] has a const method
   // as well as a non-const method. There must be two! That
   // will guarentee that it does not change "this". Note that "rhs" is
   // a const parameter...
   out << "{ ";
   for (int i = 0; i < rhs.size(); i++)
      out << rhs[i] << ' ';  
   out << '}';

   return out;
}
#endif // TEST2

/******************************************
 * TEST FILL
 * This will test the following:
 *   1. Instantiating a Vector object
 *   2. Filling the contents with values
 *   3. Destroying an object when finished
 ******************************************/
void testFill()
{
#ifdef TEST2
   try
   {
      // Test1: integer Vector with default constructor
      {
         // create 
         Vector <int> v1(3);

         cout << "Enter numbers, type 0 when done\n";
         int number;
         do
         {
            cout << "\t" << v1 << " > ";
            cin  >> number;
            if (number)
               v1.push_back(number);
         }
         while (number);
         cout << "\tSize:     " << v1.size()                   << endl;
         cout << "\tCapacity: " << v1.capacity()               << endl;
         cout << "\tEmpty?    " << (v1.empty() ? "Yes" : "No") << endl;
      }
      cout << "First vector deleted\n";

      // Test2: character Vector with non-default constructor
      {
         Vector <char> v2(2);

         cout << "Insert user-provided characters in the Vector\n";
         cout << "Enter characters, type 'q' when done\n";
         char letter;
         do
         {
            cout << "\t" << v2 << " > ";
            cin  >> letter;
            if (letter != 'q')
               v2.push_back(letter);
         }
         while (letter != 'q');
         cout << "\tSize:  " << v2.size() << endl;

         // clear the contents
         cout << "\tNow we will clear the contents\n";
         v2.clear();
         cout << "\tSize:     " << v2.size()                   << endl;
         cout << "\tCapacity: " << v2.capacity()               << endl;
         cout << "\tEmpty?    " << (v2.empty() ? "Yes" : "No") << endl;
      }
      cout << "\tSecond Vector deleted\n";
   }
   catch (const char * sError)
   {
      cout << sError << endl;
   }
#endif // TEST2
}

/******************************************
 * TEST ITERATE
 * This will test the following:
 *   1. Instantiating a Vector object
 *   2. Filling the contents with values
 *   3. Displaying the values using an iterator
 *   4. Destroying an object when finished
 ******************************************/
void testIterate()
{
#ifdef TEST3
   try
   {
      // create a vector
      Vector <string> v;

      // fill the container with text
      cout << "Enter text, type \"quit\" when done\n";
      string text;
      do
      {
         cout << "\t" << v << " > ";
         cin  >> text;
         if (text != "quit")
            v.push_back(text);
      }
      while (text != "quit");

      // display the contents of the Container
      cout << "Which item would you like to look up?\n";
      VectorIterator <string> it;
      int i = 0;
      for (it = v.begin(); it != v.end(); ++it)
         cout << "  " << i++ << "\t" << *it << endl;

      // find a given item
      int index;
      cout << "\t> ";
      cin  >> index;

      // prompt for a new value
      cout << "The old value is \""
           << v[index]
           << "\". What is the new value?\n";
      cout << "\t> ";
      cin  >> text;

      // the [] must be read & write. This means it must return by-reference
      v[index] = text;
      cout << "\t" << v << endl;
   }
   catch (const char * sError)
   {
      cout << sError << endl;
   }
#endif // TEST3
}

/**********************************************
 * TEST COPY
 * This will test the following:
 *    1. Instantiate a Vector object using non-default constructor
 *    2. Fill the contents with values
 *    3. Copy one Vector with the values of another
 *    4. Display the contents of the copied Vector with an iterator
 **********************************************/
void testCopy()
{
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);

#ifdef TEST4
   try
   {
      // create a vector
      Vector <float> v1;

      // fill the vector with a couple items that will be overwritten later
      v1.push_back(-0.1);  
      v1.push_back(-0.1);

      // fill the vector with numbers
      {
         Vector <float> vTemp;
         cout << "Enter numbers, type 0.0 when done\n";
         float number;
         do
         {
            cout << "\t> ";
            cin  >> number;
            if (number != 0.0)
               vTemp.push_back(number);
         }
         while (number != 0.0);

         // use the assignment operator
         cout << "Copy vTemp into v1\n";
         v1 = vTemp;
         cout << "vTemp = " << vTemp << endl;
         cout << "v1    = " << v1    << endl;

         // fill in the values for vTemp, not influencing v1 hopefully
         cout << "Now vTemp is overwritten with -1.0\n";
         for (int i = 0; i < vTemp.size(); i++)
            vTemp[i] = 0.1;
         cout << "vTemp = " << vTemp << endl;
         cout << "v1    = " << v1    << endl;
      } // vTemp is destroyed
      
      // copy the container
      Vector <float> v2(v1);

      // destroy the old values in v1
      VectorIterator <float> it;
      for (it = v1.begin(); it != v1.end(); ++it)
         *it = 0.2;

      // display the contents
      cout << "v1 is set to 0.2 while v2 should be the same\n";
      cout << "v1    = " << v1 << endl;
      cout << "v2    = " << v2 << endl;
   }
   catch (const char * sError)
   {
      cout << sError << endl;
   }
#endif // TEST4
}

