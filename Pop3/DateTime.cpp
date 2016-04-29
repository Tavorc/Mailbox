#include "DateTime.h"
#include <iostream>
#include <string>
using namespace std;

DateTime::DateTime()
{}

DateTime :: DateTime(char* mailtime)
{
	char* day = new char[2];
	char* month = new char[2];
	char* year = new char[4];
	char* hour = new char[2];
	char* min = new char[2];
	char* sec = new char[2];
	string day1,month1,year1,hour1,min1,sec1;
	day[0]=mailtime[0];
	day[1]= mailtime[1];
	day[2] = '\0';
	day1 = day;
	_day = day1;
	month[0] = mailtime[2];
	month[1] = mailtime[3];
	month[2] = '\0';
	month1 = month;
	_month = month1;
	year[0] = mailtime[4];
	year[1] = mailtime[5];
	year[2] = mailtime[6];
	year[3] = mailtime[7];
	year[4] = '\0';
	year1 =year;
	_year = year;
	hour[0] = mailtime[8];
	hour[1] = mailtime[9];
	hour[2] = '\0';
	hour1 = hour;
	_hour = hour1;
	min[0] = mailtime[10];
	min[1] = mailtime[11];
	min[2] = '\0';
	min1 = min;
	_min = min1;
	sec[0] = mailtime[12];
	sec[1] = mailtime[13];
	sec[2] = '\0';
	sec1 = sec;
	_sec = sec1;
	
}

DateTime :: DateTime(const DateTime &datetime)
{
	 _day=datetime._day;
	 _month = datetime._month;
	 _year = datetime._year;
	 _sec = datetime._sec;
	 _min = datetime._min;
	 _hour = datetime._hour;
	 
	 
}

DateTime& DateTime :: operator=(const DateTime& dt)
{
	 _day=dt._day;
	 _month=dt._month;
	 _year=dt._year;
	 _sec=dt._sec;
	 _min=dt._min;
	 _hour=dt._hour;
	 return *this;
}

const string&   DateTime::getDay()
{
	return _day;
}
const string& DateTime :: getMonth()
{
	return _month;
}
const string&  DateTime:: getYear()
{
	return _year;
}
const string& DateTime:: getSec()
{
	return _sec;
}
const string& DateTime:: getMin()
{
	return _min;
}
const string& DateTime:: getHour()
{
	return _hour;
}


void DateTime:: setDay(const string& day)
{
	_day = day;
}
void DateTime::setMonth(const string& month)
{
	_month = month;
}
void DateTime::setYear(const string& year)
{
	_year = year;
}
void DateTime::setSec(const string& sec)
{
	_sec = sec;
}
void DateTime::setMin(const string& min)
{
	_min = min;
}
void DateTime::setHour(const string& hour)
{
	_hour = hour;
}
