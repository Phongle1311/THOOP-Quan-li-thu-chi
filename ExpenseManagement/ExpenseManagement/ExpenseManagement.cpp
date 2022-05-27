#include "ExpenseManagement.h"
ExpenseManagement::ExpenseManagement() {
	acummulated = 0;
	remaining_money_in_month = 0;
	remaining_money_from_before_months = 0;
}
ExpenseManagement::ExpenseManagement(double acummulated, double remaining_money_in_month, double remaining_money_from_before_months, Loan debt) {
	this->acummulated = acummulated;
	this->remaining_money_in_month = remaining_money_in_month;
	this->remaining_money_from_before_months = remaining_money_from_before_months;
	this->debt = debt;
}
double ExpenseManagement::GetAcummulatedMoney() {
	return acummulated;
}
ExpenseManagement::~ExpenseManagement() {

}
void ExpenseManagement::SetDebt(Loan debt) {
	this->debt = debt;
}
Loan ExpenseManagement::GetDebt() {
	return debt;
}
void ExpenseManagement::SetRemainingMoneyInMonth(double money) {
	remaining_money_in_month = money;
}
double ExpenseManagement::GetRemainingMoneyInMonth() {
	return remaining_money_in_month;
}
double ExpenseManagement::GetRemainingMoneyFromBeforeMonths() {
	return remaining_money_from_before_months;
}
void ExpenseManagement::SetRemainingMoneyFromBeforeMonths(double money) {
	remaining_money_from_before_months = money;
}