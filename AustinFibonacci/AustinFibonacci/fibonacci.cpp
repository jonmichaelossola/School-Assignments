//
//  fibonacci.cpp
//  AustinFibonacci
//
//  Created by Jon Michael Ossola on 10/23/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include "fibonacci.h"
#include "WholeNumber.h" // for list and WholeNumber
#include <iostream>
using namespace std;

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci() throw (const char *)
{
    // show the first serveral Fibonacci numbers
    int number;
//    cout << "How many Fibonacci numbers would you like to see? ";
//    cin  >> number;
//
//    // your code to display the first <number> Fibonacci numbers
//    int f1 = 0;
//    int f2 = 1;
//    int ft = 1;
//    if (number > 1)
//    {
//        for (int i = 0; i < number; ++i)
//        {
//            ft = f1 + f2;
//            f1 = f2;
//            f2 = ft;
//            cout << "\t" << f1 << endl;
//        }
//    }
    
            
    // prompt for a single large Fibonacci
    cout << "Which Fibonacci number would you like to display? ";
    cin  >> number;
    
    // your code to display the <number>th Fibonacci number
    // get the new pointers so it is fast
    WholeNumber * fib1;
    WholeNumber * fib2;
    WholeNumber * temp;
    try
    {
        fib1 = new WholeNumber(0);
        fib2 = new WholeNumber(1);
        temp = new WholeNumber(1);
    }
    catch (bad_alloc)
    {
        throw "Not enough memory";
    }
    
    // do the math
    for (int i = 0; i < number - 1; ++i)
    {
        *temp = *fib1;
        *temp += *fib2;
        *fib1 = *fib2;
        *fib2 = *temp;
        cout << *fib2;
    }

    // free memory
    delete fib1;
    delete fib2;
    delete temp;
}
