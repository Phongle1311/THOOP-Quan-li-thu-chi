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
	cout << "Enter static debt: ";
	cin >> debtS;
	cout << "Enter duration of static debt (month): ";
	cin >> durationS;
	cout << "Enter interest rate of static debt (vd: 1% = 0.01): ";
	cin >> interestRateS;
}

void Loan::EnterInforDebtD() {
	cout << "Enter dynamic debt: ";
	cin >> debtD;
	cout << "Enter duration of dynamic debt (month): ";
	cin >> durationD;
}

void Loan::EnterInterRateDebtD() {
	if (interestRateD.size() < durationD) {
		cout << "Enter Interest rate of " << interestRateD.size() + 1 << " month (vd: 1% = 0.01): ";
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
	if (cur.MonthDiff(cur, START_DAY) <= durationS)
		return debtS + debtS * durationS * interestRateS;
	else
		return 0;
}

double Loan::GetTotalDebtD(Date cur) {
	int monthsLeft = cur.MonthDiff(cur, START_DAY);
	if (monthsLeft <= durationD) {
		int n = interestRateD.size();
		if (n == 0) {
			cout << "Error: Must have information for at least 1 month!";
			return 0;
		}
		double res = debtD;
		if (n > durationD) {
			n = durationD;
		}
		int root = debtD;
		for (int i = 0; i < n; ++i) {
			res += (root * interestRateD[i]);
		}
		if (n > durationD)
			return res;
		for (int i = n; i < durationD; ++i) {
			res += (root * interestRateD[n - 1]);
		}
		return res;
	}
	else {
		return 0;
	}
}

int Loan::GetDurationS() {
	return durationS;
}
int Loan::GetDurationD() {
	return durationD;
}

double Loan::GetInterRateS(Date cur) {
	return GetTotalDebtS(cur) - debtS;
}
double Loan::GetInterRateD(Date cur) {
	return GetTotalDebtD(cur) - debtD;
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