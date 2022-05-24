#pragma once

// Thu chi hằng tháng
class Family
{
private:
	// Thu nhập gồm: lương của vợ/chồng, thu nhập chung, thu nhập khác
	double husband_salary;
	double wife_salary;
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
	double GetDeposit();			// Phần tiền gửi vào tiết kiệm
	double GetRemainingMoney();		// Phần tiền còn dư
	void HusbandSalaryInput();		// Nhập lương chồng		
	void WifeSalaryInput();			// Nhập lương vợ	
	void JointIncomeInput();		// Nhập thu nhập chung	
	void OtherIncomeInput();		// Nhập thu nhập khác	
	void ExpenseInput();			// Nhập chi sinh hoạt	
	void CostsIncurredInput();		// Nhập chi phí phát sinh	
};
