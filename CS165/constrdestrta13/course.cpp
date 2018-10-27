// course.cpp

#include "course.h"
#include <string>
#include <iostream>
using namespace std;

Course::Course(int size)
{
   this->size = size;

   classList = new Student[size];
}

Student Course::getStudent(int index) const
{
   return classList[index];
}

void Course::setStudent(int index, const Student & student)
{
   this->classList[index] = student;
}

Course::~Course()
{
	cout << "Cleaning up course: " << name << endl;

	delete [] classList;

	classList = NULL;
}

Course & Course::operator=(const Course &rhs)
{
	for (int i = 0; i < this->size; i++)
	{
		delete [] this->classList;
	}

	this->size = rhs.size;

	this->name = rhs.name;

	this->classList = new Student[size];

	for (int i = 0; i < size; i++)
	{
		this->classList[i] = rhs.classList[i];
	}

	return *this;
}

Course::Course(const Course &rhs)
{
	this->classList = NULL;

	*this = rhs;
}
