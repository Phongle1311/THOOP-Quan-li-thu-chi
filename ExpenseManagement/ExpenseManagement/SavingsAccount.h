#pragma once
#include "SavingsBook.h"
#include "Date.h"
#include <vector>
class SavingsAccount
{
private:
	vector<SavingsBook> book_list;
	double total_balance;
	double total_interest;
public:
	SavingsAccount();
	~SavingsAccount();
	double GetTotalBalance(Date cur);				// Lấy tổng tiền hiện có trong tất cả các sổ
	double GetTotalInterest(Date cur);				// Lấy tổng số tiền lãi
	bool AddSavingsBook(double money, Date cur);	// Mở thêm 1 sổ
	bool RemoveSavingsBook(Date cur);				// Xóa những sổ đã hết kỳ hạn
	void PrintBooksInformation(Date cur);			
};

