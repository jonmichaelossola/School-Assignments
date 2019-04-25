#include <iostream>
#include "circle.h"

using namespace std;

/***********************************************************
 * Function: Main
 * Prompts for a circle and displays it. 
 ***********************************************************/
int main()
{
   Circle circle;

   circle.promptForCircle();

   cout << "Your circle is:\n";
   circle.display();

   cout << "\n\n";

   // Test a getter
   // This comes for free with the is-a relationship
   // You need to create it for the has-a relationship
   cout << "The x-coordinate of your circle is: " << circle.getX() << endl;

   return 0;
}


