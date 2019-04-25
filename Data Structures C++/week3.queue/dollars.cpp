/***********************************************************************
 * Program:
 *    DOLLARS
 * Summary:
 *    This file contains the notion of money
 * Author
 *    Br. Helfrich
 ************************************************************************/

#include <iostream>  // for OSTREAM and ISTREAM
#include <cassert>   // for ASSERT
#include "dollars.h" // for the class definition
using namespace std;

/********************************************
 * DOLLARS READ
 * This function reads dollars from the input stream:
 *     - skips leading white spaces
 *     - skips leading $ signs
 *     - only consumes two decimal places
 *     - negative values work with () or -
 * For example:
 *   $1.34     -->  134 cents
 *   -1.2      --> -120 cents
 *  $(4.211)   --> -421 cents
 *   -6        --> -600 cents
 *******************************************/
istream & operator >> (istream & in, Dollars & rhs)
{
   // initially zero
   rhs.cents = 0;
   if (in.fail())
      return in;

   // skip leading spaces and dollar signs;
   while (isspace(in.peek()) || in.peek() == '$')
      in.get();

   // is the next character a negative?
   bool negative = false;
   while ('-' == in.peek() || '(' == in.peek())
   {
      negative = true;
      in.get();
   }

   // consume digits, assuming they are dollars
   while (isdigit(in.peek()))
      rhs.cents = rhs.cents * 10 + (in.get() - '0');

   // everything up to here was dollars so multiply by 100
   rhs.cents *= 100;

   // did we get a decimal
   if ('.' == in.peek())
   {
      // consume the decimal
      in.get();

      // next digit is in the 10cent place if it exists
      if (isdigit(in.peek()))
         rhs.cents += (in.get() - '0') * 10;
      // the final digit is the 1cent place if it exists
      if (isdigit(in.peek()))
         rhs.cents += (in.get() - '0');
   }

   // take care of the negative stuff
   rhs.cents *= (negative ? -1 : 1);

   // see if there is a trailing )
   if (')' == in.peek())
      in.get();

   return in;
}

/*******************************************
 * DOLLARS DISPLAY
 * This function displays dollars on the screen
 *     - All dollars are preceeded with $
 *     - Negative amounts have () rather than -
 *     - Exactly two decimal places are always shown
 * For example:
 *   124 cents   --> $1.24
 *   300 cents   --> $3.00
 *  -498 cents   --> $(4.98)
 ******************************************/
ostream & operator << (ostream & out, const Dollars & rhs)
{
   // units
   out << '$';
   int cents = rhs.cents;

   // negative?
   if (rhs.cents < 0)
   {
      out << '(';
      cents *= -1;
   }
   assert(cents >= 0);

   // dollars
   out << cents / 100;

   // cents
   out << '.'
       << (cents % 100 < 10 ? "0" : "")
       << cents % 100;

   // negative?
   if (rhs.cents < 0)
      out << ')';

   return out;
}

