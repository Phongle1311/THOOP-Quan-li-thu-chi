#include "MyFunctions.h"

int main() {
	Date d(1,7,2022);
	Loan l;
	l.EnterInforDebtD();
	l.EnterInterRateDebtD();
	l.EnterInterRateDebtD();
	cout<<l.GetTotalDebtD1(d);
	return 0;
}