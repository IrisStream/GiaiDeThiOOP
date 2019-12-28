#include "bai1.h"

MyFloat::MyFloat()
{
	mData = new char[10];
}

MyFloat::MyFloat(float v)
{
	mData = new char[10];
	snprintf(mData, sizeof(mData), "%f", v);
}

MyFloat::MyFloat(const MyFloat& source)
{
	this->mData = new char[strlen(source.mData) + 1];
	for (int i = 0; i <= strlen(source.mData); i++)
	{
		this->mData[i] = source.mData[i];
	}
}

MyFloat::operator char* () const
{
	return mData;
}

MyFloat& MyFloat::operator =(const MyFloat& source)
{
	if (this->mData != NULL)
		delete[]this->mData;
	this->mData = new char[strlen(source.mData) + 1];
	for (int i = 0; i <= strlen(source.mData); i++)
	{
		this->mData[i] = source.mData[i];
	}
	return *this;
}

MyFloat MyFloat::ValueOf(float value)
{
	MyFloat temp(value);
	return temp;
}

MyFloat::~MyFloat()
{
	if (mData != NULL)
		delete[]mData;
}

istream& operator >>(istream& in, MyFloat& f)
{
	in >> f.mData;
	return in;
}

ostream& operator <<(ostream& out, const MyFloat& f)
{
	out << f.mData;
	return out;
}

inline MyComplex::MyComplex(float real, float imaginary) :MyFloat(real)
{
	mImaginary = new char[10];
	snprintf(mImaginary, sizeof(mImaginary), "%f", imaginary);
}

MyComplex& MyComplex::operator=(const MyComplex& source)
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

inline PI* PI::getPi()
{
	if (Pi == NULL)
		Pi = new PI;
	return Pi;
}
