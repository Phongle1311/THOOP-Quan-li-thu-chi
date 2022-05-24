#include "ExpenseManagement.h"
ExpenseManagement::ExpenseManagement() {
  acummulated=0;
  start_date=0;
  finish_date=0;
}
ExpenseManagement::ExpenseManagement(double acummulated, double debt, string start_date, string finish_date) {
  this->acummulated=acummulated;
  this->debt=debt;
  this->start_date=start_date;
  this->finish_date=finish_date;
}
double ExpenseManagement::GetAcummulatedMoney() {
  return acummulated;
}
ExpenseManagement::~ExpenseManagement() {
  delete[] debt;
}
