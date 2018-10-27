/***********************************************************************
* Source File:
*    Implementation of the Card class.
* Summary: 
*    This file will implement all the methods described in card.h
* Author:
*    Br. Helfrich
************************************************************************/

#include <iostream>       // for IFSTREAM and OFSTREAM
#include <cassert>        // because I am paranoid
#include <string>         
#include <cstring>       // for STRCMP
#include "card.h"         // for the class definition
using namespace std;

/**************************************
 * CARD NAMES
 * The name on each card
 **************************************/
const char * CARD_NAMES[] =
{
   "-INVALID-", // 0
   "AngleFish", // 1
   "Cod",       // 2
   "Crab",      // 3
   "Dolphin",   // 4
   "SeaHorse",  // 5
   "Shark",     // 6
};

/*****************************
 * Insertion  cout << x;
 * RETURN:    ostream by reference   (so we can say (cout << x) << y;)
 * PARAMETER: ostream by reference   (we do not want a copy of cout)
 *            constant by reference  (we do not want to make a copy or change)
 *****************************/
ostream & operator << (ostream & out, const Card & card)
{
   // we better be one of the valid cards...
   assert(card.validate());

   // display the friendly name of the card
   out << CARD_NAMES[card.value];

   // return the output stream
   return out;
}

/*****************************
 * Extraction    cin >> x;
 * RETURN:    istream by reference  (so we can say (cin >> x) >> y;)
 * PARAMETER: istream by reference  (we do not want a copy of cin)
 *            by reference          (no copies but we do want to change this) 
 *****************************/
istream & operator >> (istream & in, Card & card)
{
   // input comes in the form of a string
   string input;
   in >> input;

   // do the actual work
   card = input.c_str();
   assert(card.validate());

   // return the input stream
   return in;
}

/*************************************
 * ASSIGNMENT
 * RETURN:    *this by reference
 * PARAMETER: a constant Card
 * METHOD:    not const
 *************************************/
Card & Card :: operator = (const Card & rhs)
{
   assert(rhs.validate());
   value = rhs.value;
   return *this;
}

/*************************************
 * ASSIGNMENT
 * RETURN:    *this by reference
 * PARAMETER: a constant string representing the card
 * METHOD:    not const
 *************************************/
Card & Card :: operator = (const char * rhs)
{
   // initially we don't know the value
   value = INVALID;
   for (int i = INDEX_FIRST; value == INVALID && i <= INDEX_LAST; i++)
      if (strcmp(rhs, CARD_NAMES[i]) == 0)
         value = i;

   assert(validate());
   return *this;
}

/*****************************
 * VALIDATE
 *****************************/
bool Card :: validate() const
{
   return (value == INVALID ||
       (value >= INDEX_FIRST && value <= INDEX_LAST));
}

