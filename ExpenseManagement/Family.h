#pragma once
#include "MyException.h"

// Thu chi hằng tháng
class Family
{
private:
	// Thu nhập gồm: lương của vợ/chồng, thu nhập chung, thu nhập khác
	double wife_salary;
	double husband_salary;
	double joint_income;
	double other_income;

	// Chi phí gồm: chi phí sinh hoạt, chi phí phát sinh
	double expense;
	double costs_incurred;

public:
	Family();
	Family(double wife_salary, double husband_salary, double joint_income, double other_income, double expense, double costs_incurred);
	double GetTotalIncome();		// Tổng thu nhập
	double GetTotalCost();			// Tổng chi phí
	double GetDeposit();
	double GetRemainingMoney();		// Phần tiền còn dư
	void IncomeInput();				// Nhập thu riêng
	void CostInput();				// Nhập chi riêng
	void Input();					// Nhập thu chi chung
};
