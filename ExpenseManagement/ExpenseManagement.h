#pragma once
#include "MyException.h"
#include "Loan.h"
#include <string>
#include <iostream>
using namespace std;
class ExpenseManagement
{
private:
	double acummulated;
	Loan* debt;
	string start_date;
	string finish_date;
public:
	ExpenseManagement();
	ExpenseManagement(double acummulated, double debt, string start_date, string finish_date);
	double GetAcummulatedMoney();
	double GetInterest();
	double GetTotalDebt();
	bool IsDebtFree(string date);
};

