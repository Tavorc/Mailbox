#ifndef _DATE_H
#define _DATE_H


#include <string>


using namespace std;

class DateTime		
{
private:
	string _day;
	string _month;
	string _year;
	string _sec;
	string _min;
	string _hour;
			

public:
	DateTime();
	DateTime(char* mailtime);            //conversion Ctor
	DateTime(const DateTime &datetime);    //copy Ctor
	
	DateTime& operator=(const DateTime& dt);   // operator =
	
	//getters
	const string& getDay();
	const string& getMonth();
	const string& getYear();
	const string& getHour();
	const string& getMin();
	const string& getSec();
	
	//setters
	void setDay(const string& day);
	void setMonth(const string& month);
	void setYear(const string& year);
	void setSec(const string& sec);
	void setMin(const string& min);
	void setHour(const string& hour);
	
};

#endif