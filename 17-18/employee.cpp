#include "employee.h"


Employee::Employee(string id, string name, Date birthDay, string address, float salaryFactor, Date startDate)
{
	this->id = id;
	this->name = name;
	this->birthDay = birthDay;
	this->address = address;
	this->salaryFator = salaryFactor;
	this->startDate = startDate;
}

string Employee::getName()
{
	return this->name;
}


void Employee::input()
{
	cout << "Nhap ma nhan vien: ";
	cin >> this->id;
	cout << "Nhap ten nhan vien: ";
	cin.ignore();
	getline(cin,this->name);
	cout << "Nhap ngay thang nam sinh: ";
	cin >> this->birthDay;
	cout << "Nhap dia chi: ";
	cin.ignore();
	getline(cin, this->address);
	cout << "Nhap he so luong: ";
	cin >> this->salaryFator;
	cout << "Nhap ngay bat dau lam viec: ";
	cin >> this->startDate;
}

void Employee::output() const
{
	cout << "ID: " << this->id << endl;
	cout << "Ho va ten: " << this->name << endl;
	cout << "Ngay sinh: " << this->birthDay << endl;
	cout << "Dia chi: " << this->address << endl;
	cout << "He so luong: " << this->salaryFator << endl;
	cout << "Ngay bat dau lam viec: " << this->startDate << endl;
}

void Manager::input()
{
	cout << "--NHAP MANAGER--" << endl;
	Employee::input();
}

void Manager::ouput()
{
	cout << "--XUAT MANAGER--" << endl;
	Employee::output();
}

int Manager::computeSalary() const
{
	return Employee::basicSalary * this->salaryFator;
}

int Manager::countEmployees()
{
	int counter = this->employees.size();
	for (int i = 0; i < this->employees.size(); i++)
	{
		counter += this->employees[i]->countEmployees();
	}
	return counter;
}

void Manager::addEmployee(Employee* employee)
{
	this->employees.push_back(employee);
}

void Manager::removeEmployee(string name)
{
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i]->getName() == name)
		{
			delete employees[i];
			employees[i] = employees[employees.size() - 1];
			employees.resize(employees.size() - 1);
		}
	}
}


void Programmer::input()
{
	cout << "--NHAP PROGRAMMER--" << endl;
	Employee::input();
	cout << "Nhap tien lam ngoai gio: ";
	cin >> this->overtime;
}

void Programmer::ouput()
{
	cout << "--XUAT PROGRAMMER--" << endl;
	Employee::output();
	cout << "Overtime: " << this->overtime << endl;
}

int Programmer::computeSalary() const
{
	return Employee::basicSalary*this->salaryFator + this->overtime;
}

int Programmer::countEmployees()
{
	return 0;
}

void Designer::input()
{
	cout << "--NHAP DESIGNER--" << endl;
	Employee::input();
	cout << "Nhap tien thuong them: ";
	cin >> this->bonus;
}

void Designer::ouput()
{
	cout << "--XUAT DESIGNER--" << endl;
	Employee::output();
	cout << "Bonus: " << this->bonus << endl;
}

int Designer::computeSalary() const
{
	return Employee::basicSalary*this->salaryFator + this->bonus;
}

int Designer::countEmployees()
{
	return 0;
}


void Tester::input()
{
	cout << "--NHAP TESTER--" << endl;
	Employee::input();
	cout << "Nhap so loi tim duoc: ";
	cin >> this->error;
}

void Tester::ouput()
{
	cout << "XUAT TESTER" << endl;
	Employee::output();
	cout << "So loi tim duoc: " << this->error << endl;
}

int Tester::computeSalary() const
{
	return Employee::basicSalary*this->salaryFator + this->error * Tester::errorFactor;
}

int Tester::countEmployees()
{
	return 0;
}

void Tester::setErrorFactor(int factor)
{
	cout << "Pleas enter the admin password: ";
	string pw;
	cin >> pw;
	if (pw == "sondeptrai")
	{
		errorFactor = factor;
		cout << "Change Success!!" << endl;
	}
	else
	{
		cout << "Wrong password! Leu leu :P" << endl;
	}
}
