#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	double n, r, guess;
	cin >> n;
	guess = n / 2;
	r = n / guess;
	guess = (guess + r) / 2;
	do {
		r = n / guess;
		guess = (guess + r) / 2;
	} while (guess - r > 0.01);
	/*cout << setprecision(2) << guess;*/
	cout << setprecision(2) << setiosflags(ios::fixed) << guess;
}