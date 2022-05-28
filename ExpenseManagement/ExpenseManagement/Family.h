#pragma once
#include "SavingsAccount.h"
#include "Loan.h"
//Thu chi hằng tháng
class Family
{
private:
	//Thu nhập gồm: lương của vợ/chồng, thu nhập chung, thu nhập khác
	double husband_salary;
	double wife_salary;
	double other_income;

	//Chi phí gồm: chi phí sinh hoạt, chi phí phát sinh
	double bills;
	double food_expense;
	double other_expense;

	//Tài khoản tiết kiệm gia đình
	double family_account;

	//Tiền tích lũy được từ thu nhập khác của tháng trước
	double accumulated;

	//Tài khoản tiết kiệm ngân hàng
	SavingsAccount bank_account;

	//Quản lý nợ
	Loan debts;

public:
	Family();
	Family(double wife_salary, double husband_salary, double other_income, double bills, double food_expense, double other_expense, double family_account, double accumulated, SavingsAccount bank_account, Loan debts);
	
	//Lấy ra thu nhập khác
	double GetOtherIncome();	
	//Lấy ra tổng chi phí
	double GetTotalCost();
	//Lấy ra phần tiền gửi vào tiết kiệm
	double GetDeposit();	
	//Lấy ra tổng tiền lương của hai vợ chồng
	double GetTotalSalary();
	//Lấy ra hiệu thu - chi
	double GetDiffernceIncomeAndExpense();
	//Lấy ra tiền tích lũy dư được từ tháng trước
	double GetAccumulated();
	//Lấy ra tiền tích lũy được của tháng này để dành cho tháng sau
	double GetAccumulateForNextMonth();		
	//Gửi tiền vào ngân hàng
	bool MakeDepositToAccount(double money, Date cur);
	
	//Nhập lương chồng	
	void HusbandSalaryInput();	
	//Nhập lương vợ
	void WifeSalaryInput();	
	//Nhập thu nhập khác
	void OtherIncomeInput();
	//Nhập chi sinh hoạt (điện, nước...)
	void BillsInput();		
	//Nhập chi phí ăn uống
	void FoodExpenseInput();	
	//Nhập chi phí khác
	void OtherExpenseInput();
	
	//Cập nhật tiền tích lũy của tháng trước
	void SetAccumulated(double money);
	//Cập nhật khoản nợ
	void SetDebts(Loan debts);
	//In ra thông tin đã nhập
	void PrintAllInformationInput();
	//Gửi tiền vào tài khoản riêng của gia đình (không tính lãi)
	void SaveMoneyToFamilyAccount(double money);

	//Lấy ra khoản nợ
	Loan GetDebts();
	//Lấy ra tài khoản ngân hàng
	SavingsAccount GetAccount();
};
