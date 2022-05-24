#include "Family.h"
#include <iostream>
using namespace std;
Family::Family() {
	wife_salary = 0;
	husband_salary = 0;
	joint_income = 0;
	other_income = 0;
	expense = 0;
	costs_incurred = 0;
}
Family::Family(double wife_salary, double husband_salary, double joint_income, double other_income, double expense, double costs_incurred){
	this->wife_salary = wife_salary;
	this->husband_salary = husband_salary;
	this->joint_income = joint_income;
	this->other_income = other_income;
	this->expense = expense;
	this->costs_incurred = costs_incurred;
}
double Family::GetTotalIncome() {
	return wife_salary + husband_salary + joint_income + other_income;
}
double Family::GetTotalCost() {
	return expense + costs_incurred;
}
double Family::GetDeposit() {
	// chỉ dùng lương để trả nợ, dùng thu nhập khác để trả chi phí
	// Nếu thu nhập khác không đủ trả chi phí thì dùng một phần lương để bù vào
	// tiền lương còn lại bao nhiêu thì gửi tiết kiệm
	double salary = wife_salary + husband_salary;
	double shortage = expense + costs_incurred - joint_income - other_income;
	if (shortage > 0)
		return  salary - shortage;
	return salary;
}
double Family::GetRemainingMoney() {
	if (other_income + joint_income > expense + costs_incurred)
		return other_income + joint_income - expense - costs_incurred;
	return 0;
}
void Family::HusbandSalaryInput() {
	cout << "Enter husband salary: ";
	cin >> husband_salary;
}
void Family::WifeSalaryInput() {
	cout << "Enter wife salary: ";
	cin >> wife_salary;
}
void Family::JointIncomeInput() {
	cout << "Enter joint income: ";
	cin >> joint_income;
}
void Family::OtherIncomeInput() {
	cout << "Enter other income: ";
	cin >> other_income;
}
void Family::ExpenseInput() {
	cout << "Enter expense: ";
	cin >> expense;
}
void Family::CostsIncurredInput() {
	cout << "Enter cost costs incurred: ";
	cin >> costs_incurred;
}

