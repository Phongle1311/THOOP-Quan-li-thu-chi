#pragma once
#include "Loan.h"
#include <string>
#include <iostream>
using namespace std;
class ExpenseManagement
{
private:
	double acummulated;
	double remaining_money_in_month;
	double remaining_money_from_before_months;
	Loan debt;
public:
	ExpenseManagement();
	ExpenseManagement(double acummulated, double remaining_money_in_month, double remaining_money_from_before_months, Loan debt);
	double GetAcummulatedMoney();
	/*double GetInterest();*/
	void SetDebt(Loan debt);
	Loan GetDebt();
	void SetRemainingMoneyInMonth(double money);
	double GetRemainingMoneyFromBeforeMonths();
	void SetRemainingMoneyFromBeforeMonths(double money);
	double GetRemainingMoneyInMonth();
	//bool IsDebtFree(string date);
	~ExpenseManagement();
};

