/***********************************************************************
* Header File
*    This is the header file for a "Go Fish" card
* Summary: 
*     Playing cards for the children's version of Go Fish
* Author:
*    Br. Helfrich
************************************************************************/

#ifndef CARD_H
#define CARD_H

#include <iostream>       // for IFSTREAM and OFSTREAM
#include <cassert>        // for ASSERT in the constructors

#define INDEX_FIRST 1
#define INDEX_LAST  6
#define INVALID     0

/*****************************************
 * CARD
 * Card class for the children's version
 * of Go Fish. The text of the cards is
 * described at the top of card.cpp
 *****************************************/
class Card
{
  public:
   // various constructors
   Card()                  : value(INVALID)   { assert(validate()); }
   Card(const Card & rhs)  : value(rhs.value) { assert(validate()); }
   Card(const char * rhs)  : value(INVALID)   { *this = rhs;        }

   bool isInvalid() const { return value == INVALID; }

   // insertion and extraction operators
   friend std::ostream & operator << (std::ostream & out, const Card & card);
   friend std::istream & operator >> (std::istream & in,        Card & card);
   
   // assignment
   Card & operator = (const Card & rhs);     // copy one card to another
   Card & operator = (const char * rhs);     // assign the string to the card
   
   // Absolute and relative comparision... comparing cards
   bool operator == (const Card & rhs) const { return value == rhs.value; }
   bool operator != (const Card & rhs) const { return value != rhs.value; }
   bool operator >= (const Card & rhs) const { return value >= rhs.value; }
   bool operator >  (const Card & rhs) const { return value >  rhs.value; }
   bool operator <= (const Card & rhs) const { return value <= rhs.value; }
   bool operator <  (const Card & rhs) const { return value <  rhs.value; }
   
   
  private:
   // holds the value.  Though there are 256 possible, only 52 are used
   unsigned char value;                // internal representation

   // private functions
   bool validate() const;              // are we in a valid state?
};

#endif // CARD_H
