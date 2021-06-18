#pragma once
#include <iostream>
using namespace std;

class School {
protected:
	string name;
	int studentAmount;
	int studentAmountNextYear;
public:
	School(){ 
		name = "";
		studentAmount = 0;
		studentAmountNextYear = 0;
	}
	School(string name, int studentAmount) {
		this->name = name;
		this->studentAmount = studentAmount;
		studentAmountNextYear = studentAmount;
	}

	void admissions(float amount) {
		studentAmount += amount;
	}
	void dropouts(float amount) {
		if(studentAmount >= amount) studentAmount -= amount;
	}
	void transfer(float amount, School& toSchool) {
		if (studentAmount >= amount) {
			studentAmount -= amount;
			toSchool.admissions(amount);
		}
	}

	friend ostream& operator<<(ostream& os,School output) {
		os << output.name << "\t" << output.studentAmount << "\t" << output.studentAmountNextYear;
		return os;
	}
};

class PrivateSchool : public School {
public:
	PrivateSchool() : School() {}
	PrivateSchool(string name, int studentAmount) : School(name, studentAmount) {}

	void dropouts(float amount) {
		if (studentAmount >= amount) {
			studentAmount -= amount;
			if (dropoutTime > 0)studentAmountNextYear -= 100;
			dropoutTime++;
		}
	}
	void transfer(float amount, School& toSchool) {
		if (studentAmount >= amount) {
			dropouts(amount);
			toSchool.admissions(amount);
		}
	}

private:
	int dropoutTime = 0;
};

class PublicSchool : public School {
public:
	PublicSchool() : School() {}
	PublicSchool(string name, int studentAmount) : School(name, studentAmount) {}

	void dropouts(float amount) {
		if (studentAmount >= amount) {
			studentAmount -= amount;
			if (amount > 100) studentAmountNextYear -= (studentAmountNextYear * 0.05);
		}
	}
	void transfer(float amount, School& toSchool) {
		if (studentAmount >= amount) {
			dropouts(amount);
			toSchool.admissions(amount);
		}
	}
	void apply_growth() {
		studentAmountNextYear += growing_rate * studentAmountNextYear;
	}

private:
	float growing_rate = 0.05;
};