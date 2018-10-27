#ifndef VELOCITY_H
#define VELOCITY_H

using namespace std;
#include <iostream>
#include <cmath>

class Velocity
{
private:
   float dx;
   float dy;

public:
   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;

   Velocity &operator ++();
   Velocity operator ++(int x);

   inline friend Velocity operator + (const Velocity &lhs, const Velocity &rhs)
   {
   	Velocity p;
   	p.dx = lhs.dx + rhs.dx;
   	p.dy = lhs.dy + rhs.dy;
   	return p;
   }

   inline friend Velocity & operator += (Velocity &lhs, const Velocity & rhs)
   {
   	lhs.dx = lhs.dx + rhs.dx;
   	lhs.dy = lhs.dy + rhs.dy;
   	return lhs;
   }

   inline friend Velocity operator - (const Velocity & lhs, const Velocity & rhs)
   {
   	Velocity result;
   	result.dx = lhs.dx - rhs.dx;
   	result.dy = lhs.dy - rhs.dy;
   	return result;
   }

   inline friend Velocity & operator -= (Velocity & lhs, const Velocity & rhs)
   {
   	lhs.setDx(lhs.dx - rhs.dx);
   	lhs.setDy(lhs.dy - rhs.dy);

   	return lhs;
   }
};

inline bool operator ==(const Velocity &lhs, const Velocity &rhs)
{
   float dxDiff = fabs(lhs.getDx() - rhs.getDx());
   float dyDiff = fabs(lhs.getDy() - rhs.getDy());

   return (dxDiff <= .001 && dyDiff <= .001);
}

inline bool operator !=(const Velocity &lhs, const Velocity &rhs)
{

   return !(lhs == rhs);
}

inline bool operator >(const Velocity &lhs, const Velocity &rhs)
{
   float mag1 = sqrt(lhs.getDx()*lhs.getDx() + lhs.getDy()*lhs.getDy());
   float mag2 = sqrt(rhs.getDx()*rhs.getDx() + rhs.getDy()*rhs.getDy());

   return (mag1 > mag2);
}

inline bool operator <(const Velocity &lhs, const Velocity &rhs)
{
   float mag1 = sqrt(lhs.getDx()*lhs.getDx() + lhs.getDy()*lhs.getDy());
   float mag2 = sqrt(rhs.getDx()*rhs.getDx() + rhs.getDy()*rhs.getDy());

   return (mag1 < mag2);
}

inline bool operator <=(const Velocity &lhs, const Velocity &rhs)
{
   float mag1 = sqrt(lhs.getDx()*lhs.getDx() + lhs.getDy()*lhs.getDy());
   float mag2 = sqrt(rhs.getDx()*rhs.getDx() + rhs.getDy()*rhs.getDy());

   if (mag1 <= mag2)
      return true;
   else 
      return false;
}

inline bool operator >=(const Velocity &lhs, const Velocity &rhs)
{
   float mag1 = sqrt(lhs.getDx()*lhs.getDx() + lhs.getDy()*lhs.getDy());
   float mag2 = sqrt(rhs.getDx()*rhs.getDx() + rhs.getDy()*rhs.getDy());

   if (mag1 >= mag2)
      return true;
   else 
      return false;
}

inline istream& operator >>(istream &in, Velocity &rhs)
{
   float dx;
   float dy;
   in >> dx >> dy;
   rhs.setDx(dx);
   rhs.setDy(dy);
   return in;
}

inline ostream& operator <<(ostream &out, const Velocity &rhs)
{
   out << "(dx=" << rhs.getDx() << ", dy=" << rhs.getDy() << ")";
}
#endif
