#include "ExpenseManagement.h"
ExpenseManagement::ExpenseManagement() {
	acummulated = 0;
}
ExpenseManagement::ExpenseManagement(double acummulated, Loan debt) {
	this->acummulated = acummulated;
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