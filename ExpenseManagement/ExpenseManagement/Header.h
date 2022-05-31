#pragma once
#include <iostream>
#include <conio.h>
#include "Date.h"
#include "Family.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

bool nhapSoNguyen(int& n);
void MainMenu();
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void readDatabase(const char* fileName);
void writeOneMonthFile(const char* fileName, int id);
void writeAllMonthFile(const char* fileName); 
void writeDatabase(const char* fileName);
