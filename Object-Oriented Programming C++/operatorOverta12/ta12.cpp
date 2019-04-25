/******************************************
 * Testing code for Team Activity 12
 ******************************************/

#include <iostream>
using namespace std;

#include "point.h"
#include "velocity.h"

void partI(const Velocity &v1, const Velocity &v2)
{

   Velocity v3 = v1 + v2;
   
   cout << "v1 + v2 = ";
   v3.display();
   cout << endl;

   v3 += v1;

   cout << "v3 += v1 gives: ";
   v3.display();
   cout << endl;

   cout << endl;

}

void partII(const Velocity &v1, const Velocity &v2)
{
   cout << "PartII" << endl;
   Velocity v3 = v1 - v2;
   
   cout << "v1 - v2 = ";
   v3.display();
   cout << endl;

   v3 -= v1;

   cout << "v3 -= v1 gives: ";
   v3.display();
   cout << endl;

   cout << endl;
}

void partIII(const Velocity &v1, const Velocity &v2)
{
   Point p;
   cout << "Enter a new point:\n";
   
   float x;
   cout << "x: ";
   cin >> x;
   p.setX(x);

   float y;
   cout << "y: ";
   cin >> y;
   p.setY(y);

   p += v1;
   cout << "Adding v1 to p gives: " << p << endl;

   p += v2;
   cout << "After that, adding v2 to p gives: " << p << endl;
   
   cout << endl;
}

void stretchI(const Velocity &v1, const Velocity &v2)
{

   if (v1 == v2)
      cout << "==\n";

   if (v1 != v2)
      cout << "!=\n";

   if (v1 > v2)
      cout << ">\n";

   if (v1 < v2)
      cout << "<\n";

   if (v1 >= v2)
      cout << ">=\n";

   if (v1 <= v2)
      cout << "<=\n";

   cout << endl;

}

void stretchII(const Velocity &v1, const Velocity &v2)
{

   Velocity v3;

   cout << "Enter another velocity (in the format: 1.23 2.34): ";
   cin >> v3;

   cout << "The three velocity objects are: ";
   cout << v1 << ", " << v2 << ", and " << v3 << endl;

   cout << endl;

}

void stretchIII(const Velocity &v1, const Velocity &v2)
{

   Velocity v3 = v1;
   Velocity v4 = ++v3;

   cout << "Using ++v, the value is: ";
   v3.display();
   cout << endl;

   cout << "and the returned value is: ";
   v4.display();
   cout << endl;

   v3 = v1;
   v4 = v3++;

   cout << "Using v++, the value is: ";
   v3.display();
   cout << endl;

   cout << "and the returned value is: ";
   v4.display();
   cout << endl;

   cout << endl;

}


int main()
{
   Velocity v1;
   Velocity v2;

   v1.prompt();
   v2.prompt();

   partI(v1, v2);
   partII(v1, v2);
   partIII(v1, v2);

   stretchI(v1, v2);
   stretchII(v1, v2);
   stretchIII(v1, v2);

   return 0;
}
