/***********************************************************************
* Program:
*    Week 06, NODE
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the Node class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>        // for CIN and COUT
#include <iomanip>         // for SETW
#include <string>          // for the String class
#include <fstream>         // for IFSTREAM
#include <iomanip>         // for SETW
#include <cassert>         // for ASSERT
#include "node.h"          // your Node class should be in node.h
#include "sortInsertion.h" // your insertionSort() function
using namespace std;


// prototypes for our four test functions
void testSimple();
void testInsert();
void testLoop();
void testInteractive();
void testInsertionSort();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testInsert()
#define TEST3   // for testLoop()
#define TEST4   // for testInteractive()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a linked list\n";
   cout << "\t2. The above plus insert items onto the linked list\n";
   cout << "\t3. The above plus loop through the linked list\n";
   cout << "\t4. The above plus find items in the linked list\n";
   cout << "\ta. Insertion Sort\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         testInsertionSort();
         break;
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testInsert();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testLoop();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testInteractive();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a Node: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   try
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(1);
   
      // Test 1.a: a bool linked list with default constructor
      cout << "Create a bool linked list\n";
      Node <bool> * n1 = new Node <bool> (true);
      n1->pNext = new Node <bool> (false);
      cout << "\tn1->data:  " << (n1->data ? "true" : "false")    << endl;
      cout << "\tn1->pNext: " << (n1->pNext ? "address" : "NULL") << endl;
      cout << "\tn1->pNext->data:  "
           << (n1->pNext->data ? "true" : "false")     << endl;
      cout << "\tn1->pNext->pNext: "
           << (n1->pNext->pNext ?  "address" : "NULL") << endl;
      freeData(n1);
   
      // Test 1.b: double linked list and add one element
      cout << "Create a double linked list and add two elements: 1.1 2.2\n";
      Node <double> * n2 = new Node <double> (1.1);
      n2->pNext = new Node <double> (2.2);
      cout << "\tn2->data:  " << n2->data                         << endl;
      cout << "\tn2->pNext: " << (n2->pNext ? "address" : "NULL") << endl;
      cout << "\tn2->pNext->data:  "
           << n2->pNext->data                          << endl;
      cout << "\tn2->pNext->pNext: "
           << (n2->pNext->pNext ?  "address" : "NULL") << endl;
   
      // Test 1.c: copy the double List
      cout << "Copy the double linked list\n";
      Node <double> * n3 = copy(n2);
      freeData(n2);
      cout << "\tn3->data:  " << n3->data                         << endl;
      cout << "\tn3->pNext: " << (n3->pNext ? "address" : "NULL") << endl;
      cout << "\tn3->pNext->data:  "
           << n3->pNext->data                          << endl;
      cout << "\tn3->pNext->pNext: "
           << (n3->pNext->pNext ?  "address" : "NULL") << endl;

      // Test 1.d: free up the remaining linked lists
      freeData(n3);
      cout << "Destroying the second and third linked list\n";
   }
   catch (const char * error)
   {
      cout << error << endl;
   }   
#endif //TEST1
}

/*******************************************
 * TEST INSERT
 * Add a whole bunch of items to the linked list.  This will
 * test the insert() algorithm
 *****************************************/
void testInsert()
{
#ifdef TEST2
   try
   {
      // create a list: { 10 }
      cout << "Create an integer linked list and put the number 10 on top\n";
      Node <int> * n = NULL;
      insert(10, n);
      cout << "\tn->data:  " << n->data                         << endl;
      cout << "\tn->pNext: " << (n->pNext ? "address" : "NULL") << endl;

      // add 20: { 10, 20 }
      cout << "Add the number 20 to the back\n";
      insert(20, n);
      cout << "\t{ " << n->data << ", " << n->pNext->data << " }\n";
      if (n->pNext->pNext != NULL)
         cout << "ERROR: the list does not have a NULL\n";

      // add 15,25: { 10, 15, 20, 25 }
      cout << "Add 15 to the middle and 25 to the back\n";
      insert(15, n);
      insert(25, n->pNext->pNext);
      cout << "\t{ " << n->data
           << ", "<< n->pNext->data
           << ", "<< n->pNext->pNext->data
           << ", "<< n->pNext->pNext->pNext->data
           << " }\n";
      if (n->pNext->pNext->pNext->pNext != NULL)
         cout << "ERROR: the list does not have a NULL\n";

      // add 5: { 5, 10, 15, 20, 25 }
      cout << "Add 5 to the head\n";
      insert(5, n, true);
      cout << "\t{ " << n->data
           << ", "<< n->pNext->data
           << ", "<< n->pNext->pNext->data
           << ", "<< n->pNext->pNext->pNext->data
           << ", "<< n->pNext->pNext->pNext->pNext->data
           << " }\n";
      if (n->pNext->pNext->pNext->pNext->pNext != NULL)
         cout << "ERROR: the list does not have a NULL\n";
   
      // free up the list
      freeData(n);
   }
   catch (const char * error)
   {
      cout << error << endl;
   }   
#endif // TEST2   
}

/*******************************************
 * TEST LOOP
 * We will test looping through the linked list
 * including using the display function
 ******************************************/
void testLoop()
{
#ifdef TEST3
   try
   {
      // create
      cout << "Create a char linked list: { a, b, c, d, e, f }\n";
      Node <char> * n = NULL;

      insert('c', n, true);               // { c } 
      insert('d', n);                     // { c, d }
      insert('f', n->pNext);              // { c, d, f }
      insert('b', n, true);               // { b, c, d, f }
      insert('e', n->pNext->pNext);       // { b, c, d, e, f }
      insert('a', n, true);               // { a, b, c, d, e, f }

      cout << "\t{ " << n << " }\n";

      // empty the list and start again
      cout << "Empty the list\n";
      freeData(n);
      cout << "\tThe list is "
           << (n == NULL ? "" : "not ")
           << "empty\n";

      // fill the list again
      cout << "Fill the list now with: { Z, Y, X, W, V, U }\n";

      insert('Y', n, true);                  // { Y }
      insert('Z', n, true);                  // { Z, Y }
      insert('V', n->pNext);                 // { Z, Y, V }
      insert('U', n->pNext->pNext);          // { Z, Y, V, U }
      insert('X', n->pNext);                 // { Z, Y, X, V, U }
      insert('W', n->pNext->pNext);          // { Z, Y, X, W, V, U }

      cout << "\t{ " << n << " }\n";

      // copy the list
      Node <char> * nCopy = copy(n);
      cout << "Copy of the list:\n";
      cout << "\t{ " << nCopy << " }\n";
      freeData(nCopy);
   
      // empty the list
      cout << "Empty the list\n";
      freeData(n);
      cout << "\tThe list is "
           << (n == NULL ? "" : "not ")
           << "empty\n";
   }
   catch (const char * error)
   {
      cout << error << endl;
   }
#endif // TEST3
}

/*********************************************
 * TEST INTERACTIVE
 * Interactively add and find items in the
 * linked-list
 *********************************************/
void testInteractive()
{
#ifdef TEST4
   // create
   cout << "Create a string linked list\n";
   Node <string> * n = NULL;

   // instructions
   cout << "Instructions:\n"
        << "\t+ dog 4  inserts dog onto the 4th slot, 0 begin the head\n"
        << "\t? cat    determines if cat is in the list\n"
        << "\t*        clear the list\n"
        << "\t!        quit\n";

   char command;         // prompt user input for a command
   int slot;             // prompt for a slot to insert into the linked-list
   string text;          // prompt for text to insert or find
   Node <string> * p;    // loop variable through the list
   int i;                // loop variable through the slots

   do
   {
      // prompt
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      cout << "{ " << n << " } > ";
      cin  >> command;

      try
      {
         switch (command)
         {
            case '+':
               // prompt
               cin >> text >> slot;
               
               // empty list or head of the list case
               if (slot == 0 || n == NULL)
                  insert(text, n, true);
               else
               // otherwise find the slot
               {
                  for (i = 1,      p = n;
                       i < slot && p->pNext;
                       i++,        p = p->pNext)
                     ;
               
                  insert(text, p);
               }
               break;
            case '?':
               // prompt
               cin >> text;

               // find the node
               p = find(n, text);

               // display the results
               cout << "\tThe text was "
                    << (p == NULL ? "not " : "")
                    << "found\n";
               break;
            case '*': // delete if we are asked to
            case '!': // delete if we are to quit
               // delete everything
               freeData(n);
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
#endif // TEST4
}

#define NUM_COLUMNS   8
#define INDENT        2
#define WIDTH_COLUMN ((80 - INDENT) / NUM_COLUMNS)

/***********************************************
 * DISPLAY
 * Display the contents of the list
 **********************************************/
template <class T>
void display(T array[], int num)
{
   // loop through the entire list
   for (int i = 0; i < num; i++)
   {
      // display the leading indnet
      if (i % NUM_COLUMNS == 0)
         cout << setw(INDENT) << "";

      // display the item
      cout << setw(WIDTH_COLUMN)
           << array[i];

      // display the trailing newline character
      if (i % NUM_COLUMNS == (NUM_COLUMNS - 1) || i == num - 1)
         cout << endl;
   }
}

/************************************************
 * TEST INSERTION SORT
 * The interactive function allowing the user to
 * test the insertionSort() function
 ***********************************************/
void testInsertionSort()
{
   //
   // first, sort an array of floats
   //

   float array1[] = { 3.6, 8.1, 4.5, 5.4, 7.2, 1.8, 6.3, 2.7, 0.9, 9.0 };
   int   num1 = sizeof(array1) / sizeof(array1[0]);
   cout << "An array of " << num1 << " numbers\n";

   // display unsorted
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);
   cout << "Unsorted:\n";
   display(array1, num1);

   // sort the list
   sortInsertion(array1, num1);

   // display sorted
   cout << "Sorted:\n";
   display(array1, sizeof(array1) / sizeof(array1[0]));

   //
   // next, sort an array of strings
   //

   string array2[100];
   int    num2 = sizeof(array2) / sizeof(array2[0]);
   ifstream fin("/home/cs235/week06/words.txt");
   assert(!fin.fail());
   for (int i = 0; i < num2; i++)
   {
      fin >> array2[i];
      assert(!fin.fail());
   }
   fin.close();
   cout << "\nAn array of " << num2 << " words\n";

   // display unsorted
   cout << "Unsorted:\n";
   display(array2, num2);

   // sort the list
   sortInsertion(array2, num2);

   // display sorted
   cout << "Sorted:\n";
   display(array2, sizeof(array2) / sizeof(array2[0]));
}

