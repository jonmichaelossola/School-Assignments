/***********************************************************************
 * Program
 *    Container Test
 * Summary:
 *    This program is designed to test the Container class as defined
 *    in container.h.  It will illustrate how to include the Container
 *    class, instantiate a Container object, and iterate through a
 *    Container using ContainerIterator.
 * Author:
 *    Br. Helfrich
 *************************************************************************/

#include <iostream>     // for CIN and COUT
#include "vector.h"  // for CONTAINER and CONTAINER_ITERATOR
using namespace std;

/*************************************************
 * MAIN
 * Just a simple driver program
 *************************************************/
int main()
{
   // fill a container with integers
   Vector <int> c1(10 /*capacity*/);
   cout << "Please enter 10 values:\n";
   for (int i = 0; i < 10; i++)
   {
      int value;
      cout << "> ";
      cin  >> value;
      c1.insert(value);
   }

   // display the status:
   cout << "\tsize:   " << c1.size()                   << endl;
   cout << "\tempty?: " << (c1.empty() ? "Yes" : "No") << endl;

   // display the contents
   for (VectorIterator <int> it = c1.begin(); it != c1.end(); ++it)
      cout << "\t" << *it << endl;

   return 0;
}
