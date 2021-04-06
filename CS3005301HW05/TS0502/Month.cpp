#include "Month.h"


Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	mon.push_back(first);
	mon.push_back(second);
	mon.push_back(third);
	if (mon.compare("Jan") == 0) {
		month = 1;
	}
	else if (mon.compare("Feb") == 0) {
		month = 2;
	}
	else if (mon.compare("Mar") == 0) {
		month = 3;
	}
	else if (mon.compare("Apr") == 0) {
		month = 4;
	}
	else if (mon.compare("May") == 0) {
		month = 5;
	}
	else if (mon.compare("Jun") == 0) {
		month = 6;
	}
	else if (mon.compare("Jul") == 0) {
		month = 7;
	}
	else if (mon.compare("Aug") == 0) {
		month = 8;
	}
	else if (mon.compare("Sep") == 0) {
		month = 9;
	}
	else if (mon.compare("Oct") == 0) {
		month = 10;
	}
	else if (mon.compare("Nov") == 0) {
		month = 11;
	}
	else if (mon.compare("Dec") == 0) {
		month = 12;
	}
	else
		month = 1;
}

Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt>12)
		month = 1;
	else
		month = monthInt;
}


Month::~Month()
{
}

void Month::inputInt()
{
	cin >> month;
	if (month < 1 || month>12)
		month = 1;
}

void Month::inputStr()
{
	char m;
	for (int i = 0; i < 3; i++) {
		cin >> m;
		mon.push_back(m);
	}
	if (mon.compare("Jan") == 0) {
		month = 1;
	}
	else if (mon.compare("Feb") == 0) {
		month = 2;
	}
	else if (mon.compare("Mar") == 0) {
		month = 3;
	}
	else if (mon.compare("Apr") == 0) {
		month = 4;
	}
	else if (mon.compare("May") == 0) {
		month = 5;
	}
	else if (mon.compare("Jun") == 0) {
		month = 6;
	}
	else if (mon.compare("Jul") == 0) {
		month = 7;
	}
	else if (mon.compare("Aug") == 0) {
		month = 8;
	}
	else if (mon.compare("Sep") == 0) {
		month = 9;
	}
	else if (mon.compare("Oct") == 0) {
		month = 10;
	}
	else if (mon.compare("Nov") == 0) {
		month = 11;
	}
	else if (mon.compare("Dec") == 0) {
		month = 12;
	}
	else
		month = 1;
}

void Month::outputInt()
{
	cout << month;
}

void Month::outputStr()
{
	if (mon.compare("Jan") == 0 || month == 1) {
		month = 1;
		mon = "Jan";
	}
	else if (mon.compare("Feb") == 0 || month == 2) {
		month = 2;
		mon = "Feb";
	}
	else if (mon.compare("Mar") == 0 || month == 3) {
		month = 3;
		mon = "Mar";
	}
	else if (mon.compare("Apr") == 0 || month == 4) {
		month = 4;
		mon = "Apr";
	}
	else if (mon.compare("May") == 0 || month == 5) {
		month = 5;
		mon = "May";
	}
	else if (mon.compare("Jun") == 0 || month == 6) {
		month = 6;
		mon = "Jun";
	}
	else if (mon.compare("Jul") == 0 || month == 7) {
		month = 7;
		mon = "Jul";
	}
	else if (mon.compare("Aug") == 0 || month == 8) {
		month = 8;
		mon = "Aug";
	}
	else if (mon.compare("Sep") == 0 || month == 9) {
		month = 9;
		mon = "Sep";
	}
	else if (mon.compare("Oct") == 0 || month == 10) {
		month = 10;
		mon = "Oct";
	}
	else if (mon.compare("Nov") == 0|| month == 11) {
		month = 11;
		mon = "Nov";
	}
	else if (mon.compare("Dec") == 0|| month == 12) {
		month = 12;
		mon = "Dec";
	}
	else {
		month = 1;
		mon = "Jan";
	}
	cout << mon;
}

Month Month::nextMonth()
{
	int next = month + 1;
	return next;
}
