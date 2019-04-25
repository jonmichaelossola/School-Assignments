// student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
   int id;
   char *name;

public:
	Student() { name = NULL; }
	~Student();
	Student(const Student &rhs);
	Student & operator=(const Student &rhs);

   int getId() const { return id; }
   void setId(int id) { this->id = id; }

   std::string getName() const { return name; }
   void setName(std::string name)
   {
   	if (this->name != NULL)
   	{
   		delete [] this->name;
   		this->name = NULL;
   	}
   	this->name = new char[name.size() + 1];

   	strcpy(this->name, name.c_str());
   }

   friend ostream& operator<<(ostream &out, const Student &student)
   {
      out << student.id << " - " << student.name << endl;
      return out;
   }
};

#endif
