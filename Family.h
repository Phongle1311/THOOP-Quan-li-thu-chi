#pragma once
#include "MyException.h"
class Family
{
private:
	double salary;
	double other_income;
	double expense;
	double costs_incurred;
public:
	Family();
	Family(double salary, double other_income, double expense, double costs_incurred);
	double GetDeposit();
	double GetRemainingMoney();
	void Input();
};

