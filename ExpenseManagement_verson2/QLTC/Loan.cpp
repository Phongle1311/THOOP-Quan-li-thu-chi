#include "Loan.h"
Loan::Loan() {
	START_DAY.Update(1, 5, 2022);
	debtS = 0;
	durationS = 0;
	interestRateS = 0;
	debtD = 0;
	durationD = 0;
}

Loan::Loan(double debtS, double durationS, double interestRateS, double debtD, double durationD) {
	START_DAY.Update(1, 5, 2022);
	this->debtS = debtS;
	this->durationS = durationS;
	this->interestRateS = interestRateS;
	this->debtD = debtD;
	this->durationD = durationD;
}

void Loan::EnterInforDebtS() {
	cout << "Enter static Debt: ";
	cin >> debtS;
	cout << "Enter duration of static Debt (year): ";
	cin >> durationS;
	durationS *= 12;
	cout << "Enter interest rate of static Debt (%/year, vd: 1% = 0.01): ";
	cin >> interestRateS;
}

void Loan::EnterInforDebtD() {
	cout << "Enter dynamic Debt: ";
	cin >> debtD;
	cout << "Enter duration of dynamic Debt (month): ";
	cin >> durationD;
}

void Loan::EnterInterRateDebtD() {
	if (interestRateD.size() < durationD) {
		cout << "Enter Interest rate of " << interestRateD.size() + 1 << " month (%/month, vd: 1% = 0.01): ";
		double temp;
		cin >> temp;
		interestRateD.push_back(temp);
	}
	else
		// Nếu quá kì hạn mà vẫn nhập lãi xuất thì báo lỗi
		cout << "Error at UpdateInterestRateD!!! (overdue)" << '\n';
}

double Loan::GetTotalDebtS(Date cur) {
	//Đến kì hạn thì mới trả về số tiền còn chưa đến thì trả về 0;
	if (cur.MonthDiff(cur, START_DAY) == durationS)
		return debtS + debtS * (durationS / 12.0) * interestRateS;
	else
		return 0;
}

double Loan::GetTotalDebtD1(Date cur) {
	double res = debtD;
	int monthsLeft = cur.MonthDiff(cur, START_DAY);
	if (monthsLeft == durationD) {
		for (int i = 0; i < durationD; ++i) {
			if (i >= interestRateD.size() - 1) {
				res = res + res * interestRateD[interestRateD.size() - 1];
			}
			else {
				res = res + res * interestRateD[i];
			}
		}
		return res;
	}
	else {
		return 0;
	}
}

double Loan::GetTotalDebtD2(Date cur) {
	int n = interestRateD.size();
	double res = debtD;
	int monthsLeft = cur.MonthDiff(cur, START_DAY);
	for (int i = 0; i < n; ++i) {
		res = res + (res * interestRateD[i]);
	}
	int m = monthsLeft - n;
	for (int i = n; i < m; ++i) {
		res = res + (res * interestRateD[n - 1]);
	}
	return res;
}
Date Loan::GetDueDateDebtS() {
	Date due_date;
	if (START_DAY.GetMonth() + durationS > 12) {
		due_date.SetMonth((START_DAY.GetMonth() + durationS) % 12);
		due_date.SetYear(START_DAY.GetYear() + (START_DAY.GetMonth() + durationS) / 12);
	}
	else {
		due_date.SetMonth(START_DAY.GetMonth() + durationS);
		due_date.SetYear(START_DAY.GetYear());
	}
	return due_date;
}
Date Loan::GetDueDateDebtD() {
	Date due_date;
	if (START_DAY.GetMonth() + durationD > 12) {
		due_date.SetMonth((START_DAY.GetMonth() + durationD) % 12);
		due_date.SetYear(START_DAY.GetYear() + (START_DAY.GetMonth() + durationD) / 12);
	}
	else {
		due_date.SetMonth((START_DAY.GetMonth() + durationD) % 12);
		due_date.SetYear(START_DAY.GetYear() + (START_DAY.GetMonth() + durationD) / 12);
	}
	return due_date;
}