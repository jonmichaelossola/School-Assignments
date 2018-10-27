#include <iostream>
#include "bag.h"

using namespace std;
int main() 
{
	//PART I
	Bag<float> firstBag;
	cout << "---PART I---" << endl;
	cout << "Count should be 0: " << firstBag.getCount() << endl;
	cout << "Capacity should be 5: " << firstBag.getCapacity() << endl;
	firstBag.addItem(9);
	firstBag.addItem(8);
	firstBag.addItem(7);
	cout << "Count should be 3: " << firstBag.getCount() << endl;
	cout << "Capacity be 5: " << firstBag.getCapacity() << endl;
	cout << "Item[1] should be 8: " << firstBag.getItem(1) << endl;
	
	
	// PART II
	
	Bag<int> secondBag;
	cout << "---PART II---" << endl;
	cout << "Count should be 0: " << secondBag.getCount() << endl;
	cout << "Capacity be 5: " << secondBag.getCapacity() << endl;
	secondBag.addItem(1);
	secondBag.addItem(2);
	secondBag.addItem(3);
	secondBag.addItem(4);
	secondBag.addItem(5);
	cout << "Count should be 5: " << secondBag.getCount() << endl;
	cout << "Capacity be 5: " << secondBag.getCapacity() << endl;
	secondBag.addItem(6);
	cout << "Count should be 6: " << secondBag.getCount() << endl;
	cout << "Capacity be 10: " << secondBag.getCapacity() << endl;
	cout << "Item[5] should be 6: " << secondBag.getItem(5) << endl;
	
	
	//PART III
	
	Bag<char> thirdBag;
	cout << "---PART III---" << endl;
	cout << "Count should be 0: " << thirdBag.getCount() << endl;
	cout << "Capacity be 5: " << thirdBag.getCapacity() << endl;
	thirdBag.addItem('a');
	thirdBag.addItem('b');
	thirdBag.addItem('c');
	thirdBag.addItem('d');
	thirdBag.addItem('e');
	cout << "Count should be 5: " << thirdBag.getCount() << endl;
	cout << "Capacity be 5: " << thirdBag.getCapacity() << endl;
	thirdBag.addItem('z');
	cout << "Count should be 6: " << thirdBag.getCount() << endl;
	cout << "Capacity be 10: " << thirdBag.getCapacity() << endl;
	cout << "Item[5] should be z: " << thirdBag.getItem(5) << endl;
	

	
	//STRETCH I
	cout << "---STRETCH I---" << endl;
	cout << "Location of 'c' should be 2: " << thirdBag.find('c') << endl;
	cout << "Location of 'z' should be 5: " << thirdBag.find('z') << endl;
	cout << "Location of 'q' should be -1 (not found): " << thirdBag.find('q') << endl;
	
	
	
	//STRETCH II
	cout << "---STRETCH II---" << endl;
	cout << "Count should be 6: " << thirdBag.getCount() << endl;
	cout << "Item[2] should be c: " << thirdBag.getItem(2) << endl;
	for (int i = 0; i < thirdBag.getCount(); i++)
	{
		cout << thirdBag.getItem(i) << " ";
	}
	cout << endl;
	thirdBag.deleteItem(2);
	cout << "Count should be 5: " << thirdBag.getCount() << endl;
	cout << "Item[2] should be d: " << thirdBag.getItem(2) << endl;
	cout << "Item[1] should be c: " << thirdBag.getItem(1) << endl;
	for (int i = 0; i < thirdBag.getCount(); i++)
	{
		cout << thirdBag.getItem(i) << " ";
	}
	cout << endl;
	
}
