/***********************************************************************
* Program:
*    Checkpoint 10b, Removing from Vectors
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/***********************************************************
 * Class: Food
 * Description: Holds a food name composed of a name and its
 *   expiration date.
 *
 * You do not need to change this class.
 ***********************************************************/
class Food
{
private:
   string name;
   int month;
   int year;

public:
   /***********************
    * Constructors
    ***********************/
   Food()
   {
      name = "Unspecified";
      month = -1;
      year = -1;
   }

   Food(string name, int month, int year)
   {
      this->name = name;
      this->month = month;
      this->year = year;
   }

   ~Food()
   {
      cout << "Deleting " << name << endl;
   }

   /***********************
    * Getters/Setters
    ***********************/
   string getName() const { return name; }
   int getMonth() const { return month; }
   int getYear() const { return year; }

   void setName(string name) { this->name = name; }
   void setMonth(int month) { this->month = month; }
   void setYear(int year) { this->year = year; }

   /***********************
    * Display
    ***********************/
   void display() const
   {
      cout << name << " - " << month << "/" << year << endl;
   }
};

/*****************************************************
 * Function: promptInventory
 * Description: Asks the user for each item in their
 *   inventory and adds them to the vector.
 *****************************************************/
void promptInventory(vector<Food*> &items)
{
   string name;
   int month;
   int year;
   
   do
   {
      cout << "Enter item name: ";
      getline(cin, name);

      if (name != "quit")
      {
         cout << "Enter expiration month: ";
         cin >> month;

         cout << "Enter expiration year: ";
         cin >> year;

         cin.ignore(); // get rid of the extra '\n' char


         // TODO: Fill this in!
         // Create a new food item using name, month, and year
         // Add it to the items vector
         Food * food = new Food();
         food->setName(name);
         food->setMonth(month);
         food->setYear(year);
         items.push_back(food);

         cout << endl;
      }


   } while (name != "quit");
}


/*****************************************************
 * Function: displayInventory
 * Description: Displays each item in the inventory
 *****************************************************/
void displayInventory(vector<Food*> &items)
{
   cout << "Your current inventory:\n";


   // TODO: Fill this in!
   // Use an iterator to walk through the vector
   // and call the display() method on each Food item
   vector<Food*> :: iterator iter = items.begin();
   int i = 0;

   while (iter != items.end())
   {
      cout << items[i]->getName() << " - " << items[i]->getMonth() << "/" << items[i]->getYear() << endl;
      iter++;
      i++;
   }

}

/*****************************************************
 * Function: removeExpiredItems
 * Description: Removes any items that have expired
 *  (occurred before the given month and year) and
 *  deletes them.
 *****************************************************/
void removeExpiredItems(vector<Food*> &items, int currentMonth,
                        int currentYear)
{
   cout << "Checking for expired items...\n";


   // TODO: Fill this in!
   // Use an iterator to walk through the vector
   // and detect each item that has expired. Then delete it
   // and erase it from the list.
   vector<Food*> :: iterator iter = items.begin();

   for (int i = 0; i < items.size(); i++)
   {
      if (items[i]->getYear() < currentYear || items[i]->getYear() == currentYear
         && items[i]->getMonth() < currentMonth)
      {
      	 cout << "Deleting " << items[i]->getName() << endl;
         items.erase(items.begin() + i);
      }
      iter++;
   }

}

/*****************************************************
 * Function: removeExpiredItems
 * Description: Removes any items that have expired
 *  (occurred before the given month and year) and
 *  deletes them.
 *****************************************************/
void deleteRemainingItems(vector<Food*> &items)
{
   cout << "Cleaning up remaining items...\n";

   // You don't need to change this one--it works already.
   // (You can use it as a hint for your above functions...)

   vector<Food*>::iterator it = items.begin();

   while (it != items.end())
   {
      // *it (or in other words the thing that it refers to) is a Food*
      // so that's the thing we want to delete.
      Food* pFood = *it;
      delete pFood;

      // Not required, but its good to set pointers to null after deleting
      pFood = NULL;

      it = items.erase(it);

      // we don't need to call it++ in this case because erasing the
      // current item will automatically advance it to the next one.
   }
}

int main()
{
   vector<Food*> items;

   promptInventory(items);
   cout << endl;

   displayInventory(items);
   cout << endl;

   int month;
   int year;

   cout << "Enter current month: ";
   cin >> month;

   cout << "Enter current year: ";
   cin >> year;
   cout << endl;

   removeExpiredItems(items, month, year);
   cout << endl;

   displayInventory(items);
   cout << endl;

   deleteRemainingItems(items);

   cout << "\nGoodbye\n";

   return 0;
}
