#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double pi = 3.1415926535897;
	double r, sphere;
	while (cin >> r) {
		sphere = 4.0 / 3 * pi * r * r * r;
		cout << setprecision(6) << setiosflags(ios::fixed) << sphere << endl;
	}
}