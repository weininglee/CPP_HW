#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Month
{
public:
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);
	~Month();

	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	Month nextMonth();
private:
	int month = 1;
	string mon;
};

