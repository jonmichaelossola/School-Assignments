/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

#include <iostream>

/******************************************************
 * Class: Money
 * Description: Holds a value of dollars and cents.
 ******************************************************/
class Money
{
private:
   int dollars;
   int cents;

public:
   /************************
    * Constructors
    ************************/
   Money()
   {
      setDollars(0);
      setCents(0);
   }

   Money(int dollars, int cents)
   {
      setDollars(dollars);
      setCents(cents);
   }

   /************************
    * Getters and Setters
    ************************/
   int getDollars() const { return dollars; }
   int getCents() const { return cents; }
   
   // These could be done in a smarter way to add cents to dollars if more than 100 etc.
   // but we're trying to keep it simple for this assignment...
   void setDollars(int dollars) { this->dollars = dollars; }
   void setCents(int cents) { this->cents = cents; }

   /************************
    * Other public methods
    ************************/
   void prompt();
   void display() const;


   /************************
    * Member operators
    ************************/



   // TODO: Put your protoypes here!
   friend Money & operator ++(Money & rhs)
   {
    rhs.setCents(rhs.getCents() + 1.0);
    return rhs;
   }

   // add two Money objects together
   friend Money operator + (const Money &lhs, const Money &rhs)
   {
    return Money(lhs.getDollars() + rhs.getDollars(),
        lhs.getCents() + rhs.getCents());
   } 

   friend Money & operator += (Money &lhs, Money &rhs)
   {
    lhs.setDollars(lhs.getDollars() + rhs.getDollars());
    lhs.setCents(lhs.getCents() + rhs.getCents());
    return lhs;
   }



   /*************************
    * Private helper methods
    *************************/
   void handleOverflow();

};

#endif
