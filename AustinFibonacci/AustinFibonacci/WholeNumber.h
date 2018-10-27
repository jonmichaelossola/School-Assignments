//
//  WholeNumber.hpp
//  AustinFibonacci
//
//  Created by Jon Michael Ossola on 10/23/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#ifndef WholeNumber_h
#define WholeNumber_h

#include <stdio.h>

#include "list.h"    // for LIST

class WholeNumber
{
private:
    // contains the 3 digit long nodes
    List<unsigned int> total;
    
public:
    
    // Default constructor: Empty all the things
    WholeNumber() {}
    
    // Copy constructor: copy the stuff
    WholeNumber(WholeNumber & rhs) { this->total = rhs.total; }
    
    // Non default constructor: Put something in right away
    WholeNumber(unsigned int add) { total.push_front(add); }
    
    // Destructor: Deletes everything if it hasn't already been deleted
    ~WholeNumber() { total.clear(); }
    
    // Overloaded operator: =
    WholeNumber & operator = (WholeNumber & rhs);
    
    // Overloaded operator: +=
    WholeNumber & operator += (WholeNumber & add) throw (const char *);
    
    // Overloaded operator: << (friend)
    friend std::ostream & operator << (std::ostream & out, WholeNumber & rhs);
    
};


#endif /* WholeNumber_h */
