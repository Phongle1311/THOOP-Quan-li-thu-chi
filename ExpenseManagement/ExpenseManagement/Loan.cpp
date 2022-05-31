#include "Loan.h"
Loan::Loan() {
	START_DAY.Update(1, 5, 2022);
	debtS = 0;
	durationS = 0;
	interestRateS = 0;
	debtD = 0;
	durationD = 0;
}

Loan::Loan(double debtS, int durationS, double interestRateS, double debtD, int durationD) {
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
	cout << "Enter interest rate of static debt (0.004 - 0.02): ";
	cin >> interestRateS;
	while (interestRateS < 0.004 || interestRateS > 0.02) {
		cout << "Limit exceeded, try again: ";
		cin >> interestRateS;
	}
}

void Loan::EnterInforDebtD() {
	cout << "Enter dynamic debt: ";
	cin >> debtD;
	cout << "Enter duration of dynamic debt (month): ";
	cin >> durationD;
}

void Loan::EnterInterRateDebtD() {
	if (interestRateD.size() < durationD) {
		cout << "Enter Interest rate of " << interestRateD.size() + 1 << " month (0.004 - 0.02): ";
		double temp;
		cin >> temp;
		while (temp < 0.004 || temp > 0.02) {
			cout << "Limit exceeded, try again: ";
			cin >> temp;
		}
		interestRateD.push_back(temp);
	}
	else
		// Nếu quá kì hạn mà vẫn nhập lãi xuất thì báo lỗi
		cout << "Error at UpdateInterestRateD!!! (overdue)" << '\n';
}

double Loan::GetTotalDebtS() {
	return debtS + debtS * durationS * interestRateS;
}

double Loan::GetTotalDebtD() {
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

int Loan::GetDurationS() {
	return durationS;
}
int Loan::GetDurationD() {
	return durationD;
}

double Loan::GetInterRateS() {
	return GetTotalDebtS() - debtS;
}
double Loan::GetInterRateD() {
	return GetTotalDebtD() - debtD;
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

void Loan::SetDebtS(double DebtS) {
	this->debtS = DebtS;
}
void Loan::SetDebtD(double DebtD) {
	this->debtD = DebtD;
}
void Loan::SetDurationS(int duration) {
	durationS = duration;
}
void Loan::SetDurationD(int duration) {
	durationD = duration;
}
void Loan::SetInterestRateS(double rateS) {
	interestRateS = rateS;
}
