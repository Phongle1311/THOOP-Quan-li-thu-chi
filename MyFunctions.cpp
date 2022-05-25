#include "MyFunctions.h"

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
	this->month = month;
	this->year = year;
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

Date Date::Current() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return Date(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
}

//Loan:: 
Loan::Loan() {
	START_DAY.Update(1, 5, 2022);
	debtS = 0;
	durationS = 0;
	interestRateS = 0;
	debtD = 0;
	durationD = 0;
}

Loan::Loan(double debtS, double durationS, double interestRateS, double debtD, double durationD) {
	START_DAY.Update(1, 5, 2022);
	this->debtS = debtS;
	this->durationS = durationS;
	this->interestRateS = interestRateS;
	this->debtD = debtD;
	this->durationD = durationD;
}

void Loan::EnterInforDebtS() {
	cout << "Enter static Debt: ";
	cin >> debtS;
	cout << "Enter duration of static Debt: ";
	cin >> durationS;
	cout << "Enter interest rate of static Debt: ";
	cin >> interestRateS;
}

void Loan::EnterInforDebtD() {
	cout << "Enter dynamic Debt: ";
	cin >> debtD;
	cout << "Enter duration of dynamic Debt : ";
	cin >> durationD;
}

void Loan::EnterInterRateDebtD() {
	if (interestRateD.size() < durationD) {
		cout << "Enter Interest rate of " << interestRateD.size() + 1 << " month: ";
		double temp;
		cin >> temp;
		interestRateD.push_back(temp);
	}
	else
		// Nếu quá kì hạn mà vẫn nhập lãi xuất thì báo lỗi
		cout << "Error at UpdateInterestRateD!!! (overdue)" << '\n';
}

double Loan::GetTotalDebtS(Date cur) {
	//Đến kì hạn thì mới trả về số tiền còn chưa đến thì trả về 0;
	if (cur.MonthDiff(cur, START_DAY) == durationS)
		return debtS+debtS* (durationS / 12.0) * interestRateS;
	else
		return 0;
}

double Loan::GetTotalDebtD1(Date cur) {
	double res = debtD;
	int monthsLeft = cur.MonthDiff(cur, START_DAY);
	if (monthsLeft == durationD) {
		for (int i = 0; i < durationD; ++i) {
			res = res + res * interestRateD[i];
		}
		return res;
	}
	else {
		return 0;
	}
}

double Loan::GetTotalDebtD2(Date cur) {
	int n = interestRateD.size();
	double res = debtD;
	int monthsLeft = cur.MonthDiff(cur, START_DAY);
	for (int i = 0; i < n; ++i) {
		res = res + (res * interestRateD[i]);
	}
	int m = monthsLeft - n;
	for (int i = n; i < m; ++i) {
		res = res + (res * interestRateD[n - 1]);
	}
	return res;
}
