#pragma once
#include <ctime>

class Date
{
private:
	int day;
	int month;
	int year;
public:
	//Contructors and Destructor
	Date();
	Date(int day, int month, int year);
	~Date();

	//Getter and Setter
	int GetMonth();
	int GetYear();
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void Update(int day, int month, int year);

	//1. greater 0. equal -1. less
	int Compare(Date& d);
	//The number of months
	static int MonthDiff(Date after, Date before);
	//Increase 1 month
	void IncreaseMonth();
};