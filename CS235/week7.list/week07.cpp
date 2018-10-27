/***********************************************************************
* Program:
*    Week 07, LIST
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the List class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>     // for CIN and COUT
#include <iomanip>      // for SETW
#include <string>       // for the String class
#include <cassert>      // for ASSERT
#include "list.h"       // your List class should be in list.h
#include "fibonacci.h"  // your fibonacci() function
using namespace std;


// prototypes for our four test functions
void testSimple();
void testPush();
void testIterate();
void testInsertRemove();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testPush()
#define TEST3   // for testIterate()
#define TEST4   // for testInsertRemove()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a List\n";
   cout << "\t2. The above plus push items onto the List\n";
   cout << "\t3. The above plus iterate through the List\n";
   cout << "\t4. The above plus insert and remove items from the list\n";
   cout << "\ta. Fibonacci\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         fibonacci();
         break;
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testPush();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testIterate();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testInsertRemove();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a List: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   try
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(5);
   
      // Test 1.a: a bool List with default constructor
      cout << "Create a bool List using the default constructor\n";
      List <bool> l1;
      cout << "\tSize:  " << l1.size()                   << endl;
      cout << "\tEmpty? " << (l1.empty() ? "Yes" : "No") << endl;

      // Test 1.b: double List and add one element
      cout << "Create a double List and add one element: 3.14159\n";
      List <double> l2;
      l2.push_back(3.14159); 
      cout << "\tSize:  " << l2.size()                   << endl;
      cout << "\tEmpty? " << (l2.empty() ? "Yes" : "No") << endl;
      cout << "\tFront: " << l2.front()                  << endl;
      cout << "\tBack:  " << l2.back()                   << endl;
  
      {
         // Test 1.c: copy the double List
         cout << "Copy the double List using the copy-constructor\n";
         List <double> l3(l2);
         cout << "\tSize:  " << l3.size()                   << endl; 
         cout << "\tEmpty? " << (l3.empty() ? "Yes" : "No") << endl;
         cout << "\tFront: " << l3.front()                  << endl;
         cout << "\tBack:  " << l3.back()                   << endl;
      }

      // test 1.d: Copy the List using the assignment operator
      cout << "Copy a double List using the assignment operator\n";
      List <double> l4;
      l4.push_back(1.0); // this node will get destroyed with the =
      l4 = l2;
      cout << "\tSize:  " << l4.size()                   << endl;
      cout << "\tEmpty? " << (l4.empty() ? "Yes" : "No") << endl;
      cout << "\tFront: " << l4.front()                  << endl;
      cout << "\tBack:  " << l4.back()                   << endl;
   }
   catch (const char * error)
   {
      cout << error << endl;
   }
#endif //TEST1
}

/*******************************************
 * TEST PUSH
 * Add a whole bunch of items to the List.  This will
 * test the push_back() and push_front() algorithm
 *****************************************/
void testPush()
{
#ifdef TEST2
   try
   {
      // create
      List <int> l1;
      int size1 = 0;

      // test push_back
      cout << "Enter integer values to put on the back, type 0 when done\n";
      int value;
      do
      {
         if (l1.empty())
            cout << "\t(   ...   ) > ";
         else
            cout << "\t( "
                 << l1.front()
                 << " ... "
                 << l1.back()
                 << " ) > ";
         cin  >> value;
         if (value)
         {
            l1.push_back(value);
            size1++;
         }
      }
      while (value);

      // test copy
      List <int> l2(l1);
      assert(l1.size() == l2.size());
      cout << "Copied l1 into l2\n";

      // modify the front and back of l1 and l2
      if (!l1.empty())
      {
         assert(l1.back()  == l2.back());
         assert(l1.front() == l2.front());
         l1.back()  =  42;
         l1.front() = -42;
      }
      cout << "Modified l1\n";

      // test empty
      l2.clear();
      int size2 = 0;
      cout << "Copied list l2 is "
           << (l2.empty() ? "empty." : "not empty.") << endl;

      // test push_front
      cout << "Enter integer values to put on the front, type 0 when done\n";
      do
      {
         if (l2.empty())
            cout << "\t(   ...   ) > ";
         else
            cout << "\t( "
                 << l2.front()
                 << " ... "
                 << l2.back()
                 << " ) > ";
         cin  >> value;
         if (value)
         {
            l2.push_front(value);
            size2++;
         }
      }
      while (value);

      // make sure the original list is not changed
      assert(l1.size() == size1);
      assert(l2.size() == size2);
      cout << "Sizes of l1 and l2 are correct\n";

      // make sure that l1 was not changed
      if (!l1.empty())
      {
         assert(l1.back()  ==  42);
         assert(l1.front() == -42);
      }
      cout << "The list l1 was unchanged\n";
   }
   catch (const char * error)
   {
      cout << error << endl;
   }
#endif // TEST2   
}

/*****************************************
 * LIST :: DISPLAY
 * Display the contents of the list forwards
 ****************************************/
template <class T>
ostream & operator << (ostream & out, List <T> & rhs)
{
   out << '{';

#ifdef TEST3
   ListIterator <T> it;
   for (it = rhs.begin(); it != rhs.end(); ++it)
      out << "  " << *it;
#endif // TEST3

   out << "  }";

   return out;   
}

/*******************************************
 * TEST ITERATE
 * We will test the iterators. We will go through the
 * list forwards and backwards
 ******************************************/
void testIterate()
{
#ifdef TEST3
   // create
   cout << "Create a string List with the default constructor\n";
   List <string> l;

   // instructions
   cout << "Instructions:\n"
        << "\t+ dog   pushes dog onto the front\n"
        << "\t- cat   pushes cat onto the back\n"
        << "\t#       displays the contents of the list backwards\n"
        << "\t*       clear the list\n"
        << "\t!       quit\n";

   char command;
   string text;
   do
   {
      cout << l << " > ";
      cin  >> command;

      try
      {
         switch (command)
         {
            case '+':
               cin >> text;
               l.push_front(text);
               break;
            case '-':
               cin >> text;
               l.push_back(text);
               break;
            case '#':
               cout << "\tBackwards: {";
               for (ListIterator <string> it = l.rbegin();
                    it != l.rend();
                    --it)
                  cout << "  " << *it;
               cout << "  }\n";
               break;
            case '*':
               l.clear();
               break;
            case '!':
               // do nothing, we will exit out of the loop
               break;
            default:
               cout << "Unknown command\n";
               cin.ignore(256, '\n');
         }      
      }
      catch (const char * e)
      {
         cout << '\t' << e << endl;
      }
   }
   while (command != '!');
#endif // TEST3
}

/*******************************************
 * TEST INSERT REMOVE
 * We will insert items in a list from the location
 * specified by the iterator, and remove items from
 * the list from the given iterator
 *******************************************/
void testInsertRemove()
{
#ifdef TEST4
   // first, fill the list
   List <char> l;
   for (char letter = 'a'; letter <= 'm'; letter++) {
      l.push_back(letter);
   }

   // instructions
   cout << "Instructions:\n"
        << "\t+ 3 A  put 'A' after the 3rd item in the list\n"
        << "\t- 4    remove the fourth item from the list\n"
        << "\t!       quit\n";

   char command;
   do
   {
      ListIterator <char> it;
      int index = 0;
      char letter;
      
      // display the list with indicies in the row above
      cout << ' ';
      for (it = l.begin(); it != l.end(); ++it)
         cout << setw(3) << index++;
      cout << endl;
      cout << l << endl;

      // prompt for the next command
      cout << "> ";
      cin  >> command;

      try
      {
         switch (command)
         {
            case '+':
               cin >> index >> letter;
               it = l.begin();
               while (index-- > 0)
                  ++it;
               l.insert(it, letter);
               break;
            case '-':
               cin >> index;
               it = l.begin();
               while (index-- > 0)
                  ++it;
               l.remove(it);
               break;
            case '!':
               break;
            default:
               cout << "Unknown command\n";
               break;
         }

         // error recovery: unexpected input
         if (cin.fail())
         {
            cin.clear();
            cin.ignore(256, '\n');
         }
         
      }
      // error recovery: thrown exception
      catch (const char * e)
      {
         cout << '\t' << e << endl;
      }
   }
   while (command != '!'); 
#endif // TEST4
}
