#include "Header.h"

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
		cout << "|| 3. Tra cuu thu chi                                              ||\n";
		cout << "|| 4. Tai khoan ngan hang                                          ||\n";
		cout << "|| 5. Xuat file excel                                              ||\n";
		cout << "|| 0. Thoat                                                        ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon! ";

		bool b = nhapSoNguyen(chon);
		while (!b || chon < 0 || chon > 5) {
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
		cout << "|| 3. Thu nhap chung                                               ||\n";
		cout << "|| 4. Thu nhap khac                                                ||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon! ";

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
			
			break;
		case 2:

			break;
		case 3:

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
	char ctmp;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                            QUAN LY CHI                          ||\n";
		cout << "|| 1. Nhap tien dien                                               ||\n";
		cout << "|| 2. Nhap tien nuoc                                               ||\n";
		cout << "|| 3. Nhap chi tieu khac                                           ||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon! ";

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

			break;
		case 2:

			break;
		default:

			break;
		}

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}

void Menu3() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                          TRA CUU THU CHI                        ||\n";
		cout << "|| 1. Tong tien mat hien co                                        ||\n";
		cout << "|| 2. Tra cuu thu chi theo thang                                   ||\n";
		cout << "|| 3. Tra cuu tong thu chi                                         ||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon! ";

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

			break;
		case 2:

			break;
		default:

			break;
		}

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}

void Menu4() {
	int chon = 0;
	char ctmp;

	while (true) {
		system("cls");
		cout << "||================================MENU=============================||\n";
		cout << "||                          NGAN HANG                              ||\n";
		cout << "|| 1. Xem tinh trang so no                                         ||\n";
		cout << "|| 2. Xem tinh trang so tiet kiem                                  ||\n";
		cout << "|| 3. Tra cuu tong tai khoan                                       ||\n";
		cout << "|| 4. Lich su giao dich                                            ||\n";
		cout << "|| 0. Quay ve man hinh chinh                                       ||\n";
		cout << "||=================================o0o=============================||\n";
		cout << "Moi ban lua chon! ";

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

			break;
		case 2:

			break;
		default:

			break;
		}

		std::cout << "Nhan phim bat ki de tro ve!\n";
		ctmp = _getch();
	}
}