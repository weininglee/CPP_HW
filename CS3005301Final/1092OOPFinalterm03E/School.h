#pragma once
#include <iostream>
#include <string>
using namespace std;

class School {
public:
	string name;
	int studentNumber;
	int studentNumberNextYear;

	School() {
		studentNumber = 0;
		studentNumberNextYear = 0;
	}

	School(string name, float amount) {
		this->name = name;
		studentNumber = amount;
		studentNumberNextYear = amount;
	}

	void admissions(float number) {
		if (number >= 0) {
			studentNumber += number;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	void dropouts(float number) {
		if (number <= studentNumber) {
			studentNumber -= number;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	void transfer(float number, School& toSchool) {
		if (studentNumber >= number) {
			studentNumber -= number;
			toSchool.admissions(number);
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	friend ostream& operator<<(ostream& out, School o) {
		out << o.name << "\t" << o.studentNumber << "\t" << o.studentNumberNextYear;
		return out;
	}
};

class PrivateSchool : public School {
public:
	PrivateSchool(string name, float amount) {
		this->name = name;
		studentNumber = amount;
		studentNumberNextYear = amount;
	}

	void dropouts(float number) {
		if (studentNumber >= number) {
			if (dropstime != 0) {
				studentNumberNextYear -= 100;
			}
			studentNumber -= number;
			dropstime++;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	void transfer(float number, School& toSchool) {
		if (studentNumber >= number) {
			if (dropstime != 0) {
				studentNumberNextYear -= 100;
			}
			studentNumber -= number;
			dropstime++;
			toSchool.admissions(number);
		}
		else {
			cout << "ERROR" << endl;
		}
	}

private:
	int dropstime = 0;
};

class PublicSchool : public School {
public:
	PublicSchool(string name, float amount) {
		this->name = name;
		studentNumber = amount;
		studentNumberNextYear = amount;
	}

	void dropouts(float number) {
		if (studentNumber >= number) {
			if (number > 100) {
				studentNumberNextYear -= studentNumberNextYear * 0.05;
			}
			studentNumber -= number;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	void transfer(float number, School& toSchool) {
		if (studentNumber >= number) {
			if (number > 100) {
				studentNumberNextYear -= studentNumberNextYear * 0.05;
			}
			studentNumber -= number;
			toSchool.admissions(number);
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	void apply_growth() {
		studentNumberNextYear += growing_rate * studentNumberNextYear;
	}

private:
	double growing_rate = 0.05;
};