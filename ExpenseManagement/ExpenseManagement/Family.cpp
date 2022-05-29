#include "Family.h"
#include <iostream>
#include <cmath>
using namespace std;
Family::Family() {
	wife_salary = 0;
	husband_salary = 0;
	other_income = 0;
	bills = 0;
	food_expense = 0;
	other_expense = 0;
	accumulated = 0;
	family_account = 0;
}
Family::Family(double wife_salary, double husband_salary, double other_income, double bills, double food_expense, double other_expense, double family_account, double accumulated, SavingsAccount bank_account, Loan debts) {
	this->wife_salary = wife_salary;
	this->husband_salary = husband_salary;
	this->other_income = other_income;
	this->bills = bills;
	this->food_expense = food_expense;
	this->other_expense = other_expense;
	this->accumulated = accumulated;
	this->bank_account = bank_account;
	this->family_account = family_account;
}
double Family::GetOtherIncome() {
	return other_income;
}
double Family::GetTotalCost() {
	return bills + food_expense + other_expense;
}
double Family::GetTotalSalary() {
	return wife_salary + husband_salary;
}
double Family::GetDeposit() {												
	// chỉ dùng lương để trả nợ, dùng thu nhập khác tháng hiện tại và tiền tích lũy được 
	// của tháng trước để trả chi phí, nếu thu nhập khác không đủ trả chi phí thì dùng 
	// một phần lương để bù vào tiền lương còn lại bao nhiêu thì gửi tiết kiệm
	double diff = GetDiffernceIncomeAndExpense();							
	if (diff < 0) {
		return  GetTotalSalary() + diff;
	}
	return GetTotalSalary();												
}
double Family::GetDiffernceIncomeAndExpense() {
	return GetOtherIncome() + accumulated - GetTotalCost();
}
double Family::GetAccumulated() {
	return accumulated;
}
double Family::GetAccumulateForNextMonth() {
	return GetDiffernceIncomeAndExpense() > 0 ? GetDiffernceIncomeAndExpense() : 0;
}
double Family::GetFamilyAccount() {
	return family_account;
}
void Family::HusbandSalaryInput() {
	cout << "Enter husband salary: ";
	cin >> husband_salary;
}
void Family::WifeSalaryInput() {
	cout << "Enter wife salary: ";
	cin >> wife_salary;
}
void Family::OtherIncomeInput() {
	cout << "Enter other income: ";
	cin >> other_income;
}
void Family::BillsInput() {
	cout << "Enter bills input: ";
	cin >> bills;
}
void Family::FoodExpenseInput() {
	cout << "Enter food expense input: ";
	cin >> food_expense;
}
void Family::OtherExpenseInput() {
	cout << "Enter other expense input: ";
	cin >> other_expense;
}
void Family::SetAccumulated(double money) {
	accumulated = money;
}
void Family::PrintAllInformationInput() {
	cout << "Wife salary: " << wife_salary << endl;
	cout << "Husband salary: " << husband_salary << endl;
	cout << "Other income: " << other_income + accumulated << " (included +" << accumulated << " from last month)" << endl;
	cout << "Bills: " << bills << endl;
	cout << "Food expense: " << food_expense << endl;
	cout << "Other expense: " << other_expense << endl;
}
void Family::SaveMoneyToFamilyAccount(double money) {
	family_account += money;
}
void Family::SetDebts(Loan debts) {
	this->debts = debts;
}
void Family::SetAccount(SavingsAccount bank_account) {
	this->bank_account = bank_account;
}
bool Family::MakeDepositToAccount(double money, Date cur) {
	if (GetDeposit() > 0) {
		bank_account.AddSavingsBook(money, cur);
		return true;
	}
	return false;
}
bool Family::MakeDepositToAccount(double money, int term, double interest_rate, Date cur) {
	if (GetDeposit() > 0) {
		bank_account.AddSavingsBook(money, term, interest_rate, cur);
		return true;
	}
	return false;
}
Loan Family::GetDebts() {
	return debts;
}
SavingsAccount Family::GetAccount() {
	return bank_account;
}