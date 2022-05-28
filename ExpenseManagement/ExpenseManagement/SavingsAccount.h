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
	//Lấy tổng tiền hiện có trong tất cả các sổ
	double GetTotalBalance(Date cur);
	//Lấy tổng số tiền lãi
	double GetTotalInterest(Date cur);		
	//Mở thêm 1 sổ
	bool AddSavingsBook(double money, Date cur);
	//Xóa những sổ đã hết kỳ hạn
	bool RemoveSavingsBook(Date cur);	
	//In thông tin của sổ tiết kiệm
	void PrintBooksInformation(Date cur);			
};

