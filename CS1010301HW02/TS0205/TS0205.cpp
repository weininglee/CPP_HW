#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct BitInt
{
	string num;
};

BitInt Add(BitInt a, BitInt b) {
	BitInt sum;
	//反轉對齊個位數
	reverse(a.num.begin(), a.num.end());
	reverse(b.num.begin(), b.num.end());
	//sum.num = "a";
	int plus = 0, index = 0;
	for (index; index < min(a.num.size(), b.num.size()); index++) {
		int x = (a.num[index] - '0') + (b.num[index] - '0') + plus;
		//cout << (x % 10) << " ";
		sum.num += (char)(x % 10 + '0');
		//cout << (char)(x % 10);
		//cout << sum.num << "";
		plus = x / 10;
	}
	if (a.num.size() > b.num.size()) {
		for (index = b.num.size(); index < a.num.size(); index++) {
			int x = (a.num[index] - '0') + plus;
			sum.num = sum.num + (char)(x % 10 + '0');
			plus = x / 10;
		}
	}
	else if (a.num.size() < b.num.size()) {
		for (index = a.num.size(); index < b.num.size(); index++) {
			int x = (b.num[index] - '0') + plus;
			sum.num = sum.num + (char)(x % 10 + '0');
			plus = x / 10;
		}
	}
	if (plus) {
		sum.num = sum.num + (char)(plus + '0');
	}
	reverse(sum.num.begin(), sum.num.end());
	return sum;
}

bool check(BitInt a, BitInt b) {
	for (int j = 0; j < (a.num.size() + b.num.size()); j++) {
		string check;
		check = a.num + b.num;
		if (check[j] < '0' || check[j]>'9')
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		BitInt A, B;
		cin >> A.num >> B.num;
		if (check(A, B)) {
			BitInt result = Add(A, B);
			cout << result.num << endl;
		}
		else
			cout << "Not a valid number, please try again." << endl;
	}
}