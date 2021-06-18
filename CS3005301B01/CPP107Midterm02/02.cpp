#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
        int gcd = 1;
        for (int i = 2; i <= std::min(a, b); ++i) {
            if (0 == a % i && 0 == b % i) {
                gcd = i;
            }
        }
        cout << gcd << endl;
	}
}