#pragma once
#include <ctime>

class Date
{
private:
	int day;
	int month;
	int year;
public:
	// Contructors and Destructor
	Date();
	Date(int day, int month, int year);
	~Date();

	// Getter and Setter
	int GetMonth();
	int GetYear();
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void Update(int day, int month, int year);

	int Compare(Date& d);							// 1. greater 0. equal -1. less
	static int MonthDiff(Date after, Date before);				// the number of months
	/*static Date Current();*/							// current time of system
};

