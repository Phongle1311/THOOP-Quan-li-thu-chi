#pragma once
#include "MyException.h"
#include "Loan.h"
class Loan2 :public Loan
{
private:
	double DEBT;
	double DURATION;
public:
	void InterestRateInput();
};

