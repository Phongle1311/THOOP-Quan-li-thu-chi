#pragma once
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

	int Compare(Date& d);
	static int MonthDiff(Date after, Date& before);
};

