#include "Header.h"

int main() {
	readDatabase("Database.csv");
	MainMenu();
	writeDatabase("Database.csv");
	//writeOneMonthFile("a.csv", 3);
	system("pause");
	return 0;
}