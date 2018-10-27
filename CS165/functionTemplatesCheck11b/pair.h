/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{
private:
	T1 value1;
	T2 value2;
public:
	T1 getFirst() const { return value1; }
	T2 getSecond() const { return value2; }
	void setFirst(const T1 &value1) { this->value1 = value1; }
	void setSecond(const T2 &value2) { this->value2 = value2; }
	void display() const
	{
		std::cout << value1 << " - " << value2;
	}
};

#endif // PAIR_H
