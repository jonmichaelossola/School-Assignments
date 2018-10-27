/***********************************************************************
 * Module:
 *    Week 08, Pair
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement a pair: two values
 ************************************************************************/

#ifndef PAIR_H
#define PAIR_H

#include <iostream>  // for ISTREAM and OSTREAM

/**********************************************
 * PAIR
 * This class couples together a pair of values, which may be of
 * different types (T1 and T2). The individual values can be
 * accessed through its public members first and second.
 *
 * Additionally, when compairing two pairs, only T1 is compared. This
 * is a key in a name-value pair.
 ***********************************************/
template <class T1, class T2>
class Pair
{
public:
   // constructors
  Pair() : first(), second() {}
   Pair(const T1 & first, const T2 & second) : first(first), second(second) {}
   Pair(const Pair <T1, T2> & rhs) : first(rhs.first), second(rhs.second) {}

   // copy the values
   Pair <T1, T2> & operator = (const Pair <T1, T2> & rhs)
   {
      first  = rhs.first;
      second = rhs.second;
      return *this;
   }

   // constant fetchers
   const T1 & getFirst()  const { return first;  }
   const T2 & getSecond() const { return second; }
   
   // compare Pairs.  Only first will be compared!
   bool operator >  (const Pair & rhs) const { return first >  rhs.first; }
   bool operator >= (const Pair & rhs) const { return first >= rhs.first; }
   bool operator <  (const Pair & rhs) const { return first <  rhs.first; }
   bool operator <= (const Pair & rhs) const { return first <= rhs.first; }
   bool operator == (const Pair & rhs) const { return first == rhs.first; }
   bool operator != (const Pair & rhs) const { return first != rhs.first; }
   
   // these are public.  We cannot validate!
   T1 first;
   T2 second;
};

/*****************************************************
 * PAIR INSERTION
 * Display a pair for debug purposes
 ****************************************************/
template <class T1, class T2>
inline std::ostream & operator << (std::ostream & out, const Pair <T1, T2> & rhs)
{
   out << '(' << rhs.first << ", " << rhs.second << ')';
   return out;
}

/*****************************************************
 * PAIR EXTRACTION
 * input a pair
 ****************************************************/
template <class T1, class T2>
inline std::istream & operator >> (std::istream & in, Pair <T1, T2> & rhs)
{
   in >> rhs.first >> rhs.second;
   return in;
}

#endif // PAIR_H
