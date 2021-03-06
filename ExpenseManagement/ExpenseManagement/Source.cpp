#include "Header.h"
#include "Family.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <iostream>
#include "Date.h"
#include "Family.h"

Date cur(1, 5, 2022);
vector<Family> f(100);
int index = 0;

bool nhapSoNguyen(int& n) {
	n = 0;
	string s;
	cin >> s;
	// Bo qua cac khoang cach dau va cuoi string
	int i = 0, j = s.size() - 1;
	while (s[i] == ' ') i++;
	while (s[j] == ' ') j--;

	// Kiem tra dau am duong
	bool am = 0;
	if (s[i] != ' ') {
		if (s[i] == '-') am = 1, i++;
		else if (s[i] == '+') i++;
	}

	// Duyet string tach lay so
	while (i <= j) {
		if (s[i] < '0' || s[i]>'9') return 0;
		else n = n * 10 + s[i] - '0';
		i++;
	}

	if (am) n = -n;
	return 1;
}

void MainMenu() {
	int select = 0;
	char ctmp;

	/*Loan temp_debt;
	temp_debt.SetInterestRateD(0);
	f[0].SetDebts(temp_debt);*/

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================|| \n";
		cout << "||                    Expense Management Project                   ||\n";
		cout << "|| 1. Manage income & expense                                      ||\n";
		cout << "|| 2. Manage loan                                                  ||\n";
		cout << "|| 3. Look up                                                      ||\n";
		cout << "|| 4. Bank                                                         ||\n";
		cout << "|| 5. Export to file excel                                         ||\n";
		cout << "|| 6. Move to next month                                           ||\n";
		cout << "|| 0. Exit                                                         ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(select);
		while (!b || select < 0 || select > 6) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(select);
		}
		if (select == 0) break;

		system("cls");
		switch (select)
		{
		case 1:
			Menu1();
			break;
		case 2:
			Menu2();
			break;
		case 3:
			Menu3();
			break;
		case 4:
			Menu4();
			break;
		case 5:
			// Xuat file excel
			break;
		case 6: {
			f[index + 1].SaveMoneyToFamilyAccount(f[index].GetFamilyAccount());     // C???p nh???t ti???n t??i kho???n gia ????nh cho th??ng sau
			f[index + 1].SetAccumulated(f[index].GetAccumulateForNextMonth());		// C???p nh???t ti???n t??ch l??y cho th??ng sau
			f[index + 1].SetAccount(f[index].GetAccount());                         // C???p nh???t c??c th??ng tin th??? ng??n h??ng cho th??ng sau
			Loan dD = f[index].GetDebts();
			dD.SetInterestRateD(dD.GetRatesD().back());
			f[index + 1].SetDebts(dD);											    // C???p nh???t c??c th??ng tin n??? cho th??ng sau
			index++;
			cur.IncreaseMonth();
			break;
		}
		default:
			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
}

void Menu1() {
	int select = 0;
	int select2 = 0;
	int select3 = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                      MANAGE INCOME & EXPENSES                   ||\n";
		cout << "|| 1. Enter wife salary                                            ||\n";
		cout << "|| 2. Enter husband salary                                         ||\n";
		cout << "|| 3. Enter other income                                           ||\n";
		cout << "|| 4. Enter bills                                                  ||\n";
		cout << "|| 5. Enter food expense                                           ||\n";
		cout << "|| 6. Enter other expense                                          ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(select);
		while (!b || select < 0 || select > 6) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(select);
		}
		if (select == 0) break;

		system("cls");
		switch (select)
		{
		case 1:
			f[index].WifeSalaryInput();
			break;
		case 2:
			f[index].HusbandSalaryInput();
			break;
		case 3:
			f[index].OtherIncomeInput();
			break;
		case 4:
			f[index].BillsInput();
			break;
		case 5:
			f[index].FoodExpenseInput();
			break;
		case 6:
			f[index].OtherExpenseInput();
			break;
		default:

			break;
		}
		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}

	// Y??u c???u ng?????i d??ng c?? mu???n g???i ti???t ki???m ng??n h??ng
	cout << "Do you want to make deposit into a book?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Select: ";
	bool c = nhapSoNguyen(select2);
	while (!c || select2 < 1 || select2 > 2) {
		if (!c)  cout << "Wrong format, try again: ";
		else cout << "Limit exceeded, try again: ";
		c = nhapSoNguyen(select2);
	}
	if (select2 == 1) {
		if (f[index].GetDeposit() > 0) {
			double money = 0;
			// L???y ra c??c s??? d?? ???? qua ng??y ?????o h???n
			for (int i = 0; i < f[index].GetAccount().GetNumberBooks(); i++) {
				if (f[index].GetAccount().GetBook(i).IsDueDate(cur)) {
					money += f[index].GetAccount().GetBook(i).GetBalance(cur);
				}
			}
			if (money > 0) {
				SavingsAccount sa = f[index].GetAccount();
				sa.RemoveSavingsBook(cur);
				cout << "There are " << money << " from the due books. Do you want to combine them into this month?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No (save " << money << " to family account)" << endl;
				cout << "Select: ";
				bool d = nhapSoNguyen(select3);
				while (!d || select3 < 1 || select3 > 2) {
					if (!d)  cout << "Wrong format, try again: ";
					else cout << "Limit exceeded, try again: ";
					d = nhapSoNguyen(select3);
				}
				if (select3 == 1) {
					f[index].SetAccount(sa);
				}
				else {
					f[index].SaveMoneyToFamilyAccount(money);
					f[index].SetAccount(sa);
					money = 0;
				}
			}
			f[index].MakeDepositToAccount(f[index].GetDeposit() + money, cur);
			cout << "Make deposit successfully" << endl;
		}
		else {
			cout << "You don't have enough money to make a deposit. Please go to Look up for details" << endl;
		}
	}
	else {
		f[index].SaveMoneyToFamilyAccount(f[index].GetDeposit());		// Ng?????i d??ng kh??ng g???i v??o ng??n h??ng th?? ????a v??o tk gia ????nh
		cout << "Saved this amount to family account!" << endl;
	}
}

void Menu2() {
	int select = 0;
	char ctmp;
	Loan debt = f[index].GetDebts();
	while (true) {
		system("cls");
		Date START(1, 5, 2022);
		if (cur.Compare(START) == 0) {
			cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
			cout << "||================================MENU=============================||\n";
			cout << "||                            MANAGE LOAN                          ||\n";
			cout << "|| 1. Enter 1st loan (dynamic interst)                             ||\n";
			cout << "|| 2. Enter 2nd loan (fixed interest)                              ||\n";
			cout << "|| 0. Return to main screen                                        ||\n";
			cout << "||=================================o0o=============================||\n";
			cout << "Select: ";

			bool b = nhapSoNguyen(select);
			while (!b || select < 0 || select > 2) {
				if (!b)  cout << "Wrong format, try again: ";
				else cout << "Limit exceeded, try again: ";
				b = nhapSoNguyen(select);
			}
			if (select == 0) break;

			system("cls");
			switch (select)
			{
			case 1:
				debt.EnterInforDebtD();
				debt.EnterInterRateDebtD();
				break;
			case 2:
				debt.EnterInforDebtS();
				break;
			default:
				break;
			}
		}
		else {
			cout << "1st Loan (dynamic interst)" << endl;
			debt.EnterInterRateDebtD();
			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
	f[index].SetDebts(debt);
}
void Menu3() {
	int select = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                               LOOK UP                           ||\n";
		cout << "|| 1. Look up the lastest month                                    ||\n";
		cout << "|| 2. Predict debts payment situation                              ||\n";
		cout << "|| 3. Look up before months                                        ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(select);
		while (!b || select < 0 || select > 3) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(select);
		}
		if (select == 0) break;

		system("cls");
		switch (select)
		{
			// Xem t??nh h??nh thu - chi c???a th??ng
		case 1: {
			f[index].PrintAllInformationInput();
			break;
		}
			  // D??? b??o t??nh t??nh tr??? n??? d???a tr??n th??ng m???i nh???t
		case 2: {
			int duration_d = f[index].GetDebts().GetDurationD();
			int duration_s = f[index].GetDebts().GetDurationS();
			double monthly_debt_d = f[index].GetDebts().GetTotalDebtD() / duration_d;
			double monthly_debt_s = f[index].GetDebts().GetTotalDebtS() / duration_s;
			Date due_date_debt_d = f[index].GetDebts().GetDueDateDebtD();
			Date due_date_debt_s = f[index].GetDebts().GetDueDateDebtS();
			double accumulate = f[index].GetAccumulateForNextMonth();
			double deposit = f[index].GetAccount().GetBook(cur).GetPrincipal();
			double balance_family = f[index].GetFamilyAccount();
			double total_month = accumulate + f[index].GetDeposit();

			cout << "Total 1st debt is: " << f[index].GetDebts().GetTotalDebtD() << endl;
			cout << "Total 2nd debt is: " << f[index].GetDebts().GetTotalDebtS() << endl;
			cout << "Total debts you have: " << f[index].GetDebts().GetTotalDebtD() + f[index].GetDebts().GetTotalDebtS() << endl;
			cout << "Estimated 1st debt per month is: " << monthly_debt_d << endl;
			cout << "Estimated 2nd debt per month is: " << monthly_debt_s << endl;
			cout << "Total estimated debts per month you have to pay is: " << monthly_debt_s + monthly_debt_d << endl;
			if (f[index].GetTotalSalary() + f[index].GetOtherIncome() < f[index].GetTotalCost()) {
				cout << "Warning! You don't have enough money to pay expenses, you go bankrupt!!!" << endl;
				break;
			}
			else {
				cout << "Total accumulated money from incomes - expenses in this month: +" << accumulate << endl;
				cout << "Total money you make a deposit to a savings book: " << deposit << endl;
				cout << "Total balance in family account: " << balance_family << endl;
				cout << "Total amount of money you can have in this month to pay debts (excluding interest): " << accumulate + deposit + balance_family << endl;
				cout << endl << "Prediction: " << endl;
				if (due_date_debt_d.Compare(due_date_debt_s) == -1) {
					// ?????c t??nh ti???n l??i s??? c?? t??? vi???c g???i ti???t ki???m ???????c t??? th???i ??i???m hi???n t???i ?????n ng??y tr??? n??? ?????u ti??n
					Date cur1(1, cur.GetMonth() + 1, cur.GetYear());
					Family f1 = f[index];
					SavingsBook sb = f1.GetAccount().GetBook(f1.GetAccount().GetNumberBooks() - 1);
					while (cur1.Compare(due_date_debt_d) < 0) {
						f1.MakeDepositToAccount(deposit, sb.GetTerm(), sb.GetInterestRate(), cur1);
						cur1.Update(1, cur1.GetMonth() + 1, cur1.GetYear());
					}
					// f1.GetAccount().PrintBooksInformation(cur1);
					double total1 = 0;
					double interest1 = f1.GetAccount().GetTotalInterest(cur1);
					for (int i = 0; i < index; i++) {
						total1 += f[i].GetAccumulateForNextMonth() + f[i].GetDeposit();
					}
					total1 += total_month * Date::MonthDiff(due_date_debt_d, cur) + interest1;

					// D??? ??o??n n??? 1
					cout << "On " << due_date_debt_d.GetMonth() << "/" << due_date_debt_d.GetYear() << endl;
					cout << "Total amount of money you can have is: " << total1 << " (included +" << interest1 << " from interest)" << endl;
					if (total1 > f[index].GetDebts().GetTotalDebtD()) {
						cout << "You will have enough money to pay 1st debt" << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total1 - f[index].GetDebts().GetTotalDebtD())
							<< " more to pay 1st debt" << endl;
					}

					// ?????c t??nh ti???n l??i s??? c?? t??? vi???c g???i ti???t ki???m ???????c t??? th???i ??i???m hi???n t???i ?????n ng??y tr??? n??? ?????u th??? hai
					while (cur1.Compare(due_date_debt_s) < 0) {
						f1.MakeDepositToAccount(deposit, sb.GetTerm(), sb.GetInterestRate(), cur1);
						cur1.Update(1, cur1.GetMonth() + 1, cur1.GetYear());
					}
					// f1.GetAccount().PrintBooksInformation(cur1);
					double total2 = 0;
					double interest2 = f1.GetAccount().GetTotalInterest(cur1);
					for (int i = 0; i < index; i++) {
						total2 += f[i].GetAccumulateForNextMonth() + f[i].GetDeposit();
					}
					total2 += total_month * Date::MonthDiff(due_date_debt_s, cur) + interest2;

					// D??? ??o??n n??? 2
					cout << "On " << due_date_debt_s.GetMonth() << "/" << due_date_debt_s.GetYear() << endl;
					cout << "Total amount of money you can have is: " << total2 << " (included +" << interest2 << " from interest)" << endl;
					if (total2 - (f[index].GetDebts().GetTotalDebtS() + f[index].GetDebts().GetTotalDebtD()) > 0) {
						cout << "You will have enough money to pay 2nd debt" << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total2 - (f[index].GetDebts().GetTotalDebtS() + f[index].GetDebts().GetTotalDebtD()))
							<< " more to pay 2nd debt" << endl;
					}
				}
				else {
					// ?????c t??nh ti???n l??i s??? c?? t??? vi???c g???i ti???t ki???m ???????c t??? th???i ??i???m hi???n t???i ?????n ng??y tr??? n??? ?????u th??? hai
					Date cur2(1, cur.GetMonth() + 1, cur.GetYear());
					Family f2 = f[index];
					SavingsBook sb = f2.GetAccount().GetBook(f2.GetAccount().GetNumberBooks() - 1);
					while (cur2.Compare(due_date_debt_s) < 0) {
						f2.MakeDepositToAccount(deposit, sb.GetTerm(), sb.GetInterestRate(), cur2);
						cur2.Update(1, cur2.GetMonth() + 1, cur2.GetYear());
					}
					double total2 = 0;
					double interest2 = f2.GetAccount().GetTotalInterest(cur2);
					for (int i = 0; i < index; i++) {
						total2 += f[i].GetAccumulateForNextMonth() + f[i].GetDeposit();
					}
					total2 += total_month * Date::MonthDiff(due_date_debt_s, cur) + interest2;

					// D??? ??o??n n??? 2
					cout << "On " << due_date_debt_s.GetMonth() << "/" << due_date_debt_s.GetYear() << endl;
					cout << "Total amount of money you can have is: " << total2 << " (included +" << interest2 << " from interest)" << endl;
					if (total2 > f[index].GetDebts().GetTotalDebtS()) {
						cout << "You will have enough money to pay 2nd debt" << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total2 - f[index].GetDebts().GetTotalDebtS())
							<< " more to pay 2nd debt" << endl;
					}

					// ?????c t??nh ti???n l??i s??? c?? t??? vi???c g???i ti???t ki???m ???????c t??? th???i ??i???m hi???n t???i ?????n ng??y tr??? n??? ?????u ti??n
					while (cur2.Compare(due_date_debt_d) < 0) {
						f2.MakeDepositToAccount(deposit, sb.GetTerm(), sb.GetInterestRate(), cur2);
						cur2.Update(1, cur2.GetMonth() + 1, cur2.GetYear());
					}
					double total1 = 0;
					double interest1 = f2.GetAccount().GetTotalInterest(cur2);
					for (int i = 0; i < index; i++) {
						total1 += f[i].GetAccumulateForNextMonth() + f[i].GetDeposit();
					}
					total1 += total_month * Date::MonthDiff(due_date_debt_d, cur) + interest1;

					// D??? ??o??n n??? 1
					cout << "On " << due_date_debt_d.GetMonth() << "/" << due_date_debt_d.GetYear() << endl;
					cout << "Total amount of money you can have is: " << total1 << " (included +" << interest1 << " from interest)" << endl;
					if (total1 - (f[index].GetDebts().GetTotalDebtS() + f[index].GetDebts().GetTotalDebtD()) > 0) {
						cout << "You will have enough money to pay 1st debt" << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total1 - (f[index].GetDebts().GetTotalDebtS() + f[index].GetDebts().GetTotalDebtD()))
							<< " more to pay 1st debt" << endl;
					}
				}
			}
			break;
		}
		case 3: {
			Date d;
			Date start;
			start.Input();

			int temp_index = 0;
			if (d.Compare(cur) <= 0 && d.Compare(start) >= 0) {
				temp_index = index - Date::MonthDiff(cur, d);

				cout << endl << "On " << d.GetMonth() << "/" << d.GetYear() << endl;
				cout << "Information about Incomes and Expenses" << endl;
				f[temp_index].PrintAllInformationInput();

				cout << endl << "Information debts" << endl;
				cout << "You have 2 debts: " << endl;
				cout << "Debt 1: " << f[temp_index].GetDebts().GetTotalDebtD() << ", due date: "
					<< f[temp_index].GetDebts().GetDueDateDebtD().GetMonth() << "/"
					<< f[temp_index].GetDebts().GetDueDateDebtD().GetYear() << endl;
				cout << "Debt 2: " << f[temp_index].GetDebts().GetTotalDebtS() << ", due date: "
					<< f[temp_index].GetDebts().GetDueDateDebtS().GetMonth()
					<< "/" << f[temp_index].GetDebts().GetDueDateDebtS().GetYear() << endl;

				cout << endl << "Information savings account" << endl;
				f[temp_index].GetAccount().PrintBooksInformation(cout,d);
				cout << "Total current balance you have: " << f[temp_index].GetAccount().GetTotalBalance(d) << endl;
			}
			else {
				cout << "No data matching with this time information!" << endl;
			}
			break;
		}
		default:
			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
}

void Menu4() {
	int select = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                                BANK                             ||\n";
		cout << "|| 1. View debt status                                             ||\n";
		cout << "|| 2. View savings books status                                    ||\n";
		cout << "|| 3. View total current balance                                   ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(select);
		while (!b || select < 0 || select > 3) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(select);
		}
		if (select == 0) break;

		system("cls");
		switch (select)
		{
		case 1: {
			Date due_date_d = f[index].GetDebts().GetDueDateDebtD();
			Date due_date_s = f[index].GetDebts().GetDueDateDebtS();
			cout << "You have 2 debts: " << endl;
			cout << "Debt 1: " << f[index].GetDebts().GetTotalDebtD() << ", due date: " << due_date_d.GetMonth() << "/" << due_date_d.GetYear() << endl;
			cout << "Debt 2: " << f[index].GetDebts().GetTotalDebtS() << ", due date: " << due_date_s.GetMonth() << "/" << due_date_s.GetYear() << endl;
			break;
		}
		case 2:
			f[index].GetAccount().PrintBooksInformation(cout, cur);
			break;
		case 3:
			cout << "Total current balance you have: " << f[index].GetAccount().GetTotalBalance(cur) << endl;
			break;
		default:
			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
}

void readDatabase(const char* fileName) {
	fstream fi(fileName, ios::in);
	// Ki???m tra file c?? tr???ng h??y kh??ng, n???u tr???ng th?? kh???i ?????c
	if (fi.peek() == ifstream::traits_type::eof()) {
		return;
	}

	string line, word;
	vector<string> row;

	// D??ng ?????u ????? ?????c th??ng tin v??? c??c kho???n n???
	getline(fi, line);
	row.clear();
	stringstream s(line);
	while (getline(s, word, ',')) {
		row.push_back(word);
	}
	Loan debt(stod(row[0]), stoi(row[1]), stod(row[2]), stoi(row[3]), stod(row[4]));

	//  C??c d??ng c??n l???i: d??? li???u m???i th??ng: L????ng ch???ng, l????ng v???, thu nh???p kh??c
	//  h??a ????n, ??n u???ng, chi ti??u kh??c; g???i ti???t ki???m (0/1: kh??ng g???i/g???i),
	//  k?? h???n, l??i su???t; l??i su???t deptD
	double wife_salary;
	double husband_salary;
	double other_income;
	double bills;
	double food_expense;
	double other_expense;
	double accumulated = 0;
	double family_account = 0;

	SavingsAccount bank_account;

	while (getline(fi, line)) {
		row.clear();
		stringstream s(line);
		while (getline(s, word, ',')) {
			row.push_back(word);
		}

		wife_salary = stod(row[0]);
		husband_salary = stod(row[1]);
		other_income = stod(row[2]);
		bills = stod(row[3]);
		food_expense = stod(row[4]);
		other_expense = stod(row[5]);
		debt.SetInterestRateD(stod(row[9]));

		f[index].Update(wife_salary, husband_salary, other_income, bills, food_expense, other_expense, debt);
		if (row[6][0] == '0') {
			f[index].SaveMoneyToFamilyAccount(f[index].GetDeposit());
		}
		else {
			int term_temp = stoi(row[7]);
			double interest_rate_temp = stod(row[8]);
			double money = 0;

			// L???y ra c??c s??? d?? ???? qua ng??y ?????o h???n
			for (int i = 0; i < f[index].GetAccount().GetNumberBooks(); i++) {
				if (f[index].GetAccount().GetBook(i).IsDueDate(cur)) {
					money += f[index].GetAccount().GetBook(i).GetBalance(cur);
				}
			}
			if (money > 0) {
				SavingsAccount sa = f[index].GetAccount();
				sa.RemoveSavingsBook(cur);
				if (row[10][0] == '0') {
					f[index].SaveMoneyToFamilyAccount(money);
					f[index].SetAccount(sa);
					money = 0;
				}
				else {
					f[index].SetAccount(sa);
				}
			}
			f[index].MakeDepositToAccount(f[index].GetDeposit() + money, term_temp, interest_rate_temp, cur);
		}

		f[index + 1].SaveMoneyToFamilyAccount(f[index].GetFamilyAccount());     // C???p nh???t ti???n t??i kho???n gia ????nh cho th??ng sau
		f[index + 1].SetAccumulated(f[index].GetAccumulateForNextMonth());		// C???p nh???t ti???n t??ch l??y cho th??ng sau
		f[index + 1].SetAccount(f[index].GetAccount());                         // C???p nh???t c??c th??ng tin th??? ng??n h??ng cho th??ng sau
		Loan dD = f[index].GetDebts();
		dD.SetInterestRateD(dD.GetRatesD().back());
		f[index + 1].SetDebts(dD);											    // C???p nh???t c??c th??ng tin n??? cho th??ng sau
		index++;
		cur.IncreaseMonth();
	}
	fi.close();
}

void writeOneMonthFile(const char* fileName, int id) {
	fstream fo(fileName, ios::out);
	Date d(1, 5, 2022);
	for (int i = 1; i <= id; i++) d.IncreaseMonth();
	fo << "\n<< MONTHLY REVENUE AND EXPENDITURE STATISTICS - " << d.GetMonth() << '/' << d.GetYear() << " >>\n\n";

	fo << ">>> INCOME:\n ";
	fo << "Wife salary:," << f[id].GetWifeSalary() << ",(milion VND)\n";
	fo << "Husband salary:," << f[id].GetHusbandSalary() << ",(milion VND)\n";
	fo << "Other income:," << f[id].GetOtherIncome() << ",(milion VND)\n";
	double totalIncome = f[id].GetTotalSalary() + f[id].GetOtherIncome();
	fo << "    >Total income:," << totalIncome << ",(milion VND)\n";
	
	fo << "\n>>> EXPENSE:\n ";
	fo << "Bills:," << f[id].GetBills() << ",(milion VND)\n";
	fo << "Foods:," << f[id].GetFoodsExpense() << ",(milion VND)\n";
	fo << "Other expense:," << f[id].GetOtherExpense() << ",(milion VND)\n";
	double totalCost = f[id].GetTotalCost();
	fo << "    >Total expense:," << totalCost << ",(milion VND)\n";
	
	if (totalIncome > totalCost)
		fo << "\n,> In this month your family earned more than spent: " << totalIncome - totalCost << " (milion VND)\n\n\n";
	else
		fo << "\n,> In this month your family spent more than earned: " << totalCost - totalIncome << " (milion VND)\n\n\n";

	fo << "\n>>> DEPT:\n ";
	fo << "+ Debt 1:,(Dynamic Debt)," << f[id].GetDebts().GetTotalDebtD() << ", Due date:,"
		<< f[id].GetDebts().GetDueDateDebtD().GetMonth() << "/"
		<< f[id].GetDebts().GetDueDateDebtD().GetYear() << '\n';
	fo << "+ Debt 2:,(Static Debt)," << f[id].GetDebts().GetTotalDebtS() << ", Due date:,"
		<< f[id].GetDebts().GetDueDateDebtS().GetMonth()
		<< "/" << f[id].GetDebts().GetDueDateDebtS().GetYear() << '\n';
	
	int duration_d = f[id].GetDebts().GetDurationD();
	int duration_s = f[id].GetDebts().GetDurationS();
	double monthly_debt_d = f[id].GetDebts().GetTotalDebtD() / duration_d;
	double monthly_debt_s = f[id].GetDebts().GetTotalDebtS() / duration_s;
	fo << "\n    >,Estimated, 1st debt, per month, is:," << monthly_debt_d << '\n';
	fo << "    >,Estimated, 2nd debt, per month, is:," << monthly_debt_s << '\n';
	fo << "    >,Total, estimated, debts,per month, you have to, pay is:," << monthly_debt_s + monthly_debt_d << '\n\n';

	fo << "\n>>> SAVINGS ACCOUNTS:\n ";
	f[id].GetAccount().PrintBooksInformation(fo, d);
	fo << "Total current balance you have: " << f[id].GetAccount().GetTotalBalance(d) << endl;
	
	fo.close();
}

void writeAllMonthFile(const char* fileName) {
	fstream fo(fileName, ios::out);
	//  t??? t??? vi???t
	fo.close();
}

void writeDatabase(const char* fileName) {
	fstream fo(fileName, ios::out);

	//  Ghi th??ng tin n???
	Loan debt = f[0].GetDebts();
	fo << debt.GetDebtD() << ',';
	fo << debt.GetDurationD() << ',';
	fo << debt.GetDebtS() << ',';
	fo << debt.GetDurationS() << ',';
	fo << debt.GetRateS() << "\n";

	//  Ghi th??ng tin t???ng th??ng
	Date issue_date(1, 5, 2022);
	vector<double> rateD = f[index].GetDebts().GetRatesD();

	for (int i = 0; i <= index; i++) {
		fo << f[i].GetWifeSalary() << ',';
		fo << f[i].GetHusbandSalary() << ',';
		fo << f[i].GetOtherIncome() << ',';
		fo << f[i].GetBills() << ',';
		fo << f[i].GetFoodsExpense() << ',';
		fo << f[i].GetOtherExpense() << ',';
		
		SavingsBook sb = f[i].GetAccount().GetBook(issue_date);
		if (sb.GetInterestRate() != 0) fo << "1,"; else fo << "0,";
		fo << sb.GetTerm() << ',';
		fo << sb.GetInterestRate() << ',';
		
		fo << rateD[i] << ',';

		if (f[i].GetAccount().GetBook(issue_date).GetBalance(issue_date) - f[i].GetDeposit() > 0)
			fo << "1\n"; 
		else 
			fo << "0\n";

		issue_date.IncreaseMonth();
	}
	fo.close();
}

