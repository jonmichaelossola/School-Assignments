/*****************************************************************
 * File: assign05.cpp
 * Purpose: This main function will exercise all the classes of
 *    this project.
 *
 * You may comment out certain parts while you are working on the
 * program, but you should make sure it is all present when you
 * submit.
 *****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "order.h"
#include "product.h"
#include "address.h"
#include "customer.h"

int main()
{
   ///////////////////////////////////////
   // Address Class
   ///////////////////////////////////////
   cout << "*** ADDRESS ***\n";
   cout << "Default constructor:\n";
   Address home;
   home.display();
   cout << endl;

   cout << "Getters/Setters:\n";
   home.setStreet("Bag End");
   home.setCity("The Shire");
   home.setState("ME");
   home.setZip("12345");

   cout << "Street: " << home.getStreet() << endl;
   cout << "City: " << home.getCity() << endl;
   cout << "State: " << home.getState() << endl;
   cout << "Zip: " << home.getZip() << endl;
   cout << endl;

   cout << "Display:\n";
   home.display();
   cout << endl;

   cout << "Non-default constructor:\n";
   Address hotel("The Prancing Pony", "Bree", "BR", "99999");

   hotel.display();
   cout << endl;

   /////////////////////////////////////////
   // Customer Class
   /////////////////////////////////////////
   cout << "*** CUSTOMER ***\n";
   cout << "Default constructor:\n";
   Customer frodo;
   frodo.display();
   cout << endl;

   cout << "Getters/Setters\n";
   frodo.setName("Frodo Baggins");
   frodo.setAddress(home);

   cout << "Name: " << frodo.getName() << endl;
   cout << "Address:\n";
   frodo.getAddress().display();
   cout << endl;

   cout << "Non-default constructor:\n";
   Customer gandalf("Gandalf the Grey", hotel);
   gandalf.display();
   cout << endl;

   /////////////////////////////////////////////
   // Product Class
   /////////////////////////////////////////////
   cout << "*** PRODUCT ***\n";
   cout << "Default constructor:\n";
   Product theRing;
   theRing.displayAdvertising();
   cout << endl;

   cout << "Getters/Setters:\n";
   theRing.setName("Ring of Power");
   theRing.setDescription("One Ring to bring them all and in the darkness bind them");
   theRing.setWeight(1);
   theRing.setBasePrice(999);

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "Name: " << theRing.getName() << endl;
   cout << "Description: " << theRing.getDescription() << endl;
   cout << "Weight: " << theRing.getWeight() << endl;
   cout << "BasePrice: " << theRing.getBasePrice() << endl;
   cout << endl;

   cout << "Non-default constructor:\n";
   Product staff("Wizard Staff", "More than just a walking stick", 100, 10);
   
   cout << "\nAdvertising:\n";
   staff.displayAdvertising();
   
   cout << "\nInventory:\n";
   staff.displayInventory();

   cout << "\nReceipt:\n";
   staff.displayReceipt();
   cout << endl;

   ////////////////////////////////////
   // Order Class
   ////////////////////////////////////
   cout << "*** ORDER ***\n";
   cout << "Default constructor:\n";
   Order orderRing;
   orderRing.displayInformation();
   cout << endl;

   cout << "Getters/Setters:\n";
   orderRing.setProduct(theRing);
   orderRing.setQuantity(1);
   orderRing.setCustomer(frodo);

   cout << "Product:\n";
   orderRing.getProduct().displayReceipt();
   cout << "Quantity: " << orderRing.getQuantity() << endl;
   cout << "Customer:\n";
   orderRing.getCustomer().display();
   cout << "Shipping Zip: " << orderRing.getShippingZip() << endl;
   cout << "TotalPrice: " << orderRing.getTotalPrice() << endl;
   cout << endl;

   cout << "Non-default constructor:\n";
   Order orderStaff(staff, 2, gandalf);

   cout << "Display Shipping Label:\n";
   orderStaff.displayShippingLabel();

   cout << "\nDisplay Information:\n";
   orderStaff.displayInformation();

   return 0;
}
