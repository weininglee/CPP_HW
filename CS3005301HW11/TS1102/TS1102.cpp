#include<iostream>
using namespace std;


int main() {
	int arow, acol, brow, bcol;
	while (cin >> arow >> acol >> brow >> bcol) {
		double** a = new double* [arow];
		for (int i = 0; i < arow; i++) {
			a[i] = new double[acol];
		}
		double** b = new double* [brow];
		for (int i = 0; i < brow; i++) {
			b[i] = new double[bcol];
		}
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				cin >> a[i][j];
			}
		}
		/*for (int i = 0; i < arow; i++) {
			for (int j = 0; j < acol; j++) {
				cout << a[i][j] ;
			}
			cout << endl;
		}*/
		for (int i = 0; i < brow; i++) {
			for (int j = 0; j < bcol; j++) {
				cin >> b[i][j];
				//cout << b[i][j] << endl;
			}
		}
		if (acol != brow) {
			cout << "Matrix multiplication failed." << endl;
			continue;
		}
		double** ab = new double* [arow];
		for (int i = 0; i < arow; i++) {
			ab[i] = new double[bcol];
		}

		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < bcol; j++) {
				ab[i][j] = 0;
			}
		}

		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < bcol; j++) {
				for (int k = 0; k < acol; k++) {

					ab[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		for (int i = 0; i < arow; i++) {
			for (int j = 0; j < bcol; j++) {
				cout << ab[i][j];
				if (j != bcol - 1) {
					cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < arow; i++) {
			delete[] a[i];
		}
		delete[] a;

		for (int i = 0; i < brow; i++) {
			delete[] b[i];
		}
		delete[] b;

		for (int i = 0; i < arow; i++) {
			delete[] ab[i];
		}
		delete[] ab;
	}
}