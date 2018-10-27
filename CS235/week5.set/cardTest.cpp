#include <iostream>
#include "card.h"

using namespace std;

int main()
{
   Card card;
   cout << "> ";
   cin  >> card;
   cout << "Your card is: " << card << endl;
   return 0;
}
