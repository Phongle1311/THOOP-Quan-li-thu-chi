#pragma once
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;
class SavingsBook
{
private:
	double balance;									// Số dư
	int term;										// Kì hạn
	double interest_rate;							// Lãi suất
	Date issued_date;								// Ngày phát hành
public:
	SavingsBook();
	SavingsBook(double balance, int term, double interest_rate, Date issued_date);
	double GetBalance();							// Lấy số dư 
	double GetInterest();							// Lấy tiền lãi
	bool IsDueDate();								// Kiểm tra đến kỳ hạn chưa
	Date GetDueDate();								// Lấy ra ngày đảo hạn
	bool MakeDeposit(double money);					// Gửi tiền vào sổ
	void TermInput();								// Nhập kỳ hạn
	void InterestInput();							// Nhập lãi suất
	void SetIssuedDate(Date issued_date);			// Đặt ngày phát hành sổ
};
