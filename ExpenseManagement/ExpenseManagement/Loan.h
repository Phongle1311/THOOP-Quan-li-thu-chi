#pragma once
#include "Date.h"
#include <vector>
#include <iostream>
using namespace std;

class Loan {
private:
	//START_DAY là biến thời điểm bắt đầu (1/5/2022)
	Date START_DAY;
	//debtD là nợ gốc của lãi nợ linh động (thay đổi theo tháng)
	double debtD;
	//durationD là kì hạn của loại nợ linh động (tính bằng tháng)
	int durationD;
	//mỗi phần tử trong vector interestRateD là lãi xuất (lãi/tháng) của nợ linh động theo từng tháng
	vector<double> interestRateD;
	//debtS là nợ gốc của loại nợ cố định
	double debtS;
	//durationS là kì hạn của loại nợ cố định (tính bằng tháng)
	int durationS;
	//interestRateS là lãi xuất (lãi/tháng) của loại nợ cố định
	double interestRateS;
public:
	//Hàm khởi tạo mặc định
	Loan();
	//Hàm khởi tạo đầy đủ tham số
	Loan(double debtS, double durationS, double interestRateS, double debtD, double durationD);

	//Hàm nhập thông tin (nợ gốc, kì hạn, lãi xuất (lãi/tháng)) cho lãi cố định
	void EnterInforDebtS();
	//Hàm nhập thông tin (nợ gốc, kì hạn) cho lãi linh động
	void EnterInforDebtD();
	//Hàm nhập lãi xuất (lãi/tháng) cho lãi linh động (mỗi tháng gọi hàm 1 lần)
	void EnterInterRateDebtD();

	//Lấy ra nợ (cố định) phải trả trong tháng này
	double GetTotalDebtS(Date cur);
	//Lấy ra nợ (linh động) phải trả trong tháng này
	double GetTotalDebtD1(Date cur);
	//Lấy ra nợ (linh động) ước tính dựa vào tháng mới nhất 
	double GetTotalDebtD2(Date cur);
	//Lấy ra kì hạn nợ (cố định)
	int GetDurationS();
	//Lấy ra kì hạn nợ (linh động)
	int GetDurationD();
	//Lấy ra tổng tiền lãi nợ (cố định)
	double GetInterRateS(Date cur);
	//Lấy ra tổng tiền lãi nợ (linh động)
	double GetInterRateD1(Date cur);

	//Lấy ra ngày đảo hạn của nợ linh động
	Date GetDueDateDebtD();
	//Lấy ra ngày đảo hạn của nợ cố định
	Date GetDueDateDebtS();
};