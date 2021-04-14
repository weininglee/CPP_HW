#include <iostream>
#include <vector>
#include "VecNf.h"
using namespace std;

void doNothing(VecNf tar) { return; }

int main() {
	VecNf empty;
	float a_value[] = { 3.0, 2.0 };
	float b_value[] = { 3, 5, 2 };
	float c_value[] = { -1, -1, 0 };
	VecNf A(a_value, 2);
	VecNf B(b_value, 3);
	VecNf C(c_value, 3);
	VecNf T;
	T = A; // Assignment
	for (int i = 0; i < T.Size(); i++) {
		cout << T[i] << " ";
	} cout << endl;

	T = B; // Assignment
	for (int i = 0; i < T.Size(); i++) {
		cout << T[i] << " ";
	} cout << endl;

	T = B + C; // Vector addition
	for (int i = 0; i < T.Size(); i++) {
		cout << T[i] << " ";
	} cout << endl;

	doNothing(T);

	cout << C * B << endl; // Scale

	cout << A * C << endl; // Inconsistent

	cout << 5.0 * A << endl;

	cout << A * 5.0 << endl;

	return 0;
}