#include "employee.h"



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
		cin.ignore();
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
		cout << "-------------------------------" << endl;
	}
	int totalSalary = 0;
	for (int i = 0; i < n; i++)
	{
		totalSalary += a[i]->computeSalary();
	}
	cout << "Tong luong can tra la: " << totalSalary << endl;
	return 0;
}