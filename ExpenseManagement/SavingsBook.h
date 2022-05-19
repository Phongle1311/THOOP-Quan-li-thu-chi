#pragma once
#include "MyException.h"
#include <string>
#include <iostream>
using namespace std;
class SavingsBook
{
private:
	int id;
	double balance;
	int period;
	double interest_rate;
	string issued_date;
public:
	SavingsBook();
	SavingsBook(int id, double balance, int period, double interest_rate, string issued_date);
	double GetBalance();
	double GetDeposit();
	bool IsDueDate();
	bool MakeDeposit(double money);
	void Input();
};

