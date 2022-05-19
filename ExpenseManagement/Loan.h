#pragma once
class Loan
{
protected:
	double debt;
	double duration;
	double interest_rate;
public:
	Loan();
	Loan(double debt, double duration, double interest_rate);
	double GetTotalDebt();
};

