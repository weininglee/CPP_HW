#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int num;
	vector<int> list;
	while (cin >> num) {
		list.push_back(num);
	}
	cout << "N" << "\t" << "count" << endl;
	sort(list.begin(), list.end());
	reverse(list.begin(), list.end());
	for (int i = 0; i < list.size();) {
		int cou = count(list.begin() + i, list.end(), list[i]);
		cout << list[i] << "\t" << cou << endl;						
		i += cou;
	}
	list.clear();
}