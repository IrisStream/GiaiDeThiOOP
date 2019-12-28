#include "employee.h"
#include <stdio.h>


const int Employee::basicSalary = 10000000;
int Tester::errorFactor = 200000;

int main()
{
	cout << "Nhap so luong nhan vien: ";
	int n;
	cin >> n;
	Employee** a = new Employee * [n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap loai nhan vien: ";
		string type;
		getline(cin, type);
		if (type.empty())
			getline(cin, type);
		if (type == "Manager")
		{
			a[i] = new Manager;
		}
		else if (type == "Programmer")
		{
			a[i] = new Programmer;
		}
		else if (type == "Designer")
		{
			a[i] = new Designer;
		}
		else if (type == "Tester")
		{
			a[i] = new Tester;
		}
		a[i]->input();
		cout << "Nhap ten cap tren truc tiep: ";
		string name;
		cin.ignore();
		getline(cin, name);
		for (int j = 0; j < i; j++)
		{
			if (a[j]->getName() == name)
			{
				Manager* manager = dynamic_cast<Manager*>(a[j]);
				manager->addEmployee(a[i]);
				break;
			}
		}
		cout << "-------------------------------" << endl;
	}
	int totalSalary = 0;
	for (int i = 0; i < n; i++)
	{
		totalSalary += a[i]->computeSalary();
	}
	cout << "Tong luong can tra la: " << totalSalary << endl;
	cout << "Nhung quan ly co nhieu hon 10 cap duoi la: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->countEmployees() > 10)
			cout << a[i]->getName() << endl;
	}
	return 0;
}