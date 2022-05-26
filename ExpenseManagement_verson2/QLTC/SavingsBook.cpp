#include "SavingsBook.h"
#include "Family.h"
#include "Header.h"

SavingsBook::SavingsBook() {
	balance = 0;
	term = 0;
	interest_rate = 0;
	issued_date.SetMonth(5);
	issued_date.SetYear(2022);
}

SavingsBook::SavingsBook(double balance, int term, double interest_rate, Date issued_date) {
	this->balance = balance;
	this->term = term;
	this->interest_rate = interest_rate;
	this->issued_date.SetMonth(issued_date.GetMonth());
	this->issued_date.SetYear(issued_date.GetYear());
}
double SavingsBook::GetBalance(Date cur) {
	return IsDueDate(cur) ? balance + balance * interest_rate * term : balance;
}
int SavingsBook::GetTerm() {
	return term;
}
double SavingsBook::GetInterestRate() {
	return interest_rate;
}
Date SavingsBook::GetIssuedDate() {
	return issued_date;
}
double SavingsBook::GetInterest(Date cur) {
	return IsDueDate(cur) ? balance * interest_rate * term : 0;
}
Date SavingsBook::GetDueDate() {
	Date due_date;
	if (issued_date.GetMonth() + term > 12) {
		due_date.SetMonth((issued_date.GetMonth() + term) % 12);
		due_date.SetYear(issued_date.GetYear() + (issued_date.GetMonth() + term) / 12);
	}
	else {
		due_date.SetMonth(issued_date.GetMonth() + term);
		due_date.SetYear(issued_date.GetYear());
	}
	return due_date;
}
bool SavingsBook::IsDueDate(Date cur) {
	if (Date::MonthDiff(cur, issued_date) >= term)
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
	/*bool b = nhapSoNguyen(select);
	while (!b || select < 1 || select > 2) {
		if (!b)  cout << "Wrong format, Try again: ";
		else cout << "Select is invalid, Try again: ";
		b = nhapSoNguyen(select);
	}*/
	term = (select == 1) ? 6 : 12;
}
void SavingsBook::InterestInput() {
	double interest_rate_input;
	if (term <= 6) {
		cout << "Enter monthly interest rate (0.004 - 0.01): ";		// Đặt phạm vi nhất định (theo tháng)
		cin >> interest_rate_input;
		while (interest_rate_input < 0.004 || interest_rate_input > 0.01) {
			cout << "Limit exceeded, try again: ";
			cin >> interest_rate_input;
		}
	}
	else {
		cout << "Enter annual interest rate (0.05 - 0.07): ";			// Đặt phạm vi nhất định (theo năm)
		cin >> interest_rate_input;
		while (interest_rate_input < 0.05 || interest_rate_input > 0.07) {
			cout << "Limit exceeded, try again: ";
			cin >> interest_rate_input;
		}
	}
	interest_rate = interest_rate_input;
}
void SavingsBook::SetIssuedDate(Date issued_date) {
	this->issued_date.SetMonth(issued_date.GetMonth());
	this->issued_date.SetYear(issued_date.GetYear());
}
