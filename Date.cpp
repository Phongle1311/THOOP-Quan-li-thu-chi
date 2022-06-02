#include "Date.h"
Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}
Date::~Date() {

}
int Date::GetMonth() {
	return month;
}
int Date::GetYear() {
	return year;
}
void Date::SetDay(int day) {
	this->day = day;
}
void Date::SetMonth(int month) {
	this->month = month;
}
void Date::SetYear(int year) {
	this->year = year;
}
void Date::Update(int day, int month, int year) {
	this->day = day;
	if (month > 12) {
		this->month = month - 12;
		this->year = year + 1;
	}
	else {
		this->month = month;
		this->year = year;
	}
}

void Date::Input() {
	int month_input;
	int year_input;

	cout << "Enter the month: ";
	bool c = nhapSoNguyen(month_input);
	while (!c || month_input < 1 || month_input > 12) {
		if (!c)  cout << "Wrong format, try again: ";
		else cout << "Limit exceeded, try again: ";
		c = nhapSoNguyen(month_input);
	}

	cout << "Enter the year: ";
	c = nhapSoNguyen(year_input);
	while (!c) {
		cout << "Wrong format, try again: ";
		c = nhapSoNguyen(year_input);
	}

	Update(1, month_input, year_input);
}


int Date::Compare(Date& d) {
	if (year < d.year) return -1;
	if (year > d.year) return 1;
	if (month < d.month) return -1;
	if (month > d.month) return 1;
	if (day < d.day) return -1;
	if (day > d.day) return 1;
	return 0;
}

int Date::MonthDiff(Date after, Date before) {
	return (after.year - before.year) * 12 + after.month - before.month;
}

void Date::IncreaseMonth() {
	if (month < 12) month++;
	else year++, month = 1;
}
