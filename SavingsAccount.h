#pragma once
#include "MyException.h"
#include "SavingsBook.h"
class SavingsAccount
{
private:
	SavingsBook* books_list;
public:
	SavingsAccount();
	~SavingsAccount();
	double GetTotalBalance();
	double GetTotalDeposit();
	bool AddSavingsBook(SavingsBook book);
	bool RemoveSavingBook(int id );
	bool MakeDeposit(int id, double money);
};

