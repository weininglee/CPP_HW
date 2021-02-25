#include<iostream>

using namespace std;

int main() {
	unsigned long long int x, y, z; // x = hour , y = min , z = sec
	while (cin >> z) {
		y = z / 60;
		x = y / 60;
		y = y % 60;
		z = z % 60;
		cout << x << " hours " << y << " minutes and " << z << " seconds" << endl;
	}
}
