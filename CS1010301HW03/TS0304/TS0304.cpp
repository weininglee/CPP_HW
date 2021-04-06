#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int Y;
	while (cin >> Y) {
		int n = (Y - 1900) / 10;
		double bit = pow(2, n + 2);
		int N = 0;
		double sum = 0;
		while (sum < bit) {
			sum += log2(++N);
		}
		cout << N - 1 << endl;
	}
}