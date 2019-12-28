#include "date.h"

istream& operator>>(istream& in, Date& date)
{
	char tmp;
	in >> date.day >> tmp >> date.month >> tmp >> date.year;
	return in;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
