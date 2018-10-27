// course.h

#ifndef COURSE_H
#define COURSE_H

#include "student.h"

#include <string>
#include <iostream>
using namespace std;

class Course
{
private:
   string name;
   int size;
   Student* classList;

public:
   Course(int size);
   ~Course();
   Course(const Course &rhs);
   Course & operator=(const Course & list);

   string getName() const { return name; }
   void setName(string name) { this->name = name; }
   
   int getSize() const { return size; }
   void setSize(int size) { this->size = size; }

   Student getStudent(int index) const;
   void setStudent(int index, const Student &);

   friend ostream& operator<<(ostream &out, const Course &course)
   {
      out << "Class list for course: " << course.name << endl;

      for (int i = 0; i < course.size; i++)
      {
         out << course.classList[i];
      }

      return out;
   }

};

#endif
