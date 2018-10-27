/**********************************************************
 * File: check11b.cpp
 * Author: Br. Burton
 *
 * Purpose: This file tests the Pair class. You should not
 *   need to change it.
 **********************************************************/
#include <iostream>
#include <string>
using namespace std;

#include "pair.h"

int main()
{
   string first;
   cout << "Please enter a first name: ";
   cin >> first;

   string last;
   cout << "Please enter a last name: ";
   cin >> last;

   Pair<string, string> fullName;
   fullName.setFirst(first);
   fullName.setSecond(last);

   cout << "The first name is: " << fullName.getFirst() << endl;
   cout << "The last name is: " << fullName.getSecond() << endl;
   cout << "The complete pair is: ";
   fullName.display();
   cout << endl << endl;


   int num1;
   cout << "Please enter a number: ";
   cin >> num1;

   int num2;
   cout << "Please enter another number: ";
   cin >> num2;

   Pair<int, int> numbers;
   numbers.setFirst(num1);
   numbers.setSecond(num2);

   cout << "The first number is: " << numbers.getFirst() << endl;
   cout << "The second number is: " << numbers.getSecond() << endl;
   cout << "The complete pair is: ";
   numbers.display();
   cout << endl << endl;



   string name;
   cout << "Please enter a name: ";
   cin >> name;

   int score;
   cout << "Please enter a score: ";
   cin >> score;

   Pair<string, int> grade;
   grade.setFirst(name);
   grade.setSecond(score);

   cout << "The name is: " << grade.getFirst() << endl;
   cout << "The score is: " << grade.getSecond() << endl;
   cout << "The complete pair is: ";
   grade.display();
   cout << endl << endl;

   return 0;
}
