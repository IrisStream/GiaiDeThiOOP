#ifndef BAI1_H
#define BAI1_H
#include <iostream>
using namespace std;

class MyFloat
{
protected:
	char* mData;
public:
	MyFloat();
	MyFloat(float v);
	MyFloat(const MyFloat& source);
	operator char* () const;
	virtual MyFloat& operator =(const MyFloat& source);
	static MyFloat ValueOf(float value);
	~MyFloat();
	friend istream& operator >>(istream& in, MyFloat& f);
	friend ostream& operator <<(ostream& out, const MyFloat& f);
};

class MyComplex : public MyFloat
{
private:
	char* mImaginary;
public:
	MyComplex(float real, float imaginary);
	virtual MyComplex& operator=(const MyComplex& source);
};

class PI : public MyFloat
{
private:
	PI() : MyFloat(float(3.14)){}
	static PI* Pi;
public:
	static PI* getPi();
};


#endif // !BAI1_H
