#include "SavingsAccount.h"
SavingsAccount::SavingsAccount() {
	total_balance = 0;
	total_interest = 0;
}
SavingsAccount::~SavingsAccount() {
	book_list.clear();
}
double SavingsAccount::GetTotalBalance(Date cur) {
	RemoveSavingsBook(cur);
	return total_balance;
}
double SavingsAccount::GetTotalInterest(Date cur) {
	RemoveSavingsBook(cur);
	return total_interest;
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
bool SavingsAccount::RemoveSavingsBook(Date cur) {
	int count = 0;
	for (int i = 0; i < book_list.size(); i++) {
		if (book_list[i].IsDueDate(cur)) {
			total_balance += book_list[i].GetInterest(cur);	 //Lấy ra lãi của những sổ đã hết kỳ hạn
			total_interest += book_list[i].GetInterest(cur);
			book_list.erase(book_list.begin() + i);			 //Xóa sổ tiết kiệm
			count++;
			i--;
		}
	}
	return count == 0 ? false : true;						 //Kiểm tra tháng này có sổ nào hết kỳ hạn không
}
void SavingsAccount::PrintBooksInformation(Date cur) {
	for (int i = 0; i < book_list.size(); i++) {
		cout << i + 1 << "/ " << "balance : " << book_list[i].GetBalance(cur) << " ,term : " 
			 << book_list[i].GetTerm() << " (month)" << " interest rate: " << book_list[i].GetInterestRate() 
			 << " ,issued date: " << book_list[i].GetIssuedDate().GetMonth() << "/" << book_list[i].GetIssuedDate().GetYear() 
			 << " ,due date: " << book_list[i].GetDueDate().GetMonth() << "/" << book_list[i].GetDueDate().GetYear() << endl;
	}
}