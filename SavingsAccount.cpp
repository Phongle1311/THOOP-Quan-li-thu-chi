#include "SavingsAccount.h"
SavingsAccount::SavingsAccount() {
	total_balance = 0;
	total_interest = 0;
}
SavingsAccount::~SavingsAccount() {
	book_list.clear();
}
double SavingsAccount::GetTotalBalance(Date cur) {
	UpdateStatusSavingsBook(cur);
	return total_balance;
}
double SavingsAccount::GetTotalInterest(Date cur) {
	UpdateStatusSavingsBook(cur);
	return total_interest;
}
int SavingsAccount::GetNumberBooks() {
	return book_list.size();
}
SavingsBook SavingsAccount::GetBook(int index) {
	if (index < book_list.size())
		return book_list[index];
	return book_list.back();
}
SavingsBook SavingsAccount::GetBook(Date issued_date) {
	SavingsBook sb;
	for (int i = 0; i < book_list.size(); i++) {
		if (book_list[i].GetIssuedDate().Compare(issued_date) == 0) {
			return book_list[i];
		}
	}
	return sb;
}
bool SavingsAccount::AddSavingsBook(double money, Date cur) {
	SavingsBook book;
	book.MakeDeposit(money);
	book.TermInput();
	book.InterestInput();
	book.SetIssuedDate(cur);
	book_list.push_back(book);
	total_balance += money;									 //Lúc này chưa có lãi, nên chỉ cộng thêm tiền gốc 
	return true;
}
bool SavingsAccount::AddSavingsBook(double money, int term, double interest_rate, Date cur) {
	SavingsBook book;
	book.MakeDeposit(money);
	book.SetTerm(term);
	book.SetInterestRate(interest_rate);
	book.SetIssuedDate(cur);
	book_list.push_back(book);
	total_balance += money;
	return true;
}
void SavingsAccount::UpdateStatusSavingsBook(Date cur) {
	for (int i = 0; i < book_list.size(); i++) {
		if (book_list[i].IsDueDate(cur)) {
			total_balance += book_list[i].GetInterest(cur);	 //Lấy ra lãi của những sổ đã hết kỳ hạn
			total_interest += book_list[i].GetInterest(cur);
		}
	}
}
bool SavingsAccount::RemoveSavingsBook(Date cur) {
	int count = 0;
	for (int i = 0; i < book_list.size(); i++) {
		if (book_list[i].IsDueDate(cur)) {
			total_balance -= book_list[i].GetPrincipal();
			book_list.erase(book_list.begin() + i);			 //Xóa sổ tiết kiệm
			count++;
			i--;
		}
	}
	return count == 0 ? false : true;						 //Kiểm tra tháng này có sổ nào hết kỳ hạn không
}

void SavingsAccount::PrintBooksInformation(ostream& out, Date cur) {
	for (int i = 0; i < book_list.size(); i++) {
		out << i + 1 << "/ " << "balance: " << book_list[i].GetBalance(cur) << ", term: "
			<< book_list[i].GetTerm() << " (month)" << " interest rate: " << book_list[i].GetInterestRate()
			<< ", issued date: " << book_list[i].GetIssuedDate().GetMonth() << "/" << book_list[i].GetIssuedDate().GetYear()
			<< ", due date: " << book_list[i].GetDueDate().GetMonth() << "/" << book_list[i].GetDueDate().GetYear()
			<< ", expect: " << book_list[i].GetPrincipal() + book_list[i].GetPrincipal()
			* book_list[i].GetInterestRate() * book_list[i].GetTerm() << endl;
	}
}