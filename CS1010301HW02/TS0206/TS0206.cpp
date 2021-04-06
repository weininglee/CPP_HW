#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double income;
	while (cin >> income) {
		double tax = 0.0;
		if (income <= 750 && income >= 0) {
			tax += income * 0.01;
		}
		else if (income <= 2250) {
			tax = 7.5 + (income - 750) * 0.02;
		}
		else if (income <= 3750) {
			tax = 37.5 + (income - 2250) * 0.03;
		}
		else if (income <= 5250) {
			tax = 82.5 + (income - 3750) * 0.04;
		}
		else if (income <= 7000) {
			tax = 142.5 + (income - 5250) * 0.05;
		}
		else {
			tax = 230 + (income - 7000) * 0.06;
		}
		cout << setprecision(2) << fixed << tax << endl;
	}	
}