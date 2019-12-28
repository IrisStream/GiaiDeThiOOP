#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "date.h"
using namespace std;

class Employee
{
protected:
	string id;
	string name;
	Date birthDay;
	string address;
	float salaryFator;
	Date startDate;
	static const int basicSalary;
public:
	Employee(
		string id = "123456789",
		string name = "Ngo Van Mac Dinh",
		Date birthDay = Date(),
		string address = "HCMUS",
		float salaryFactor = 1.0,
		Date startDate = Date(1, 1, 2019)
	);
	string getName();
	virtual void input();
	virtual void output() const;
	virtual int computeSalary() const = 0;
	virtual int countEmployees() = 0;
};

class Manager : public Employee
{
private:
	vector<Employee*> employees;
public:
	Manager() : Employee() {}
	virtual void input();
	virtual void ouput();
	virtual int computeSalary() const; 
	virtual int countEmployees();
	void addEmployee(Employee*);
	void removeEmployee(string name);
};

class Programmer : public Employee
{
private:
	int overtime;
public:
	Programmer(int overtime = 0) : Employee(), overtime(overtime) {}
	virtual void input();
	virtual void ouput();
	virtual int computeSalary() const;
	virtual int countEmployees();
};

class Designer : public Employee
{
private:
	int bonus;
public:
	Designer(int bonus = 0) : Employee(), bonus(bonus) {}
	virtual void input();
	virtual void ouput();
	virtual int computeSalary() const;
	virtual int countEmployees();
};

class Tester : public Employee
{
private:
	int error;
	static int errorFactor;
public:
	Tester(int error = 0) : Employee(), error(error) {}
	virtual void input();
	virtual void ouput();
	virtual int computeSalary() const;
	virtual int countEmployees();
	static void setErrorFactor(int);
};

#endif // !EMPLOYEE
