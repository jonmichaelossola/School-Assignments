/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   float realNumber;
   float imaginaryNumber;
};

// TODO: Add your prompt function here
void prompt(Complex & x)
{
   cout << "Real: ";
   cin >> x.realNumber;
   cout << "Imaginary: ";
   cin >> x.imaginaryNumber;
}

// TODO: Add your display function here
void display(Complex & sum)
{
   cout << sum.realNumber;
   cout << " + ";
   cout << sum.imaginaryNumber;
   cout << "i";
}

/*********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y, Complex & sum)
{
   // TODO: Fill in the body of the add function
   int number;
   sum.realNumber = x.realNumber + y.realNumber;
   sum.imaginaryNumber = x.imaginaryNumber + y.imaginaryNumber;
   return sum;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex x;
   Complex y;
   
   // Call your prompt function twice to fill in c1, and c2 
   prompt(x);
   prompt(y);
   
   // Declare another Complex for the sum
   Complex sum;
   
   // Call the addComplex function, putting the result in sum;
   sum = addComplex(x, y, sum);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
   
   return 0;
}


