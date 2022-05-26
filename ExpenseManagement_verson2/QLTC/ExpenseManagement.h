#pragma once
#include "Loan.h"
#include <string>
#include <iostream>
using namespace std;
class ExpenseManagement
{
private:
	double acummulated;
	Loan debt;
public:
	ExpenseManagement();
	ExpenseManagement(double acummulated, Loan debt);
	double GetAcummulatedMoney();
	double GetInterest();
	void SetDebt(Loan debt);
	Loan GetDebt();
	bool IsDebtFree(string date);
	~ExpenseManagement();
};

