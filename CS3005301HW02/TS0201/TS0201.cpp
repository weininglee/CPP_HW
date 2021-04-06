#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double dev(double aver, vector<double> num, int n) {
	double total = 0.0;
	for (int x = 0; x < n; x++) {
		//cout << num[x] << " ";
		total += (((num[x] - aver) * (num[x] - aver)));
	}
	total /= n;
	return sqrt(total);
}

int main() {
	int n;
	double stan;
	//vector<int> number;
	while (cin >> n) {
		double aver = 0.0, sum = 0.0;
		vector<double> number;
		for (int x = 0; x < n; x++) {
			double m;
			cin >> m;
			number.push_back(m);
			sum += m;
		}
		aver = sum / n;
		stan = dev(aver, number, n);
		//number.clear();
		cout << "Average:" << aver << "\t" << "Standard deviation:" << stan << endl;
	}
}