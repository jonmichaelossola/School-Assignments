/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Jon Michael Ossola
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;

/*********************************************************************************
* Display function. if the buying Queue is not currently empty, then display
* the currently held shares. Same goes for the selling Queue. And finally, 
* display the proceeds. Pass in the Queues by value so that we don't mess them up.
*********************************************************************************/
void Portfolio :: display(Queue<Portfolio> qBuy, Queue<Portfolio> qSell)
{
	if (!qBuy.empty())
		cout << "Currently held:\n";
	while (!qBuy.empty())
	{
		cout << "\tBought " << qBuy.front().shares << " shares at "; 
		cout << qBuy.front().cost << endl;
		qBuy.pop();
	}

	// the proceeds variable for later on. It's going to keep track of all our profits.
	Dollars proceeds;

	if (!qSell.empty())
		cout << "Sell History:\n";
	while (!qSell.empty())
	{
		cout << "\tSold " << qSell.front().shares; 
		cout << " shares at " << qSell.front().cost;
		cout << " for a profit of " << qSell.front().profit << endl;

		// let's count the profits we made.
		proceeds = proceeds + qSell.front().profit;

		// and then let's pop the items off of our selling queue.
		qSell.pop();
	}


	cout << "Proceeds: " << proceeds << endl;
}

/**********************************************************************************
* Buy function. Pretty cut and dry. Make a new portfolio, and set the contents
* of it equal to the values entered in by the user and passed in as parameters.
* Use the push method of the Queue class to push in the new portfolio object.
**********************************************************************************/
void Portfolio :: buy(const int &newShares, 
	const Dollars &newCost, Queue<Portfolio> &qBuy)
{
	Portfolio newPort;

	newPort.shares = newShares;
	newPort.cost = newCost;

	qBuy.push(newPort);
}

/*********************************************************************************
* Sell function. Pass in the parameters. if the shares sold is greater than the
* first item on the buy queue, pop off an item in the buy queue. Calculate profit.
* If the new share is smaller, subtract it from buy queue's top and push it on sell queue.
*********************************************************************************/
void Portfolio :: sell(int numSoldShares, const Dollars &costSoldShares, 
	Queue<Portfolio> &qSell, Queue<Portfolio> &qBuy)
{
	if (numSoldShares > qBuy.front().shares)
	{
		while (numSoldShares > qBuy.front().shares)
		{
			// declarea a new portfolio and load the parameters onto it.
		  Portfolio tempPort;
		  tempPort.shares = numSoldShares;
		  tempPort.cost = costSoldShares;

		  // set profit to the following algarithm
		  tempPort.profit = (tempPort.cost - qBuy.front().cost) * qBuy.front().shares;
		  tempPort.shares = qBuy.front().shares;
		  numSoldShares -= qBuy.front().shares;

		  // push the temporary portfolio on the stack.
		  qSell.push(tempPort);
		  // since there's no shares left, pop off the first item in the buy queue
		  qBuy.pop();
		}
	}
	if (numSoldShares <= qBuy.front().shares)
	{
		// Make a new portfolio object and initialize its variables
		Portfolio newPort;
		newPort.shares = numSoldShares;
		newPort.cost = costSoldShares;
		newPort.profit = (newPort.cost - qBuy.front().cost) * numSoldShares;

		// subtract the amount of shares remaining from the buy queue
		qBuy.front().shares -= numSoldShares;
		// push it now onto the sell queue
		qSell.push(newPort);

		// if the top of buy queue still has some shares, don't pop it off
		if (qBuy.front().shares == 0)
			qBuy.pop();
	}
}

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";
   
   string option;
   int shares;
   Dollars cost;

   Queue<Portfolio> qBuy;
   Queue<Portfolio> qSell;
   Portfolio myPortfolio;

   do
   {
   	cout << "> ";
   	cin >> option;

   	switch (option[0])
   	{
   		case 'd': case 'D':
   		myPortfolio.display(qBuy, qSell);
   		break;
   		case 's': case 'S':
   		cin >> shares >> cost;
   		myPortfolio.sell(shares, cost, qSell, qBuy);
   		break;
   		case 'b' : case 'B' :
   		cin >> shares >> cost;
   		myPortfolio.buy(shares, cost, qBuy);
   		break;
   		case 'q' :
   		break;
   	}
   } while (option[0] != 'q');

}


