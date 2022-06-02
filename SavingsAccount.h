#pragma once
#include "SavingsBook.h"
#include "Date.h"
#include <vector>
#include <iostream>

using namespace std;

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
	//Mở thêm 1 sổ (chưa biết trước kì hạn, lãi suất)
	bool AddSavingsBook(double money, Date cur);
	//Lấy ra số lươngj sổ
	int GetNumberBooks();
	//Lấy ra 1 sổ từ 1 vị trí nào đó
	SavingsBook GetBook(int index);
	//Lấy ra 1 sổ từ dựa trên ngày phát hành
	SavingsBook GetBook(Date issued_date);
	//Mở thêm 1 sổ (đã biết trước kì hạn, lãi suất)
	bool AddSavingsBook(double money, int term, double interest_rate, Date cur);
	//Xóa những sổ đã hết kỳ hạn
	bool RemoveSavingsBook(Date cur);	
	//Cập nhật số dư, tiền lãi
	void UpdateStatusSavingsBook(Date cur);
	//In thông tin của sổ tiết kiệm
	void PrintBooksInformation(ostream& out, Date cur);
};

