// student.cpp

#include "student.h"
#include <iostream>
using namespace std;

Student::~Student()
{
	if (name != NULL)
	{
		delete [] name;
		name = NULL;
	}
}


Student & Student::operator=(const Student &rhs)
{
	if (rhs.name == this->name)
	{
		return *this;
	}
	
	if (this->name != NULL)
	{
		delete [] name;
	}

	setName(rhs.getName());
	id = rhs.id;
	return *this;
}


Student::Student(const Student &student)
{
	name = NULL;

	*this = student;
}
