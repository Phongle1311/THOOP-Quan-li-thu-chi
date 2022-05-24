#pragma once
#include <string>
#include <iostream>
#include "Date.h"

using namespace std;
class SavingsBook
{
private:
	double balance;
	int term;
	double interest_rate;
	Date issued_date;
public:
	SavingsBook();
	SavingsBook(double balance, int term, double interest_rate, Date issued_date);
	double GetBalance();							//Lấy số dư 
	double GetInterest();							//Lấy tiền lãi
	bool IsDueDate();								//Kiểm tra đến kỳ hạn chưa
	bool MakeDeposit(double money);					//Gửi tiền vào sổ
	void TermInput();								//Nhập kỳ hạn
	void InterestInput();							//Nhập lãi suất
	void SetIssuedDate(const Date& issued_date);	//Đặt ngày phát hành sổ
};

