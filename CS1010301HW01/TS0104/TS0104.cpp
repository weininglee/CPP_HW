#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	string x;
	while (cin >> x) {
		cout << setw(10) << x << endl;
	}
}