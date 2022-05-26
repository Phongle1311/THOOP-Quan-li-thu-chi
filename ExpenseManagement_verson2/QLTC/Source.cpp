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
		cout << "||================================MENU=============================||\n";
		cout << "||                    DO AN QUAN LY THU CHI GIA DINH               ||\n";
		cout << "|| 1. Quan ly thu nhap                                             ||\n";
		cout << "|| 2. Quan ly chi tieu                                             ||\n";
		cout << "|| 3. Quan ly chi no                                               ||\n";
		cout << "|| 4. Tra cuu thu chi                                              ||\n";
		cout << "|| 5. Tai khoan ngan hang                                          ||\n";
		cout << "|| 6. Xuat file excel                                              ||\n";
		cout << "|| 0. Thoat                                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 6) {
			if (!b)  cout << "Sai dinh dang, moi nhap lai: ";
			else cout << "Vuot qua gioi han, moi nhap lai: ";
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
		default:
			//Xuat file excel
			break;
		}

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}

void Menu1() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                            QUAN LY THU                          ||\n";
		cout << "|| 1. Nhap luong vo                                                ||\n";
		cout << "|| 2. Nhap luong chong                                             ||\n";
		cout << "|| 3. Thu nhap khac												||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 4) {
			if (!b)  cout << "Sai dinh dang, moi nhap lai: ";
			else cout << "Vuot qua gioi han, moi nhap lai: ";
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

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}

void Menu2() {
	int chon = 0;
	int chon2 = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                            QUAN LY CHI                          ||\n";
		cout << "|| 1. Nhap chi tieu												||\n";
		cout << "|| 2. Nhap chi phi phat sinh                                       ||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 3) {
			if (!b)  cout << "Sai dinh dang, moi nhap lai: ";
			else cout << "Vuot qua gioi han, moi nhap lai: ";
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
	
		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
	cout << "Do you want to make deposit into a book?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Select: ";
	bool c = nhapSoNguyen(chon2);
	while (!c || chon2 < 1 || chon2 > 2) {
		if (!c)  cout << "Sai dinh dang, moi nhap lai: ";
		else cout << "Vuot qua gioi han, moi nhap lai: ";
		c = nhapSoNguyen(chon2);
	}
	if (c == 1) {
		f.MakeDepositToAccount(f.GetDeposit(), cur);
		cout << "Make deposit successfully" << endl;
	}
	else {
		cout << "Make deposit unsuccessfully" << endl;
	}
}
void Menu3() {
	int chon = 0;
	char ctmp;
	Loan debt;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                            QUAN LY NO							||\n";
		cout << "|| 1. Nhap no 1													||\n";
		cout << "|| 2. Nhap no 2													||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 2) {
			if (!b)  cout << "Sai dinh dang, moi nhap lai: ";
			else cout << "Vuot qua gioi han, moi nhap lai: ";
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
		std::cout << "Nhan phim bat ki de tro ve!\n";
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
		cout << "||================================MENU=============================||\n";
		cout << "||                          TRA CUU THU CHI                        ||\n";
		cout << "|| 1. Tra cuu thang moi nhat										||\n";
		cout << "|| 2. Du doan														||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 3) {
			if (!b)  cout << "Sai dinh dang, moi nhap lai: ";
			else cout << "Vuot qua gioi han, moi nhap lai: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1: {
			cout << "Tong tien thu: " << f.GetTotalIncome()<<" trieu (vnd)" << endl;
			cout << "Tong tien chi: " << f.GetTotalCost() << " trieu (vnd)" << endl;
			double money = f.GetTotalIncome() - f.GetTotalCost();
			if (money > 0) {
				cout << "Thang nay kiem duoc: +" << money << " trieu (vnd)" << endl;
			}
			else {
				cout << "Thang nay bi am tien" << endl;
			}
			break;
		}
		case 2:
			break;
		default:
			break;
		}

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}

void Menu5() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                          NGAN HANG                              ||\n";
		cout << "|| 1. Xem tinh trang so no                                         ||\n";
		cout << "|| 2. Xem tinh trang so tiet kiem                                  ||\n";
		cout << "|| 3. Tra cuu tong tai khoan                                       ||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon: ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 4) {
			if (!b)  cout << "Sai dinh dang, moi nhap lai: ";
			else cout << "Vuot qua gioi han, moi nhap lai: ";
			b = nhapSoNguyen(chon);
		}
		if (chon == 0) break;

		system("cls");
		switch (chon)
		{
		case 1: {
			Date due_date1 = f.GetExpenseManagement().GetDebt().GetDueDateDebtS();
			Date due_date2 = f.GetExpenseManagement().GetDebt().GetDueDateDebtD();
			cout << "Ban co 2 khoan no: " << endl;
			cout << "No 1: " << f.GetExpenseManagement().GetDebt().GetTotalDebtS(due_date1) << "(trieu vnd), ngay dao han: " << due_date1.GetMonth() << "/" << due_date1.GetYear() << endl;
			cout << "No 2: " << f.GetExpenseManagement().GetDebt().GetTotalDebtD1(due_date2) << "(trieu vnd), ngay dao han: " << due_date2.GetMonth() << "/" << due_date2.GetYear() << endl;
			break;
		}
		case 2:
			f.GetAccount().PrintBooksInformation(cur);
			break;
		case 3:
			cout << "Tong so du trong tai khoan hien co la: " << f.GetAccount().GetTotalBalance() << " (trieu vnd)" << endl;
			break;
		default:
			break;
		}

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}