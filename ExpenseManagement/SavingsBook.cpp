#include "SavingsBook.h"
#include "Family.h"
SavingsBook::SavingsBook() {
	balance = 0;
	term = 0;
	interest_rate = 0;
	issued_date.month = 5;
	issued_date.year = 2022;
}
SavingsBook::SavingsBook(double balance, int term, double interest_rate, Date issued_date) {
	this->balance = balance;
	this->term = term;
	this->interest_rate = interest_rate;
	this->issued_date.month = issued_date.month;
	this->issued_date.year = issued_date.year;
}
double SavingsBook::GetBalance() {
	return IsDueDate() ? balance + balance * interest_rate * term : balance;
}
double SavingsBook::GetInterest() {
	return IsDueDate() ? balance * interest_rate * term : 0;
}
bool SavingsBook::IsDueDate() {
	if (Date::MonthDiff(Date.Current, issued_date) >= term) //Date.Current là thời điểm hiện tại
		return true;
	return false;
}
bool SavingsBook::MakeDeposit(double money) {
	if (money > 0) {
		balance = money;
		return true;
	}
	return false;
}
void SavingsBook::TermInput() {
	int select;
	cout << "1. A 6 month term" << endl;
	cout << "2. A 1 year term" << endl;
	cout << "Select a term: ";
	cin >> select;
	while (select != 1 && select != 2) {
		cout << "Select is invalid, Try again: " << endl;
		cin >> select;
	}
	term = (select == 1) ? 6 : 12;
	cout << "Enter successfully" << endl;
}
void SavingsBook::InterestInput() {
	double interest_rate_input;
	if (term <= 6) {
		cout << "Enter monthly interest rate (0.4 - 1.0) (%): ";		// Đặt phạm vi nhất định (theo tháng)
		cin >> interest_rate_input;
		while (interest_rate_input < 0.4 || interest_rate_input > 1.0) {
			cout << "Limit exceeded, try again: ";
			cin >> interest_rate_input;
		}
	}
	else {
		cout << "Enter annual interest rate (5.0 - 7.0) (%): ";			// Đặt phạm vi nhất định (theo năm)
		cin >> interest_rate_input;
		while (interest_rate_input < 5.0 || interest_rate_input > 7.0) {
			cout << "Limit exceeded, try again: ";
			cin >> interest_rate_input;
		}
	}
	cout << "Enter successfully" << endl;
}
void SavingsBook::SetIssuedDate(const Date& issued_date) {
	this->issued_date.month = issued_date.month;
	this->issued_date.year = issued_date.year;
}