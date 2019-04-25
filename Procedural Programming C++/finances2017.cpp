#include <iomanip>
#include <iostream>
using namespace std;

int main ()
{

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2); 
   
   cout << "\tItem           Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome" << setw(10) << "$" << setw(10) << "1000.00\n";
   cout << "\tTaxes" << setw(11) << "$" << setw(10) << "100.00\n";    
   cout << "\tTithing" << setw(9) << "$" << setw(10) << "100.00\n";
   cout << "\tLiving" << setw(10) << "$" << setw(10) << "650.00\n";   
   cout << "\tOther" << setw(11) << "$" << setw(10) << "90.00\n";
   cout << "\t=============  ==========\n";
   cout << "\tDelta" << setw(11) << "$" <<setw(10) << "60.00\n";
   return 0;
}
