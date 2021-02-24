#include<iostream>

using namespace std;

int main() {
	long long int x, y, z; // x = hour , y = 
	cin >> z;
	y = z / 60;
	x = y / 60;
	y = y % 60;
	z = z % 60;
	cout << x << " hours " << y << " minutes and " << z << " seconds ";
}