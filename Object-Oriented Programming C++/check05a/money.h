/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

public:
	int setDollars(const int dollars);
	int setCents(const int cents);
	int getCents() const { return cents; }
	int getDollars() const { return dollars; }
   void prompt();
   void display() const;
};

#endif
