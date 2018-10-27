/***********************************************************************
* Program:
*    Assignment 13, CS124          (e.g. Assignment 10, Hello World)
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    My program can convert the degree of Celcius to Farenheit.
*    
*    
*    
*    
*
*    Estimated:  1.0 hrs   
*    Actual:     0.45 hrs
*      For me, the most difficult part of this was figuring out the right code how to make the farenheit into celsius.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The function of my code can convert celsius degrees into farenheit
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);
   // float is farenheit;
   float f;
   cout << "Please enter Fahrenheit degrees: ";
   cin >> f; 

   float c = 5.0 / 9.0 * (f - 32.0); // this is the math equation which computes the farenheit into celsius
   
   cout << "Celsius: " << c << endl;
   
   return 0;
}
