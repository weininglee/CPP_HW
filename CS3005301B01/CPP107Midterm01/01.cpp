#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	double a, b, c;
	while (cin >> a >> b >> c) {
		double root1, root2;
		if ((pow(b, 2) - 4 * a * c) > 0){
			root1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
			root2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
			if (root1 == -root1) root1 = 0;
			if (root2 == -root2) root2 = 0;
			cout << max(root1, root2) << " " << min(root1, root2) << endl;
		}
		else if ((pow(b, 2) - 4 * a * c) == 0) {
			root1 = -b / (2 * a);
			if (root1 == -root1) root1 = 0;
			cout << root1 << endl;
		}
		else {
			cout << "No Root" << endl;
		}
	}
}