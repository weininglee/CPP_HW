#include <iostream>
#include <string>
using namespace std;

class bignum {
	string num;
	bool sign = 1;
public:
	bignum add(bignum b) {
		if (sign == 0 && b.sign == 0) {
			bignum c;
			sign = 1;
			b.sign = 1;
			c = add(b);
			c.sign = 0;
			return c;
		}
		else if (sign == 1 && b.sign == 1) {
			bignum sum;
			//反轉對齊個位數
			reverse(num.begin(), num.end());
			reverse(b.num.begin(), b.num.end());
			//sum.num = "a";
			int plus = 0, index = 0;
			for (index; index < min(num.size(), b.num.size()); index++) {
				int x = (num[index] - '0') + (b.num[index] - '0') + plus;
				//cout << (x % 10) << " ";
				sum.num += (char)(x % 10 + '0');
				//cout << (char)(x % 10);
				//cout << sum.num << "";
				plus = x / 10;
			}
			if (num.size() > b.num.size()) {
				for (index = b.num.size(); index < num.size(); index++) {
					int x = (num[index] - '0') + plus;
					sum.num = sum.num + (char)(x % 10 + '0');
					plus = x / 10;
				}
			}
			else if (num.size() < b.num.size()) {
				for (index = num.size(); index < b.num.size(); index++) {
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
		else {
			bignum sum;
			if (sign == 0 && b.sign == 1) {
				if (num.size() > b.num.size()) {
					sum = minus(b);
					sum.sign = 0;
					return sum;
				}
				else if (num.size() < b.num.size()) {
					sum = b.minus(*this);
					return sum;
				}
				for (int i = num.size() - 1; i >= 0; i--) {
					if (num[i] > b.num[i]) {
						sum = minus(b);
						sum.sign = 0;
						return sum;
					}
					else if (num[i] < b.num[i]) {
						sum = b.minus(*this);
						return sum;
					}
				}
				sum.num = "0";
				return sum;
			}
			else {
				if (num.size() > b.num.size()) {
					sum = minus(b);
					return sum;
				}
				else if (num.size() < b.num.size()) {
					sum = b.minus(*this);
					sum.sign = 0;
					return sum;
				}
				for (int i = num.size() - 1; i >= 0; i--) {
					if (num[i] > b.num[i]) {
						sum = minus(b);
						return sum;
					}
					else if (num[i] < b.num[i]) {
						sum = b.minus(*this);
						sum.sign = 0;
						return sum;
					}
				}
				sum.num = "0";
				return sum;
			}
		}
	}
	bignum minus(bignum b) {
		bignum diff;
		reverse(num.begin(), num.end());
		reverse(b.num.begin(), b.num.end());
		int div = 0, index = 0;
		for (index; index < min(num.size(), b.num.size()); index++) {
			int x = (num[index] - '0') - (b.num[index] - '0') - div;
			if (x < 0) {
				x += 10;
				div = 1;
			}
			else {
				div = 0;
			}
			diff.num += (char)(x % 10 + '0');
		}
		for (index = b.num.size(); index < num.size(); index++) {
			int x = (num[index] - '0') - div;
			if (x < 0) {
				x += 10;
				div = 1;
			}
			else {
				div = 0;
			}
			diff.num += (char)(x % 10 + '0');
		}
		reverse(diff.num.begin(), diff.num.end());
		return diff;
	}
	friend ostream& operator<<(ostream& out, bignum n) {
		if (n.sign == 0) {
			out << '-';
		}
		int i;
		for (i = 0; i < n.num.size() - 1; i++) {
			if (n.num[i] != '0') {
				break;
			} 
		}
		n.num.erase(0, i);
		out << n.num << endl;
		return out;
	}
	friend istream& operator>>(istream& in, bignum& n) {
		in >> n.num;
		if (n.num[0] == '-') {
			n.sign = 0;
			n.num.erase(0, 1);
		}
		else {
			n.sign = 1;
		}
		return in;
	}
};

int main() {
	bignum a, b;
	while (cin >> a >> b) {
		bignum c = a.add(b);
		cout << c;
	}
}