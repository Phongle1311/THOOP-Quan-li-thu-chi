#include "Family.h"
#include <iostream>
using namespace std;
Family::Family() {
	salary = 0;
	other_income = 0;
	expense = 0;
	costs_incurred = 0;
}
Family::Family(double salary, double other_income, double expense, double costs_incurred) {
	this->salary = salary;
	this->other_income = other_income;
	this->expense = expense;
	this->costs_incurred = costs_incurred;
}
double Family::GetDeposit() {
	double shortage = expense + costs_incurred - other_income;
	if (shortage > 0)
		return salary - shortage;
	return salary;
}
double Family::GetRemainingMoney() {
	if (other_income > expense + costs_incurred)
		return other_income - expense - costs_incurred;
	return 0;
}
void Family::Input() {
	double husband_salary;
	double wife_salary;
	cout << "Enter husband salary: ";
	cin >> husband_salary;
	cout << "Enter wife salary: ";
	cin >> wife_salary;
	salary = husband_salary + wife_salary;
	cout << "Enter other income: ";
	cin >> other_income;
	cout << "Enter expense: ";
	cin >> expense;
	cout << "Enter cost costs incurred: ";
	cin >> costs_incurred;
}
