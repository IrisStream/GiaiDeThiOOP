#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day = 1,int month = 1,int year = 2000): day(day),month(month),year(year){}
	friend istream& operator >>(istream& in, Date& date);
	friend ostream& operator <<(ostream& out, const Date& date);
};

#endif // !DATE_H
