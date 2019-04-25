/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <string>
#include <iostream>    // for ISTREAM and OSTREAM

// the interactive stock buy/sell function
void stocksBuySell();

class Portfolio
{
public:
	Portfolio() : shares(0), cost(Dollars()), profit(Dollars()) { }

	int shares;

	Dollars cost;

	Dollars profit;

	void display(Queue<Portfolio> qBuy, Queue<Portfolio> qSell);

	void buy(const int &newShares, const Dollars &newCost,
	 Queue<Portfolio> &qBuy);

	void sell(int newShares, const Dollars &newCost,
	 Queue<Portfolio> &qSell, Queue<Portfolio> &qBuy);
};

#endif // STOCK_H

