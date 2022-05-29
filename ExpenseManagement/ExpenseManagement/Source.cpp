#include "Header.h"
#include "Family.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <iostream>
Date cur(1, 5, 2022);
vector<Family> f(100);
int index = 0;

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
	int select = 0;
	char ctmp;

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
			//Xuat file excel
			break;
		case 6: {
			f[index + 1].SaveMoneyToFamilyAccount(f[index].GetFamilyAccount());     //Cập nhật tiền tài khoản gia đình cho tháng sau
			f[index + 1].SetAccumulated(f[index].GetAccumulateForNextMonth());		//Cập nhật tiền tích lũy cho tháng sau
			f[index + 1].SetAccount(f[index].GetAccount());                         //Cập nhật các thông tin thẻ ngân hàng cho tháng sau
			f[index + 1].SetDebts(f[index].GetDebts());                             //Cập nhật các thông tin nợ cho tháng sau
			index++;
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
	int select = 0;
	int select2 = 0;
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

	//Yêu cầu người dùng có muốn gửi tiết kiệm ngân hàng
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
			f[index].MakeDepositToAccount(f[index].GetDeposit(), cur);
			cout << "Make deposit successfully" << endl;
		}
		else {
			cout << "You don't have enough money to make a deposit. Please go to Look up for details" << endl;
		}
	}
	else {
		f[index].SaveMoneyToFamilyAccount(f[index].GetDeposit());		//Người dùng không gửi vào ngân hàng thì đưa vào tk gia đình
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
		cout << "|| 2. Predict debt payment situation                               ||\n";
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
		//Xem tình hình thu - chi của tháng
		case 1: {
			f[index].PrintAllInformationInput(); 
			cout << "Total incomes you have " << f[index].GetAccumulated() + f[index].GetOtherIncome() << endl;
			cout << "Total expenses you pay " << f[index].GetTotalCost() << endl;

			if (f[index].GetDiffernceIncomeAndExpense() > 0) {
				cout << "This month, the incomes are more than the expenses, You get +" 
					 << f[index].GetDiffernceIncomeAndExpense() << endl;
			}
			else {
				if (f[index].GetTotalSalary() + f[index].GetOtherIncome() < f[index].GetTotalCost()) {
					cout << "The incomes are less than the expenses, You get " << f[index].GetDiffernceIncomeAndExpense() << endl;
					cout << "Warning! You don't have enough money to pay expenses, you go bankrupt!!!" << endl;
					break;
				}
				else {
					cout << "This month, the incomes are less than the expenses, You get " << f[index].GetDiffernceIncomeAndExpense() << endl;
					cout << "You need " << abs(f[index].GetDiffernceIncomeAndExpense()) << " more from Salary to pay expenses" << endl;
				}
			}
			break;
		}
		//Dự báo tình tình trả nợ dựa trên tháng mới nhất
		case 2: {
			int duration_d = f[index].GetDebts().GetDurationD();
			int duration_s = f[index].GetDebts().GetDurationS();
			double monthly_debt_d = f[index].GetDebts().GetTotalDebtD(cur) / duration_d;
			double monthly_debt_s = f[index].GetDebts().GetTotalDebtS(cur) / duration_s;
			Date due_date_debt_d = f[index].GetDebts().GetDueDateDebtD();
			Date due_date_debt_s = f[index].GetDebts().GetDueDateDebtS();
			double accumulate = f[index].GetAccumulateForNextMonth();
			/*double balance_bank = f[index].GetAccount().GetTotalBalance(cur);
			double balance_family = f[index].GetFamilyAccount();*/
			/*double total_month = accumulate + balance_bank + balance_family;*/
			double total_month = accumulate;
			cout << "Estimated 1st debt per month is: " << monthly_debt_d << endl;
			cout << "Estimated 2nd debt per month is: " << monthly_debt_s << endl;
			cout << "Total estimated debts per month you have to pay is: " << monthly_debt_s + monthly_debt_d << endl;
			if (f[index].GetTotalSalary() + f[index].GetOtherIncome() < f[index].GetTotalCost()) {
				cout << "Warning! You don't have enough money to pay expenses, you go bankrupt!!!" << endl;
				break;
			}
			else {
				/*cout << "Total accumalate for next month: " << accumulate << endl;
				cout << "Total balance in bank account: " << balance_bank << endl;
				cout << "Total balance in family account: " << balance_family << endl;*/
				cout << "Total amount of money you can have in this month to pay debts: " << total_month << endl;
				cout << "Prediction: " << endl;
				if (due_date_debt_d.Compare(due_date_debt_s) == -1) {
					//Dự doán nợ 1
					if (total_month >= monthly_debt_d) {
						cout << "You will have enough money to pay 1st debt on " << due_date_debt_d.GetMonth()
							<< "/" << due_date_debt_d.GetYear() << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total_month * duration_d - f[index].GetDebts().GetTotalDebtD(cur))
							<< " more to pay 1st debt on " << due_date_debt_d.GetMonth()
							<< "/" << due_date_debt_d.GetYear() << endl;
					}

					//Dự doán nợ 2
					if (total_month * duration_s 
						- (f[index].GetDebts().GetTotalDebtS(cur) + f[index].GetDebts().GetTotalDebtD(cur)) > 0) {
						cout << "You will have enough money to pay 2nd debt on " << due_date_debt_s.GetMonth()
							<< "/" << due_date_debt_s.GetYear() << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total_month * duration_s
							- (f[index].GetDebts().GetTotalDebtS(cur) + f[index].GetDebts().GetTotalDebtD(cur)))
							<< " more to pay 2nd debt on " << due_date_debt_s.GetMonth()
							<< "/" << due_date_debt_s.GetYear() << endl;
					}
				}
				else {
					//Dự doán nợ 1
					if (total_month >= monthly_debt_s) {
						cout << "You will have enough money to pay 2nd debt on " << due_date_debt_s.GetMonth()
							<< "/" << due_date_debt_s.GetYear() << endl;
					}
					else {
						cout << "Regretfully, You need " << abs((total_month - monthly_debt_s) * duration_s)
							<< " more to pay 2nd debt on " << due_date_debt_s.GetMonth()
							<< "/" << due_date_debt_s.GetYear() << endl;
					}

					//Dự doán nợ 2
					if (total_month * duration_d - (monthly_debt_d + monthly_debt_s) > 0) {
						cout << "You will have enough money to pay 1st debt on " << due_date_debt_d.GetMonth()
							<< "/" << due_date_debt_d.GetYear() << endl;
					}
					else {
						cout << "Regretfully, You need " << abs(total_month * duration_d - (monthly_debt_d + monthly_debt_s))
							<< " more to pay 1st debt on " << due_date_debt_d.GetMonth()
							<< "/" << due_date_debt_d.GetYear() << endl;
					}
				}
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
			cout << "Debt 1: " << f[index].GetDebts().GetTotalDebtD(cur) << ", due date: " << due_date_d.GetMonth() << "/" << due_date_d.GetYear() << endl;
			cout << "Debt 2: " << f[index].GetDebts().GetTotalDebtS(cur) << ", due date: " << due_date_s.GetMonth() << "/" << due_date_s.GetYear() << endl;
			break;
		}
		case 2:
			f[index].GetAccount().PrintBooksInformation(cur);
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