/***********************************************************************
 * Header:
 *    DOLLARS
 * Summary:
 *    This file contains the notion of money
 * Author
 *    Br. Helfrich
 ************************************************************************/

#ifndef DOLLARS_H
#define DOLLARS_H

#include <iostream>  // for OSTREAM and ISTREAM

/******************************************
 * DOLLARS
 * This class behaves like a number except it handles
 * input and output for money different.
 * The following inputs are the same for example:
 *   -4 -4.0 (4.00) -$4.00 $-4
 ******************************************/
class Dollars
{
  public:
   // constructors
  Dollars()                        : cents(0)     {                        }
  Dollars(int cents)               : cents(cents) {                        }
  Dollars(double dollars)          : cents(0)     { *this = dollars;       }
  Dollars(const Dollars & dollars) : cents(0)     { *this = dollars;       }

   // operators
   Dollars & operator = (double dollars)
   {
      cents = (int)(dollars * 100.0);
      return *this;
   }
   Dollars & operator = (int dollars)
   {
      *this = (double)dollars;
      return *this;
   }
   Dollars & operator = (const Dollars & dollars)
   {
      cents = dollars.cents;
      return *this;
   }
   Dollars operator - (const Dollars & rhs) const
   {
      return Dollars(cents - rhs.cents);
   }
   Dollars operator * (int value) const
   {
      return Dollars(cents * value);
   }
   Dollars operator * (double value) const
   {
      return Dollars((int)((double)cents * value));
   }
   Dollars operator + (const Dollars & rhs) const
   {
      return Dollars(cents + rhs.cents);
   }
   Dollars & operator += (const Dollars & rhs)
   {
      return *this = *this + rhs;
   }
   bool operator == (const Dollars & rhs) const
   {
      return this->cents == rhs.cents;
   }
   bool operator != (const Dollars & rhs) const
   {
      return !(*this == rhs);
   }
   bool operator > (const Dollars & rhs) const
   {
      return this->cents > rhs.cents;
   }
   bool operator >= (const Dollars & rhs) const
   {
      return *this > rhs || *this == rhs;
   }
   bool operator < (const Dollars & rhs) const
   {
      return !(*this >= rhs);
   }
   bool operator <= (const Dollars & rhs) const
   {
      return !(*this > rhs);
   }      

   // input and output
   friend std::ostream & operator << (std::ostream & out, const Dollars & rhs);
   friend std::istream & operator >> (std::istream & in,        Dollars & rhs);

  private:
   int cents;  // more accurate than floating point numbers; no errors!
};

#endif // DOLLARS_H
