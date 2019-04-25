/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   Stack<char> stack;
   string postfix = " ";

  for (int i = 0; i < infix.length(); i++)
  {
     try
     {
        switch (infix[i])
        {
         // don't put a break statement between + and - because we want
         // the same action for both of them.
           case '+':
           case '-':
           // If the stack isn't empty, and if the top isn't the opening 
           // bracket, print and delete all the stack items.
           if (!stack.empty() && stack.top() != '(')
           {
            while (!stack.empty())
            {
               postfix += ' ';
               postfix += stack.top();
               stack.pop();
            }
           }
           // push the + or - onto the stack and put after operator 
           stack.push(infix[i]);
           postfix += ' ';
           break;
           case '*':
           case '%':
           case '/':
           // if the stack isn't empty and the top value of the stack is
           // the ^ character, copy items to stack and then pop them.
           if (!stack.empty() && (stack.top() == '^'))
           {
            while (!stack.empty())
            {
               postfix += ' ';
               postfix += stack.top();
               stack.pop();
            }
           }
           stack.push(infix[i]);
           postfix += ' ';
           break;
           case '^':
           // highest order of operations apart from parenthasis, so 
           // let's push that onto the stack
           stack.push(infix[i]);
           postfix += ' ';
           break;
           case ' ':
           break;
           case '(':
           // just push it onto the stack and we will deal with it later
           stack.push(infix[i]);
           break;
           case ')':
           // print of all the operators until we find the opening parenthases
           while (stack.top() != '(')
           {
            postfix += ' ';
            postfix += stack.top();
            stack.pop();
           }
           // pop the opening parenthases and don't put it on the stack
           stack.pop();
           break;
           default:
           // anything besides the operators, lets add to the postfix
           postfix += infix[i];
        }
     }
     catch (const char * error)
     {
        cout << error << endl;
     }
  }
  // let's go ahead and save the rest of the operators to the stack
  while (!stack.empty())
  {
   // spaces too, because you know, they're important
   postfix += ' ';
   postfix += stack.top();
   stack.pop();
  }
   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
