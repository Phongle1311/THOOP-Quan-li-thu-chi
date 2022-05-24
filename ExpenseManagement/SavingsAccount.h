#pragma once
#include "SavingsBook.h"
#include "Date.h"
#include <vector>
class SavingsAccount
{
private:
	vector<SavingsBook> book_list;
	double total_balance;
public:
	SavingsAccount();
	~SavingsAccount();
	double GetTotalBalance();								//Lấy tổng tiền hiện có trong tất cả các sổ
	bool AddSavingsBook(SavingsBook book, double money);	//Mở thêm 1 sổ
	bool RemoveSavingsBook();								//Xóa những sổ đã hết kỳ hạn
};

