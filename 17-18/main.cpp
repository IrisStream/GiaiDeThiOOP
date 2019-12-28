#include "employee.h"

class MyFloat
{
protected:
	char* mData;
public:
	MyFloat()
	{
		mData = new char[10];
	}
	MyFloat(float v)
	{
		mData = new char[10];
		snprintf(mData, sizeof(mData), "%f", v);
	}
	MyFloat(const MyFloat& source)
	{
		this->mData = new char[strlen(source.mData) + 1];
		for (int i = 0; i <= strlen(source.mData); i++)
		{
			this->mData[i] = source.mData[i];
		}
	}
	operator char* () const
	{
		return mData;
	}
	virtual MyFloat& operator =(const MyFloat& source)
	{
		if (this->mData != NULL)
			delete []this->mData;
		this->mData = new char[strlen(source.mData) + 1];
		for (int i = 0; i <= strlen(source.mData); i++)
		{
			this->mData[i] = source.mData[i];
		}
		return *this;
	}
	static MyFloat ValueOf(float value)
	{
		MyFloat temp(value);
		return temp;
	}
	~MyFloat()
	{
		if(mData != NULL)
			delete []mData;
	}
	friend istream& operator >>(istream& in, MyFloat& f)
	{
		in >> f.mData;
		return in;
	}
	friend ostream& operator <<(ostream& out, const MyFloat& f)
	{
		out << f.mData;
		return out;
	}
};

class MyComplex : public MyFloat
{
private:
	char* mImaginary;
public:
	MyComplex(float real, float imaginary) :MyFloat(real)
	{
		mImaginary = new char[10];
		snprintf(mImaginary, sizeof(mImaginary), "%f", imaginary);
	}
	virtual MyComplex& operator=(const MyComplex& source)
	{
		MyFloat::operator=(source);
		delete[] this->mImaginary;
		this->mImaginary = new char[strlen(source.mImaginary) + 1];
		for (int i = 0; i <= strlen(source.mImaginary); i++)
		{
			this->mImaginary[i] = source.mImaginary[i];
		}
		return *this; 
	}
};

class PI : public MyFloat
{
private:
	PI() : MyFloat(float(3.14))
	{
	}
	static PI* Pi;
public:
	static PI* getPi()
	{
		if (Pi == NULL)
			Pi = new PI;
		return Pi;
	}
};


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