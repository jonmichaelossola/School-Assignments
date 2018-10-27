/***********************************************************************
* Program:
*    Week 04, DEQUE
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the Deque class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>     // for CIN and COUT
#include <string>       // for the String class
#include <cassert>      // for ASSERT
#include "deque.h"      // your Deque class should be in deque.h
#include "nowServing.h" // your nowServing() function
using namespace std;


// prototypes for our four test functions
void testSimple();
void testPushPopFront();
void testWrapping();
void testErrors();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testPushPopFront()
#define TEST3   // for testWrapping()
#define TEST4   // for testErrors()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a Deque\n";
   cout << "\t2. The above plus push, pop, top\n";
   cout << "\t3. The above plus test implementation of wrapping\n";
   cout << "\t4. The above plus exercise the error Deque\n";
   cout << "\ta. Now Serving\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         nowServing();
         break;
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testPushPopFront();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testWrapping();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testErrors();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a Deque: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   try
   {
      // Test 1.a: bool Deque with default constructor
      cout << "Create a bool Deque using default constructor\n";
      Deque <bool> d1;
      cout << "\tSize:     " << d1.size()                   << endl;
      cout << "\tCapacity: " << d1.capacity()               << endl;
      cout << "\tEmpty?    " << (d1.empty() ? "Yes" : "No") << endl;

      // Test 1.b: double Deque with non-default constructor
      cout << "Create a double Deque using the non-default constructor\n";
      Deque <double> d2(10 /*capacity*/);
      cout << "\tSize:     " << d2.size()                   << endl;
      cout << "\tCapacity: " << d2.capacity()               << endl;
      cout << "\tEmpty?    " << (d2.empty() ? "Yes" : "No") << endl;

      // Test 1.c: copy the Deque using the copy constructor
      {
         cout << "Create a double Deque using the copy constructor\n";
         Deque <double> d3(d2);
         cout << "\tSize:     " << d3.size()                   << endl;
         cout << "\tCapacity: " << d3.capacity()               << endl;
         cout << "\tEmpty?    " << (d3.empty() ? "Yes" : "No") << endl;
      }

      // Test 1.d: copy the Deque using the assignment operator
      cout << "Copy a double Deque using the assignment operator\n";
      Deque <double> d4(2);
      d4 = d2;
      cout << "\tSize:     " << d4.size()                   << endl;
      cout << "\tCapacity: " << d4.capacity()               << endl;
      cout << "\tEmpty?    " << (d4.empty() ? "Yes" : "No") << endl;
   }
   catch (const char * error)
   {
      cout << error << endl;
   }
   
#endif //TEST1
}

#ifdef TEST2
/******************************************
 * DISPLAY
 * Display the contents of the deque
 ******************************************/
template <class T>
ostream & operator << (ostream & out, Deque <T> d)
{

   out << "{ ";
   while (!d.empty())
   {
      out << d.front() << ' ';
      d.pop_front();
   }
   out << '}';

   return out;
}
#endif // TEST2


/*******************************************
 * TEST PUSH POP FRONT
 * Add a whole bunch of items to the Deque.  This will
 * test the Deque growing algorithm
 *****************************************/
void testPushPopFront()
{
#ifdef TEST2
   try
   {
      // create
      Deque <int> d1;

      // fill
      cout << "Enter integer values, type 0 when done\n";
      int value;
      do
      {
         cout << "\t" << d1 << " > ";
         cin  >> value;
         if (value)
            d1.push_back(value);
      }
      while (value);

      // display how big it is
      cout << "\tSize:     " << d1.size()                   << endl;
      cout << "\tEmpty?    " << (d1.empty() ? "Yes" : "No") << endl;
      cout << "\tCapacity: " << d1.capacity()               << endl;

      // make a copy of it using the assignment operator and copy constructor
      Deque <int> d2(2);
      d2 = d1;
      Deque <int> d3(d1);

      // destroy the old copy
      d1.clear();

      // display the two copies
      cout << "\td1 = " << d1 << endl;
      cout << "\td2 = " << d2 << endl;
      cout << "\td3 = " << d3 << endl;
   }
   catch (const char * error)
   {
      cout << error << endl;
   }   
#endif // TEST2   
}

/*******************************************
 * TEST WRAPPING
 * We will test pop_front(), pop_back(),
 * push_front(), and push_back() to make
 * sure the Deque looks the way we expect
 * it to look.
 ******************************************/
void testWrapping()
{
#ifdef TEST3
   // create
   Deque <string> d(4);

   // instructions
   cout << "instructions:\n"
        << "\t+f dog   pushes dog onto the front\n"
        << "\t+b cat   pushes cat onto the back\n"
        << "\t-f       pops off the front\n"
        << "\t-b       pops off the back\n"
        << "\t*        clear the deque\n"
        << "\t?        shows the statistics of the deque\n"
        << "\t!        quit\n";

   string command;
   string text;
   do
   {
      cout << d << " > ";
      cin  >> command;

      try
      {
         if (command == "+f")
         {
            cin >> text;
            d.push_front(text);
         }
         else if (command == "+b")
         {
            cin >> text;
            d.push_back(text);
         }
         else if (command == "-f")
         {
            cout << "\tpop: " << d.front() << endl;
            d.pop_front();
         }
         else if (command == "-b")
         {
            cout << "\tpop: " << d.back() << endl;
            d.pop_back();
         }
         else if (command == "?")
         {
            cout << "\tSize:     " << d.size()     << endl;
            cout << "\tCapacity: " << d.capacity() << endl;
         }
         else if (command == "*")
         {
            d.clear();
         }
         else if (command != "!")
         {
            cout << "Unknown command\n";
            cin.ignore(256, '\n');
         }      
      }
      catch (const char * e)
      {
         cout << '\t' << e << endl;
      }
   }
   while (command != "!");
#endif // TEST3
}

/*******************************************
 * TEST ERRORS
 * Numerous error conditions will be tested
 * here, including bogus popping and the such
 *******************************************/
void testErrors()
{
#ifdef TEST4
   // create
   Deque <char> d;

   // test using front() with an empty deque
   try
   {
      d.front();
      cout << "BUG! We should not be able to front() with an empty deque!\n";
   }
   catch (const char * error)
   {
      cout << "\tDeque::front() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }

   // test using back() with an empty deque
   try
   {
      d.back();
      cout << "BUG! We should not be able to back() with an empty deque!\n";
   }
   catch (const char * error)
   {
      cout << "\tDeque::back() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }

   // test using pop_front() with an empty deque
   try
   {
      d.pop_front();
      cout << "BUG! We should not be able to pop_front() "
           << "with an empty deque!\n";
   }
   catch (const char * error)
   {
      cout << "\tDeque::pop_front() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }      

   // test using pop_back() with an empty deque
   try
   {
      d.pop_back();
      cout << "BUG! We should not be able to pop_back() "
           << "with an empty deque!\n";
   }
   catch (const char * error)
   {
      cout << "\tDeque::pop_back() error message correctly caught.\n"
           << "\t\"" << error << "\"\n";
   }      

#endif // TEST4
}
