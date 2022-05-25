#include "SavingsAccount.h"
SavingsAccount::SavingsAccount() {
	total_balance = 0;
}
SavingsAccount::~SavingsAccount() {
	book_list.clear();
}
double SavingsAccount::GetTotalBalance() {
	return total_balance;
}
bool SavingsAccount::AddSavingsBook(SavingsBook book, double money) {
	book.MakeDeposit(money);
	book.TermInput();
	book.InterestInput();
	book.SetIssuedDate(Date::Current());
	book_list.push_back(book);
	total_balance += money;									// Lúc này chưa có lãi, nên chỉ cộng thêm tiền gốc 
	return true;
}
bool SavingsAccount::RemoveSavingsBook() {
	int count = 0;
	for (int i = 0; i < book_list.size(); i++) {
		if (book_list[i].IsDueDate()) {
			total_balance += book_list[i].GetInterest();	// Lấy ra lãi của những sổ đã hết kỳ hạn
			book_list.erase(book_list.begin() + i);			// Xóa sổ tiết kiệm
			count++;
			i--;
		}
	}
	return count == 0 ? false : true;						//Kiểm tra tháng này có sổ nào hết kỳ hạn không
}
