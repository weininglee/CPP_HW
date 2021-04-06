#include "Fraction.h"

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	long double ans = (long double)numerator / denominator;
	if (numerator == 0) {
		cout << 0 << endl;
	}
	else if (ans == numerator / denominator) {
		cout << numerator / denominator << endl;
	}
	else {
		cout << fixed << setprecision(6) << ans << endl;
	}
}

void Fraction::outputReducedFraction()
{
	int a = numerator, b = denominator;
	int temp = 1;
	while (temp != 0) {
		temp = a % b;
		a = b; 
		b = temp;
	}
	temp = a;
	double ans = (double)numerator / denominator;
	if (numerator == 0) {
		cout << 0 << endl;
	}
	else if (ans == numerator / denominator) {
		cout << numerator / denominator << endl;
	}
	else {
		cout << numerator / temp << "/" << denominator / temp << endl;
	}
}



