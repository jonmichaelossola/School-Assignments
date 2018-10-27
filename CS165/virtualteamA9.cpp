/***********************************************************************
* Program:
*    Checkpoint ###, ????          (e.g. Checkpoint 01a, review)  
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

class Employee
{
protected:
	string name;
public:
	~Employee()
	{
		cout << "Deleting : " << name << endl;
	}
	void setName(const string &name) { this->name = name; }
	string getName() const { return name; }
	virtual void display() const = 0;
	virtual int getPayCheck() const = 0;
};

class HourlyEmployee : public Employee
{
private:
	int hourlyWage;
	int hours;
public:
	~HourlyEmployee()
	{
		cout << "Deleting: " << name << endl;
	}
	void setHourlyWage(const int hourlyWage) { this->hourlyWage = hourlyWage; }
	int getHourlyWage() const { return hourlyWage; }
	int getHours() const { return hours; }
	void setHours(int hours) { this->hours = hours; }
	virtual void display() const
	{
		cout << name << " - " << "$" << hourlyWage << "/hour" << endl;
	}
	virtual int getPayCheck() const
	{
		return hours * hourlyWage;
	}
};

class Salary : public Employee
{
private:
	int salary;
public:
	~Salary()
	{
		cout << "Deleting: " << name << endl;
	}
	void setSalary(const int salary) { this->salary = salary; }
	int getSalary() const { return salary; }
	virtual void display() const
	{
		cout << name << " - " << "$" << salary << "/year" << endl;
	}
	virtual int getPayCheck() const
	{
		return salary / 24;
	}
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	Employee * array[3];
	char input;
	string name;
	int pay;
	int count = 0;


	for (int i = 0; i < 3; i++)
	{
		cout << "Enter an h or an s: ";
		cin >> input;
		cout << "Enter a name: ";
		cin >> name;

		if (input == 'h')
		{
			HourlyEmployee * hourlyEmployee = new HourlyEmployee;
			hourlyEmployee->setName(name);
			cout << "What is the hourly rate? ";
			cin >> pay;
			cout << "How many hours did you work? ";
			int hours;
			cin >> hours;
			hourlyEmployee->setHourlyWage(pay);
			hourlyEmployee->setHours(hours);
			array[count] = hourlyEmployee;
			count++;
		}
		else
		{
			Salary * salary = new Salary;
			salary->setName(name);
			cout << "What is the salary? ";
			cin >> pay;
			salary->setSalary(pay);
			array[count] = salary;
			count++;
		}

	}

	for (int x = 0; x < count; x++)
	{
		array[x]->display(); 
		cout << "  " << array[x]->getPayCheck();
		cout << endl;
	}
   return 0;
}
