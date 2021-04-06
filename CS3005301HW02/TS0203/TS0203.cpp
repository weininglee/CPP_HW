#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string sentence;
	while (cin >> sentence) {
		size_t len = sentence.length();
		double wide = ceil(sqrt(len));
		for (int i = 0; i < wide; i++) {
			for (int j = 0; j < len; j++) {
				if (j % static_cast<int> (wide) == i) {
					cout << sentence[j];
				}
			}
			cout << endl;
		}
	}
}