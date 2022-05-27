#include "Header.h"
#include "Family.h"
Date cur(1, 5, 2022);
Family f;

bool nhapSoNguyen(int& n) {
	n = 0;
	string s;
	cin >> s;

	//Bo qua cac khoang cach dau va cuoi string
	int i = 0, j = s.size() - 1;
	while (s[i] == ' ') i++;
	while (s[j] == ' ') j--;

	//Kiem tra dau am duong
	bool am = 0;
	if (s[i] != ' ') {
		if (s[i] == '-') am = 1, i++;
		else if (s[i] == '+') i++;
	}

	//Duyet string tach lay so
	while (i <= j) {
		if (s[i] < '0' || s[i]>'9') return 0;
		else n = n * 10 + s[i] - '0';
		i++;
	}

	if (am) n = -n;
	return 1;
}

void MainMenu() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================|| \n";
		cout << "||                    Expense Management Project                   ||\n";
		cout << "|| 1. Manage income                                                ||\n";
		cout << "|| 2. Manage expenses                                              ||\n";
		cout << "|| 3. Manage loan                                                  ||\n";
		cout << "|| 4. Look up                                                      ||\n";
		cout << "|| 5. Bank                                                         ||\n";
		cout << "|| 6. Export to file excel                                         ||\n";
		cout << "|| 7. Move to next month                                           ||\n";
		cout << "|| 0. Exit                                                         ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 7) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
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
			Menu5();
			break;
		case 6:
			//Xuat file excel
			break;
		case 7: {
			ExpenseManagement em = f.GetExpenseManagement();
			em.SetRemainingMoneyFromBeforeMonths(em.GetRemainingMoneyInMonth());
			f.SetExpenseManagement(em);
			int new_month = cur.GetMonth() + 1;
			if (new_month > 12) {
				cur.Update(1, new_month - 12, cur.GetYear() + 1);
			}
			else {
				cur.Update(1, new_month, cur.GetYear());
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

void Menu1() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                            MANAGE INCOME                        ||\n";
		cout << "|| 1. Enter wife salary                                            ||\n";
		cout << "|| 2. Enter husband salary                                         ||\n";
		cout << "|| 3. Enter other income                                           ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 4) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1:
			f.WifeSalaryInput();
			break;
		case 2:
			f.HusbandSalaryInput();
			break;
		case 3:
			f.OtherIncomeInput();
			break;
		default:

			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
}

void Menu2() {
	int chon = 0;
	int chon2 = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                            MANAGE EXPENSES                      ||\n";
		cout << "|| 1. Enter expense                                                ||\n";
		cout << "|| 2. Enter costs incurred                                         ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 3) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1:
			f.ExpenseInput();
			break;
		case 2:
			f.CostsIncurredInput();
			break;
		default:

			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
	cout << "Do you want to make deposit into a book?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Select: ";
	bool c = nhapSoNguyen(chon2);
	while (!c || chon2 < 1 || chon2 > 2) {
		if (!c)  cout << "Wrong format, try again: ";
		else cout << "Limit exceeded, try again: ";
		c = nhapSoNguyen(chon2);
	}
	if (chon2 == 1) {
		if (f.GetDeposit() > 0) {
			f.MakeDepositToAccount(f.GetDeposit(), cur);
			cout << "Make deposit successfully" << endl;
		}
		else {
			cout << "You don't have enough money to make a deposit" << endl;
		}
	}
	else {
		ExpenseManagement manage = f.GetExpenseManagement();
		manage.SetRemainingMoneyInMonth(f.GetDeposit() + f.GetExpenseManagement().GetRemainingMoneyInMonth());
		f.SetExpenseManagement(manage);
		cout << "Make deposit unsuccessfully" << endl;
	}
}
void Menu3() {
	int chon = 0;
	char ctmp;
	Loan debt = f.GetExpenseManagement().GetDebt();

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                            MANAGE LOAN                          ||\n";
		cout << "|| 1. Enter 1st loan (fixed interest, just enter at the firt time) ||\n";
		cout << "|| 2. Enter 2nd loan (dynamic interst)                             ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 2) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1:
			debt.EnterInforDebtS();
			break;
		case 2:
			debt.EnterInforDebtD();
			debt.EnterInterRateDebtD();
			break;
		default:
			break;
		}
		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
	ExpenseManagement manage = f.GetExpenseManagement();
	manage.SetDebt(debt);
	f.SetExpenseManagement(manage);
}

void Menu4() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "Time: " << cur.GetMonth() << "/" << cur.GetYear() << endl;
		cout << "||================================MENU=============================||\n";
		cout << "||                               LOOK UP                           ||\n";
		cout << "|| 1. Look up the lastest month                                    ||\n";
		cout << "|| 2. Predict debt payment situation                               ||\n";
		cout << "|| 0. Return to main screen                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Select: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 3) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1: {
			cout << "Total income in this month: " << f.GetTotalIncome() << " million (vnd)" << endl;
			cout << "Total cost in this month: " << f.GetTotalCost() << " million (vnd)" << endl;
			cout << "Extra amount you have from months ago: " << f.GetExpenseManagement().GetRemainingMoneyFromBeforeMonths() << " million (vnd)" << endl;
			cout << "Total interest from your books: " << f.GetAccount().GetTotalInterest(cur) << " million (vnd)" << endl;
			double money = f.GetTotalIncome() + f.GetExpenseManagement().GetRemainingMoneyFromBeforeMonths() + f.GetAccount().GetTotalInterest(cur) - f.GetTotalCost();
			if (money > 0) {
				cout << "You earn: +" << money << " million (vnd) in this month" << endl;
				cout << "You accumulate: +" << f.GetExpenseManagement().GetRemainingMoneyInMonth() << " million (vnd) in a next month" << endl;
			}
			else {
				cout << "You have negative money in this month, you go bankrupt!!!" << endl;
			}
			break;
		}
		case 2:
			break;
		default:
			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
}

void Menu5() {
	int chon = 0;
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

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 4) {
			if (!b)  cout << "Wrong format, try again: ";
			else cout << "Limit exceeded, try again: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1: {
			Date due_date1 = f.GetExpenseManagement().GetDebt().GetDueDateDebtS();
			Date due_date2 = f.GetExpenseManagement().GetDebt().GetDueDateDebtD();
			cout << "You have 2 debts: " << endl;
			cout << "Debt 1: " << f.GetExpenseManagement().GetDebt().GetTotalDebtS(due_date1) << "(milion vnd), due date: " << due_date1.GetMonth() << "/" << due_date1.GetYear() << endl;
			cout << "Debt 2: " << f.GetExpenseManagement().GetDebt().GetTotalDebtD1(due_date2) << "(milion vnd), due date: " << due_date2.GetMonth() << "/" << due_date2.GetYear() << endl;
			break;
		}
		case 2:
			f.GetAccount().PrintBooksInformation(cur);
			break;
		case 3:
			cout << "Total current balance you have: " << f.GetAccount().GetTotalBalance(cur) << " (milion vnd)" << endl;
			break;
		default:
			break;
		}

		std::cout << "Press any key to return!\n";
		ctmp = _getch();
	}
}