/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }

   // copy constructor
   NumberList(const NumberList & rhs);
   // destructor
   ~NumberList();
   // operator overload for the assignment operator
   NumberList& operator=(const NumberList &numList);
   // non default constructor
   NumberList(const int size);


   int getNumber(int index) const;
   void setNumber(int index, int value);
   
   void displayList() const;

};

#endif
