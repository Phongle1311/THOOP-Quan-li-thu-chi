#pragma once
#include "SavingsAccount.h"
#include "ExpenseManagement.h"
// Thu chi hằng tháng
class Family
{
private:
	// Thu nhập gồm: lương của vợ/chồng, thu nhập chung, thu nhập khác
	double husband_salary;
	double wife_salary;
	double other_income;

	// Chi phí gồm: chi phí sinh hoạt, chi phí phát sinh
	double expense;
	double costs_incurred;

	//quản lý tài khoản
	SavingsAccount account;

	//Quản lý chi tiêu
	ExpenseManagement manage;

public:
	Family();
	Family(double wife_salary, double husband_salary, double other_income, double expense, double costs_incurred);
	double GetTotalIncome();		// Tổng thu nhập
	double GetTotalCost();			// Tổng chi phí
	double GetDeposit();			// Phần tiền gửi vào tiết kiệm
	double GetRemainingMoney();		// Phần tiền còn dư
	void HusbandSalaryInput();		// Nhập lương chồng		
	void WifeSalaryInput();			// Nhập lương vợ	
	void OtherIncomeInput();		// Nhập thu nhập khác	
	void ExpenseInput();			// Nhập chi sinh hoạt	
	void CostsIncurredInput();		// Nhập chi phí phát sinh	
	bool MakeDepositToAccount(double money, Date cur);
	void SetExpenseManagement(ExpenseManagement manage);
	ExpenseManagement GetExpenseManagement();
	SavingsAccount GetAccount();
};
