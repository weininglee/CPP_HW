#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		int dia;
		if (a > b) {
			dia = a - b;
		}
		else {
			dia = b - a;
		}
		int max = 0;
		int n = 0;
		if (a > b)
			n = b;
		else 
			n = a;
		for (int i = 0; i < dia + 1; i++) {
			int count = 1,num = i + n;
			//cout << num << endl;
			while (num != 1) {
				if (num % 2 == 0) {
					num /= 2;
				}
				else {
					num = num * 3 + 1;
				}
				count++;
			}
			//cout << count;
			if (count > max)
				max = count;
		}
		cout << a << " " << b << " " << max << endl;
	}
}