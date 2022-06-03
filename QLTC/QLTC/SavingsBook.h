#pragma once
#include <string>
#include "Date.h"

using namespace std;
class SavingsBook
{
private:
	//Số dư
	double balance;
	//Kì hạn
	int term;	
	//Lãi suất
	double interest_rate;
	//Ngày phát hành
	Date issued_date;	

public:
	SavingsBook();
	SavingsBook(double balance, int term, double interest_rate, Date issued_date);
	//Lấy ra số dư 
	double GetBalance(Date cur);
	//Lấy ra kỳ hạn
	int GetTerm();
	//Lấy ra lãi suất
	double GetInterestRate();
	//Lấy ra ngày phát hành sổ
	Date GetIssuedDate();
	//Lấy ra tiền lãi
	double GetInterest(Date cur);
	//Lấy ra tiền gốc
	double GetPrincipal();
	//Lấy ra ngày đảo hạn
	Date GetDueDate();
	//Kiểm tra đến kỳ hạn chưa
	bool IsDueDate(Date cur);
	//Gửi tiền vào sổ
	bool MakeDeposit(double money);	
	//Nhập kỳ hạn
	void TermInput();	
	//Nhập lãi suất
	void InterestInput();
	//Đặt kì hạn
	void SetTerm(int term);
	//Đặt lãi suất
	void SetInterestRate(double interest_rate);
	//Đặt ngày phát hành sổ
	void SetIssuedDate(Date issued_date);			
};
